#include <iostream>
#include "graphByHoff.h"
using namespace std ;

int main(){
    int graph[4][4] ;

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            graph[i][j] = 0 ;
        }
    }

    graph[0][1] = 1 ;
    graph[0][2] = 1 ;
    graph[1][2] = 1 ;
    graph[2][0] = 1 ;
    graph[2][3] = 1 ;
    graph[3][3] = 1 ;

    int check[4] = {0, 0, 0, 0} ;

    BFS(&graph[0][0], &check[0], 4) ;


    return 0;
}
