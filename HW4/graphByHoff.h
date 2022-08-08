#ifndef SUMMERDS_HW_GRAPHBYHOFF_H
#define SUMMERDS_HW_GRAPHBYHOFF_H

#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std ;

typedef struct {
    int start ;
    int end ;
    int length ;
}edge;

void BFS(int * graph, int* check, int amount){

}

void DFS(int *graph, int *check, int amount){
    stack<int> lineup ;

    int index=0 ;
    while(index!=amount){

        if(index == 0){
            lineup.push(2) ;
            *(check+2) = 1 ;
        }
        else{
            if(!lineup.empty()){
                int top = lineup.top() ;
                lineup.pop() ;
                cout << top << " " ;
                for(int i=amount-1; i>=0; i--){
                    if(*(graph+top*amount+i) == 1 && *(check+i) == 0) {
                        lineup.push(i);
                        *(check+i) = 1 ;
                    }
                }
            }
        }

        index=0 ;
        for(int i=0; i<amount; i++){
            index += *(check+i) ;
        }
    }

    while(!lineup.empty()){
        cout << lineup.top() << " " ;
        lineup.pop() ;
    }
}

void kruskal(vector<edge> edges, int *check, int amount){

    int index=0 ;
    int totalLength = 0;
    auto p = edges.end()-1 ;
    while(index!=amount-1){

        if(*(check+p->start)==0 || *(check+p->end)==0){
            if(*(check+p->start) == 0)  *(check+p->start) = 1 ;
            else    *(check+p->end) = 1 ;

            totalLength += p->length ;

            cout << p->start << "--" << p->end << "==" << p->length << "\n" ;

        }

        p-- ;

        index=0 ;
        for(int i=0; i<amount; i++){
            index += *(check+i) ;
        }
    }

    cout << "Minimum Cost Spanning Tree: " << totalLength ;
}

#endif //SUMMERDS_HW_GRAPHBYHOFF_H
