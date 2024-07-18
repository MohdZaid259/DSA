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
struct Node *dltFirst(struct Node *head){
        struct Node *ptr=head;
        head=head->next;
        free(ptr);
        printf("deleteatFirst: ");
        return head;
}
struct Node *dltindx(struct Node *head,int index){
        struct Node *p=head;
        struct Node *q=head->next;
        int i=1;
        while(i<index){
            p=p->next;
            q=q->next;
            i++;
        }
        p->next=q->next;
        free(q);
        printf("deleteatIndex: ");
        return head;
}
struct Node *dltEnd(struct Node *head){
        struct Node *p=head;
        struct Node *q=head->next;
        while(q->next!=NULL){
            p=p->next;
            q=q->next;
        }
        p->next=NULL;
        free(q);
        printf("deleteatEnd: ");
        return head;
}
struct Node *afterNode(struct Node *head,int data){
        struct Node *p=head;
        struct Node *q=head->next;
        while(q->next!=NULL && q->data!=data){
            p=p->next;
            q=q->next;
        }
        if(q->data==data){
            p->next=q->next;
            free(q);
        }
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
    head=dltFirst(head);
    traversal(head);
    head=dltindx(head,2);
    traversal(head);
    head=dltEnd(head);
    traversal(head);
    head=afterNode(head,15);
    traversal(head);
    printf("\n");
}