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
#include "queue_array.h"
#include "linkedlist.h"
#include "deque.h"
#include "binary_search_tree.h"

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
        printf("当前队列最前面的元素是%d\t",peekQueue(queue));
        printf("第%d个从队列中出来的元素是%d\n",i++,dequeueQueue(queue));
    }
    
    queueArray* queueArray = createQueueArray();
    for(int k = 0;k<100;k++)
    {
        enqueQueue(queueArray, k);
    }
    
    printf("队列是否已满:%s\n",isFullQueue(queueArray)>0?"true":"false");
    
    
    for(int k = 0;k<50;k++)
    {
        queueArrayElement e = dequeQueue(queueArray);
        printf("出队的元素是:%d\n",e);
    }
    
    printf("队列是否已空:%s\n",isEmptyQueue(queueArray)>0?"true":"false");
    
    for(int k = 0;k<50;k++)
    {
        enqueQueue(queueArray, k);
    }
    
    for(int k = 0;k<100;k++)
    {
        queueArrayElement e = dequeQueue(queueArray);
        printf("出队的元素是:%d\n",e);
    }
    
    linkedList *list = createLinkedList();
    for(int k = 0;k<20;k++)
    {
        insertLinkedList(list, 2*k-1);
    }
    printLinkedList(list);
    
    printf("\n删除前linkedlist的长度是%d\n",sizeofLinkedList(list));
    
    linkedListElementT element =  removeLinkedList(list, 1);
    printf("从linkedlist删除的第%d个元素是%d\n",5,element);
    
    printLinkedList(list);
    
    printf("\n删除后linkedlist的长度是%d\n",sizeofLinkedList(list));
    printf("linkedlist是否为空%s\n",isEmptyLinkedList(list)>0?"true":"false");
    
    for(int k = 0;k<5;k++)
    {
        printf("在linkedlist中查找%d的下标是%d\n",k,searchLinkedList(list,k));
    }
    
    deque * d = createDeque();
    for(int i = 0;i<5;i++)
    {
        push_front(d, 2*i+1);
        push_back(d, 2*i);
    }
    
    while(!is_empty_deque(d))
    {
        dequeElementT front = pop_front(d);
        printf("%d \t",front);
    }
    
    for(int i = 0;i<5;i++)
    {
        push_front(d, 2*i+1);
        push_back(d, 2*i);
    }
    
    printf("\n从前往后打印双端队列的值:\n");
    print_element_front(d);
    
    printf("\n从后往前打印双端队列的值:\n");
    print_element_back(d);
    
    
    while(!is_empty_deque(d))
    {
        dequeElementT back = pop_back(d);
        printf("\n%d",back);
    }
    
    printf("\n双端队列是否为空:%s\n",is_empty_deque(d)?"是":"否");
    
    
    //二叉搜索树
    
    binaryTreeNode * root = NULL;
    insert_bst(&root,10);
    insert_bst(&root, 8);
    insert_bst(&root, 7);
    insert_bst(&root, 9);
    insert_bst(&root, 12);
    insert_bst(&root, 11);
    insert_bst(&root, 13);
    
    printf("\n前序遍历:\n");
    print_preorder(root);
    printf("\n中序遍历:\n");
    print_inorder(root);
    printf("\n后序遍历:\n");
    print_postorder(root);
    
    binaryTreeNode * temp = search_bst(&root, 11);
    printf("%d",temp->value);
    
    destroy_bst(root);
    
    return 0;
}
