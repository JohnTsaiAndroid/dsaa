//
//  stack.c
//  dsaa
//
//  Created by JohnTsai on 16/7/4.
//  Copyright © 2016年 JohnTsai. All rights reserved.
//

#include "stack.h"
//用于动态分配内存
#include <stdlib.h>

//栈的初始化，大小为maxSize
void stackInit(stackT *stack,int maxSize)
{
    stackElementT * newContents
          = (stackElementT *)malloc(sizeof(stackElementT)*maxSize);
    if(newContents==NULL)
    {
        printf("No memory to alloc stack");
        exit(1);
    }
    
    stack->contents = newContents;
    stack->maxSize = maxSize;
    stack->top = -1;
}

//栈的销毁
void stackDestroy(stackT *stack)
{
    free(stack->contents);
    
    stack->contents = NULL;
    stack->maxSize = 0;
    stack->top = -1;
}

//判断栈是否为空
int stackIsEmpty(stackT *stack)
{
    return stack->top<0;
}

//判断栈是否满
int stackIsFull(stackT *stack)
{
    return stack->top>=stack->maxSize-1;
}

//出栈
stackElementT stackPop(stackT * stack)
{
    if(stackIsEmpty(stack))
    {
        printf("stack is empty,cannot pop an element from it!");
        exit(1);
    }
    return stack->contents[stack->top--];
}

//入栈
void stackPush(stackT * stack,stackElementT element)
{
   if(stackIsFull(stack))
   {
       printf("stack is full,cannot push an element into stack!");
       exit(1);
   }
    stack->contents[++stack->top] = element;
}