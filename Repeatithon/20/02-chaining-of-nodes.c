#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

typedef unsigned long long int addr_t; 

struct node 
{
    int data; 
    struct node* prev; 
    struct node* next; 
}; 

void experiment_1(void); 
void experiment_2(void); 

int main(void) 
{
    experiment_1(); 
    experiment_2(); 
    return (0); 
} 

void experiment_1(void) 
{
    struct node* first_node = NULL; 

    first_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == first_node) 
    {
        fprintf(stderr, "malloc():fatal:out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    struct node* second_node = NULL; 

    second_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == second_node) 
    {
        fprintf(stderr, "malloc():fatal:out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    first_node->data = 100; 
    first_node->prev = NULL; 
    first_node->next = second_node; 

    second_node->data = 200; 
    second_node->prev = first_node; 
    second_node->next = NULL; 

    printf("Address in first_node: %zu\n", (addr_t)first_node); 
    printf("Address in first node->prev: %zu\n", (addr_t)(first_node->prev)); 
    printf("Address in first_node->next = %zu\n", (addr_t)(first_node->next)); 

    printf("Address in second node: %zu\n", (addr_t)second_node); 
    printf("Address in second_node->prev = %zu\n", (addr_t)second_node->prev); 
    printf("Address in second_node->next = %zu\n", (addr_t)second_node->next); 

    puts("OBSERVE: address in first_node->next == address of second_node"); 
    puts("OBSERVE address in second_node->prev == address of first_node"); 

    free(first_node); 
    first_node = NULL; 

    free(second_node); 
    second_node = NULL; 
} 

void experiment_2(void) 
{
    struct node* first_node = NULL; 
    struct node* second_node = NULL; 
    struct node* third_node = NULL; 
    struct node* fourth_node = NULL; 

    first_node = (struct node*)malloc(sizeof(struct node)); 
    assert(first_node != NULL); 

    second_node = (struct node*)malloc(sizeof(struct node)); 
    assert(second_node != NULL); 

    third_node = (struct node*)malloc(sizeof(struct node)); 
    assert(third_node != NULL); 

    fourth_node = (struct node*)malloc(sizeof(struct node)); 
    assert(fourth_node != NULL); 

    first_node->data = 100; 
    second_node->data = 200; 
    third_node->data = 300; 
    fourth_node->data = 400; 

    // link first node with second node 
    first_node->prev = NULL; 
    first_node->next = second_node; 
    second_node->prev = first_node; 
    
    // link second node with third node 
    second_node->next = third_node; 
    third_node->prev = second_node; 

    // link third node with fourth node 
    third_node->next = fourth_node; 
    fourth_node->prev = third_node; 
    fourth_node->next = NULL; 

    // write a code to traverse through all node 
    struct node* run = NULL; 
    run = first_node; 
    while(run != NULL) 
    {
        printf("run->data = %d\n", run->data); 
        run = run->next; 
    } 

    // write a code to transverse through list in backward direction 
    run = fourth_node; 
    while(run != NULL) 
    {
        printf("p_run->data = %d\n", run->data); 
        run = run->prev; 
    } 

    // delete all nodes while traversing through list 
    struct node* run_previous = NULL; 
    run = fourth_node; 
    while(run != NULL) 
    {
        printf("Deleting node with data: %d\n", run->data); 
        run_previous = run->prev; 
        free(run); 
        run = run_previous; 
    } 

    run_previous = first_node = second_node = third_node = fourth_node = 0; 
} 

// 2 
#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

// node layout definition 
struct node 
{
    int data; 
    struct node* prev; 
    struct node* next; 
};  

void experiment_1(void); 
void experiment_2(void); 

int main(void) 
{
    experiment_1(); 
    experiment_2(); 
    return (0); 
} 

void experiment_1(void) 
{
    struct node* first_node = NULL; 
    struct node* second_node = NULL; 

    first_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == first_node) 
    {
        fprintf(stderr, "malloc():fatal:out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    first_node->data = 0; 
    first_node->prev = NULL; 
    first_node->next = NULL; 

    second_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == second_node) 
    {
        fprintf(stderr, "malloc():fatal: out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    second_node->data = 0; 
    second_node->prev = first_node; 
    second_node->next = NULL; 

    printf("Address in first_node = %zu\n", first_node); 
    printf("Address in p_first_node->prev = %zu\n", (unsigned long long)(first_node->prev)); 
    printf("Address in p_first_node->next = %zu\n", (unsigned long long)(first_node->next)); 

    printf("Address of second_node = %zu\n", second_node); 
    printf("Address in second_node->prev = %zu\n", (unsigned long long)(second_node->prev)); 
    printf("Address in second_node->next = %zu\n", (unsigned long long)(second_node->next)); 

    free(first_node); 
    first_node = NULL; 
    free(second_node); 
    second_node = NULL; 
} 

void experiment_2(void)
{
    struct node* first_node = NULL; 
    struct node* second_node = NULL; 
    struct node* third_node = NULL; 
    struct node* fourth_node = NULL; 

    first_node = (struct node*)malloc(sizeof(struct node)); 
    assert(first_node != NULL); 

    second_node = (struct node*)malloc(sizeof(struct node)); 
    assert(second_node != NULL); 

    third_node = (struct node*)malloc(sizeof(struct node)); 
    assert(third_node != NULL); 

    fourth_node = (struct node*)malloc(sizeof(struct node)); 
    assert(fourth_node != NULL); 

    first_node->data = 100; 
    first_node->prev = NULL; 
    first_node->next = second_node; 

    second_node->data = 200; 
    second_node->prev = first_node; 
    second_node->next = third_node; 

    third_node->data = 300; 
    third_node->prev = second_node; 
    third_node->next = fourth_node; 

    fourth_node->data = 400; 
    fourth_node->prev = third_node; 
    fourth_node->next = NULL; 

    // traverse through all nodes in forward direction 
    struct node* run = NULL; 
    run = first_node; 
    while(run != NULL) 
    {
        printf("run->data = %d\n", run->data); 
        run = run->next; 
    } 

    // transverse through list in reverse direction 
    run = fourth_node; 
    while(run != NULL) 
    {
        printf("run->data = %d\n", run->data); 
        run = run->prev; 
    } 

    // delete all nodes while traversing in reverse direction 
    struct node* run_previous = NULL; 
    run = fourth_node; 
    while(run != NULL) 
    {
        printf("deleting node with data = %d\n", run->data); 
        run_previous = run->prev; 
        free(run); 
        run = run->prev; 
    } 

    run_previous = run = first_node = second_node = third_node = fourth_node = NULL; 
} 

// 3 
#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

struct node 
{
    int data; 
    struct node* prev;
    struct node* next; 
}; 

void experiment_1(void); 
void experiment_2(void); 

int main(void) 
{
    experiment_1(); 
    experiment_2(); 
    return (0); 
} 

void experiment_1(void) 
{
    struct node* first_node = NULL; 
    struct node* second_node = NULL; 

    first_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == first_node) 
    {
        fprintf(stderr, "malloc():fatal:out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    second_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == second_node) 
    {
        fprintf(stderr, "malloc():fatal:out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    first_node->data = 100; 
    first_node->next = second_node; 
    first_node->prev = NULL; 

    second_node->data = 200; 
    second_node->prev = first_node; 
    second_node->next = NULL;

    printf("address of first node = %zu\n", (unsigned long long)first_node); 
    printf("address in first_node->prev = %zu\n", (unsigned long long)(first_node->prev)); 
    printf("address in first_node->next = %zu\n", (unsigned long long)(first_node->next)); 

    printf("address of second_node = %zu\n", (unsigned long long)second_node); 
    printf("address in second_node->prev = %zu\n", (unsigned long long)(second_node->prev)); 
    printf("address in second_node->next = %zu\n", (unsigned long long)(second_node->next)); 

    assert(first_node == second_node->prev);
    assert(first_node->next == second_node); 

    free(first_node); 
    first_node = NULL; 
    free(second_node); 
    second_node = NULL; 
} 

void experiment_2(void) 
{
    struct node* first_node = NULL; 
    struct node* second_node = NULL; 
    struct node* third_node = NULL; 
    struct node* fourth_node = NULL; 

    first_node = (struct node*)malloc(sizeof(struct node)); 
    assert(NULL != first_node); 

    second_node = (struct node*)malloc(sizeof(struct node)); 
    assert(NULL != second_node); 

    third_node = (struct node*)malloc(sizeof(third_node)); 
    assert(NULL != third_node); 

    fourth_node = (struct node*)malloc(sizeof(fourth_node)); 
    assert(NULL != fourth_node); 

    first_node->data = 100; 
    first_node->prev = NULL; 
    first_node->next = second_node; 

    second_node->data = 200; 
    second_node->prev = first_node; 
    second_node->next = third_node; 

    third_node->data = 300; 
    third_node->prev = second_node; 
    third_node->next = fourth_node; 

    fourth_node->data = 400; 
    fourth_node->prev = third_node; 
    fourth_node->next = NULL; 

    // traverse through list in forward direction 
    struct node* run = NULL; 
    run = first_node; 
    while(run != NULL) 
    {
        printf("run->data = %d\n", run->data); 
        run = run->next; 
    } 

    // tranverse through list in reverse direction 
    run = fourth_node; 
    while(run != NULL) 
    {
        printf("run->data = %d\n", run->data); 
        run = run->prev; 
    }

    // delete all nodes while traversing in reverse direction 
    struct node* run_prev = NULL; 
    run = fourth_node; 
    while(run != NULL) 
    {
        printf("deleting node with data = %d\n", run->data); 
        run_prev = run->prev; 
        free(run); 
        run = run_prev; 
    } 

    run = run_prev = first_node = second_node = third_node = fourth_node = NULL; 
} 

