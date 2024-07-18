/* 
Intermediate results are some kind of useful as heaviest element is shifted to rightmost

Best time complexity : O(n)
Worst time complexity :O(n^2)

Stability : YES 

Adaptive : No but Upgradable
*/

#include <stdio.h>

void display(int* arr,int n){
    for (int i=0; i<=n-1; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void bubble(int* arr,int n){
    for(int i=0; i<n-1; i++){
        printf("Number of passes done: %d\n",i+1);
        int temp;
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
        display(arr,n);
    }
}
void bubbleAdaptive(int* arr,int n){
    int temp, sorted=0;
    for(int i=0; i<n-1; i++){ //for number of passes
        printf("Number of passes done: %d\n",i+1);
        sorted=1;
        for(int j=0; j<n-i-1; j++){ //for comparisons in each pass
            if(arr[j]>arr[j+1]){
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
                sorted=0;
            }
        }
        if(sorted){
            return;
        }
    }
}
int main(){
    int arr[]={3,6,1,3,8,4,9,2};
    // int arr[]={1,2,3,4,5,6,7,8,9};
    int n=sizeof(arr)/sizeof(int);
    printf("\nArray Before Sorting:\n");
    display(arr,n);
    printf("\n");

    bubble(arr,n);

    printf("\nArray After Sorting:\n");
    display(arr,n);
    printf("\n");

    return 0;
}
