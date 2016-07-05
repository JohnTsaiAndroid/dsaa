//
//  queue_array.c
//
//  循环数组实现队列
//
//  dsaa
//
//  Created by JohnTsai on 16/7/5.
//  Copyright © 2016年 JohnTsai. All rights reserved.
//

#include "queue_array.h"
#include <stdlib.h>

queueArray * createQueueArray()
{
    queueArray *queue = (queueArray*)malloc(sizeof(queueArray));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isEmptyQueue(queueArray * queue)
{
    return queue->front == -1&& queue->rear ==-1;
}

int isFullQueue(queueArray * queue)
{
    return (queue->rear+1)%MAX_SIZE==queue->front;
}

//入队
void enqueQueue(queueArray * queue,queueArrayElement element)
{
   if(isEmptyQueue(queue))
   {
       queue->front = queue->rear = 0;
       queue->contents[queue->rear] = element;
   }else if(isFullQueue(queue)){
       printf("the queue is full\n");
       exit(1);
   }else{
       queue->rear = (queue->rear+1)%MAX_SIZE;
       queue->contents[queue->rear] = element;
   }
}

//出队
queueArrayElement dequeQueue(queueArray * queue)
{
    if(isEmptyQueue(queue))
    {
        printf("the stack is empty");
        exit(1);
    }
    queueArrayElement result = queue->contents[queue->front];
    if(queue->front==queue->rear)
    {
        queue->front = queue->rear = -1;
    }else
    {
        queue->front=(queue->front+1)%MAX_SIZE;
    }
    return result;
}

//获取队列最前面的元素
queueArrayElement peekQueueArray(queueArray * queue)
{
    if(isEmptyQueue(queue))
    {
        printf("the stack is empty");
        exit(1);

    }
    return queue->contents[queue->front];
}