/*
    PRACTISE SET 1 

    @Goal:      Write a program that takes two sorted arrays and merges them into single array. 
                You must use a third array to store the result. 
    @Date:      13 Dec 25 
    @Author:    Sarthak A. Jaiswal 
*/

#include <stdio.h> 
#include <stdlib.h> 

void print_array(int* arr, int N, const char* msg); 
int* merge_sorted_arrays(int* a1, int N1, int* a2, int N2, int* retSize); 

int main(void) 
{
    void test_1(void); 
    void test_2(void); 
    void test_3(void); 
    void test_4(void); 

    puts("test_1():"); 
    test_1(); 
    puts("test_2():"); 
    test_2(); 
    puts("test_3():"); 
    test_3(); 
    puts("test_4():"); 
    test_4(); 

    return (0); 
} 

void test_1(void) // normal case 
{
    int arr1[] = {1, 3, 5, 7}; 
    int arr2[] = {2, 4, 6, 8}; 
    int N1 = 4, N2 = 4; 

    int* merged_array = NULL; 
    int merged_array_size = -1; 

    print_array(arr1, N1, "a1: "); 
    print_array(arr2, N2, "a2: "); 

    merged_array = merge_sorted_arrays(arr1, N1, arr2, N2, &merged_array_size); 
    if(merged_array == NULL || merged_array_size <= 0) 
    {
        printf("Array merging failed\n"); 
        return; 
    } 
    print_array(merged_array, merged_array_size, "merged_array: ");  

    free(merged_array); 
    merged_array = NULL; 
    merged_array_size = -1; 
} 

void test_2(void) // first array with size=1
{
    int arr1[] = {2}; 
    int arr2[] = {1, 4, 6, 8}; 
    int N1 = 1, N2 = 4; 

    int* merged_array = NULL; 
    int merged_array_size = -1; 

    print_array(arr1, N1, "a1: "); 
    print_array(arr2, N2, "a2: "); 

    merged_array = merge_sorted_arrays(arr1, N1, arr2, N2, &merged_array_size); 
    if(merged_array == NULL || merged_array_size <= 0) 
    {
        printf("Array merging failed\n"); 
        return; 
    } 
    print_array(merged_array, merged_array_size, "merged_array: ");  

    free(merged_array); 
    merged_array = NULL; 
    merged_array_size = -1; 
} 

void test_3(void) // all elements of 1st array smaller than that of second  
{
    int arr1[] = {5, 5, 5, 5}; 
    int arr2[] = {6, 6, 6, 6}; 
    int N1 = 4, N2 = 4; 

    int* merged_array = NULL; 
    int merged_array_size = -1; 

    print_array(arr1, N1, "a1: "); 
    print_array(arr2, N2, "a2: "); 

    merged_array = merge_sorted_arrays(arr1, N1, arr2, N2, &merged_array_size); 
    if(merged_array == NULL || merged_array_size <= 0) 
    {
        printf("Array merging failed\n"); 
        return; 
    } 
    print_array(merged_array, merged_array_size, "merged_array: ");  

    free(merged_array); 
    merged_array = NULL; 
    merged_array_size = -1; 
} 

void test_4(void) // second array size smaller than that of first 
{
    int arr1[] = {1, 2, 3, 4}; 
    int arr2[] = {5, 6}; 
    int N1 = 4, N2 = 2; 

    int* merged_array = NULL; 
    int merged_array_size = -1; 

    print_array(arr1, N1, "a1: "); 
    print_array(arr2, N2, "a2: "); 

    merged_array = merge_sorted_arrays(arr1, N1, arr2, N2, &merged_array_size); 
    if(merged_array == NULL || merged_array_size <= 0) 
    {
        printf("Array merging failed\n"); 
        return; 
    } 
    print_array(merged_array, merged_array_size, "merged_array: ");  

    free(merged_array); 
    merged_array = NULL; 
    merged_array_size = -1; 
} 

void print_array(int* arr, int N, const char* msg)  
{
    int i = 0; 

    // code 
    if(msg) 
        printf("%s ", msg); 

    while(i < N) 
    {
        printf("%d ", arr[i]); 
        i = i + 1; 
    } 
    printf("\n"); 
} 

int* merge_sorted_arrays(int* a1, int N1, int* a2, int N2, int* retSize) 
{
    int* new_array = NULL; 
    int N; 
    int i, j; 
    
    // code 
    N = N1 + N2; 
    new_array = (int*)malloc(N * sizeof(int)); 
    if(new_array == NULL) 
    {
        fprintf(stderr, "merge_sorted_arrays():fatal: out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    i = 0, j = 0;
    int k = 0;  
    while(1) 
    {
        if(i >= N1) 
        {
            while(j < N2)
            {
                new_array[k] = a2[j]; 
                k = k + 1; 
                j = j + 1; 
            } 
            break; 
        } 

        if(j >= N2)
        {
            while(i < N1)
            {
                new_array[k] = a1[i]; 
                k = k + 1; 
                j = j + 1; 
            } 
            break; 
        }

        if(a1[i] < a2[j]) 
        {
            new_array[k] = a1[i]; 
            i = i + 1; 
            k = k + 1; 
        } 
        else 
        {
            new_array[k] = a2[j]; 
            j = j + 1; 
            k = k + 1; 
        }
    } 

    *retSize = N; 
    return (new_array); 
} 

