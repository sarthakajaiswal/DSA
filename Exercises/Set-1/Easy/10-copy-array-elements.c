/*
    PRACTISE SET 1 

    @Goal:      Write a program that copies all elements from one array to 
                another array(of same size) using a loop. 
    @Date:      11 Dec 25 
    @Author:    Sarthak A. Jaiswal 
*/

#include <stdio.h> 

void copy_array(int src[], int dest[], int N); 
void print_array(int A[], int N); 

int main(void) 
{
    void test_1(void); 
    void test_2(void); 

    puts("test_1():"); 
    test_1(); 
    puts("test_2():"); 
    test_2(); 
    
    return (0); 
} 

void test_1(void) 
{
    int A[5] = {1, 2, 3, 4, 5}; 
    int B[5]; 
    int N = 5;

    printf("Source array: "); 
    print_array(A, N); 
    printf("\n"); 

    copy_array(A, B, N); 

    printf("Copied array: "); 
    print_array(B, N); 
    printf("\n"); 
} 

void test_2(void) 
{
    int A[3] = {1, 2, 3}; 
    int B[1]; 
    int N = 1;

    printf("Source array: "); 
    print_array(A, N); 
    printf("\n"); 

    copy_array(A, B, N); 

    printf("Copied array: "); 
    print_array(B, N); 
    printf("\n"); 
} 

void copy_array(int src[], int dest[], int N)
{
    int i; 

    for(i = 0; i < N; ++i) 
        dest[i] = src[i]; 
} 

void print_array(int A[], int N) 
{
    int i; 

    for(i = 0; i < N; ++i) 
        printf("%d ", A[i]); 
} 

