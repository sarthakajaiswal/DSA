#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <assert.h> 

// node layout definition 
struct node 
{
    int data; 
    struct node* prev; 
    struct node* next; 
}; 

// interface function declarations 
int insert_start(struct node* head_node, int new_data); 
int insert_end(struct node* head_node, int new_data); 
int insert_before(struct node* head_node, int existing_data, int new_data); 
int insert_after(struct node* head_node, int existing_data, int new_data); 

// get and pop functions 
int get_start(struct node* head_node, int* p_start_data); 
int get_end(struct node* head_node, int* p_end_data); 

int pop_start(struct node* head_node, int* p_start_data); 
int pop_end(struct node* head_node, int* p_end_data); 

// remove functions 
int remove_start(struct node* head_node); 
int remove_end(struct node* head_node); 
int remove_data(struct node* head_node, int r_data); 

// miscalleneous functions 
int find(struct node* head_node, int search_data); 
int get_list_length(struct node* head_node); 
int is_list_empty(struct node* head_node); 
void show(struct node* head_node, const char* msg); 

// list destruction function 
int destroy_list(struct node* head_node); 

// 2 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <assert.h> 

// node layout definition 
struct node 
{
    int data; 
    struct node* prev; 
    struct node* next; 
};  

// interface function delarations 
// create list function 
struct node* create_list(void); 

// data insertion functions 
int insert_start(struct node* head_node, int new_data); 
int insert_end(struct node* head_node, int new_data); 
int insert_after(struct node* head_node, int existing_data, int new_data); 
int insert_before(struct node* head_node, int existing_data, int new_data); 

// getters 
int get_start(struct node* head_node, int* p_start_data); 
int get_end(struct node* head_node, int* p_end_data); 

// pop and remove functions 
int pop_start(struct node* head_node, int* p_popped_data); 
int pop_end(struct node* head_node, int* p_popped_data); 

int remove_start(struct node* head_node); 
int remove_end(struct node* head_node); 
int remove_data(struct node* head_node, int r_data); 

// miscalleneous functions 
int find(struct node* head_node, int f_data); 
int is_list_empty(struct node* head_node); 
int get_list_length(struct node* head_node); 
void show_list(struct node* head_node, const char* msg); 

// list destroy functions 
int destroy_list(struct node* head_node); 

// 3 
#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include <string.h> 

// node layout definition 
struct node 
{
    int data; 
    struct node* prev; 
    struct node* next; 
}; 

// interface function declarations 
// list creation function 
struct node* create_list(void); 

// data insertion function 
int insert_start(struct node* head_node, int new_data); 
int insert_end(struct node* head_node, int new_data); 
int insert_before(struct node* head_node, int existing_data, int new_data); 
int insert_after(struct node* head_node, int existing_data, int new_data); 

// getters 
int get_start(struct node* head_node, int* p_start_data); 
int get_end(struct node* head_node, int* p_end_data); 

// pop and remove function 
int pop_start(struct node* head_node, int* p_popped_data); 
int pop_end(struct node* head_node, int* p_popped_data); 

int remove_start(struct node* head_node); 
int remove_end(struct node* head_node); 
int remove_data(struct node* head_node, int r_data); 

// list destruction function 
int destroy_list(struct node* head_node); 

// 4 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <assert.h> 

// node layout definition 
struct node 
{
    int data; 
    struct node* prev; 
    struct node* next; 
}; 

// interface function declarations 
// list creation function 
struct node* create_list(void); 

// data insertion functions 
int insert_start(struct node* head_node, int new_data); 
int insert_end(struct node* head_node, int new_data); 
int insert_after(struct node* head_node, int existing_data, int new_data); 
int insert_before(struct node* head_node, int existing_data, int new_data); 

// getters 
int get_start(struct node* head_node, int* p_start_data); 
int get_end(struct node* head_node, int* p_end_data); 

// pop and remove functions 
int pop_start(struct node* head_node, int* p_popped_data); 
int pop_end(struct node* head_node, int* p_popped_data); 

int remove_start(struct node* head_node); 
int remove_end(struct node* head_node); 
int remove_data(struct node* head_node, int r_data); 

// miscalleneuos functions 
int find(struct node* head_node, int f_data); 
int is_list_empty(struct node* head_node); 
int get_list_length(struct node* head_node); 
void show_list(struct node* head_node); 

// list destruction function 
int destroy_list(struct node* head_node); 

// 5 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <assert.h> 

// node layout definition 
struct node 
{
    int data; 
    struct node* prev; 
    struct node* next; 
}; 

// interface function declarations 
// list creation function 
struct node* create_list(void); 

// data insertion functions 
int insert_start(struct node* head_node, int new_data); 
int insert_end(struct node* head_node, int new_data); 
int insert_before(struct node* head_node, int existing_data, int new_data); 
int insert_after(struct node* head_node, int existing_data, int new_data); 

// getters 
int get_start(struct node* head_node, int* p_start_data); 
int get_end(struct node*, int*); 

// pop and remove functions 
int pop_start(struct node*, int*); 
int pop_end(struct node*, int*); 

int remove_start(struct node* head_node); 
int remove_end(struct node* head_node); 
int remove_data(struct node* head_node, int r_data); 

// miscalleneous function 
int find(struct node* head_node, int f_data); 
int get_list_length(struct node* head_node); 
int is_list_empty(struct node* head_node); 
void show_list(struct node* head_node, const char* msg); 

// list destruction function 
int destroy_list(struct node* head_node); 

// definitions 
struct node* create_list(void) 
{
    struct node* p_list = NULL; 
    
    p_list = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_list) 
    { 
        fprintf(stderr, "create_list():malloc(): memory allocation failed\n"); 
        exit(EXIT_FAILURE); 
    } 
    p_list->next = NULL; 
    p_list->prev = NULL; 
    p_list->data = 0; 

    return (p_list); 
} 

struct node* create_list(void) 
{
    struct node* p_list = NULL; 

    p_list = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_list) 
    {
        fprintf(stderr, "create_list():malloc(): memory allocation failure\n"); 
        exit(EXIT_FAILURE); 
    } 
    p_list->data = 0; 
    p_list->prev = NULL; 
    p_list->next = NULL; 

    return (p_list); 
} 

struct node* create_list(void) 
{
    struct node* p_list = NULL; 

    p_list = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_list)
    {
        fprintf(stderr, "create_list():malloc(): error in allocating memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    p_list->data = 0; 
    p_list->next = NULL; 
    p_list->prev = NULL; 

    return (p_list); 
} 

struct node* create_list(void) 
{
    struct node* p_list = NULL; 

    p_list = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_list) 
    {
        fprintf(stderr, "create_list(): malloc() > memory allocation failure\n"); 
        exit(EXIT_FAILURE); 
    } 
    p_list->data = 0; 
    p_list->next = NULL; 
    p_list->prev = NULL; 

    return (p_list); 
} 

struct node* create_list(void) 
{
    struct node* p_list = NULL; 

    p_list = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_list) 
    {
        fprintf(stderr, "create_list():malloc() > memory allocation failure\n"); 
        exit(EXIT_FAILURE); 
    } 
    p_list->next = NULL; 
    p_list->prev = NULL; 
    p_list->data = 0; 

    return (p_list); 
} 

int insert_start(struct node* head_node, int new_data) 
{
    struct node* new_node = NULL; 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        fprintf(stderr, "insert_start():malloc() > memory allocation failure\n"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 

    new_node->next = head_node->next; 
    new_node->prev = head_node; 

    if(head_node->next != NULL) 
        head_node->next->prev = new_node;
    head_node->next = new_node; 

    return (1); 
} 

int insert_start(struct node* head_node, int new_data) 
{
    struct node* new_node = NULL; 
    
    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        fprintf(stderr, "insert_start():malloc():memory allcation failure\n"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 
    
    new_node->next = head_node->next; 
    new_node->prev = head_node; 

    if(head_node->next != NULL) 
        head_node->next->prev = new_node; 
    head_node->next = new_node; 

    return (1); 
} 

int insert_start(struct node* head_node, int new_data) 
{
    struct node* new_node = NULL; 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        fprintf(stderr, "insert_start():malloc(): memory allocation failure\n"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 

    new_node->next = head_node->next; 
    new_node->prev = head_node; 
    if(head_node->next != NULL) 
        head_node->next->prev = new_node;
    head_node->next = new_node; 

    return (1); 
} 

int insert_start(struct node* head_node, int new_data) 
{
    struct node* new_node = NULL; 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        fprintf(stderr, "insert_start():malloc(): failed to allocate memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 

    new_node->next = head_node->next; 
    new_node->prev = head_node; 
    if(head_node->next != NULL) 
        head_node->next->prev = new_node; 
    head_node->next = new_node; 

    return (1); 
} 

int insert_start(struct node* head_node, int new_data) 
{
    struct node* new_node = NULL; 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        fprintf(stderr, "insert_start():malloc():memory allocation failure\n"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 

    new_node->next = head_node->next; 
    new_node->prev = head_node; 
    if(head_node->next != NULL) 
        head_node->next->prev = new_node; 
    head_node->next = new_node; 

    return (1); 
} 

int insert_end(struct node* head_node, int new_data) 
{
    struct node* run = NULL; 
    struct node* new_node = NULL; 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        fprintf(stderr, "insert_end():malloc() > failed to allocate memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 
    new_node->next = NULL; 
    new_node->prev = NULL; 

    run = head_node; 
    while(run->next != NULL) 
        run = run->next; 

    new_node->next = run->next; 
    new_node->prev = run; 
    run->next = new_node; 

    return (1); 
} 

int insert_end(struct node* head_node, int new_data) 
{
    struct node* new_node = NULL; 
    struct node* run = NULL; 

    run = head_node; 
    while(run->next != NULL) 
        run = run->next; 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        fprintf(stderr, "insert_end():malloc(): memory allocation failure\n"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 

    new_node->prev = run; 
    new_node->next = run->next; 
    run->next = new_node; 

    return (1); 
} 

int insert_end(struct node* head_node, int new_data) 
{
    struct node* run = NULL; 
    struct node* new_node = NULL; 

    run = head_node; 
    while(run->next != NULL) 
        run = run->next; 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        fprintf(stderr, "insert_end():malloc(): memory allocation failure\n"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 
    
    new_node->next = run->next; 
    new_node->prev = run; 
    run->next = new_node; 

    return (1); 
} 

int insert_end(struct node* head_node, int new_data) 
{
    struct node* run = NULL; 
    struct node* new_node = NULL; 

    run = head_node; 
    while(run->next != NULL) 
        run = run->next; 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        fprintf(stderr, "insert_end():malloc():memory allocation failure\n"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 

    new_node->next = run->next; 
    new_node->prev = run; 
    run->next = new_node; 

    return (1); 
}  

int insert_end(struct node* head_node, int new_data) 
{
    struct node* new_node = NULL; 
    struct node* run = NULL; 

    run = head_node; 
    while(run->next != NULL) 
        run = run->next; 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        fprintf(stderr, "insert_end():malloc(): memory allocation failure\n"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 

    new_node->next = run->next; 
    new_node->prev = run; 
    run->next = new_node; 

    return (1); 
} 

int insert_before(struct node* head_node, int existing_data, int new_data) 
{
    struct node* new_node = NULL; 
    struct node* run = NULL; 
    struct node* existing_node = NULL; 

    run = head_node->next; 
    while(run != NULL) 
    {
        if(run->data == existing_data) 
            break; 

        run=run->next; 
    } 

    if(run == NULL) 
        return (2); 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        fprintf(stderr, "insert_before():malloc(): memory allocation failure\n"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 

    new_node->next = run->next; 
    new_node->prev = run; 
    run->next = new_node; 

    return (1); 
} 

int insert_before(struct node* head_node, int existing_data, int new_data) 
{
    struct node* new_node = NULL; 
    struct node* run = NULL; 
    struct node* existing_node = NULL; 

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
        fprintf(stderr, "insert_before():malloc():memory allocation failure\n"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 

    new_node->next = run; 
    new_node->prev = run->prev; 
    run->prev->next = new_node; 
    run->prev = new_node; 

    return (1); 
} 

int insert_before(struct node* head_node, int existing_data, int new_data) 
{
    struct node* new_node = NULL; 
    struct node* run = NULL; 
    struct node* existing_node = NULL; 

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
        fprintf(stderr, "insert_before():malloc():memory allocation failure\n"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 

    new_node->prev = existing_node->prev; 
    new_node->next = existing_node; 
    existing_node->prev->next = new_node; 
    existing_node->next = new_node; 

    return (1); 
} 

int insert_before(struct node* head_node, int existing_data, int new_data) 
{
    struct node* new_node = NULL; 
    struct node* run = NULL; 
    struct node* existing_node = NULL; 

    run = head_node->next; 
    while(run != NULL) 
    {
        if(run->data == existing_data) 
            break; 
        run = run->next; 
    } 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        fprintf(stderr, "insert_before():malloc(): error in allocating memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 

    new_node->next = existing_node; 
    new_node->prev = existing_node->prev; 
    existing_node->prev->next = new_node; 
    existing_node->prev = new_node; 

    return (1); 
} 

int insert_before(struct node* head_node, int existing_data, int new_data) 
{
    struct node* new_node = NULL; 
    struct node* run = NULL; 
    struct node* existing_node = NULL; 

    run = head_node; 
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
        fprintf(stderr, "insert_before(): malloc(): memory allocation failure\n"); 
        exit(EXIT_FAILURE); 
    } 

    new_node->data = new_data; 
    new_node->next = existing_node; 
    new_node->prev = existing_node->prev; 
    existing_node->prev->next = new_node; 
    existing_node->prev = new_node; 

    return (1); 
} 

int insert_after(struct node* head_node, int existing_data, int new_data) 
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

    if(NULL == run) 
        return (2); 

    existing_node = run; 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        fprintf(stderr, "insert_after(): malloc(): memory allocation failure\n"); 
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

int insert_after(struct node* head_node, int existing_data, int new_data) 
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

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        fprintf(stderr, "insert_after():malloc(): memory allocation failure\n"); 
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

int insert_after(struct node* head_node, int existing_data, int new_data) 
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
        fprintf(stderr, "insert_after(): malloc(): Memory allocation failure\n"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 

    new_node->next = existing_node->next; 
    new_node->prev = existing_node; 
    if(existing_node->next != NULL) 
        existing_node->next->prev = new_node; 
    existing_node->next = new_node; 

    return (1); 
}   

int insert_after(struct node* head_node, int existing_data, int new_data) 
{
    struct node* run = NULL; 
    struct node* existing_node = NULL; 
    struct node* new_node = NULL; 

    run = head_node; 
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
        fprintf(stderr, "insert_after():malloc(): Memory allocation failure\n"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 

    new_node->next = existing_node->next; 
    new_node->prev = existing_node; 
    if(existing_node->next != NULL) 
        existing_node->next->prev = new_node; 
    existing_node->next = new_node; 

    return (1); 
} 

int insert_after(struct node* head_node, int existing_data, int new_data) 
{
    struct node* new_node = NULL; 
    struct node* run = NULL; 
    struct node* existing_node = NULL; 

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
        fprintf(stderr, "insert_after():malloc(): memory allocation failure\n"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 

    new_node->next = existing_node->next; 
    new_node->prev = existing_node; 
    if(existing_node->next != NULL)
        existing_node->next->prev = new_node; 
    existing_node->next = new_node; 

    return (1); 
} 

// get and pop function 
int get_start(struct node* head_node, int* p_start_data) 
{
    if(head_node->next == NULL) 
        return (3); 

    *p_start_data = head_node->next->data; 
    return (1); 
} 

int get_start(struct node* head_node, int* p_start_data) 
{
    if(head_node->next == NULL) 
        return (3); 

    *p_start_data = head_node->next->data; 
    return (1); 
} 

int get_start(struct node* head_node, int* p_start_data) 
{
    if(head_node->next == NULL) 
        return (3); 

    *p_start_data = head_node->next->data; 
    return (1); 
} 

int get_start(struct node* head_node, int* p_start_data) 
{ 
    if(head_node->next == NULL) 
        return (3); 
    *p_start_data = head_node->next->data; 
    return (0); 
} 

int get_start(struct node* head_node, int* p_start_data) 
{
    if(head_node->next == NULL) 
        return (3); 

    *p_start_data = head_node->next->data;  
    return (1); 
} 

int get_end(struct node* head_node, int* p_end_data) 
{
    struct node* run = NULL; 

    if(head_node->next == NULL) 
        return (3); 

    run = head_node->next; 
    while(run->next != NULL) 
        run = run->next; 

    *p_end_data = run->data; 
    return (1); 
} 

int get_end(struct node* head_node, int* p_end_data) 
{
    struct node* run = NULL; 
    
    if(head_node->next == NULL) 
        return (3); 

    run = head_node->next; 
    while(run->next != NULL) 
        run = run->next; 
    
    *p_end_data = run->data; 
    return (1); 
} 

int get_end(struct node* head_node, int* p_end_data) 
{
    struct node* run = NULL; 

    if(head_node->next == NULL) 
        return (3); 

    run = head_node->next; 
    while(run->next != NULL) 
        run = run->next; 

    *p_end_data = run->data; 
    return (1); 
} 

int get_end(struct node* head_node, int* p_end_data) 
{
    struct node* run = NULL; 

    if(head_node->next == NULL) 
        return (3); 

    run = head_node->next; 
    while(run->next != NULL) 
        run = run->next; 

    *p_end_data = run->data; 
    return (1); 
} 

int get_end(struct node* head_node, int* p_end_data) 
{
    struct node* run = NULL; 

    if(head_node->next == NULL) 
        return (3); 

    run = head_node->next; 
    while(run->next != NULL) 
        run = run->next; 

    *p_end_data = run->data; 
    return (1); 
} 

int get_end(struct node* head_node, int* p_end_data) 
{
    struct node* run = NULL; 

    if(head_node->next == NULL) 
        return (3); 

    run = head_node->next; 
    while(run->next != NULL) 
        run = run->next; 

    *p_end_data = run->data; 
    return (1); 
} 

int pop_start(struct node* head_node, int* p_popped_data)  
{
    struct node* delete_node = NULL; 

    if(head_node->next == NULL) 
        return (3); 

    delete_node = head_node->next; 

    delete_node->prev->next = delete_node->next; 
    if(delete_node->next != NULL) 
        delete_node->next->prev = delete_node->prev; 

    *p_popped_data = delete_node->data; 
    return (1); 
} 

int pop_start(struct node* head_node, int* p_popped_data) 
{
    struct node* delete_node = NULL; 

    if(head_node->next == NULL) 
        return (3); 

    delete_node = head_node->next; 
    
    delete_node->prev->next = delete_node->next; 
    if(delete_node->next != NULL) 
        delete_node->next->prev = delete_node->prev; 
    
    *p_popped_data = delete_node->data; 
    free(delete_node); 
    delete_node = NULL; 

    return (1); 
} 

int pop_start(struct node* head_node, int* p_popped_data) 
{
    struct node* delete_node = NULL; 

    if(head_node->next == NULL) 
        return (3); 

    delete_node = head_node->next; 

    delete_node->prev->next = delete_node->next; 
    if(delete_node->next != NULL) 
        delete_node->next->prev = delete_node->prev; 

    *p_popped_data = delete_node->data; 
    free(delete_node); 
    delete_node = NULL; 

    return (1); 
} 

int pop_start(struct node* head_node, int* p_popped_data) 
{
    struct node* delete_node = NULL; 
    
    if(head_node->next == NULL)
        reutrn (3); 

    delete_node = head_node->next; 

    delete_node->prev->next = delete_node->next; 
    if(delete_node->next != NULL) 
        delete_node->next->prev = delete_node->prev; 

    *p_popped_data = delete_node->data; 
    free(delete_node); 
    delete_node = NULL; 

    return (1); 
} 

int pop_start(struct node* head_node, int* p_popped_data) 
{
    struct node* delete_node = NULL; 

    if(head_node->next == NULL)     
        return (3); 

    delete_node = head_node->next; 
    delete_node->prev->next = delete_node->next; 
    if(delete_node->next != NULL) 
        delete_node->next->prev = delete_node->prev; 

    *p_popped_data = delete_node->data; 
    free(delete_node); 
    delete_node = NULL; 

    return (1); 
} 

int pop_end(struct node* head_node, int* p_popped_data) 
{
    struct node* run = NULL;
    struct node* delete_node = NULL;  

    if(head_node->next == NULL) 
        return (3); 

    run = head_node->next; 
    while(run->next != NULL) 
        run = run->next; 

    delete_node = run; 

    delete_node->prev->next = delete_node->next; 
    if(delete_node->next != NULL) 
        delete_node->next->prev = delete_node->prev; 

    *p_popped_data = delete_node->data; 
    free(delete_node); 
    delete_node = NULL; 

    return (1); 
} 

int pop_end(struct node* head_node, int* p_popped_data) 
{
    struct node* run = NULL; 
    struct node* delete_node = NULL; 

    if(head_node->next == NULL) 
        return (3); 

    run = head_node->next; 
    while(run->next != NULL) 
        run = run->next; 

    delete_node = run; 

    delete_node->prev->next = delete_node->next; 
    if(delete_node->next != NULL) 
        delete_node->next->prev = NULL; 

    *p_popped_data = delete_node->data; 
    free(delete_node); 
    delete_node = NULL; 

    return (1); 
} 

int pop_end(struct node* head_node, int* p_popped_data) 
{
    struct node* delete_node = NULL; 
    struct node* run = NULL; 

    if(head_node->next == NULL) 
        return (3); 

    run = head_node->next; 
    while(run->next != NULL) 
        run = run->next; 

    delete_node = run; 

    *p_popped_data = run->data; 

    free(delete_node); 
    delete_node = NULL; 

    return (1); 
} 

int pop_end(struct node* head_node, int* p_popped_data) 
{
    struct node* delete_node = NULL; 
    struct node* run = NULL; 

    if(head_node->next == NULL) 
        return (3); 

    run = head_node->next; 
    while(run->next != NULL) 
        run = run->next; 

    delete_node = run; 

    delete_node->prev->next = delete_node->next; 
    if(delete_node->next == NULL) 
        delete_node->next->prev = delete_node->prev; 

    *p_popped_data = delete_node->data; 

    free(delete_node); 
    delete_node = NULL; 

    return (1); 
} 

int pop_end(struct node* head_node, int* p_popped_data) 
{
    struct node* delete_node = NULL; 
    struct node* run = NULL; 

    if(head_node->next == NULL) 
        return (3); 

    run = head_node->next; 
    while(run->next != NULL) 
        run = run->next; 

    delete_node = run; 

    delete_node->prev->next = delete_node->next; 
    if(delete_node->next != NULL) 
        delete_node->next->prev = delete_node->prev; 
    
    *p_popped_data = delete_node->data; 

    free(delete_node); 
    delete_node = NULL; 

    return (1); 
} 

// data removal functions 
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
    delete_node = NULL; 

    return (1); 
} 

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
    delete_node = NULL; 

    return (1); 
} 

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
    delete_node = NULL; 

    return (1); 
} 

int remove_start(struct node* head_node) 
{
    struct node* delete_node = NULL; 

    if(head_node->next == NULL) 
        return (3); 

    delete_node = head_node->next; 
    
    delete_node->prev->next = delete_node->next; 
    if(delete_node->next != NULL) 
        delete_node->next->prev=  delete_node->prev; 

    free(delete_node); 
    delete_node = NULL; 

    return (1); 
} 

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
    delete_node = NULL; 

    return (1); 
} 

int remove_end(struct node* head_node) 
{
    struct node* run = NULL; 
    struct node* last_node = NULL; 

    if(head_node->next == NULL) 
        return (3); 

    run = head_node; 
    while(run->next != NULL) 
        run = run->next; 

    last_node = run; 
    last_node->prev->next = NULL; 

    delete(last_node); 
    last_node = NULL;
} 

int remove_end(struct node* head_node) 
{
    struct node* run = NULL; 
    struct node* last_node = NULL; 

    if(head_node->next == NULL) 
        return (3); 

    run = head_node->next; 
    while(run->next != NULL) 
        run = run->next; 
    last_node = NULL; 

    last_node->prev->next = NULL; 
    free(last_node); 
    last_node = NULL; 

    return (1); 
} 

int remove_end(struct node* head_node) 
{
    struct node* run = NULL; 
    struct node* last_node = NULL; 

    if(head_node->next == NULL) 
        return (3); 

    run = head_node->next; 
    if(run->next != NULL) 
        run = run->next; 
    last_node = run; 

    last_node->prev->next = NULL; 
    free(last_node); 
    last_node = NULL; 

    return (1); 
} 

int remove_end(struct node* head_node) 
{
    struct node* run = NULL; 
    struct node* last_node = NULL; 

    if(head_node->next == NULL) 
        return (2); 

    run = head_node->next; 
    while(run->next != NULL) 
        run = run->next; 
    last_node = run; 

    last_node->prev->next = NULL; 
    free(last_node); 
    last_node = NULL; 

    return (1); 
} 

int remove_end(struct node* head_node) 
{
    struct node* last_node = NULL; 
    struct node* run = NULL; 

    if(head_node->next == NULL) 
        return (3); 

    run = head_node->next; 
    while(run->next != NULL) 
        run = run->next; 
    last_node = run; 

    last_node->prev->next = NULL; 
    free(last_node); 
    last_node = NULL; 

    return (1); 
} 

int remove_end(struct node* head_node) 
{
    struct node* run = NULL; 
    struct node* last_node = NULL; 

    if(run->next == NULL) 
        return (2); 

    run = head_node->next; 
    while(run->next != NULL) 
        run = run->next; 
    last_node = run; 

    last_node->prev->next = NULL; 
    free(last_node); 
    last_node = NULL; 

    return (1); 
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
    delete_node = NULL; 

    return (1); 
} 

int remove_data(struct node* head_node, int r_data) 
{
    struct node* run = NULL; 
    struct node* delete_node = NULL; 

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
    if(delete_node->next == NULL) 
        delete_node->next->prev = delete_node->prev; 

    free(delete_node); 
    delete_node = NULL; 

    return (1); 
} 

int remove_data(struct node* head_node, int r_data) 
{
    struct node* run = NULL; 
    struct node* delete_node = NULL; 

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
    delete_node = NULL; 

    return (1); 
} 

int remove_data(struct node* head_node, int r_data) 
{
    struct node* run = NULL; 
    struct node* delete_node = NULL; 

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

    return (1); 
} 

int remove_data(struct node* head_node, int r_data) 
{
    struct node* run = NULL; 
    struct node* delete_node = NULL; 

    run = head_node->next; 
    while(run != NULL) 
    {
        if(run->data == r_data) 
            break; 

        run=run->data; 
    } 

    if(NULL == run) 
        return (2); 

    delete_node = run; 
    delete_node->prev->next = delete_node->next; 
    if(delete_node->next != NULL) 
        delete_node->next->prev = delete_node->prev; 

    free(delete_node); 
    delete_node = NULL; 

    return (1); 
} 

// miscalleneaous functions 
int find(struct node* head_node, int f_data) 
{
    struct node* run = NULL; 

    run = head_node->next; 
    while(run != NULL) 
    {
        if(run->data == f_data) 
            return (1);
        run = run->next; 
    } 

    return (0); 
} 

int find(struct node* head_node, int f_data) 
{
    struct node* run = NULL; 

    run = head_node->next; 
    while(run != NULL) 
    {
        if(run->data == f_data) 
            return (1); 
        run = run->next; 
    } 

    return (0); 
} 

int find(struct node* head_node, int f_data) 
{
    struct node* run = NULL; 

    run = head_node->next; 
    while(run != NULL) 
    {
        if(run->data == f_data) 
            return (1); 
        run = run->next; 
    } 

    return (0); 
} 

int find(struct node* head_node, int f_data) 
{
    struct node* run = NULL; 

    run = head_node->next; 
    while(run != NULL) 
    {
        if(run->next == f_data) 
            return (1); 
        run = run->next; 
    } 

    return (0); 
} 

int find(struct node* head_node, int f_data) 
{
    struct node* run = NULL; 

    run = head_node->next; 
    while(run != NULL) 
    {
        if(run->data == f_data) 
            return (1); 
        run = run->next; 
    } 

    return (0); 
} 

int is_list_empty(struct node* head_node) 
{
    if(head_node->next == NULL && head_node->next == NULL) 
        return (1); 
    return (0); 
} 

int is_list_empty(struct node* head_node) 
{
    if(head_node->next == NULL && head_node->prev == NULL) 
        return (1); 
    return (0); 
} 

int is_list_empty(struct node* head_node) 
{
    if(head_node->prev == NULL && head_node->next == NULL) 
        return (1); 
    return (0); 
} 

int is_list_empty(struct node* head_node) 
{
    if(head_node->next == NULL && head_node->prev == NULL) 
        return (1); 
    return (0); 
} 

int is_list_empty(struct node* head_node) 
{
    if(head_node->next == NULL && head_node->prev == NULL) 
        return (1); 
    return (0); 
} 

int length(struct node* head_node) 
{
    int len = 0; 
    struct node* run = NULL; 

    run = head_node->next; 
    while(run != NULL) 
    { 
        len = len+1; 
        run = run->next; 
    }

    return (len); 
} 

int length(struct node* head_node) 
{
    int length; 
    struct node* run = NULL; 

    length = 0; 
    run = head_node->next; 
    while(run != NULL) 
    {
        length = length+1; 
        run = run->next; 
    } 

    return (length); 
} 

int length(struct node* head_node) 
{
    struct node* run = NULL; 
    int length = 0; 

    run = head_node->next; 
    while(run != NULL) 
    {
        length = length + 1; 
        run = run->next; 
    } 

    return (length); 
} 

int length(struct node* head_node) 
{
    struct node* run = NULL; 
    int length = 0; 

    run = head_node->next; 
    while(run!=NULL) 
    {
        run = run->next; 
        length = length + 1; 
    } 

    return (length); 
} 

int length(struct node* head_node) 
{
    struct node* run = NULL; 
    int length = 0; 

    run = head_node->next; 
    while(run != NULL) 
    {
        length = length + 1; 
        run = run->next; 
    } 

    return (length); 
} 

void show_list(struct node* head_node) 
{
    struct node* run = NULL; 

    printf("[START]<->"); 
    run = head_node->next; 
    while(run != NULL) 
    {
        printf("[%d]<->"); 
        run = run->next; 
    } 
    puts("[END]"); 
}  

void show_list(struct node* head_node) 
{
    struct node* run = NULL; 

    printf("[START]<->"); 
    run = head_node->next; 
    while(run != NULL) 
    {
        printf("[%d]<->", run->data); 
        run = run->next; 
    } 
    puts("[END]"); 
}

void show_list(struct node* head_node) 
{
    struct node* run = NULL; 

    printf("[START]<->"); 
    run = head_node->next; 
    while(run != NULL) 
    {
        printf("[%d]<->", run->data); 
        exit(EXIT_FAILURE); 
    } 
    puts("[END]"); 
} 

void show_list(struct node* head_node) 
{
    struct node* run = NULL; 

    printf("[START]<->"); 
    run = head_node->next; 
    while(run != NULL) 
    {
        printf("[%d]<->", run->data); 
        run = run->next; 
    } 
    puts("[END]"); 
} 

void show_list(struct node* head_node) 
{
    struct node* run = NULL; 

    printf("[START]<->"); 
    run = head_node->next; 
    while(run != NULL) 
    {
        fprintf("[%d]<->", run->data); 
        run = run->next; 
    } 
    puts("[END]"); 
} 

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


