//
//  linkedlist.c
//  dsaa
//
//  Created by JohnTsai on 16/7/5.
//  Copyright © 2016年 JohnTsai. All rights reserved.
//

#include "linkedlist.h"
#include <stdlib.h>

linkedList * createLinkedList()
{
    linkedList * list = (linkedList *)malloc(sizeof(linkedList));
    list->head = NULL;
    return list;
}
int searchLinkedList(linkedList * list,linkedListElementT element)
{
    if(isEmptyLinkedList(list)){
        printf("the linked list is empty");
        return -1;
    }
    linkedListNode * temp = list->head;
    int index = 1;
    while(temp!=NULL){
        if(element==temp->value){
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
}
void insertLinkedList(linkedList * list,linkedListElementT element)
{
    linkedListNode * temp = list->head;
    linkedListNode * node = (linkedListNode*)malloc(sizeof(linkedListNode));
    node->next = NULL;
    node->value = element;
    if(list->head==NULL)
    {
        list->head = node;
    }
    else{
        while(temp->next!=NULL)
        {
            temp= temp->next;
        }
        temp->next = node;
    }
}
linkedListElementT removeLinkedList(linkedList * list,int index)
{
    if(isEmptyLinkedList(list))
    {
        printf("the linked list is empty");
        exit(1);
    }
    if(index>sizeof(list)||index<1)
    {
        printf("wrong argument index %d",index);
        exit(1);
    }
    if(index == 1){
        linkedListElementT value = list->head->value;
        list->head = list->head->next;
        return value;
    }
    linkedListNode * cur = list->head;
    for(int i = 1;i< index-1;i++){
        cur = cur->next;
    }
    linkedListNode * toRemove = cur->next;
    linkedListElementT value = toRemove->value;
    cur->next = toRemove->next;
    free(toRemove);
    return value;
    
}
int isEmptyLinkedList(linkedList * list)
{
    return list->head==NULL;
}
int sizeofLinkedList(linkedList * list)
{
    int size = 0;
    linkedListNode * temp = list->head;
    while(temp!=NULL)
    {
        size++;
        temp = temp->next;
    }
    return  size;
}
void printLinkedList(linkedList *list)
{
    if(isEmptyLinkedList(list))
    {
        printf("the linked list is empty");
        exit(1);
    }
    linkedListNode * temp = list->head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->value);
        temp = temp->next;
    }

}