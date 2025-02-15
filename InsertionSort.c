#include<stdio.h>

void print_arr(int* arr , int array_length); 
void insertion_sort(int* array , int array_length);
int main(){
    int array_length;
    scanf("%d",&array_length);

    int array[array_length];
    for(int i = 0 ; i < array_length ; i++) scanf("%d",&array[i]);

    insertion_sort(array , array_length);

    for(int i = 0 ; i < array_length ; i++) printf("%d ",array[i]);

    return 0;
}

//This Function needs two arguements --> 1.Array to be sorted and 2.length of the array
void insertion_sort(int* array , int array_length){
   for(int i = 1 ; i < array_length ; i++){
        int key = array[i] , j;// we have to declare j here since we will br using it even after completion of inner for_loop
        //key will store the value that is to be inserted in sorted array
        for(j = i - 1 ; j >= 0 && array[j] > key ; j--){//This will move the neccesary elements to right so we cnn insert key
            array[j + 1] = array[j];
        }
        array[j + 1] = key; //this will insert key value in its position.
   }
}

void print_arr(int* array , int array_length){//This does nothing other than printing the array.
    for(int i = 0 ; i < array_length ; i++) printf("%d ",array[i]);
    printf("\n");
}
/*Insertion Sort is a basic sorting technique */
/*In this sorting technique , we will assume the array to be two parts .. Sorted part and Unsorted part*/
/*each iteration you will insert an element at its correct position in sorted arr*/
/*Since this insertion of new element occurs at correct position , the sorted array is not disturbed*/

/*You will consider the first element(0th index to be sorted).*/
/*And you will start from index 1 and place each element in its correct position until the array is fully sorted*/

/*The insertion of Elements is done by moving the neccesary values to right and placing the element in the free slot obtained*/
/*Each time the Sorted array gets bigger so , to find the correct position each iteration will increase in worst case*/
/*it will be 1 + 2 + 3 + 4 + ..... n -1 iterations*/
/*This makes its Time Complexity (n-1)*(n)/2 which is (n^2 +......)/2 which is O(n^2)*/
/*Space Complexity is O(1) since we are not using any extra space*/
/*This is a stable sorting technique meaning relative positions of equal elements will not change*/