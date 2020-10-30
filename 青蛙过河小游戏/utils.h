//
// Created by zero on 2020/10/18.
//

#ifndef SOURCE_UTILS_H
#define SOURCE_UTILS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <curses.h>
#include <termios.h>
#include <fcntl.h>
#define ROW 10
#define COLUMN 50

class Frog{
public:
    int x_pos;
    int y_pos;
    Frog(){}
    Frog(int x,int y):x_pos(x),y_pos(y){}
};

class Log {
public:
    int row;
    int len;
    int left_pos;
    int direction; // 1: left; 1: right
    int randseed;

    Log(int idx = 0, int len = 10, int left_pos = 0, int direction = 1, int randseed = 0) {
        this->row = idx + 1; // row starts from 1
        this->len = len;
        this->left_pos = left_pos;
//        this->direction = direction;
        this->direction = direction;
    }

    void printLog() {
        printf("\033[%d;1H", this->row + 1);

        if (this->direction == 1) {
            for (int i = 0; i < COLUMN; i++) {
                if (i >= this->left_pos && i <= this->left_pos + this->len) putchar('=');
//            else if (this->left_pos+this->len > COLUMN && i < (this->left_pos+this->len)%COLUMN) putchar('=');
                else putchar(' ');
            }
        }
        else{
            for (int i = 0; i < COLUMN; i++) {
                if (i >= this->left_pos && i <= this->left_pos + this->len) putchar('=');
//            else if (this->left_pos+this->len > COLUMN && i < (this->left_pos+this->len)%COLUMN) putchar('=');
                else putchar(' ');
            }
        }


        printf("\033[%d;51H", this->row + 1);
        for (int i = 0; i < COLUMN; i++) {
            putchar(' ');
        }
    }
    
    void logs_move() {
        /*  Move the logs  */
        switch (this->direction) {
            case -1: // moving left
                this->left_pos--;
                if (this->left_pos+this->len == 0) {
                    this->len = rand() % 15 + 10;
                    this->left_pos = 50;
                }
                break;

            case 1: // moving right
                this->left_pos++;
                srand(this->len);
                if (this->left_pos == COLUMN - 1) {
                    this->len = rand() % 15 + 10;
                    this->left_pos = -this->len;
                }
                break;
            default:
                break;
        }
    }
};

class Game {
private:
    char action;

public:
    int living; // 1: living; 0: died; -1: quit 2: win

    Game() {
        this->action = '0';
        this->living = 1;
    }

    // P.S. print frog and pring log must go together (first print log then print frog)

    void init_game() {
        printf("Game Starts!\n");
        sleep(1);
    }

    int judge(Frog *frog, Log *logs) {
        if (frog->y_pos == ROW ){
            this->living = 1;
            return 1;
        }
        else if (frog->y_pos == 0){
            this->living = 2;
            return 2;
        }
    
//        if (frog->x_pos == 1 || frog->x_pos == COLUMN){
//            this->living = 0;
//            return 0;
//        }

        Log log = logs[frog->y_pos - 1];
        if (log.direction == 1) {
            if (frog->x_pos >= log.left_pos && frog->x_pos <= log.left_pos + log.len + 1) {
                this->living = 1;
                return 1; // still live
            } else {
                this->living = 0;
                return 0;
            }
        } else if (log.direction == -1) {
            if (frog->x_pos >= log.left_pos + 1 && frog->x_pos <= log.left_pos + log.len + 2) {
                this->living = 1;
                return 1; // still live
            } else {
                this->living = 0;
                return 0;
            }
        }
        this->living = 0;
        return 0;
    }

    void show_status() {
        printf("\n");
        sleep(2);
        if (living == 2) {
            printf("YOU LUCKY BASTARD (win)\n");
        } else if (living == 0) {
            printf("YOU SUCK (lose)\n");
        } else {
            printf("YOU LITTLE COWARD (quit)\n");
        }
    }
};

#endif //SOURCE_UTILS_H
