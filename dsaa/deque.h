//
//  deque.h
//  dsaa
//
//  Created by JohnTsai on 16/7/5.
//  Copyright © 2016年 JohnTsai. All rights reserved.
//

#ifndef deque_h
#define deque_h

#include <stdio.h>

typedef int dequeElementT;

typedef struct dequeElement{
    struct dequeElement * pre;
    struct dequeElement * next;
    dequeElementT value;
}dequeNode;

typedef struct{
    dequeNode * front;
    dequeNode * rear;
}deque;

deque * createDeque();
void push_front(deque *,dequeElementT);
void push_back(deque *,dequeElementT);
dequeElementT pop_back(deque *);
dequeElementT pop_front(deque *);
dequeElementT back_deque(deque *);
dequeElementT front_deque(deque *);
int is_empty_deque(deque *);
void print_element_front(deque *);
void print_element_back(deque *);

#endif /* deque_h */
