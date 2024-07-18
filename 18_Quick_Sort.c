#include <stdio.h>

void display(int arr[],int n){
    for(int i=0; i<=n-1; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void quicksort(int arr[],int low,int high){
    int prindx; // Index of pivot after partition
    if(low<high){
        prindx=partition(arr,low,high);
        quicksort(arr,low,prindx-1);
        quicksort(arr,prindx+1,high);
    }
}
int partition(int arr[],int low,int high){
    int pivot=arr[low];
    int i=low+1;
    int j=high;
    int temp;
    do{
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<j){
            temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }
    }while(i<j);
    // Swaping A[low] and A[j]
    temp=arr[j];
    arr[j]=arr[low];
    arr[low]=temp;
    return j; // pivot position
}
int main(){
    int arr[]={6,3,7,8,2,4,1,9};
    int n=sizeof(arr)/sizeof(int);
    display(arr,n);
    quicksort(arr,0,n-1);
    display(arr,n);
    return 0;
}
