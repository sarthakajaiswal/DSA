/*********************************************************************************
 * 
 *      DOUBLY LINKED LIST 
 * 
 * Author:  Sarthak A. Jaiswal 
 * Date:    06 Dec 2025 
 * 
 **********************************************************************************/

#ifndef _DCLL_H 
#define _DCLL_H 

/* standard headers */ 
#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

/* symbolic constants */ 
#define SUCCESS     1 
#define TRUE        1 
#define FALSE       0 
#define LIST_DATA_NOT_FOUND 2 
#define LIST_EMPTY  3 

/* typedefs */
typedef struct node node_t; 
typedef node_t list_t; 

typedef int data_t; 
typedef int status_t; 
typedef unsigned long long len_t; 

/* Node layout definition */
struct node 
{
    data_t data; 
    struct node* next; 
    struct node* prev; 
};  

/* Interface functions */
list_t* create_list(void); 

status_t insert_start(
            list_t* p_list, 
            data_t new_data
        ); 
status_t insert_end(
            list_t* p_list, 
            data_t new_data
        ); 
status_t insert_before(
            list_t* p_list, 
            data_t existing_data, 
            data_t new_data
        ); 
status_t insert_after(
            list_t* p_list, 
            data_t existing_data, 
            data_t new_data
        ); 

status_t get_start(
            list_t* p_list, 
            data_t* p_start_data
        ); 
status_t get_end(
            list_t* p_list, 
            data_t* p_end_data
        ); 

status_t pop_start(
            list_t* p_list, 
            data_t* p_start_data
        ); 
status_t pop_end(
            list_t* p_list, 
            data_t* p_end_data
        ); 

status_t remove_start(list_t* p_list); 
status_t remove_end(list_t* p_list); 
status_t remove_data(
            list_t* p_list, 
            data_t r_data
        ); 
status_t clear_list(list_t* p_list); 

status_t is_empty(list_t* p_list); 
status_t find_in_list(
            list_t* p_list, 
            data_t f_data
        ); 
len_t get_list_length(list_t* p_list); 
void show_list(
            list_t* p_list, 
            const char* msg
        ); 

status_t destroy_list(list_t** pp_list); 

/* Interlist routines */
/* concat immutable */
list_t* get_concated_list(
            list_t* p_list_1, 
            list_t* p_list_2
        ); 

/* concat mutable */
status_t concat_list(
            list_t* p_list_1, 
            list_t** pp_list_2 
        ); 

/* merge sorted list */
list_t* merge_lists(
            list_t* p_list_1, 
            list_t* p_list_2 
        ); 

/* reversal routines */
list_t* get_reversed_list(list_t* p_list); 
status_t reverse_list(list_t* p_list); 

/* List auxilliary functions */
static void generic_insert(
            node_t* p_beg, 
            node_t* p_mid, 
            node_t* p_end
        ); 
static void generic_delete(node_t* p_delete_node); 
static node_t* search_node(
            list_t* p_list, 
            data_t s_data 
        ); 
static node_t* get_node(data_t new_data); 

/* auxialliary functions */
static void* xcalloc(
            size_t nr_elements, 
            size_t size_per_element 
        ); 

#endif /* _DCLL_H */

