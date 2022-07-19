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
    struct biDirNode *duplicateHead = head->nextNode ;

    if(head->value == target){
        duplicateHead->preNode = NULL ;
        head->nextNode = NULL ;
        free(head) ;
        return duplicateHead ;
    }else{
        struct biDirNode *n = head ;

        int k=1 ;
        while(n->value != target){
            n = n->nextNode ;
            k++ ;
        }
        struct biDirNode *beforeT = n->preNode ;
        struct biDirNode *afterT = n->nextNode ;
        nodeConnect(beforeT, afterT) ;
        return head ;
    }
}

void printLinkedList(struct biDirNode *n, int amount){
    printf("[") ;
    for(int i=0; i<amount; i++){
        printf("%d, ", n->value) ;
        n = n->nextNode ;
    }
    printf("\b\b]") ;
}

void printLinkedListReverse(struct biDirNode *n, int amount){
    printf("[") ;
    for(int i=amount-1; i>=0; i--){
        printf("%d, ", n->value) ;
        n = n->preNode ;
    }
    printf("\b\b]") ;
}

void printLinkedListReverseSpecial(struct biDirNode *n, int amount){
    for(int i=amount-1; i>=0; i--){
        printf("%d ", n->value) ;
        n = n->preNode ;
    }
}

void freeNode(struct biDirNode *head){
    free(head) ;
}

#endif //SUMMER_DS_HW_LINKEDLISTBYHOFF_H
