//
//  main.c
//  dsaa
//
//  Created by JohnTsai on 16/7/4.
//  Copyright © 2016年 JohnTsai. All rights reserved.
//

#include <stdio.h>
#include "pow.h"
#include "gcd.h"
#include "fibo.h"
#include "stack.h"
#include <stdlib.h>
#include "stack_linkedlist.h"
#include "queue.h"

int main(int argc, const char * argv[])
{
    //乘方
    printf("%.0f的%d次方等于%.0f\n",5.0,3,pow_recursive(5.0,3));
    printf("%.0f的%d次方等于%.0f\n",5.0,3,pow_non_recursive(5.0,3));
    
    //最大公约数
    int a = 1989;
    int b = 867;
    int c = gcd(a,b);
    printf("%d和%d的最大公约数是%d\n",a,b,c);
    
    //斐波那契数列
    printf("第%d个斐波那契数列中的数是%d\n",20,fibonacci_non_recursive(20));
    

    //栈
    stackT * stack = (stackT*)malloc(sizeof(stackT));
    stackT stack2;
    
    //初始化
    stackInit(stack, 10);
    int isEmpty = stackIsEmpty(stack);
    
    printf("The stack is Empty?%s\n",isEmpty==1?"true":"false");
    
    //入栈
    stackPush(stack, 'a');
    stackPush(stack, 'b');
    stackPush(stack, 'c');
    stackPush(stack, 'd');
    stackPush(stack, 'e');
    
    
    int i = 0;
    //出栈
    while(!stackIsEmpty(stack))
    {
        printf("第%d次出栈的元素是:%c\n",i++,stackPop(stack));
    }
    
    stackDestroy(stack);
    free(stack);
    
    stackInit(&stack2,5);
    printf("The stack is Empty?%s\n",isEmpty==1?"true":"false");
    stackPush(&stack2, 'a');
    stackPush(&stack2, 'b');
    stackPush(&stack2, 'c');
    stackPush(&stack2, 'd');
    stackPush(&stack2, 'e');
    
    printf("The stack is full?%s\n",stackIsFull(&stack2)==1?"true":"false");
    
    i=0;
    while(!stackIsEmpty(&stack2))
    {
      printf("第%d次出栈的元素是:%c\n",i++,stackPop(&stack2));
    }
    stackDestroy(&stack2);
    
    
    
    ///使用LinkedList实现的Stack
    stackLLT stackll;
    
    stackllInit(&stackll);
    
    stackNode * node1 = (stackNode *)malloc(sizeof(stackNode));
    stackNode * node2= (stackNode *)malloc(sizeof(stackNode));
    stackNode * node3= (stackNode *)malloc(sizeof(stackNode));
    node1->value = 'z';
    node1->next = NULL;
    stackllPush(&stackll, node1);
    node2->value='y';
    node2->next = NULL;
    stackllPush(&stackll, node2);
    node3->value='x';
    node3->next = NULL;
    stackllPush(&stackll, node3);
    
    i = 0;
    while(!stackllIsEmpty(&stackll))
    {
        stackElementT result = stackllPop(&stackll);
        printf("第%d次出栈的元素是:%c\n",i++,result);

    }
    stackllDestroy(&stackll);
    
    queueT *queue = (queueT *)malloc(sizeof(queueT));
    createQueue(queue);
    enqueueQueue(queue, 1);
    enqueueQueue(queue, 2);
    enqueueQueue(queue, 3);
    i = 0;
    while(queue->front!=NULL)
    {
        printf("第%d个从队列中出来的元素是%d\n",i++,dequeueQueue(queue));
    }
    return 0;
}
