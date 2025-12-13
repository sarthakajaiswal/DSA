/*
    PRACTISE SET 1 

    @Goal:      Write a program to reverse an array without using any additional array. The reversal 
                must happen in original array itself using element swapping.  
    @Date:      11 Dec 25 
    @Author:    Sarthak A. Jaiswal 
*/
#include <stdio.h> 

void reverse_array(int A[], int N); 
void show_array(int A[], int N); 

int main(void) 
{
    void test_1(void); 
    void test_2(void); 
    void test_3(void); 

    puts("test_1():"); 
    test_1(); 
    puts("test_2():"); 
    test_2(); 
    puts("test_3():"); 
    test_3(); 

    return (0); 
} 

void test_1(void) // odd array size 
{
    int A[5] = {1, 2, 3, 4, 5}; 
    int N = 5; 

    printf("Array before reversal: "); 
    show_array(A, N); 

    reverse_array(A, N); 

    printf("Array after reversal: "); 
    show_array(A, N); 
} 

void test_2(void) // array size == 1 
{
    int A[1] = {100}; 
    int N = 1; 

    printf("Array before reversal: "); 
    show_array(A, N); 

    reverse_array(A, N); 

    printf("Array after reversal: "); 
    show_array(A, N); 
} 

void test_3(void) // even array size 
{
    int A[6] = {1, 2, 3, 4, 5, 6}; 
    int N = 6; 

    printf("Array before reversal: "); 
    show_array(A, N); 

    reverse_array(A, N); 

    printf("Array after reversal: "); 
    show_array(A, N); 
} 

void reverse_array(int A[], int N) 
{
    int swap_count = N/2; 

    // swap the element from first half with its corrs. element in second half 
    for(int i = 0; i < swap_count; ++i) 
    {
        int tmp; 
        tmp = A[i]; 
        A[i] = A[N-1-i]; 
        A[N-1-i] = tmp; 
    } 
} 

void show_array(int A[], int N) 
{
    int i = 0; 
    while(i < N) 
    {
        printf("%d ", A[i]); 
        i = i + 1; 
    } 
    printf("\n"); 
} 
