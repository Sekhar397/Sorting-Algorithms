#include<stdio.h>

int max(int* arrar , int length);
void radix_sort(int* arr , int size);
void counting_sort(int* arr , int size , int exponential);
int main(){
    int array_length;
    scanf("%d",&array_length);

    int array[array_length];
    for(int i = 0 ; i < array_length ; i++) scanf("%d",&array[i]);

    radix_sort(array , array_length);

    for(int i = 0 ; i < array_length ; i++) printf("%d ",array[i]);

    return 0;
}

void radix_sort(int* arr , int size){
    //finds maximum of array
    int maximum = max(arr , size);

    //sorts the array based on each place value from 1 to log10(max) + 1;
    for(int exp = 1 ; maximum/exp != 0 ; exp *= 10){
        counting_sort(arr , size , exp);
    }
}

void counting_sort(int* arr , int size , int exponential){
    int count[10] = {0};//this stores elements have x digit

    for(int i = 0 ; i < size ; i++){
        count[(arr[i]/exponential)%10]++; //this gives the digit at necessary place value
    } 

    //here we are finding cumulative frequency and we are doing -1 since indexes start with 0. 
    count[0] -= 1;
    for(int i = 1 ; i < 10 ; i++){
        count[i] += count[i - 1]; 
    }

    //we make a new array and sort the elements in this array based on place value
    int new_arr[size];
    for(int i = size - 1 ; i >= 0 ; i--){
        new_arr[count[(arr[i]/exponential)%10]] = arr[i];
        count[(arr[i]/exponential)%10]--;
    }

    //we copy back to original array.
    for(int i = 0 ; i < size ; i++){
        arr[i] = new_arr[i];
    }
}

//finds maximum of array
int max(int* arr , int size){
    int max = arr[0];
    for(int i = 1 ; i < size ; i++) if(max < arr[i]) max = arr[i];

    return max;
}


/*This is a really fun sorting technique*/
/*but this version of code doesnt count in negative numbers*/

/*radix sort takes advantages of places values and digit value*/
/*for this version to sort the elements based on a given place value it takes 3n + 10 which is considered to be O(n)*/
/*and we have to sort the array as many times as there are digits in maximum number so log10(max) + 1 which is considered to be log10(max)*/
/*so time_complexity will be O(n)*O(log10(max)) ==> O(n*log10(max))*/

/*This will take an extra space of n + 10* , n for making new_array and 10 for counting digits frequency*/

/*First we sort the elements based on ones place*/
/*then we sort based on 10s place , since array is already sorted based on ones place they will remain undisturbed during this and so on*/

//For exp 23 235 45 34 67 98
//after ones place sorting 23 34 235 45 48 98
//after 10s place sortin 23 34 235 45 48 98 --> as you can see 23 34 35(ignore 2 since hundered place is not sorted) (45 48) 98
//the order of 45 and 48 hasnt changed 