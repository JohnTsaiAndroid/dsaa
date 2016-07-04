//
//  stack_linkedlist.c
//  dsaa
//
//  Created by JohnTsai on 16/7/4.
//  Copyright © 2016年 JohnTsai. All rights reserved.
//

#include "stack_linkedlist.h"
#include <stdlib.h>

void stackllInit(stackLLT * stack)
{
    stack->top = NULL;
}


void stackllDestroy(stackLLT * stack)
{
    while(!stackllIsEmpty(stack)){
        stackNode * temp = stack->top;
        stack->top = stack->top->next;
        temp->next = NULL;
        free(temp);
    }
}

int stackllIsEmpty(stackLLT * stack)
{
    return stack->top==NULL;
}

void stackllPush(stackLLT * stack,stackNode * node)
{
    if(stackllIsEmpty(stack))
    {
       stack->top = node;
    }
    else
    {
       node->next = stack->top;
       stack->top = node;
    }
}

stackElementT stackllPop(stackLLT * stack)
{
    if(stackllIsEmpty(stack))
    {
        printf("The stack is empty,cannot pop an element from it");
        exit(1);
    }
    stackElementT value  = stack->top->value;
    stack->top = stack->top->next;
    return value;
}