#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};
void traverse(struct stack *ptr){
    int i=0;
    while(ptr->arr[i]!=ptr->arr[ptr->top+1]){
        printf("| %d |\n",ptr->arr[i]);
        i++;
    }
        printf("======");
}
int isFull(struct stack *ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }
    return 0;
}
int isEmpty(struct stack *ptr){
    if(ptr->top==-1){
        return 1;
    }
    return 0;
}
int push(struct stack *ptr,int val){
    if(isFull(ptr)){
        printf("Stack Overflow! Can't push further");
        return 0;
    }
    ptr->top++;
    ptr->arr[ptr->top]=val;
    return val;
}
int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Nothing to Pop");
        return 0;
    }
    int val=ptr->arr[ptr->top];
    ptr->top--;
    return val;
}
int stackTop(struct stack *ptr){
    return ptr->arr[ptr->top];
    }
int stackBottom(struct stack *ptr){
    return ptr->arr[0];
    }
int peek(struct stack *ptr,int i){
    return ptr->arr[ptr->top-i+1];
}
int main(){
    struct stack *sp=(struct stack *)malloc(sizeof(struct stack)); //struct pointer to point on structure
    sp->size=20;
    sp->top=-1;
    sp->arr=(int *)malloc(sp->size * sizeof(int));
    printf("Before Operation, Empty: %d\n",isEmpty(sp));
    printf("Before Operation, Full: %d\n",isFull(sp));
    push(sp,10);
    push(sp,20);
    push(sp,30);
    push(sp,40);
    push(sp,50);
    push(sp,60);
    push(sp,70);
    pop(sp);
    pop(sp);
    pop(sp);
    traverse(sp);
    printf("\nAfter Operation, Empty: %d\n",isEmpty(sp));
    printf("After Operation, Full: %d\n",isFull(sp));
    printf("Top_Most :%d\n",stackTop(sp));
    printf("Bottom_Most :%d\n",stackBottom(sp));
    for(int j=1;j<sp->top+2;j++){
        printf("\n%d is at %dst Position",peek(sp,j),j);
    }
    return 0;
}