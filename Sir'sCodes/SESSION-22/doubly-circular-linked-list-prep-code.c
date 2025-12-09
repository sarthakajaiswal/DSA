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
    struct node* head_node = NULL;  //  Pointer to dummy node of doubly linked list 

    head_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == head_node)
    {
        puts("malloc():fatal:memory allocation error"); 
        exit(EXIT_FAILURE); 
    }
    printf("Address in head_node = %zu\n", (unsigned long long)head_node); 

    //  Right now the linked list is empty. therefore, the last_node = head_node 
    //  as per the requirements of circular linked list 
    //  the prev pointer of head node should point to last node (= head_node if list is empty)
    //  the next pointer of last node (=head node if list is empty) should point to head_node 

    head_node->prev = head_node; 
    head_node->next = head_node; 

    //  First node with data 
    struct node* first_node = NULL; 
    first_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == first_node)
    {
        puts("malloc():fatal:memory allocation error"); 
        exit(EXIT_FAILURE); 
    }
    printf("Address in first_node = %zu\n", (unsigned long long)first_node); 

    first_node->data = 100; 
    head_node->next = first_node; 
    head_node->prev = first_node; 

    first_node->next = head_node; 
    first_node->prev = head_node; 

    //  Second node with data 
    struct node* second_node = NULL; 
    second_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == second_node)
    {
        puts("malloc():fatal:out of memory"); 
        exit(EXIT_FAILURE); 
    }
    printf("Address in second_node = %zu\n", (unsigned long long)second_node); 
    second_node->data = 200; 
    first_node->next = second_node; 
    second_node->prev = first_node; 
    second_node->next = head_node; 
    head_node->prev = second_node;
    
    //  Third node with data
    struct node* third_node = NULL; 
    third_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == third_node) 
    {
        puts("malloc():fatal:out of memory"); 
        exit(EXIT_FAILURE); 
    }
    printf("Address in third_node = %zu\n", (unsigned long long)third_node); 
    third_node->data = 300; 
    second_node->next = third_node; 
    third_node->prev = second_node; 
    third_node->next = head_node; 
    head_node->prev = third_node; 

    //  Traversal 
    //  Travel through all nodes with data 
    struct node* run = NULL; 

    run = head_node->next;  //  the next pointer of head node will point to the first node with data 
    while(run != head_node) //  note the peculiar termination condition. Its run != head_node (and not run != NULL)
    {
        printf("run->data = %d\n", run->data); 
        run = run->next; 
    }

    //  Destroy linked list : Free all nodes along with the head_node 
    struct node* run_next = NULL; 

    //  Stage 1: Free all nodes with data (i.e. all nodes except head node will be freed)
    run = head_node->next; 
    while(run != head_node)
    {
        run_next = run->next; 
        printf("Freeing node at address : %zu and content : %d\n", (unsigned long long)run, run->data); 
        free(run); 
        run = run_next; 
    }

    //  Stage 2: Free the head node 
    printf("Freeing head node: address : %zu\n", (unsigned long long)head_node); 
    free(head_node); 
    head_node = NULL; 

    puts("List successfully destroyed"); 
}