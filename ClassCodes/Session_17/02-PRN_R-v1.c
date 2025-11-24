/* 
    @Goal: to print the array in reverse sequence using recursion 
    @Date: 24 Nov 2025 
    @Author: Sarthak A. Jaiswal 
*/

#include <stdio.h> 

void prn_r(int A[], int N, int i); 

int main(void) 
{
    int N = 8; 
    int A[8] = {100, 200, 300, 400, 500, 600, 700, 800}; 

    prn_r(A, N, N-1); 

    return (0); 
} 

void prn_r(int A[], int N, int i) 
{
    if(i < 0 || i >= N) 
        return; 
        
    printf("a[%d]: %d\n", i, A[i]); 
    prn_r(A, N, i-1); 
} 

