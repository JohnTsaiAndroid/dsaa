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
