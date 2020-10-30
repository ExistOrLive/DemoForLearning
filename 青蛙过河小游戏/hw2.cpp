#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <curses.h>
#include <termios.h>
#include <fcntl.h>
#include "utils.h"

#define ROW 10
#define COLUMN 50 

pthread_mutex_t game_mutex;
pthread_mutex_t cursor_mutex;
pthread_mutex_t log_mutex;

struct Node{
	int x , y; 
	Node( int _x , int _y ) : x( _x ) , y( _y ) {}; 
	Node(){} ; 
} frog ; 


char map[ROW+10][COLUMN] ;

Log logs[ROW - 1];

Game game;

// Determine a keyboard is hit or not. If yes, return 1. If not, return 0. 
int kbhit(void){
	struct termios oldt, newt;
	int ch;
	int oldf;

	tcgetattr(STDIN_FILENO, &oldt);

	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);

	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	oldf = fcntl(STDIN_FILENO, F_GETFL, 0);

	fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

	ch = getchar();

	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	fcntl(STDIN_FILENO, F_SETFL, oldf);

	if(ch != EOF)
	{
		ungetc(ch, stdin);
		return 1;
	}
	return 0;
}


void updateMapWithLog(){
    memset( map , 0, sizeof( map ) ) ;
    for(int j = 0; j < COLUMN - 1; ++j )
        map[ROW][j] = map[0][j] = '|' ;

    for(int j = 0; j < COLUMN - 1; ++j )
        map[0][j] = map[0][j] = '|' ;
    
    for(int i = 0; i < ROW - 1; ++i){
        for(int j = 0; j < COLUMN - 1; ++j){
            if(j >= logs[i].left_pos && j < logs[i].left_pos + logs[i].len ){
                map[i+1][j] = '=';
            } else {
                map[i+1][j] = ' ';
            }
        }
    }
}

void updateMapWithFrog(){
    map[frog.x][frog.y] = '0';
}

void *logs_move( void *t ){
    
    while(true){
        sleep(1);
        
        Frog tmpfrog;
        Log tmpLogs[ROW -1];
        int result = 1;
        
        pthread_mutex_lock(&log_mutex);
        for(int i = 0; i < ROW; i++){
            logs[i].logs_move();
            tmpLogs[i] = logs[i];
        }
        updateMapWithLog();
        pthread_mutex_unlock(&log_mutex);
        
        pthread_mutex_lock(&cursor_mutex);
        tmpfrog = Frog(frog.y, frog.x);
        updateMapWithFrog();
        pthread_mutex_unlock(&cursor_mutex);
        
        putchar('\n');
        for(int i = 0; i <= ROW; ++i)
            puts( map[i] );
        
        pthread_mutex_lock(&game_mutex);
        result = game.living;
        if(result == 1){
            result = game.judge(&tmpfrog, tmpLogs);
        }
        pthread_mutex_unlock(&game_mutex);
        
        if(result != 1){
            pthread_exit(NULL);
        }
    }

    return NULL;
}

void *getInput( void *t ){
    while(true){
        int result = kbhit();
        if(result == 1){
            int i = 0,j = 0;
            bool quit = false;
            char a = getchar();
            switch(a){
                case 'w':
                case 'W':{
                    i = -1;
                }
                    break;
                case 'S':
                case 's':{
                    i = 1;
                }
                    break;
                case 'A':
                case 'a':{
                    j = -1;
                }
                    break;
                case 'D':
                case 'd':{
                    j = 1;
                }
                    break;
                case 'Q':
                case 'q':{
                    quit = true;
                }
                    break;
                default:
                    break;
            }
            if(quit == true){
                pthread_mutex_lock(&game_mutex);
                game.living = -1;
                pthread_mutex_unlock(&game_mutex);
                break;
            }
            
            if(i != 0 || j!= 0){
                pthread_mutex_lock(&cursor_mutex);
                frog.x += i;
                frog.y += j;
                if(frog.x < 0){
                    frog.x = 0;
                }
                if(frog.x > ROW){
                    frog.x = ROW;
                }
                if(frog.y < 0){
                    frog.y = 0;
                }
                if(frog.y >= COLUMN){
                    frog.y = COLUMN - 1;
                }
                pthread_mutex_unlock(&cursor_mutex);
            }
        }
        int gameresult = 1;
        pthread_mutex_lock(&game_mutex);
        gameresult = game.living;
        pthread_mutex_unlock(&game_mutex);
        if(gameresult != 1){  // end
            break;
        }
        
    }
    
    return NULL;
}

int main( int argc, char *argv[] ){

	// Initialize the river map and frog's starting position
	memset( map , 0, sizeof( map ) ) ;
	int i , j ; 
	for( i = 1; i < ROW; ++i ){	
		for( j = 0; j < COLUMN - 1; ++j )	
			map[i][j] = ' ' ;  
	}	

	for( j = 0; j < COLUMN - 1; ++j )	
		map[ROW][j] = map[0][j] = '|' ;

	for( j = 0; j < COLUMN - 1; ++j )	
		map[0][j] = map[0][j] = '|' ;

	frog = Node( ROW, (COLUMN-1) / 2 ) ; 
	map[frog.x][frog.y] = '0' ;
    
    // init logs
    for(int i = 0; i < ROW - 1; ++i){
        logs[i] = Log(i,rand()%15+10,rand()%(COLUMN - 1), i % 2 == 0 ? 1 : -1);
    }
    
    game.init_game();
    
    for( i = 0; i <= ROW; ++i)
        puts( map[i] );
    
    pthread_mutex_init(&game_mutex, NULL);
    pthread_mutex_init(&cursor_mutex, NULL);
    pthread_mutex_init(&log_mutex, NULL);
    
    pthread_t thread_log_move;
    pthread_create(&thread_log_move, NULL, &logs_move, NULL);
    
    pthread_t thread_cursor;
    pthread_create(&thread_cursor, NULL, &getInput, NULL);

    pthread_join(thread_log_move, NULL);
    pthread_join(thread_cursor, NULL);
    
    game.show_status();
    
    pthread_mutex_destroy(&game_mutex);
    pthread_mutex_destroy(&cursor_mutex);
    pthread_mutex_destroy(&log_mutex);

	return 0;

}
