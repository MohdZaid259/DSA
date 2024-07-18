#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};
void traversal(struct Node *head){
    struct Node *ptr=head;
    struct Node *p;
    printf("\nPrinting in Forward Direction:\n");
    while(ptr->next!=NULL){
        printf("Element %d\n",ptr->data);
        ptr=ptr->next;
        if(ptr->next==NULL){
            p=ptr;
            printf("Element %d\n",ptr->data);
        }
    }
        printf("\nPrinting in Backward Direction:\n");
    while(p->prev!=NULL){
        printf("Element %d\n",p->data);
        p=p->prev;
        if(p->prev==NULL){
            printf("Element %d\n",p->data);
        }
    }
}
int main(){ // Nodes creation:
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;
    // Allocating memory from Heap for the Nodes
    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    fourth=(struct Node*)malloc(sizeof(struct Node));
    fifth=(struct Node*)malloc(sizeof(struct Node));
    
    head->data=7;
    head->next=second;
    head->prev=NULL;
    second->data=11;
    second->next=third;
    second->prev=head;
    third->data=15;
    third->next=fourth;
    third->prev=second;
    fourth->data=44;
    fourth->next=fifth;
    fourth->prev=third;
    fifth->data=73;
    fifth->next=NULL;
    fifth->prev=fourth;

    traversal(head);
    return 0;
}