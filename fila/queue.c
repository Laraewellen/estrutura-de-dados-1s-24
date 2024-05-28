#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void enqueue(QueueNode** root, char data){
    QueueNode* qNode = malloc(sizeof(QueueNode));
    qNode->data = data;
    qNode->next = NULL;
    if(isEmpty(*root)){
        *root = qNode;
    }
    else{
        QueueNode* tmp = (*root)->next;
    while (tmp-> next == NULL){
        if(tmp != NULL && tmp->next == NULL){
            tmp->next = qNode;
        }
        else{
            tmp = tmp->next;
        }
    } 
    }
}
}

char dequeue(QueueNode** root)
char peek(QueueNode* root)

int isEmpty(QueueNode* root){
    return root == NULL;
}

void display(QueueNode* root)