#include <stdio.h>

#include "treeByHoff.h"

int main(){

    struct tNode nodes[8] ;
    struct tNode *p = &nodes[1] ;

    nodes[1].value = 10 ;
    nodes[1].fNode = NULL ;
    nodes[1].lChild = &nodes[2] ;
    nodes[1].rChild = &nodes[3] ;

    nodes[2].value = 11 ;
    nodes[2].fNode = &nodes[1] ;
    nodes[2].lChild = &nodes[4] ;
    nodes[2].rChild = NULL ;

    nodes[3].value = 9 ;
    nodes[3].fNode = &nodes[1] ;
    nodes[3].lChild = &nodes[6] ;
    nodes[3].rChild = &nodes[7] ;

    nodes[4].value = 7 ;
    nodes[4].fNode = &nodes[2] ;
    nodes[4].lChild = NULL ;
    nodes[4].rChild = NULL ;

//    nodes[5].value = -1 ;
    nodes[5].value = -1 ;
    nodes[5].fNode = NULL ;
    nodes[5].lChild = NULL ;
    nodes[5].rChild = NULL ;

    nodes[6].value = 15 ;
    nodes[6].fNode = &nodes[3] ;
    nodes[6].lChild = NULL ;
    nodes[6].rChild = NULL ;

    nodes[7].value = 8 ;
    nodes[7].fNode = &nodes[3] ;
    nodes[7].lChild = NULL ;
    nodes[7].rChild = NULL ;

    printf("Before insert:") ;
    inorderTraversal(&p) ;

//    printf("STOP") ;

    int index = 1 ;
    while(index < 8){
        if(nodes[index].lChild == NULL) {
            nodes[index].lChild = &nodes[2 * index] ;
            nodes[2*index].lChild = NULL ;
            nodes[2*index].rChild = NULL ;
            nodes[2*index].fNode = &nodes[index] ;
            nodes[2*index].value = 12 ;
            break ;
        }
        else if(nodes[index].rChild == NULL){
            nodes[index].rChild = &nodes[2 * index+1] ;
            nodes[2*index+1].lChild = NULL ;
            nodes[2*index+1].rChild = NULL ;
            nodes[2*index+1].fNode = &nodes[index] ;
            nodes[2*index+1].value = 12 ;
            break ;
        }
        index++ ;
    }

    printf("\nAfter insert:") ;
    inorderTraversal(&p) ;

    return 0 ;
}