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
        puts("out of memory"); 
        exit(EXIT_FAILURE); 
    }

    struct node* second_node = NULL; 

    second_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == second_node)
    {
        puts("out of memory"); 
        exit(EXIT_FAILURE); 
    }

    first_node->data = 100; 
    first_node->prev = NULL; 
    first_node->next = second_node; 

    second_node->data = 200; 
    second_node->prev = first_node; 
    second_node->next = NULL; 

    printf("Address in first_node:%zu\n", (addr_t)first_node); 
    printf("Address in first_node->prev:%zu\n", (addr_t)first_node->prev); 
    printf("Address in first_node->next:%zu\n", (addr_t)first_node->next); 

    printf("Address in second_node:%zu\n", (addr_t)second_node); 
    printf("Address in second_node->prev:%zu\n", (addr_t)second_node->prev); 
    printf("Address in second_node->next:%zu\n", (addr_t)second_node->next); 

    puts("OBSERVE:address in first_node->next == address in second_node"); 
    puts("OBSERVE:address in second_node->prev == address in first_node");

    free(first_node); 
    first_node = NULL; 

    free(second_node); 
    second_node = NULL; 
}

void experiment_2(void)
{
    struct node* first_node = NULL; 
    struct node* second_node =  NULL; 
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

    //  Link first node with the second 
    first_node->prev = NULL; 
    first_node->next = second_node; 
    second_node->prev = first_node; 

    //  Link the second node with the third 
    second_node->next = third_node; 
    third_node->prev = second_node; 

    //  Link the third node with the fourth 
    third_node->next = fourth_node; 
    fourth_node->prev = third_node; 
    fourth_node->next = NULL; 

    /* Write a code to traverse through the linked nodes in the forward direction */
    struct node* run = NULL; 
    run = first_node; 
    while(run != NULL)
    {
        printf("run->data = %d\n", run->data); 
        run = run->next; 
    }

    /* Write a code to traverfse through the linked nodes in the backward direction */
    run = fourth_node; 
    while(run != NULL)
    {
        printf("run->data = %d\n", run->data); 
        run = run->prev; 
    }

    /* Delete all nodes while traversing in the backward direction */
    struct node* run_previous = NULL; 
    run = fourth_node; 
    while(run != NULL)
    {
        printf("Deleting node with data = %d\n", run->data); 
        run_previous = run->prev; 
        free(run); 
        run = run_previous; 
    }

    run_previous = first_node = second_node = third_node = fourth_node = NULL; 
}