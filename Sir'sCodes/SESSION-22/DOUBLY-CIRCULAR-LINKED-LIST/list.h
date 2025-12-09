#ifndef _LIST_H 
#define _LIST_H 

//  Header files 
#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h>

//  Symbolic constants 
enum status 
{
    SUCCESS             = 1, 
    TRUE                = 1, 
    FALSE               = 0, 
    LIST_DATA_NOT_FOUND = 2, 
    LIST_EMPTY          = 3
}; 

//  Typedefs 
typedef int             data_t; 
typedef int             len_t; 
typedef enum status     status_t; 
typedef struct node     node_t; 
typedef node_t          list_t; 

//  Node layout definition 
struct node 
{
    data_t data; 
    struct node* prev; 
    struct node* next; 
}; 

//  Declarations of interface functions 

//  Create list function 
list_t* create_list(void); 

//  Insertion functions 
status_t insert_start(list_t* p_list, data_t new_data); 
status_t insert_end(list_t* p_list, data_t new_data); 
status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data);
status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data); 

//  Get and pop functions 
status_t get_start(list_t* p_list, data_t* p_start_data); 
status_t get_end(list_t* p_list, data_t* p_end_data); 
status_t pop_start(list_t* p_list, data_t* p_start_data); 
status_t pop_end(list_t* p_list, data_t* p_end_data); 

//  Remove functions 
status_t remove_start(list_t* p_list); 
status_t remove_end(list_t* p_list); 
status_t remove_data(list_t* p_list, data_t e_data); 

//  Miscallaneous functions 
status_t find(list_t* p_list, data_t search_data); 
status_t is_list_empty(list_t* p_list); 
len_t get_list_length(list_t* p_list); 
void show(list_t* p_list, const char* msg); 

//  Destroy function 
status_t destroy_list(list_t** pp_list); 

//  Helper functions 
void generic_insert(node_t* start_node, node_t* mid_node, node_t* end_node); 
void generic_delete(node_t* delete_node); 
node_t* search_node(list_t* p_list, data_t search_data); 
node_t* get_node(data_t new_data); 
void* xmalloc(size_t size); 

#endif  // _LIST_H 