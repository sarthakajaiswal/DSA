/*********************************************************************************
 * 
 *      DOUBLY LINKED LIST 
 * 
 * Author:  Sarthak A. Jaiswal 
 * Date:    02 MARCH 2025 
 * 
 **********************************************************************************/

#include "dll.h" 

/* Interface function declarations */ 
/* creation */ 
list_t* 
create_list(void) 
{
    list_t* p_new_list = NULL; 

    p_new_list = get_node(0); 
    return (p_new_list); 
} 

/* data insertion */ 
status_t 
insert_start(list_t* p_list, data_t new_data) 
{
    node_t* p_new_node = NULL; 

    p_new_node = get_node(new_data); 
    generic_insert(p_list, p_new_node, p_list->next); 
    return (SUCCESS); 
} 

status_t 
insert_end(list_t* p_list, data_t new_data) 
{
    node_t* p_new_node = NULL; 
    node_t* p_run = NULL; 

    p_new_node = get_node(new_data); 

    // get last node 
    p_run = p_list; 
    while(p_run->next != NULL) 
        p_run = p_run->next; 

    p_new_node->prev = p_run; 
    p_run->next = p_new_node; 

    return (SUCCESS); 
} 

status_t 
insert_after(list_t* p_list, data_t existing_data, data_t new_data) 
{
    node_t* p_new_node = NULL; 
    node_t* p_existing_node = NULL; 

    p_existing_node = search_node(p_list, existing_data); 
    if(NULL == p_existing_node) 
        return (LIST_DATA_NOT_FOUND); 

    p_new_node = get_node(new_data); 
    generic_insert(p_existing_node, p_new_node, p_existing_node->next); 

    return (SUCCESS); 
} 

status_t 
insert_before(list_t* p_list, data_t existing_data, data_t new_data) 
{
    node_t* p_new_node = NULL; 
    node_t* p_existing_node = NULL; 

    p_existing_node = search_node(p_list, existing_data); 
    if(NULL == p_existing_node) 
        return (LIST_DATA_NOT_FOUND); 

    p_new_node = get_node(new_data); 
    generic_insert(p_existing_node->prev, p_new_node, p_existing_node); 

    return (SUCCESS); 
} 

/* getters */ 
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
    node_t* p_run = NULL; 

    if(is_list_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 

    // get last node 
    p_run = p_list->next; 
    while(p_run->next != NULL) 
        p_run = p_run->next; 
    
    *p_end_data = p_run->data; 
    return (SUCCESS); 
} 

/* pop functions */ 
status_t 
pop_start(list_t* p_list, data_t* p_popped_data) 
{
    if(is_list_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 

    *p_popped_data = p_list->next->data; 
    generic_delete(p_list->next); 
    return (SUCCESS); 
} 

status_t 
pop_end(list_t* p_list, data_t* p_popped_data) 
{
    node_t* p_run = NULL; 

    if(is_list_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 

    // get last node 
    p_run = p_list->next; 
    while(p_run->next != NULL) 
        p_run = p_run->next; 

    *p_popped_data = p_run->data; 
    generic_delete(p_run); 
    return (SUCCESS); 
} 

/* data removal */ 
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
    node_t* p_last_node = NULL; 

    if(is_list_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 

    p_last_node = p_list->next; 
    while(p_last_node->next != NULL) 
        p_last_node = p_last_node->next; 

    generic_delete(p_last_node); 
    return (SUCCESS); 
} 

status_t 
remove_data(list_t* p_list, data_t r_data) 
{
    node_t* p_remove_node = NULL; 

    p_remove_node = search_node(p_list, r_data); 
    if(NULL == p_remove_node) 
        return (LIST_DATA_NOT_FOUND); 

    generic_delete(p_remove_node); 
    return (SUCCESS); 
} 

status_t 
clear_list(list_t* p_list) 
{
    node_t* p_run = NULL; 
    node_t* p_run_next = NULL; 

    p_run = p_list->next; 
    while(p_run != NULL) 
    {
        p_run_next = p_run->next; 
        free(p_run); 
        p_run = p_run_next; 
    } 

    p_list->next = NULL; 
    return (SUCCESS); 
} 

/* miscalleneous */ 
list_t*    
to_list(data_t* p_array, size_t array_size) 
{
    list_t* p_new_list = NULL; 
    size_t i = 0; 

    p_new_list = create_list(); 
    for(i = 0; i < array_size; ++i) 
        assert(insert_end(p_new_list, p_array[i]) == SUCCESS); 

    return (p_new_list); 
} 

data_t*     
to_array(list_t* p_list, size_t* p_array_size) 
{
    node_t* p_run = NULL; 
    data_t* p_array = NULL; 
    len_t list_length = 0; 

    list_length = get_list_length(p_list); 
    if(list_length == 0) 
    {
        *p_array_size = 0;
        return (NULL); 
    } 

    p_array = (data_t*)xmalloc(sizeof(data_t) * list_length); 

    p_run = p_list->next; 
    int i = 0; 
    while(p_run != NULL) 
    {
        p_array[i] = p_run->data; 
        p_run = p_run->next; 
        i += 1; 
    } 

    *p_array_size = list_length; 
    return (p_array); 
} 

status_t    
is_list_empty(list_t* p_list) 
{
    return (p_list->next == NULL && p_list->prev == NULL); 
} 

status_t    
find_in_list(list_t* p_list, data_t f_data) 
{
    return (search_node(p_list, f_data) != NULL); 
} 

len_t       
get_list_length(list_t* p_list) 
{
    node_t* p_run = NULL; 
    len_t length = 0; 

    p_run = p_list->next; 
    while(p_run != NULL) 
    {
        p_run = p_run->next; 
        length += 1; 
    }

    return (length); 
} 

void        
show_list(list_t* p_list, const char* msg) 
{
    node_t* p_run = NULL; 

    if(msg) 
        puts(msg); 

    printf("[START]<->"); 
    p_run = p_list->next; 
    while(p_run != NULL) 
    {
        printf("[%d]<->", p_run->data); 
        p_run = p_run->next; 
    } 
    puts("[END]"); 
} 

/* reversal routines */ 
list_t* 
get_reversed_list(list_t* p_list) 
{
    list_t* p_reversed_list = NULL; 
    node_t* p_run = NULL; 

    p_reversed_list = create_list(); 

    p_run = p_list->next; 
    while(p_run != NULL) 
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

    if(p_list->next == NULL || p_list->next->next == NULL) 
        return (SUCCESS); 

    p_first_node = p_list->next; 
    p_run = p_list->next->next; 
    p_first_node->next = NULL;  // break the remaining list from main list 

    // insert elements from broken list into main list one-by-one 
    while(p_run != NULL) 
    {
        p_run_next = p_run->next; 
        generic_insert(p_list, p_run, p_first_node); 
        p_first_node = p_run; 

        p_run = p_run_next; 
    } 
    
    return (SUCCESS); 
} 

/* interlist routines */ 
list_t* 
get_concated_list(list_t* p_list_1, list_t* p_list_2) 
{
    list_t* p_concated_list = NULL; 
    node_t* p_run = NULL; 

    p_concated_list = create_list(); 

    for(p_run = p_list_1->next; p_run != NULL; p_run = p_run->next) 
        assert(insert_end(p_concated_list, p_run->data) == SUCCESS); 

    for(p_run = p_list_2->next; p_run != NULL; p_run = p_run->next) 
        assert(insert_end(p_concated_list, p_run->data) == SUCCESS);
        
    return (p_concated_list); 
} 

status_t 
concat_lists(list_t* p_list_1, list_t** pp_list_2) 
{
    list_t* p_list_2 = NULL; 
    node_t* p_last_node = NULL; 

    p_list_2 = *pp_list_2; 

    // get last node of p_list_1 
    p_last_node = p_list_1; 
    while(p_last_node->next != NULL) 
        p_last_node = p_last_node->next; 

    p_last_node->next = p_list_2->next; 
    if(is_list_empty(p_list_2) == FALSE) 
        p_list_2->next->prev = p_last_node; 

    free(p_list_2); 
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
        if(p_run_1 == NULL) 
        {
            while(p_run_2 != NULL) 
            {
                assert(insert_end(p_merged_list, p_run_2->data) == SUCCESS); 
                p_run_2 = p_run_2->next; 
            } 
            break; 
        } 
        if(p_run_2 == NULL) 
        {
            while(p_run_1 != NULL) 
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

/* destruction */ 
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

/* List helper routines */ 
node_t* 
get_node(data_t new_data) 
{
    node_t* new_node = NULL; 

    new_node = (node_t*)xmalloc(sizeof(node_t)); 
    new_node->data = new_data; 
    new_node->next = NULL; 
    new_node->prev = NULL; 

    return (new_node); 
} 

node_t* 
search_node(list_t* p_list, data_t s_data) 
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

void    
generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end) 
{
    p_mid->prev = p_beg; 
    p_mid->next = p_end; 

    p_beg->next = p_mid; 
    if(p_end != NULL) 
        p_end->prev = p_mid; 
} 

void    
generic_delete(node_t* p_delete_node) 
{
    p_delete_node->prev->next = p_delete_node->next; 
    if(p_delete_node->next != NULL) 
        p_delete_node->next->prev = p_delete_node->prev; 

    free(p_delete_node); 
    p_delete_node = NULL; 
} 

/* General Purpose heler functions */ 
void* 
xmalloc(size_t size_in_bytes) 
{
    void* p = NULL; 

    p = malloc(size_in_bytes); 
    if(NULL == p) 
    {
        fprintf(stderr, "malloc() > memory allocation failure\n"); 
        exit(EXIT_FAILURE); 
    } 

    return (p); 
} 
