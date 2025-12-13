/*
    @GOAL: singly circular linked list preparation code 
    @DATE: 07 Dec 2025 
    @AUTHOR: Sarthak A. Jaiswal 
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

struct node 
{
    int data; 
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
    struct node* head_node = NULL; 

    head_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == head_node) 
    {
        puts("malloc(): failed"); 
        exit(EXIT_FAILURE); 
    }

    // In circular linked list, the next link of head node should store 
    // the base address of the head node if the listt is empty 
    head_node->data = 0; 
    head_node->next = head_node; // impoertant for maintaining circularity property in boudary cases 

    // First node with data 
    struct node* first_node = NULL; 
    first_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == first_node) 
    {
        puts("malloc(): failed\n"); 
        exit(EXIT_FAILURE); 
    } 
    first_node->data = 100; 
    first_node->next = head_node; 
    head_node->next = first_node; 

    // second node with data 
    struct node* second_node = NULL; 

    second_node = (struct node*)malloc(sizeof(struct node)); 
    if(second_node == NULL) 
    {
        puts("malloc(): failed\n"); 
        exit(EXIT_FAILURE); 
    } 
    second_node->data = 200; 
    second_node->next = NULL; 
    first_node->next = second_node; 

    // third node with data 
    struct node* third_node = NULL; 
    
    third_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == third_node) 
    {
        puts("malloc(): failed\n"); 
        exit(EXIT_FAILURE); 
    } 

    third_node->data = 300; 
    third_node->next = head_node; 
    second_node->next = third_node; 

    ///////////////////////////////////////////////////// 
    // Travel through all nodes with data 
    struct node* run = NULL; 

    puts("Travelling through all nodes with data"); 
    run = head_node->next; 
    while(run != head_node) 
    {
        printf("run->data = %d\n", run->data); 
        run = run->next; 
    }

    // Get the address of last node with data 
    // Empty linked list analysis of code fragment below 
    // linked list is empty -> head_node->next == head_node 
    // run = head_node->next; // that puts head_node in run 
    // Therefore, run->next != head_node is FALSE at the first evaluation 
    // and therefore loop does not run at all 
    run = head_node->next; 
    while(run->next != head_node) 
    {
        run = run->next; 
    } 
    // Currently, the linked list is non-empty 
    // Therefore, run points to last node with data (which is 300) 
    printf("run->data(last node) = %d\n", run->data); 

    // last node and second last node 
    struct node* run_previous = NULL; 

    run_previous = head_node; 
    run = head_node->next; 
    while(run != head_node) 
    {
        run_previous = run; 
        run = run->next; 
    } 

    // In case of empty linked list: both run and run_previous == head_node 
    // In case of non-empty linked list: run == last node with data and run_previous == predecessor node 
    int search_data = 200; 

    run_previous = head_node; 
    run = head_node->next; 
    while(run != head_node) 
    {
        if(run->data == search_data) 
            break; 
        run_previous = run; 
        run = run->next; 
    } 

    if(run == head_node) 
        puts("search data not found"); 
    
    printf("run->data == %d, search_data = %d\n", run->data, search_data); 

    // destroy linked list 
    struct node* run_next = NULL; 
    run = head_node->next; 
    while(run != head_node) 
    {
        run_next = run->next; 
        free(run); 
        run = run->next; 
    } 

    free(head_node); 
    head_node = NULL; 

    puts("Linked list destroyed successfully"); 
} 