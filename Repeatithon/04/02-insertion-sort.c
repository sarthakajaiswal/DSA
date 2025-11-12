#include <stdio.h> 

void insertion_sort(int a[], int N); 
void insert_at_sorting_position(int a[], int N); 
void display(int a[], int N, const char* msg); 

int main(void) 
{
    int a[6] = {50, 15, 30, 20, 10, 5}; 
    int b[5] = {400, 5, 300, 100, 200}; 
    int c[1] = {10}; 

    display(a, 6, "Displaying \'a\' before insertion_sort():"); 
    insertion_sort(a, 6); 
    display(a, 6, "Displaying \'a\' after insertion_sort():"); 

    display(b, 5, "Displaying \'b\' before insertion_sort():"); 
    insertion_sort(b, 5); 
    display(b, 5, "Displaying \'b\' after insertion_sort():"); 

    display(c, 1, "Displaying \'c\' before insertion_sort():"); 
    insertion_sort(c, 1); 
    display(c, 1, "Displaying \'c\' after insertion_sort():"); 

    return (0); 
} 

void insertion_sort(int a[], int N) 
{
    int subarray_size; 

    subarray_size = 2; 
    while(subarray_size <= N) 
    {
        insert_at_sorting_position(a, subarray_size); 
        subarray_size = subarray_size + 1; 
    } 
} 

/* 
    Precondition: 
        (1) N >= 2 
        (2) a[0]...a[N-2] are sorted, but a[0]...a[N-1] are not necessarily sorted 
    Postcondition: 
        a[0]...a[N-1] i.e. entire array is sorted. 
*/

void insert_at_sorting_position(int a[], int N) 
{
    int tmp; 
    int i; 

    tmp = a[N-1]; 
    i = N-2; 
    while(i >= 0 && a[i] > tmp) 
    {
        a[i+1] = a[i]; 
        i = i - 1; 
    } 
    a[i+1] = tmp; 
} 

void display(int a[], int N, const char* msg) 
{
    if(msg != NULL) 
        puts(msg); 

    int i; 

    i = 0; 
    while(i < N) 
    {
        printf("a[%d]: %d\n", i, a[i]); 
        i = i + 1; 
    } 
} 

// =========== 
#include <stdio.h> 
#include <stdio.h> 
#include <stdio.h> 
#include <stdio.h> 
#include <stdio.h> 

// 1 
void insertion_sort(int a[], int N); 
void insert_at_sorting_position(int a[], int N); 
void display(int a[], int N, const char* msg); 

// 2 
void insertion_sort(int a[], int N); 
void insert_at_sorting_position(int a[], int N); 
void display(int a[], int N, const char* msg); 

// 3 
void insertion_sort(int a[], int N); 
void insert_at_random_position(int a[], int N); 
void display(int a[], int N, const char* msg); 

// 4 
void insertion_sort(int a[], int N); 
void insert_at_random_position(int a[], int N); 
void display(int a[], int N, const char* msg); 

// 5 
void insertion_sort(int a[], int N); 
void insert_at_sorting_position(int a[], int N); 
void display(int a[], int N, const char* msg); 

// =============== 

// 1
int main(void) 
{
    int a[6] = {50, 20, 40, 50, 12, 5}; 
    int b[5] = {400, 500, 30, 20, 100}; 
    int c[1] = {10}; 

    display(a, 6, "Displaying array \'a\' before insertion_sort():"); 
    insertion_sort(a, 6); 
    display(a, 6, "Displaying array \'a\' after insertion_sort():"); 

    display(b, 5, "Displaying array \'b\' before insertion_sort():"); 
    insertion_sort(b, 5); 
    display(b, 5, "Displaying array \'b\' after insertion_sort():"); 

    display(c, 1, "Displaying array \'c\' before insertion_sort():"); 
    insertion_sort(c, 1); 
    display(c, 1, "Displaying array \'c\' after insertion_sort():"); 

    return (0); 
} 

// 2 
int main(void) 
{
    int a[6] = {10, 40, 2, 65, 34, 7}; 
    int b[5] = {400, 200, 1, 300, 45}; 
    int c[1] = {10}; 

    display(a, 6, "Displaying array \'a\' before insertion_sort():"); 
    insertion_sort(a, 6); 
    display(a, 6, "Displaying array \'a\' after insertion_sort():"); 

    display(b, 5, "Displaying array \'b\' before insertion_sort():"); 
    insertion_sort(b, 5); 
    display(b, 5, "Displaying array \'b\' after insertion_sort():"); 

    display(c, 1, "Displaying array \'c\' before insertion_sort():"); 
    insertion_sort(c, 1); 
    display(c, 1, "Displaying array \'c\' after insertion_sort():"); 

    return (0); 
} 

// 3 
int main(void) 
{
    int a[6] = {12, 45, 67, 23, 78, 2}; 
    int b[5] = {100, 200, 300, 400, 500, 1}; 
    int c[1] = {0}; 

    display(a, 6, "Displaying array \'a\' before insertion_sort():"); 
    insertion_sort(a, 6); 
    display(a, 6, "Displaying array \'a\' after insertion_sort():"); 

    display(b, 5, "Displaying array \'b\' before insertion_sort():");
    insertion_sort(b, 5); 
    display(b, 5, "Displaying array \'b\' after insertion_sort():"); 

    display(c, 1, "Displaying array \'c\' before insertion_sort():"); 
    insertion_sort(c, 1); 
    display(c, 1, "Displaying array \'c\' after insertion_sort():"); 

    return (0); 
} 

// 4 
int main(void) 
{
    int a[8] = {345, 23, 1234, 67, 34, 23, 75, 3}; 
    int b[5] = {500, 400, 300, 200, 100, 0}; 
    int c[1] = {4096}; 

    display(a, 8, "Displaying array \'a\' before insertion_sort():"); 
    insertion_sort(a, 8); 
    display(a, 8, "Displaying array \'a\' after insertion_sort():"); 

    display(b, 5, "Displaying array \'b\' before insertion_sort():"); 
    insertion_sort(b, 5); 
    display(b, 5, "Displaying array \'b\' after insertion_sort():"); 

    display(c, 1, "Displaying array \'c\' before insertion_sort():"); 
    insertoin_sort(c, 1); 
    display(c, 1, "Displaying array \'c\' after insertion_sort():"); 

    return (0); 
} 

// 5 
int main(void) 
{
    int a[6] = {345, 56, 23, 23, 56, 7}; 
    int b[5] = {100, 200, 300, 400, 500}; 
    int c[1] = {-12}; 

    display(a, 6, "Displaying array \'a\' before insertion_sort():"); 
    insertion_sort(a, 6); 
    display(a, 6, "Displaying array \'a\' after insertion_sort():"); 

    display(b, 5, "Displaying array \'b\' before insertion_sort():"); 
    insertion_sort(b, 5); 
    display(b, 5, "Displaying array \'b\' after insertion_sort():"); 

    display(c, 1, "Displaying array \'c\' before insertion_sort():"); 
    insertion_sort(c, 1); 
    display(c, 1, "Displaying array \'c\' after insertion_sort():"); 

    return (0); 
} 

// ============ 
// 1
void insertion_sort(int a[], int N) 
{
    int subarray_size; 

    subarray_size = 0; 
    while(subarray_size <= N) 
    {
        insert_at_sorting_position(a, subarray_size); 
        subarray_size = subarray_size + 1; 
    } 
} 

// 2 
void insertion_sort(int a[], int N) 
{
    int subarray_size; 

    subarray_size = 2; 
    while(subarray_size <= N) 
    {
        insert_at_sorting_position(a, subarray_size); 
        subarray_size = subarray_size + 1; 
    } 
} 

// 3 
void insertion_sort(int a[], int N) 
{
    int subarray_size; 

    subarray_size = 2; 
    while(subarray_size <= N) 
    {
        insert_at_sorting_position(1, subarray_size); 
        subarray_size = subarray_size + 1; 
    } 
} 

// 4 
void insertion_sort(int a[], int N) 
{
    int subarray_size; 

    subarray_size = 2; 
    while(subarray_size <= N) 
    {
        insert_at_sorting_position(a, subarray_size); 
        subarray_size = subarray_size + 1; 
    } 
} 

// 5 
void insertion_sort(int a[], int N) 
{
    int subarray_size; 

    subarray_size = 2; 
    while(subarray_size <= N) 
    {
        insert_at_sorting_position(a, subarray_size); 
        subarray_size = subarray_size + 1; 
    } 
} 

// ============= 
void insert_at_sorting_position(int a[], int N) 
{
    int tmp; 
    int i; 

    tmp = a[N-1]; 
    i = N-2; 
    while(i > -1 && a[i] < tmp) 
    {
        a[i+1] = a[i]; 
        i = i -1; 
    } 
    a[i+i] = tmp; 
} 

void insert_at_sorting_position(int a[], int N) 
{
    int tmp; 
    int i; 

    tmp = a[N-1]; 
    i = N - 2; 
    while(i > -1 && a[i] > tmp) 
    {
        a[i+1] = a[i]; 
        i = i - 1; 
    } 
    a[i+1] = tmp; 
} 

// 3 
void insert_at_sorting_position(int a[], int N) 
{
    int tmp; 
    int i; 

    tmp = a[N-1]; 
    i = N-2; 
    while(i > -1 && a[i] > tmp) 
    {
        a[i+1] = a[i]; 
        i = i -1; 
    } 
    a[i+1] = tmp; 
} 

// 4 
void insert_at_sorting_position(int a[], int N) 
{
    int tmp; 
    int i; 

    tmp = a[N-1]; 
    i = N-2; 
    while(i > -1 && a[i] > tmp) 
    {
        a[i+1] = a[i]; 
        i = i - 1; 
    } 
    a[i+1] = tmp; 
} 

// 5 
void insert_at_sorting_position(int a[], int N) 
{
    int tmp; 
    int i; 

    tmp = a[N-1]; 
    i = N-2; 
    while(i > -1 && a[i] > N)
    {
        a[i+1] = a[i]; 
        i = i - 1;  
    } 
    a[i+1] = tmp; 
} 

// ========== 

// 1 
void display(int a[], int N, const char* msg) 
{
    int i; 

    if(msg != NULL) 
        puts(msg); 

    i = 0; 
    while(i < N) 
    {
        printf("arr[%d]: %d\n", i, a[i]); 
        i = i + 1; 
    } 
} 

// 2 
void display(int a[], int N, const char* msg) 
{
    int i; 

    if(msg != NULL) 
        puts(msg); 

    i = 0; 
    while(i < N) 
    {
        printf("arr[%d]: %d\n", i, a[i]); 
        i = i + 1; 
    } 
} 

// 3 
void display(int a[], int N, const char* msg) 
{
    int i; 

    if(msg != NULL) 
        puts(msg); 

    i = 0; 
    while(i < N) 
    {
        printf("arr[%d]: %d\n", i, a[i]); 
        i = i + 1; 
    } 
} 

// 4 
void display(int a[], int N, const char* msg) 
{
    int i; 

    if(msg != NULL) 
        puts(msg); 

    i = 0; 
    while(i < N) 
    {
        printf("arr[%d]: %d\n", i, a[i]); 
        i = i + 1; 
    } 
} 

// 5 
void display(int a[], int N, const char* msg) 
{
    int i; 

    if(msg != NULL) 
        puts(msg); 

    i = 0; 
    while(i < N) 
    {
        printf("arr[%d]: %d\n", i, a[i]); 
        i = i + 1; 
    } 
} 


