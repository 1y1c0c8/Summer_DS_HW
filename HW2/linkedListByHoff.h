//
// Created by kenny on 2022/7/18.
//

#ifndef SUMMER_DS_HW_LINKEDLISTBYHOFF_H
#define SUMMER_DS_HW_LINKEDLISTBYHOFF_H

#include <stdio.h>
#include <stdlib.h>

struct biDirNode{
    struct biDirNode *preNode ;
    int value ;
    struct biDirNode *nextNode ;
};

struct biDirNode* nodeCreate(int value){
    struct biDirNode *newNode ;
    newNode = malloc(sizeof(struct biDirNode)) ;
    newNode->preNode = NULL ;
    newNode->value = value ;
    newNode->nextNode = NULL ;
    return newNode ;
}

void nodeConnect(struct biDirNode *pre, struct biDirNode *new){
    pre->nextNode = new ;
    new->preNode = pre ;
}

struct biDirNode* nodeDelete(struct biDirNode *head, int target){
    int choice=0 ;
    struct biDirNode *duplicateHead = head->nextNode ;

    if(head->value == target){
        duplicateHead->preNode = NULL ;
        head->nextNode = NULL ;
        free(head) ;
        return duplicateHead ;
    }else{
        struct biDirNode *n = head ;

        //printf("Start traversal till the value of curNode is target:\n") ;
        int k=1 ;
        while(n->value != target){
            //printf("The no.%d cycle, the value of curNode is %d.\n", k, n->value) ;
            n = n->nextNode ;
            k++ ;
        }
        struct biDirNode *beforeT = n->preNode ;
        struct biDirNode *afterT = n->nextNode ;
        nodeConnect(beforeT, afterT) ;
        return head ;
    //printf("TEST POINT!") ;
    }
}

void freeNode(struct biDirNode *start){
    free(start) ;
}

#endif //SUMMER_DS_HW_LINKEDLISTBYHOFF_H
