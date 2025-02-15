#include<stdio.h>

void print_arr(int* arr , int array_length); 
void selection_sort(int* array , int array_length);
int main(){
    int array_length;
    scanf("%d",&array_length);

    int array[array_length];
    for(int i = 0 ; i < array_length ; i++) scanf("%d",&array[i]);

    selection_sort(array , array_length);

    print_arr(array , array_length);

    return 0;
}

//This Function needs two arguements --> 1.Array to be sorted and 2.length of the array
void selection_sort(int* array , int array_length){
    for(int i = 0 ; i < array_length - 1; i++){ // this is to traverse the array (n-1) times
        int min_index = i;//For each iteration we will consider ith index will have minimum value at start.
        for(int j = i + 1 ; j < array_length ; j++) {//we will start j from i + 1 and go till array_length - 1
        // which lets us compare to the values right to ith index only

        if(array[min_index] > array[j]) min_index = j; //if ever we find an index with even smaller value , we change min_index;
        }
        //after each traversal we will have the index with minimum value in min_index.
        if(min_index != i){ //we will check if min_index is 1 , in which case we need not swap
            array[min_index] ^= array[i];
            array[i] ^= array[min_index];
            array[min_index] ^= array[i];
        }//This swaps the two values

        //print_arr(arr , arr_length) --> uncomment if want to see what happens after each iteration.
    }
}

void print_arr(int* array , int array_length){//This does nothing other than printing the array.
    for(int i = 0 ; i < array_length ; i++) printf("%d ",array[i]);
    printf("\n");
}
/*Selection Sort is a basic sorting technique */
/*In this sorting technique , you repeatedly find the minimum element and set it in it's place*/
/*You start from 0th index and compare it to all the elements to its right and find the minimum and set it in 0th index*/
/*Now start from 1st index and compare it to all the elements to its right and find the second minimum and set it in 1st index and....*/

/*With this you have to travese through the array (n-1)times and at ith iteration you will have to visit (n - i - 2) elements */
/*This makes its Time Complexity (n-1)*(n)/2 which is (n^2 +......)/2 which is O(n^2)*/
/*Space Complexity is O(1) since we are not using any extra space*/
/*This is an unstable sorting technique meaning relative positions of equal elements may change*/