#include <stdio.h>
#include <stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int *arr;
};
void traversal(struct queue *q){
    int i = q->f + 1;
    if (q->f == q->r){
        printf("The Queue is Empty!\n");
    }
    printf("-------------\n");
    while (i != q->r + 1){
        printf("%d ", q->arr[i]);
        i++;
    }
    printf("\n-------------\n");
}
int isEmpty(struct queue *q){
    if (q->f == q->r){
        return 1;
    }
    return 0;
}
int isFull(struct queue *q){
    if (q->r == q->size - 1){
        return 1;
    }
    return 0;
}
int enqueue(struct queue *q, int val){
    if (isFull(q)){
        printf("Queue Overflow! Can't Enqueue %d\n", val);
        return 0;
    }
    q->r++;
    q->arr[q->r] = val;
    return 1;
}
int dequeue(struct queue *q){
    if (isEmpty(q)){
        printf("Queue Underflow!\n");
        return 0;
    }
    q->f++;
    int val = q->arr[q->f];
    return val;
}
int main(){
    struct queue q;
    q.size = 4;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));
    enqueue(&q, 11); // &q because we are sending address of Queue
    enqueue(&q, 22);
    enqueue(&q, 33);
    enqueue(&q, 44);
    enqueue(&q, 55); // queue Overflow
    traversal(&q);
    printf("The Dequeued Element is: %d\n", dequeue(&q));
    printf("The Dequeued Element is: %d\n", dequeue(&q));
    traversal(&q);
    return 0;
}