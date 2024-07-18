/* 
Intermediate results are not useful as some element can be inserted inbetween anytime

Best time complexity : O(n)
Worst time complexity :O(n^2)

Stability : YES 

Adaptive : YES
*/

#include <stdio.h>

void display(int* arr, int n){
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int *arr, int n){
    int key, j;
    // Loop for passes
    for (int i = 1; i <= n-1; i++){
        printf("Number of passes done: %d\n",i);
        key = arr[i];
        j = i-1;
        // Loop for each pass
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        display(arr,n);
    }
}

int main(){
   // -1   0    1   2   3   4   5
   //      12,| 54, 65, 07, 23, 09 --> i=1, key=54, j=0
   //      12,| 54, 65, 07, 23, 09 --> 1st pass done (i=1)!

   //      12, 54,| 65, 07, 23, 09 --> i=2, key=65, j=1
   //      12, 54,| 65, 07, 23, 09 --> 2nd pass done (i=2)!

   //      12, 54, 65,| 07, 23, 09 --> i=3, key=7, j=2
   //      12, 54, 65,| 65, 23, 09 --> i=3, key=7, j=1
   //      12, 54, 54,| 65, 23, 09 --> i=3, key=7, j=0
   //      12, 12, 54,| 65, 23, 09 --> i=3, key=7, j=-1
   //      07, 12, 54,| 65, 23, 09 --> 3rd pass done (i=3)!

   // Fast forwarding and 4th and 5th pass will give:
   //      07, 12, 54, 65,| 23, 09 --> i=4, key=23, j=3
   //      07, 12, 23, 54,| 65, 09 --> arrfter the 4th pass

   //      07, 12, 23, 54, 65,| 09 --> i=5, key=09, j=4
   //      07, 09, 12, 23, 54, 65| --> arrfter the 5th pass 
    
    int arr[] = {12, 54, 65, 7, 23, 9};
    int n = 6;
    printf("\nArray Before Sorting:\n");
    display(arr, n);
    printf("\n");

    insertionSort(arr, n);

    printf("\nArray After Sorting:\n");
    display(arr, n);
    printf("\n");
    return 0;
}
