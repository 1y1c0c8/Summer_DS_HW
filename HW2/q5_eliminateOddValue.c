#include <stdio.h>
#include <stdlib.h>
#include "singleLinkedListByHoff.h"

int main(){
    printf("How many nodes do you want:\n") ;
    int amount=0 ;
    scanf("%d", &amount) ;

    printf("Please key in the elements seperated by space:\n") ;
    struct node *nodes[amount] ;
    for(int i=0; i<amount; i++){
        int value=0 ;
        scanf("%d", &value) ;
        nodes[i] = singleNodeCreate(value) ;
        if(i!=0)
            singleNodeConnect(nodes[i-1], nodes[i]) ;
    }
    nodes[amount-1]->nextNode = nodes[0] ;

    struct node *traversal = nodes[0] ;
//    struct node *new ;

    int remainNode=amount ;
    for(int i=0; i<amount; i++){
        if((traversal->value)%2){
            remainNode-- ;
        }
        traversal = traversal->nextNode ;
    }

    struct node *newNodes[remainNode] ;
    traversal = nodes[0] ;
    int index=remainNode-1 ;
    for(int i=0; i<amount; i++){
        if(!(traversal->value%2)) {
            newNodes[index] = traversal;
            index-- ;
        }
        traversal = traversal->nextNode ;
    }

    for(int i=0; i<remainNode; i++){
        if(i!=0)
            singleNodeConnect(newNodes[i-1], newNodes[i]) ;
    }
    newNodes[remainNode-1]->nextNode = newNodes[0] ;

    printf("After processed:\n") ;
    printSingleLinkedListSpecial(newNodes[0], remainNode) ;

    return 0 ;
}