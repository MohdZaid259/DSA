#include <stdio.h>

//works for both sorted or unsorted Array
int linear(int arr1[],int size1, int element){
    for(int i=0;i<size1;i++){
        if(arr1[i]==element){
            printf("\nElement %d found at index %d in Arr1",element,i);
            return i;
        }
    }
    printf("\nElement %d isn't present in Arr1",element);
    return 0;
}
//works only for sorted Array
int binary(int arr2[],int size2, int element){
    int low=0,mid,high=size2-1;
    while(low<=high){
        mid=(low+high)/2;
        if(arr2[mid]==element){
            printf("\nElement %d found at index %d in Arr2",element,mid);
            return mid;
        }
        if(arr2[mid]<element){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    printf("\nElement %d isn't present in Arr2",element);
    return 0;
}
int main(){
    int arr1[]={1,4,3,5,5,3,6,2};
    int size1=sizeof(arr1)/sizeof(int);
    linear(arr1,size1,5);
    int arr2[]={1,2,3,4,5,6,7,8,9};
    int size2=sizeof(arr2)/sizeof(int);
    binary(arr2,size2,8);
    return 0;
}