#include <stdio.h>
#include <stdlib.h>
#include "singleLinkedListByHoff.h"

int main() {
    printf("How many nodes do you want?\n");
    int amount = 0;
    scanf("%d", &amount);

    struct node *nodes[amount];
    printf("Please key in the elements seperated by space:\n");
    for (int i = 0; i < amount; i++) {
        int value = 0;
        scanf("%d", &value);
        nodes[i] = singleNodeCreate(value);

        if (i != 0)
            singleNodeConnect(nodes[i - 1], nodes[i]);
    }

    struct node *evenLLHead = singleNodeCreate(-1);
    struct node *evenLLTail = evenLLHead;
    struct node *oddLLHead = singleNodeCreate(-1);
    struct node *oddLLTail = oddLLHead;
    struct node *traversal = nodes[0];

    for (int i = 0; i < amount; i++) {
        if (i % 2) {
            oddLLTail->nextNode = traversal;
            oddLLTail = oddLLTail->nextNode;
        } else {
            evenLLTail->nextNode = traversal;
            evenLLTail = evenLLTail->nextNode;
        }
        traversal = traversal->nextNode;
    }

    struct node *newHead = evenLLHead->nextNode;
    evenLLTail->nextNode = oddLLHead->nextNode;

    printSingleLinkedList(newHead, amount);

    return 0;
}