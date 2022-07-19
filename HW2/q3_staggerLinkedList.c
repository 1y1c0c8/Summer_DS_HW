#include <stdio.h>
#include "linkedListByHoff.h"

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

    struct biDirNode *odd = nodeCreate(nodes[0]->value) ;
    struct biDirNode *oddTail = odd ;
    struct biDirNode *even = nodeCreate(nodes[1]->value) ;
    struct biDirNode *evenTail = even ;

    for(int i=2; i<amount; i++){
        if(i%2 == 0){
            nodeConnect(oddTail, nodes[i]) ;
            oddTail = oddTail->nextNode ;
        }else {
            nodeConnect(evenTail, nodes[i]);
            evenTail = evenTail->nextNode;
        }
    }

    nodeConnect(oddTail, even) ;

    printLinkedList(odd, amount) ;

    return 0 ;
}