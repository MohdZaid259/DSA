#include <stdio.h>

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void SSort(int arr[],int n){
    int indxmin;int temp;
    for(int i=0;i<n-1;i++){
        indxmin=i;
        for (int j=i+1;j<n;j++){
            if(arr[j]<arr[indxmin]){
                indxmin=j;
            }
        }
        // swaping A[i] and A[indxmin]
        temp=arr[i];
        arr[i]=arr[indxmin];
        arr[indxmin]=temp;
    }
}
int main(){
    int arr[]={1,6,4,3,9,5,2};
    int n=sizeof(arr)/sizeof(int);
    display(arr,n);
    SSort(arr,n);
    display(arr,n);
    return 0;
}