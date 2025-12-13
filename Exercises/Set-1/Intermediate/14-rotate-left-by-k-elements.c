/*
    PRACTISE SET 1 

    @Goal:      Write a program to rotate an array to left by K positions. After rotation, 
                the first K elements should move to end. Do this in place without using additions arrays. 
    @Date:      12 Dec 25 
    @Author:    Sarthak A. Jaiswal 
*/

#include <stdio.h> 

void rotate_left_by_k_positions(int* arr, int N, int K); 
void print_array(int arr[], int N); 

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

void test_1(void) 
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};  
    int N = 7; 
    int K = 3; // nr of times array to be rotated 

    printf("Before rotate_left(): "); 
    print_array(arr, N); 
    rotate_left_by_k_positions(arr, N, K); 
    printf("After rotate_left(): "); 
    print_array(arr, N); 
} 

void test_2(void) 
{
    int arr[] = {1, 2, 3};  
    int N = 3; 
    int K = 3; // nr of times array to be rotated 

    printf("Before rotate_left(): "); 
    print_array(arr, N); 
    rotate_left_by_k_positions(arr, N, K); 
    printf("After rotate_left(): "); 
    print_array(arr, N); 
} 

void test_3(void) 
{
    int arr[] = {1};  
    int N = 1; 
    int K = 3; // nr of times array to be rotated 

    printf("Before rotate_left(): "); 
    print_array(arr, N); 
    rotate_left_by_k_positions(arr, N, K); 
    printf("After rotate_left(): "); 
    print_array(arr, N); 
} 

void test_4(void) 
{
    int arr[] = {10, 20};  
    int N = 2; 
    int K = 3; // nr of times array to be rotated 

    printf("Before rotate_left(): "); 
    print_array(arr, N); 
    rotate_left_by_k_positions(arr, N, K); 
    printf("After rotate_left(): "); 
    print_array(arr, N); 
} 

void print_array(int arr[], int N) 
{
    int i = 0; 

    // code 
    while(i < N) 
    {
        printf("%d ", arr[i]); 
        i = i + 1; 
    }
    printf("\n"); 
}

void rotate_left_by_k_positions(int* arr, int N, int K) 
{
    // code 
    for(int i = 0; i < K; ++i) // k times rotation 
    {
        int tmp = arr[0]; 
        int j = 0; 
        while(j < N-1) 
        {
            arr[j] = arr[j+1]; 
            j = j + 1; 
        } 
        arr[j] = tmp; 
    } 
} 
