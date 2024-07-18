#include <stdio.h>

void display(int arr[],int size){
    printf("\nElements are: ");
    for(int i=0;i<size;i++){
        printf("  %d ",arr[i]);
    }
}
int insrtAtIndx(int arr[],int size,int element,int capacity,int index){
    if(size>=capacity){
        printf("Array don't have enough space");
        return 0;
    }
    for (int i=size-1;i>=index;i--){
        arr[i+1]=arr[i];
    }
    arr[index]=element;
    size++;
    printf("\nUpdated Successfully!");
    for(int i=0;i<size;i++){
        printf("  %d ",arr[i]);
    }
    return 1;
}
void deletAtIndx(int arr[],int size,int index){
    for (int i=index;i<=size-1;i++){
        arr[i]=arr[i+1];
    }
    size--;
    printf("\nDeleted Successfully!");
    for(int i=0;i<=size;i++){
        printf("  %d ",arr[i]);
    }
}
void main(){
    int arr[20]={1,2,3,4,5,6,7,8,9};
    int size=9,capacity=20; 
    display(arr,size);
    insrtAtIndx(arr,size,44,capacity,2);
    deletAtIndx(arr,size,3);
}