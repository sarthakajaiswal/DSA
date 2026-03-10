#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

struct node 
{
    int data; 
    struct node* prev; 
    struct node* next; 
}; 

void experiment(void); 

int main(void) 
{
    experiment(); 
    return (EXIT_SUCCESS); 
} 

void experiment(void) 
{
    struct node* head_node = NULL; // pointer to dummy node of linked list 

    head_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == head_node) 
    {
        puts("malloc(): fatal: out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    printf("address in head node = %lld\n", (unsigned long long)head_node); 

    head_node->prev = head_node; 
    head_node->next = head_node; 

    // first node with data 
    struct node* first_node = NULL; 
    first_node = (struct node*)malloc(sizeof(struct node)); 
    if(first_node == NULL) 
    {
        puts("malloc():fatal: out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    printf("address in first node = %zu\n", (unsigned long long)first_node); 

    first_node->data = 100; 
    head_node->next = first_node; 
    head_node->prev = first_node; 
    first_node->next = head_node; 
    first_node->prev = head_node; 

    // second node with data 
    struct node* second_node = NULL; 
    second_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == second_node) 
    {
        puts("malloc():fatal:out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    printf("address in second_node: %zu\n", (unsigned long long)second_node); 

    second_node->data = 200; 
    second_node->prev = first_node; 
    second_node->next = head_node; 
    first_node->next = second_node; 
    head_node->prev = second_node; 

    // third node with data 
    struct node* third_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == third_node) 
    {
        puts("malloc():fatal: out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    printf("address in third_node = %zu\n", (unsigned long long)third_node); 

    third_node->data = 300; 
    third_node->prev = second_node; 
    third_node->next = head_node; 
    second_node->next = third_node; 
    head_node->prev = third_node; 

    // traversal 
    struct node* run = NULL; 

    run = head_node->next; 
    while(run != head_node) 
    {
        printf("run->data = %d\n", run->data); 
        run = run->next; 
    } 

    // destroy linked list 
    struct node* run_next = NULL; 

    run = head_node->next; 
    while(run != head_node) 
    {
        run_next = run->next; 
        printf("freeing node at address: %zu and content: %d\n", (unsigned long long)run, run->data); 
        free(run); 
        run = run_next; 
    } 

    printf("Freeing head node: address: %zu\n", (unsigned long long)head_node); 
    free(head_node); 
    head_node = NULL; 

    puts("List succesfully destroyed\n"); 
} 

// 2 
#include <stdio.h>
#include <stdlib.h> 
#include <assert.h> 

struct node 
{
    int data; 
    struct node* prev; 
    struct node* next; 
}; 

void experiment(void); 

int main(void) 
{
    experiment(); 
    return (0); 
} 

void experiment(void) 
{
    struct node* p_head_node = NULL; // pointer to dummy node of list 

    p_head_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_head_node) 
    {
        puts("malloc():fatal:out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    printf("Address in head_node = %zu\n", (unsigned long long)p_head_node); 
    p_head_node->data = -1; 
    p_head_node->prev = p_head_node; 
    p_head_node->next = p_head_node; 

    struct node* p_first_node = NULL; 
    p_first_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_first_node) 
    {
        puts("malloc():fatal: out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    printf("address in p_first_node = %zu\n", (unsigned long long)p_first_node); 

    p_first_node->data = 100; 
    p_first_node->prev = p_head_node; 
    p_first_node->next = p_head_node; 
    p_head_node->next = p_first_node; 
    p_head_node->prev = p_first_node; 

    struct node* p_second_node = NULL; 
    p_second_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_second_node) 
    {
        puts("malloc():fatal: out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    printf("address is p_second_node = %zu\n", (unsigned long long)p_second_node); 

    p_second_node->data = 200; 
    p_second_node->prev = p_first_node; 
    p_second_node->next = p_head_node; 
    p_first_node->next = p_second_node; 
    p_head_node->prev = p_second_node; 

    struct node* p_third_node = NULL; 
    p_third_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_third_node) 
    {
        puts("malloc():fatal: out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    printf("address in p_third_node = %zu\n", (unsigned long long)p_third_node); 

    p_third_node->data = 300; 
    p_third_node->prev = p_second_node; 
    p_third_node->next = p_head_node; 
    p_second_node->next = p_third_node; 
    p_head_node->prev = p_third_node; 

    // traversal 
    // travel through all nodes with data 
    struct node* p_run = NULL; 

    p_run = p_head_node->next; 
    while(p_run != p_head_node) 
    {
        printf("run->data = %d\n", p_run->data); 
        p_run = p_run->next; 
    } 

    // destroying list 
    struct node* p_run_next = NULL; 
    p_run = p_head_node->next; 
    while(p_run != p_head_node) 
    {
        p_run_next = p_run->next; 
        printf("freeing address at %zu\n", (unsigned long long)p_run); 
        free(p_run); 
        p_run = p_run_next; 
    } 

    printf("freeing head_node at %zu\n", (unsigned long long)p_head_node); 
    free(p_head_node); 
    p_head_node = NULL; 

    puts("List successfully destroyed"); 
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

void experiment(void); 

int main(void) 
{
    experiment(); 
    return (0); 
} 

void experiment(void) 
{
    struct node* p_head_node = NULL; // pointer to dummy node of double linked list 

    p_head_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_head_node) 
    {
        puts("malloc():fatal:out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    printf("address in p_head_node = %zu\n", (unsigned long long)p_head_node); 

    p_head_node->prev = p_head_node; 
    p_head_node->next = p_head_node; 

    // pointer to first node with data 
    struct node* p_first_node = NULL; 
    p_first_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_first_node) 
    {
        puts("malloc():fatal:out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    printf("address in p_first_node = %zu\n", (unsigned long long)p_first_node); 

    p_first_node->data = 100; 
    p_first_node->prev = p_head_node; 
    p_first_node->next = p_head_node; 
    p_head_node->next = p_first_node; 
    p_head_node->prev = p_first_node; 

    // pointer to second node with data 
    struct node* p_second_node = NULL; 
    p_second_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_second_node) 
    {
        puts("malloc():fatal:out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    printf("address in p_second_node = %zu\n", (unsigned long long)p_second_node); 

    p_second_node->data = 200; 
    p_second_node->prev = p_first_node; 
    p_second_node->next = p_head_node; 
    p_first_node->next = p_second_node; 
    p_head_node->prev = p_second_node; 

    // pointer to third node with data 
    struct node* p_third_node = NULL; 
    p_third_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_third_node) 
    {
        puts("malloc():fatal:out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    printf("address in p_third_node = %zu\n", (unsigned long long)p_third_node); 
    p_third_node->data = 300; 
    p_third_node->prev = p_second_node; 
    p_third_node->next = p_head_node; 
    p_second_node->next = p_third_node; 
    p_head_node->prev = p_third_node; 

    // traversal 
    struct node* p_run = NULL; 

    p_run = p_head_node->next; 
    while(p_run != p_head_node) 
    {
        printf("p_run->data = %d\n", p_run->data); 
        p_run = p_run->next; 
    } 

    // destruction 
    struct node* p_run_next = NULL; 
    p_run = p_head_node->next; 
    while(p_run != p_head_node) 
    {
        p_run_next = p_run->next; 
        printf("freeing address %zu\n", (unsigned long long)p_run); 
        free(p_run); 
        p_run = p_run_next; 
    } 
    p_first_node = NULL; 
    p_second_node = NULL; 
    p_third_node = NULL; 

    printf("freeing address %zu\n", (unsigned long long)p_head_node); 
    free(p_head_node); 
    p_head_node = NULL; 

    puts("List destroyed successfully\n"); 
} 

// 4 
#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

struct node 
{
    int data; 
    struct node* prev; 
    struct node* next; 
}; 

void experiment(void); 

int main(void) 
{
    experiment(); 
    return (0); 
} 

void experiment(void) 
{
    struct node* p_head_node = NULL; // pointer to dummy node of doubly circular linked list 

    p_head_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_head_node) 
    {
        puts("malloc():fatal: out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    printf("adress in p_head_node = %p\n", p_head_node); 

    p_head_node->next = p_head_node; 
    p_head_node->prev = p_head_node; 

    // pointer to first node with data 
    struct node* p_first_node = NULL; 
    p_first_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_first_node) 
    {
        puts("malloc():fatal: out of memory\n");
        exit(EXIT_FAILURE); 
    } 
    printf("address in p_first_node = %p\n", p_first_node); 

    p_first_node->data = 100; 
    p_first_node->next = p_head_node; 
    p_first_node->prev = p_head_node; 
    p_head_node->next = p_first_node; 
    p_head_node->prev = p_first_node; 

    // pointer to second node with data 
    struct node* p_second_node = NULL; 
    p_second_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_second_node) 
    {
        puts("malloc():fatal: out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    printf("address in p_second_node = %p\n", p_second_node); 

    p_second_node->data = 200; 
    p_second_node->prev = p_first_node; 
    p_second_node->next = p_head_node; 
    p_first_node->next = p_second_node; 
    p_head_node->prev = p_second_node; 

    // pointer to third node with data 
    struct node* p_third_node = NULL; 
    p_third_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_third_node) 
    {
        puts("malloc():fatal: out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    printf("address in p_third_node = %p\n", p_third_node); 

    p_third_node->data = 300; 
    p_third_node->prev = p_second_node; 
    p_third_node->next = p_head_node; 
    p_second_node->next = p_third_node; 
    p_head_node->prev = p_third_node; 

    // traversal 
    struct node* p_run = NULL; 
    p_run = p_head_node->prev; 
    while(p_run != p_head_node) 
    {
        printf("p_run->data = %d\n", p_run->data); 
        p_run = p_run->prev; 
    } 

    // destruction 
    struct node* p_run_next = NULL; 
    p_run = p_head_node->next; 
    while(p_run != p_head_node) 
    {
        p_run_next = p_run->next; 
        printf("freeing address %p\n", p_run); 
        free(p_run); 
        p_run = p_run_next; 
    } 
    p_first_node = NULL; 
    p_second_node = NULL; 
    p_third_node = NULL; 

    printf("freeing address %p\n", p_head_node); 
    free(p_head_node); 
    p_head_node = NULL; 

    puts("List destroyed successfully\n"); 
} 

// 5 
#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

struct node 
{
    int data; 
    struct node* prev; 
    struct node* next; 
}; 

void experiment(void); 

int main(void) 
{
    experiment(); 
    return (0); 
} 

void experiment(void) 
{
    struct node* p_head_node = NULL; // pointer to dummy node of doubly circcular linked list 
    p_head_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_head_node) 
    {
        puts("malloc():fatal: out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    printf("address in p_head_node = %zu\n", (unsigned long long)p_head_node); 
    p_head_node->prev = p_head_node; 
    p_head_node->next = p_head_node; 

    struct node* p_first_node = NULL; // pointer to first node with data 
    p_first_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_first_node) 
    {
        puts("malloc():fatal:out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    printf("address in p_first_node = %zu\n", (unsigned long long)p_first_node); 
    p_first_node->data = 100; 
    p_first_node->prev = p_head_node; 
    p_first_node->next = p_head_node; 
    p_head_node->next = p_first_node; 
    p_head_node->prev = p_first_node; 

    struct node* p_second_node = NULL; // pointer to second node with data 
    p_second_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_second_node) 
    {
        puts("malloc():fatal:out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    printf("adress in p_second_node = %zu\n", (unsigned long long)p_second_node); 

    p_second_node->data = 200; 
    p_second_node->prev = p_first_node; 
    p_second_node->next = p_head_node; 
    p_first_node->next = p_second_node; 
    p_head_node->prev=  p_second_node; 

    struct node* p_third_node = NULL; // pointer to third node with data 
    p_third_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_third_node) 
    {
        puts("malloc():fatal: out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    printf("address in p_third_node = %zu\n", (unsigned long long)p_third_node); 
    p_third_node->data = 300; 
    p_third_node->next = p_head_node; 
    p_third_node->prev = p_second_node; 
    p_second_node->next = p_third_node; 
    p_head_node->prev = p_third_node; 

    // traversal 
    struct node* p_run = NULL; 

    p_run = p_head_node->next; 
    while(p_run != p_head_node) 
    {
        printf("p_run->data = %d\n", p_run->data); 
        p_run = p_run->next; 
    } 

    // destroying list 
    struct node* p_run_next = NULL; 
    p_run = p_head_node->next; 
    while(p_run != p_head_node) 
    {
        p_run_next = p_run->next; 
        printf("freeing address %zu\n", (unsigned long long)p_run); 
        free(p_run); 
        p_run = p_run_next; 
    } 
    p_first_node = NULL; 
    p_second_node = NULL; 
    p_third_node = NULL; 

    printf("freeing address %zu\n", (unsigned long long)p_head_node); 
    free(p_head_node); 
    p_head_node = NULL; 

    puts("List destroyed successfully"); 
} 

