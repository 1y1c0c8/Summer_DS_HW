#include <iostream>
#include <vector>
#include <algorithm>
#include "graphByHoff.h"
using namespace std ;


bool cmpLength(edge a, edge b){
    return a.length>b.length ;
}

int main(){
    cout << "Edges in the constructed MST" << "\n" ;

    vector<edge> edges ;
    edges.push_back({0,1,11}) ;
    edges.push_back({0,2,7}) ;
    edges.push_back({0,3,6}) ;
    edges.push_back({1,3,14}) ;
    edges.push_back({2,3,5}) ;

    sort(edges.begin(), edges.end(), cmpLength) ;

    int check[4] = {0, 0, 0, 0} ;

    kruskal(edges, &check[0], 4) ;


    return 0 ;
}