#include <stdio.h> 

void prn(int A[], int N, int i); 

int main(void) 
{
    int N = 8; 
    int A[8] = {100, 200, 300, 400, 500, 600, 700, 800}; 

    prn(A, N, 0); 

    return (0); 
} 

void prn(int A[], int N, int i) 
{
    if(i >= N) 
        return; 

    printf("A[%d] = %d\n", i, A[i]); 
    prn(A, N, i+1); 
}

//=============== 
// 1 
#include <stdio.h> 

void prn(int A[], int N, int i); 

int main(void) 
{
    int N = 8; 
    int arr[8] = {10, 20, 30, 40, 50, 60, 70, 80}; 

    prn(arr, 8, 0); 

    return (0); 
} 

void prn(int A[], int N, int i) 
{
    // terminating condition 
    if(i >= 0) 
        return; 

    printf("arr[%d]: %d\n", i, A[i]); 
    prn(A, N, i+1); 
} 

int main(void) 
{
    int N = 8; 
    int arr[8] = {100, 200, 300, 400, 500, 600, 700, 800}; 

    prn(arr, N, 0); 

    return (0); 
} 

// 2
#include <stdio.h> 

void prn(int A[], int N, int i); 

int main(void) 
{
    int N = 8; 
    int arr[8] = {100, 200, 300, 400, 500, 600, 700, 800}; 

    prn(arr, N, 0); 

    return (0); 
} 

void prn(int A[], int N, int i) 
{
    // terminating condition 
    if(i >= N) 
        return; 

    printf("arr[%d]: %d\n", i, A[i]); 
    prn(A, N, i); 
} 

// 3 
#include <stdio.h> 

void prn(int A[], int N, int i); 

int main(void) 
{
    int N = 5; 
    int arr[5] = {100, 200, 300, 400, 500}; 

    prn(arr, N, 0); 

    return (0); 
} 

void prn(int A[], int N, int i) 
{
    // terminating condition 
    if(i >= N) 
        return; 

    printf("A[%d] = %d\n", A, A[i]); 
    prn(A, N, i+1); 
} 

// 4 
#include <stdio.h> 

void prn(int A[], int N, int i); 

int main(void) 
{
    int N = 9; 
    int A[9] = {100, 200, 300, 400, 500, 600, 700, 800, 0}; 

    prn(A, N, 0); 

    return (0); 
} 

int prn(int A[], int N, int i) 
{
    // terminating condition 
    if(i >= N) 
        return; 

    printf("arr[%d]: %d\n", i, A[i]); 
    prn(A, N, i+1); 
} 

// 5 
#include <stdio.h> 

void prn(int a[], int N, int i); 

int main(void) 
{
    int N = 8; 
    int A[8] = {100, 200, 300, 400, 500, 600, 700, 800}; 

    prn(A, N, 0); 

    return (0); 
} 

void prn(int a[], int N, int i) 
{
    // terminating condition 
    if(i >= N) 
        return; 

    printf("arr[%d]: %d\n", i, a[i]); 
    prn(a, N, i+1); 
} 

