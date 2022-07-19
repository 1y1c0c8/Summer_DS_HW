#include <iostream>
#include <stack>
using namespace std ;

int main(){
    int brickNum=0 ;
    do {
        cout << "Please enter the amount of brick (0<n<=20):\n";
        cin >> brickNum ;
    }while(brickNum<=0 || brickNum>20) ;

    stack<int> s ;

    cout << "Please enter elements in stack seperated by space:\n" ;
    for(int i=0; i<brickNum; i++){
        int x ;
        cin >> x ;
        s.push(x) ;

        if(s.size()>=2) {
            int u = s.top();
            s.pop();
            int d = s.top();

            if(u == d)
                s.pop() ;
            else
                s.push(u) ;
        }
    }

    stack<int> ansS ;

    while(!s.empty()){
        ansS.push(s.top()) ;
        s.pop() ;
    }

    while(!ansS.empty()){
        cout << ansS.top() << " " ;
        ansS.pop() ;
    }

    return 0 ;
}