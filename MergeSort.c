#include<stdio.h>

void print_arr(int* arr , int array_length); 
void mergesort(int* arr , int size);
void merge(int* parent_arr , int* left , int* right , int parent_size);
int main(){
    int array_length;
    scanf("%d",&array_length);

    int array[array_length];
    for(int i = 0 ; i < array_length ; i++) scanf("%d",&array[i]);

    mergesort(array , array_length);

    for(int i = 0 ; i < array_length ; i++) printf("%d ",array[i]);

    return 0;
}

//This takes two arguements --> array to be sorted and its array length
void mergesort(int* arr , int size){
    if(size == 1) return;//if size == 1 we cant futher break it down so we return and start merging while backtracking

    int left_size = size/2; //Half of elements of arr will be left array
    int right_size = size - left_size; //remaining half will be elements of right array

     // two arrays are created so that the original array can be broken into two parts
    int left[left_size] , right[right_size]; //so we declare arrays and copy respective elements to respective arrays 
    for(int i = 0 ; i < left_size ; i++) left[i] = arr[i]; 
    for(int i = 0 ; i < right_size ; i++) right[i] = arr[left_size + i];

    // the left array is sent to mergesort to break it even further
    mergesort(left , left_size);
    // the right array is sent to mergesort to break it even further
    mergesort(right , right_size);

    //the two arrays are broken down , they will start to merge in sorted order and we will be left with two sorted arrays.
    //now our job is to merge both of these sorted arrays without disturbing them.
    merge(arr , left , right , size);
}
//takes four arguements parent_arr , two sorted arrays which are to be merged into parent arr , and length of parent arr.
void merge(int* parent_arr , int* left , int* right , int parent_size){
    int left_size = parent_size/2 , right_size = parent_size - left_size;
    int l = 0 , r = 0 , i = 0; //we will use two pointers one for left array and other for right and compare the values these are pointing at.
    //while i is used to place the elements in correct order 
    
    // loop used to merge the sorted arrays.
    while(l < left_size && r < right_size){
        if(left[l] > right[r]) parent_arr[i++] = right[r++];
        else parent_arr[i++] = left[l++];
    }

    //copies the elements from left to parent_arr.
    while(l < left_size) parent_arr[i++] = left[l++];

    //copies the elements from right to parent_arr.
    while(r < right_size) parent_arr[i++] = right[r++];
}

void print_arr(int* array , int array_length){//This does nothing other than printing the array.
    for(int i = 0 ; i < array_length ; i++) printf("%d ",array[i]);
    printf("\n");
}

/*MergeSort is an advanced recursive sorting technique*/
/*In this sorting technique , the you will recursively break the array into two smaller arrays based on size until you reach size of 1*/
/*then we will commpare and merge them in sorted order while backtracking*/

/*We will make use of some space in this sorting algorithm*/
/*so merging them back to main array will take O(n)*/ 
/*and dividing the array into two equal parts everytime will take O(log2(n) + 1)*/

//Since both of them are done simulataneously total time complexity will be O(n*(log2(n) + 1)) == O(nlog2(n)) */
/*It will take an extra space of n where n is array_length , so space_complexity is O(n)*/
/*This is a stable sorting technique meaning relative positions of equal elements will not change*/