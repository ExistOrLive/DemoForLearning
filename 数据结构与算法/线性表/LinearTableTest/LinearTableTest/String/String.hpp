//
//  String.hpp
//  LinearTableTest
//
//  Created by 朱猛 on 2019/7/5.
//  Copyright © 2019 朱猛. All rights reserved.
//

#ifndef String_hpp
#define String_hpp

#include <stdio.h>
#include <string.h>

namespace zm {
    
    static const int StringInitSize = 16;
    static const int StringIncrementSize = 16;
    
    class String
    {
    private:
        char * list;
        size_t length;
        size_t capacity;
        
        // nextIndexForKMP
        int nextIndexForKMP(int index, String & subStr)
        {
            if(index == 0)
            {
                return -1;
            }
            
            int nextIndex = 0;
            
            // 计算最长的相同前后缀, 从最长的index - 1 到 最短的 1 结束
            for(int length = index -1 ; length >= 1; length --)
            {
                int i = 0;
                
                // 按位比较前后缀
                for(i = 0; i <= length -1; i++)
                {
                    if(subStr.charAtIndex(i) != subStr.charAtIndex(index  - length + i))
                    {
                        break;
                    }
                }
                
                if(i == length)
                {
                    nextIndex = length;  // nextIndex 为最长前缀的下一个位置
                    break;
                }
            }
            
            return nextIndex;
        }

    public:
        String()
        {
            this->list = new char[StringInitSize];
            this->capacity = StringInitSize;
            this->length = 0;
        }
        
        String(char * charArray)
        {
            size_t length = strlen(charArray);
            this->list = new char[length];
            for(int i =0; i < length;i++)
            {
                this->list[i] = charArray[i];
            }
            this->capacity = length;
            this->length = length;
        }
        String(String &str)
        {
            size_t length = str.strLength();
            this->list = new char[length];
            for(int i=0; i < length;i++)
            {
                this->list[i] = str.charAtIndex(i);
            }
            this->capacity = length;
            this->length = length;
        }
        
        ~ String()
        {
            delete[] this->list;
            this->list = NULL;
            this->length = 0;
            this->capacity = 0;
        }
        
        
        size_t strLength()
        {
            return this->length;
        }
        
        char charAtIndex(int index)
        {
            if(index < 0 || index >= this->length)
            {
                return -1;
            }
            
            return this->list[index];
        }
        
        // KMP
        int indexOfString(String & subStr)
        {
            if(subStr.strLength() > this->length)
            {
                return -1;
            }
            
            int i = 0;
            int j = 0;     // 模式串的索引
            do
            {
                if(this->list[i] == subStr.charAtIndex(j))
                {
                    i++;
                    j++;
                }
                else
                {
                    int nextIndex = nextIndexForKMP(j, subStr);
                    if(-1 == nextIndex)
                    {
                        j = 0;
                        i++;
                    }
                    else
                    {
                        j = nextIndex;
                    }
                }
                
            }while(j < subStr.strLength() && (i + (subStr.strLength() - j) <= this->length));
            // 如果j < subStr.strLength()， 模式串的索引没有最后
            // (i + (subStr.strLength() - j) <= this->length)
            
            // 模式串匹配完
            if( j == subStr.strLength())
            {
                return (int)(i - j);
            }
            else
            {
                return -1;
            }
        }
        
    };
}

#endif /* String_hpp */
