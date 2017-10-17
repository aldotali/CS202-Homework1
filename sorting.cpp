/*
 * Title: Algorithms & efficiency
 * Author: Aldo Tali
 * ID: 21500097
 * Section: 2
 * Assignment: 1
 * Description: This file contains the implementation of the sorting 
 *              algorithms that will be tested in homework1
 *--------------------------------------------------------------------
 */

#include "sorting.h"
#include <iostream>
#include <stdlib.h> 
#include <ctime>
#include <iomanip>
using namespace std;

/**
  * This function is the implementation of insertionSort algorithm
  * The function tajes an array of integers, the size of the array,
  * a pass by reference count for comparisons and one for moves.
  * The algorithm will sort the array. It will count the first element 
  * as already sorted and starting from the second it will find the
  * the proper place of the next element in the sorted part of the array
  * In no way do I claim this piece of code to be mine. The following
  * implemtentation was based on the Course Slides.
**/
void insertionSort(int *arr, int size, int &compCount, int &moveCount){

     //variables to be used in the function
     int nextItem;
     int location;
     
     //traverse the array n-1 times since we count the first element to be already sorted by nature
     for ( int unsorted = 1; unsorted < size; unsorted++) {
         
         //store the current item that needs to be put in the sorted array
         nextItem =  arr[unsorted];
         location = unsorted; 
         moveCount++;
         
         //traverse the sorted array until we find the location of the new element that will be inserted
         //also shift all the elements greater than the current item to the right 
         for ( ; location > 0 && arr[location - 1 ] > nextItem; location--) {
             compCount++; //each time the loop runs 1 checking occurs
             moveCount++; // we keep shifting the numbers
             arr[location] = arr[location-1];
         }
         //this count overhead is for the time when the loop breaks 
         //if (location > 0)
             compCount++;
         
         //last movement
         moveCount++;
         //insert our current item to the correct sorted position
         arr[location] = nextItem;
     }
      
}


/**
  * These functions are the implementation of the merge sort algorithm
  * The function takes an array of integers, the size of the array,
  * a pass by reference count for comparisions and one for moves.
  * The algorithm will sort the array. It will use a recursive way
  * for the divide and conquer. Firstly the division of the array
  * into equal part is done recursively and then the merge of the
  * divided parts will take place.
  * In no way do I claim this piece of code to be mine. The following
  * implementation was based on the Course Slides.
 **/
void mergeSort(int *arr, int size, int &compCount, int &moveCount){
     mergesort (arr, size, 0, size-1, compCount, moveCount);
}

//the recursive algorithm implementation for mergesort
void mergesort(int *arr, int size, int first, int last, int &compCount, int &moveCount){
     //the recursive call gets executed only if we still have some partitioning and merging left to be done
     if (first < last){
        
        //use midpoint for partitioning       
        int mid = (first + last)/2;
        
        //recursively call both sides of the array
        mergesort(arr, size, first, mid, compCount, moveCount);
        mergesort(arr, size, mid+1, last, compCount, moveCount);
        
        //merge the sorted halves of the array
        merge(arr, first, mid, last, size, compCount, moveCount);
     }
}

//the merge function for merging 2 sorted arrays into 1
void merge(int *arr, int first, int mid,  int last, int size, int &compCount, int &moveCount){
     //use of temporaryArray to store the values in sorted order
     int tempArray[size];
     
     //keep track of the beginign and ending of the partitions
     int first1 = first, last1 = mid;
     int first2 = mid + 1, last2 = last;
     int index = first1;
     
     //move through the array and pass the elements to the temporary array in a sorted fashion
     for ( ; (first1 <= last1)&& (first2 <= last2); index++){
         compCount++;
         moveCount++;
         if ( arr[first1] < arr[first2] ) {
            tempArray[index] = arr[first1];
            first1++;
         }
         else {
              tempArray[index] = arr[first2];
              first2++;
         }
     }
     
     //if there is any element left on the first half then put those element to the temporary array
     for ( ; first1 <= last1; first1++, index++){
         moveCount++;
         tempArray[index] = arr[first1];
     }
     
     //if there is any element left on the second half then put those element to the temporary array
     for ( ; first2 <= last2; first2++, index++) {
         moveCount++;
         tempArray[index] = arr[first2];
     }
     
     //transfer back the data from the temporary to the original array 
     for (index = first; index <= last; index++) {
         moveCount++;
         arr[index] = tempArray[index];
     }
}


/**
  * These functions are the implementation of the quick sort algorithm
  * The function takes an array of integers, the size of the array,
  * a pass by reference count for comparisions and one for moves.
  * The algorithm will sort the array. It will use a recursive way
  * for the divide and conquer. The partitioning of the array is done 
  * by using the last element of the array as a pivot.
  * In no way do I claim this piece of code to be mine. The following
  * implementation was based on the Course Slides.
 **/
 
void quickSort(int *arr, int size, int &compCount, int &moveCount){
     quicksort(arr, 0, size-1,compCount, moveCount);
}


//fuction which handles the recursive calls of the quickSort function.
void quicksort(int *arr, int first, int last,int &compCount, int &moveCount){
     //keeps the index of the pivot in the array
     int pivotIndex ;
     
     //use the recursive definitions only if we still have unsorted elements
     if (first < last) {
        
        //keep partitioning the array into 2 regions less than and larger than
        //the pivot,respectively.
        partition(arr,first,last,pivotIndex,compCount, moveCount);
        
        //Sort the regions defined above
        quicksort(arr, first, pivotIndex,compCount,moveCount);
        quicksort(arr, pivotIndex+1, last,compCount, moveCount);
      
     }
}


//divides the array into two regions S1 and S2
void partition(int *arr, int first, int last, int &pivotIndex,int &compCount, int &moveCount){
     //choose the last element of the array as pivot
     int pivot = arr[last];
     moveCount++;
     //define the region bounds
     int lastS1 = first;
     int firstUnknown = first;
     
     //traverse the unknown region and put elements less than pivot in S1,
     // and elements bigger than pivot into S2. 
     for (; firstUnknown < last; firstUnknown++) {
         compCount++;
         if (arr[firstUnknown] < pivot){
            lastS1++;
            moveCount+=3;
            swap(arr[firstUnknown], arr[lastS1]);
         }
     }
     
     moveCount+=3;
     //put the pivot to its right place
     swap(arr[last], arr[lastS1]);
     pivotIndex = lastS1;
}

//swaps two integers with one another
void swap (int &no1 , int &no2 ){
     int x = no1;
     no1 = no2;
     no2 = x; 
}

//this function was implemented for testing purposes
void displayArray(int *arr, int size){
     for (int i = 0 ; i < size; i++) {
         cout<<arr[i]<<" ";
     }
     cout<<endl;
}


//The following will execute parts a, b and c 
void performanceAnalysis(){
     executePartb1();
     cout<<endl<<endl;
     executePartb2();
     cout<<endl<<endl;
     executePartb3();
     cout<<endl<<endl;
}


/*
 * Creates 3  random arrays and executes part 1 of the Homework to test the 
 * performance of the sort algorithms.
 *
 */
void executePartb1(){
     const int ARRAYSIZES = 5;
     int** doubleArray;
     int arraySizes[ARRAYSIZES] = {1000,5000,10000,15000,20000};
 
     cout<<"Part b1 - Performance analysis of random integers array\n----------------------------------------------------------\n";
     cout<<"\t\tElapsed Time\tcompCount\tmoveCount\n";

     // generates the random size arrays and runs the sort algorithms to check the performance
     for (int i = 0; i < ARRAYSIZES; i++) {
         doubleArray = generateRandomArrays(arraySizes[i]);
         printOutput(arraySizes,i, doubleArray);
         deallocate2DArray(doubleArray, 3);
     }
}


/*
 * Creates 3  ascending arrays and executes part 1 of the Homework to test the 
 * performance of the sort algorithms.
 *
 */
void executePartb2(){
     const int ARRAYSIZES = 5;
     int** doubleArray;
     int arraySizes[ARRAYSIZES] = {1000,5000,10000,15000,20000};
 
     cout<<"Part b2 - Performance analysis of Ascending integers array\n----------------------------------------------------------\n";
     cout<<"\t\tElapsed Time\tcompCount\tmoveCount\n";

     // generates the ascending size arrays and runs the sort algorithms to check the performance
     for (int i = 0; i < ARRAYSIZES; i++) {
         doubleArray = generateAscendingArrays(arraySizes[i]);
         printOutput(arraySizes,i, doubleArray);
         deallocate2DArray(doubleArray, 3);
     }
}

/*
 * Creates 3  ascending arrays and executes part 1 of the Homework to test the 
 * performance of the sort algorithms.
 *
 */
void executePartb3(){
     const int ARRAYSIZES = 5;
     int** doubleArray;
     int arraySizes[ARRAYSIZES] = {1000,5000,10000,15000,20000};
 
     cout<<"Part b3 - Performance analysis of Descending integers array\n----------------------------------------------------------\n";
     cout<<"\t\tElapsed Time\tcompCount\tmoveCount\n";

     // generates the descending size arrays and runs the sort algorithms to check the performance
     for (int i = 0; i < ARRAYSIZES; i++) {
         doubleArray = generateDescendingArrays(arraySizes[i]);
         printOutput(arraySizes,i, doubleArray);
         deallocate2DArray(doubleArray, 3);
     }
}

//dallocates the 2 dimensional array on the heap
void deallocate2DArray(int** array, int rows){
     for (int i = 0; i < rows; i++) {
         delete[] array[i];
     }
     delete[] array;
}

//generates three random arrays
int** generateRandomArrays(int size){
      int randNum;
      int** doubleArray = new int*[3];
      doubleArray[0] = new int[size];
      doubleArray[1] = new int[size];
      doubleArray[2] = new int[size];
      for (int i = 0; i < size; i++) {
         randNum = rand();
         doubleArray[0][i] = randNum;
         doubleArray[1][i] = randNum;
         doubleArray[2][i] = randNum;
     }
     return doubleArray;
}


//generates three ascending arrays
int** generateAscendingArrays(int size){
      int** doubleArray = new int*[3];
      doubleArray[0] = new int[size];
      doubleArray[1] = new int[size];
      doubleArray[2] = new int[size];
      for (int i = 0; i < size; i++) {
         doubleArray[0][i] = i;
         doubleArray[1][i] = i;
         doubleArray[2][i] = i;
     }
     return doubleArray;
}

//generates three descending arrays
int** generateDescendingArrays(int size){
      int** doubleArray = new int*[3];
      doubleArray[0] = new int[size];
      doubleArray[1] = new int[size];
      doubleArray[2] = new int[size];
      int count = size;
      for (int i = 0; i < size; i++) {
         doubleArray[0][i] = count;
         doubleArray[1][i] = count;
         doubleArray[2][i] = count;
         count = count - 1;
     }
     return doubleArray;
}


//Runs the insertion algorithms and outputs the analysis
void printOutput(int* arraySizes,int size, int** arr){
     clock_t beginTime = clock();
     clock_t endTime;
     int compCount = 0, moveCount = 0; 
     int elapsedTime = 0;
      
     //make a call to insertion sort
     cout<<"Array Size : "<<arraySizes[size]<<endl;
     beginTime = clock();
     insertionSort(arr[0],arraySizes[size], compCount,  moveCount);
     endTime = clock();
     elapsedTime = endTime - beginTime;
     cout<<"Insertion Sort"<<setw(10)<<elapsedTime<<setw(15)<<compCount<<setw(15)<<moveCount<<endl;
     compCount = 0; moveCount = 0; elapsedTime = 0;
     
     //make a call to merge sort
     beginTime = clock();
     mergeSort(arr[1],arraySizes[size], compCount,  moveCount);
     endTime = clock();
     elapsedTime = endTime - beginTime;
     cout<<"MergeSort"<<setw(15)<<elapsedTime<<setw(15)<<compCount<<setw(15)<<moveCount<<endl;
     compCount = 0; moveCount = 0; elapsedTime = 0;
     
     //make a call to quicksort
     beginTime = clock();
     quickSort(arr[2],arraySizes[size], compCount,  moveCount);
     endTime = clock();
     elapsedTime = endTime - beginTime;
     cout<<"QuickSort"<<setw(15)<<elapsedTime<<setw(15)<<compCount<<setw(15)<<moveCount<<endl;
     cout<<"----------------------------------------------------------\n";

}

