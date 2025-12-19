// header files 
#include <stdio.h> 
#include <stdlib.h> 

// symbolic constants 
#define SUCCESS     1
#define TRUE        1 
#define FALSE       0 
#define LIST_EMPTY  2 
#define LIST_DATA_NOT_FOUND 3 

// node layout definition 
struct node 
{
    int data; 
    struct node* prev; 
    struct node* next; 
}; 

struct node* create_list(void); 
int insert_start(struct node* p_list, int new_data); 
int insert_end(struct node* p_list, int new_data); 
int insert_before(struct node* p_list, int existing_data, int new_data); 
int insert_after(struct node* p_list, int existing_data, int new_data); 

int get_start(struct node* p_list, int* p_start_data); 
int get_end(struct node* p_list, int* p_end_data); 

int pop_start(struct node* p_list, int* p_start_data); 
int pop_end(struct node* p_list, int* p_end_data); 

int remove_start(struct node* p_list); 
int remove_end(struct node* p_list); 
int remove_data(struct node* p_list, int r_data); 

int find(struct node* p_list, int f_data);
int get_list_length(struct node* p_list); 
int is_empty(struct node* p_list); 
void show(struct node* p_list, const char* msg); 

int clear_list(struct node* p_list); 
int destroy_list(struct node* p_list); 

int main(void) 
{
    return (0); 
} 

struct node* create_list(void) 
{
    struct node* new_list = NULL; 

    new_list = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_list) 
    {
        fprintf(stderr, "malloc():fatal:out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    new_list->data = 0; 
    new_list->next = NULL; 
    new_list->prev = NULL; 

    return (new_list); 
} 

int insert_start(struct node* p_list, int new_data) 
{
    struct node* new_node = NULL; 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        fprintf(stderr, "malloc():fatal:out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 
    new_node->next = p_list->next; 
    new_node->prev = p_list; 
    if(p_list->next != NULL) 
        p_list->next->prev = new_node; 
    p_list->next = new_node; 

    return (SUCCESS); 
} 

int insert_end(struct node* p_list, int new_data) 
{
    struct node* run = NULL; 

    run = p_list; 
    while(run->next != NULL) 
        run = run->next; 

    run->next = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == run->next) 
    {
        fprintf(stderr, "malloc():fatal:out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    run->next->next = NULL; 
    run->next->prev = run; 
    run->next->data = new_data; 
} 

int insert_after(struct node* p_list, int existing_data, int new_data) 
{
    struct node* run = NULL; 

    run = p_list->next; 
    while(run != NULL) 
    {
        if(run->data == existing_data) 
            break; 

        run = run->next; 
    } 

    if(run == NULL) 
        return (LIST_DATA_NOT_FOUND); 

    struct node* new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        printf("malloc():fatal:out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 
    new_node->next = run->next; 
    new_node->prev = run; 

    if(run->next != NULL)
        run->next->prev = new_node; 
    run->next = new_node; 

    return (SUCCESS); 
} 

int insert_before(struct node* p_list, int existing_data, int new_data) 
{
    struct node* run = NULL; 
    struct node* existing_node = NULL; 
    struct node* new_node = NULL; 

    // code 
    run = p_list->next; 
    while(run != NULL) 
    {
        if(run->data == existing_data) 
            break; 
        run = run->next; 
    } 

    if(run == NULL) 
        return (LIST_DATA_NOT_FOUND); 

    existing_node = run; 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        fprintf(stderr, "insert_before():malloc():fatal:out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 

    new_node->next = existing_node; 
    new_node->prev = existing_node->prev; 
    if(existing_node->prev != NULL)
        existing_node->prev->next = new_node; 
    existing_node->prev = new_node; 

    return (SUCCESS); 
} 

// remove functions 
int remove_start(struct node* p_list) 
{
    struct node* p_start_node = NULL; 

    if(p_list->next == NULL)    
        return (LIST_EMPTY); 

    p_start_node = p_list->next; 
    if(p_start_node->next != NULL) 
        p_start_node->next->prev = p_list; 
    p_list->next = p_start_node->next; 

    return (1); 
} 

int remove_end(struct node* p_list) 
{ 
    struct node* last_node = NULL; 
    struct node* run = NULL; 

    run = p_list; 
    while(run->next != NULL) 
        run = run->next; 

    run->prev->next = NULL; 
    free(run); 
    run = NULL; 

    return (1); 
}

int remove_data(struct node* p_list, int r_data) 
{
    struct node* run  = NULL; 
    struct node* delete_node = NULL; 

    // code 
    run = p_list->next; 
    while(run != NULL) 
    {
        if(run->data == r_data) 
            break; 
        run = run->next; 
    } 

    if(run == NULL) 
        return (3); 

    run->prev->next = run->next; 
    if(run->next != NULL) 
        run->next->prev = run->prev; 
    free(run); 
    run = NULL; 

    return (1); 
} 

// pop functions 
int pop_start(struct node* head_node, int* p_popped_data) 
{
    struct node* first_node = NULL; 

    // code 
    if(head_node->next == NULL && head_node->prev == NULL)
        return (LIST_EMPTY); 
    
    first_node = head_node->next; 
    *p_popped_data = first_node->data; 
    if(first_node->next != NULL) 
        first_node->next->prev = head_node; 
    head_node->next = first_node; 

    free(first_node); 
    first_node = NULL; 

    return (1); 
} 

int pop_end(struct node* head_node, int* p_popped_data) 
{} 

