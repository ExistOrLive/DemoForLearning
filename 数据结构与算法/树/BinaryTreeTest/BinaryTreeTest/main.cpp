//
//  main.cpp
//  BinaryTreeTest
//
//  Created by 朱猛 on 2019/7/8.
//  Copyright © 2019 朱猛. All rights reserved.
//

#include <iostream>
#include "BinaryTree.hpp"
#include "ThreadedBinaryTree.hpp"
#include <time.h>

using namespace zm;


void visit(int & value)
{
    printf("%d ",value);
}

int main(int argc, const char * argv[]) {
    
    BinaryTree<int> tree;
    int beginTime,endTime;
    
    int array[20] = {0,1,3,5,2,6,8,9,10,24,7,4,23,15,203,102,16,12,19,11};
    tree.createBinaryTree(array, 20);
    
//    printf("前序遍历 \n");
//    tree.DLRTraverse(&visit);
//     printf("\n");
//    tree.DLRTraverse1(&visit);
    
    printf("中序遍历 \n");
  //  tree.LDRTraverse(&visit);
    printf("\n");
    beginTime = clock();
    for(int i =0 ; i < 100; i++)
    {
        tree.LDRTraverse1(&visit);
    }
  
    endTime = clock();
    
    printf("耗时： %d\n",endTime - beginTime);
    
//
//    printf("后序遍历 \n");
//    tree.LRDTraverse(&visit);
//    printf("\n");
//    tree.LRDTraverse1(&visit);
//
//    printf("层次遍历 \n");
//
//    tree.levelTraverse(&visit);
    
     printf("\n");
    
     printf("线索二叉树\n");
    
    ThreadedBinaryTree<int> threadedTree;
    
    threadedTree.createBinaryTree(array, 20);
    
    threadedTree.LDRThreading();
    
    beginTime = clock();
    for(int i =0 ; i < 100; i++)
    {
        threadedTree.LDRTraverse1(&visit);
    }
    
    endTime = clock();
    
    printf("耗时： %d\n",endTime - beginTime);
    
}
