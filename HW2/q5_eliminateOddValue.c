#include <stdio.h>
#include "linkedListByHoff.h"

int isOdd(int value){
    return (value)%2 ;
}

int main(){
    int amount=0 ;
    scanf("%d", &amount) ;

    struct biDirNode *nodes[amount] ;
    for(int i=0; i<amount; i++){
        int value ;
        scanf("%d", &value) ;
        nodes[i] = nodeCreate(value) ;

        if(i>0)
            nodeConnect(nodes[i-1], nodes[i]) ;
    }

    struct biDirNode *newHead = nodeCreate(1) ;
    struct biDirNode *n = nodes[0] ;
    struct biDirNode *tail = newHead ;

    int i=0;
    int evenValueAmount=0 ;
    while(i<amount){
        if(!isOdd(n->value)) {
            nodeConnect(tail, n);
            tail = tail->nextNode ;
            evenValueAmount++ ;
        }
        n = n->nextNode ;
        i++ ;
    }

    printLinkedListReverseSpecial(tail, evenValueAmount) ;


    return 0 ;
}