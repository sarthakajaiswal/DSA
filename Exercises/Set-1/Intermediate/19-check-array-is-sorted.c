/*
    PRACTISE SET 1 

    @Goal:      Write a program to check wether an array is sorted in non-decreasing order. 
                Return "Sorted" or "Not Sorted" accordingly. 
    @Date:      13 Dec 25 
    @Author:    Sarthak A. Jaiswal 
*/

#include <stdio.h> 

const char* check_array_is_sorted_non_decreasingly(int* arr, int N); 
void show_array(int* arr, int N); 

int main(void) 
{
    void test_1(void); 
    void test_2(void); 
    void test_3(void); 
    void test_4(void); 
    void test_5(void); 
    void test_6(void); 

    printf("test_1():"); 
    test_1(); 
    printf("test_2():"); 
    test_2(); 
    printf("test_3():"); 
    test_3(); 
    printf("test_4():"); 
    test_4(); 
    printf("test_5():"); 
    test_5(); 
    printf("test_6():"); 
    test_6(); 

    return (0); 
} 

void test_1(void) // general case 
{
    int arr[] = {1, 2, 2, 4, 5}; 
    int N = 5;  
    const char* array_sort_status = NULL; 

    show_array(arr, 5); 
    array_sort_status = check_array_is_sorted_non_decreasingly(arr, N); 
    puts(array_sort_status); 
} 

void test_2(void) // array with 1 element 
{
    int arr[] = {1}; 
    int N = 1;  
    const char* array_sort_status = NULL; 

    show_array(arr, 1); 
    array_sort_status = check_array_is_sorted_non_decreasingly(arr, N); 
    puts(array_sort_status); 
} 

void test_3(void) // all elements same 
{
    int arr[] = {2, 2, 2, 2, 2}; 
    int N = 5;  
    const char* array_sort_status = NULL; 

    show_array(arr, 5); 
    array_sort_status = check_array_is_sorted_non_decreasingly(arr, N); 
    puts(array_sort_status); 
} 

void test_4(void) // strictly-decreasing order  
{
    int arr[] = {5, 4, 3, 2, 1}; 
    int N = 5;  
    const char* array_sort_status = NULL; 

    show_array(arr, 5); 
    array_sort_status = check_array_is_sorted_non_decreasingly(arr, N); 
    puts(array_sort_status); 
} 

void test_5(void) // strictly-increasing order  
{
    int arr[] = {1, 2, 3, 4, 5}; 
    int N = 5;  
    const char* array_sort_status = NULL; 

    show_array(arr, 5); 
    array_sort_status = check_array_is_sorted_non_decreasingly(arr, N); 
    puts(array_sort_status); 
} 

void test_6(void) // random elements 
{
    int arr[] = {45, 6, 7, 234, 8}; 
    int N = 5;  
    const char* array_sort_status = NULL; 

    show_array(arr, 5); 
    array_sort_status = check_array_is_sorted_non_decreasingly(arr, N); 
    puts(array_sort_status); 
} 

const char* check_array_is_sorted_non_decreasingly(int* arr, int N) 
{
    int i; 

    // code 
    for(i = 1; i < N; ++i) 
    {
        if(arr[i] < arr[i-1]) 
            return ("Not Sorted"); 
    } 

    return ("Sorted"); 
} 

void show_array(int* arr, int N) 
{
    int i; 

    // code 
    i = 0; 
    while(i < N) 
    {
        printf("%d ", arr[i]); 
        i = i + 1; 
    } 
} 
