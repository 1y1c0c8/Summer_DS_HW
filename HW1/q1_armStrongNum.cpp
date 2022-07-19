#include <iostream>
#include <exception>
using namespace std ;

#define HD hundredsDigit
#define TD tensDigit
#define UD unitsDigit

int cube(int N){
    return N*N*N ;
}

bool isArmstrongNum(int N){
    int hundredsDigit = N/100 ;
    int tensDigit = (N%100)/10 ;
    int unitsDigit = N%10 ;

    return cube(HD) + cube(TD) + cube(UD) == N ;
}


int main(){


    int inputValue=0 ;
    char choice=' ' ;

    do {
        cout << "Enter a number X (100<=X<1000) to check whether it's an Armstrong number:\n" ;
        cin >> inputValue;

        while (inputValue < 100 || inputValue >= 1000) {
            cout << "This number is out of specific range, please try another one...\n";
            cin >> inputValue;
        }

        if (isArmstrongNum(inputValue))
            cout << "Yes, it is an Armstrong number.\n";
        else
            cout << "No, it is not an Armstrong number.\n";


        cout << "Do you want to try again?(y/n)\n" ;
        cin >> choice ;
    }while(choice == 'Y' || choice == 'y') ;


    return 0 ;
}
