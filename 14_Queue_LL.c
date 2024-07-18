#include <stdio.h>
#include <stdlib.h>

struct Node *f = NULL;
struct Node *r = NULL;

struct Node{
    int data;
    struct Node *next;
};
void traversal(struct Node *f){
    struct Node *ptr=f;
    printf("------------\n");
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n------------\n");
}
int isEmpty(struct Node *f){
    if (f == NULL){
        return 1;
    }
    return 0;
}
int isFull(struct Node *f){
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL){
        return 1;
    }
    return 0;
}
struct Node *enqueue(int val){
    if (isFull(f)){
        printf("Queue Overflow! Can't Enqueue %d\n", val);
        return f;
    }
    else{
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = val;
        n->next = NULL;
        if (isEmpty(f)){
            f = r = n;
        }
        r->next = n;
        r = n;
        return f;
    }
}
// int dequeue(){
//     if (isEmpty(f)){
//         printf("Queue Underflow! Nothing to Dequeue");
//         return 0;
//     }
//     int dqd = f->data;
//     f = f->next;
//     return dqd;
// }
int dequeue(){
    int val=-1;
    struct Node *ptr=f;
    if (f==NULL){
        printf("Empty\n");
        return 0;
    }
    else{
        f=f->next;
        val=ptr->data;
        free(ptr);
        return val;
    }
}
int main(){

    enqueue(11);
    enqueue(22);
    enqueue(33);
    enqueue(44);
    traversal(f);

    dequeue();
    dequeue();
    traversal(f);
    
    return 0;
}