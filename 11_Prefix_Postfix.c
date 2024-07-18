#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack{
    int size;
    int top;
    char *arr;
};
int isEmpty(struct stack *ptr){
    if(ptr->top==-1){
        return 1;
    }
    return 0;
}
void push(struct stack *ptr,char ch){
    ptr->top++;
    ptr->arr[ptr->top]=ch;
}
char pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Nothing to Pop");
        return 0;
    }
    char val=ptr->arr[ptr->top];
    ptr->top--;
    return val;
}
int stackTop(struct stack *sp){
    return sp->arr[sp->top];
}
int precedence(char ch){
    if(ch=='*' || ch=='/')
        return 2;
    else if(ch=='+' || ch=='-')
        return 1;
    else
        return 0;
}
int isOperator(char ch){
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
        return 1;
    }
    return 0;
}
char *intopo(struct stack *sp,char *infix){
    char *postfix=(char *)malloc((strlen(infix)+1) * sizeof(char));
    int i=0; //track infix traversal
    int j=0; //track postfix traversal
    while(infix[i]!='\0'){
        if(!isOperator(infix[i])){
            postfix[j]=infix[i];
            i++; 
            j++;
        }
        else{
            if(precedence(infix[i])>precedence(stackTop(sp))){
                push(sp,infix[i]);
                i++;
            }
            else{
                postfix[j]=pop(sp);
                j++;
            }
        }
    }
    while(!isEmpty(sp)){
        postfix[j]=pop(sp);
        j++;
    }
    postfix[j]='\0';
    return postfix;
}
int main(){
    struct stack *sp=(struct stack *)malloc(sizeof(struct stack)); //struct pointer to point on structure
    sp->size=20;
    sp->top=-1;
    sp->arr=(char *)malloc(sp->size * sizeof(char));
    char *infix="x-y/z-k*d";
    printf("Postfix: %s",intopo(sp,infix));
    return 0;
}