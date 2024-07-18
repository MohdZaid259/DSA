#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next; // struct Node type pointer to point on struct Node type Structure
};
void traversal(struct Node *head){
    struct Node *ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }printf("\n");
}
struct Node *instFirst(struct Node *head,int data){
        struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
        ptr->data=data;
        ptr->next=head;
        printf("insertatFirst: ");
        return ptr;
}
struct Node *instindx(struct Node *head,int data,int index){
        struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
        struct Node *p=head;
        int i=1;
        while(i<index){
            p=p->next;
            i++;
        }
        ptr->data=data;
        ptr->next=p->next;
        p->next=ptr;
        printf("insertatIndex: ");
        return head;
}
struct Node *instEnd(struct Node *head,int data){
        struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
        struct Node *p=head;
        while(p->next!=NULL){
            p=p->next;
        }
        ptr->data=data;
        ptr->next=NULL;
        p->next=ptr;
        printf("insertatEnd: ");
        return head;
}
struct Node *afterNode(struct Node *head,struct Node *prev,int data){
        struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
        ptr->data=data;
        ptr->next=prev->next;
        prev->next=ptr;
        printf("afterNode: ");
        return head;
}
int main(){ // Nodes creation:
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    // Allocating memory from Heap for the Nodes
    head=(struct Node *)malloc(sizeof(struct Node));
    second=(struct Node *)malloc(sizeof(struct Node));
    third=(struct Node *)malloc(sizeof(struct Node));
    fourth=(struct Node *)malloc(sizeof(struct Node));

    head->data=7;
    head->next=second;
    second->data=11;
    second->next=third;
    third->data=15;
    third->next=fourth;
    fourth->data=18;
    fourth->next=NULL;

    printf("\nThe Original LL: ");
    traversal(head);
    head=instFirst(head,3);
    traversal(head);
    head=instindx(head,33,3);
    traversal(head);
    head=instEnd(head,55);
    traversal(head);
    head=afterNode(head,third,77);
    traversal(head);
    printf("\n");
}