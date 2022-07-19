#include <iostream>
#include <queue>
using namespace std ;

int main(){
    int rowNum=0, colNum=0 ;

    do {
        cout << "Enter row and column like (rowNum colNum):\n";
        cin >> rowNum >> colNum ;
    }while(rowNum<=0 || rowNum >=100 || colNum<=0 || colNum>=100) ;

    int matrix[rowNum][colNum] ;
    cout << "Please enter the matrix like matrix[row][col]:\n" ;

    for(int i=0; i<rowNum; i++){
        for(int j=0; j<colNum; j++){
            cin >> matrix[i][j] ;
        }
    }

    cout << "After transpose:\n" ;
    for(int i=0; i<colNum; i++){
        for(int j=0; j<rowNum; j++){
            cout << matrix[j][i] << " " ;
        }
        cout << "\n" ;
    }

    return 0 ;
}