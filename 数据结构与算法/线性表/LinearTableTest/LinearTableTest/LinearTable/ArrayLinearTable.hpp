//
//  ArrayLinearTable.hpp
//  LinearTableTest
//
//  Created by 朱猛 on 2019/6/23.
//  Copyright © 2019 朱猛. All rights reserved.
//

#ifndef ArrayLinearTable_hpp
#define ArrayLinearTable_hpp

#include <stdio.h>
#include "LinearTable.h"


namespace zm {
    
    template <typename T>

    class ArrayLinearTable: public LinearTable<T>
    {
    private:
        
        int capacity;                 //! 线性表的容量
        
        int incrementNum = 16;        //! 线性表的增量
        
        T * list;
        
        void enlargeList();
        
    public:
        
        ArrayLinearTable(int capacity = 16);
        
        ~ ArrayLinearTable();
        
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
    ArrayLinearTable<T>:: ArrayLinearTable(int capacity) : LinearTable<T>()
    {
        this->capacity = capacity;
        this->list = new T[capacity];
    }
    
    template <typename T>
    ArrayLinearTable<T>:: ~ ArrayLinearTable()
    {
        delete[] this->list;
        this->capacity = 0;
    }
    
    template <typename T>
    void ArrayLinearTable<T>:: clearList()
    {
        this->size = 0;
    }
    
    template <typename T>
    bool ArrayLinearTable<T>:: isEmpty()
    {
        return this->size == 0;
    }
    
    template <typename T>
    int ArrayLinearTable<T>:: length()
    {
        return this->size;
    }
    
    template <typename T>
    T ArrayLinearTable<T>:: getElem(int index)
    {
        if(index >= this->size || index < 0)
        {
            throw __cpp_exceptions;
        }
        
        return list[index];
    }
    
    template <typename T>
    int ArrayLinearTable<T>:: locateElem(T & elem,int(*compare)(T &,T &))
    {
        int i = 0;
        for(; i < this->size; i++)
        {
            if(compare(list[i],elem) == 0)
            {
                return i;
            }
        }
        
        return -1;
    }
    
    //    template <typename T>
    //    T ArrayLinearTable<T>:: priorElem(T & elem)
    //    {
    //
    //    }
    //
    //    template <typename T>
    //    T ArrayLinearTable<T>:: nextElem(T & elem);
    //    {
    //
    //    }
    
    
    template <typename T>
    bool ArrayLinearTable<T>:: insertElem(T & elem,int index)
    {
        if(index > this->size || index < 0)
        {
            throw __cpp_exceptions;
        }
        
        if(this->size >= this->capacity)
        {
            enlargeList();
        }
        
        for(int i = this->size - 1; i >= index; i--)
        {
            this->list[i+1] = this->list[i];
        }
        
        this->list[index] = elem;
        this->size ++;
        
        return true;
    }
    
    template <typename T>
    T ArrayLinearTable<T>::deleteElem(int index)
    {
        if(index >= this->size || index < 0)
        {
            throw __cpp_exceptions;
        }
        
        T elem = this->list[index];
        
        for(int i = index; i <= this->size - 2; i++)
        {
            this->list[i] = this->list[i+1];
        }
        this->size --;
        
        return elem;
    }
    
    template <typename T>
    void ArrayLinearTable<T>:: traverse(void(*visit)(T&))
    {
        for(int i = 0; i < this->size; i++)
        {
            visit(this->list[i]);
        }
    }
    
    
    template <typename T>
    void ArrayLinearTable<T>:: enlargeList()
    {
        T * newList = new T[this->capacity + this->incrementNum];
        
        if(!newList)
        {
            throw __cpp_exceptions;
        }
        
        for(int i = 0; i < this->size; i++)
        {
            newList[i] = this->list[i];
        }
        
        this->list = newList;
        this->capacity += this->incrementNum;
        
    }
    

    
}







#endif /* ArrayLinearTable_hpp */
