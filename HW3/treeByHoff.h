#ifndef SUMMERDS_HW_TREE_H
#define SUMMERDS_HW_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct tNode{
    struct tNode *fNode ;
    int value ;
    struct tNode *lChild ;
    struct tNode *rChild ;
    int curMode ;
    int order ;
};

void nextCurNode(struct tNode **curNode, struct tNode *root, bool *arrive){
    while((*curNode)->curMode == -1){
        if((*curNode)->fNode != NULL)
            (*curNode) = (*curNode)->fNode ;

        if(*curNode == root)
            break ;
    }
}

struct tNode* tCreate(struct tNode **curNode, int value, bool *arriveP, struct tNode **rootP){

    if((*curNode) == NULL) {
        struct tNode *root = malloc(sizeof(struct tNode)) ;

        root->fNode = NULL ;
        root->value = value ;
        root->lChild = NULL ;
        root->rChild = NULL ;
        root->curMode = 1 ;
        root->order = 1 ;

        (*rootP) = root ;
        (*curNode) = root ;
    }
    else if((*curNode)->curMode == 1){
        struct tNode *newTNode = malloc(sizeof(struct tNode)) ;

        (*curNode)->curMode = 2 ;
        if(value != -1) {
            (*curNode)->lChild = newTNode;

            newTNode->fNode = (*curNode);
            newTNode->value = value ;
            newTNode->lChild = NULL ;
            newTNode->rChild = NULL ;
            newTNode->curMode = 1 ;
            newTNode->order = 2*(newTNode->fNode->order) ;

            (*curNode) = newTNode ;
        }
    }

    else if((*curNode)->curMode == 2){
        struct tNode *newTNode = malloc(sizeof(struct tNode)) ;

        (*curNode)->curMode = -1 ;
        if(value != -1){
            (*curNode)->rChild = newTNode;

            newTNode->fNode = (*curNode);
            newTNode->value = value ;
            newTNode->lChild = NULL ;
            newTNode->rChild = NULL ;
            newTNode->curMode = 1 ;
            newTNode->order = 2*(newTNode->fNode->order) ;

            (*curNode) = newTNode ;
        }

        if((*curNode)->curMode == -1)   nextCurNode(curNode, *rootP, arriveP) ;
    }
}


// .lChild -> .fNode -> .rChild
void inorderTraversal(struct tNode **root){
    if((*root)->lChild!=NULL)
        inorderTraversal(&(*root)->lChild) ;
    printf("%d ", (*root)->value) ;
    if((*root)->rChild!=NULL)
        inorderTraversal(&(*root)->rChild) ;
}

void inorderTraversalII(struct tNode **root, struct tNode *nodesHeadP){
    if((*root)->lChild!=NULL)
        inorderTraversal(&(*root)->lChild) ;
//    printf("%d ", (*root)->value) ;

    *( nodesHeadP+((*root)->order)*(sizeof(struct tNode)) ) = *(*root) ;

    if((*root)->rChild!=NULL)
        inorderTraversal(&(*root)->rChild) ;
}

void preorderTraversal(struct tNode **root){
    printf("%d ", (*root)->value) ;
    if((*root)->lChild!=NULL)
        preorderTraversal(&(*root)->lChild) ;
    if((*root)->rChild!=NULL)
        preorderTraversal(&(*root)->rChild) ;
}

void postorderTraversal(struct tNode **root){
    if((*root)->lChild!=NULL)
        postorderTraversal(&(*root)->lChild) ;
    if((*root)->rChild!=NULL)
        postorderTraversal(&(*root)->rChild) ;
    printf("%d ", (*root)->value) ;
}

#endif //SUMMERDS_HW_TREE_H
