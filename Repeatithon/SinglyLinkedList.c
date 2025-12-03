#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <assert.h> 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <assert.h> 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include <string.h> 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <assert.h> 

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

#define SUCCESS     1 
#define TRUE        1 
#define FALSE       0 
#define LIST_DATA_NOT_FOUND 2 
#define LIST_EMPTY  3 

#define SUCCESS     1 
#define TRUE        1 
#define FALSE       0 
#define LIST_DATA_NOT_FOUND 2 
#define LIST_EMPTY  3 

#define SUCCESS     1 
#define TRUE        1 
#define FALSE       0 
#define LIST_DATA_NOT_FOUND 2 
#define LIST_EMPTY  3 

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

/* interface function declarations */
/* List creation functions */
struct node* create_list(void); 

/* data addition functions */
int insert_start(struct node* p_list, int new_data); 
int insert_end(struct node* p_list, int new_data); 
int insert_after(struct node* p_list, int existing_data, int new_data); 
int insert_before(struct node* p_list, int existing_data, int new_data); 

// get functions 
int get_start(struct node* p_list, int* p_start_data); 
int get_end(struct node* p_list, int* p_end_data); 

/* pop functions */
int pop_start(struct node* p_list, int* p_start_data); 
int pop_end(struct node* p_list, int* p_end_data); 

/* Remove functions */
int remove_start(struct node* p_list); 
int remove_end(struct node* p_list); 
int remove_data(struct node* p_list, int r_data); 

/* miscalleneous functions */
int find(struct node* p_list, int f_data);  
int get_list_length(struct node* p_list); 
int is_list_empty(struct node* p_list); 
void show_list(struct node* p_list, const char* msg); 

/* List destruction function */
int destroy_list(struct node* p_list); 

// 2
/* List interface functions */
/* List creation function */
struct node* create_list(void); 

/* Data insertion function */
int insert_start(struct node* p_list, int new_data); 
int insert_end(struct node* p_list, int new_data); 
int insert_after(struct node* p_list, int existing_data, int new_data); 
int insert_before(struct node* p_list, int existing_data, int new_data); 

/* get functions */
int get_start(struct node* p_list, int* p_start_data); 
int get_end(struct node* p_list, int* p_end_data); 

/* pop functions */
int pop_start(struct node* p_list, int* p_start_data); 
int pop_end(struct node* p_list, int* p_end_data); 

/* remove functions */
int remove_start(struct node* p_list); 
int remove_end(struct node* p_list); 
int remove_data(struct node* p_list, int r_data); 

/* miscalleneous functions */
int get_list_length(struct node* p_list); 
int is_list_empty(struct node* p_list); 
int find(struct node* p_list, int f_data); 
void show_list(struct node* p_list, const char* msg); 

/* List destruction functions */
int destroy_list(struct node* p_list); 

// 3 
/* List interface functions */
/* list creation function */
struct node* create_list(void); 

/* data addition functions */
int insert_start(struct node* p_list, int new_data); 
int insert_end(struct node* p_list, int new_data); 
int insert_after(struct node* p_list, int existing_data, int new_data); 
int insert_before(struct node* p_list, int existing_data, int new_data); 

/* get functions */
int get_start(struct node* p_list, int* p_start_data); 
int get_end(struct node* p_list, int* p_end_data); 

/* remove functions */
int remove_start(struct node* p_list); 
int remove_end(struct node* p_list); 
int remove_data(struct node* p_list, int r_data); 

/* pop functions */
int pop_start(struct node* p_list, int* p_start_data); 
int pop_end(struct node* p_list, int* p_end_data); 

/* Miscalleneous function */
int get_list_length(struct node* p_list); 
int is_list_empty(struct node* p_list); 
int find(struct node* p_list, int f_data); 
void show_list(struct node* p_list, const char* msg); 

/* List destruction functions */
int destroy_list(struct node* p_list); 

// 4 
/* List interface routines */
/* List creation functions */
struct node* create_list(void); 

/* List addition functions */
int insert_start(struct node* p_list, int new_data); 
int insert_end(struct node* p_list, int new_data); 
int insert_after(struct node* p_list, int existing_data, int new_data); 
int insert_before(struct node* p_list, int existing_data, int new_data); 

/* get functions */
int get_start(struct node* p_list, int* p_start_data); 
int get_end(struct node* p_list, int* p_end_data); 

/* pop functions */
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
 
// 5 
/* List interface functions */
/* list creation functions */ 
struct node* create_list(void); 

/* data insertion function */
int insert_start(struct node* p_list, int new_data); 
int insert_end(struct node* p_list, int new_data); 
int insert_after(struct node* p_list, int existing_data, int new_data); 
int insert_before(struct node* p_list, int existing_data, int new_data); 

/* get functions */
int get_start(struct node* p_list, int* p_start_data); 
int get_end(struct node* p_list, int* p_end_data); 

/* Pop functions */
int pop_start(struct node* p_list, int* p_start_data); 
int pop_end(struct node* p_list, int* p_end_data); 

/* remove functions */
int remove_start(struct node* p_list); 
int remove_end(struct node* p_list); 
int remove_data(struct node* p_list, int r_data); 

/* Miscalleneous functions */
int find(struct node* p_list, int f_data); 
int get_list_length(struct node* p_list); 
int is_list_empty(struct node* p_list); 
void show_list(struct node* p_list, const char* msg); 

/* List destruction function */
int destroy_list(struct node* p_list); 

/* SERVER IMPLEMENTATION */
struct node* create_list(void) 
{
    struct node* p_new_list = NULL; 

    p_new_list = (struct node*)malloc(sizeof(struct node)); 
    if(p_new_list == NULL) 
    {
        printf("Out of memory"); 
        exit(EXIT_FAILURE); 
    }   
    p_new_list->next = NULL; 
    p_new_list->data = 0; 

    return (p_new_list); 
} 

struct node* create_list(void) 
{
    struct node* p_new_list = NULL; 

    p_new_list = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_new_list) 
    {
        fprintf(stderr, "Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    p_new_list->next = NULL; 
    p_new_list->data = 0; 

    return (p_new_list); 
} 

struct node* create_list(void) 
{
    struct node* p_new_list = NULL; 

    p_new_list = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_new_list) 
    {
        fprintf(stderr, "Out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_list->data = 0; 
    p_new_list->next = NULL; 

    return (p_new_list); 
} 

struct node* create_list(void) 
{
    struct node* p_new_list = NULL; 

    p_new_list = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_new_list) 
    {
        fprintf(stderr, "Out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_list->data = 0; 
    p_new_list->next = NULL; 

    return (p_new_list); 
} 

struct node* create_list(void) 
{
    struct node* p_new_list = NULL; 

    p_new_list = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_new_list) 
    {
        fprintf(stderr, "Out of memory"); 
        exit(EXIT_FAILURE); 
    }
    p_new_list->next = NULL; 
    p_new_list->data = 0; 
    
    return (p_new_list); 
} 

struct node* create_list(void) 
{
    struct node* p_new_list = NULL; 

    p_new_list = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_new_list) 
    {
        fprintf(stderr, "Out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_list->next = NULL; 
    p_new_list->data = 0; 

    return (p_new_list); 
} 

/* Data insertion functions */
int insert_start(struct node* p_list, int new_data) 
{
    struct node* new_node = NULL; 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(new_node == NULL) 
    {
        fprintf(stderr, "Out of memory"); 
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
        fprintf(stderr, "Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    new_node->data = new_data; 
    new_node->next = p_list->next; 
    p_list->next = p_list; 

    return (SUCCESS); 
} 

int insert_start(struct node* p_list, int new_data) 
{
    struct node* new_node = NULL; 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        fprintf(stderr, "Out of memory"); 
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
        fprintf(stderr, "Out of memory"); 
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
        fprintf(stderr, "Out of memory"); 
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
        fprintf(stderr, "Out of memory"); 
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

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        fprintf(stderr, "Out of memory"); 
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
        fprintf(stderr, "Out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 
    new_node->next = NULL; 

    run = p_list; 
    while(run->next != NULL) 
        run = run->next; 

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
        fprintf(stderr, "Out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 
    new_node->next = NULL; 

    run = p_list; 
    while(run->next != NULL) 
        run = run->next; 

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
        fprintf(stderr, "Out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = 0; 
    new_node->next = NULL; 

    run = p_list; 
    while(run->next != NULL) 
        run = run->next; 

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
        fprintf(stderr, "Out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 
    new_node->next = NULL; 

    run = p_list; 
    while(run->next != NULL) 
        run = run->next; 

    run->next = new_node; 

    return (SUCCESS); 
} 

int insert_after(struct node* p_list, int existing_data, int new_data) 
{
    struct node* run = NULL; 
    struct node* new_node = NULL; 

    run = p_list->next; 
    while(run != NULL) 
    {
        if(run->data == existing_data) 
        {
            new_node = (struct node*)malloc(sizeof(struct node)); 
            if(new_node == NULL) 
            {
                fprintf(stderr, "Out of memory"); 
                exit(EXIT_FAILURE); 
            } 
            new_node->data = new_data; 
            new_node->next = run->next; 
            run->next = new_node; 

            return (SUCCESS); 
        } 

        run = run->next; 
    }   
    
    return (LIST_DATA_NOT_FOUND); 
} 

int insert_after(struct node* p_list, int existing_data, int new_data) 
{
    struct node* run = NULL; 
    struct node* new_node = NULL; 

    run = p_list->next; 
    while(run != NULL) 
    {
        if(run->data == existing_data) 
        {
            new_node = (struct node*)malloc(sizeof(struct node)); 
            if(new_node == NULL) 
            {
                fprintf(stderr, "Out of memory"); 
                exit(EXIT_FAILURE); 
            } 
            new_node->data = new_data; 
            new_node->next = run->next; 
            run->next = new_node; 

            return (SUCCESS); 
        } 

        run = run->next; 
    } 

    return (LIST_DATA_NOT_FOUND); 
} 

int insert_after(struct node* p_list, int existing_data, int new_data) 
{
    struct node* run = NULL; 
    struct node* new_node = NULL; 

    run = p_list->next; 
    while(run != NULL) 
    {
        if(run->data == existing_data)
        {
            new_node = (struct node*)malloc(sizeof(struct node)); 
            if(new_node == NULL) 
            {
                fprintf(stderr, "Out of memory"); 
                exit(EXIT_FAILURE); 
            } 

            new_node->data = existing_data; 
            new_node->next = run->next; 
            run->next = new_node; 

            return (SUCCESS); 
        }

        run = run->next; 
    } 

    return (LIST_DATA_NOT_FOUND); 
} 

int insert_after(struct node* p_list, int existing_data, int new_data) 
{
    struct node* run = NULL; 
    struct node* new_node = NULL; 

    run = p_list->next; 
    while(run != NULL) 
    {
        if(run->data == existing_data) 
        {
            new_node = (struct node*)malloc(sizeof(struct node)); 
            if(new_node == NULL) 
            {
                fprintf(stderr, "Out of memory"); 
                exit(EXIT_FAILURE); 
            } 
            new_node->data = new_data; 
            new_node->next = run->next; 
            run->next = new_node; 

            return (SUCCESS); 
        }

        run = run->next; 
    } 

    return (LIST_DATA_NOT_FOUND); 
} 

int insert_after(struct node* p_list, int existing_data, int new_data) 
{
    struct node* run = NULL; 
    struct node* new_node = NULL; 

    run = p_list->next; 
    while(run != NULL) 
    {
        if(run->data == existing_data) 
        {
            new_node = (struct node*)malloc(sizeof(struct node)); 
            if(NULL == new_node) 
            {
                fprintf(stderr, "Out of memory"); 
                exit(EXIT_FAILURE); 
            } 

            new_node->data = new_data; 
            new_node->next = run->next; 
            run->next = new_node; 

            return (SUCCESS); 
        }

        run = run->next; 
    } 
    
    return (LIST_DATA_NOT_FOUND); 
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
        fprintf(stderr, "Out of memory"); 
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

    run_previous = p_list; 
    run = p_list->next; 
    while(run != NULL) 
    {
        if(run->data == existing_data) 
            break; 

        run_previous = run; 
        run = run->next; 
    } 
    if(run == NULL) 
        return (LIST_DATA_NOT_FOUND); 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        fprintf(stderr, "Out of memory"); 
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
    if(new_node == NULL) 
    {
        fprintf(stderr, "Out of memory"); 
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

    new_node->next = run; 
    run_previous->next = new_node; 
    
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
        fprintf(stderr, "Out of memory"); 
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
    if (p_list->next == NULL) 
        return (LIST_EMPTY); 

    *p_start_data = p_list->next->data; 
    return (SUCCESS); 
} 

int get_end(struct node* p_list, int* p_end_data) 
{
    struct node* run = NULL; 

    if(run->next == NULL)
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
        run = run->next; 

    *p_end_data = run->data; 
    return (SUCCESS); 
} 

int pop_start(struct node* p_list, int* p_start_data) 
{
    struct node* delete_previous = NULL; 
    struct node* delete_next = NULL; 
    struct node* delete_node = NULL; 

    if(p_list->next == NULL) 
        return (LIST_EMPTY); 

    *p_start_data = p_list->next->data; 

    delete_previous = p_list; 
    delete_node = p_list->next; 
    delete_next = p_list->next->next; 

    delete_previous->next = delete_next; 
    delete(delete_node); 
    delete_node = NULL; 

    return (SUCCESS); 
} 

int pop_start(struct node* p_list, int* p_start_data) 
{
    struct node* delete_previous = NULL; 
    struct node* delete_node = NULL; 
    struct node* delete_next = NULL; 

    if(p_list->next == NULL) 
        return (LIST_EMPTY); 

    *p_start_data = p_list->next->data; 

    delete_previous = p_list; 
    delete_node = p_list->next; 
    delete_next = p_list->next->next; 

    delete_previous->next = delete_next; 
    free(delete_node); 
    delete_node = NULL; 

    return (SUCCESS); 
} 

int pop_start(struct node* p_list, int* p_start_data) 
{
    struct node* delete_previous = NULL; 
    struct node* delete_node = NULL; 
    struct node* delete_next = NULL; 

    if(p_list->next == NULL) 
        return (LIST_EMPTY); 

    *p_start_data = p_list->next->data; 

    delete_previous = p_list; 
    delete_node = p_list->next; 
    delete_next = p_list->next->next; 

    delete_previous->next = delete_next; 
    free(delete_node); 
    delete_node = NULL; 

    return (SUCCESS); 
} 

int pop_start(struct node* p_list, int* p_start_data) 
{
    struct node* delete_previous = NULL; 
    struct node* delete_node = NULL; 
    struct node* delete_next = NULL; 

    if(p_list->next == NULL) 
        return (LIST_EMPTY); 

    *p_start_data = p_list->next->data; 

    delete_previous = p_list; 
    delete_node = p_list->next; 
    delete_next = p_list->next->next; 

    delete_previous->next = delete_next; 
    free(delete_node); 
    delete_node = NULL; 

    return (SUCCESS); 
} 

int pop_start(struct node* p_list, int* p_start_data) 
{
    struct node* delete_previous = NULL; 
    struct node* delete_node = NULL; 
    struct node* delete_next = NULL; 

    if(p_list->next == NULL) 
        return (LIST_EMPTY); 

    *p_start_data = p_list->next->data; 

    delete_previous = p_list; 
    delete_node = p_list->next; 
    delete_next = p_list->next->next; 

    delete_previous->next = delete_next; 
    free(delete_node); 
    delete_node = NULL; 

    return (SUCCESS); 
} 

int pop_start(struct node* p_list, int* p_start_data) 
{
    struct node* delete_previous = NULL; 
    struct node* delete_node = NULL; 
    struct node* delete_next = NULL; 

    if(p_list->next == NULL) 
        return (LIST_EMPTY); 

    *p_start_data = p_list->next->data; 

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

    if(p_list->next == NULL) 
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

int pop_end(struct node* p_list, int* p_end_data) 
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

    *p_end_data = run->data; 

    free(run); 
    run = NULL; 
    run_previous->next = NULL; 

    return (SUCCESS); 
} 

int pop_end(struct node* p_list, int* p_end_data) 
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

    *p_end_data = run->data; 
    
    free(run); 
    run = NULL; 
    run_previous->next = NULL; 
    return (SUCCESS); 
} 

int pop_end(struct node* p_list, int* p_end_data) 
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

    *p_end_data = run->data; 

    free(run); 
    run = NULL; 
    run_previous->next = NULL; 

    return (SUCCESS); 
} 

int pop_end(struct node* p_list, int* p_end_data) 
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

    *p_end_data = run->data; 

    free(run); 
    run = NULL; 
    run_previous = NULL; 

    return (SUCCESS); 
} 

/* Remove functions */
int remove_start(struct node* p_list)
{
    struct node* delete_previous = NULL; 
    struct node* delete_node = NULL; 
    struct node* delete_next = NULL; 

    if(p_list->next == NULL) 
        return (LIST_EMPTY); 

    delete_node = p_list->next; 
    delete_previous = p_list; 
    delete_next = p_list->next->next; 

    delete_node->next = delete_next; 

    free(delete_node); 
    delete_node = NULL; 

    return (SUCCESS); 
} 

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

    return (LIST_EMPTY); 
} 

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

int remove_end(struct node* p_list) 
{
    struct node* run_previous = NULL; 
    struct node* run = NULL; 

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

    if(NULL == run) 
        return (LIST_DATA_NOT_FOUND); 

    run_previous->next = run->next; 
    free(run); 
    run = NULL; 

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

    if(NULL == run) 
        return (LIST_DATA_NOT_FOUND); 

    run_previous->next = run->next; 

    free(run); 
    run = NULL; 

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

    if(NULL == run) 
        return (LIST_DATA_NOT_FOUND); 

    run_previous->next = run->next; 
    free(run); 
    run = NULL; 

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

    if(NULL == run) 
        return (LIST_DATA_NOT_FOUND); 

    run_previous->next = run->next; 
    free(run); 
    run = NULL; 

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

    if(NULL == run) 
        return (LIST_DATA_NOT_FOUND); 

    run_previous->next = run->next; 
    free(run); 
    run = NULL;
    
    return (SUCCESS); 
} 

/* Miscalleneous Functions */
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
    struct node* run = NULL; 
    size_t len = 0; 

    run = p_list->next; 
    while(run != NULL) 
    {
        len = len + 1; 
        run = run->next; 
    }

    return (len); 
} 

int get_list_length(struct node* p_list) 
{
    struct node* run = NULL; 
    size_t len = 0; 

    run = p_list->next; 
    while(run != NULL) 
    { 
        len = len + 1; 
        run = run->next; 
    }

    return (len); 
} 

int get_list_length(struct node* p_list) 
{
    struct node* run = NULL; 
    size_t len = 0; 

    run = p_list->next; 
    while(run != NULL) 
    {
        len = len + 1; 
        run = run->next; 
    } 

    return (len); 
} 

int get_list_length(struct node* p_list) 
{
    struct node* run = NULL; 
    size_t len = 0; 

    run = p_list->next; 
    while(run != NULL) 
    {
        len = len + 1; 
        run = run->next; 
    }

    return (len); 
} 

int get_list_length(struct node* p_list) 
{
    struct node* run = NULL; 
    size_t len = 0; 

    run = p_list->next; 
    while(run != NULL) 
    {
        len = len + 1; 
        run = run->next; 
    }

    return (len); 
} 

int is_list_empty(struct node* p_list) 
{
    return (p_list->next == NULL); 
} 

int is_list_empty(struct node* p_list) 
{
    return (p_list->next == NULL); 
} 

int is_list_empty(struct node* p_list) 
{
    return (p_list->next == NULL); 
}

int is_list_empty(struct node* p_list) 
{
    return (p_list->next == NULL); 
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

    printf("[START]->"); 
    run = p_list->next; 
    while(run != NULL) 
    {
        printf("[%d]->", run->data); 
        run = run->next; 
    } 
    printf("[END]\n"); 
}

void show_list(struct node* p_list, const char* msg) 
{
    struct node* run = NULL; 

    if(msg) 
        puts(msg); 

    printf("[START]->"); 
    run = p_list->next; 
    while(run != NULL) 
    {
        printf("[%d]->", run->data); 
        run = run->next; 
    } 
    printf("[END]"); 
} 

void show_list(struct node* p_list, const char* msg) 
{
    struct node* run = NULL; 

    if(msg) 
        puts(msg); 

    printf("[START]->"); 
    run = p_list->next; 
    while(run != NULL) 
    {
        printf("[%d]->", run->data); 
        run = run->next; 
    }
    printf("[END]\n"); 
} 

void show_list(struct node* p_list, const char* msg) 
{ 
    struct node* run = NULL; 

    if(msg) 
        puts(msg); 

    printf("[START]->"); 
    run = p_list->next; 
    while(run != NULL) 
    {
        printf("[%d]->", run->data); 
        run = run->next; 
    } 
    printf("[END]\n"); 
}

void show_list(struct node* p_list, const char* msg) 
{
    struct node* run = NULL; 

    printf("[START]->"); 
    run = p_list->next; 
    while(run != NULL) 
    {
        printf("[%d]->", run->data); 
        run = run->next; 
    } 
    printf("[END]\n"); 
} 

/* List destruction functions */
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

