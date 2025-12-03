#ifndef _LIST_H 
#define _LIST_H 

#endif 

#ifndef _LIST_H 
#define _LIST_H 

#endif 

#ifndef _LIST_H 
#define _LIST_H 
#endif /* _LIST_H */

#ifndef _LIST_H 
#define _LIST_H 

#endif /* _LIST_H */

#ifndef _LIST_H 
#define _LIST_H 

#endif /* _LIST_H */

#include <stdio.h> 
#include <stdio.h> 
#include <stdio.h> 
#include <stdio.h> 
#include <stdio.h> 

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

typedef int data_t; 
typedef int status_t; 
typedef int len_t; 

typedef struct node node_t; 
typedef node_t list_t; 

struct node 
{
    int data; 
    struct node* prev; 
    struct node* next; 
}; 

typedef int data_t; 
typedef int status_t; 
typedef int len_t; 

typedef struct node node_t; 
typedef node_t list_t; 

struct node 
{
    int data; 
    struct node* prev; 
    struct node* next; 
}; 

typedef int data_t; 
typedef int status_t; 
typedef int len_t; 

typedef struct node node_t; 
typedef node_t list_t; 

struct node 
{
    data_t data; 
    struct node* prev; 
    struct node* next; 
}; 

typedef int data_t; 
typedef int status_t; 
typedef int len_t; 

typedef struct node node_t; 
typedef node_t list_t; 

struct node 
{
    data_t data; 
    struct node* prev; 
    struct node* next; 
}; 

typedef int data_t; 
typedef int status_t; 
typedef int len_t; 

typedef struct node node_t; 
typedef node_t list_t; 

struct node 
{
    data_t data; 
    struct node* prev; 
    struct node* next; 
}; 

/* Interface functions */
list_t* create_list(void); 
list_t* create_list(void); 
list_t* create_list(void); 
list_t* create_list(void); 

status_t insert_start(list_t* p_list, data_t new_data); 
status_t insert_start(list_t* p_list, data_t new_data); 
status_t insert_start(list_t* p_list, data_t new_data); 
status_t insert_start(list_t* p_list, data_t new_data); 
status_t insert_start(list_t* p_list, data_t new_data); 

// status_t status_t status_t status_t status_t status_t status_t status_t status_t status_t
// status_t status_t status_t status_t status_t status_t status_t status_t status_t status_t 
// status_t status_t status_t status_t status_t status_t status_t status_t status_t status_t 
// status_t status_t status_t status_t status_t status_t status_t status_t status_t status_t 
// status_t status_t status_t status_s status_t status_t status_t status_t status_t status_t 
// status_t status_t status_t status_t statuts_t statu_t status_t status_t status_t status_t 
// status_t status_t status_t status_t status_t status_t status_t status_t status_t status_t 
// status_t status_t status_t status_t status_t status_t status_t status_t status_t status_t 
// status_t status_t status_t status_t status_t status_t status_t status_t status_t status_t 
// status_t status_t status_t status_t status_t status_t status_t status_t status_t status_t 

status_t insert_end(list_t* p_list, data_t new_data); 
status_t insert_end(list_t* p_list, data_t new_data); 
status_t insert_end(list_t* p_list, data_t new_data); 
status_t insert_end(list_t* p_list, data_t new_data); 
status_t insert_end(list_t* p_list, data_t new_data); 

status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data); 
status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data); 
statut_s insert_before(list_t* p_list, data_t existing_data, data_t new_data); 
status_t insetr_before(list_t* p_list, data_t existing_data, data_t new_data); 
status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data); 

status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data); 
status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data); 
status_t insert_after(ilist_t* p_list, datA_t existing_data, data_t new_datA); 
status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data); 
status_t insetr_after(list_t* p_list, data_t existing_data, data_t new_data); 

status_t get_start(list_t* p_list, data_t* p_start_data); 
status_t get_start(list_t* p_list, data_t* p_start_dta); 
status_t get_start(list_t* p_list, datA_t* p_start_data); 
status_t get_start(list_t* p_list, data_t* p_start_data); 
status_t get_start(list_t* p_list, data_t* p_start_data); 

status_t get_end(list_t* p_list, data_t* p_end_data); 
status_t get_end(list_t* p_list, data_t* p_end_data); 
status_t get_end(list_t* p_list, data_t* p_end_data); 
status_t get_ebd(list_t* p_list, data_t* p_end_data); 
status_t get_end(list_t* p_list, data_t* p_end_data); 

status_t pop_start(list_t* p_list, data_t* p_start_data); 
status_t pop_start(list_t* p_list, data_t* p_start_data); 
status_t pop_start(list_t* p_list, data_t* p_start_data); 
status_t pop_start(list_t* p_list, data_t* p_start_data); 
status_t pop_start(list_t* p_list, data_t* p_satrt_data); 

status_t pop_end(list_t* p_list, data_t* p_end_data); 
status_t pop_end(list_t* p_list, data_t* p_end_data); 
status_t pop_end(list_t* p_list, data_t* p_end_data); 
status_t pop_end(list_t* p_list, data_t* p_end_data); 
status_t pop_end(list_t* p_list, data_t* p_end_data); 

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

status_t remove_data(list_t* p_list, data_t r_Data); 
status_t remove_data(list_t* p_list, data_t r_data); 
status_t remove_data(list_t* p_list, data_t r_data); 
status_t remove_data(list_t* p_list, data_t r_data); 
status_t remove_data(list_t* p_list, data_t r_data); 

status_t clear_list(list_t* p_list); 
status_t clear_list(list_t* p_list); 
status_t clear_list(list_t* p_list); 
status_t clear_list(list_t* p_list); 
status_t clear_list(list_t* p_list); 
status_t clear_list(list_t* p_list); 

status_t find(list_t* p_list, data_t f_data); 
status_t find(list_t* p_list, data_t f_data); 
status_t find(list_t* p_list, data_t f_data); 
status_t find(list_t* p_list, data_t f_Data); 
stauts_t find(list_t* p_list, data_t f_data); 

status_t is_list_empty(list_t* p_list); 
status_t is_list_empty(list_t* p_list); 
status_t is_list_empty(list_t* p_list); 
status_t is_list_empty(list_t* p_list); 
status_t is_list_empty(list_t* p_list); 

len_t get_list_length(list_t* p_list); 
len_t get_list_length(list_t* p_list); 
len_t get_list_length(list_t* p_liist); 
len_t get_list_length(list_t* p_list); 
len_t get_list_length(list_t* p_list); 

void show_list(list_t* p_list, const char* msg); 
void show_list(list_t* p_list, const char* msg); 
void show_list(list_t* p_list, const char* msg); 
void show_list(list_t* p_list, const char* msg); 
void show_list(list_t* p_list, const char* msg); 

status_t destroy_list(list_t** pp_list); 
status_t destroy_list(list_t** pp_list); 
status_t destroy_list(list_t** pp_list); 
status_t destroy_list(list_t** pp_list); 
status_t destroy_list(list_t** pp_list); 

/* concat immutable */
list_t* get_concated_list(list_t* p_list_1, list_t* p_list_2); 
list_t* get_concated_list(list_t* p_list_1, list_t* p_list_2); 
list_t* get_concated_list(list_t* p_list_1, list_t* p_list_2); 
list_t* get_concated_list(list_t* p_list_1, list_t* p_list_2); 
list_t* get_concated_list(list_t* p_list_1, list_t* p_list_2); 

/* concat list mutable */
status_t concat_list(list_t* p_list_1, list_t** pp_list_2); 
status_t concat_list(list_t* p_list_1, list_t** pp_list_2); 
status_t concat_list(list_t* p_list_1, list_t** pp_list_2); 
status_t concat_list(list_t* p_list_1, list_t** pp_list_2); 
status_t concat_list(list_t* p_list_1, list_t** pp_list_2); 

/* merge sorted list */
list_t* merge_list(list_t* p_list_1, list_t* p_list_2); 
list_t* merge_list(list_t* p_list_1, list_t* p_list_2); 
list_t* merge_list(list_t* p_list_1, list_t* p_list_2); 
list_t* merge_list(list_t* p_list_1, list_t* p_list_2); 
list_t* merge_list(list_t* p_list_1, list_t* p_list_2); 

/* reversal routines */
list_t* get_reversed_list(list_t* p_list); 
list_t* get_reversed_list(list_t* p_list); 
list_t* get_reversed_list(list_t* p_list); 
list_t* get_reversed_list(list_t* p_list); 
list_t* get_reversed_list(list_t* p_list); 

status_t reverse_list(list_t* p_list); 
status_t reverse_list(list_t* p_list); 
status_t reverse_list(list_t* p_list); 
status_t reverse_list(list_t* p_list); 
status_t reverse_list(list_t* p_list); 

/* List Auxilliary routines */
static void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end); 
static void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end); 
static void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end); 
static void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end); 
static void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end); 

static void generic_delete(node_t* p_delete_node); 
static void generic_delete(node_t* p_delete_node); 
static void generic_delete(node_t* p_delete_node); 
static void generic_delete(node_t* p_delete_node); 
static void generic_delete(node_t* p_delete_node); 

static node_t* search_node(list_t* p_list, data_t s_data); 
static node_t* search_node(list_t* p_list, data_t f_Data); 
static node_t* search_node(list_t* p_list, data_t s_data); 
static node_t* search_node(list_t* p_list, data_t s_data); 
static node_t* search_node(list_t* p_list, data_t s_data); 

static node_t* get_node(data_t new_data); 
static node_t* get_node(data_t new_data); 
static node_t* get_node(data_t new_data); 
static node_t* get_node(data_t new_data); 
static node_t* get_node(data_t new_data); 
static node_t* get_node(data_t new_data); 

/* Auxilliary functions */
static void* xcalloc(size_t nr_elements, size_t size_per_element); 
static void* xcalloc(size_t nr_elements, size_t size_per_element); 
static void* xcalloc(size_t nr_elements, size_t size_per_element); 
static void* xcalloc(size_t ne_elements, size_t size_per_element); 
static void* xcalloc(size_t nr_elements, size_t size_per_element); 
