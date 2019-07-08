//
//  BinaryTree.hpp
//  BinaryTreeTest
//
//  Created by 朱猛 on 2019/7/8.
//  Copyright © 2019 朱猛. All rights reserved.
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <stdio.h>
#include "Stack/LinkedStack.hpp"
#include "LinearTable/ArrayLinearTable.hpp"
#include "Queue/LinkedQueue.cpp"

using namespace std;

namespace zm {
    
    template <typename T>
    class BinaryTreeNode
    {
    public:
        T value;
        BinaryTreeNode * leftNode;
        BinaryTreeNode * rightNode;
    };
    
    template <typename T>
    class BinaryTree
    {
    private:
        BinaryTreeNode<T> * rootNode;
        int depth;
        int size;
        
        void insertNode(T value, BinaryTreeNode<T> * &tree)
        {
            if(tree == NULL)
            {
                BinaryTreeNode<T> * node = new BinaryTreeNode<T>();
                node->value = value;
                node->leftNode = NULL;
                node->rightNode = NULL;
                tree = node;
            }
            else
            {
                if(tree->value > value)
                {
                    insertNode(value,tree->leftNode);
                }
                else if(tree->value < value)
                {
                    insertNode(value,tree->rightNode);
                }
            }
        }
        
        // 前序遍历 一次循环
        void DLRTraverseNode(BinaryTreeNode<T> * node,void(*visit)(T&))
        {
            if(node == NULL)
            {
                return;
            }
            
            visit(node->value);
            DLRTraverseNode(node->leftNode,visit);
            DLRTraverseNode(node->rightNode,visit);
        }
        
        // 中序遍历 一次循环
        void LRDTraverseNode(BinaryTreeNode<T> * node,void(*visit)(T&))
        {
            if(node == NULL)
            {
                return;
            }
            
            LRDTraverseNode(node->leftNode,visit);
            LRDTraverseNode(node->rightNode,visit);
            visit(node->value);
        }
        
        // 中序遍历 一次循环
        void LDRTraverseNode(BinaryTreeNode<T> * node,void(*visit)(T&))
        {
            if(node == NULL)
            {
                return;
            }
            
            
            LDRTraverseNode(node->leftNode,visit);
            visit(node->value);
            LDRTraverseNode(node->rightNode,visit);
        }
    
    public:
        
        BinaryTree<T>()
        {
            this->rootNode = NULL;
            this->depth = 0;
            this->size = 0;
        }
        
        ~ BinaryTree<T>()
        {
            
        }
        
        void createBinaryTree(T * array, int length)
        {
            for(int i = 0 ; i < length; i++)
            {
                insertNode(array[i],this->rootNode);
            }
        }
#pragma mark - 遍历 递归
        // 前序遍历 递归
        void DLRTraverse(void(*visit)(T&))
        {
            DLRTraverseNode(this->rootNode,visit);
        }
        
        // 中序遍历
        void LDRTraverse(void(*visit)(T&))
        {
            LDRTraverseNode(this->rootNode,visit);
        }
        
        // 后序遍历
        void LRDTraverse(void(*visit)(T&))
        {
            LRDTraverseNode(this->rootNode,visit);
        }
        
#pragma mark - 遍历 循环迭代 利用栈来实现，递归实际上就是栈
        
        // 前序遍历 迭代 循环 (利用栈来实现，递归实际上就是栈)
        void DLRTraverse1(void(*visit)(T&))
        {
            LinkedStack<BinaryTreeNode<T> *> stack;
            
            BinaryTreeNode<T> * rootNode = this->rootNode;
            while(rootNode != NULL || stack.length() > 0)
            {
                // 将从根节点开始的所有左子树的左节点入栈
                while (rootNode != NULL) {
                    visit(rootNode->value);           // 在入栈之前，先访问j节点的值
                    stack.push(rootNode);
                    rootNode = rootNode->leftNode;
                }
                
                stack.pop(rootNode);
                rootNode = rootNode->rightNode;
            }
            
        }
        

        void LDRTraverse1(void(*visit)(T&))
        {
            LinkedStack<BinaryTreeNode<T> *> stack;
            
            BinaryTreeNode<T> * rootNode = this->rootNode;
            
            while(rootNode != NULL || stack.length() > 0)
            {
                while (rootNode != NULL) {
                    stack.push(rootNode);
                    rootNode = rootNode->leftNode;
                }
                
                BinaryTreeNode<T> * tmpNode = NULL;
                stack.pop(tmpNode);
                visit(tmpNode->value);
                rootNode = tmpNode->rightNode;
            }
            
        }
     
        // 后序遍历
        // 因为是后序遍历，有右子树的节点不能直接访问， 需要等到右子树全部访问完
        // 需要一个线性表保存已经遍历到但是有右子树的节点
        void LRDTraverse1(void(*visit)(T&))
        {
            LinkedStack<BinaryTreeNode<T> *> stack;
            ArrayLinearTable<BinaryTreeNode<T> *>  nodesForVisted;
            
            BinaryTreeNode<T> * rootNode = this->rootNode;
            
            while(rootNode != NULL || stack.length() > 0)
            {
                // 将从根节点开始的所有左子树的左节点入栈
                while (rootNode != NULL) {
                    stack.push(rootNode);
                    rootNode = rootNode->leftNode;
                }
                
                BinaryTreeNode<T> * tmpNode = NULL;
                stack.getTop(tmpNode);
                
                // 如果栈顶节点的右子树已经遍历，就直接访问
                if(nodesForVisted.locateElem(tmpNode, NULL) != -1)
                {
                    stack.pop(tmpNode);
                    visit(tmpNode->value);
                }
                else
                {
                     // 如果栈顶节点的右子树没有遍历，需要右子树入栈
                    rootNode = tmpNode->rightNode;
                    nodesForVisted.insertElem(tmpNode, 0);
                }
            }
            
            
        }
        
#pragma mark - 层次遍历
        
        // 层次遍历需要一个队列实现
        void levelTraverse(void(*visit)(T&))
        {
            if(this->rootNode == NULL)
            {
                return;
            }
            
            BinaryTreeNode<T> * currentNode = this->rootNode;
            LinkedQueue<BinaryTreeNode<T> *> queue;
            queue.enQueue(currentNode);
            
            do{
                if(queue.deQueue(currentNode) == true)
                {
                    visit(currentNode->value);
                    
                    if(currentNode->leftNode != NULL)
                    {
                        queue.enQueue(currentNode->leftNode);
                    }
                    if(currentNode->rightNode != NULL)
                    {
                        queue.enQueue(currentNode->rightNode);
                    }
                }
            }while(queue.queueLength() > 0);

        }
      
        
        
    };
}

#endif /* BinaryTree_hpp */
