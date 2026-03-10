#ifndef _DCLL_H 
#define _DCLL_H 

/* standard headers */ 
#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include <math.h> 

/* symbolic constants */ 
#define SUCCESS     1 
#define TRUE        1 
#define FALSE       0 
#define LIST_DATA_NOT_FOUND -1 
#define LIST_EMPTY  -2 
#define LIST_INSUFFICIENT_ELEMENTS  -3 

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
/* creation */ 
list_t* create_list(void); 

/* data insertion */ 
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

/* getters */ 
status_t get_start(
            list_t* p_list, 
            data_t* p_start_data
        ); 
status_t get_end(
            list_t* p_list, 
            data_t* p_end_data
        ); 

/* pop functions */ 
status_t pop_start(
            list_t* p_list, 
            data_t* p_start_data
        ); 
status_t pop_end(
            list_t* p_list, 
            data_t* p_end_data
        ); 

/* data removal */ 
status_t remove_start(list_t* p_list); 
status_t remove_end(list_t* p_list); 
status_t remove_data(
            list_t* p_list, 
            data_t r_data
        ); 
status_t clear_list(list_t* p_list); 

/* miscalleneous */ 
list_t* to_list(data_t* p_array, size_t p_array_size); 
data_t* to_array(list_t* p_list, size_t* p_array_size); 
status_t is_list_empty(list_t* p_list); 
status_t find_in_list(
            list_t* p_list, 
            data_t f_data
        ); 
len_t get_list_length(list_t* p_list); 
void show_list(
            list_t* p_list, 
            const char* msg
        ); 

// ----------------------------------------------------------------------------------         

status_t get_second_last(
            list_t* p_list, 
            data_t* p_second_last_data
        );  
status_t swap_first_and_last(list_t* p_list); 
status_t move_last_to_first(list_t* p_list); 
status_t move_first_to_last(list_t* p_list); 
status_t check_if_sum_of_first_and_last_equals_target(list_t* p_list, data_t target); 

status_t rotate_right_by_k(list_t* p_list, size_t k); 
status_t rotate_left_by_k(list_t* p_list, size_t k); 
status_t insert_before_last(list_t* p_list, data_t new_data); 
status_t delete_second_last(list_t* p_list); 
void traverse_n_rounds_alternate(list_t* p_list, int n); 
list_t* split_into_halves(list_t* p_list); 
status_t interleave_lists(list_t* p_list, list_t** pp_list); 
status_t is_list_symmetric(list_t* p_list); 
void find_pairs_with_sum(list_t* p_list, data_t target); 

status_t zigzag_arrangement(list_t* p_list); 

// ---------------------------------------------------------------------------------- 

/* reversal */
list_t* get_reversed_list(list_t* p_list); 
status_t reverse_list(list_t* p_list);  

/* Interlist routines */
/* concat immutable */
list_t* get_concated_list(
            list_t* p_list_1, 
            list_t* p_list_2
        ); 

/* concat mutable */
status_t concat_lists(
            list_t* p_list_1, 
            list_t** pp_list_2 
        ); 

/* merge sorted list */
list_t* merge_lists(
            list_t* p_list_1, 
            list_t* p_list_2 
        ); 

/* destruction functions */ 
status_t destroy_list(list_t** pp_list); 

/* List auxilliary functions */
static node_t* search_node(
            list_t* p_list, 
            data_t s_data 
        ); 
static node_t* get_node(data_t new_data); 
static void generic_insert(
            node_t* p_beg, 
            node_t* p_mid, 
            node_t* p_end
        ); 
static void generic_delete(node_t* p_delete_node); 

/* auxialliary functions */
static void* xmalloc(size_t size_in_bytes); 

#endif /* _DCLL_H */

