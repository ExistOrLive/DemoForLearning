//
//  main.cpp
//  LinearTableTest
//
//  Created by 朱猛 on 2019/7/4.
//  Copyright © 2019 朱猛. All rights reserved.
//

#include <iostream>
#include "String/String.hpp"

using namespace zm;
using std::string;

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




int main(int argc, const char * argv[]) {

    
    char a[25] = "5685675678345669";
    char b[20] = "568569";
    
    String c(a);
    String d(b);
    int location = c.indexOfString(d);
    
    printf("location = %d",location);
    return 0;
}
