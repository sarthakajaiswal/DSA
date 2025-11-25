/*
    @Goal: Singly Linked List repeatithon 
    @Author: Sarthak A. Jaiswal 
*/

/* Header files */
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <assert.h> 

/* Symbolic constants */
#define SUCCESS     1 
#define TRUE        1 
#define FALSE       0 
#define LIST_DATA_NOT_FOUND 2 
#define LIST_EMPTY  3 

/* Node layout definition */
struct node 
{
    int data; 
    struct node* next; 
}; 

/* Interface function declarations */
/* List creation function */
struct node* create_list(void); 

/* Data addition functions */
int insert_start(struct node* p_list, int new_data); 
int insert_end(struct node* p_list, int new_data); 
int insert_before(struct node* p_list, int existing_data, int new_data); 
int insert_after(struct node* p_list, int existing_data, int new_data); 

/* Get functions */
int get_start(struct node* p_list, int* p_start_data); 
int get_end(struct node* p_list, int* p_end_data); 

/* Pop functions */
int pop_start(struct node* p_list, int* p_start_data); 
int pop_end(struct node* p_list, int* p_end_data); 

/* data removal functions */
int remove_start(struct node* p_list); 
int remove_end(struct node* p_list); 
int remove_data(struct node* p_list, int r_data); 

/* Miscalleneous functions */
int find(struct node* p_list, int f_data); 
int get_list_length(struct node* p_list); 
int is_list_empty(struct node* p_list); 
void show_list(struct node* p_list, const char* msg); 

/* List destruction functions */
int destroy_list(struct node* p_list); 

/* client of linked list */
int main(void) 
{
    struct node* p_list = NULL; 

    int status; 
    int data, start_data, end_data; 
    int length; 

    static const char* line = "----------------------------------------------------"; 

    p_list = create_list(); 
    assert(p_list != NULL); 
    printf("List created Successfully\n"); 
    puts(line);  

    printf("Testing assertion on empty list:"); 
    assert(is_list_empty(p_list) == TRUE); 
    assert(get_list_length(p_list) == 0); 
    assert(get_start(p_list, &start_data) == LIST_EMPTY); 
    assert(get_end(p_list, &end_data) == LIST_EMPTY); 
    assert(pop_start(p_list, &start_data) == LIST_EMPTY); 
    assert(pop_end(p_list, &end_data) == LIST_EMPTY); 
    assert(remove_start(p_list) == LIST_EMPTY);
    assert(remove_end(p_list) == LIST_EMPTY); 
    printf("All assertions on empty list successfull\n"); 
    puts(line); 

    show_list(p_list, "Showing list immedietly after creation.\n"); 
    puts(line); 

    for(data = 0; data < 5; ++data) 
    {
        status = insert_start(p_list, data * 10); 
        assert(status == SUCCESS); 
        printf("%d inserted succesfully at the start of list\n", data*10); 
    } 
    show_list(p_list, "Showing list after insert_start():"); 
    puts(line); 

    for(data = 0; data < 5; ++data) 
    {
        status = insert_end(p_list, data*5); 
        assert(status == SUCCESS); 
        printf("%d inserted succesfully at the end of list\n", data*5); 
    } 
    show_list(p_list, "Showing list after insert_end()"); 
    puts(line); 

    status = insert_after(p_list, -5, 10); 
    assert(status == LIST_DATA_NOT_FOUND); 
    printf("Expected error to insert data 10 after non-existing data -5\n"); 
    puts(line); 

    status = insert_after(p_list, 0, 100); 
    assert(status == SUCCESS); 
    show_list(p_list, "Showing list after insert_after():"); 
    puts(line); 

    status = insert_before(p_list, 43, 200); 
    assert(status == LIST_DATA_NOT_FOUND); 
    printf("Expected failure to insert data 200 before non-existing data 43\n"); 
    puts(line); 

    status = insert_before(p_list, 0, 200); 
    assert(status == SUCCESS); 
    show_list(p_list, "Showing list after successfully inserting data 200 before 0:"); 
    puts(line); 

    status = get_start(p_list, &start_data);
    assert(status == SUCCESS); 
    printf("Data at the start: %d\n", start_data); 
    show_list(p_list, "Showing list to demonstrate that get_start() returns start data without removing it: "); 
    puts(line); 

    status = get_end(p_list, &end_data); 
    assert(status == SUCCESS); 
    printf("Data at the end: %d\n", end_data); 
    show_list(p_list, "Showing list to demonstrate that get_end() returns end data without removing it: "); 
    puts(line); 
    
    status = pop_start(p_list, &start_data); 
    assert(status == SUCCESS); 
    printf("Data at the start = %d\n", start_data); 
    show_list(p_list, "Showing list to demonstrate that pop_start() removes and returns start data: "); 
    puts(line); 

    status = pop_end(p_list, &end_data); 
    assert(status == SUCCESS); 
    printf("Data at the end = %d\n", end_data); 
    show_list(p_list, "Showing list to demostrate that pop_end() removes and returns end data: "); 
    puts(line); 

    status = remove_start(p_list); 
    assert(status == SUCCESS); 
    show_list(p_list, "Showing list after remove_start(): "); 
    puts(line); 

    status = remove_end(p_list); 
    assert(status == SUCCESS); 
    show_list(p_list, "Showing list after remove_end(): "); 
    puts(line); 

    status = remove_data(p_list, 78); 
    assert(status == LIST_DATA_NOT_FOUND); 
    printf("Expected error in removing non-existent data 78\n"); 
    puts(line); 

    status = remove_data(p_list, 0); 
    assert(status == SUCCESS); 
    show_list(p_list, "Showing list after removing existing data 0: "); 
    puts(line); 

    status = find(p_list, 91); 
    assert(status == FALSE); 
    printf("Expected return value TRUE from find() for non-existent data 91\n"); 
    puts(line); 

    status = find(p_list, 100); 
    assert(status == TRUE); 
    printf("Expected return value TRUE from find() for existing data 100\n"); 
    puts(line); 

    status = is_list_empty(p_list); 
    assert(status == FALSE); 
    printf("Expected return value FALSE from is_list_empty()\n"); 
    puts(line); 

    length = get_list_length(p_list); 
    printf("Length of list = %d\n", length); 
    puts(line); 

    status = destroy_list(p_list); 
    assert(status == SUCCESS); 
    p_list = NULL; 
    printf("List is destroyed successfully\n"); 
    puts(line); 

    return (0); 
} 

/* Server of linked list */
/* Interface function definitions */
/*List creation function */
struct node* create_list(void) 
{
    struct node* head_node = NULL; 

    head_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == head_node) 
    {
        printf("Out of memory\n"); 
        exit(EXIT_FAILURE); 
    }
    head_node->data = 0; 
    head_node->next = NULL; 

    return (head_node); 
} 

/* Data insertion functions */
int insert_start(struct node* p_list, int new_data) 
{
    struct node* new_node = NULL; 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(new_node == NULL) 
    {
        puts("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 
    new_node->next = p_list->next; 
    p_list->next = new_node; 

    return (SUCCESS); 
}

int insert_end(struct node* p_list, int new_data) 
{
    struct node* run = NULL; 
    struct node* new_node = NULL; 

    // step1: allocate and initialize new node 
    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        printf("Out of memory\n"); 
        exit(EXIT_FAILURE); 
    }  
    new_node->data = new_data; 
    new_node->next = NULL; 

    // step2: locate last node 
    run = p_list; 
    while(run->next != NULL) 
    {
        run = run->next; 
    } 

    // step3: Append the new node at the last position 
    run->next = new_node; 

    return (SUCCESS); 
} 

int insert_after(struct node* p_list, int existing_data, int new_data) 
{
    struct node* existing_node = NULL; 
    struct node* new_node = NULL; 
    struct node* run = NULL; 

    // step1: search for the node containing first occurence of existing data 
    run = p_list->next; 
    while(run != NULL) 
    {
        if(run->data == existing_data) 
        {
            break; 
        } 
        run = run->next; 
    } 

    // if existing data in snot found then return error as such 
    if(NULL == run) 
        return (LIST_DATA_NOT_FOUND); 

    // step2: Allocate and initialize new node 
    existing_node = run; 
    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        printf("Out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 

    // step3: insert the new node at its appropriate position 
    new_node->next = existing_node->next; 
    existing_node->next = new_node; 

    return (SUCCESS); 
} 

int insert_before(struct node* p_list, int existing_data, int new_data) 
{
    struct node* run = NULL; 
    struct node* run_previous = NULL; 
    struct node* new_node = NULL; 

    // step1: Search for the first occurence of existing data maintaining the back pointer 
    run_previous = p_list; 
    run = p_list->next; 
    while(run != NULL) 
    {
        if(run->data == existing_data) 
            break; 

        run_previous = run; 
        run = run->next; 
    } 

    // if existing data is not found throught the list then return error saying as such 
    if(NULL == run)
        return (LIST_DATA_NOT_FOUND); 

    // step2: Allocate and initialize new node 
    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        printf("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 

    // step3: Insert the new node at the appropriate position 
    new_node->next = run; 
    run_previous->next = new_node; 

    return (SUCCESS); 
} 

/* Get functions */
int get_start(struct node* p_list, int* p_start_data) 
{
    if(p_list->next == NULL) 
        return (LIST_EMPTY); 

    *p_start_data = p_list->next->data; 
    return (SUCCESS); 
} 

int get_end(struct node* p_list, int* p_end_data) 
{
    struct node* run = NULL; 

    if(p_list->next == NULL) 
        return (LIST_EMPTY); 

    run = p_list; 
    while(run->next != NULL) 
    {
        run = run->next; 
    } 

    *p_end_data = run->data; 

    return (SUCCESS); 
} 

/* Pop functions */
int pop_start(struct node* p_list, int* p_start_data) 
{
    struct node* delete_previous = NULL; 
    struct node* delete_node = NULL; 
    struct node* delete_next = NULL; 

    if(p_list->next == NULL) 
        return (LIST_EMPTY); 

    delete_previous = p_list; 
    delete_node = p_list->next; 
    delete_next = p_list->next->next; 

    delete_previous->next = delete_next; 

    free(delete_node); 
    delete_node = NULL; 

    return (SUCCESS); 
} 

int pop_end(struct node* p_list, int* p_end_data) 
{
    struct node* run = NULL; 
    struct node* run_previous = NULL; 

    if(NULL == p_list->next) 
        return (LIST_EMPTY); 

    run_previous = p_list; 
    run = p_list->next; 
    while(run->next != NULL) 
    {
        run_previous = run; 
        run = run->next; 
    } 

    *p_end_data = run->data; 
    
    free(run); 
    run = NULL; 
    run_previous->next = NULL; 
    
    return (SUCCESS); 
} 

/* remove functions */
int remove_start(struct node* p_list) 
{
    struct node* delete_previous = NULL; 
    struct node* delete_node = NULL; 
    struct node* delete_next = NULL; 

    if(p_list->next == NULL) 
        return (LIST_EMPTY); 

    delete_previous = p_list; 
    delete_node = p_list->next; 
    delete_next = p_list->next->next; 

    delete_previous->next = delete_next; 

    free(delete_node); 
    delete_node = NULL; 

    return (SUCCESS); 
} 

int remove_end(struct node* p_list) 
{
    struct node* run = NULL; 
    struct node* run_previous = NULL; 

    if(p_list->next == NULL) 
        return (LIST_EMPTY); 

    run_previous = p_list; 
    run = p_list->next; 
    while(run->next != NULL) 
    {
        run_previous = run; 
        run = run->next; 
    } 

    free(run); 
    run = NULL; 
    run_previous->next = NULL; 

    return (SUCCESS); 
} 

int remove_data(struct node* p_list, int r_data) 
{
    struct node* run = NULL; 
    struct node* run_previous = NULL; 

    run_previous = p_list; 
    run = p_list->next; 
    while(run != NULL) 
    {
        if(run->data == r_data) 
            break; 

        run_previous = run; 
        run = run->next; 
    } 

    if(run == NULL) 
        return (LIST_DATA_NOT_FOUND); 
    
    run_previous->next = run->next; 
    free(run); 
    run = NULL; 

    return (SUCCESS); 
} 

/* Miscalleneous functions */
int find(struct node* p_list, int f_data) 
{
    struct node* run = NULL; 

    run = p_list->next; 
    while(run != NULL) 
    {
        if(run->data == f_data) 
            return (TRUE); 
        run = run->next; 
    } 

    return (FALSE); 
} 

int get_list_length(struct node* p_list) 
{
    int len = 0; 
    struct node* run = NULL; 

    run = p_list->next; 
    while(run != NULL)
    {
        len = len+1; 
        run = run->next; 
    } 

    return (len); 
} 

int is_list_empty(struct node* p_list) 
{
    return (p_list->next == NULL); 
} 

void show_list(struct node* p_list, const char* msg) 
{
    struct node* run = NULL; 

    if(msg) 
        puts(msg); 

    printf("[START] ->"); 
    run = p_list->next; 
    while(run != NULL) 
    {
        printf("[%d]->", run->data); 
        run = run->next; 
    } 
    printf("[END]\n"); 
} 

/* List destruction function */
int destroy_list(struct node* p_list) 
{
    struct node* run = NULL; 
    struct node* run_next = NULL; 

    run = p_list; 
    while(run != NULL) 
    {
        run_next = run->next; 
        free(run); 
        run = run_next; 
    } 

    return (SUCCESS); 
} 

// ====================================================================================================== 

// 1
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <assert.h> 

// 2 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <assert.h> 

// 3 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <assert.h> 

// 4 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <assert.h> 

// 5 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <assert.h> 

// 1
#define SUCCESS 1 
#define TRUE        1 
#define FALSE       0 
#define LIST_DATA_NOT_FOUND 2 
#define LIST_EMPTY  3 

// 2
#define SUCCESS     1 
#define TRUE        1 
#define FALSE       0 
#define LIST_DATA_NOT_FOUND 2 
#define LIST_EMPTY  3 

// 3 
#define SUCCESS     1 
#define TRUE        1 
#define FALSE       0 
#define LIST_DATA_NOT_FOUND 2 
#define LIST_EMPTY  3 

// 4 
#define SUCCESS     1 
#define TRUE        1 
#define FALSE       0 
#define LIST_DATA_NOT_FOUND 2 
#define LIST_EMPTY  3 

// 5 
#define SUCCESS     1 
#define TRUE        1 
#define FALSE       0 
#define LIST_DATA_NOT_FOUND 2 
#define LIST_EMPTY  3 

/* node layout definition */
struct node 
{
    int data; 
    struct node* next; 
}; 

struct node 
{
    int data; 
    struct node* next; 
}; 

struct node 
{
    int data; 
    struct node* next; 
}; 

struct node 
{
    int data; 
    struct node* next; 
}; 

struct node 
{
    int data; 
    struct node* next; 
}; 

/* Interface function declarations */
/* List creation functions */
struct node* create_list(void); 
struct node* create_list(void); 
struct node* create_list(void); 
struct node* create_list(void); 
struct node* create_list(void); 

/* Data addition functions */
int insert_start(struct node* p_list, int start_data); 
int insert_start(struct node* p_list, int start_data); 
int insert_start(struct node* p_list, int start_data); 
int insert_start(struct node* p_list, int start_data); 
int insert_start(struct node* p_list, int start_data); 

int insert_end(struct node* p_list, int end_data); 
int insert_end(struct node* p_list, int end_data); 
int insert_end(struct node* p_list, int end_data); 
int insert_end(struct node* p_list, int end_data); 
int insert_end(struct node* p_list, int end_data); 

int insert_before(struct node* p_list, int existing_data, int new_data); 
int insert_before(struct node* p_list, int existing_data, int new_data); 
int insert_before(struct node* p_list, int existing_data, int new_data); 
int insert_before(struct node* p_list, int existing_data, int new_data); 
int insert_before(struct node* p_list, int existing_data, int new_data); 

int insert_after(struct node* p_list, int existing_data, int new_data); 
int insert_after(struct node* p_list, int existing_data, int new_data); 
int insert_after(struct node* p_list, int existing_data, int new_data); 
int insert_after(struct node* p_list, int existing_data, int new_data); 
int insert_after(struct node* p_list, int existing_data, int new_data); 

/* Get functions */
int get_start(struct node* p_list, int* p_start_data); 
int get_start(struct node* p_list, int* p_start_data); 
int get_start(struct node* p_list, int* p_start_data); 
int get_start(struct node* p_list, int* p_start_data); 
int get_start(struct node* p_list, int* p_start_data); 

int get_end(struct node* p_list, int* p_end_data); 
int get_end(struct node* p_list, int* p_end_data); 
int get_end(struct node* p_list, int* p_end_data); 
int get_end(struct node* p_list, int* p_end_data); 
int get_end(struct node* p_list, int* p_end_data); 

/* Pop functions */
int pop_start(struct node* p_list, int* p_start_data); 
int pop_start(struct node* p_list, int* p_start_data); 
int pop_start(struct node* p_list, int* p_start_data); 
int pop_start(struct node* p_list, int* p_start_data); 
int pop_start(struct node* p_list, int* p_start_data); 

int pop_end(struct node* p_list, int* p_end_data); 
int pop_end(struct node* p_list, int* p_end_data); 
int pop_end(struct node* p_list, int* p_end_data); 
int pop_end(struct node* p_list, int* p_end_data); 
int pop_end(struct node* p_list, int* p_end_data); 

/* remove functions */
int remove_start(struct node* p_list); 
int remove_start(struct node* p_list); 
int remove_start(struct node* p_list); 
int remove_start(struct node* p_list); 
int remove_start(struct node* p_list); 

int remove_end(struct node* p_list); 
int remove_end(struct node* p_list); 
int remove_end(struct node* p_list); 
int remove_end(struct node* p_list); 
int remove_end(struct node* p_list); 

int remove_data(struct node* p_list, int r_data); 
int remove_data(struct node* p_list, int r_data); 
int remove_data(struct node* p_list, int r_data); 
int remove_data(struct node* p_list, int r_data); 
int remove_data(struct node* p_list, int r_data); 

/* Miscalleneous functions */
int find(struct node* p_list, int f_data); 
int find(struct node* p_list, int f_data); 
int find(struct node* p_list, int f_data); 
int find(struct node* p_list, int f_data); 
int find(struct node* p_list, int f_data); 

int get_list_length(struct node* p_list); 
int get_list_length(struct node* p_list); 
int get_list_length(struct node* p_list); 
int get_list_length(struct node* p_list); 
int get_list_length(struct node* p_list); 

int is_list_empty(struct node* p_list); 
int is_list_empty(struct node* p_list); 
int is_list_empty(struct node* p_list); 
int is_list_empty(struct node* p_list); 
int is_list_empty(struct node* p_list); 

void show_list(struct node* p_list, const char* msg); 
void show_list(struct node* p_list, const char* msg); 
void show_list(struct node* p_list, const char* msg); 
void show_list(struct node* p_list, const char* msg); 
void show_list(struct node* p_list, const char* msg); 

/* List destruction function */
int destroy_list(struct node* p_list); 
int destroy_list(struct node* p_list); 
int destroy_list(struct node* p_list); 
int destroy_list(struct node* p_list); 
int destroy_list(struct node* p_list); 

// ============================================================================= 

// 1 
int main(void) 
{
    struct node* p_list = NULL; 

    int status; 
    int data, start_data, end_data; 
    int length; 

    const char* line = "---------------------------------------------------------"; 

    return (0); 
} 

int main(void) 
{
    struct node* p_list = NULL; 

    int status = 0; 
    int data, start_data, end_data; 
    int length; 

    const char* line = "----------------------------------------------------------"; 

    return (0); 
} 

int main(void) 
{
    struct node* p_list = NULL; 

    int status = 0; 
    int data, start_data, end_data; 
    int length; 

    const char* line = "----------------------------------------------------------"; 

    return (0); 
} 

int main(void) 
{
    struct node* p_list = NULL; 

    int status; 
    int data, start_data, end_data; 
    int length; 

    const char* line = "------------------------------------------------------------"; 

    return (0); 
} 

int main(void) 
{
    struct node* p_list = NULL; 

    int status; 
    int data, start_data, end_data; 
    int length; 

    const char* line = "---------------------------------------------------------------"; 

    return (0); 
} 

//---------- 

/* Client of linked list */
int main(void) 
{
    struct node* p_list = NULL; 

    int status; 
    int data, start_data, end_data; 
    int length; 

    static const char* line = "---------------------------------------------------"; 

    p_list = create_list(); 
    assert(p_list != NULL); 
    printf("List created successfully\n"); 
    puts(line); 

    p_list = create_list(); 
    assert(p_list != NULL); 
    printf("List created successfully\n"); 
    puts(line); 

    p_list = create_list(); 
    assert(p_list != NULL); 
    printf("List created successfully\n"); 
    puts(line); 

    p_list = create_list(); 
    assert(p_list != NULL); 
    printf("List created successfully"); 
    puts(line); 

    p_list = create_list(); 
    assert(p_list != NULL); 
    printf("List created successfully\n"); 
    puts(line); 

    //----------------- 

    printf("Testing assertions on empty list\n"); 
    assert(is_list_empty(p_list) == TRUE); 
    assert(get_list_length(p_list) == 0); 
    assert(get_start(p_list, &start_data) == LIST_EMPTY); 
    assert(get_end(p_list, &end_data) == LIST_EMPTY); 
    assert(pop_start(p_list, &start_data) == LIST_EMPTY); 
    assert(pop_end(p_list, &end_data) == LIST_EMPTY); 
    assert(remove_start(p_list) == LIST_EMPTY); 
    assert(remove_end(p_list) == LIST_EMPTY); 
    printf("All assertions on empty list are successfuull\n"); 
    puts(line); 

    printf("Testing assertions on empty list\n"); 
    assert(is_list_empty(p_list) == TRUE); 
    assert(get_list_length(p_list) == 0); 
    assert(get_start(p_list, &start_data) == LIST_EMPTY); 
    assert(get_end(p_list, &end_data) == LIST_EMPTY); 
    assert(pop_start(p_list, &start_data) == LIST_EMPTY); 
    assert(pop_end(p_list, &end_data) == LIST_EMPTY); 
    assert(remove_start(p_list) == LIST_EMPTY); 
    assert(remove_end(p_list) == LIST_EMPTY); 
    printf("All assertions of empty list are successfull\n"); 
    puts(line); 

    printf("Testing assertions on empty list\n"); 
    assert(is_list_empty(p_list) == TRUE); 
    assert(get_list_length(p_list) == 0); 
    assert(get_start(p_list, &start_data) == LIST_EMPTY); 
    assert(get_end(p_list, &end_data) == LIST_EMPTY); 
    assert(pop_start(p_list, &start_data) == LIST_EMPTY); 
    assert(pop_end(p_list, &end_data) == LIST_EMPTY); 
    assert(remove_start(p_list) == LIST_EMPTY); 
    assert(remove_end(p_list) == LIST_EMPTY); 
    printf("All assertions on empty list are successfull\n"); 
    puts(line); 

    printf("Testing assertions on empty list\n"); 
    assert(is_list_empty(p_list) == TRUE); 
    assert(get_list_length(p_list) == 0); 
    assert(get_start(p_list, &start_data) == LIST_EMPTY); 
    assert(get_end(p_list, &end_data) == LIST_EMPTY); 
    assert(pop_start(p_list, &start_data) == LIST_EMPTY); 
    assert(pop_end(p_list, &end_data) == LIST_EMPTY); 
    assert(remove_start(p_list) == LIST_EMPTY); 
    assert(remove_end(p_list) == LIST_EMPTY); 
    printf("All assertions on empty list are successfull\n"); 
    puts(line); 

    printf("Testing assertions on empty list\n"); 
    assert(is_list_empty(p_list) == TRUE); 
    assert(get_list_length(p_list) == 0); 
    assert(get_start(p_list, &start_data) == LIST_EMPTY); 
    assert(get_end(p_list, &end_data) == LIST_EMPTY); 
    assert(pop_start(p_list, &start_data) == LIST_EMPTY); 
    assert(pop_end(p_list, &end_data) == LIST_EMPTY); 
    assert(remove_start(p_list) == LIST_EMPTY); 
    assert(remove_end(p_list) == LIST_EMPTY); 
    printf("All assertions on empty list are successfull\n"); 
    puts(line); 

    show_list(p_list, "Showing list immediately after creation\n"); 
    puts(line); 

    show_list(p_list, "Shwong list immedietly after creation:"); 
    puts(line); 

    show_list(p_list, "Showing list immedietly after creation:"); 
    puts(line); 

    show_list(p_list, "Shwoing list immedietly after creation\n"); 
    puts(line); 

    show_list(p_list, "Showing list immedietly after creation:"); 
    puts(line); 

    show_list(p_list, "Showing list immedietly after creation: "); 
    puts(line); 

    // 1 
    for(data = 0; data < 5; ++data) 
    { 
        status = insert_start(p_list, data * 10); 
        assert(status == SUCCESS); 
        printf("%d inserted at the start of list\n", data*10); 
    }
    show_list(p_list, "SHowing list after inserting 5 elements at the start of the list"); 

    for(data = 1; data <= 5; ++data) 
    {
        status = insert_end(p_list, data*5); 
        assert(status == SUCCESS); 
        printf("%d inserted at the end of list\n", data*5); 
    }
    show_list(p_list, "Showing list after inseryion 5 elements at the end:"); 

    // 2 
    for(data = 0; data < 5; ++data) 
    {
        status = insert_start(p_list, data * 10); 
        assret(status == SUCCESS); 
        printf("%d inserted at the start of list\n", data * 10); 
    } 
    show_list(p_list, "Showing list after inserting 5 elements at the start of list:"); 

    for(data = 1; data <= 5; ++data) 
    {
        status = insert_end(p_list, data*5); 
        assert(status == SUCCESS); 
        printf("%d inserted successfully at the end of list\n", data*5); 
    } 
    show_list(p_list, "SHowing list after inserting 5 elements at the end of list: "); 

    // 3 
    for(data = 0;  data < 5; ++data) 
    {
        status = insert_start(p_list, data * 10); 
        assert(status == SUCCESS); 
        printf("%d inserted succesfully at the start of list\n", data*10); 
    } 
    show_list(p_list, "Showing list after inserting 5 elements at start of list: "); 

    for(data = 1; data <= 5; ++data) 
    {
        status = insert_end(p_list, data*5); 
        assert(status == SUCCESS); 
        printf("%d inserted successfully at the end of list\n", data*5); 
    } 
    show_list(p_list, "SHowing list after inserting 5 elements at end of list: "); 

    // 4 
    for(data = 0; data < 5; ++data) 
    {
        status = insert_start(p_list, data * 10); 
        assert(status == SUCCESS); 
        printf("%d inserted successfully at the start of list\n", data*10); 
    } 
    show_list(p_list, "Showing list After inserting 5 elements at the start of list:"); 

    for(data = 1; data <= 5; ++data) 
    {
        status = insert_end(p_list, data*5); 
        assert(status == SUCCESS); 
        printf("%d inserted successfully at the end of list\n", data * 5); 
    } 
    show_list(p_list, "SHowing list after inserting 5 elements at end of list:"); 

    // 5 
    for(data = 0; data < 5; ++data) 
    {
        status = insert_start(p_list, data * 10); 
        assert(status == SUCCESS); 
        printf("%d inserted successfully at start of list\n", data*10); 
    } 
    show_list(p_list, "Showing list after inserting 5 elements at the start of list:"); 

    for(data = 1; data <= 5; ++data) 
    {
        status = insert_end(p_list, data*5); 
        assert(status == SUCCESS); 
        printf("%d inserted at the end of list\n", data * 5); 
    } 
    show_list(p_list, "Showing list after inserting 5 elements at the end of list:"); 

    // -------------------------- 

    status = insert_after(p_list, -5, 100); 
    assert(status == LIST_DATA_NOT_FOUND); 
    printf("Expected error to insert data 100 after non-existent data -5\n"); 

    status = insert_after(p_list, -5, 100); 
    assert(status == SUCCESS); 
    printf("Expected error to insert data 100 after non-existing data -5\n"); 

    status = insert_after(p_list, -5, 100); 
    assert(status == SUCCESS); 
    printf("Expected error to insert data 100 after non-existing data -5\n"); 

    status = insert_after(p_list, -5, 100); 
    assert(status == SUCCESS); 
    printf("Expected error to insert data 100 after non-existing data -5\n"); 

    status = insert_after(p_list, -5, 100); 
    assert(status == SUCCESS); 
    printf("Expected error to insert data 100 after non-exsting data -5\n"); 

    // --------------- 

    status = insert_after(p_list, 0, 100); 
    assert(status == SUCCESS); 
    show_list(p_list, "Showing list after inserting 100 after 0"); 

    status = insert_after(p_list, 0, 100); 
    assert(status == SUCCESS); 
    show_list(p_list, "Showing list after inserting 100 after 0"); 

    status = insert_after(p_list, 0, 100); 
    assert(status == SUCCESS); 
    show_list(p_list, "Showing list after inserting 100 after 0") ; 

    status = insert_after(p_list, 0, 100); 
    assert(status == SUCCESS); 
    show_list(p_list, "SHowing list after inserting 100 after 0"); 

    status = insert_after(p_list, 0, 100); 
    assert(status == SUCCESS); 
    show_list(p_list, "Showing list after inserting 100 after 0"); 

    // ---------------- 

    status = insert_before(p_list, 43, 200); 
    assert(status == LIST_DATA_NOT_FOUND); 
    printf("Expected failure to insert data 200 after non-existing data 43\n"); 

    status = insert_before(p_list, 43, 200); 
    assert(status == LIST_DATA_NOT_FOUND); 
    printf("Expected failure to insert data 200 after non-existing data 43\n"); 

    status = insert_before(p_list, 43, 200); 
    assert(status == LIST_DATA_NOT_FOUND); 
    printf("Expected failure to insert data 200 after non-existing data 43\n"); 
    
    status = insert_before(p_list, 43, 200); 
    assert(status == LIST_DATA_NOT_FOUND); 
    printf("Expected failure to insert data 200 before non-existing data 43\n"); 

    status = insert_before(p_list, 43, 200); 
    assert(status == LIST_DATA_NOT_FOUND); 
    printf("Expected failure to insert data 200 before non-existing data 43\n"); 

    status = insert_before(p_list, 43, 200); 
    assert(status == LIST_DATA_NOT_FOUND); 
    printf("Expected failure to insert data 200 before non-existing data 43\n"); 

    // ----------- 

    status = insert_before(p_list, 0, 200); 
    assert(status == SUCCESS); 
    show_list(p_list, "Showing list after inserting 200 after existing data 0: "); 

    status = insert_before(p_list, 0, 200); 
    assert(status == SUCCESS); 
    show_list(p_list, "SHowing list after inserting 200 before existing data 0: "); 

    status = insert_before(p_list, 0, 200); 
    assert(status == SUCCESS); 
    show_list(p_list, "Showing list after inserting 200 before existing data 0: "); 

    status = insert_before(p_list, 0, 200); 
    assert(status == SUCCESS); 
    show_list(p_list, "Showing list after inserting 200 before existing data 0: "); 

    status = insert_before(p_list, 0, 200); 
    assert(status == SUCCESS); 
    show_list(p_list, "Showing list after inserting 200 before existing data 0: "); 

    // ------------ 

    status = get_start(p_list, &start_data); 
    assert(status == SUCCESS); 
    printf("Data at the start: %d\n", start_data); 
    show_list(p_list, "Showing list to demonstrate that get_start() returns start data without removing it:"); 
    puts(line); 

    status = get_start(p_list, &start_data); 
    assert(status == SUCCESS);
    printf("Data at the start = %d\n", start_data); 
    show_list(p_list, "Showing list to demonstrate get_start() returns start data without removing it: "); 
    puts(line); 

    status = get_start(p_list, &start_data); 
    assert(status == SUCCESS); 
    printf("Data at the start = %d\n", start_data); 
    show_list(p_list, "Showing list to demonstrate get_start() returns start data without removing it: "); 
    puts(line); 

    status = get_start(p_list, &start_data); 
    assert(status == SUCCESS); 
    printf("Data at start  = %d\n", start_data); 
    // data data data data data data data data data  
    show_list(p_list, "Showing list to demonstrate get_start() return start data without removing it:"); 
    puts(line); 

    status = get_start(p_list, &start_data); 
    assert(status == SUCCESS); 
    printf("Data at the start = %d\n", start_data); 
    show_list(p_list, "Showing list to demostrate get_start() returns start data without removing it: "); 
    puts(line); 

    //-------------------- 

    status = get_end(p_list, &end_data); 
    assert(status == SUCCESS); 
    printf("Data at the end: %d\n", end_data); 
    show_list(p_list, "Showing list to demonstrate that get_end() returns the end data without removing it: "); 
    puts(line); 

    status = get_end(p_list, &end_data); 
    assert(status == SUCCESS); 
    printf("Data at end of list = %d\n", end_data); 
    show_list(p_list, "Showing list to demonstrate that get_end() returns the end data without removing it: "); 
    puts(line); 

    status = get_end(p_list, &end_data); 
    assert(status == SUCCESS); 
    printf("Data at the end of list = %d\n", end_data); 
    show_list(p_list, "Showing list to demonstrate that get_end() returns the end data without removing it: "); 
    puts(line); 

    status = get_end(p_list, end_data); 
    assert(status == SUCCESS); 
    printf("Data at the end of list = %d\n", end_data); 
    show_list(p_list, "Showing list to demonstrate that get_end() returns the end data without removing it: "); 
    puts(line); 

    status = get_end(p_list, end_data); 
    assert(status == SUCCESS); 
    printf("Data at the end of list = %d\n", end_data); 
    show_list(p_list, "Showing list to demonstrate that get_end() returns the end data without removing it: "); 
    puts(line); 

    // --------------------- 

    status = pop_start(p_list, &start_data); 
    assert(status == SUCCESS); 
    printf("Data at the start = %d\n", start_data); 
    show_list(p_list, "Showing list to demonstrate that pop_start() removes and returns start data: "); 
    puts(line); 

    status = pop_start(p_list, &start_data); 
    assert(status == SUCCESS); 
    printf("Data at the start = %d\n", start_data); 
    show_list(p_list, "Showing list to demonstrate that pop_start() removes and returns start data: "); 
    puts(line); 

    status = pop_start(p_list, &start_data); 
    assert(status == SUCCESS); 
    printf("Data at the start of list = %d\n", start_data); 
    show_list(p_list, "Showing list to demonstrate pop_start() returns and removes start data: "); 
    puts(line); 

    status = pop_start(p_list, &start_data); 
    assert(status == SUCCESS); 
    printf("start data = %d\n", start_data); 
    show_list(p_list, "SHowing list to demostrate pop_start() returns and removes start data: "); 
    puts(line); 

    status = pop_start(p_list, &start_data); 
    assert(status == SUCCESS); 
    printf("start data = %d\n", start_data); 
    show_list(p_list, "Showing list to demonstrate pop_start() returns and removes start data: "); 
    puts(line); 

    // ------------------------- 
    status = pop_end(p_list, &end_data); 
    assert(status == SUCCESS); 
    printf("end_data = %d\n", end_data); 
    show_list(p_list, "SHowing list to demostrate pop_end() returns and removes end data: "); 
    puts(line); 

    status = pop_end(p_list, &end_data); 
    assert(status == SUCCESS); 
    printf("end data = %d\n", end_data); 
    show_list(p_list, "Showing list to demostrate pop_end() returns and removes end data : "); 
    puts(line); 

    status = pop_end(p_list, &end_data); 
    assert(status == SUCCESS); 
    printf("end data = %d\n", end_data); 
    show_list(p_list, "Showing list to demostrate pop_end() returns and removes end data: "); 
    puts(line); 

    status = pop_end(p_list, &end_data); 
    assert(status == SUCCESS); 
    printf("end data = %d\n", end_data); 
    show_list(p_list, "Showing list to demostarte pop_end() returns and removes end data: "); 
    puts(line); 

    status = pop_end(p_list, &end_data); 
    assert(status == SUCCESS); 
    printf("end data = %d\n", end_data); 
    show_list(p_list, "Showing list to demostrate pop_end() returns and removes end data: "); 
    puts(line); 

    //----------- 
    status = remove_start(p_list); 
    assert(status == SUCCESS); 
    show_list(p_list, "showing list after remove_start():"); 
    puts(line); 

    status = remove_start(p_list); 
    assert(status == SUCCESS); 
    show_list(p_list, "Showing list after remove_start():"); 
    puts(line); 

    status = remove_start(p_list); 
    assert(status == SUCCESS); 
    show_list(p_list, "Showing list after remove_start():"); 
    puts(line); 

    status = remove_start(p_list); 
    assert(status == SUCCESS); 
    show_list(p_list, "Showing list after remove_start(): "); 
    puts(line); 

    status = remove_start(p_list); 
    assert(status == SUCCESS); 
    show_list(p_list, "Showing list after remove_start() : "); 
    puts(line); 

    status = remove_start(p_list); 
    assetr(status == SUCCESS); 
    show_list(p_list, "Showing list after remove_start(): "); 
    puts(line); 

    //------------- 
    status = remove_end(p_list); 
    assert(status == SUCCESS); 
    show_list(p_list, "Showing list after remove_end(): "); 
    puts(line); 

    status = remove_end(p_list); 
    assert(status == SUCCESS); 
    show_list(p_list, "Showing list after remove_end(): "); 
    puts(line); 

    status = remove_end(p_list); 
    assert(status == SUCCESS); 
    show_list(p_list, "Showing list after remove_end(): "); 
    puts(line); 

    status = remove_end(p_list); 
    assert(status == SUCCESS); 
    show_list(p_list, "Showing list after remove_end(): "); 
    puts(line); 

    status = remove_end(p_list); 
    assert(status == SUCCESS); 
    show_list(p_list, "SHowing list after remove_end(): "); 
    puts(line); 

    //------------------ 
    status = remove_data(p_list, 78); 
    assert(status == LIST_DATA_NOT_FOUND); 
    printf("Expected faiilure to remove non-existing data 78\n"); 
    puts(line); 

    status = remove_data(p_list, 78); 
    assert(status == LIST_DATA_NOT_FOUND); 
    printf("Expected failure to remove non-existing data 78\n"); 
    puts(line); 

    status = remove_data(p_list, 78); 
    assert(status == LIST_DATA_NOT_FOUND); 
    printf("Expected error to remove non-existent data 78\n"); 
    puts(line); 

    status = remove_data(p_list, 78); 
    assert(status == SUCCESS); 
    printf("Expected error to remove non-existing data 78\n"); 
    puts(line); 

    status = remove_data(p_list, 78); 
    assert(status == SUCCESS); 
    printf("Expected error to remove non-existing data 78\n"); 
    puts(line); 

    //------------------- 
    status = remove_data(p_list, 0); 
    assert(status == SUCCESS); 
    show_list(p_list, "Showing list after removing existing data 0\n"); 
    puts(line); 

    status = remove_data(p_list, 0); 
    assert(status == SUCCESS); 
    show_list(p_list, "Shwoing list after removing existing data 0\n"); 
    puts(line); 

    status = remove_data(p_list, 0);
    assert(status == SUCCESS); 
    show_list(p_list, "Showing list after removing existing data 0\n"); 
    puts(line); 

    status = remove_data(p_list, 0); 
    assert(status == SUCCESS); 
    show_list(p_list, "Showing list after removing existing data 0\n"); 
    puts(line); 

    status = remove_data(p_list, 0); 
    assert(status == SUCCESS); 
    show_list(p_list, "SHowing list after removing existing data 0\n"); 
    puts(line); 
    //-------------------- 

    status = find(p_list, 91); 
    assert(status == FALSE); 
    printf("Expected return value FALSE from find() for non-existng data 91\n"); 
    puts(line); 

    status = find(p_list, 91); 
    assert(status == FALSE); 
    printf("Expected return valur FALSE from() find() for non-existing data 91\n"); 
    puts(line); 

    status = find(p_list, 45); 
    assert(status == FALSE); 
    printf("Expected return value FALSE from find() for non-existing data 45\n"); 
    puts(line); 

    status = find(p_list, 98); 
    assert(status == FALSE); 
    printf("Expected return value FALSE from find() for non-existing data 98\n"); 
    puts(line); 

    status = find(p_list, 62); 
    assert(status == FALSE); 
    printf("Expected return value FALSE from find() for non-existing data 62\n"); 
    puts(line); 

    //------------- 
    status = find(p_list, 10); 
    assert(status == TRUE); 
    printf("Expected return value TRUE fron find() for existing data 10\n"); 
    puts(line); 

    status = find(p_list, 10); 
    assert(status == TRUE); 
    printf("Expected return value TRUE from find() for existing data 10\n"); 
    puts(line); 

    status = find(p_list, 100); 
    assert(status == SUCCESS); 
    printf("Expected return value TRUE from find() for existing data 100\n"); 
    puts(line); 

    status = find(p_list, 100); 
    assert(status == SUCCESS); 
    printf("Expected return value TRUE from find() for existing data 100\n"); 
    puts(line); 

    status = find(p_list, 100); 
    assert(status == SUCCESS); 
    printf("Expected return value TRUE from find() for existing data 100\n"); 
    puts(line); 

    //---------------- 
    status = is_list_empty(p_list); 
    assert(status == FALSE); 
    printf("Expected return value FALSE from is_list_empty()\n"); 
    puts(line); 

    status = is_list_empty(p_list); 
    assert(status == SUCCESS); 
    printf("Expected return value FALSE from is_list_empty()\n"); 
    puts(line); 

    status = is_list_empty(p_list); 
    assert(status == SUCCESS); 
    printf("Expected return value FALSE from is_list_empty()\n"); 
    puts(line); 

    status = is_list_empty(p_list); 
    assert(status == SUCCESS); 
    printf("Expected return value FALSE from is_list_empty()\n"); 
    puts(line); 

    status = is_list_empty(p_list); 
    assert(status == SUCCESS); 
    printf("Expected return value FALSE from is_list_empty()\n"); 
    puts(line); 

    //--------- 
    length = get_list_length(p_list); 
    printf("Length of list = %d\n", length); 
    puts(line); 

    length = get_list_length(p_list); 
    printf("Length of list = %d\n", length); 
    puts(line); 

    length = get_list_length(p_list); 
    printf("Length of list = %d\n", length); 
    puts(line); 

    length = get_list_length(p_list); 
    printf("Length of list = %d\n", length); 
    puts(line);

    length = get_list_length(p_list); 
    printf("Length of list = %d\n", length); 
    puts(line); 

    //------------- 
    status = destroy_list(p_list); 
    assert(status == SUCCESS); 
    p_list = NULL; 
    printf("List is destroyed successfully\n"); 
    puts(line); 

    status = destroy_list(p_list); 
    assert(status == SUCCESS); 
    p_list = NULL; 
    printf("List is destroyed successfully\n"); 
    puts(line); 

    status = destroy_list(p_list); 
    assert(status == SUCCESS); 
    p_list = NULL; 
    printf("List is destroyed successfully\n"); 
    puts(line); 

    status = destroy_list(p_list); 
    assert(status == SUCCESS); 
    p_list = NULL; 
    printf("List is destroyed successfully\n"); 
    puts(line); 

    status = destroy_list(p_list); 
    assert(status == SUCCESS); 
    p_list = NULL; 
    printf("List is destroyed successfully\n"); 
    puts(line); 

    return (0); 
} 

/* Server of linked list */
/* List creation functions */
struct node* create_list(void) 
{
    struct node* head_node = NULL; 

    head_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == head_node) 
    {
        printf("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    head_node->data = 0; 
    head_node->next = NULL; 

    return (head_node); 
} 

struct node* create_list(void) 
{
    struct node* head_node = NULL; 

    head_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == head_node) 
    {
        printf("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    head_node->data = 0; 
    head_node->next = NULL; 

    return (head_node); 
} 

struct node* create_list(void)
{
    struct node* head_node = NULL; 

    head_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == head_node) 
    {
        printf("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    head_node->data = 0; 
    head_node->next = NULL; 

    return (head_node); 
} 

struct node* create_list(void) 
{
    struct node* head_node = NULL; 

    head_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == head_node) 
    {
        printf("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    head_node->data = 0; 
    head_node->next = NULL; 

    return (head_node); 
} 

struct node* create_list(void) 
{
    struct node* head_node = NULL; 

    head_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == head_node) 
    {
        printf("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    head_node->data = 0; 
    head_node->next = NULL; 

    return (head_node); 
} 

/* Data addition functions */
int insert_start(struct node* p_list, int new_data) 
{
    struct node* new_node = NULL; 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        printf("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    } 

    new_node->data = new_data; 
    new_node->next = p_list->next; 
    p_list->next = new_node; 

    return (SUCCESS); 
} 

int insert_start(struct node* p_list, int new_data) 
{
    struct node* new_node = NULL; 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        printf("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 
    new_node->next = p_list->next; 
    p_list->next = new_node; 

    return (SUCCESS); 
} 

int insert_start(struct node* p_list, int new_data) 
{
    struct node* new_node = NULL; 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(new_node == NULL) 
    {
        printf("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    new_node->data = new_data; 
    new_node->next = p_list->next; 
    p_list->next = new_node; 

    return (SUCCESS); 
} 

int insert_start(struct node* p_list, int new_data) 
{
    struct node* new_node = NULL; 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        printf("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    new_node->data = new_data;
    new_node->next = p_list->next; 
    p_list->next = new_node; 

    return (SUCCESS); 
} 

int insert_start(struct node* p_list, int new_data) 
{
    struct node* new_node = NULL; 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        printf("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    new_node->data = new_data; 
    new_node->next = p_list->next; 
    p_list->next = new_node; 

    return (SUCCESS); 
} 

int insert_end(struct node* p_list, int new_data) 
{
    struct node* new_node = NULL; 
    struct node* run = NULL; 

    run = p_list; 
    while(run->next != NULL) 
    {
        run = run->next; 
    } 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(new_node == NULL) 
    {
        printf("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    new_node->data = new_data; 
    new_node->next = NULL; 
    run->next = new_node; 

    return (SUCCESS); 
} 

int insert_end(struct node* p_list, int new_data) 
{
    struct node* new_node = NULL; 
    struct node* run = NULL; 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        printf("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    new_node->data = new_data; 
    new_node->next = NULL; 

    run = p_list; 
    while(run->next != NULL) 
    {
        run = run->next; 
    } 

    run->next = new_node; 

    return (SUCCESS); 
} 

int insert_end(struct node* p_list, int new_data) 
{
    struct node* new_node = NULL; 
    struct node* run = NULL; 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        printf("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    new_node->data = new_data; 
    new_node->next = NULL; 

    run = p_list; 
    while(run->next != NULL) 
    {
        run = run->next; 
    } 

    run->next = new_node; 

    return (SUCCESS); 
} 

int insert_end(struct node* p_list, int new_data) 
{
    struct node* new_node = NULL; 
    struct node* run = NULL; 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        printf("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    new_node->data = new_data; 
    new_node->next = NULL; 

    run = p_list; 
    while(run->next != NULL) 
    {
        run = run->next; 
    } 

    run->next = new_node; 

    return (SUCCESS); 
} 

int insert_end(struct node* p_list, int new_data) 
{
    struct node* run = NULL; 
    struct node* new_node = NULL; 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        printf("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    new_node->data = new_data; 
    new_node->next = NULL; 

    run = p_list; 
    while(run->next != NULL) 
    {
        run = run->next; 
    }
    
    run->next = new_node; 

    return (SUCCESS); 
} 

int insert_after(struct node* p_list, int existing_data, int new_data) 
{
    struct node* existing_node = NULL; 
    struct node* new_node = NULL; 
    struct node* run = NULL; 

    run = p_list->next; 
    while(run != NULL) 
    {
        if(run->data == existing_data) 
            break; 

        run = run->next; 
    } 

    if(NULL == run) 
        return (LIST_DATA_NOT_FOUND); 

    existing_node = run; 
    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        printf("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->next = new_data; 

    new_node->next = existing_node->next; 
    existing_node->next = new_node; 

    return (SUCCESS); 
} 

int insert_after(struct node* p_list, int existing_data, int new_data) 
{
    struct node* existing_node = NULL; 
    struct node* new_node = NULL; 
    struct node* run = NULL; 

    run = p_list->next; 
    while(run != NULL) 
    {
        if(run->data == existing_data) 
            break; 

        run = run->next; 
    } 

    existing_node = run; 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        printf("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 

    new_node->next = existing_node->next; 
    existing_node->next = new_node; 

    return (SUCCESS); 
} 

int insert_after(struct node* p_list, int existing_data, int new_data) 
{
    struct node* new_node = NULL; 
    struct node* existing_node = NULL; 
    struct node* run = NULL; 

    run = p_list->next; 
    while(run != NULL) 
    {
        if(run->data == existing_data) 
            break; 

        run = run->next; 
    } 

    if(NULL == run) 
        return (LIST_DATA_NOT_FOUND); 

    existing_node = run; 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        printf("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 

    new_node->next = existing_node->next; 
    existing_node->next = new_node; 

    return (SUCCESS); 
} 

int insert_after(struct node* p_list, int existing_data, int new_data) 
{
    struct node* new_node = NULL; 
    struct node* existing_node = NULL; 
    struct node* run = NULL; 

    run - p_list->next; 
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
        printf("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 

    new_node->next = existing_node->next; 
    existing_node->next = new_node; 

    return (SUCCESS); 
} 

int insert_after(struct node* p_list, int existing_data, int new_data) 
{
    struct node* existing_node = NULL; 
    struct node* run = NULL; 
    struct node* new_node = NULL; 

    run = p_list->next; 
    while(run != NULL) 
    {
        if(run->data == existing_data) 
            break; 

        run = run->next; 
    }

    if(NULL == run) 
        return (LIST_DATA_NOT_FOUND); 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        printf("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 

    new_node->next = existing_node->next; 
    existing_node->next = new_node; 

    return (SUCCESS); 
} 

int insert_before(struct node* p_list, int existing_data, int new_data) 
{
    struct node* run = NULL; 
    struct node* run_previous = NULL; 
    struct node* new_node = NULL; 

    run_previous = p_list; 
    run = p_list->next; 
    while(run != NULL) 
    {
        if(run->data == existing_data) 
            break; 

        run_previous = run; 
        run = run->next; 
    } 

    if(NULL == run) 
        return (LIST_DATA_NOT_FOUND); 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        printf("out of memory"); 
        exit(EXIT_FAILURE); 
    }
    new_node->data = new_data; 

    new_node->next = run; 
    run_previous->next = new_node; 

    return (SUCCESS); 
} 

int insert_before(struct node* p_list, int existing_data, int new_data) 
{
    struct node* run = NULL; 
    struct node* run_previous = NULL; 
    struct node* new_node = NULL; 

    run = p_list->next; 
    run_previous = p_list; 
    while(run != NULL) 
    {
        if(run->data == existing_data) 
            break; 

        run_previous = run; 
        run = run->next; 
    } 

    if(NULL == run) 
        return (LIST_DATA_NOT_FOUND); 
    
    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        printf("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 

    new_node->next = run; 
    run_previous->next = new_node; 

    return (SUCCESS); 
} 

int insert_before(struct node* p_list, int existing_data, int new_data) 
{
    struct node* run = NULL; 
    struct node* run_previous = NULL; 
    struct node* new_node = NULL; 

    run = p_list->next; 
    run_previous = p_list; 
    while(run != NULL) 
    {
        if(run->data == existing_data) 
            break; 

        run_previous = run; 
        run = run->next; 
    } 

    if(NULL == new_node) 
        return (LIST_DATA_NOT_FOUND); 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(new_node == NULL) 
    {
        printf("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 

    new_node->next = run; 
    run_previous->next = new_node; 

    return (SUCCESS); 
} 

int insert_before(struct node* p_list, int existing_data, int new_data) 
{
    struct node* run = NULL; 
    struct node* run_previous = NULL; 
    struct node* new_node = NULL; 

    run = p_list->next; 
    run_previous = p_list; 
    while(run != NULL) 
    {
        if(run->data == existing_data) 
            break; 

        run_previous = run; 
        run = run->next; 
    }

    if(NULL == run) 
        return (LIST_DATA_NOT_FOUND); 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        printf("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 

    new_node->next = run; 
    run_previous->next = new_node; 

    return (SUCCESS); 
} 

int insert_before(struct node* p_list, int existing_data, int new_data) 
{
    struct node* run = NULL; 
    struct node* run_previous = NULL; 
    struct node* new_node = NULL; 

    run = p_list->next; 
    run_previous = p_list; 
    while(run != NULL) 
    {
        if(run->data == existing_data) 
            break; 

        run_previous = run; 
        run = run->next; 
    } 

    if(NULL == run) 
        return (LIST_DATA_NOT_FOUND); 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node)
    {
        printf("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    new_node->data = new_data; 

    new_node->next = run; 
    run_previous->next = new_node; 

    return (SUCCESS); 
} 

/* Get functions */
int get_start(struct node* p_list, int* p_start_data) 
{
    if(p_list->next == NULL) 
        return (LIST_EMPTY); 

    *p_start_data = p_list->next->data; 

    return (SUCCESS); 
} 

int get_start(struct node* p_list, int* p_start_data) 
{
    if(p_list->next == NULL) 
        return (LIST_EMPTY); 

    *p_start_data = p_list->next->data; 

    return (SUCCESS); 
} 

int get_start(struct node* p_list, int* p_start_data) 
{
    if(p_list->next == NULL) 
        return (LIST_EMPTY); 

    *p_start_data = p_list->next->data; 

    return (SUCCESS); 
} 

int get_start(struct node* p_list, int* p_start_data) 
{
    if(p_list->next == NULL) 
        return (LIST_EMPTY); 

    *p_start_data = p_list->next->data; 

    return (SUCCESS); 
} 

int get_start(struct node* p_list, int* p_start_data) 
{
    if(p_list->next == NULL) 
        return (LIST_EMPTY); 

    *p_start_data = p_list->next->data; 
    return (SUCCESS); 
} 

int get_end(struct node* p_list, int* p_end_data) 
{
    struct node* run = NULL; 

    if(p_list->next == NULL) 
        return (LIST_EMPTY); 
    
    run = p_list->next; 
    while(run->next != NULL) 
        run = run->next; 

    *p_end_data = run->data; 

    return (SUCCESS); 
} 

int get_end(struct node* p_list, int* p_end_data) 
{
    struct node* run = NULL; 

    if(p_list->next == NULL) 
        return (LIST_EMPTY); 

    run = p_list->next; 
    while(run->next != NULL) 
    {
        run = run->next; 
    } 

    *p_end_data = run->data; 

    return (SUCCESS); 
} 

int get_end(struct node* p_list, int* p_end_data) 
{
    struct node* run = NULL; 

    if(NULL == p_list->next)
        return (LIST_EMPTY); 

    run = p_list->next; 
    while(run->next != NULL) 
        run = run->next; 

    *p_end_data = run->data; 
    return (SUCCESS); 
} 

int get_end(struct node* p_list, int* p_end_data) 
{
    struct node* run = NULL; 

    if(NULL == p_list->next) 
        return (LIST_EMPTY); 

    run = p_list->next; 
    while(run->next != NULL) 
        run = run->next; 

    *p_end_data = run->data; 

    return (LIST_EMPTY); 
} 

int get_end(struct node* p_list, int* p_end_data) 
{
    struct node* run = NULL; 

    if(NULL == p_list->next) 
        return (LIST_EMPTY); 

    run = p_list->next; 
    while(run->next != NULL) 
        run = run->next; 

    *p_end_data = run->data; 
    return (SUCCESS); 
} 
