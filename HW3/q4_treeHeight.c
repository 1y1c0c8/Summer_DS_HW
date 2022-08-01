#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){
    int amount = 0;
    scanf("%d", &amount) ;
    amount++ ;

    scanf("\n") ;
    char string[256] ;
    gets(string) ;

    int level ;

    level = log2(amount) ;

    printf("%d", level) ;

    return 0 ;
}