#ifndef SUMMERDS_HW_GRAPHBYHOFF_H
#define SUMMERDS_HW_GRAPHBYHOFF_H

#include <iostream>
#include <stack>
using namespace std ;

void BFS(int * graph, int* check, int amount){
    stack<int> lineup ;
    cout << "BFS starting from vertex 1: " ;

    int index = 0 ;
    int checkNum = 0 ;
    while(checkNum!=amount){
        if(index==0) {
            lineup.push(index + 1);
            *(check+(index+1)) = 1 ;
        }
        else{
            if(!lineup.empty()){
                int temp = lineup.top() ;
                cout << temp << " " ;
                lineup.pop() ;

                for(int j=amount-1; j>=0; j--){
                    if(*(graph+(4*temp+j))==1 && *(check+j)==0) {
                        lineup.push(j);
                        *(check+j) = 1 ;
                    }
                }
            }
        }

        for(int i=0; i<amount; i++){
            checkNum += *(check+i) ;
        }

        index++ ;
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
