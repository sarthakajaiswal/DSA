/* 
// header files 
#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

// symbolic constants 
enum status 
{
    SUCCESS     = 1, 
    TRUE        = 1, 
    FALSE       = 0, 
    LIST_DATA_NOT_FOUND = 2, 
    LIST_EMPTY  = 3, 
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
    struct node* prev; 
    struct node* next; 
};  

// interface function declarations 
// creation 
list_t* create_list(void); 

// data insertion 
status_t insert_start(list_t* p_list, data_t new_data); 
status_t insert_end(list_t* p_list, data_t new_data); 
status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data); 
status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data); 

// get and pop functions 
status_t get_start(list_t* p_list, data_t* p_start_data); 
status_t get_end(list_t* p_list, data_t* p_end_data); 
status_t pop_start(list_t* p_list, data_t* p_start_data); 
status_t pop_end(list_t* p_list, data_t* p_end_data); 

// data removal 
status_t remove_start(list_t* p_list); 
status_t remove_end(list_t* p_list); 
status_t remove_data(list_t* p_list, data_t r_data); 

// miscalleneous functions 
status_t find(list_t* p_list, data_t f_data); 
status_t is_empty(list_t* p_list); 
len_t get_list_length(list_t* p_list); 
void show_list(list_t* p_list, const char* msg); 

// destroy functions 
status_t destroy_list(list_t** pp_list); 

int main(void) 
{
    list_t* p_list = NULL; 
    data_t data; 
    data_t first_data; 
    data_t last_data; 
    status_t status; 

    p_list = create_list(); 
    assert(p_list != NULL); 

    assert(is_empty(p_list) == TRUE); 
    assert(get_start(p_list, &first_data) == LIST_EMPTY); 
    assert(get_end(p_list, &last_data) == LIST_EMPTY); 
    assert(get_list_length(p_list) == 0); 
    assert(pop_start(p_list, &first_data) == LIST_EMPTY); 
    assert(pop_end(p_list, &last_data) == LIST_EMPTY); 
    assert(remove_start(p_list) == LIST_EMPTY); 
    assert(remove_end(p_list) == LIST_EMPTY); 

    show_list(p_list, "Just after creation:"); 

    // insert data at start 
    for(data = 1; data <= 5; ++data) 
        assert(insert_start(p_list, data*10) == SUCCESS); 
    show_list(p_list, "After insert_start():"); 

    // insert data at end 
    for(data = 6; data <= 10; ++data) 
        assert(insert_end(p_list, data*10) == SUCCESS); 
    show_list(p_list, "After insert_end():"); 

    // insert after  
    assert(insert_after(p_list, 0, 100) == LIST_DATA_NOT_FOUND); 
    assert(insert_after(p_list, 100, -100) == SUCCESS); 

    // insert_before 
    assert(insert_before(p_list, 0, 200) == LIST_DATA_NOT_FOUND); 
    assert(insert_before(p_list, 50, 200) == SUCCESS); 

    // get and pop functions 
    show_list(p_list, "Before get start():"); 
    assert(get_start(p_list, &first_data) == SUCCESS); 
    printf("start_data = %d\n", first_data); 
    show_list(p_list, "after get_start():"); 

    show_list(p_list, "Before get end(): "); 
    assert(get_end(p_list, &last_data) == SUCCESS); 
    printf("end_data = %d\n", last_data); 
    show_list(p_list, "after get_end():"); 

    show_list(p_list, "before pop_start():"); 
    assert(pop_start(p_list, &first_data) == SUCCESS); 
    printf("start_data = %d\n", first_data); 
    show_list(p_list, "after pop_start():"); 

    show_list(p_list, "before pop_end()"); 
    assert(pop_end(p_list, &last_data) == SUCCESS); 
    printf("end data = %d\n", last_data); 
    show_list(p_list, "after pop_end():"); 

    // remove functions 
    show_list(p_list, "Before remove_start():"); 
    assert(remove_start(p_list) == SUCCESS); 
    show_list(p_list, "After remove_start():"); 

    show_list(p_list, "Before remove_end():"); 
    assert(remove_end(p_list) == SUCCESS); 
    show_list(p_list, "after remove_end():"); 

    show_list(p_list, "Before remove_data(): ");
    assert(remove_data(p_list, -100) == LIST_DATA_NOT_FOUND); 
    assert(remove_data(p_list, 70) == SUCCESS);  
    show_list(p_list, "after remove_Data(): "); 

    // miscalleneous functions 
    assert(find(p_list, -70) == FALSE); 
    assert(find(p_list, 90) == TRUE); 

    len_t length = 0; 
    length = get_list_length(p_list); 
    printf("length = %d\n", length); 

    assert(is_empty(p_list) == FALSE); 
    puts("list is not empty at this point"); 

    // destroy 
    assert(destroy_list(&p_list) == SUCCESS); 
    assert(p_list == NULL); 

    puts("List tested and destroyed successfully"); 

    return (EXIT_SUCCESS); 
} 

// Interface function definitions / 
// create 
list_t* create_list(void) 
{
    list_t* p_list = NULL; 

    p_list = (list_t*)malloc(sizeof(list_t)); 
    if(NULL == p_list) 
    {
        puts("malloc():fatal: out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    p_list->data = 0; 
    p_list->next = p_list; 
    p_list->prev = p_list; 

    return (p_list); 
} 

// data insertion 
status_t insert_start(list_t* p_list, data_t new_data) 
{
    node_t* p_new_node = NULL; 

    p_new_node = (node_t*)malloc(sizeof(node_t)); 
    if(NULL == p_new_node) 
    {
        puts("malloc():fatal: out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_node->data = new_data; 

    p_new_node->prev = p_list; 
    p_new_node->next = p_list->next; 
    p_list->next->prev = p_new_node;
    p_list->next = p_new_node; 

    return (SUCCESS); 
} 

status_t insert_end(list_t* p_list, data_t new_data) 
{
    node_t* p_new_node = NULL; 

    p_new_node = (node_t*)malloc(sizeof(node_t)); 
    if(NULL == p_new_node) 
    {
        puts("malloc():fatal:out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_node->data = new_data; 

    p_new_node->prev = p_list->prev; 
    p_new_node->next = p_list; 
    p_list->prev->next = p_new_node; 
    p_list->prev = p_new_node; 

    return (SUCCESS); 
} 

status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data) 
{
    node_t* new_node = NULL; 
    node_t* run = NULL; 

    run = p_list->next; 
    while(run != p_list) 
    {
        if(run->data == existing_data) 
            break; 
        run = run->next; 
    } 

    if(run == p_list) 
        return (LIST_DATA_NOT_FOUND); 

    new_node = (node_t*)malloc(sizeof(node_t)); 
    if(NULL == new_node) 
    {
        puts("malloc():fatal:out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 

    new_node->next = run; 
    new_node->prev = run->prev; 
    run->prev->next = new_node; 
    run->prev = new_node; 

    return (SUCCESS); 
} 

status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data) 
{
    node_t* run = NULL; 
    node_t* new_node = NULL; 

    run = p_list->next; 
    while(run != p_list) 
    {
        if(run->data == existing_data) 
            break; 
        run = run->next; 
    } 

    if(run == p_list) 
        return (LIST_DATA_NOT_FOUND); 

    new_node = (node_t*)malloc(sizeof(node_t)); 
    if(NULL == new_node) 
    {
        puts("malloc():fatal: out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 

    new_node->prev = run; 
    new_node->next = run->next; 
    run->next->prev = new_node; 
    run->next = new_node; 

    return (SUCCESS); 
} 

// get and pop 
status_t get_start(list_t* p_list, data_t* p_start_data) 
{
    if(p_list->prev == p_list && p_list->next == p_list) 
        return (LIST_EMPTY); 

    *p_start_data = p_list->next->data; 
    return (SUCCESS); 
} 

status_t get_end(list_t* p_list, data_t* p_end_data) 
{
    if(p_list->prev == p_list && p_list->next == p_list) 
        return (LIST_EMPTY); 

    *p_end_data = p_list->prev->data; 
    return (SUCCESS); 
} 

status_t pop_start(list_t* p_list, data_t* p_popped_data) 
{
    node_t* p_start_node = NULL; 

    if(p_list->prev == p_list && p_list->next == p_list) 
        return (LIST_EMPTY); 

    p_start_node = p_list->next; 
    p_start_node->next->prev = p_start_node->prev; 
    p_start_node->prev->next = p_start_node->next; 

    free(p_start_node); 
    p_start_node = NULL; 

    return (SUCCESS); 
} 

status_t pop_end(list_t* p_list, data_t* p_popped_data) 
{
    node_t* p_end_node = NULL; 

    if(p_list->prev == p_list && p_list->next == p_list) 
        return (LIST_EMPTY); 

    p_end_node = p_list->prev; 
    p_end_node->prev->next = p_end_node->next; 
    p_end_node->next->prev = p_end_node->prev; 

    free(p_end_node); 
    p_end_node = NULL; 

    return (SUCCESS); 
} 

// data removal 
status_t remove_start(list_t* p_list) 
{
    node_t* p_start_node = NULL; 

    if(p_list->prev == p_list && p_list->next == p_list) 
        return (LIST_EMPTY); 

    p_start_node = p_list->next; 
    p_start_node->next->prev = p_list; 
    p_list->next = p_start_node->next; 

    free(p_start_node); 
    p_start_node = NULL; 

    return (SUCCESS); 
} 

status_t remove_end(list_t* p_list) 
{
    node_t* p_end_node = NULL; 

    if(p_list->prev == p_list && p_list->next == p_list) 
        return (LIST_EMPTY); 

    p_end_node = p_list->prev; 
    p_end_node->prev->next = p_list; 
    p_list->prev = p_end_node->prev; 

    free(p_end_node); 
    p_end_node = NULL; 

    return (SUCCESS); 
} 

status_t remove_data(list_t* p_list, data_t r_data) 
{
    node_t* run = NULL; 
    node_t* remove_node = NULL; 

    run = p_list->next; 
    while(run != p_list) 
    {
        if(run->data == r_data) 
            break; 
        run = run->next; 
    } 

    if(run == p_list) 
        return (LIST_DATA_NOT_FOUND); 

    remove_node = run; 

    remove_node->next->prev = remove_node->prev; 
    remove_node->prev->next = remove_node->next; 

    free(remove_node); 
    remove_node = NULL; 

    return (SUCCESS); 
} 

// miscalleneous 
status_t find(list_t* p_list, data_t f_data) 
{
    node_t* run = NULL; 

    run = p_list->next; 
    while(run != p_list) 
    {
        if(run->data == f_data) 
            return (TRUE); 
        run = run->next; 
    } 

    return (FALSE); 
} 

status_t is_empty(list_t* p_list) 
{
    return (p_list->prev == p_list && p_list->next == p_list); 
} 

len_t get_list_length(list_t* p_list) 
{
    len_t length = 0; 
    node_t* run = NULL; 

    run = p_list->next; 
    while(run != p_list) 
    {
        length += 1; 
        run = run->next; 
    } 

    return (length); 
} 

void show_list(list_t* p_list, const char* msg) 
{
    node_t* run = NULL; 

    if(msg) 
        puts(msg); 

    printf("[START]<->"); 
    run = p_list->next; 
    while(run != p_list) 
    {
        printf("[%d]<->", run->data); 
        run = run->next; 
    } 
    puts("[END]"); 
} 

// destroy 
status_t destroy_list(list_t** pp_list) 
{
    list_t* p_list = NULL; 
    node_t* run = NULL; 
    node_t* run_next = NULL; 

    p_list = *pp_list; 
    
    run = p_list->next; 
    while(run != p_list) 
    { 
        run_next = run->next; 
        free(run); 
        run = run->next; 
    } 

    free(p_list); 
    p_list = NULL; 
    *pp_list = NULL; 

    return (SUCCESS); 
} 

// header files 
#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

// symbolic constants 
enum status 
{
    SUCCESS             = 1, 
    TRUE                = 1, 
    FALSE               = 0, 
    LIST_DATA_NOT_FOUND = -1, 
    LIST_EMPTY          = -2, 
}; 

typedef int         data_t; 
typedef int         len_t; 
typedef enum status status_t; 
typedef struct node node_t; 
typedef node_t      list_t; 

// node layout definition 
struct node 
{
    data_t data; 
    struct node* prev; 
    struct node* next; 
}; 

// declarations of interface functions 
// creation 
list_t* create_list(void); 

// data insertion 
status_t insert_start(list_t* p_list, data_t new_data); 
status_t insert_end(list_t* p_list, data_t new_data); 
status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data); 
status_t insert_before(list_t* p_list, data_t existig_data, data_t new_data); 

// get and pop functions 
status_t get_start(list_t* p_list, data_t* p_start_data); 
status_t get_end(list_t* p_list, data_t* p_end_data); 
status_t pop_start(list_t* p_list, data_t* p_popped_data); 
status_t pop_end(list_t* p_list, data_t* p_popped_data); 

// data removal 
status_t remove_start(list_t* p_list); 
status_t remove_end(list_t* p_list); 
status_t remove_data(list_t* p_list, data_t r_data); 

// miscalleneous functions 
status_t find(list_t* p_list, data_t f_data); 
status_t is_list_empty(list_t* p_list); 
len_t get_list_length(list_t* p_list); 
void show(list_t* p_list, const char* msg); 

// destruction 
status_t destroy_list(list_t** pp_list); 

int main(void) 
{
    list_t* p_list = NULL; 
    data_t start_data; 
    data_t end_data; 
    data_t data; 
    status_t status; 
    len_t length; 

    p_list = create_list(); 

    assert(is_list_empty(p_list) == TRUE); 
    assert(get_list_length(p_list) == 0); 
    assert(get_start(p_list, &start_data) == LIST_EMPTY); 
    assert(get_end(p_list, &end_data) == LIST_EMPTY); 
    assert(pop_start(p_list, &start_data) == LIST_EMPTY); 
    assert(pop_end(p_list, &end_data) == LIST_EMPTY); 
    assert(remove_start(p_list) == LIST_EMPTY); 
    assert(remove_end(p_list) == LIST_EMPTY); 

    puts("All assertions on empty list succesfull"); 

    show(p_list, "Just after creation"); 
    for(int i = 0; i <= 5; ++i) 
        insert_start(p_list, i*10); 
    show(p_list, "After insert_start():"); 

    for(int i = 6; i <= 10; ++i) 
        insert_end(p_list, i*10); 
    show(p_list, "After insert_end():"); 

    assert(insert_after(p_list, -100, 500) == LIST_DATA_NOT_FOUND); 
    assert(insert_before(p_list, -200, 1000) == LIST_DATA_NOT_FOUND); 

    assert(insert_after(p_list, 0, 500) == SUCCESS); 
    show(p_list, "After insert_after():"); 

    assert(insert_before(p_list, 0, 1000) == SUCCESS); 
    show(p_list, "After insert_before():"); 

    assert(get_start(p_list, &start_data) == SUCCESS); 
    printf("start data = %d\n", start_data); 
    show(p_list, "After get_start():"); 

    assert(get_end(p_list, &end_data) == SUCCESS); 
    printf("end data = %d\n", end_data); 
    show(p_list, "After get_end():"); 

    assert(pop_start(p_list, &start_data) == SUCCESS); 
    printf("start_data = %d\n", start_data); 
    show(p_list, "After pop_start():"); 

    assert(pop_end(p_list, &end_data) == SUCCESS); 
    printf("end data = %d\n", end_data); 
    show(p_list, "after pop_end():"); 

    assert(remove_start(p_list) == SUCCESS); 
    show(p_list, "After remove_start():"); 

    assert(remove_end(p_list) == SUCCESS); 
    show(p_list, "After remove_end():"); 

    assert(remove_data(p_list, -100) == LIST_DATA_NOT_FOUND); 
    assert(remove_data(p_list, 0) == SUCCESS); 
    show(p_list, "After remove_data():"); 

    assert(find(p_list, 0) == FALSE); 
    assert(find(p_list, 500) == TRUE); 

    assert(is_list_empty(p_list) == FALSE); 

    length = get_list_length(p_list); 
    printf("length = %d\n", length); 
    show(p_list, NULL); 

    status = destroy_list(&p_list); 
    assert(status == SUCCESS && p_list == NULL); 

    puts("List testing succesfully completed"); 

    return (0); 
} 

list_t* create_list(void) 
{
    list_t* p_new_list = NULL; 

    p_new_list = (list_t*)malloc(sizeof(list_t)); 
    if(NULL == p_new_list) 
    {
        puts("malloc():fatal: out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_list->data = 0;
    p_new_list->next = p_new_list; 
    p_new_list->prev = p_new_list; 

    return (p_new_list); 
} 

status_t insert_start(list_t* p_list, data_t new_data) 
{
    node_t* p_new_node = NULL; 

    p_new_node = (node_t*)malloc(sizeof(struct node)); 
    if(NULL == p_new_node) 
    {
        puts("malloc():fatal: out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_node->data = new_data; 
    p_new_node->prev = p_list; 
    p_new_node->next = p_list->next; 
    p_list->next->prev = p_new_node; 
    p_list->next = p_new_node; 

    return (SUCCESS); 
} 

status_t insert_end(list_t* p_list, data_t new_data) 
{
    node_t* p_new_node = NULL; 

    p_new_node = (node_t*)malloc(sizeof(struct node)); 
    if(NULL == p_new_node)
    {
        puts("malloc():fatal: out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_node->data = new_data; 
    p_new_node->prev = p_list->prev; 
    p_new_node->next = p_list; 
    p_list->prev->next = p_new_node; 
    p_list->prev = p_new_node; 

    return (SUCCESS); 
} 

status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data) 
{
    node_t* p_new_node = NULL; 
    node_t* p_run = NULL; 
    node_t* p_existing_node = NULL; 

    p_run = p_list->next; 
    while(p_run != p_list) 
    {
        if(p_run->data == existing_data) 
            break; 
            
        p_run = p_run->next; 
    } 

    if(p_run == p_list) 
        return (LIST_DATA_NOT_FOUND); 

    p_existing_node = p_run; 

    p_new_node = (node_t*)malloc(sizeof(struct node)); 
    if(NULL == p_new_node) 
    {
        puts("malloc():fatal: out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_node->data = new_data; 
    p_new_node->prev = p_run->prev; 
    p_new_node->next = p_run;
    p_run->prev->next = p_new_node; 
    p_run->prev = p_new_node; 

    return (SUCCESS); 
} 

status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data) 
{
    node_t* p_new_node = NULL; 
    node_t* p_run = NULL; 
    node_t* p_existing_node = NULL; 

    p_run = p_list->next; 
    while(p_run != p_list) 
    {
        if(p_run->data == existing_data) 
            break; 

        p_run = p_run->next; 
    } 

    if(p_run == p_list) 
        return (LIST_DATA_NOT_FOUND); 

    p_existing_node = p_run; 

    p_new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_new_node) 
    {
        puts("malloc():fatal:out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_node->data = new_data; 

    p_new_node->prev = p_existing_node; 
    p_new_node->next = p_existing_node->next; 
    p_existing_node->next->prev = p_new_node; 
    p_existing_node->next = p_new_node; 

    return (SUCCESS); 
} 

status_t get_start(list_t* p_list, data_t* p_start_data) 
{
    if(p_list->prev == p_list && p_list->next == p_list) 
        return (LIST_EMPTY); 

    *p_start_data = p_list->next->data; 
    return (SUCCESS); 
} 

status_t get_end(list_t* p_list, data_t* p_end_data) 
{
    if(p_list->prev == p_list && p_list->next == p_list) 
        return (LIST_EMPTY); 

    *p_end_data = p_list->prev->data; 
    return (SUCCESS); 
} 

status_t pop_start(list_t* p_list, data_t* p_popped_data) 
{
    node_t* p_start_node = NULL; 

    if(p_list->prev == p_list && p_list->next == p_list) 
        return (LIST_EMPTY); 

    p_start_node = p_list->next; 
    *p_popped_data = p_start_node->data; 

    p_start_node->next->prev = p_list; 
    p_list->next = p_start_node->next; 

    free(p_start_node);  
    return (SUCCESS); 
} 

status_t pop_end(list_t* p_list, data_t* p_popped_data) 
{
    node_t* p_end_node = NULL; 

    if(p_list->next == p_list && p_list->prev == p_list) 
        return (LIST_EMPTY); 

    p_end_node = p_list->prev; 
    *p_popped_data = p_end_node->data; 

    p_end_node->prev->next = p_list; 
    p_list->prev = p_end_node->prev; 
    free(p_end_node); 

    return (SUCCESS); 
} 

status_t remove_start(list_t* p_list) 
{
    node_t* p_start_node = NULL; 

    if(p_list->prev == p_list && p_list->next == p_list) 
        return (LIST_EMPTY); 

    p_start_node = p_list->next; 

    p_start_node->next->prev = p_list; 
    p_list->next = p_start_node->next; 
    free(p_start_node); 

    return (SUCCESS); 
} 

status_t remove_end(list_t* p_list) 
{
    node_t* p_end_node = NULL; 

    if(p_list->prev == p_list && p_list->next == p_list) 
        return (LIST_EMPTY); 

    p_end_node = p_list->prev; 

    p_end_node->prev->next = p_list; 
    p_list->prev = p_end_node->prev; 
    free(p_end_node); 

    return (SUCCESS); 
} 

status_t remove_data(list_t* p_list, data_t r_data) 
{
    node_t* p_remove_node = NULL; 
    node_t* p_run = NULL; 

    p_run = p_list->next; 
    while(p_run != p_list) 
    {
        if(p_run->data == r_data) 
            break; 

        p_run = p_run->next; 
    } 

    if(p_run == p_list) 
        return (LIST_DATA_NOT_FOUND); 

    p_remove_node = p_run; 

    p_remove_node->next->prev = p_remove_node->prev; 
    p_remove_node->prev->next = p_remove_node->next; 
    free(p_run); 

    return (SUCCESS); 
} 

status_t find(list_t* p_list, data_t f_data) 
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

status_t is_list_empty(list_t* p_list) 
{
    if(p_list->prev == p_list && p_list->next == p_list) 
        return (TRUE);
    return (FALSE); 
} 

len_t get_list_length(list_t* p_list) 
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

void show(list_t* p_list, const char* msg) 
{
    node_t* p_run = NULL; 

    if(msg) 
        puts(msg); 

    printf("[START]<->"); 
    p_run = p_list->next; 
    while(p_run != p_list) 
    {
        printf("[%d]<->", p_run->data); 
        p_run = p_run->next; 
    } 
    puts("[END]"); 
} 

status_t destroy_list(list_t** pp_list) 
{
    list_t* p_list = NULL; 
    node_t* p_run = NULL; 
    node_t* p_run_next = NULL; 

    p_list = *pp_list; 
    
    p_run = p_list->next; 
    while(p_run != p_list) 
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

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

#define TRUE    1 
#define FALSE   0 
#define SUCCESS 1 
#define LIST_DATA_NOT_FOUND -1 
#define LIST_EMPTY          -2 

typedef int     data_t; 
typedef int     status_t; 
typedef int     len_t; 
typedef struct node     node_t; 
typedef node_t          list_t; 

// node layout definition 
struct node 
{
    data_t data; 
    struct node* prev; 
    struct node* next; 
}; 

// List interface routines  
// creation 
list_t* create_list(void); 

// data insertion 
status_t insert_start(list_t* p_list, data_t new_data); 
status_t insert_end(list_t* p_list, data_t new_data); 
status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data); 
status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data); 

// get and pop 
status_t get_start(list_t* p_list, data_t* p_start_data); 
status_t get_end(list_t* p_list, data_t* p_end_data); 
status_t pop_start(list_t* p_list, data_t* p_start_data); 
status_t pop_end(list_t* p_list, data_t* p_end_data); 

// removal 
status_t remove_start(list_t* p_list); 
status_t remove_end(list_t* p_list); 
status_t remove_data(list_t* p_list, data_t r_data); 

// miscalleneous functions 
status_t is_empty(list_t* p_list); 
status_t find(list_t* p_list, data_t f_data); 
len_t get_list_length(list_t* p_list); 
void show(list_t* p_list, const char* msg); 

// destruction 
status_t destroy_list(list_t** pp_list); 

// client 
int main(void) 
{
    list_t* p_list = NULL; 
    data_t start_data; 
    data_t end_data; 
    data_t data; 
    status_t status; 
    len_t length; 

    p_list = create_list(); 
    assert(p_list != NULL); 

    assert(get_start(p_list, &start_data) == LIST_EMPTY); 
    assert(get_end(p_list, &end_data) == LIST_EMPTY);
    assert(pop_start(p_list, &start_data) == LIST_EMPTY); 
    assert(pop_end(p_list, &end_data) == LIST_EMPTY); 
    assert(remove_start(p_list) == LIST_EMPTY); 
    assert(remove_end(p_list) == LIST_EMPTY); 
    assert(remove_data(p_list, 0) == LIST_DATA_NOT_FOUND); 
    assert(is_empty(p_list) == TRUE); 
    assert(get_list_length(p_list) == 0); 
    puts("Assertions on empty list successfull"); 

    show(p_list, "Just after creation:"); 

    for(int i = 0; i <= 5; ++i) 
        assert(insert_start(p_list, i*10) == SUCCESS); 
    show(p_list, "After insert_start():"); 

    for(int i = 6; i <= 10; ++i) 
        assert(insert_end(p_list, i*10) == SUCCESS); 
    show(p_list, "After insert_end():"); 

    assert(insert_after(p_list, 7, 500) == LIST_DATA_NOT_FOUND); 
    assert(insert_before(p_list, 7, 1000) == LIST_DATA_NOT_FOUND); 

    assert(insert_before(p_list, 0, 149) == SUCCESS); 
    show(p_list, "After insert_before():"); 
    assert(insert_after(p_list, 0, 144) == SUCCESS); 
    show(p_list, "After insert_after():"); 

    assert(get_start(p_list, &start_data) == SUCCESS); 
    printf("start data = %d\n", start_data); 
    show(p_list, "after get_start():"); 

    assert(get_end(p_list, &end_data) == SUCCESS); 
    printf("end data = %d\n", end_data); 
    show(p_list, "after get_end():"); 

    assert(pop_start(p_list, &start_data) == SUCCESS); 
    printf("start_data = %d\n", start_data); 
    show(p_list, "after pop_start():"); 

    assert(pop_end(p_list, &end_data) == SUCCESS); 
    printf("end data = %d\n", end_data); 
    show(p_list, "after pop_end():"); 

    assert(remove_start(p_list) == SUCCESS); 
    show(p_list, "After remove_start():"); 

    assert(remove_end(p_list) == SUCCESS);
    show(p_list, "After remove_end():"); 
    
    assert(remove_data(p_list, 7) == LIST_DATA_NOT_FOUND); 
    assert(remove_data(p_list, 0) == SUCCESS); 
    show(p_list, "After remove_data():"); 

    assert(is_empty(p_list) == FALSE);

    assert(find(p_list, 149) == TRUE); 
    assert(find(p_list, 0) == FALSE); 

    length = get_list_length(p_list); 
    printf("length = %d\n", length); 

    status = destroy_list(&p_list); 
    assert(status == SUCCESS && p_list == NULL); 

    puts("List testing completed successfully"); 

    return (0); 
} 

// interface function definitions 
// creation 
list_t* create_list(void) 
{
    list_t* p_new_list = NULL; 

    p_new_list = (list_t*)malloc(sizeof(list_t)); 
    if(NULL == p_new_list) 
    {
        puts("malloc():fatal:out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_list->data = 0; 
    p_new_list->prev = p_new_list; 
    p_new_list->next = p_new_list; 

    return (p_new_list); 
} 

// data insertion 
status_t insert_start(list_t* p_list, data_t new_data) 
{
    node_t* p_new_node = NULL; 

    p_new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_new_node) 
    {
        puts("malloc():fatal:out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_node->data = new_data; 

    p_new_node->next = p_list->next; 
    p_new_node->prev = p_list; 
    p_list->next->prev = p_new_node; 
    p_list->next = p_new_node; 

    return (SUCCESS); 
} 

status_t insert_end(list_t* p_list, data_t new_data) 
{
    node_t* p_new_node = NULL; 

    p_new_node = (node_t*)malloc(sizeof(node_t)); 
    if(NULL == p_new_node) 
    {
        puts("malloc():fatal:out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_node->data = new_data; 

    p_new_node->next = p_list; 
    p_new_node->prev = p_list->prev; 
    p_list->prev->next = p_new_node; 
    p_list->prev = p_new_node; 

    return (SUCCESS); 
} 

status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data) 
{
    node_t* p_new_node = NULL; 
    node_t* p_existing_node = NULL; 
    node_t* p_run = NULL; 

    p_run = p_list->next; 
    while(p_run != p_list) 
    {
        if(p_run->data == existing_data) 
            break; 
        p_run = p_run->next; 
    } 

    if(p_run == p_list) 
        return (LIST_DATA_NOT_FOUND); 

    p_existing_node = p_run; 

    p_new_node = (node_t*)malloc(sizeof(node_t)); 
    if(NULL == p_new_node) 
    {
        fprintf(stderr, "malloc():fatal:out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_node->data = new_data; 

    p_new_node->next = p_existing_node; 
    p_new_node->prev = p_existing_node->prev; 
    p_existing_node->prev->next = p_new_node; 
    p_existing_node->prev = p_new_node; 

    return (SUCCESS); 
} 

status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data) 
{
    node_t* p_new_node = NULL; 
    node_t* p_existing_node = NULL; 
    node_t* p_run = NULL; 

    p_run = p_list->next; 
    while(p_run != p_list) 
    { 
        if(p_run->data == existing_data) 
            break; 
        p_run = p_run->next; 
    } 

    if(p_run == p_list) 
        return (LIST_DATA_NOT_FOUND); 

    p_existing_node = p_run; 

    p_new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_new_node) 
    {
        puts("malloc():fatal:out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_node->data = new_data; 

    p_new_node->prev = p_existing_node;
    p_new_node->next = p_existing_node->next; 
    p_existing_node->next->prev = p_new_node; 
    p_existing_node->next = p_new_node; 

    return(SUCCESS); 
} 

// getters 
status_t get_start(list_t* p_list, data_t* p_start_data) 
{
    if(p_list->prev == p_list && p_list->next == p_list) 
        return (LIST_EMPTY); 

    *p_start_data = p_list->next->data; 
    return (SUCCESS); 
} 

status_t get_end(list_t* p_list, data_t* p_end_data) 
{
    if(p_list->prev == p_list && p_list->next == p_list) 
        return (LIST_EMPTY); 

    *p_end_data = p_list->prev->data; 
    return (SUCCESS); 
} 

// pop functions 
status_t pop_start(list_t* p_list, data_t* p_start_data) 
{
    node_t* p_start_node = NULL; 

    if(p_list->prev == p_list && p_list->next == p_list) 
        return (LIST_EMPTY); 

    p_start_node = p_list->next; 
    
    *p_start_data = p_start_node->data; 

    p_start_node->next->prev = p_list; 
    p_list->next = p_start_node->next; 
    free(p_start_node); 

    return (SUCCESS); 
} 

status_t pop_end(list_t* p_list, data_t* p_end_data) 
{
    node_t* p_end_node = NULL; 

    if(p_list->prev == p_list && p_list->next == p_list) 
        return (LIST_EMPTY); 

    p_end_node = p_list->prev; 

    *p_end_data = p_end_node->data; 
    p_end_node->prev->next = p_list; 
    p_list->prev = p_end_node->prev; 

    return (SUCCESS); 
} 

// data removal functions 
status_t remove_start(list_t* p_list) 
{
    node_t* p_start_node = NULL; 

    if(p_list->next == p_list && p_list->prev == p_list) 
        return (LIST_EMPTY); 

    p_start_node = p_list->next; 

    p_start_node->next->prev = p_list; 
    p_list->next = p_start_node->next; 
    free(p_start_node); 
    p_start_node = NULL; 
    
    return (SUCCESS); 
} 

status_t remove_end(list_t* p_list) 
{
    node_t* p_end_node = NULL; 

    if(p_list->prev == p_list && p_list->next == p_list) 
        return (LIST_EMPTY); 

    p_end_node = p_list->prev; 

    p_end_node->prev->next = p_list; 
    p_list->prev = p_end_node->prev; 
    free(p_end_node); 
    p_end_node = NULL; 

    return (SUCCESS); 
} 

status_t remove_data(list_t* p_list, data_t r_data) 
{
    node_t* r_node = NULL; 
    node_t* p_run = NULL; 

    p_run = p_list->next; 
    while(p_run != p_list) 
    { 
        if(p_run->data == r_data) 
            break; 
        p_run = p_run->next; 
    }

    if(p_run == p_list) 
        return (LIST_DATA_NOT_FOUND); 

    r_node = p_run; 

    r_node->prev->next = r_node->next; 
    r_node->next->prev = r_node->prev; 
    free(r_node); 
    r_node = NULL; 

    return (SUCCESS); 
} 

// miscalleneous functions 
status_t is_empty(list_t* p_list) 
{
    if(p_list->prev == p_list && p_list->next == p_list) 
        return (TRUE); 
    return (FALSE); 
} 

status_t find(list_t* p_list, data_t f_data) 
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

len_t get_list_length(list_t* p_list) 
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

void show(list_t* p_list, const char* msg) 
{
    node_t* p_run = NULL; 

    if(msg) 
        puts(msg); 

    printf("[START]<->"); 
    for(p_run = p_list->next; p_run != p_list; p_run = p_run->next) 
        printf("[%d]<->", p_run->data); 
    puts("[END]"); 
} 

// destruction 
status_t destroy_list(list_t** pp_list) 
{
    list_t* p_list = NULL; 
    node_t* p_run = NULL; 
    node_t* p_run_next = NULL; 

    p_list = *pp_list; 

    for(p_run = p_list->next; p_run != p_list; p_run = p_run_next) 
    {
        p_run_next = p_run->next; 
        free(p_run); 
    } 

    free(p_list); 
    p_list = NULL; 
    *pp_list = NULL; 

    return (SUCCESS); 
} 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

typedef int     data_t; 
typedef size_t  len_t; 
typedef enum status status_t; 
typedef struct node node_t; 
typedef node_t      list_t; 

enum status 
{
    SUCCESS = 1, 
    TRUE    = 1, 
    FALSE   = 0, 
    LIST_EMPTY          = -1, 
    LIST_DATA_NOT_FOUND = -2, 
}; 

// node layout definition 
struct node 
{
    data_t data; 
    struct node* prev; 
    struct node* next; 
}; 

// interface function declarations 
// creation 
list_t* create_list(void); 

// data insertion 
status_t insert_start(list_t* p_list, data_t new_data); 
status_t insert_end(list_t* p_list, data_t new_data); 
status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data); 
status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data); 

// getters 
status_t get_start(list_t* p_list, data_t* p_start_data); 
status_t get_end(list_t* p_list, data_t* p_end_data); 

// pop functions 
status_t pop_start(list_t* p_list, data_t* p_start_data); 
status_t pop_end(list_t* p_list, data_t* p_end_data); 

// data removal 
status_t remove_start(list_t* p_list); 
status_t remove_end(list_t* p_list); 
status_t remove_data(list_t* p_list, data_t r_data); 

// miscalleneous functions 
status_t is_empty(list_t* p_list); 
status_t find(list_t* p_list, data_t f_data); 
len_t get_list_length(list_t* p_list); 
void show(list_t* p_list, const char* msg); 

// destruction 
status_t destroy_list(list_t** pp_list); 

// client 
int main(void) 
{
    list_t* p_list = NULL; 
    data_t start_data, end_data, data; 
    len_t length; 
    status_t status; 

    p_list = create_list(); 
    assert(p_list != NULL); 
    assert(get_start(p_list, &start_data) == LIST_EMPTY); 
    assert(get_end(p_list, &end_data) == LIST_EMPTY); 
    assert(pop_start(p_list, &start_data) == LIST_EMPTY); 
    assert(pop_end(p_list, &end_data) == LIST_EMPTY); 
    assert(remove_start(p_list) == LIST_EMPTY); 
    assert(remove_end(p_list) == LIST_EMPTY); 
    assert(is_empty(p_list) == TRUE); 
    assert(get_list_length(p_list) == 0); 
    puts("All assertions on empty list succesfull"); 

    show(p_list, "Just after creation:"); 

    for(int i = 0; i <= 5; ++i)
        assert(insert_start(p_list, i*10) == SUCCESS); 
    show(p_list, "After insert_start():"); 

    for(int i = 6; i < 10; ++i) 
        assert(insert_end(p_list, i*10) == SUCCESS); 
    show(p_list, "After insert_end():"); 

    assert(insert_after(p_list, 7, 100) == LIST_DATA_NOT_FOUND); 
    assert(insert_before(p_list, 7, 200) == LIST_DATA_NOT_FOUND); 

    assert(insert_before(p_list, 0, 100) == SUCCESS); 
    show(p_list, "After insert_before():"); 
    assert(insert_after(p_list, 0, 200) == SUCCESS); 
    show(p_list, "After insert_after():"); 

    assert(get_start(p_list, &start_data) == SUCCESS); 
    printf("start data = %d\n", start_data); 
    show(p_list, "After get_start():"); 

    assert(get_end(p_list, &end_data) == SUCCESS); 
    printf("end data = %d\n", end_data); 
    show(p_list, "After get_end():"); 

    assert(pop_start(p_list, &start_data) == SUCCESS); 
    printf("start data = %d\n", start_data); 
    show(p_list, "After pop_start():"); 

    assert(pop_end(p_list, &end_data) == SUCCESS); 
    printf("end data = %d\n", end_data); 
    show(p_list, "After pop_end():"); 

    assert(remove_start(p_list) == SUCCESS); 
    show(p_list, "After remove_start():"); 

    assert(remove_end(p_list) == SUCCESS); 
    show(p_list, "After remove_end():"); 

    assert(remove_data(p_list, 7) == LIST_DATA_NOT_FOUND); 
    assert(remove_data(p_list, 0) == SUCCESS); 
    show(p_list, "After remove_data():"); 

    assert(is_empty(p_list) == FALSE); 

    assert(find(p_list, 0) == FALSE); 
    assert(find(p_list, 100) == TRUE); 

    length = get_list_length(p_list); 
    printf("length = %lld\n", length); 

    status = destroy_list(&p_list); 
    assert(status == SUCCESS && p_list == NULL); 

    puts("List testing successfully completed\n"); 

    return (0); 
} 

// interface function definitions 
// creation 
list_t* create_list(void) 
{
    list_t* p_new_list = NULL; 

    p_new_list = (list_t*)malloc(sizeof(list_t)); 
    if(NULL == p_new_list) 
    {
        puts("malloc():fatal: out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_list->data = 0; 
    p_new_list->prev = p_new_list; 
    p_new_list->next = p_new_list; 

    return (p_new_list); 
} 

// data insertion 
status_t insert_start(list_t* p_list, data_t new_data) 
{
    node_t* p_new_node = NULL; 

    p_new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_new_node) 
    {
        puts("malloc():fatal:out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_node->data = new_data; 

    p_new_node->prev = p_list; 
    p_new_node->next = p_list->next; 
    p_list->next->prev = p_new_node; 
    p_list->next = p_new_node; 

    return (SUCCESS); 
} 

status_t insert_end(list_t* p_list, data_t new_data) 
{
    node_t* p_new_node = NULL; 

    p_new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_new_node) 
    {
        puts("malloc():fatal:out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_node->data = new_data; 

    p_new_node->prev = p_list->prev; 
    p_new_node->next = p_list; 
    p_list->prev->next = p_new_node; 
    p_list->prev = p_new_node; 

    return (SUCCESS); 
} 

status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data) 
{
    node_t* p_new_node = NULL; 
    node_t* p_run = NULL; 
    node_t* p_existing_node = NULL; 

    for(p_run = p_list->next; p_run != p_list; p_run = p_run->next) 
        if(p_run->data == existing_data) 
            break; 
            
    if(p_run == p_list) 
        return (LIST_DATA_NOT_FOUND); 

    p_existing_node = p_run; 

    p_new_node = (node_t*)malloc(sizeof(node_t)); 
    if(NULL == p_new_node) 
    {
        puts("malloc():fatal:out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_node->data = new_data; 

    p_new_node->next = p_existing_node; 
    p_new_node->prev = p_existing_node->prev; 
    p_existing_node->prev->next = p_new_node; 
    p_existing_node->prev = p_new_node; 

    return (SUCCESS); 
} 

status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data) 
{
    node_t* p_new_node = NULL; 
    node_t* p_run = NULL; 
    node_t* p_existing_node = NULL; 

    p_run = p_list->next; 
    while(p_run != p_list) 
    {
        if(p_run->data == existing_data) 
            break; 
        p_run = p_run->next; 
    } 

    if(p_run == p_list) 
        return (LIST_DATA_NOT_FOUND); 

    p_existing_node = p_run; 

    p_new_node = (node_t*)malloc(sizeof(node_t)); 
    if(NULL == p_new_node) 
    {
        puts("malloc():fatal:out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_node->data = new_data; 

    p_new_node->next = p_existing_node->next; 
    p_new_node->prev = p_existing_node; 
    p_existing_node->next->prev = p_new_node; 
    p_existing_node->next = p_new_node; 

    return (SUCCESS); 
} 

// getters 
status_t get_start(list_t* p_list, data_t* p_start_data) 
{
    if(p_list->next == p_list && p_list->prev == p_list) 
        return (LIST_EMPTY); 

    *p_start_data = p_list->next->data; 

    return (SUCCESS); 
} 

status_t get_end(list_t* p_list, data_t* p_end_data) 
{
    if(p_list->prev == p_list && p_list->next == p_list) 
        return (LIST_EMPTY); 

    *p_end_data = p_list->prev->data; 

    return (SUCCESS); 
} 

// pop functions 
status_t pop_start(list_t* p_list, data_t* p_start_data)
{
    node_t* p_start_node = NULL; 

    if(p_list->prev == p_list && p_list->next == p_list) 
        return (LIST_EMPTY); 

    p_start_node = p_list->next; 
    *p_start_data = p_start_node->data; 

    p_start_node->next->prev = p_list; 
    p_list->next = p_start_node->next; 
    free(p_start_node); 
    p_start_node = NULL; 

    return (SUCCESS); 
} 

status_t pop_end(list_t* p_list, data_t* p_end_data) 
{
    node_t* p_end_node = NULL; 

    if(p_list->prev == p_list && p_list->next == p_list) 
        return (LIST_EMPTY); 

    p_end_node = p_list->prev; 
    *p_end_data = p_end_node->data; 

    p_end_node->prev->next = p_list; 
    p_list->prev = p_end_node->prev; 
    free(p_end_node); 
    p_end_node = NULL; 

    return (SUCCESS); 
} 

// data removal 
status_t remove_start(list_t* p_list) 
{
    node_t* p_start_node = NULL; 

    if(p_list->prev == p_list && p_list->next == p_list) 
        return (LIST_EMPTY); 

    p_start_node = p_list->next; 

    p_start_node->next->prev = p_list; 
    p_list->next = p_start_node->next; 
    free(p_start_node); 
    p_start_node = NULL; 

    return (SUCCESS); 
} 

status_t remove_end(list_t* p_list) 
{
    node_t* p_end_node = NULL; 

    if(p_list->prev == p_list && p_list->next == p_list) 
        return (LIST_EMPTY); 

    p_end_node = p_list->prev; 

    p_end_node->prev->next = p_list; 
    p_list->prev = p_end_node->prev; 
    free(p_end_node); 
    p_end_node = NULL; 

    return (SUCCESS); 
} 

status_t remove_data(list_t* p_list, data_t r_data) 
{
    node_t* p_remove_node = NULL; 
    node_t* p_run = NULL; 

    p_run = p_list->next; 
    while(p_run != p_list) 
    {
        if(p_run->data == r_data) 
            break; 
        p_run = p_run->next; 
    } 

    if(p_run == p_list) 
        return (LIST_DATA_NOT_FOUND); 

    p_remove_node = p_run; 

    p_remove_node->next->prev = p_remove_node->prev; 
    p_remove_node->prev->next = p_remove_node->next; 
    free(p_remove_node); 
    p_remove_node = NULL; 

    return (SUCCESS); 
} 

// miscalleneous functions 
status_t is_empty(list_t* p_list) 
{
    if(p_list->prev == p_list && p_list->next == p_list) 
        return (TRUE); 
    return (FALSE); 
} 

status_t find(list_t* p_list, data_t f_data) 
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

len_t get_list_length(list_t* p_list) 
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

void show(list_t* p_list, const char* msg) 
{
    node_t* p_run = NULL; 

    if(msg) 
        puts(msg); 

    printf("[START]<->"); 
    p_run = p_list->next; 
    while(p_run != p_list) 
    {
        printf("[%d]<->", p_run->data); 
        p_run = p_run->next; 
    } 
    puts("[END]"); 
} 

// destruction 
status_t destroy_list(list_t** pp_list) 
{
    node_t* p_run = NULL; 
    node_t* p_run_next = NULL; 
    list_t* p_list = NULL; 

    p_list = *pp_list; 

    p_run = p_list->next; 
    while(p_run != p_list) 
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

*/ 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

enum status 
{
    SUCCESS     = 1, 
    TRUE        = 1, 
    FALSE       = 0, 
    LIST_DATA_NOT_FOUND = -1, 
    LIST_EMPTY          = -2, 
}; 

typedef int     data_t; 
typedef size_t  len_t; 
typedef enum status     status_t; 
typedef struct node     node_t; 
typedef node_t          list_t; 

// node layout definition 
struct node 
{
    data_t data; 
    struct node* next; 
    struct node* prev; 
}; 

/* List interface declarations */ 
// creation 
list_t* create_list(void); 

// data insertion 
status_t insert_start(list_t* p_list, data_t new_data); 
status_t insert_end(list_t* p_list, data_t new_data); 
status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data); 
status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data); 

// getters 
status_t get_start(list_t* p_list, data_t* p_start_data); 
status_t get_end(list_t* p_list, data_t* p_end_data); 

// pop functions 
status_t pop_start(list_t* p_list, data_t* p_start_data); 
status_t pop_end(list_t* p_list, data_t* p_end_data); 

// data removal 
status_t remove_start(list_t* p_list); 
status_t remove_end(list_t* p_list); 
status_t remove_data(list_t* p_list, data_t r_data); 

// miscalleneous 
status_t is_list_empty(list_t* p_list); 
status_t find(list_t* p_list, data_t f_data); 
len_t get_list_length(list_t* p_list); 
void show(list_t* p_list, const char* msg); 

// destroy list 
status_t destroy_list(list_t** pp_list); 

/* Client Side */ 
int main(void) 
{
    list_t* p_list = NULL; 
    data_t start_data, end_data, data; 
    len_t length; 
    status_t status; 

    p_list = create_list(); 
    assert(p_list != NULL); 
    assert(get_start(p_list, &start_data) == LIST_EMPTY); 
    assert(get_end(p_list, &end_data) == LIST_EMPTY); 
    assert(pop_start(p_list, &start_data) == LIST_EMPTY); 
    assert(pop_end(p_list, &end_data) == LIST_EMPTY); 
    assert(remove_start(p_list) == LIST_EMPTY); 
    assert(remove_end(p_list) == LIST_EMPTY); 
    assert(is_list_empty(p_list) == TRUE); 
    assert(get_list_length(p_list) == 0); 
    puts("All assertions on empty list are successfull."); 

    show(p_list, "Just after creation:"); 

    for(int i = 0; i <= 5; ++i) 
        assert(insert_start(p_list, i*10) == SUCCESS); 
    show(p_list, "After insert_start():"); 

    for(int i = 6; i < 10; ++i) 
        assert(insert_end(p_list, i*10) == SUCCESS); 
    show(p_list, "After insert_end():"); 

    assert(insert_after(p_list, 7, 100) == LIST_DATA_NOT_FOUND); 
    assert(insert_before(p_list, 7, 200) == LIST_DATA_NOT_FOUND); 

    assert(insert_after(p_list, 0, 100) == SUCCESS); 
    show(p_list, "After insert_after():"); 
    
    assert(insert_before(p_list, 0, 200) == SUCCESS); 
    show(p_list, "After insert_before():"); 

    assert(get_start(p_list, &start_data) == SUCCESS); 
    printf("start data = %d\n", start_data); 
    show(p_list, "After get_start():"); 

    assert(get_end(p_list, &end_data) == SUCCESS); 
    printf("end data = %d\n", end_data); 
    show(p_list, "After get_end():"); 

    assert(pop_start(p_list, &start_data) == SUCCESS); 
    printf("start data = %d\n", start_data); 
    show(p_list, "After pop_start():"); 

    assert(pop_end(p_list, &end_data) == SUCCESS); 
    printf("end data = %d\n", end_data); 
    show(p_list, "After pop_end():"); 

    assert(remove_start(p_list) == SUCCESS); 
    show(p_list, "After remove_start():"); 

    assert(remove_end(p_list) == SUCCESS); 
    show(p_list, "After remove_end():"); 

    assert(remove_data(p_list, 7) == LIST_DATA_NOT_FOUND); 
    assert(remove_data(p_list, 0) == SUCCESS); 
    show(p_list, "after remove_data():"); 

    assert(is_list_empty(p_list) == FALSE); 

    assert(find(p_list, 0) == FALSE); 
    assert(find(p_list, 100) == TRUE); 

    length = get_list_length(p_list); 
    printf("length = %lld\n", length); 

    status = destroy_list(&p_list); 
    assert(status == SUCCESS && p_list == NULL); 

    puts("List testing succesfully completed"); 

    return (0); 
} 

/* interface function definitions */ 
// creation 
list_t* create_list(void) 
{
    list_t* p_new_list = NULL; 

    p_new_list = (list_t*)malloc(sizeof(list_t)); 
    if(NULL == p_new_list) 
    {
        puts("malloc():fatal:out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_list->data = 0; 

    p_new_list->prev = p_new_list; 
    p_new_list->next = p_new_list; 

    return (p_new_list); 
}  

// data insertion 
status_t insert_start(list_t* p_list, data_t new_data) 
{
    node_t* p_new_node = NULL; 

    p_new_node = (node_t*)malloc(sizeof(node_t)); 
    if(NULL == p_new_node) 
    {
        fprintf(stderr, "malloc():fatal:out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_node->data = new_data; 

    p_new_node->prev = p_list; 
    p_new_node->next = p_list->next; 
    p_list->next->prev = p_new_node; 
    p_list->next = p_new_node; 

    return (SUCCESS); 
} 

status_t insert_end(list_t* p_list, data_t new_data) 
{
    node_t* p_new_node = NULL; 

    p_new_node = (node_t*)malloc(sizeof(node_t)); 
    if(NULL == p_new_node) 
    {
        puts("malloc():fatal:out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_node->data = new_data; 

    p_new_node->prev = p_list->prev; 
    p_new_node->next = p_list; 
    p_list->prev->next = p_new_node; 
    p_list->prev = p_new_node; 

    return (SUCCESS); 
} 

status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data) 
{
    node_t* p_run = NULL; 
    node_t* p_existing_node = NULL; 
    node_t* p_new_node = NULL; 

    for(p_run = p_list->next; p_run != p_list; p_run = p_run->next) 
    {
        if(p_run->data == existing_data) 
            break; 
    } 

    if(p_run == p_list) 
        return (LIST_DATA_NOT_FOUND); 

    p_existing_node = p_run; 

    p_new_node = (node_t*)malloc(sizeof(node_t)); 
    if(NULL == p_new_node) 
    {
        puts("malloc():fatal:out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_node->data = new_data; 

    p_new_node->next = p_existing_node->next; 
    p_new_node->prev = p_existing_node->prev; 
    p_existing_node->next->prev = p_new_node; 
    p_existing_node->next = p_new_node; 

    return (SUCCESS); 
}

status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data) 
{
    node_t* p_new_node = NULL; 
    node_t* p_existing_node = NULL; 
    node_t* p_run = NULL; 

    for(p_run = p_list->next; p_run != p_list; p_run = p_run->next) 
        if(p_run->data == existing_data) 
            break; 

    if(p_run == p_list) 
        return (LIST_DATA_NOT_FOUND); 

    p_existing_node = p_run; 

    p_new_node = (node_t*)malloc(sizeof(node_t)); 
    if(NULL == p_new_node) 
    {
        puts("malloc():fatal:out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_node->data = new_data; 

    p_new_node->next = p_existing_node; 
    p_new_node->prev = p_existing_node->prev; 
    p_existing_node->prev->next = p_new_node; 
    p_existing_node->prev = p_new_node; 

    return (SUCCESS); 
} 

// getters 
status_t get_start(list_t* p_list, data_t* p_start_data) 
{
    if(p_list->prev == p_list && p_list->next == p_list) 
        return (LIST_EMPTY); 

    *p_start_data = p_list->next->data; 
    return (SUCCESS); 
} 

status_t get_end(list_t* p_list, data_t* p_end_data) 
{ 
    if(p_list->prev == p_list && p_list->next == p_list) 
        return (LIST_EMPTY); 

    *p_end_data = p_list->prev->data; 
    return (SUCCESS); 
} 

// pop functions 
status_t pop_start(list_t* p_list, data_t* p_start_data) 
{
    node_t* p_start_node = NULL; 

    if(p_list->prev == p_list && p_list->next == p_list) 
        return (LIST_EMPTY); 

    p_start_node = p_list->next; 
    *p_start_data = p_start_node->data; 

    p_start_node->next->prev = p_list; 
    p_list->next = p_start_node->next; 
    free(p_start_node); 

    return (SUCCESS); 
} 

status_t pop_end(list_t* p_list, data_t* p_end_data) 
{
    node_t* p_end_node = NULL; 

    if(p_list->prev == p_list && p_list->next == p_list) 
        return (LIST_EMPTY); 

    p_end_node = p_list->prev; 
    *p_end_data = p_end_node->data; 

    p_end_node->prev->next = p_list; 
    p_list->prev = p_end_node->prev; 
    free(p_end_node); 

    return (SUCCESS); 
} 

// data removal 
status_t remove_start(list_t* p_list) 
{
    node_t* p_start_node = NULL; 

    if(p_list->prev == p_list && p_list->next == p_list) 
        return (LIST_EMPTY); 

    p_start_node = p_list->next; 
    
    p_start_node->next->prev = p_list; 
    p_list->next = p_start_node->next; 
    free(p_start_node); 

    return (SUCCESS); 
} 

status_t remove_end(list_t* p_list) 
{
    node_t* p_end_node = NULL; 

    if(p_list->prev == p_list && p_list->next == p_list) 
        return (LIST_EMPTY); 

    p_end_node = p_list->prev; 

    p_end_node->prev->next = p_list; 
    p_list->prev = p_end_node->prev; 
    free(p_end_node); 

    return (SUCCESS); 
}  

status_t remove_data(list_t* p_list, data_t r_data) 
{
    node_t* p_delete_node = NULL; 
    node_t* p_run = NULL; 

    p_run = p_list->next; 
    while(p_run != p_list) 
    {
        if(p_run->data == r_data) 
            break; 
        p_run = p_run->next; 
    } 

    if(p_run == p_list) 
        return (LIST_DATA_NOT_FOUND); 

    p_delete_node = p_run; 
    
    p_delete_node->prev->next = p_delete_node->next; 
    p_delete_node->next->prev = p_delete_node->prev; 
    free(p_delete_node);
     
    return (SUCCESS); 
} 

// miscalleneous 
status_t is_list_empty(list_t* p_list) 
{
    if(p_list->prev == p_list && p_list->next == p_list) 
        return (TRUE); 
    return (FALSE); 
} 

len_t get_list_length(list_t* p_list) 
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

status_t find(list_t* p_list, data_t f_data) 
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

void show(list_t* p_list, const char* msg) 
{
    node_t* p_run = NULL; 

    if(msg) 
        puts(msg); 

    printf("{START}<->"); 
    p_run = p_list->next; 
    while(p_run != p_list) 
    {
        printf("{%d}<->", p_run->data); 
        p_run = p_run->next; 
    } 
    puts("{END}"); 
} 

// destroy 
status_t destroy_list(list_t** pp_list) 
{
    node_t* p_list = NULL; 
    node_t* p_run = NULL; 
    node_t* p_run_next = NULL; 

    p_list = *pp_list; 

    p_run = p_list->next; 
    while(p_run != p_list) 
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
