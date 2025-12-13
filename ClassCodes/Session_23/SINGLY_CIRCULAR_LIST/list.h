/*
    @GOAL: singly circular linked list using modular approach  
    @DATE: 07 Dec 2025 
    @AUTHOR: Sarthak A. Jaiswal 
*/

#ifndef _SCLL_H 
#define _SCLL_H 

// header files 
#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

// Symbolic constants 
enum status 
{
    SUCCESS         = 1, 
    TRUE            = 1, 
    FALSE           = 0, 
    LIST_DATA_NOT_FOUND = 2, 
    LIST_EMPTY      = 3 
}; 

// typedefs 
typedef int             data_t; 
typedef int             len_t; 
typedef enum status     status_t; 
typedef struct node     node_t; 
typedef node_t          list_t; 

// node layout definition 
struct node 
{
    data_t data; 
    struct node* next; 
}; 

// declarations of interface functions 

// create list function 
list_t* create_list(void); 

// data addition functions 
status_t insert_start(list_t* p_list, data_t new_data); 
status_t insert_end(list_t* p_list, data_t new_data); 
status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data); 
status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data); 

// get and pop functions 
status_t get_start(list_t* p_list, data_t* p_start_data); 
status_t get_end(list_t* p_list, data_t* p_end_data); 
status_t pop_start(list_t* p_list, data_t* p_start_data); 
status_t pop_end(list_t* p_list, data_t* p_end_data); 

// remove functions 
status_t remove_start(list_t* p_list); 
status_t remove_end(list_t* p_list); 
status_t remove_data(list_t* p_list, data_t r_data); 

// miscalleneous functions 
status_t find(list_t* p_list, data_t f_data); 
status_t is_list_empty(list_t* p_list); 
len_t get_list_length(list_t* p_list); 
void show(list_t* p_list, const char* msg); 

// destroy list 
status_t destroy_list(list_t** pp_list); 

#endif  /* _SCLL_H */ 
