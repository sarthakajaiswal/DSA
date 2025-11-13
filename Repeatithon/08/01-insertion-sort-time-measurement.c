#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <time.h> 

void input(int* p_array, int N); 
void output(int* p_array, int N, const char* msg); 
void sort(int* p_array, int N); 

int main(void) 
{
    int* a = NULL; 
    int N = 0; 

    time_t t_start; 
    time_t t_end; 
    time_t t_delta; 

    printf("Enter size of array: "); 
    scanf("%d", &N); 

    if(N <= 0) 
    {
        puts("Bad size for array"); 
        exit(EXIT_FAILURE); 
    } 

    a = (int*)malloc(N * sizeof(int)); 
    if(NULL == a) 
    {
        puts("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    input(a, N); 
    t_start = time(0); 
    sort(a, N); 
    t_end = time(0); 
    t_delta = t_end-t_start; 
    printf("INTEGRAL TIME FOR SORT: %lu\n", t_delta); 
    
    free(a); 
    a = NULL; 
} 

void input(int* p_array, int N) 
{
    int cap = N * 10; 
    int i; 

    srand(time(0)); 

    i = 0; 
    while(i < N) 
    {
        p_array[i] = rand() % cap; 
        i = i + 1; 
    }
} 

void output(int* p_array, int N, const char* msg) 
{
    int i; 

    if(NULL != msg) 
        puts(msg); 

    i = 0; 
    while(i < N) 
    {
        printf("a[%d]: %d\n", i, p_array[i]); 
        i = i + 1; 
    } 
} 

void sort(int* p_array, int N) 
{
    int i, j; 
    int key; 

    j = 1; 
    while(j < N) 
    {
        key = p_array[j]; 

        i = j - 1; 
        while(i > -1 && p_array[i] > key) 
        {
            p_array[i+1] = p_array[i]; 
            i = i - 1; 
        } 
        p_array[i+1] = key; 

        j = j + 1; 
    } 
} 

//======= 
// 1 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <time.h> 

// 2 
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

#include <stdlib.h> 
#include <stdio.h> 
#include <time.h> 

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

//======== 
// 1 
void input(int* p_array, int N); 
void output(int* p_array, int N, const char* msg); 
void sort(int* p_array, int N); 

// 2 
void input(int* p_array, int N); 
void output(int* p_array, int N, const char* msg); 
void sort(int* p_array, int N); 

// 3 
void input(int* p_array, int N); 
void output(int* p_array, int N, const char* msg); 
void sort(int* p_array, int N); 

// 4 
void input(int* p_array, int N); 
void output(int* p_array, int N, const char* msg); 
void sort(int* p_array, int N); 

// 5 
void input(int* p_array, int N); 
void output(int* p_array, int N, const char* msg); 
void sort(int* p_array, int N); 

// ======== 
int main(void) 
{
    int* a = NULL; 
    int N = 0; 

    time_t t_start; 
    time_t t_end; 
    time_t t_delta; 

    printf("Enter size of array: "); 
    scanf("%d", &N); 

    if(N <= 0) 
    {
        puts("Bad array size"); 
        exit(EXIT_FAILURE); 
    } 

    a = (int*)malloc(N * sizeof(int)); 
    if(NULL == a) 
    {
        puts("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    intput(a, N); 
    t_start = time(0); 
    sort(a, N); 
    t_end = time(0); 
    t_delta = t_end - t_start; 
    printf("INTEGRAL TIME FOR SORT: %lu\n", t_delta); 

    free(a); 
    a = NULL; 
} 

// 2 
int main(void) 
{
    int* a = NULL; 
    int N = -1; 

    time_t t_start; 
    time_t t_end; 
    time_t t_delta; 

    printf("Enter size for array:"); 
    scanf("%d", &N); 

    if(N <= 0) 
    {
        puts("Bad array size"); 
        exit(EXIT_FAILURE); 
    } 

    a = (int*)malloc(N * sizeof(int)); 
    if(NULL == a) 
    {
        puts("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    input(a, N); 
    t_start = time(0); 
    sort(a, N); 
    t_end = time(0); 
    t_delta = t_end - t_start; 

    printf("INTEGRAL TIME FOR SORT: %lu\n", t_delta); 

    free(a); 
    a = NULL; 
} 

// 3 
int main(void) 
{
    int* a = NULL; 
    int N = -1; 

    time_t t_start; 
    time_t t_end; 
    time_t t_delta; 

    printf("Enter array size: "); 
    scanf("%d", &N); 
    if(N <= 0) 
    {
        puts("Bad array size"); 
        exit(EXIT_FAILURE); 
    } 

    a = (int*)malloc(N * sizeof(int)); 
    if(NULL == a) 
    {
        puts("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    input(a, N); 
    t_start = time(0); 
    sort(a, N); 
    t_end = time(0); 
    t_delta = t_end - t_start; 
    printf("INTEGRAL TIME FOR SORTING : %lu\n", t_delta); 

    free(a); 
    a = NULL; 
} 

// 4 
int main(void) 
{
    int* a = NULL; 
    int N = -1; 

    time_t t_start; 
    time_t t_end; 
    time_t t_delta; 

    printf("Enter array size : "); 
    scanf("%d", &N); 

    if(N <= 0) 
    {
        puts("Bad array size"); 
        exit(EXIT_FAILURE); 
    } 

    a = (int*)malloc(N * sizeof(int)); 
    if(NULL == a) 
    {
        puts("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    input(a, N); 
    t_start = time(0); 
    sort(a, N); 
    t_end = time(0); 
    t_delta = t_end - t_start; 
    printf("INTEGRAL TIME FOR SORT: %lu\n", t_delta); 

    free(a); 
    a = NULL; 
} 

// 5 
int main(void) 
{
    int* a = NULL; 
    int N = -1; 

    time_t t_start; 
    time_t t_end; 
    time_t t_delta; 

    printf("Enter array size:"); 
    scanf("%d", &N); 

    if(N <= 0) 
    {
        puts("Bad array size"); 
        exit(EXIT_FAILURE); 
    } 

    a = (int*)malloc(N * sizeof(int)); 
    if(NULL == a) 
    {
        puts("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    input(a, N); 
    t_start = time(0); 
    sort(a, N); 
    t_end = time(0); 
    t_delta = t_end - t_start; 
    printf("INTEGRAL TIME FOR SORT : %lu\n", t_delta); 

    free(a); 
    a = NULL; 
} 

//======== 
// 1 
void input(int* p_array, int N) 
{
    int cap = N * 10; 
    int i; 
    
    srand(time(0)); 

    i = 0; 
    while(i < N) 
    {
        p_array[i] = rand() % cap; 
        i = i + 1;  
    } 
} 

// 2 
void input(int* p_array, int N) 
{
    int cap = N * 10; 
    int i; 

    srand(tie(0)); 

    i = 0; 
    while(i < N) 
    {
        p_array[i] = rand() % cap; 
        i = i + 1; 
    } 
} 

// 3 
void input(int* p_array, int N) 
{
    int i; 
    int cap = N * 10; 

    srand(time(0)); 

    i = 0; 
    while(i < N) 
    {
        p_array[i] = rand() % cap; 
        i = i + 1; 
    } 
} 

// 4 
void input(int* p_array, int N) 
{
    int cap = N * 10; 
    int i; 

    srand(time(0)); 

    i = 0; 
    while(i < N) 
    {
        p_array[i] = rand() % cap; 
        i = i + 1; 
    } 
} 

// 5 
void input(int* p_array, int N) 
{
    int cap = N * 10; 
    int i; 

    srand(time(0)); 

    i = 0; 
    while(i < N) 
    {
        p_array[i] = rand() % cap; 
        i = i + 1; 
    } 
} 

//========= 
// 1 
void output(int* p_array, int N, const char* msg) 
{
    int i; 

    if(NULL != msg) 
        puts(msg); 

    i = 0; 
    while(i < N) 
    {
        printf("a[%d]: %d\n", i, p_array[i]); 
        i = i + 1; 
    } 
} 

// 2 
void output(int* p_array, int N, const char* msg) 
{
    int i; 

    if(NULL != msg) 
        puts(msg); 

    i = 0; 
    while(i < N) 
    {
        printf("a[%d]: %d\n", i, p_array[i]); 
        i = i + 1; 
    } 
} 

// 3 
void output(int* p_array, int N, const char* msg) 
{
    int i; 

    if(msg != NULL) 
        puts(msg); 

    i = 0; 
    while(i < N) 
    {
        printf("a[%d]: %d\n", i, p_array[i]); 
        i = i + 1; 
    } 
} 

// 4 
void output(int* p_array, int N, const char* msg) 
{
    int i; 

    if(msg != NULL) 
        puts(msg); 

    i = 0; 
    while(i < N) 
    {
        printf("a[%d]: %d\n", i, p_array[i]); 
        i  = i + 1; 
    } 
} 

// 5 
void output(int* p_array, int N, const char* msg) 
{
    int i; 

    if(msg != NULL) 
        puts(msg); 

    i = 0; 
    while(i < N) 
    {
        printf("a[%d]: %d\n", i, p_array[i]); 
        i = i + 1; 
    } 
} 

//=========== 
// 1 
void sort(int* p_array, int N) 
{
    int i, j; 
    int key; 

    j = N-1; 
    while(j < N) 
    {
        key = p_array[j]; 

        i = j - 1; 
        while(i > -1 && p_array[i] > key) 
        {
            p_array[i + 1] = p_array[i]; 
            i = i - 1; 
        } 
        p_array[i+1] = key; 

        j = j + 1; 
    } 
} 

// 2 
void sort(int* p_array, int N) 
{
    int i, j; 
    int key; 

    j = 1; 
    while(j < N) 
    {
        key = p_array[j]; 

        i = j - 1; 
        while(i > -1 && p_array[i] > key) 
        {
            p_array[i+1] = p_array[i]; 
            i = i - 1; 
        } 
        p_array[i+1] = key; 

        j = j + 1; 
    } 
} 

//3 
void sort(int* p_array, int N) 
{
    int i, j; 
    int key; 

    j = 1; 
    while(j < N)
    {
        key = p_array[j]; 

        i = j - 1; 
        while(i > -1 && p_array[i] > key) 
        {
            p_array[i+1] = p_array[i]; 
            i = i - 1; 
        } 
        p_array[i+1] = key; 

        j = j + 1; 
    } 
} 

// 4 
void sort(int* p_array, int N) 
{
    int i, j; 
    int key; 

    j = 1; 
    while(j < N) 
    {
        key = p_array[j]; 

        i = j - 1; 
        while(i > -1 && p_array[i] > key) 
        {
            p_array[i+1] = p_array[i]; 
            i = i - 1; 
        } 
        p_array[i+1] = key; 

        j = j + 1; 
    } 
} 

// 5 
void sort(int* p_array, int N) 
{
    int i, j; 
    int key; 

    j = 1; 
    while(j < N) 
    {
        key = p_array[j]; 

        i = j - 1; 
        while(i > -1 && p_array[i] > key) 
        {
            p_array[i+1] = p_array[i]; 
            i = i - 1; 
        } 
        p_array[i+1] = key; 

        j = j + 1; 
    } 
} 


