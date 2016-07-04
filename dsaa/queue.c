//
//  queue.c
//  dsaa
//
//  Created by JohnTsai on 16/7/4.
//  Copyright © 2016年 JohnTsai. All rights reserved.
//

#include "queue.h"
#include <stdlib.h>

void createQueue(queueT * queue)
{
    queue = (queueT *)malloc(sizeof(queueT));
    queue->front = NULL;
    queue->rear = NULL;
}


queueElementT peekQueue(queueT * queue)
{
    if(queue->front == NULL)
    {
        printf("the queue is empty!");
        exit(1);
    }
    return queue->front->value;
}
void enqueueQueue(queueT * queue ,queueElementT element)
{
    queueNode * node = (queueNode *)malloc(sizeof(queueNode));
    node->value = element;
    node->next = NULL;
    
    if(queue->front==NULL&&queue->rear==NULL){
        queue->front = node;
        queue->rear = node;
    }else{
        queue->rear->next = node;
        queue->rear = node;
    }
    
}
queueElementT dequeueQueue(queueT * queue)
{
    if(queue->front ==NULL)
    {
        printf("the queue is empty");
        exit(1);
    }
    queueElementT value = queue->front->value;
    queueNode *temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    return  value;
}
