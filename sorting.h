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
 
// Question 2 - part (a): function prototypes -- given by the assignment
void insertionSort(int *arr, int size, int &compCount, int &moveCount);
void mergeSort(int *arr, int size, int &compCount, int &moveCount);
void quickSort(int *arr, int size, int &compCount, int &moveCount);
// Question 2 - part (b): function prototype -- given by the assignement
void performanceAnalysis();


//helper fuctions that will be used by the implementation of my homework
void mergesort(int *arr, int size, int first, int last, int &compCount, int &moveCount);
void merge(int *arr, int first, int mid, int last, int size,int &compCount, int &moveCount);
void quicksort(int *arr, int first, int last,int &compCount, int &moveCount);
void partition(int *arr, int first, int last, int &,int &compCount, int &moveCount);
void swap (int &no1 , int &no2 );
void displayArray(int *arr, int size);


void printOutput(int* arraySizes,int size, int** arr1);
void deallocate2DArray(int** array, int rows);
int** generateRandomArrays(int size);
int** generateAscendingArrays(int size);
int** generateDescendingArrays(int size);
void executePartb1();
void executePartb2();
void executePartb3();


