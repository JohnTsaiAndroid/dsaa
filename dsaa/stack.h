//
//  stack.h
//  dsaa
//
//  Created by JohnTsai on 16/7/4.
//  Copyright © 2016年 JohnTsai. All rights reserved.
//

#ifndef stack_h
#define stack_h

#include <stdio.h>

//预定义栈中元素类型，后期修改类型只需要修改此处
typedef char stackElementT;

typedef struct
{
    stackElementT * contents;
    int top;
    int maxSize;
}stackT;


void stackInit(stackT *,int);
void stackDestroy(stackT *);
int  stackIsEmpty(stackT *);
int  stackIsFull(stackT *);
stackElementT stackPop(stackT *);
void stackPush(stackT *,stackElementT);

#endif /* stack_h */
