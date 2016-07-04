//
//  stack_linkedlist.h
//  dsaa
//
//  Created by JohnTsai on 16/7/4.
//  Copyright © 2016年 JohnTsai. All rights reserved.
//

#ifndef stack_linkedlist_h
#define stack_linkedlist_h

#include <stdio.h>

typedef char stackElementT;
typedef struct stackElement{
    stackElementT value;
    struct stackElement * next;
    
}stackNode;

typedef struct{
    stackNode * top;
}stackLLT;

void stackllInit(stackLLT *);
void stackllDestroy(stackLLT *);
int stackllIsEmpty(stackLLT *);
void stackllPush(stackLLT *,stackNode *);
stackElementT stackllPop(stackLLT *);

#endif /* stack_linkedlist_h */
