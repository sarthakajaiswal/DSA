#include <stdio.h> 
#include <stdlib.h> 

struct node 
{
    int data; 
    struct node* prev; 
    struct node* next; 
}; 

void experiment_1(void); 

int main(void) 
{
    experiment_1(); 
    return (0); 
} 

void experiment_1(void) 
{
    struct node* p_node = NULL; 

    p_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_node) 
    {
        fprintf(stderr, "malloc():fatal:out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    p_node->data = 100; 
    p_node->prev = NULL; 
    p_node->next = NULL; 

    printf("Address in p_node: p_node = %zu\n", (unsigned long long)p_node); 
    printf("Address of member named data: %zu p_node->data = %zu\n", (unsigned long long)(&p_node->data)); 
    printf("Address of member named prev: %zu p_node->prev = %zu\n", (unsigned long long)(&p_node->prev)); 
    printf("Address of member named next: %zu p_node->next = %zu\n", (unsigned long long)(&p_node->next)); 

    // release free node 
    free(p_node); 
    p_node = NULL; 
} 

// 2
#include <stdio.h> 
#include <stdlib.h> 

struct node 
{
    int data; 
    struct node* prev; 
    struct node* next; 
}; 

void experiment_1(void); 

int main(void) 
{
    experiment_1(); 
    return (0); 
} 

void experiment_1(void) 
{
    struct node* p_node = NULL; 

    p_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_node) 
    {
        fprintf(stderr, "malloc():fatal:out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    p_node->data = 0; 
    p_node->prev = 0; 
    p_node->next = 0; 

    printf("Address in p_node: p_node = %zu\n", (unsigned long long)p_node); 
    printf("Address of member named data: %zu p_node->data = %zu\n", (unsigned long long)(&p_node->data), p_node->data); 
    printf("Address of member named prev: %zu p_node->prev = %zu\n", (unsigned long long)(&p_node->prev), p_node->prev); 
    printf("Address of member named next: %zu p_node->next = %zu\n", (unsigned long long)(&p_node->next), p_node->next); 

    // release p_node 
    free(p_node); 
    p_node = NULL; 
} 

// 3 
#include <stdio.h> 
#include <stdlib.h> 

struct node 
{
    int data; 
    struct node* prev; 
    struct node* next; 
}; 

void experiment_1(void); 

int main(void) 
{
    experiment_1(); 
    return (0); 
}

void experiment_1(void) 
{
    struct node* p_node = NULL; 

    p_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_node) 
    {
        fprintf(stderr, "malloc():fatal:out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    p_node->data = 0; 
    p_node->prev = NULL; 
    p_node->next = NULL; 

    printf("Address in p_node: p_node = %zu\n", (unsigned long long)p_node); 
    printf("Address of member named data: %zu p_node->data = %zu\n", (unsigned long long)(&p_node->data), p_node->data); 
    printf("Address of member named prev: %zu p_node->prev = %zu\n", (unsigned long long)(&p_node->prev), p_node->prev); 
    printf("Address of member named next: %zu p_node->next = %zu\n", (unsigned long long)(&p_node->next), p_node->next); 

    // release p_node 
    free(p_node); 
    p_node = NULL; 
} 

// 4 
#include <stdio.h> 
#include <stdlib.h> 

struct node 
{
    int data; 
    struct node* prev; 
    struct node* next; 
}; 

void experiment_1(void); 

int main(void) 
{
    experiment_1(); 
    return (0); 
} 

void experiment_1(void) 
{
    struct node* p_node = NULL; 

    p_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_node) 
    {
        fprintf(stderr, "malloc():fatal out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    p_node->data = 0; 
    p_node->prev = NULL; 
    p_node->next = NULL; 

    printf("Address in p_node: p_node = %zu\n", (unsigned long long)p_node); 
    printf("Address of member named data: %zu p_node->data = %zu\n", (unsigned long long)(&p_node->data), p_node->data); 
    printf("Address of member named prev: %zu p_node->prev = %zu\n", (unsigned long long)(&p_node->prev), p_node->prev); 
    printf("Address of member named next: %zu p_node->next = %zu\n", (unsigned long long)(&p_node->next), p_node->next); 

    // release pnode 
    free(p_node); 
    p_node = NULL; 
} 

// 5 
#include <stdio.h> 
#include <stdlib.h> 

struct node 
{
    int data; 
    struct node* prev; 
    struct node* next; 
}; 

void experiment_1(void); 

int main(void) 
{
    experiment_1(); 
    return (0); 
} 

void experiment_1(void) 
{
    struct node* p_node = NULL; 

    p_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_node) 
    {
        fprintf(stderr, "malloc():fatal: out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    p_node->data = 0; 
    p_node->prev = NULL; 
    p_node->next = NULL; 

    printf("Address in p_node: p_node = %zu\n", (unsigned long long)(&p_node->data)); 
    printf("Address of member named data: %zu p_node->data = %zu\n", (unsigned long long)(&p_node->data), p_node->data); 
    printf("Address of member named prev: %zu p_node->prev = %zu\n", (unsigned long long)(&p_node->prev), p_node->prev); 
    printf("Address of member named next: %zu p_node->next = %zu\n", (unsigned long long)(&p_node->next), p_node->next); 

    // release p_node 
    free(p_node); 
    p_node = NULL; 
} 
