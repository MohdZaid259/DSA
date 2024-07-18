#include <stdio.h>
#include <stdlib.h>

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
void push(struct stack *ptr,char val){
    ptr->top++;
    ptr->arr[ptr->top]=val;
}
char pop(struct stack *ptr){
    if(isEmpty(ptr)){
        return 0;
    }
    int val=ptr->arr[ptr->top];
    ptr->top--;
    return val;
}
int match(char a,char b){
    if( a=='(' && b==')' || a=='{' && b=='}'|| a=='[' && b==']'){
        return 1;
    }
    return 0;
}
int parenMatch(struct stack *sp,char *exp){
    int i=0; char popped_ch;
    while(exp[i]!='\0'){
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
            push(sp,exp[i]);
        }
        if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
            if(isEmpty(sp)){
                return 0;
            }
            popped_ch=pop(sp);
            if(!match( popped_ch,exp[i])){
                return 0;
            }
        }
        i++;
    }
    if(isEmpty(sp)){
        return 1;
    }
    return 0;
}
int main(){
    struct stack *sp=(struct stack *)malloc(sizeof(struct stack)); 
    sp->size=20;
    sp->top=-1;
    sp->arr=(char *)malloc(sp->size * sizeof(char));

    char *stmnt="(23[+(34-y]){}/5)";
    if(parenMatch(sp,stmnt)){
        printf("Parenthesis are Matching");
    }
    else{
    printf("Parenthesis are Not Matching");
    }
    return 0;
}