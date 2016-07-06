//
//  binary_search_tree.c
//  dsaa
//
//  Created by JohnTsai on 16/7/6.
//  Copyright © 2016年 JohnTsai. All rights reserved.
//

#include "binary_search_tree.h"
#include <stdlib.h>

binaryTreeNode* search_bst(binaryTreeNode ** tree,binaryTreeElementT value)
{
    if(!(*tree))
    {
       return NULL;
    }
    if((*tree)->value==value){
        return *tree;
    }else if((*tree)->value>value)
    {
        return  search_bst(&(*tree)->left, value);
    }else
    {
        return search_bst(&(*tree)->right, value);
        
    }
}

void destroy_bst(binaryTreeNode * tree)
{

    if(tree!=NULL)
    {
        destroy_bst(tree->left);
        destroy_bst(tree->right);
        free(tree);
    }
}

void insert_bst(binaryTreeNode ** tree,binaryTreeElementT value)
{
   if(!(*tree))
   {
       (*tree) = (binaryTreeNode*)malloc(sizeof(binaryTreeNode));
       (*tree)->left = NULL;
       (*tree)->right = NULL;
       (*tree)->value = value;
   }else{
       if(value<=(*tree)->value)
       {
           insert_bst(&(*tree)->left, value);
       }else{
           insert_bst(&(*tree)->right, value);
       }
   }
}

//前序遍历
void print_preorder(binaryTreeNode * tree)
{
   if(tree!=NULL)
   {
       printf("%d ",tree->value);
       print_preorder(tree->left);
       print_preorder(tree->right);
   }
}

//中序遍历
void print_inorder(binaryTreeNode * tree)
{
     if(tree!=NULL)
     {
         print_inorder(tree->left);
         printf("%d ",tree->value);
         print_inorder(tree->right);
     }
}

//后序遍历
void print_postorder(binaryTreeNode * tree)
{
    if(tree!=NULL){
        print_postorder(tree->left);
        print_postorder(tree->right);
        printf("%d ",tree->value);
    }

}