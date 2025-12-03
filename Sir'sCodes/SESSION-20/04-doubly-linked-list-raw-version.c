#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <assert.h> 

//  Node layout definition 
struct node 
{
    int data; 
    struct node* prev; 
    struct node* next; 
}; 

//  Interface function definitions 

//  List creation function 
struct node* create_list(void); 

//  Insert functions 
int insert_start(struct node* head_node, int new_data); 
int insert_end(struct node* head_node, int new_data); 
int insert_after(struct node* head_node, int existing_data, int new_data); 
int insert_before(struct node* head_node, int existing_data, int new_data); 

//  Remove functions 
int remove_start(struct node* head_node); 
int remove_end(struct node* head_node); 
int remove_data(struct node* head_node, int r_data); 

//  Miscallaneous functions 
int is_list_empty(struct node* head_node); 
void show(struct node* head_node, const char* msg); 

//  List destruction function 
int destroy_list(struct node* head_node); 

//  Client code 
int main(void) 
{

    return (0); 
} 

//  Interface function definitions 

//  List creation function 
struct node* create_list(void)
{
    //  Allocate dummy node. 
    //  Initialize its data, prev next members to 
    //  zero, NULL and NULL respectively 
    //  Return its address 

    struct node* head_node = NULL; 

    head_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == head_node)
    {
        puts("out of memory"); 
        exit(EXIT_FAILURE); 
    }

    head_node->data = 0; 
    head_node->prev = NULL; 
    head_node->next = NULL; 

    return (head_node); 
}

//  Insert functions 
int insert_start(struct node* head_node, int new_data)
{
    struct node* new_node = NULL; 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node)
    {
        puts("out of memory"); 
        exit(EXIT_FAILURE); 
    }

    new_node->data = new_data; 
    new_node->prev = head_node; 
    new_node->next = head_node->next; 
    
    if(head_node->next != NULL)
        head_node->next->prev = new_node; 
    
    head_node->next = new_node; 

    return (1); 
}

int insert_end(struct node* head_node, int new_data)
{
    struct node* new_node = NULL; 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node)
    {
        puts("out of memory"); 
        exit(EXIT_FAILURE); 
    }
    new_node->data = new_data; 

    struct node* run = NULL; 
    run = head_node; 
    while(run->next != NULL)
        run = run->next; 

    new_node->next = NULL; 
    new_node->prev = run; 

    run->next = new_node; 

    return (1);
}

int insert_after(struct node* head_node, int existing_data, int new_data)
{
    struct node* existing_node = NULL; 
    struct node* new_node = NULL; 
    struct node* run = NULL; 

    run = head_node->next; 
    while(run != NULL)
    {
        if(run->data == existing_data)
            break; 
        run = run->next; 
    }

    if(run == NULL)
        return (2); 

    existing_node = run; 
    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node)
    {
        puts("out of memory"); 
        exit(EXIT_FAILURE); 
    }
    new_node->data = new_data; 
    new_node->prev = existing_node; 
    new_node->next = existing_node->next; 

    if(existing_node->next != NULL)
        existing_node->next->prev = new_node; 

    existing_node->next = new_node; 

    return (1); 
}

int insert_before(struct node* head_node, int existing_data, int new_data)
{
    struct node* run = NULL; 
    struct node* existing_node = NULL; 
    struct node* new_node = NULL; 

    run = head_node->next; 
    while(run != NULL)
    {
        if(run->data == existing_data)
            break; 
        run = run->next; 
    }

    if(run == NULL)
        return (2); 

    existing_node = run; 
    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node)
    {
        puts("out of memory"); 
        exit(EXIT_FAILURE); 
    }

    new_node->next = existing_node; 
    new_node->prev = existing_node->prev; 
    existing_node->prev->next = new_node; 
    existing_node->prev = new_node; 

    return (1); 
}

//  Remove functions 
int remove_start(struct node* head_node)
{
    struct node* delete_node = NULL; 

    if(head_node->next == NULL)
        return (3); 

    delete_node = head_node->next; 

    delete_node->prev->next = delete_node->next; 
    if(delete_node->next != NULL) 
        delete_node->next->prev = delete_node->prev; 

    free(delete_node); 
    
    return (1); 
}

int remove_end(struct node* head_node)
{
    struct node* run = NULL; 
    struct node* delete_node = NULL; 
    
    if(head_node->next == NULL)
        return (3); 

    run = head_node->next; 
    while(run->next != NULL)
        run = run->next; 

    //  Taking advantage of the information that the 
    //  run pointer is the last node with data, we can write the following code 
    // run->prev->next = NULL;
    // free(run); 

    //  For general, uniform logic we can write the following code 
    delete_node = run; 

    delete_node->prev->next = delete_node->next; 
    if(delete_node->next != NULL)
        delete_node->next->prev = delete_node->prev; 

    free(delete_node); 
}

int remove_data(struct node* head_node, int r_data)
{
    struct node* delete_node = NULL; 
    struct node* run = NULL; 

    run = head_node->next; 
    while(run != NULL)
    {
        if(run->data == r_data)
            break; 
        run = run->next; 
    }

    if(run == NULL)
        return (2); 

    delete_node = run; 

    delete_node->prev->next = delete_node->next; 
    if(delete_node->next != NULL)
        delete_node->next->prev = delete_node->prev; 

    free(delete_node); 

    return (1); 
}

//  Miscallaneous functions 
int is_list_empty(struct node* head_node)
{
    return (head_node->next == NULL && head_node->prev == NULL); 
}

void show(struct node* head_node, const char* msg)
{
    struct node* run = NULL; 

    if(msg != NULL)
        puts(msg);
        
    printf("[START]->"); 
    run = head_node->next; 
    while(run != NULL)
    {
        printf("[%d]->", run->data); 
        run = run->next; 
    }
    printf("[END]\n"); 
}

//  List destruction function 
int destroy_list(struct node* head_node)
{
    struct node* run = NULL; 
    struct node* run_next = NULL; 

    run = head_node; 
    while(run != NULL)
    {
        run_next = run->next; 
        free(run); 
        run = run_next; 
    }

    return (1); 
}

//  KEEM CALM AND TRUST CPA 