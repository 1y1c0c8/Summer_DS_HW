#include <stdio.h>
#include <stdlib.h>
#include "linkedListByHoff.h"

int main(){
    int amount=0 ;
    printf("How many nodes do you want:\n") ;
    scanf("%d", &amount) ;

    printf("Please key in the elements seperated by space:\n") ;
    int elements[amount] ;
    for(int i=0; i<amount; i++){
        int value=0 ;
        scanf("%d", &value) ;
        elements[i] = value ;
    }

    struct biDirNode *nodes[amount] ;
    for(int i=0; i<amount; i++){
        nodes[i] = nodeCreate(elements[i]) ;
    }

    for(int i=0; i<amount-1; i++)
        nodeConnect(nodes[i], nodes[i+1]) ;

    printf("Key in the element you want to eliminate:\n") ;

    int target=0 ;
    scanf("%d", &target) ;
    struct biDirNode *newHead = nodeDelete(nodes[0], target) ;


    //printf("PRINT\n") ;
//    struct biDirNode *n = ans ;
//    struct biDirNode *pre = ans->preNode ;
//    struct biDirNode *next = ans->nextNode ;

//    nodeConnect(pre, next) ;
//    freeNode(n) ;
//    struct biDirNode *head = nodes[0] ;

    printLinkedList(newHead, amount-1) ;

    //printf("STOP!") ;

    return 0 ;
}