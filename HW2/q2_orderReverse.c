#include <stdio.h>
#include "linkedListByHoff.h"

int main(){
    int amount=0 ;
    scanf("%d", &amount) ;

    struct biDirNode *nodes[amount] ;
    for(int i=0; i<amount; i++){
        int value=0 ;
        scanf("%d", &value) ;
        nodes[i] = nodeCreate(value) ;

        if(i>0)
            nodeConnect(nodes[i-1], nodes[i]) ;

    }

    struct biDirNode *tail = nodes[amount-1] ;
    printf("[") ;
    for(int i=amount-1; i>=0; i--){
        printf("%d, ", tail->value) ;
        tail = tail->preNode ;
    }
    printf("\b\b]") ;

    //printf("STOP!") ;

    return 0 ;
}