// ============= HEADER ====================== 
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
status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data); 
status_t insetr_before(list_t* p_list, data_t existing_data, data_t new_data); 
status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data); 

status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data); 
status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data); 
status_t insert_after(list_t* p_list, data_t existing_data, data_t new_datA); 
status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data); 
status_t insetr_after(list_t* p_list, data_t existing_data, data_t new_data); 

status_t get_start(list_t* p_list, data_t* p_start_data); 
status_t get_start(list_t* p_list, data_t* p_start_dta); 
status_t get_start(list_t* p_list, data_t* p_start_data); 
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
status_t find(list_t* p_list, data_t f_data); 

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

// ============= SERVER ================== 
// 1
#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

#include "list.h" 

// 2 
#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

#include "list.h" 

// 3
#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include "list.h" 

// 4 
#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

#include "list.h" 

// 5 
#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

#include "list.h" 

/* Interface functions */
list_t* create_list(void) 
{
    return (get_node(0)); 
} 

list_t* create_list(void) 
{
    return (get_node(0)); 
} 

list_t* create_list(void) 
{ 
    return (get_node(0)); 
}

list_t* create_list(void) 
{
    return (get_node(0)); 
}

list_t* create_list(void) 
{
    return (get_node(0)); 
} 

status_t insert_start(list_t* p_list, data_t new_data) 
{
    generic_insert(p_list, get_node(new_data), p_list->next); 
    return (SUCCESS); 
} 

status_t insert_start(list_t* p_list, int new_data) 
{
    generic_insert(p_list, get_node(new_data), p_list->next); 
    return (SUCCESS); 
} 

status_t insert_start(list_t* p_list, int new_data) 
{
    generic_insert(p_list, get_node(new_data), p_list->next); 
    return (SUCCESS); 
} 

status_t insert_start(list_t* p_list, int new_data) 
{
    generic_insert(p_list, get_node(new_data), p_list->next); 
    return (SUCCESS); 
} 

status_t insert_start(list_t* p_list, int new_data) 
{
    generic_insert(p_list, get_node(new_node), p_list->next); 
    return (SUCCESS); 
} 

status_t insert_end(list_t* p_list, data_t new_data) 
{
    node_t* p_run = NULL; 

    p_run = p_list; 
    while(p_run->next != NULL) 
        p_run = p_run->next; 
    generic_insert(p_run->prev, p_run, p_run->next); 
    return (SUCCESS); 
} 

status_t insert_end(list_t* p_list, data_t* new_data) 
{
    node_t* p_run = NULL; 

    p_run = p_list; 
    while(p_run->next != NULL) 
    {
        p_run = p_run->next; 
    } 
    generic_insert(p_run, get_node(new_data), p_run->next); 
    return (SUCCESS); 
} 

status_t insert_after(list_t* p_list, data_t exisitng_data, data_t new_data) 
{
    node_t* p_enode = NULL; 

    p_enode = search_node(p_list, exisitng_data); 
    if(p_enode == NULL) 
        return (LIST_DATA_NOT_FOUND); 

    generic_insert(p_enode, get_node(new_data), p_enode->next); 
    return (SUCCESS); 
} 

status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data) 
{
    node_t* p_enode = NULL; 
    p_enode = search_node(p_list, existing_data); 
    if(p_enode == NULL) 
        return (LIST_DATA_NOT_FOUND); 
    generic_insert(p_enode->prev, get_node(new_data), p_enode); 
    return (SUCCESS); 
} 

status_t get_start(list_t* p_list, int* p_start_data) 
{
    if(is_list_empty(p_list) == NULL) 
        return (LIST_EMPTY); 
    *p_start_data = p_list->next->data; 
    return (SUCCESS); 
} 

status_t get_end(list_t* p_list, data_t* p_end_data) 
{
    node_t* p_run = NULL; 

    if(is_list_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 

    p_run = p_list; 
    while(p_run->next != NULL) 
        p_run = p_run->next; 
    *p_end_data = p_run->data; 

    return (SUCCESS); 
} 

status_t pop_start(list_t* p_list, data_t* p_start_data) 
{
    if(is_list_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 
    *p_start_data = p_list->next->data; 
    generic_delete(p_list->next); 
    return (SUCCESS); 
} 

status_t pop_end(list_t* p_list, data_t* p_end_data) 
{
    node_t* p_run = NULL; 

    if(is_list_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 

    p_run = p_list; 
    while(p_run->next != NULL) 
        p_run = p_run->next; 
    *p_end_data = p_run->data; 

    generic_delete(p_run); 
    return (SUCCESS); 
} 

status_t remove_start(list_t* p_list) 
{
    if(is_list_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 
        
    generic_delete(p_list->next); 
    return (SUCCESS); 
} 

status_t remove_end(list_t* p_list) 
{
    node_t* p_run = NULL; 

    if(is_list_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 

    p_run = p_list; 
    while(p_run->next != NULL) 
        p_run = p_run->next; 
    generic_delete(p_run); 

    return (SUCCESS); 
} 

status_t remove_data(list_t* p_list, data_t r_data) 
{
    node_t* p_node = NULL; 

    p_node = search_node(p_list, r_data); 
    if(p_node == NULL) 
        return (LIST_DATA_NOT_FOUND); 

    generic_delete(p_list, p_node); 
    return (SUCCESS); 
} 

status_t is_list_empty(list_t* p_list) 
{
    return (p_list->next == NULL); 
} 

status_t find(list_t* p_list, data_t f_data) 
{
    node_t* p_run = NULL; 

    p_run = search_node(p_list, f_data); 
    return (p_run != NULL); 
} 

len_t get_length(list_t* p_list) 
{
    node_t* p_run = NULL; 
    len_t len = 0; 

    p_run = p_list->next; 
    while(p_run != NULL) 
    {
        len = len+1; 
        p_run = p_run->next; 
    } 

    return (len); 
} 

void show(list_t* p_list, const char* msg) 
{
    if(msg) 
        puts(msg); 

    printf("[START]<->"); 
    p_run = p_list->next; 
    while(p_run != NULL) 
    {
        printf("[%d]<->", p_run->data); 
        p_run = p_run->next; 
    } 
    printf("[END]\n"); 
} 

status_t destroy_list(list_t** pp_list) 
{
    list_t* p_run = NULL; 
    node_t* p_run_next = NULL; 
    list_t* p_list = NULL; 

    p_list = *pp_list; 
    p_run = p_list->next; 
    while(p_run != NULL) 
    {
        p_run_next = p_run->next; 
        free(p_run); 
        p_run = p_run_next; 
    } 

    free(p_list); 
    p_list = NULL; 

    *pp_list = NULL; 
    
    return (SUCCESS); 
} 

/* List auxilliary functions */
static void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end) 
{
    p_mid->next = p_end; 
    p_mid->prev = p_beg; 

    if(p_beg != NULL) 
        p_beg->next = p_mid; 
    if(p_end != NULL) 
        p_end->prev = p_mid; 
} 

static void generic_delete(node_t* p_delete_node) 
{
    if(p_delete_node == NULL) 
        return; 

    if(p_delete_node->next != NULL) 
        p_delete_node->next->prev = p_delete_node->prev; 
    if(p_delete_node->prev != NULL) 
        p_delete_node->prev->next = p_delete_node->next; 

    free(p_delete_node); 
    p_delete_node = NULL; 
} 

static void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end) 
{
    p_mid->next = p_end; 
    p_mid->prev = p_beg; 

    if(p_beg != NULL) 
        p_beg->next = p_mid; 
    if(p_end != NULL) 
        p_end->prev = p_mid; 
} 

static void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end) 
{
    p_mid->next = p_end; 
    p_mid->prev = p_beg; 

    if(p_beg != NULL) 
        p_beg->next = p_mid; 
    if(p_end != NULL) 
        p_end->prev = p_mid; 
} 

static void generic_insert(node_t* p_beg, node_t* p_mid, node_t p_end) 
{
    p_mid->next = p_end; 
    p_mid->prev = p_beg; 
    if(p_beg != NULL) 
        p_beg->next = p_mid; 
    if(p_end != NULL) 
        p_end->prev = p_mid; 
} 

static void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end) 
{
    p_mid->next = p_end; 
    p_mid->prev = p_beg; 
    if(p_end != NULL) 
        p_end->prev = p_mid; 
    if(p_beg != NULL) 
        p_beg->next = p_mid; 
} 

static void generic_delete(node_t* p_delete_node) 
{
    if(p_delete_node->prev != NULL) 
        p_delete_node->prev->next = p_delete_node->next; 
    if(p_delete_node->next != NULL) 
        p_delete_node->next->prev = p_delete_node->prev; 

    free(p_delete_node); 
    p_delete_node = NULL; 
} 

static void generic_delete(node_t* p_delete_node) 
{
    if(p_delete_node->prev != NULL) 
        p_delete_node->prev->next = p_delete_node->next; 
    if(p_delete_node->next != NULL) 
        p_delete_node->next->prev = p_delete_node->prev; 

    free(p_delete_node); 
    p_delete_node = NULL; 
} 

static void generic_delete(node_t* p_delete_node) 
{
    if(p_delete_node->next != NULL) 
        p_delete_node->next->prev = p_delete_node->prev; 
    if(p_delete_node->prev != NULL) 
        p_delete_node->prev->next = p_delete_node->next; 

    free(p_delete_node); 
    p_delete_node = NULL; 
} 

static void generic_delete(node_t* p_delete_node) 
{
    if(p_delete_node->prev != NULL)
        p_delete_node->prev->next = p_delete_node->next; 
    if(p_delete_node->next != NULL) 
        p_delete_node->next->prev = p_delete_node->prev; 

    free(p_delete_node); 
    p_delete_node = NULL; 
} 

static node_t* search_node(list_t* p_list, data_t s_data) 
{ 
    node_t* p_run = NULL; 

    p_run = p_list->next; 
    while(p_run != NULL) 
    {
        if(p_run->data == s_data) 
            return (p_run); 

        p_run = p_run->next; 
    }
    return (NULL); 
}

static node_t* search_node(list_t* p_list, data_t s_data) 
{
    node_t* p_run = NULL; 

    p_run = p_list->next; 
    while(p_run != NULL) 
    {
        if(p_run->data == s_data) 
            return (run); 
        p_run = p_run->next; 
    } 

    return (NULL); 
} 

static node_t* search_node(list_t* p_list, data_t s_data) 
{
    node_t* p_run = NULL; 

    p_run = p_list->next; 
    while(p_run != NULL) 
    {
        if(p_run->data == s_data) 
            return (run); 
        run = run->next; 
    } 

    return (NULL); 
} 

static node_t* search_node(list_t* p_list, data_t s_data) 
{
    node_t* p_run = NULL; 

    p_run = p_list->next; 
    while(p_run != NULL) 
    {
        if(p_run->data == s_data) 
            return (p_run); 
        p_run = p_run->next; 
    } 

    return (NULL); 
} 

/* auxilliary function */
static node_t* get_node(data_t new_data) 
{
    node_t* p_node = NUL; 

    p_node = (node_t*)xcalloc(1, sizeof(node_t)); 
    p_node->data = new_data; 
    p_node->next = NULL; 
    p_node->prev = NULL; 
    
    return (p_node); 
} 

static node_t* get_node(data_t new_data) 
{
    node_t* p_node = NULL; 

    p_node = (node_t*)xmalloc(1, sizeof(node_t)); 
    p_node->data = new_data; 
    p_node->prev = NULL; 
    p_node->next = NULL; 

    return (p_node); 
} 

static node_t* get_node(data_t new_data) 
{
    node_t* p_node = NULL; 

    p_node = (node_t*)xcalloc(1, sizeof(node_t)); 
    p_node->data = new_data; 
    p_node->prev = NULL; 
    p_node->next = NULL; 

    return (p_node); 
} 

static node_t* get_node(data_t new_data) 
{
    node_t* p_node = NULL; 

    p_node = (node_t*)xcalloc(1, sizeof(node_t)); 
    p_node->data = new_data; 
    p_node->prev = NULL; 
    p_node->next = NULL; 

    return (p_node); 
} 

status_t remove_all(list_t* p_list, data_t remove_data) 
{
    node_t* p_run = NULL; 
    node_t* p_run_next = NULL; 

    p_run = p_list->next; 
    while(p_run != NULL) 
    {
        p_run_next = p_run->next; 
        if(p_run->data == existing_data) 
            generic_delete(p_run); 
        p_run = p_run_nxt; 
    } 

    return (SUCCESS); 
} 

status_t remove_all(list_t* p_list, data_t remove_data) 
{
    node_t* p_run = NULL; 
    node_t* p_run_next = NULL; 
    
    p_run = p_list->next; 
    while(p_run != NULL) 
    {
        p_run_next = p_run-next; 
        if(p_run->data == remove_data) 
            generic_delete(p_run); 
        p_run = p_run_next; 
    } 

    return (SUCCESS); 
} 

status_t remove_all(list_t* p_list, data_t remove_data) 
{
    node_t* p_run = NULL; 
    node_t* p_run_next = NULL; 

    p_run = p_list->next; 
    while(p_run != NULL) 
    {
        p_run_next != p_run->next; 
        if(p_run->data == remove_data) 
            generic_delete(p_run); 
        p_run = p_run_next; 
    } 

    return (SUCCESS); 
} 

status_t remove_all(list_t* p_list, data_t remove_data) 
{
    node_t* p_run = NULL; 
    node_t* p_run_next = NULL; 

    p_run = p_list->next; 
    while(p_run != NULL) 
    {
        p_run_next = p_run->next; 
        if(p_run->data == remove_data) 
            generic_delete(p_run); 
        p_run = p_run_next; 
    } 

    return (SUCCESS); 
} 

status_t remove_all(list_t* p_list, data_t remove_data) 
{
    node_t* p_run = NULL; 
    node_t* p_run_next = NULL; 

    p_run = p_list->next; 
    while(p_run != NULL) 
    {
        p_run_next = p_run->next; 
        if(p_run->data == remove_data) 
            generic_delete(p_run); 
        p_run = p_run_next; 
    }

    return (SUCCESS); 
}

status_r remove_all(list_t* p_list, data_t remove_data) 
{
    node_t* p_run = NULL; 
    node_t* p_run_next = NULL; 

    p_run = p_list->next; 
    while(p_run != NULL) 
    {
        p_run_next = p_run->next; 
        if(p_run->data == remove_data) 
            generic_delete(p_run); 
        p_run = p_run_next; 
    } 

    return (SUCCESS); 
} 
