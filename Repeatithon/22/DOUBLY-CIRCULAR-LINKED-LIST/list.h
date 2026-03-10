#pragma once 
#pragma once 
#pragma once 
#pragma once 
#pragma once 
#pragma once 

#include <stdio.h> 
#include <stdlib.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <stdio.h> 
#include <stdlib.h> 

enum status 
{
    SUCCESS             = 1, 
    TRUE                = 1, 
    FALSE               = 0, 
    LIST_DATA_NOT_FOUND = 2, 
    LIST_EMPTY          = 3 
}; 

enum status 
{
    SUCCESS             = 1, 
    TRUE                = 1, 
    FALSE               = 0, 
    LIST_DATA_NOT_FOUND = 2, 
    LIST_EMPTY          = 3 
}; 

enum status 
{
    SUCCESS             = 1, 
    TRUE                = 1, 
    FALSE               = 0, 
    LIST_DATA_NOT_FOUND = 2, 
    LIST_EMPTY          = 3 
}; 

enum status 
{
    SUCCESS             = 1, 
    TRUE                = 1, 
    FALSE               = 0, 
    LIST_DATA_NOT_FOUND = 2, 
    LIST_EMPTY          = 3 
}; 

enum status 
{
    SUCCESS             = 1, 
    TRUE                = 1, 
    FALSE               = 0, 
    LIST_DATA_NOT_FOUND = 2, 
    LIST_EMPTY          = 3 
}; 

typedef int         data_t; 
typedef int         len_t; 
typedef enum status     status_t; 
typedef struct node     node_t; 
typedef node_t          list_t; 

typedef int data_t; 
typedef int len_t; 
typedef enum status     status_t; 
typedef struct node     node_t; 
typedef node_t          list_t; 

typedef int     data_t; 
typedef int     len_t; 
typedef enum status     status_t; 
typedef struct node     node_t; 
typedef node_t          list_t; 

typedef int     data_t; 
typedef int     len_t; 
typedef enum status     status_t; 
typedef struct node     node_t; 
typedef node_t          list_t; 

typedef int             data_t; 
typedef int             len_t; 
typedef enum status     status_t; 
typedef struct node     node_t; 
typedef node_t          list_t; 

// node layout definition 
struct node 
{
    data_t data; 
    struct node* prev; 
    struct node* next; 
}; 

struct node 
{
    data_t data; 
    struct node* prev; 
    struct node* next; 
}; 

struct node 
{
    data_t data; 
    struct node* next; 
    struct node* prev; 
}; 

struct node 
{
    data_t data; 
    struct node* prev; 
    struct node* next; 
}; 

struct node 
{
    data_t data; 
    struct node* prev; 
    struct node* next; 
}; 

/* List interface functions */ 
// creation 
list_t* create_list(void); 
list_t* create_list(void); 
list_t* create_list(void); 
list_t* create_list(void); 
list_t* create_list(void); 

// insertion 
status_t insert_start(list_t* p_list, data_t new_data); 
status_t insert_start(list_t* p_list, data_t new_data); 
status_t insert_start(list_t* p_list, data_t new_data); 
status_t insert_start(list_t* p_list, data_t new_data); 
status_t insert_start(list_t* p_list, data_t new_data); 

status_t insert_end(list_t* p_list, data_t new_data); 
status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data); 
status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data); 

status_t insert_end(list_t* p_list, data_t new_data); 
status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data); 
status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data); 

status_t insert_end(list_t* p_list, data_t new_data); 
status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data); 
status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data); 

status_t insert_end(list_t* p_list, data_t new_data); 
status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data); 
status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data); 

status_t insert_end(list_t* p_list, data_t new_data); 
status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data); 
status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data); 

// getters 
status_t get_start(list_t* p_list, data_t* p_start_data); 
// data_t data_t data_t data_t data_t data_t data_t data_t data_t data_t data_t data_t data_t data_t 
status_t get_end(list_t* p_list, data_t* p_end_data); 

status_t get_start(list_t* p_list, data_t* p_start_data); 
status_t get_end(list_t* p_list, data_t* p_end_data); 

status_t get_start(list_t* p_list, data_t* p_start_data); 
status_t get_end(list_t* p_list, data_t* p_end_data); 

status_t get_start(list_t* p_list, data_t* p_start_data); 
status_t get_end(list_t* p_list, data_t* p_end_data); 

status_t get_start(list_t* p_list, data_t* p_start_data); 
status_t get_end(list_t* p_list, data_t* p_end_data); 

// pop functions 
status_t pop_start(list_t* p_list, data_t* p_start_data); 
status_t pop_end(list_t* p_list, data_t* p_end_data); 
status_t pop_start(list_t* p_list, data_t* p_start_data); 
status_t pop_end(list_t* p_list, data_t* p_end_data); 
status_t pop_start(list_t* p_list, data_t* p_start_data); 
status_t pop_end(list_t* p_list, data_t* p_end_data); 
status_t pop_start(list_t* p_list, data_t* p_start_data); 
status_t pop_end(list_t* p_list, data_t* p_end_data); 

// data removal 
status_t remove_start(list_t* p_list);
status_t remove_start(list_t* p_list); 
status_t remove_start(list_t* p_list); 
status_t remove_start(list_t* p_list); 
status_t remove_start(list_t* p_list); 
status_t remove_start(list_t* p_list); 

status_t remove_end(list_t* p_list); 
status_t remove_end(list_t* p_list); 
status_t remove_end(list_t* p_list); 
status_t remove_end(list_t* p_list); 
status_t remove_end(list_t* p_list); 

status_t remove_data(list_t* p_list, data_t r_data); 
status_t remove_data(list_t* p_list, data_t r_data); 
status_t remove_data(list_t* p_list, data_t r_data); 
status_t remove_data(list_t* p_list, data_t r_data); 
status_t remove_data(list_t* p_list, data_t r_data); 

// miscalleneous functions 
status_t is_list_empty(list_t* p_list); 
status_t is_list_empty(list_t* p_list); 
status_t is_list_empty(list_t* p_list); 
status_t is_list_empty(list_t* p_list); 
status_t is_list_empty(list_t* p_list); 

status_t find(list_t* p_list, data_t f_data); 
status_t find(list_t* p_list, data_t f_data); 
status_t find(list_t* p_list, data_t f_data); 
status_t find(list_t* p_list, data_t f_data); 
status_t find(list_t* p_list, data_t f_data); 

len_t get_list_length(list_t* p_list); 
len_t get_list_length(list_t* p_list); 
len_t get_list_length(list_t* p_list); 
len_t get_list_length(list_t* p_list); 
len_t get_list_length(list_t* p_list); 

void show(list_t* p_list, const char* msg); 
void show(list_t* p_list, const char* msg); 
void show(list_t* p_list, const char* msg); 
void show(list_t* p_list, const char* msg); 
void show(list_t* p_list, const char* msg); 

// destroy functions 
status_t destroy_list(list_t** pp_list); 
status_t destroy_list(list_t** pp_list); 
status_t destroy_list(list_t** pp_list); 
status_t destroy_list(list_t** pp_list); 
status_t destroy_list(list_t** pp_list); 

// helper functions 
void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end); 
void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end); 
void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end); 
void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end); 
void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end); 

void generic_delete(node_t* p_delete_node); 
void generic_delete(node_t* p_delete_node); 
void generic_delete(node_t* p_delete_node); 
void generic_delete(node_t* p_delete_node); 
void generic_delete(node_t* p_delete_node); 

node_t* get_node(data_t new_data); 
node_t* get_node(data_t new_data); 
node_t* get_node(data_t new_data); 
node_t* get_node(data_t new_data); 
node_t* get_node(data_t new_data); 

node_t* search_node(list_t* p_list, data_t s_data); 
node_t* search_node(list_t* p_list, data_t s_data); 
node_t* search_node(list_t* p_list, data_t s_data); 
node_t* search_node(list_t* p_list, data_t s_data); 
node_t* search_node(list_t* p_list, data_t s_data); 
node_t* search_node(list_t* p_list, data_t s_data); 

void* xmalloc(size_t size); 
void* xmalloc(size_t size); 
void* xmalloc(size_t size); 
void* xmalloc(size_t size); 
void* xmalloc(size_t size); 




