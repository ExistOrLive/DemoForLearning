//
//  ThreadedBinaryTree.hpp
//  BinaryTreeTest
//
//  Created by 朱猛 on 2019/7/28.
//  Copyright © 2019 朱猛. All rights reserved.
//

#ifndef ThreadedBinaryTree_hpp
#define ThreadedBinaryTree_hpp

#include <stdio.h>
#include "Stack/LinkedStack.hpp"

namespace zm{
    
    template <typename T>
    class ThreadedTreeNode
    {
    public:
        T value;
        ThreadedTreeNode * leftNode;
        ThreadedTreeNode * rightNode;
        int leftTag;
        int rightTag;
    
        ThreadedTreeNode<T>()
        {
            this->leftTag = 0;
            this->rightTag = 0;
        }
        
    };
    
    template <typename T>
    class ThreadedBinaryTree
    {
    private:
        ThreadedTreeNode<T> * rootNode;
        int depth;
        int size;
        
        void insertNode(T value, ThreadedTreeNode<T> * &tree)
        {
            if(tree == NULL)
            {
                ThreadedTreeNode<T> * node = new ThreadedTreeNode<T>();
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
        
    public:
        ThreadedBinaryTree<T>()
        {
            this->rootNode = new ThreadedTreeNode<T>;
            this->rootNode->leftTag = 0;
            this->rootNode->leftNode = NULL;
            this->rootNode->rightTag = 0;
            this->rootNode->rightNode = NULL;
        }
        
        ~ ThreadedBinaryTree<T>()
        {
            
        }
        
        // 插入节点
        void createBinaryTree(T * array, int length)
        {
            for(int i = 0 ; i < length; i++)
            {
                insertNode(array[i],this->rootNode->leftNode);
            }
        }
        
#pragma mark - 线索化
        
        // 前序线索化 需要先遍历二叉树
        void DLRThreading()
        {
            LinkedStack<ThreadedTreeNode<T> *> stack;
            ThreadedTreeNode<T> * preNode = this->rootNode;
            ThreadedTreeNode<T> * currentNode = this->rootNode;
            while(currentNode != NULL || !stack.isEmpty())
            {
                if(currentNode != NULL)
                {
                    stack.push(currentNode);
                  
                    ThreadedTreeNode<T> * tmpNode = currentNode;
                    currentNode = currentNode->leftNode;
            
                    // 建立线索
                    if(tmpNode->leftNode == NULL)
                    {
                        tmpNode->leftTag = 1;
                        tmpNode->leftNode = preNode;
                    }
                    if(preNode->rightNode == NULL)
                    {
                        preNode->rightTag = 1;
                        preNode->rightNode = tmpNode;
                    }
                    
                    preNode = tmpNode;
                }
                else
                {
                    ThreadedTreeNode<T> * tmpNode = NULL;
                    stack.pop(tmpNode);
                   
                    if(tmpNode->rightTag == 0)
                    {
                        currentNode = tmpNode->rightNode;
                    }
                    else
                    {
                        currentNode = NULL;
                    }
                    
                }
                
            }
            
            if(preNode != NULL && preNode->rightNode == NULL)
            {
                preNode->rightTag = 1;
                preNode->rightNode = this->rootNode;
                this->rootNode->rightTag = 1;
                this->rootNode->rightNode = preNode;
            }
        }
        
        // 中序线索化
        void LDRThreading()
        {
            LinkedStack<ThreadedTreeNode<T> *> stack;
            ThreadedTreeNode<T> * preNode = this->rootNode;
            ThreadedTreeNode<T> * currentNode = this->rootNode;
            while(currentNode != NULL || !stack.isEmpty())
            {
                if(currentNode != NULL)
                {
                    stack.push(currentNode);
                    currentNode = currentNode->leftNode;
                }
                else
                {
                    ThreadedTreeNode<T> * tmpNode = NULL;
                    stack.pop(tmpNode);
                    
                    if(tmpNode->leftNode == NULL)
                    {
                        tmpNode->leftTag = 1;
                        tmpNode->leftNode = preNode;
                    }
                    
                    if(preNode != this->rootNode && preNode->rightNode == NULL)
                    {
                        preNode->rightTag = 1;
                        preNode->rightNode = tmpNode;
                    }
                    preNode = tmpNode;
                    
                    if(tmpNode->rightTag == 0)
                    {
                        currentNode = tmpNode->rightNode;
                    }
                    else
                    {
                        currentNode = NULL;
                    }
                    
                }
                
            }
            
            if(preNode != NULL && preNode->rightNode == NULL)
            {
                preNode->rightTag = 1;
                preNode->rightNode = this->rootNode;
                this->rootNode->rightTag = 1;
                this->rootNode->rightNode = preNode;
            }
        }
        
        // 后序线索化
        void LRDThreading()
        {
            if(this->rootNode->leftNode == NULL)
            {
                return;
            }
        }
        
#pragma mark - 线索二叉树遍历
        
        void DLRTraverse1(void(*visit)(T&))
        {
            ThreadedTreeNode<T> * currentNode = this->rootNode->leftNode;
            
            while(currentNode != this->rootNode)
            {
                visit(currentNode->value);
                
                if(currentNode->rightTag == 1)
                {
                    currentNode = currentNode ->rightNode;
                }
                else
                {
                    if(currentNode->leftTag == 0)
                    {
                        currentNode = currentNode -> leftNode;
                    }
                    else
                    {
                        currentNode = currentNode-> rightNode;
                    }
                }
            }
        }
        
        void LDRTraverse1(void(*visit)(T&))
        {
            ThreadedTreeNode<T> * currentNode = this->rootNode->leftNode;
        
            while(currentNode != this->rootNode)
            {
                 // 找到起始店
                while(true)
                {
                    if(currentNode->leftTag == 1)
                    {
                        break;
                    }
                    
                    currentNode = currentNode->leftNode;
                }
                
                visit(currentNode->value);
                
                while(currentNode->rightTag == 1 && currentNode->rightNode != this->rootNode)
                {
                   currentNode = currentNode ->rightNode;
                   visit(currentNode->value);
                }
                
                currentNode = currentNode ->rightNode;
            }
        }
        
        
    };
}


#endif /* ThreadedBinaryTree_hpp */
