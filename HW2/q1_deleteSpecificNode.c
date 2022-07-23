#include <stdio.h>
#include <stdlib.h>
#include "singleLinkedListByHoff.h"

int main(){
    printf("How many nodes do you want?\n") ;
    int amount=0 ;
    scanf("%d", &amount) ;


    struct node *nodes[amount];
    printf("Please key in the elements seperated by space:\n") ;
    for(int i=0; i<amount; i++){
        int value=0 ;
        scanf("%d", &value) ;
        nodes[i] = singleNodeCreate(value) ;

        if(i!=0){
            singleNodeConnect(nodes[i-1], nodes[i]) ;
        }
    }

    printf("Key in the element you want to eliminate:\n") ;
    int target=0 ;
    scanf("%d", &target) ;

    struct node *newNode = singleNodeDelete(nodes[0], target) ;

    printSingleLinkedList(newNode, amount-1) ;


    return 0;
}