/*
    PRACTISE SET 1 

    @Goal:      An array contains N-1 distinct integers in range 1 to N. Exactly one number 
                is missing. Write a program to find a missing number. 
    @Date:      25 Dec 25 
    @Author:    Sarthak A. Jaiswal 
*/

#include <stdio.h> 

int get_missing_number(int arr[], int N); 
void show_array(int* arr, int N); 

int main(void) 
{
    void test_1(void); 
    void test_2(void); 
    void test_3(void); 

    // printf("test_1():"); 
    // test_1(); 
    printf("test_2():"); 
    test_2(); 
    // printf("test_3():"); 
    // test_3(); 

    return (0); 
} 

void test_1(void) // general case 
{
    int arr[] = {1, 2, 4, 5, 6}; 
    int N = 6;  

    show_array(arr, N-1); 
    printf("missing number = %d\n", get_missing_number(arr, N)); 
} 

void test_2(void) // N=2, 2nd element missing 
{
    int arr[] = {1}; 
    int N = 2;  

    show_array(arr, N-1); 
    printf("missing number = %d\n", get_missing_number(arr, N)); 
} 

void test_3(void) // N=2, 1st element missing
{
    int arr[] = {2}; 
    int N = 2;  

    show_array(arr, N-1); 
    printf("missing number = %d\n", get_missing_number(arr, N)); 
} 

int get_missing_number(int arr[], int N) 
{
    int i; 

    i = 0; 
    while(i < N-1) 
    {
        printf("arr[%d] = %d\n", i, arr[i]); 
        if(arr[i] != i+1) // at index 'i' element should be i+1 
            return (i+1); 
        i = i + 1; 
    } 
    return (i); 
} 

void show_array(int arr[], int N) 
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
