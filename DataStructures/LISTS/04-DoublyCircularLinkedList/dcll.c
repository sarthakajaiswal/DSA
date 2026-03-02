/*********************************************************************************
 * 
 *      DOUBLY CIRCULAR LINKED LIST 
 * 
 *      Author:  Sarthak A. Jaiswal 
 *      Date:    01 MARCH 2025 
 * 
 **********************************************************************************/

#include "dcll.h" 

/* List interface functions */ 
// creation 
list_t* 
create_list(void) 
{
    list_t* p_list = NULL; 

    p_list = get_node(0); 
    p_list->prev = p_list; 
    p_list->next = p_list; 

    return (p_list); 
} 

// data insertion 
status_t 
insert_start(list_t* p_list, data_t new_data) 
{
    node_t* new_node = NULL; 

    new_node = get_node(new_data); 
    generic_insert(p_list, new_node, p_list->next); 
    return (SUCCESS); 
} 

status_t 
insert_end(list_t* p_list, data_t new_data) 
{
    node_t* new_node = NULL; 

    new_node = get_node(new_data); 
    generic_insert(p_list->prev, new_node, p_list); 
    return (SUCCESS); 
} 

status_t 
insert_before(list_t* p_list, data_t existing_data, data_t new_data)
{
    node_t* existing_node = NULL; 
    node_t* new_node = NULL; 

    existing_node = search_node(p_list, existing_data); 
    if(NULL == existing_node) 
        return (LIST_DATA_NOT_FOUND); 

    new_node = get_node(new_data); 
    generic_insert(existing_node->prev, new_node, existing_node); 
    return (SUCCESS); 
} 

status_t 
insert_after(list_t* p_list, data_t existing_data, data_t new_data) 
{
    node_t* existing_node = NULL; 
    node_t* new_node = NULL; 

    existing_node = search_node(p_list, existing_data); 
    if(NULL == existing_node) 
        return (LIST_DATA_NOT_FOUND); 

    new_node = get_node(new_data); 
    generic_insert(existing_node, new_node, existing_node->next); 
    return (SUCCESS); 
} 

// getters 
status_t 
get_start(list_t* p_list, data_t* p_start_data) 
{
    if(is_list_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 
    *p_start_data = p_list->next->data; 
    return (SUCCESS); 
} 

status_t 
get_end(list_t* p_list, data_t* p_end_data) 
{
    if(is_list_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 
    *p_end_data = p_list->prev->data; 
    return (SUCCESS); 
} 

// pop functions 
status_t 
pop_start(list_t* p_list, data_t* p_start_data) 
{
    if(is_list_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 

    *p_start_data = p_list->next->data;
    generic_delete(p_list->next); 
    return (SUCCESS); 
} 

status_t 
pop_end(list_t* p_list, data_t* p_end_data) 
{
    if(is_list_empty(p_list) == TRUE)
        return (LIST_EMPTY); 

    *p_end_data = p_list->prev->data; 
    generic_delete(p_list->prev); 
    return (SUCCESS); 
} 

// data removal 
status_t 
remove_start(list_t* p_list) 
{
    if(is_list_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 
    
    generic_delete(p_list->next); 
    return (SUCCESS); 
} 

status_t 
remove_end(list_t* p_list) 
{
    if(is_list_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 

    generic_delete(p_list->prev); 
    return (SUCCESS); 
} 

status_t 
remove_data(list_t* p_list, data_t r_data) 
{
    node_t* remove_node = NULL; 

    remove_node = search_node(p_list, r_data); 
    if(NULL == remove_node) 
        return (LIST_DATA_NOT_FOUND); 

    generic_delete(remove_node); 
    return (SUCCESS); 
} 

status_t 
clear_list(list_t* p_list) 
{
    node_t* p_run = NULL; 
    node_t* p_run_next = NULL; 

    p_run = p_list->next; 
    while(p_run != p_list) 
    {
        p_run_next = p_run->next; 
        free(p_run); 
        p_run = p_run_next; 
    } 
 
    p_list->next = p_list; 
    p_list->prev = p_list; 

    return (SUCCESS); 
} 

// miscalleneous function 
list_t* 
to_list(data_t* p_array, size_t p_array_size) 
{
    list_t* p_new_list = NULL; 
    size_t i; 

    p_new_list = create_list(); 

    for(i = 0; i < p_array_size; ++i); 
        assert(insert_end(p_new_list, p_array[i]) == SUCCESS); 

    return (p_new_list); 
} 

data_t* 
to_array(list_t* p_list, size_t* p_array_size) 
{
    data_t* p_arr = NULL; 
    node_t* p_run = NULL; 
    len_t list_length; 

    list_length = get_list_length(p_list); 
    if(list_length == 0) 
    {
        *p_array_size = 0; 
        return (NULL); 
    } 

    p_arr = (data_t*)xmalloc(sizeof(data_t) * list_length); 

    size_t i = 0; 
    for(p_run = p_list->next; p_run != NULL; p_run = p_run->next, i++) 
        p_arr[i] = p_run->data; 

    *p_array_size = list_length; 
    return (p_arr); 
} 

status_t 
is_list_empty(list_t* p_list) 
{
    return (p_list->next == p_list && p_list->prev == p_list); 
} 

status_t 
find_in_list(list_t* p_list, data_t f_data) 
{
    node_t* p_run = NULL; 

    p_run = p_list->next; 
    while(p_run != p_list) 
    {
        if(p_run->data == f_data)   
            return (TRUE); 
        p_run = p_run->next; 
    } 

    return (FALSE); 
} 

len_t 
get_list_length(list_t* p_list) 
{
    node_t* p_run = NULL; 
    len_t length = 0; 

    p_run = p_list->next; 
    while(p_run != p_list) 
    {
        length += 1; 
        p_run = p_run->next; 
    } 

    return (length); 
} 

void 
show_list(list_t* p_list, const char* msg) 
{
    node_t* p_run = NULL; 

    if(msg) 
        puts(msg); 

    fprintf(stdout, "[START]<->"); 
    p_run = p_list->next; 
    while(p_run != p_list) 
    {
        fprintf(stdout, "[%d]<->", p_run->data); 
        p_run = p_run->next; 
    } 
    puts("[END]"); 
} 

// destruction 
status_t 
destroy_list(list_t** pp_list) 
{
    list_t* p_list = NULL; 

    p_list = *pp_list; 
    if(p_list != NULL) 
    {
        clear_list(p_list); 
        free(p_list); 
        p_list = NULL; 
        *pp_list = NULL; 
    } 

    return (SUCCESS); 
} 

// reversal routines 
list_t* 
get_reversed_list(list_t* p_list) 
{
    node_t* p_run = NULL; 
    list_t* p_reversed_list = NULL; 

    p_reversed_list = create_list(); 

    p_run = p_list->next; 
    while(p_run != p_list) 
    {
        assert(insert_start(p_reversed_list, p_run->data) == SUCCESS); 
        p_run = p_run->next; 
    } 

    return (p_reversed_list); 
} 

status_t 
reverse_list(list_t* p_list) 
{
    node_t* p_first_node = NULL; 
    node_t* p_run = NULL; 
    node_t* p_run_next = NULL; 

    if(p_list->next == p_list || p_list->next->next == p_list) 
        return (SUCCESS); 

    p_first_node = p_list->next; 
    p_run = p_first_node->next; 
    p_first_node->next = p_list; // break the remaining list from main list  

    // insert elements from broken list into main list one-by-one 
    while(p_run != p_list) 
    {
        p_run_next = p_run->next; 
        generic_insert(p_list, p_run, p_list->next);
        p_run = p_run->next;  
    } 

    return (SUCCESS); 
}  

// interlist routines 
list_t* 
get_concated_list(list_t* p_list_1, list_t* p_list_2) 
{
    list_t* p_concated_list = NULL; 
    node_t* p_run = NULL; 

    p_concated_list = create_list(); 
    p_run = p_list_1->next; 
    while(p_run != p_list_1) 
    {
        assert(insert_end(p_concated_list, p_run->data) == SUCCESS); 
        p_run = p_run->next; 
    } 

    p_run = p_list_2->next; 
    while(p_run != p_list_2) 
    {
        assert(insert_end(p_concated_list, p_run->data) == SUCCESS); 
        p_run = p_run->next; 
    } 

    return (p_concated_list); 
} 

status_t 
concat_lists(list_t* p_list_1, list_t** pp_list_2) 
{
    list_t* p_list_2 = NULL; 

    p_list_2 = *pp_list_2; 
    
    if(is_list_empty(p_list_2) == TRUE) 
    {
        free(p_list_2); 
        p_list_2 = NULL; 
        *pp_list_2 = NULL; 
        return (SUCCESS); 
    }  

    p_list_1->prev->next = p_list_2->next; 
    p_list_2->prev->next = p_list_1; 
    p_list_2->next->prev = p_list_1->prev;  
    p_list_1->prev = p_list_2->prev; 

    free(p_list_2); 
    p_list_2 = NULL; 
    *pp_list_2 = NULL; 

    return (SUCCESS); 
} 

list_t* 
merge_lists(list_t* p_list_1, list_t* p_list_2) 
{
    list_t* p_merged_list = NULL; 
    node_t* p_run_1 = NULL; 
    node_t* p_run_2 = NULL; 

    p_merged_list = create_list(); 

    p_run_1 = p_list_1->next; 
    p_run_2 = p_list_2->next; 
    while(TRUE) 
    {
        if(p_run_1 == p_list_1) 
        {
            while(p_run_2 != p_list_2) 
            {
                assert(insert_end(p_merged_list, p_run_2->data) == SUCCESS); 
                p_run_2 = p_run_2->next; 
            } 
            break; 
        } 

        if(p_run_2 == p_list_2) 
        {
            while(p_run_1 != p_list_1) 
            {
                assert(insert_end(p_merged_list, p_run_1->data) == SUCCESS); 
                p_run_1 = p_run_1->next; 
            } 
            break; 
        } 

        if(p_run_1->data <= p_run_2->data) 
        {
            assert(insert_end(p_merged_list, p_run_1->data) == SUCCESS); 
            p_run_1 = p_run_1->next; 
        } 
        else 
        {
            assert(insert_end(p_merged_list, p_run_2->data) == SUCCESS); 
            p_run_2 = p_run_2->next; 
        } 
    } 

    return (p_merged_list); 
} 

/* list helper functions */ 
node_t* 
get_node(data_t new_data) 
{
    node_t* new_node = NULL; 

    new_node = (node_t*)xmalloc(sizeof(node_t)); 
    new_node->data = new_data; 
    new_node->prev = NULL; 
    new_node->next = NULL; 

    return (new_node); 
} 

void 
generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end) 
{
    p_mid->prev = p_beg; 
    p_mid->next = p_end; 
    p_beg->next = p_mid; 
    p_end->prev = p_mid; 
} 

void 
generic_delete(node_t* p_delete_node) 
{
    p_delete_node->prev->next = p_delete_node->next; 
    p_delete_node->next->prev = p_delete_node->prev; 
} 

node_t* 
search_node(list_t* p_list, data_t search_data) 
{
    node_t* p_run = NULL; 

    p_run = p_list->next; 
    while(p_run != p_list) 
    {
        if(p_run->data == search_data) 
            return (p_run); 
        p_run = p_run->next; 
    } 

    return (NULL); 
} 

// general purpose helper functions 
void* 
xmalloc(size_t size_in_bytes) 
{
    void* p = NULL; 

    p = malloc(size_in_bytes); 
    if(NULL == p) 
    {
        fprintf(stderr, "memory allocation failure\n"); 
        exit(EXIT_FAILURE); 
    } 

    return (p); 
} 
