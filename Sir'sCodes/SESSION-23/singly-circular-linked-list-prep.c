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
        puts("malloc():failed"); 
        exit(EXIT_FAILURE); 
    }

    //  In cirular linked list, the next link of the head node should store 
    //  the base address of the head node if the list is empty 
    head_node->data = 0; 
    head_node->next = head_node;    //  Important for maintaining circularity property in boundary cases 

    //  First node with data 
    struct node* first_node = NULL; 
    first_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == first_node) 
    {
        puts("malloc():failed"); 
        exit(EXIT_FAILURE); 
    }
    first_node->data = 100; 
    first_node->next = head_node;   //  This maintains the circularity property 
    head_node->next = first_node; 
    
    //  Second node with data 
    struct node* second_node = NULL; 

    second_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == second_node)
    {
        puts("malloc():error"); 
        exit(EXIT_FAILURE); 
    }

    second_node->data = 200; 
    second_node->next = head_node; 
    first_node->next = second_node; 

    //  Third node with data 
    struct node* third_node = NULL; 

    third_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == third_node)
    {
        puts("malloc():error"); 
        exit(EXIT_FAILURE); 
    }
    third_node->data = 300; 
    third_node->next = head_node; 
    second_node->next = third_node; 

    //////////////////////////////////////////////////////////////
    //  Travel through all nodes with data 
    struct node* run = NULL; 

    puts("Travelling through all nodes with data"); 
    run = head_node->next; 
    while(run != head_node)
    {
        printf("run->data = %d\n", run->data); 
        run = run->next; 
    }
    puts("----Travelling through all nodes with data end----"); 
    //  Get the address of the last node with data 
    //  Empty linked list analysis of the code fragment below 
    //  Linked list empty -> head_node->next == head_node 
    //  run = head_node->next;  // that puts head_node in run 
    //  Therefore, run->next != head_node is FALSE at the first 
    //  evaluation and therefore the loop does not run at all 
    run = head_node->next; 
    while(run->next != head_node) 
    {
        run = run->next; 
    }
    //  Currently, the linked list is non-empty. 
    //  Therefore, run points to the last node with data.(which is 300)
    printf("run->data = %d\n", run->data); //   300 

    //  Last node and second to last node 
    struct node* run_previous = NULL; 

    run_previous = head_node; 
    run = head_node->next; 
    while(run != head_node)
    {
        run_previous = run; 
        run = run->next; 
    }

    //  In case of empty linked list: both run and run_previous == head_ndoe 
    //  In case of non-empty linked list: run == last node with data, run_previous -> predecessor node 
    
    //  Find the node and its predecessor node given the data
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
        puts("Search data not found"); 

    printf("run->data = %d, search_data = %d\n", run->data, search_data); 

    //  Destroy linked list 
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