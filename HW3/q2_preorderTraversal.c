#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "treeByHoff.h"

int main(){
    struct tNode  *root = NULL ;
    struct tNode **rootP = &root ;
    struct tNode  *temp = NULL ;
    struct tNode **curNodeP = &temp ;
    bool True = true;
    bool arrive = false ;
    bool *arriveP = &arrive ;

    while(True){
        printf("Enter data to be inserted or type -1 for no insertion: ") ;
        int value=0 ;
        scanf("%d", &value) ;
        tCreate(curNodeP, value, arriveP, rootP) ;

        value = value == -1 ? (*curNodeP)->value : value ;

        if((*curNodeP)->curMode == 1){
            printf("\bEnter left child of: %d\n", value) ;
        }
        else if((*curNodeP)->curMode == 2){
            printf("\bEnter right child of: %d\n", value) ;
        }

        if((*curNodeP == *rootP) && ((*rootP)->curMode == -1))
            True = false ;
    }

    printf("\b") ;
    preorderTraversal(curNodeP) ;

    return 0 ;
}