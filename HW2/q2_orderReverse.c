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

        if(i>0)
            singleNodeConnect(nodes[i-1], nodes[i]) ;
    }

    struct node *newNodes[amount] ;
    struct node *traversal = nodes[0] ;

    for(int i=amount-1; i>=0; i--){
        newNodes[i] = singleNodeCreate(traversal->value) ;
        traversal = traversal->nextNode ;
    }

    for(int i=1; i<amount; i++){
        singleNodeConnect(newNodes[i-1], newNodes[i]) ;
    }

    printf("The linked list after reverse:\n") ;
    printSingleLinkedList(newNodes[0], amount) ;

    return 0 ;
}

// 法規本土化 已完成一份章程 希望完成全部的法規
// 論壇/茶會/演講 ->創聯
//