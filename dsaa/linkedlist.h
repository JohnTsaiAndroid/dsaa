//
//  linkedlist.h
//  dsaa
//
//  Created by JohnTsai on 16/7/5.
//  Copyright © 2016年 JohnTsai. All rights reserved.
//

#ifndef linkedlist_h
#define linkedlist_h

#include <stdio.h>

typedef int linkedListElementT;

typedef struct linkedListElement{
    linkedListElementT value;
    struct linkedListElement * next;
}linkedListNode;

typedef struct{
    linkedListNode * head;
}linkedList;

linkedList * createLinkedList();
int searchLinkedList(linkedList *,linkedListElementT );
void insertLinkedList(linkedList *,linkedListElementT);
linkedListElementT removeLinkedList(linkedList *,int );
int isEmptyLinkedList(linkedList *);
int sizeofLinkedList(linkedList *);
void printLinkedList(linkedList *);

#endif /* linkedlist_h */
