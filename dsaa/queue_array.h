//
//  queue_array.h
//  dsaa
//
//  Created by JohnTsai on 16/7/5.
//  Copyright © 2016年 JohnTsai. All rights reserved.
//

#ifndef queue_array_h
#define queue_array_h

#include <stdio.h>

typedef char queueArrayElement;

#define MAX_SIZE 100

typedef struct{
    queueArrayElement contents[MAX_SIZE];
    int front;
    int rear;
}queueArray;

queueArray * createQueueArray();
int isEmptyQueue(queueArray *);
int isFullQueue(queueArray *);
void enqueQueue(queueArray * ,queueArrayElement);
queueArrayElement dequeQueue(queueArray * );
queueArrayElement peekQueueArray(queueArray *);

#endif /* queue_array_h */
