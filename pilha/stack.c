#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "limits.h"

int main(int argc, char* argv[])
void push(StackNode** root, char data);{
    stackNode* stackNode = malloc(sizeoff(StackNode));
    stackNode -> data = data;
    stackNode -> next = *root;
    *root = StackNode
}
char pop(StackNode** root){
     if (isEmpty(*root)){
        return CHAR_MIN;
     }
     StackNode* tmp = *root;
     *root = tmp -> next;
     char tmpData = tmp -> data;
     free(tmp);
     return tmpData;
}     
char peek(StackNode* root){
    if(isEmpty(root)){
        return CHAR_MIN;
    }
    return root -> data;
}

int isEmpty(StackNode* root){
     return root == NULL;
}
void display(StackNode* root){
    StackNode* tmp = root;
    while(tmp != NULL){
        printf("%c ->", tmp -> data);
        tmp = tmp -> next; 
    }
    printf("NULL\n");
}

