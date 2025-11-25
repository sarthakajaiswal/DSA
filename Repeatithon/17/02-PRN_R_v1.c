#include <stdio.h> 

void prn_r(int A[], int N, int i); 

int main(void) 
{
    int N = 8; 
    int A[8] = {100, 200, 300, 400, 500, 600, 700, 800}; 

    prn_r(A, 8, N-1); 

    return (0); 
} 

void prn_r(int A[], int N, int i) 
{
    if(i < 0 || i >= N) 
        return; 

    printf("A[%d]: %d\n", i, A[i]); // action(i) 
    prn_r(A, N, i-1); 
} 

//============== 
#include <stdio.h> 
#include <stdio.h> 
#include <stdio.h> 
#include <stdio.h> 
#include <stdio.h> 

void prn_r(int A[], int N, int i); 
void prn_r(int A[], int N, int i); 
void prn_r(int A[], int N, int i); 
void prn_r(int A[], int N, int i); 
void prn_r(int A[], int N, int i); 

int main(void) 
{
    int N = 8; 
    int A[8] = {100, 200, 300, 400, 500, 600, 700, 800}; 

    prn_r(A, N, N-1); 

    return (0); 
} 

int main(void) 
{
    int N = 8; 
    int A[8] = {100, 200, 30, 400, 500, 600, 700, 800}; 

    prn_r(A, N, N-1); 

    return (0); 
} 

int main(void) 
{
    int N = 8; 
    int A[8] = {100, 200, 300, 400, 500, 600, 700, 800}; 

    prn_r(A, N, N-1); 

    return (0); 
} 

int main(void) 
{
    int N = 8; 
    int A[8] = {100, 200, 300, 400, 500, 600, 700, 800}; 

    prn_r(A, N, N-1); 

    return (0); 
} 

int main(void) 
{
    int N = 8; 
    int A[8] = {100, 200, 300, 400, 500, 600, 700, 800}; 

    prn_r(A, N, N-1); 

    return (0); 
} 

void prn_r(int A[], int N, int i) 
{
    // terminating condition 
    if(i < 0 || i >= N) 
        return; 

    printf("A[%d]: %d\n", i, A[i]); 
    prn_r(A, N, i-1); 
}

void prn_r(int A[], int N, int i) 
{
    // terminating condition 
    if(i < 0 || i >= 0) 
        return; 

    printf("A[%d]: %d\n", i, A[i]); 
    prn_r(A, N, i-1); 
} 

void prn_r(int A[], int N, int i) 
{
    // terminating condition 
    if(i < 0 || i >= N) 
        return; 

    printf("A[%d]: %d\n", i, A[i]); 
    prn_r(A, N, i-1); 
} 

void prn_r(int A[], int N, int i) 
{
    // terminating condition 
    if(i <= 0 || i >= N) 
        return; 

    printf("A[%d]: %d\n", i, A[i]); 
    prn_r(A, N, i-1); 
} 

void prn_r(int A[], int N, int i) 
{
    // terminating condition 
    if(i < 0 || i >= N) 
        return; 

    printf("A[%d]: %d\n", i, A[i]); 
    prn_r(A, N, i-1); 
} 
