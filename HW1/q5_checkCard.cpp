#include <iostream>
#include <queue>
using namespace std ;

int main() {
    int cardNum=0 ;
    do{
        cout << "Please enter the amount of card (0<n<=50):\n" ;
        cin >> cardNum ;
    }while(cardNum<=0 || cardNum>50) ;

    queue<int> q ;
    for(int i=0; i<cardNum; i++)
        q.push(i+1) ;

    while(q.size()>=2){
        int t1 = q.front() ;
        cout << t1 << ", " ;
        q.pop() ;
        int t2 = q.front() ;
        q.pop() ;
        q.push(t2) ;
    }
    cout << q.front() ;

    return 0;
}