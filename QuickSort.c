#include<stdio.h>

void print_arr(int* arr , int array_length); 
void quicksort(int* arr , int start , int end);
int partition(int* arr , int start  , int end);
int main(){
    int array_length;
    scanf("%d",&array_length);

    int array[array_length];
    for(int i = 0 ; i < array_length ; i++) scanf("%d",&array[i]);

    quicksort(array , 0 , array_length - 1);

    for(int i = 0 ; i < array_length ; i++) printf("%d ",array[i]);

    return 0;
}

//this will take 3 arguements --> arr to be sorted , start of arr , end of arr
void quicksort(int* arr , int start , int end){
    if(end <= start) return; // when end <= start we already traversed that part of array . so return 

    int partition_index = partition(arr , start , end); // this will arrange the array so that smaller elements go before pivot , and 
    /*larger elements go after pivot .. it will also return the index of pivot element after arranging*/
    quicksort(arr , start , partition_index - 1);// we will not futher decompose left side of pivot element and do the process recursively
    quicksort(arr , partition_index + 1 , end);// we will not futher decompose right side of pivot element and do the process recursively
}

int partition(int* arr , int start , int end){
    int count = start;//it will begin at start and will increase by 1 everytime we find a number smaller than pivot

    /*pivot element can be anything , last_element , start_element , even median , this partiton function will change accordingly*/
    /*Here last element is always taken as pivot element*/

    for(int i = start ; i < end ; i++){//We run a loop from start to end 
        if(arr[i] < arr[end]){//if we find a element smaller than pivot element we swap it with arr[count] and increment count.
            int temp = arr[count]; /*so that it will keep pointing at next index that is ready to be swapped with next element smaller than pivot*/
            arr[count] = arr[i];
            arr[i] = temp;
            count++;
        }
    }

    /*in the end we have put all elements smaller than pivot to left , this only means we also left every element equal or larger in right*/
    /*however our pivot element is still at end so we will swap arr[count] with arr[end] */
    int temp = arr[end];
    arr[end] = arr[count];
    arr[count] = temp;

    //we return pivot index.
    return count;
}
/*QuickSort is an advanced recursive sorting technique*/
/*In this sorting technique , the you will recursively break the array into two arrays based on its relation with pivot element*/
/*if an element is smaller than pivot element it will end up in left side of pivot element*/
/*if an element is larger/= than pivot element it will end up in right side of pivot element*/

/*these two sub arrays (left and right side of pivot element are further broken down by recursion)*/

/*We do notl make use of some space in this sorting algorithm*/
/*rearranging the elements so that smaller elements(than pivot) will go to left of pivot element and
larger/= elements(than pivot) will go to right side of pivot element has na time complexity O(n)
/*and dividing the array into two equal parts everytime will take about O(log2(n) + 1)(assuming the partition element is median of array)*/
/*However in practice it doesnt happen so log2(n) is not for all cases but for bestcases*/
/*worst case will be sorted array and time complexity is o(n^2)*/

//Since both of them are done simulataneously total time complexity will be O(n*(log2(n) + 1)) == O(nlog2(n)) in best case */
/*and O(n^2) in worst case*/
/*It will not take any extra space , space_complexity is O(1)*/
/*This is considered to be unstable sorting technique meaning relative positions of equal elements may change*/