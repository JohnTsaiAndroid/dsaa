//
//  queue.h
//  dsaa
//
//  Created by JohnTsai on 16/7/4.
//  Copyright © 2016年 JohnTsai. All rights reserved.
//

#ifndef queue_h
#define queue_h

#include <stdio.h>

typedef int queueElementT;

typedef struct queueElement
{
    queueElementT value;
    struct queueElement * next;
}queueNode;

typedef struct{
    queueNode * front;
    queueNode * rear;
}queueT;

void createQueue(queueT *);
queueElementT peekQueue(queueT *);
void enqueueQueue(queueT *,queueElementT);
queueElementT dequeueQueue(queueT *);

#endif /* queue_h */
