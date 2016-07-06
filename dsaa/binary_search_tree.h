//
//  binary_search_tree.h
//  dsaa
//
//  Created by JohnTsai on 16/7/6.
//  Copyright © 2016年 JohnTsai. All rights reserved.
//

#ifndef binary_search_tree_h
#define binary_search_tree_h

#include <stdio.h>

typedef int binaryTreeElementT;

typedef struct binaryTreeElement{
    binaryTreeElementT value;
    struct binaryTreeElement * left;
    struct binaryTreeElement * right;
}binaryTreeNode;


binaryTreeNode* search_bst(binaryTreeNode ** tree,binaryTreeElementT value);
void destroy_bst(binaryTreeNode * tree);
void insert_bst(binaryTreeNode ** tree,binaryTreeElementT value);
void print_preorder(binaryTreeNode * tree);
void print_inorder(binaryTreeNode * tree);
void print_postorder(binaryTreeNode * tree);


#endif /* binary_search_tree_h */
