//
//  main.cpp
//  BinaryTreeTest
//
//  Created by 朱猛 on 2019/7/8.
//  Copyright © 2019 朱猛. All rights reserved.
//

#include <iostream>
#include "BinaryTree.hpp"

using namespace zm;


void visit(int & value)
{
    printf("%d ",value);
}

int main(int argc, const char * argv[]) {
    
    BinaryTree<int> tree;
    
    int array[20] = {1,3,5,2,6,8,9,10,24,7,4,23,15,203,102,16,12,19,0,11};
    tree.createBinaryTree(array, 20);
    
    printf("前序遍历 \n");
    tree.DLRTraverse(&visit);
     printf("\n");
    tree.DLRTraverse1(&visit);
    
    printf("中序遍历 \n");
    tree.LDRTraverse(&visit);
    printf("\n");
    tree.LDRTraverse1(&visit);
    
    printf("后序遍历 \n");
    tree.LRDTraverse(&visit);
    printf("\n");
    tree.LRDTraverse1(&visit);
    
    printf("层次遍历 \n");
    
    tree.levelTraverse(&visit);
    
    
}
