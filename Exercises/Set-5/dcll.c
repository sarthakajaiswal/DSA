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
    size_t i = 0; 

    p_new_list = create_list(); 

    for(i = 0; i < p_array_size; ++i) 
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

// ---------------------------------------------------------------------------------- 

status_t 
get_second_last(list_t* p_list, data_t* p_second_last_data)
{
    if(get_list_length(p_list) < 2) 
        return (LIST_INSUFFICIENT_ELEMENTS); 

    *p_second_last_data = p_list->prev->prev->data; 
    return (SUCCESS); 
} 

status_t 
swap_first_and_last(list_t* p_list) 
{
    node_t* p_start_node = NULL; 
    node_t* p_end_node = NULL; 

    if(is_list_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 

    if(get_list_length(p_list) == 1) 
        return (SUCCESS); 

    p_start_node = p_list->next; 
    p_end_node = p_list->prev; 

    // set start node to last 
    p_start_node->next->prev = p_list; 
    p_list->next = p_start_node->next; 
    generic_insert(p_end_node, p_start_node, p_list); // make p_start_node as last node 

    // set end node to first 
    p_end_node->prev->next = p_start_node; // p_start_node became the current last 
    p_start_node->prev = p_end_node->prev; 
    generic_insert(p_list, p_end_node, p_list->next); 

    return (SUCCESS); 
} 

// like right rotate 
status_t 
move_last_to_first(list_t* p_list) 
{
    node_t* p_last_node = NULL; 

    if(is_list_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 

    p_last_node = p_list->prev; 

    p_last_node->prev->next = p_list; 
    p_list->prev = p_last_node->prev; 

    generic_insert(p_list, p_last_node, p_list->next); 
    return (SUCCESS); 
} 

status_t 
move_first_to_last(list_t* p_list) 
{
    node_t* p_first_node = NULL; 

    if(is_list_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 

    p_first_node = p_list->next; 

    p_first_node->next->prev = p_list; 
    p_list->next = p_first_node->next; 

    return (SUCCESS); 
    generic_insert(p_list->prev, p_first_node, p_list); 
} 

status_t 
check_if_sum_of_first_and_last_equals_target(list_t* p_list, data_t target) 
{
    data_t start_data = 0; 
    data_t end_data = 0; 

    get_start(p_list, &start_data); 
    get_end(p_list, &end_data); 

    if(start_data + end_data == target) 
        return (TRUE); 
    return (FALSE); 
} 

status_t 
rotate_right_by_k(list_t* p_list, size_t k) 
{
    node_t* start_of_k_subnodes = NULL; // pointer to starting node of subnodes to be rotated 
    node_t* end_of_k_subnodes = NULL;   // pointer to last node of subnodes to be rotated 

    node_t* p_run = NULL; 

    if(k > get_list_length(p_list)) 
        return (LIST_INSUFFICIENT_ELEMENTS); 

    end_of_k_subnodes = p_list->prev; 

    size_t i = 0; 
    p_run = p_list->prev; 
    while(i < k) 
    {
        p_run = p_run->prev; 
        i += 1; 
    }  
    start_of_k_subnodes = p_run->next; 

    // insert k subnodes list at starting 
    start_of_k_subnodes->prev->next = p_list; 
    p_list->prev = start_of_k_subnodes->prev; 

    end_of_k_subnodes->next = p_list->next; 
    p_list->next->prev = end_of_k_subnodes; 
    start_of_k_subnodes->prev = p_list; 
    p_list->next = start_of_k_subnodes; 

    return (SUCCESS); 
} 

status_t 
rotate_left_by_k(list_t* p_list, size_t k) 
{
    node_t* start_of_k_subnodes = NULL; // pointer to starting node of subnodes to be rotated 
    node_t* end_of_k_subnodes = NULL;   // pointer to last node of subnodes to be rotated 

    node_t* p_run = NULL; 

    if(k > get_list_length(p_list)) 
        return (LIST_INSUFFICIENT_ELEMENTS); 

    start_of_k_subnodes = p_list->next; 

    size_t i = 0; 
    p_run = p_list->next; 
    while(i < k) 
    {
        p_run = p_run->next; 
        i += 1; 
    }  
    end_of_k_subnodes = p_run->prev; 

    // join list after end_of_k_subnodes to head_node 
    end_of_k_subnodes->next->prev = p_list; 
    p_list->next = end_of_k_subnodes->next; 

    // insert k subnodes list at last 
    p_list->prev->next = start_of_k_subnodes; 
    start_of_k_subnodes->prev = p_list->prev; 
    end_of_k_subnodes->next = p_list; 
    p_list->prev = end_of_k_subnodes; 

    return (SUCCESS); 
} 

status_t 
insert_before_last(list_t* p_list, data_t new_data) 
{
    if(get_list_length(p_list) < 1) 
        return (LIST_INSUFFICIENT_ELEMENTS); 

    generic_insert(p_list->prev->prev, get_node(new_data), p_list->prev); 
    return (SUCCESS); 
} 

status_t 
delete_second_last(list_t* p_list) 
{
    if(is_list_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 

    if(get_list_length(p_list) == 1) 
        return (LIST_INSUFFICIENT_ELEMENTS); 

    generic_delete(p_list->prev->prev); 
    return (SUCCESS); 
} 

void 
traverse_n_rounds_alternate(list_t* p_list, int n) 
{
    int i = 0; 
    node_t* p_run = NULL; 

    while(i < n) 
    {
        printf("Forward: "); 
        for(p_run = p_list->next; p_run != p_list; p_run = p_run->next) 
            printf("%d ", p_run->data); 
        printf("\t"); 
        
        printf("Backward: "); 
        for(p_run = p_list->prev; p_run != p_list; p_run = p_run->prev) 
            printf("%d ", p_run->data); 

        printf("\n"); 
        
        i += 1; 
    } 
} 

list_t* 
split_into_halves(list_t* p_list) 
{
    node_t* p_middle_node = NULL; 
    list_t* p_new_list = NULL;
    len_t middle_node_number = 0; 
    len_t list_length = 0; 
    
    if(is_list_empty(p_list) == TRUE) 
        return (NULL); 

    list_length = get_list_length(p_list); 
    middle_node_number = ceil((float)list_length/2.0f); // include middle node into first list 

    int i = 0; 
    p_middle_node = p_list; 
    while(i < middle_node_number) 
    {
        p_middle_node = p_middle_node->next; 
        i += 1; 
    } 

    p_new_list = create_list(); 

    if(list_length == 1) 
        return (p_new_list); 

    p_new_list->prev = p_list->prev; 
    p_list->prev->next = p_new_list; 
    p_new_list->next = p_middle_node->next; 

    p_list->prev = p_middle_node; 
    p_middle_node->next = p_list; 

    return (p_new_list); 
} 

status_t 
interleave_lists(list_t* p_list1, list_t** pp_list2)
{
    node_t* p_run1 = NULL; 
    node_t* p_run1_next = NULL; 
    node_t* p_run2 = NULL; 
    node_t* p_run2_next = NULL; 

    list_t* p_list2 = NULL; 

    p_list2 = *pp_list2; 
    p_run1 = p_list1->next; 
    p_run2 = p_list2->next; 
    
    while(p_run1 != p_list1) 
    {
        p_run1_next = p_run1->next; 

        if(p_run2 != p_list2) 
        {
            p_run2_next = p_run2->next; 
            generic_insert(p_run1, p_run2, p_run1_next); 
            p_run2 = p_run2_next; 
        } 

        p_run1 = p_run1_next; 
    } 
    while(p_run2 != p_list2) 
    {
        p_run2_next = p_run2->next; 
        generic_insert(p_list1->prev, p_run2, p_list1); 
        p_run2 = p_run2_next; 
    } 

    free(*pp_list2); 
    *pp_list2 = NULL; 

    return (SUCCESS); 
} 

status_t 
is_list_symmetric(list_t* p_list)
{
    node_t* p_run_forward = NULL; 
    node_t* p_run_backward = NULL; 

    p_run_forward = p_list->next; 
    p_run_backward = p_list->prev; 
    
    while(p_run_forward != p_run_backward && p_run_forward->prev != p_run_backward) 
    {
        if(p_run_forward->data != p_run_backward->data) 
            break; 
        
        p_run_forward = p_run_forward->next; 
        p_run_backward = p_run_backward->prev; 
    } 

    if(p_run_forward == p_run_backward || p_run_forward->prev == p_run_backward)
        return (TRUE); 
    return (FALSE); 
} 

void 
find_pairs_with_sum(list_t* p_list, data_t target)
{
    node_t* p_run_forward = NULL; 
    node_t* p_run_backward = NULL; 

    p_run_forward = p_list->next; 
    p_run_backward = p_list->prev; 
    
    while(p_run_forward != p_run_backward && p_run_forward->prev != p_run_backward) 
    {
        if(p_run_forward->data + p_run_backward->data == target) 
            printf("(%d, %d) ", p_run_forward->data, p_run_backward->data); 
        
        p_run_forward = p_run_forward->next; 
        p_run_backward = p_run_backward->prev; 
    } 
    printf("\n"); 
}  

status_t 
zigzag_arrangement(list_t* p_list)
{
    node_t* p_run_forward = NULL; 
    node_t* p_run_forward_next = NULL; 
    node_t* p_run_backward = NULL; 
    node_t* p_run_backward_prev = NULL; 

    p_run_forward = p_list->next; 
    p_run_backward = p_list->prev; 

    while(p_run_forward != p_run_backward && p_run_backward->prev != p_run_forward) 
    {
        p_run_forward_next = p_run_forward->next; 
        p_run_backward_prev = p_run_backward->prev; 

        generic_insert(p_run_forward, p_run_backward, p_run_forward_next); 
        
        p_run_forward = p_run_forward_next; 
        p_run_backward = p_run_backward_prev; 
    } 

    // set links with last node 
    p_run_backward->next = p_list; 
    p_list->prev = p_run_backward; 

    return (SUCCESS); 
} 

// ---------------------------------------------------------------------------------- 

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
