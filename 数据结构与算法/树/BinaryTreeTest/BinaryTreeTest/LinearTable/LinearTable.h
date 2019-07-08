//
//  LinearTable.h
//  LinearTableTest
//
//  Created by 朱猛 on 2019/6/23.
//  Copyright © 2019 朱猛. All rights reserved.
//

#ifndef LinearTable_h
#define LinearTable_h



namespace zm {
    
    template <typename T>
    
    class LinearTable
    {
    protected:
        int size;                     //! 线性表的长度

        
    public:
        LinearTable()
        {
            size = 0;
        }
        
        ~ LinearTable()
        {
            size = 0;
            /**
             *  销毁内存
             **/
        }
        
        /**
         *
         * 清空线性表
         **/
        virtual void clearList() = 0;
        
        virtual bool isEmpty() = 0;
        
        virtual int  length() = 0;
        
        virtual T getElem(int index) = 0;
        
        virtual int locateElem(T & elem,int(*compare)(T &,T &)) = 0;
        
//        virtual T priorElem(T & elem) = 0;
//        
//        virtual T nextElem(T & elem) = 0;
        
        virtual bool insertElem(T & elem,int index) = 0;
        
        virtual T deleteElem(int index) = 0;
        
        virtual void traverse(void(*visit)(T &)) = 0;
        
    };

}



#endif /* LinearTable_h */
