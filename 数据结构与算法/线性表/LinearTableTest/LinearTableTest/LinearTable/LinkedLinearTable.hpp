//
//  LinkedLinearTable.hpp
//  LinearTableTest
//
//  Created by 朱猛 on 2019/6/24.
//  Copyright © 2019 朱猛. All rights reserved.
//

#ifndef LinkedLinearTable_hpp
#define LinkedLinearTable_hpp

#include <stdio.h>

#include "LinearTable.h"


namespace zm {
    
    template <typename T>
    
    class Node
    {
    public:
        T value;
        Node * next;
    };
    
    template <typename T>
    
    class LinkedLinearTable : public LinearTable<T>
    {
    private:
        
        Node<T> * list;
        
        /**
         * 释放除头节点的所有节点
         **/
        void freeList();
        
    public:
        
        LinkedLinearTable();
        
        ~ LinkedLinearTable();
        
        /**
         *
         * 清空线性表
         **/
        void clearList();
        
        bool isEmpty();
        
        int  length();
        
        T getElem(int index);
        
        int locateElem(T & elem,int(*compare)(T &,T &));
        
        //        T priorElem(T & elem);
        //
        //        T nextElem(T & elem);
        
        bool insertElem(T & elem,int index);
        
        T deleteElem(int index);
        
        void traverse(void(*visit)(T&));
        
  
    };
    
    
    template <typename T>
    
    LinkedLinearTable<T>::LinkedLinearTable():LinearTable<T>()
    {
        Node<T> * headNode = new Node<T>;
        headNode->next = NULL;
        
        this->list = headNode;
    }
    
    template <typename T>
    LinkedLinearTable<T>:: ~ LinkedLinearTable()
    {
        
        freeList();
        
        // 释放头节点
        delete this->list;
        
        this->list = NULL;
    }
    
    template <typename T>
    void LinkedLinearTable<T>:: clearList()
    {
        freeList();
        this->size = 0;
    }
    
    template <typename T>
    bool LinkedLinearTable<T>:: isEmpty()
    {
        return this->size == 0;
    }
    
    template <typename T>
    int LinkedLinearTable<T>:: length()
    {
        return this->size;
    }
    
    template <typename T>
    T LinkedLinearTable<T>:: getElem(int index)
    {
        if(index >= this->size || index < 0)
        {
            throw __cpp_exceptions;
        }
        
        int i = 0;
        Node<T> * node = this->list->next;
        while(i < index)
        {
            node = node->next;
            i ++;
        }
        
        return node->value;
    }
    
    template <typename T>
    int LinkedLinearTable<T>::locateElem(T & elem,int(*compare)(T &,T &))
    {
        Node<T> * node = this->list->next;
        int index = 0;
        
        while(node)
        {
            if(compare(node->value,elem) == 0)
            {
                return index;
            }
            index ++;
            node = node->next;
        }
        
        return -1;
    }
    
    
    template <typename T>
    bool LinkedLinearTable<T>::insertElem(T &elem, int index)
    {
        if(index < 0 || index > this->size)
        {
            throw __cpp_exceptions;
        }
        
        int i = 0;
        Node<T> * node = this->list;
        
        while(i < index)
        {
            node = node->next;
            i++;
        }
        
        Node<T> * newNode = new Node<T>;
        newNode->value = elem;
        newNode->next = node->next;
        node->next = newNode;
        
        this->size ++;
        
        return true;
    }
    
    template <typename T>
    T LinkedLinearTable<T>:: deleteElem(int index)
    {
        if(index < 0 || index >= this->size)
        {
            throw __cpp_exceptions;
        }
        
        int i = 0;
        Node<T> * node = this->list;
        
        while(i < index)
        {
            node = node -> next;
            i ++;
        }
        
        Node<T> * deleteNode = node->next;
        node->next = deleteNode->next;
        this->size --;
        
        T value = deleteNode->value;
        delete deleteNode;
        deleteNode = NULL;
        
        return value;
    }
    
    
    template <typename T>
    void LinkedLinearTable<T>:: traverse(void(*visit)(T&))
    {
        Node<T> * currentNode = this->list->next;
        
        while(currentNode)
        {
            visit(currentNode->value);
            currentNode = currentNode ->next;
        }
    }
    
    template <typename T>
    void LinkedLinearTable<T>:: freeList()
    {
        Node<T> * currentNode = this->list->next;
        
        Node<T> * tmpNode = NULL;
        while(currentNode)
        {
            tmpNode = currentNode;
            currentNode = tmpNode->next;
            delete tmpNode;
            tmpNode = NULL;
        }
        this->list->next = NULL;
    }
    
    
}

#endif /* LinkedLinearTable_hpp */
