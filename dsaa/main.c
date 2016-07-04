//
//  main.c
//  dsaa
//
//  Created by JohnTsai on 16/7/4.
//  Copyright © 2016年 JohnTsai. All rights reserved.
//

#include <stdio.h>
#include "pow.h"
#include "gcd.h"
#include "fibo.h"
#include "stack.h"
#include <stdlib.h>

int main(int argc, const char * argv[])
{
    //乘方
    printf("%.0f的%d次方等于%.0f\n",5.0,3,pow_recursive(5.0,3));
    printf("%.0f的%d次方等于%.0f\n",5.0,3,pow_non_recursive(5.0,3));
    
    //最大公约数
    int a = 1989;
    int b = 867;
    int c = gcd(a,b);
    printf("%d和%d的最大公约数是%d\n",a,b,c);
    
    //斐波那契数列
    printf("第%d个斐波那契数列中的数是%d\n",20,fibonacci_non_recursive(20));
    

    //栈
    stackT * stack = (stackT*)malloc(sizeof(stackT));
    //初始化
    stackInit(stack, 10);
    int isEmpty = stackIsEmpty(stack);
    
    printf("The stack is Empty?%s\n",isEmpty==1?"true":"false");
    
    //入栈
    stackPush(stack, 'a');
    stackPush(stack, 'b');
    stackPush(stack, 'c');
    stackPush(stack, 'd');
    stackPush(stack, 'e');
    
    
    int i = 0;
    //出栈
    while(!stackIsEmpty(stack))
    {
        printf("第%d次出栈的元素是:%c\n",i++,stackPop(stack));
    }
    

    return 0;
}
