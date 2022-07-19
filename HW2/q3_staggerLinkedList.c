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

    struct biDirNode *odd =

    for(int i=0; i<amount; i++){

    }


    return 0 ;
}