#include <iostream>
using namespace std ;

int main(){
    int rowNum=0, colNum=0 ;

    do {
        cout << "Please row and column like \"rowNum colNum\":\n ";
        cin >> rowNum >> colNum ;
    }while(rowNum<=0 || rowNum>10 || colNum<=0 || colNum>10) ;

    int matrix[rowNum][colNum] ;
    cout << "Please enter elements(0<x<=200) by rows and seperated by space:\n" ;

    for(int i=0; i<rowNum*colNum; i++){
        cin >> matrix[i/colNum][i%rowNum] ;
    }

    int saddlePoint=1, row=0, col=0 ;

    for(int i=0; i<rowNum; i++){
        for(int j=0; j<colNum; j++){
            if(matrix[i][j] <= saddlePoint){
                saddlePoint = matrix[i][j] ;
                row = i, col = j ;
            }

        }
    }



    //output:
    cout << "Matrix B is:\n" ;
    for(int i=0; i<rowNum; i++){
        for(int j=0; j<colNum; j++){
            cout << matrix[i][j] << " " ;
        }
        cout << "\n" ;
    }
//    cout << "\b" ;

    cout << "Saddle point is: B[" << row << "][" << col << "]=" << saddlePoint ;

    return 0 ;
}