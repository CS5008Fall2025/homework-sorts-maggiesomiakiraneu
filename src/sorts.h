#ifndef SORTS_H
#define SORTS_H

#include <stdlib.h>
#include "sort_helper.h"

/*** code for selection sort ****/

// Returns the minimum integer from a range in an array
// Input: array - An array of integers
//        start - Where to start looking in an array
//        stop - End of where to search. Typically the 'size' of the array.
// Output: The index in an array of the minimum value between a range [start,stop]
int findMinimum(int *array, int start, int stop)
{
    // return 0; // modify to return the index of the min value
    int min_index = start; //assume first element is minimum
    
    for (int i = start + 1; i < stop; i++) //check remaining elements
    {
        if (array[i] < array[min_index]) //if found smaller element
        {
            min_index = i; //update minimum index
        }
    }
    
    return min_index; //return index of the min value
}


// =============== Sort Function ===============
// Provided below is a sort function. I have also
// provided a template for how to document functions
// to help organize your code.
// Name: sort
// Input(s):
//  - 'array' is a pointer to an integer address.
//     This is the start of some 'contiguous block of memory' that we will sort.
//  - 'size' tells us how big the array of data is we are sorting.
//  -  'print' tells it to print out after each interation
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void selectionSortIntegers(int *array, unsigned int size, int print)
{
    // todo: implement selection sort
    if (size <= 1) return; //adding this line to fix the empty list issue

    for (unsigned int i = 0; i < size - 1; i++)
    {
        
        int min_idx = findMinimum(array, i, size); //find min in unsorted part
        swap(&array[i], &array[min_idx]); //swap min to current position
        
        if (print) 
        {
            printIntArray(array, size);
        }
    }
}

/***  Code for Insertion Sort ***/

// =============== Sort Function ===============
// Provided below is a sort function. I have also
// provided a template for how to document functions
// to help organize your code.
// Name: sort
// Input(s):
//  - 'array' is a pointer to an integer address.
//     This is the start of some 'contiguous block of memory' that we will sort.
//  - 'size' tells us how big the array of data is we are sorting.
//  - 'print' tells it to print out after each iteration 
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void insertionSortIntegers(int *array, unsigned int size, int print)
{
    // TODO: Implement insertion sort
    if (size <= 1) return; //adding this line to fix the empty list issue

    for (unsigned int i = 1; i < size; i++) //start from the 2nd element
    {
        int key = array[i]; //store current element to insert
        int j = i - 1; //start comparing with previous element
        
        while (j >= 0 && array[j] > key) //shift larger element right
        {
            array[j + 1] = array[j]; //move element one position right
            j--; //move to previous element
        }
        
        array[j + 1] = key; //insert key at correct position
        
        if (print) //print after each pass if requested
        {
            printIntArray(array, size);
        }
    }

}

/** Code for Bubble Sort (from Lab -if not compiling, comment out the internals, but leave the function definition) ***/

// =============== Sort Function ===============
// Name: bubblesort
// Desc: O(n^2) comparison sort
// param(1): 'array' is a pointer to an integer address.
//           This is the start of some 'contiguous block of memory'
//           that we will sort.
// param(2)  'size' tells us how big the array of
//           data is we are sorting.
// param(3) 'print' tells it to print out after each iteration.
// Output:   No value is returned, but 'array' should
//           be modified to store a sorted array of size.
void bubbleSortIntegers(int *array, unsigned int size, int print)
{
    // code generated from lab
    if (size <= 1) return; //adding this line to fix the empty list issue
    
    for (unsigned int i = 0; i < size - 1; i++)
    {
        for (unsigned int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
            }
        }
        
        if (print)
        {
            printIntArray(array, size);
        }
    }

}

// ** You will work on merge sort during the lab on Module 06 ** //

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int temp[], int l, int m, int r)
{
    // if (arr == NULL || temp == NULL)
    // {
    //     exit(1);
    // }

    // if (l > m || m + 1 > r)
    //     return;

    if (arr == NULL || temp == NULL) //check for null
    {
        exit(1);
    }

    if (l > m || m + 1 > r) //check invalid range
        return;

    int i = l; //pointer for left subarray
    int j = m + 1; //pointer for right subarray
    int k = l; //pointer for temp array

    while (i <= m && j <= r) //merge while both subarrays have elements
    {
        if (arr[i] <= arr[j]) //left element is smaller or equal
        {
            temp[k] = arr[i]; //copy from left subarray
            i++;
        }
        else //right element is smaller
        {
            temp[k] = arr[j]; //copy from right subarray
            j++;
        }
        k++;
    }

    while (i <= m) //copy remaining left elements
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= r) //copy remaining right elements
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (i = l; i <= r; i++) //copy merged result back to original array
    {
        arr[i] = temp[i];
    }


}

// To be built during week 6 lab
// Name: mergeSort
// Input(s):
//          (1) 'arr' is a pointer to an integer address.
//              This is the start of some 'contiguous block of memory' that we will sort.
//          (2) 'temp' is a pointer to an integer address.
//          	This helps temporarily store the sorted subarray.
//          (3) 'l' and 'r' are integers, which are the first index and the last index of 'arr' respectively.
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void merge_sort(int arr[], int temp[], int l, int r)
{
    if (l < r) //only sort if range has multiple elements
    {
        int m = l + (r - l) / 2; //cal midpoint avoiding overflow
        
        merge_sort(arr, temp, l, m); //recursively sort left half
        merge_sort(arr, temp, m + 1, r); //recursively sort right half
        merge(arr, temp, l, m, r); //merge sorted halves
    }
   
}
//
// lab build, merge sort

void mergeSortIntegers(int *array, unsigned int size, int print)
{ // print is ignored for this one
    if (array == NULL)
    {
        exit(1);
    }
    if (size <= 1)
        return;

    int *temp = (int *)malloc(sizeof(int) * size);
    merge_sort(array, temp, 0, size - 1);
    free(temp);
}

// provided code 

// =============== Helper Functions ===============
// Name:    compare
// Desc:    A compare function which returns
//          a value (positive,negative, or 0)
//          to show if the result is >,<, or =.
//
// Input:   a and b here are generic types,
//          that is why they are 'void'
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void quickSortIntegers(int* array, unsigned int size, int print) 
{   // print is ignored as qsort doesn't use it
    qsort(array, size, sizeof(int), compare);
}

#endif