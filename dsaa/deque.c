//
//  deque.c
//  dsaa
//
//  Created by JohnTsai on 16/7/5.
//  Copyright © 2016年 JohnTsai. All rights reserved.
//

#include "deque.h"
#include <stdlib.h>

deque * createDeque()
{
    deque * d = (deque *)malloc(sizeof(deque));
    d->front = NULL;
    d->rear = NULL;
    return d;
}
void push_front(deque * d,dequeElementT element)
{
    dequeNode * node = (dequeNode *)malloc(sizeof(dequeNode));
    node->next = NULL;
    node->pre = NULL;
    node->value = element;
    
    if(is_empty_deque(d))
    {
        d->front = node;
        d->rear = node;
    }else{
        d->front->pre = node;
        node->next =d->front;
        d->front = node;
    }
    
}
void push_back(deque * d,dequeElementT element)
{
    dequeNode * node = (dequeNode *)malloc(sizeof(dequeNode));
    node->next = NULL;
    node->pre = NULL;
    node->value = element;
    
    if(is_empty_deque(d))
    {
        d->front = node;
        d->rear = node;
    }else{
        d->rear->next = node;
        node->pre = d->rear;
        d->rear = node;
    }
    
}
dequeElementT pop_back(deque * d)
{
   if(is_empty_deque(d))
   {
       printf("the deque is empty,cannot pop element from back");
       exit(1);
   }
    dequeElementT value = d->rear->value;
    if(d->rear->pre==NULL)
    {
        dequeNode * removed = d->rear;
        d->rear = NULL;
        d->front = NULL;
        free(removed);
    }else{
        dequeNode * removed = d->rear;
        d->rear = d->rear->pre;
        free(removed);
    }
    return value;
}
dequeElementT pop_front(deque * d)
{
    if(is_empty_deque(d))
    {
        printf("the deque is empty,cannot pop element from front");
        exit(1);
    }
    dequeElementT value = d->front->value;
    if(d->front->next==NULL)
    {
        dequeNode * removed = d->front;
        d->front = NULL;
        d->rear = NULL;
        free(removed);
    }else{
        dequeNode * removed = d->front;
        d->front = d->front->next;
        free(removed);
    }
    return value;
}
dequeElementT back_deque(deque * d)
{
    if(is_empty_deque(d))
    {
        printf("the deque is empty,cannot get value of rear of deque");
        exit(1);
    }
    return d->rear->value;
}
dequeElementT front_deque(deque * d)
{
    if(is_empty_deque(d))
    {
        printf("the deque is empty,cannot get value of front of deque");
        exit(1);
    }
    return d->front->value;
}
int is_empty_deque(deque * d)
{
    return d->rear==NULL&&d->front == NULL;
}

void print_element_front(deque * d)
{
    dequeNode * temp_front = d->front;
    while(temp_front!=NULL)
    {
        printf("%d ",temp_front->value);
        temp_front = temp_front->next;
    }
    
}
void print_element_back(deque *d)
{
    dequeNode * temp_back = d->rear;
    while(temp_back!=NULL)
    {
        printf("%d ",temp_back->value);
        temp_back = temp_back->pre;
    }
}