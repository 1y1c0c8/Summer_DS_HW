//
// Created by kenny on 2022/8/2.
//

#ifndef SUMMERDS_HW_BINARYSEARCHTREEBYHOFF_H
#define SUMMERDS_HW_BINARYSEARCHTREEBYHOFF_H

#include <stdio.h>
#include <stdlib.h>

struct bstNode{
    struct bstNode *fNode ;
    int value ;
    struct bstNode *lChild ;
    struct bstNode *rChild ;
};

//put pointer of rChild of root
struct bstNode *findRMin(struct bstNode *root){
    struct bstNode *min = malloc(sizeof(struct bstNode)) ;

    while(root->lChild!=NULL){
        min = root->lChild ;
    }
}

struct bstNode* dig(struct bstNode *root, int value){
    if(root->value > value && root->lChild!=NULL)
        dig(root->lChild, value) ;
    else if(root->value < value && root->rChild!=NULL)
        dig(root->rChild, value) ;
    else if(root->value > value && root->lChild==NULL) {
        return root;
    }
    else if(root->value < value && root->rChild==NULL) {
        return root;
    }
}

void bstCreate(struct bstNode **root, int value){
    //struct bstNode **copyRoot = root ;

    if((*root) == NULL){
        struct bstNode *newTNode = malloc(sizeof(struct bstNode)) ;
        newTNode->fNode = NULL ;
        newTNode->value = value ;
        newTNode->lChild = NULL ;
        newTNode->rChild = NULL ;
        *root = newTNode ;
    }
    else if((*root)->lChild == NULL && (*root)->rChild == NULL){
        if((*root)->value > value){
            struct bstNode *newLChild = malloc(sizeof(struct bstNode)) ;
            newLChild->fNode = *root ;
            newLChild->value = value ;
            newLChild->lChild = NULL ;
            newLChild->rChild = NULL ;
            (*root)->lChild = newLChild ;
        }
        else{
            struct bstNode *newRChild = malloc(sizeof(struct bstNode)) ;
            newRChild->fNode = *root ;
            newRChild->value = value ;
            newRChild->lChild = NULL ;
            newRChild->rChild = NULL ;
            (*root)->rChild = newRChild ;
        }
    }
    else{
        struct bstNode *loadNode = dig(*root, value) ;

        struct bstNode *newChild = malloc(sizeof(struct bstNode)) ;
        newChild->fNode = NULL ;
        newChild->value = value ;
        newChild->lChild = NULL ;
        newChild->rChild = NULL ;

        if(loadNode->value > value){
            loadNode->lChild = newChild ;
            newChild->fNode = loadNode ;
        }else if(loadNode->value < value){
            loadNode->rChild = newChild ;
            newChild->fNode = loadNode ;
        }
    }
}

// .lChild -> .fNode -> .rChild
void inorderBSTTraversal(struct bstNode **root){
    if((*root)->lChild!=NULL)
        inorderBSTTraversal(&(*root)->lChild) ;
    printf("[%2d] ", (*root)->value) ;
    if((*root)->rChild!=NULL)
        inorderBSTTraversal(&(*root)->rChild) ;
}

void preorderBSTTraversal(struct bstNode **root){
    printf("[%2d] ", (*root)->value) ;
    if((*root)->lChild!=NULL)
        preorderBSTTraversal(&(*root)->lChild) ;
    if((*root)->rChild!=NULL)
        preorderBSTTraversal(&(*root)->rChild) ;
}

void postorderBSTTraversal(struct bstNode **root){
    if((*root)->lChild!=NULL)
        postorderBSTTraversal(&(*root)->lChild) ;
    if((*root)->rChild!=NULL)
        postorderBSTTraversal(&(*root)->rChild) ;
    printf("[%2d] ", (*root)->value) ;
}

struct bstNode* bfs(struct bstNode *root, int target){

}

struct bstNode* dfs(struct bstNode *root, int target){

}


//void treeDelete(struct bstNode **root, int target){
//}



#endif //SUMMERDS_HW_BINARYSEARCHTREEBYHOFF_H
