#include <stdio.h>
#include <stdlib.h>

struct circularQueue{
    int size;
    int f;
    int r;
    int *arr;
};
void traversal(struct circularQueue *q){
    int i = q->f;
    if (i == q->r){
        printf("The circularQueue is Empty!\n");
    }
    printf("-------------\n");
    while (i != q->r){
        printf("%d ", q->arr[i]);
        i = (i + 1) % q->size; // circular increment
    }
    printf("\n-------------\n");
}
int isEmpty(struct circularQueue *q){
    if (q->f == q->r){
        return 1;
    }
    return 0;
}
int isFull(struct circularQueue *q){
    if ((q->r + 1) % q->size == q->f){
        return 1;
    }
    return 0;
}
int enqueue(struct circularQueue *q, int val){
    if (isFull(q)){
        printf("Queue Overflow! Can't Enqueue %d\n", val);
        return 0;
    }
    q->arr[q->r] = val;
    q->r = (q->r + 1) % q->size; // circular increment
    return 1;
}
int dequeue(struct circularQueue *q){
    if (isEmpty(q)){
        printf("Queue Underflow!\n");
        return 0;
    }
    int val = q->arr[q->f];
    q->f = (q->f + 1) % q->size; // circular increment
    return val;
}
int main(){
    struct circularQueue q;
    q.size = 4;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));
    enqueue(&q, 11); // &q because we are sending address of circularQueue
    enqueue(&q, 22);
    enqueue(&q, 33);
    enqueue(&q, 44);
    enqueue(&q, 55); // queue Overflow
    traversal(&q);
    printf("The Dequeued Element is: %d\n", dequeue(&q));
    printf("The Dequeued Element is: %d\n", dequeue(&q));
    enqueue(&q, 44);
    enqueue(&q, 55);
    traversal(&q);
    return 0;
}