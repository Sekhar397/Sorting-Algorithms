#include<stdio.h>

void print_arr(int* arr , int array_length); 
void bubble_sort(int* array , int array_length);
int main(){
    int array_length;
    scanf("%d",&array_length);

    int array[array_length];
    for(int i = 0 ; i < array_length ; i++) scanf("%d",&array[i]);

    bubble_sort(array , array_length);

    for(int i = 0 ; i < array_length ; i++) printf("%d ",array[i]);

    return 0;
}

//This Function needs two arguements --> 1.Array to be sorted and 2.length of the array
void bubble_sort(int* array , int array_length){
    for(int i = array_length - 1; i >= 1 ; i--) {//This rotates loop n-1 times and also reduces the length of array to be traversed each itearation by 1;
        int swap_count = 0; //This will keep check of number of swaps each iteration
        for(int j = 0 ; j < i ; j++){ //this loop is to compare adjacent elements
            if(array[j] > array[j + 1]){//if adjacent elements are in wrong position swap them and increase swao_count by 1.
                array[j] ^= array[j + 1];
                array[j + 1] ^= array[j];
                array[j] ^= array[j + 1];
                swap_count++;
            }
        }
        //print_arr(arr , arr_length) --> uncomment if want to see what happens after each iteration.
        if(swap_count == 0) break; // if swaps_count == 0 --> no swaps occured in iteration --> array is sorted --> we can break the loop.
    }
}

void print_arr(int* array , int array_length){//This does nothing other than printing the array.
    for(int i = 0 ; i < array_length ; i++) printf("%d ",array[i]);
    printf("\n");
}
/*Bubble Sort is a basic sorting technique */
/*In this sorting technique , the highest value will be get to its index in each iteration*/
/*You start from 0th index and compare adjacent elements , if they are not in correct order you swap them*/
/*i.e if(arr[i] > arr[i + 1]) swap(arr[i] , arr[i + 1]);*/
/*since everytime , the highest value in unsorted part will find its place , this should be done n-1 times*/
/*however if no swaps occur in a iteration then array is already sorted you can break out of loop*/

/*With this you have to travese through the array (n-1) at max times and at ith iteration you will have to visit (n - i - 2) elements */
/*Since the array_length to be traversed decreases by 1 every iteration*/
/*This makes its Time Complexity (n-1)*(n)/2 which is (n^2 +......)/2 which is O(n^2)*/
/*Space Complexity O(1) since we are not using any extra space*/
/*This is an unstable sorting technique meaning relative positions of equal elements may change*/