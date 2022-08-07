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

#endif //SUMMERDS_HW_GRAPHBYHOFF_H
