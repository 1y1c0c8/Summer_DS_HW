#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//#include "treeByHoff.h"
#include "binarySearchTreeByHoff.h"

int main(){
    int amount=0;
    scanf("%d", &amount) ;

    if(amount==1)   printf("-1") ;
    else if(amount == 2){
        char data[2][5] ;
        int value[2] ;

        scanf("%s ", data[0]) ;
        scanf("%s", data[1]) ;

        if(floor(strcmp(data[0], "null"))){
            value[0] = atoi(data[0]) ;
        }
        else    value[0] = -1 ;

        if(floor(strcmp(data[1], "null"))){
            value[1] = atoi(data[1]) ;
        }
        else    value[1] = -1 ;

        if(value[0] == value[1])    printf("-1") ;
        else if(value[0]>value[1])  printf("%d", value[1]) ;
        else    printf("%d", value[0]) ;
    }
    else {
        char data[amount][5];
        int value[amount];

        int index = 0;
        while (index < amount - 1) {
            scanf("%s ", data[index]);

            if (floor(strcmp(data[index], "null"))) {
                value[index] = atoi(data[index]);
            } else value[index] = -1;

            index++;
        }
        scanf("%s", data[index]);
        if (floor(strcmp(data[index], "null"))) {
            value[index] = atoi(data[index]);
        } else value[index] = -1;

        index = 2;
        int ans[2];
        ans[0] = value[0], ans[1] = value[1];
        while (index<amount) {
            if (value[index] > ans[1] && value[index!=-1]) {
                ans[0] = ans[1], ans[1] = value[index];
                break;
            }
            index++;
        }

        if(ans[0] == ans[1])    printf("-1") ;
        else    printf("%d", ans[1]) ;
    }
    return 0;
}