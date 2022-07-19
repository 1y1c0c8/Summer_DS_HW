#include <stdio.h>
#include "charLinkedListByHoff.h"

void palindromeCheck(struct biDirCharNode *head, struct biDirCharNode *tail, int amount){
    int check=0 ; //0 true /1 false
    int index=0 ;
    if(amount == 1){
        printf("It is Palindrome.") ;
        return ;
    }else if(amount%2 == 0){
        //偶數 0 1 2 3 4 5 (6, 2&3 => (6/2)-1&6/2)
        while(index!=(amount-1)/2){
            if(head->value != tail->value)
                check = 1 ;
            head = head->nextNode ;
            tail = tail->preNode ;
            index++ ;
        }
    }else{
        //奇數 0 1 2 3 4 5 6 (7, 3 => (7-1)/2)
        while(index!=((amount-1)/2)-1){
            if(head->value != tail->value)
                check = 1 ;
            head = head->nextNode ;
            tail = tail->preNode ;
            index++ ;
        }
    }
    if(check == 1) printf("Not Palindrome.") ;
    else printf("It is Palindrome.") ;
}

int main(){
    int amount=0 ;
    scanf("%d", &amount) ;

    struct biDirCharNode *nodes[amount] ;
    char t ;
    scanf("%c", &t) ;
    for(int i=0; i<amount; i++){
        char value ;
        scanf("%c", &value) ;
        nodes[i] = nodeCreate(value) ;

        if(i>0)
            nodeConnect(nodes[i-1], nodes[i]) ;
    }

    palindromeCheck(nodes[0], nodes[amount-1], amount) ;

    return 0 ;
}