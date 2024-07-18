#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
struct Node *top=NULL;

int traversal(struct Node *ptr){
    while(ptr!=NULL){
        printf("| %d |\n",ptr->data);
        ptr=ptr->next;
    }
        printf("======\n");
    return 0;
}
int isEmpty(struct Node *top){
    if(top==NULL){
        return 1;
    }
        return 0;
}
int isFull(){
    struct Node *n=(struct Node *)malloc(sizeof(struct Node));
    if(n==NULL){
        return 1;
    }
        return 0;
}
struct Node *push(struct Node *top,int data){
    if(isFull()){
        printf("Stack Overflow!");
        return 0;
    }
    struct Node *n=(struct Node *)malloc(sizeof(struct Node));
    n->data=data;
    n->next=top;
    top=n;
    return top;
}
int pop(struct Node* tp){
    if(isEmpty(tp)){
        printf("Stack Underflow\n");
    }
    else{
        struct Node* n = tp;
        top = tp->next;
        int x = n->data;
        free(n);
        return x; 
    }
}
int peek(int pos){
    struct Node* ptr = top;
    for (int i = 0; (i < pos-1 && ptr!=NULL); i++){
        ptr = ptr->next;
    }
    if(ptr!=NULL){
        return ptr->data;
    }
    else{
        return -1;
    }
}
int main(){
    // Insertion
    top=push(top,23);
    top=push(top,33);
    top=push(top,43);
    top=push(top,53);
    traversal(top);
    // Deletion
    printf("Popped element is %d\n", pop(top));
    printf("Popped element is %d\n", pop(top));
    traversal(top);
    // Peek
    for (int i = 1; i <= 2; i++)
    {
        printf("Value at position %d is : %d\n", i, peek(i));
    }
    return 0;
}