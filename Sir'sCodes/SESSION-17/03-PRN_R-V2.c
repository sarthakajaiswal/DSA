#include <stdio.h> 

void prn_r(int A[], int N, int i); 

int main(void)
{
    int N = 8; 
    int A[8] = {100, 200, 300, 400, 500, 600, 700, 800}; 
    
    prn_r(A, N, 0); 

    return (0); 
}

void prn_r(int A[], int N, int i)
{
    if(i >= N) 
        return; 

    prn_r(A, N, i+1); 
    printf("A[%d]:%d\n", i, A[i]);  // ACTION(i)
}