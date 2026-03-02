/*********************************************************************************
 * 
 *      DOUBLY LINKED LIST 
 * 
 *      Author:  Sarthak A. Jaiswal 
 *      Date:    02 MARCH 2025 
 * 
 **********************************************************************************/

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

#define SUCCESS     1 
#define FALSE       0 
#define TRUE        1 

#define LIST_DATA_NOT_FOUND     -1 
#define LIST_EMPTY              -2 

typedef int                 data_t; 
typedef int                 status_t; 
typedef unsigned long long  len_t; 
typedef struct node         node_t; 
typedef node_t              list_t; 

struct node 
{
    data_t data; 
    struct node* prev; 
    struct node* next; 
}; 

/* Interface function declarations */ 
/* creation */ 
list_t* create_list(void); 

/* data insertion */ 
status_t insert_start(list_t* p_list, data_t new_data); 
status_t insert_end(list_t* p_list, data_t new_data); 
status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data); 
status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data); 

/* getters */ 
status_t get_start(list_t* p_list, data_t* p_start_data); 
status_t get_end(list_t* p_list, data_t* p_end_data); 

/* pop functions */ 
status_t pop_start(list_t* p_list, data_t* p_popped_data); 
status_t pop_end(list_t* p_list, data_t* p_popped_data);  

/* data removal */ 
status_t remove_start(list_t* p_list); 
status_t remove_end(list_t* p_list); 
status_t remove_data(list_t* p_list, data_t r_data); 
status_t clear_list(list_t* p_list); 

/* miscalleneous */ 
list_t*     to_list(data_t* p_array, size_t array_size); 
data_t*     to_array(list_t* p_list, size_t* p_array_size);  
status_t    is_list_empty(list_t* p_list);
status_t    find_in_list(list_t* p_list, data_t f_data); 
len_t       get_list_length(list_t* p_list); 
void        show_list(list_t* p_list, const char* msg); 

/* reversal */ 
list_t*     get_reversed_list(list_t* p_list); 
status_t    reverse_list(list_t* p_list); 

/* interlist routines */ 
list_t*     get_concated_list(list_t* p_list_1, list_t* p_list_2); 
status_t    concat_lists(list_t* p_list_1, list_t** pp_list_2); 
list_t*     merge_lists(list_t* p_list_1, list_t* p_list_2); 

/* destruction */ 
status_t destroy_list(list_t** pp_list); 

/* List helper routines */ 
node_t* get_node(data_t new_data); 
node_t* search_node(list_t* p_list, data_t s_data); 
void    generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end); 
void    generic_delete(node_t* p_delete_node); 

/* General Purpose heler functions */ 
void* xmalloc(size_t size_in_bytes); 
