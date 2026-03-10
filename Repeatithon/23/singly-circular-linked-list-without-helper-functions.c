// header files 
#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

// symbolic constants 
enum status 
{
    SUCCESS             = 1, 
    FALSE               = 0, 
    TRUE                = 1, 
    LIST_DATA_NOT_FOUND = 2, 
    LIST_EMPTY          = 3 
}; 

// typedefs 
typedef int     data_t; 
typedef int     status_t; 
typedef int     len_t; 
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
// create list 
list_t* create_list(void); 

//data insertion 
status_t insert_start(list_t* p_list, data_t new_data); 
status_t insert_end(list_t* p_list, data_t new_data); 
status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data); 
status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data); 

// get and pop 
status_t get_start(list_t* p_list, data_t* p_start_data); 
status_t get_end(list_t* p_list, data_t* p_end_data); 
status_t pop_start(list_t* p_list, data_t* p_start_data); 
status_t pop_end(list_t* p_list, data_t* p_end_data); 

// remove functions 
status_t remove_start(list_t* p_list); 
status_t remove_end(list_t* p_list); 
status_t remove_data(list_t* p_list, data_t r_data); 

// miscalleneous 
status_t is_list_empty(list_t* p_list); 
len_t get_list_length(list_t* p_list); 
status_t find(list_t* p_list, data_t f_data); 
void show(list_t* p_list, const char* msg); 

// destroy functions 
status_t destroy_list(list_t** pp_list); 

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
    puts("All assertions on empty list successfull"); 
    show(p_list, "just after creation:"); 

    // ------------ 
    for(int i = 0; i < 5; ++i) 
        assert(insert_end(p_list, i*10) == SUCCESS); 
    show(p_list, "After insert_end():"); 
    for(int i = 5; i < 10; ++i) 
        assert(insert_start(p_list, i*10) == SUCCESS); 
    show(p_list, "After insert_start():"); 

    assert(insert_after(p_list, 7, 100) == LIST_DATA_NOT_FOUND); 
    assert(insert_before(p_list, 7, 200) == LIST_DATA_NOT_FOUND); 

    assert(insert_after(p_list, 50, 100) == SUCCESS); 
    show(p_list, "After insert_after():"); 
    assert(insert_before(p_list, 50, 200) == SUCCESS); 
    show(p_list, "After insert_before():"); 

    // ------------ 
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

    // ------------ 

    assert(is_list_empty(p_list) == FALSE); 
    length = get_list_length(p_list); 
    printf("length = %d\n", length); 

    assert(find(p_list, 7) == FALSE); 
    assert(find(p_list, 100) == TRUE); 

    // ----------- 

    status = destroy_list(&p_list); 
    assert(status == SUCCESS && p_list == NULL); 

    printf("list destroyed successfully"); 
} 

int main(void) 
{
    list_t* p_list = NULL; 
    data_t start_data, end_data, data; 
    len_t length = 0;
    status_t status; 

    p_list = create_list(); 
    assert(p_list != NULL); 
    assert(get_start(p_list, &start_data) == LIST_EMPTY); 
    assert(get_end(p_list, &end_data) == LIST_EMPTY); 
    assert(pop_start(p_list, &start_data) == LIST_EMPTY); 
    assert(pop_end(p_list, &end_data) == LIST_EMPTY); 
    assert(remove_start(p_list) == SUCCESS); 
    assert(remove_end(p_list) == LIST_EMPTY); 
    assert(get_list_length(p_list) == 0); 
    assert(is_list_empty(p_list) == TRUE); 
    puts("All assertions on empty list successfull"); 
    show(p_list, "Just after creation"); 

    // ---------- 

    for(int i = 0; i < 5; ++i) 
        assert(insert_start(p_list, i*10) == SUCCESS); 
    show(p_list, "After insert_start():"); 
    for(int i = 5; i < 10; ++i) 
        assert(insert_end(p_list, i*10) == SUCCESS); 
    show(p_list, "After insert_end():"); 

    assert(insert_after(p_list, 7, 100) == LIST_DATA_NOT_FOUND); 
    assert(insert_before(p_list, 7, 200) == LIST_DATA_NOT_FOUND); 

    assert(insert_before(p_list, 50, 100) == SUCCESS);
    show(p_list, "After insert_before():");  
    assert(insert_after(p_list, 50, 200) == SUCCESS); 
    show(p_list, "After insert_after():"); 

    // ---------- 
    assert(get_start(p_list, &start_data) == SUCCESS); 
    printf("start data = %d\n", start_data); 
    show(p_list, "After get_start():"); 
    assert(get_end(p_list, &end_data) == SUCCESS); 
    printf("end data = %d\n", end_data); 
    show_list(p_list, "After get_end():"); 

    assert(pop_start(p_list, &start_data) == SUCCESS); 
    printf("start data = %d\n", start_data); 
    show(p_list, "After pop_start():"); 
    assert(pop_end(p_list, &end_data) == SUCCESS); 
    printf("end data = %d\n", end_data); 
    show(p_list, "After pop_end():"); 

    // ---------- 

    length = get_list_length(p_list); 
    printf("length = %d\n", length); 

    assert(is_list_empty(p_list) == FALSE); 
    assert(find(p_list, 6) == FALSE); 
    assert(find(p_list, 100) == TRUE); 

    // ---------- 

    status = destroy_list(&p_list); 
    assert(status == SUCCESS && p_list == NULL); 

    puts("List destroyed successfully"); 
    return (0); 
} 

int main(void) 
{
    list_t* p_list = NULL; 
    data_t start_data, end_data, data; 
    status_t status; 
    len_t length; 

    p_list = create_list(); 
    assert(p_list != NULL); 
    assert(get_start(p_list, &start_data) == LIST_EMPTY); 
    assert(get_end(p_list, &end_data) == LIST_EMPTY); 
    assert(remove_start(p_list) == LIST_EMPTY); 
    assert(remove_end(p_list) == LIST_EMPTY); 
    assert(pop_start(p_list, &start_data) == LIST_EMPTY);
    assert(pop_end(p_list, &end_data) == LIST_EMPTY); 
    assert(is_list_empty(p_list) == TRUE); 
    assert(get_list_length(p_list) == 0); 
    puts("All assertions on empty list successfull"); 
    show(p_list, "Just after creation:"); 

    // ---------- 
    for(int i = 0; i < 5; ++i) 
        assert(insert_end(p_list, i*10) == SUCCESS); 
    show(p_list, "After insert_end():"); 
    for(int i = 5; i < 10; ++i) 
        assert(insert_start(p_list, i*10) == SUCCESS); 
    show(p_list, "After insert_start():"); 

    assert(insert_after(p_list, 7, 100) == LIST_DATA_NOT_FOUND); 
    assert(insert_before(p_list, 7, 200) == LIST_DATA_NOT_FOUND); 

    assert(insert_after(p_list, 50, 100) == SUCCESS); 
    show(p_list, "After insert_after():"); 
    assert(insert_before(p_list, 50, 200) == SUCCESS); 
    show(p_list, "After insert_before():"); 

    // ---------- 
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

    // ---------- 

    length = get_list_length(p_list); 
    printf("length = %d\n", length); 

    assert(is_list_empty(p_list) == TRUE); 
    assert(find(p_list, 7) == FALSE); 
    assert(find(p_list, 100) == TRUE); 

    // ---------- 

    status = destroy_list(&p_list); 
    assert(status == SUCCESS && p_list == NULL); 

    puts("List destroyed successfully\n"); 
    return (0); 
} 

int main(void) 
{
    list_t* p_list = NULL; 
    data_t start_data, end_data, data; 
    status_t status; 
    len_t len; 

    p_list = create_list(); 
    assert(p_list != NULL); 
    assert(get_start(p_list, &start_data) == LIST_EMPTY); 
    assert(get_end(p_list, &end_data) == LIST_EMPTY); 
    assert(remove_start(p_list, &start_data) == LIST_EMPTY); 
    assert(remove_end(p_list, &end_data) == LIST_EMPTY); 
    assert(pop_start(p_list, &start_data) == LIST_EMPTY); 
    assert(pop_end(p_list, &end_data) == LIST_EMPTY); 
    assert(is_list_empty(p_list) == TRUE); 
    assert(get_list_length(p_list) == 0); 
    puts("All assertions on empty list are succcessfull"); 
    show(p_list, "Just after creation:"); 

    // ------- 
    for(int i = 0; i < 5; ++i) 
        assert(insert_end(p_list, i*10) == SUCCESS); 
    show(p_list, "After insert_end():"); 
    for(int i = 5; i < 10; ++i) 
        assert(insert_start(p_list, i*10) == SUCCESS); 
    show(p_list, "After insert_start():"); 

    assert(insert_before(p_list, 7, 100) == LIST_DATA_NOT_FOUND); 
    assert(insert_after(p_list, 7, 200) == LIST_DATA_NOT_FOUND); 

    assert(insert_before(p_list, 50, 100) == SUCCESS); 
    show(p_list, "After insert_before():"); 
    assert(insert_after(p_list, 5, 200) == SUCCESS); 
    show(p_list, "After insert_after():"); 

    // ----------- 

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

    // ----------- 

    assert(find(p_list, 7) == FALSE); 
    assert(find(p_list, 100) == TRUE); 
    assert(is_list_empty(p_list) == FALSE); 
    
    len = get_list_length(p_list); 
    printf("length = %d\n", len); 

    // ----------- 

    status = destroy_list(&p_list); 
    assert(status == SUCCESS && p_list != NULL); 

    puts("List destroyed successfully"); 
    return (0); 
} 

int main(void) 
{ 
    list_t* p_list = NULL; 
    data_t start_data, end_data, data; 
    status_t status; 
    len_t length; 

    p_list = create_list(); 
    assert(p_list != NULL); 

    assert(is_list_empty(p_list) == TRUE); 
    assert(get_list_length(p_list) == 0); 
    assert(get_start(p_list, &start_data) == LIST_EMPTY); 
    assert(get_start(p_list, &end_data) == LIST_EMPTY); 
    assert(remove_start(p_list) == LIST_EMPTY); 
    assert(remove_end(p_list) == LIST_EMPTY); 
    assert(pop_start(p_list, &start_data) == LIST_EMPTY); 
    assert(pop_end(p_list, &end_data) == LIST_EMPTY); 
    puts("All assertions on empty list are successfull\n"); 
    show(p_list, "Just after creation"); 

    // -------

    for(int i = 0; i < 5; ++i) 
        assert(insert_end(p_list, i*10) == SUCCESS); 
    show(p_list, "After insert_end():"); 
    for(int i = 5; i < 10; ++i) 
        assert(insert_start(p_list, i*10) == SUCCESS); 
    show(p_list, "After insert_start():"); 

    assert(insert_after(p_list, 7, 100) == LIST_DATA_NOT_FOUND); 
    assert(insert_before(p_list, 7, 200) == LIST_DATA_NOT_FOUND); 

    assert(insert_before(p_list, 50, 100) == SUCCESS); 
    show(p_list, "After insert_before():"); 
    assert(insert_after(p_list, 50, 200) == SUCCESS); 
    show(p_list, "After insert_after():"); 

    // -------- 

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
    show(p_list, "After pop_end():"); 

    // -------- 

    assert(is_list_empty(p_list) == FALSE); 
    assert(find(p_list, 7) == FALSE); 
    assert(find(p_list, 100) == TRUE); 
    
    length = get_list_length(p_list); 
    printf("length = %d\n", length); 

    // ---------- 

    status = destroy_list(&p_list); 
    assert(status == SUCCESS && p_list == NULL); 
    return (0); 
} 

/* Interface function definitions */ 
// creation 
list_t* create_list(void) 
{
    list_t* p_list = NULL; 

    p_list = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_list) 
    {
        puts("create_list():malloc():failed"); 
        exit(EXIT_FAILURE); 
    } 
    p_list->data = 0; 
    p_list->next = p_list; 

    return (p_list); 
} 

list_t* create_list(void) 
{
    list_t* p_list = NULL; 

    p_list = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_list) 
    {
        puts("create_list():malloc():failed"); 
        exit(EXIT_FAILURE); 
    } 
    p_list->data = 0; 
    p_list->next = p_list; 

    return (p_list); 
} 

list_t* create_list(void) 
{
    list_t* p_list = NULL; 

    p_list = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_list) 
    {
        puts("create_list():malloc():failed"); 
        exit(EXIT_FAILURE); 
    }
    p_list->data = 0; 
    p_list->next = p_list; 

    return (p_list); 
} 

list_t* create_list(void) 
{
    list_t* p_list = NULL; 

    p_list = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_list) 
    {
        puts("create_list():malloc():failed"); 
        exit(EXIT_FAILURE); 
    } 
    p_list->data = 0; 
    p_list->next = p_list; 

    return (p_list); 
} 

list_t* create_list(void) 
{
    list_t* p_list = NULL; 

    p_list = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_list) 
    {
        puts("create_list():malloc():failed"); 
        exit(EXIT_FAILURE); 
    } 
    p_list->data = 0; 
    p_list->next = p_list; 

    return (p_list); 
} 

// insertion functions 
status_t insert_start(list_t* p_list, data_t new_data) 
{
    node_t* p_new_node = NULL; 

    p_new_node = (node_t*)malloc(sizeof(node_t)); 
    if(NULL == p_new_node) 
    {
        puts("insert_start():malloc():failed"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_node->data = new_data; 

    p_new_node->next = p_list->next; 
    p_list->next = p_new_node; 

    return (SUCCESS); 
} 

status_t insert_start(list_t* p_list, data_t new_data) 
{
    node_t* p_new_node = NULL; 

    p_new_node = (node_t*)malloc(sizeof(node_t)); 
    if(NULL == p_new_node) 
    {
        puts("insert_start():malloc():failed"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_node->data = new_data; 

    p_new_node->next = p_list->next; 
    p_list->next = p_new_node; 
} 

status_t insert_start(list_t* p_list, data_t new_data) 
{
    node_t* p_new_node = NULL; 

    p_new_node = (node_t*)malloc(sizeof(node_t)); 
    if(NULL == p_new_node) 
    {
        puts("insert_start():malloc():failed"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_node->data = new_data; 

    p_new_node->next = p_list->next; 
    p_list->next = p_new_node; 

    return (SUCCESS); 
} 

status_t insert_start(list_t* p_list, data_t new_data) 
{
    node_t* p_new_node = NULL; 

    p_new_node = (node_t*)malloc(sizeof(node_t)); 
    if(NULL == p_new_node) 
    {
        puts("insert_start():malloc():failed"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_node->data = new_data; 

    p_new_node->next = p_list->next; 
    p_list->next = p_new_node; 

    return (SUCCESS); 
} 

status_t insert_start(list_t* p_list, data_t new_data) 
{
    node_t* p_new_node = NULL; 

    p_new_node = (node_t*)malloc(sizeof(node_t)); 
    if(NULL == p_new_node) 
    {
        puts("insert_start():malloc():failed"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_node->data = new_data; 

    p_new_node->next = p_list->next; 
    p_list->next = p_new_node; 

    return (SUCCESS); 
} 

status_t insert_end(list_t* p_list, data_t new_data) 
{
    node_t* p_run = NULL; 
    node_t* p_new_node = NULL; 

    p_new_node = (node_t*)malloc(sizeof(node_t)); 
    if(NULL == p_new_node) 
    {
        puts("insert_end():malloc():failed\n"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_node->data = new_data; 

    p_run = p_list; 
    while(p_run->next != p_list); 
        p_run = p_run->next; 

    p_new_node->next = p_run->next; 
    p_run->next = p_new_node; 

    return (SUCCESS); 
} 

status_t insert_end(list_t* p_list, data_t new_data) 
{ 
    node_t* p_new_node = NULL; 
    node_t* p_run = NULL; 

    p_new_node = (node_t*)malloc(sizeof(node_t)); 
    if(NULL == p_new_node) 
    { 
        puts("insert_end():malloc():failed"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_node->data = new_data; 

    p_run = p_list; 
    while(p_run->next != p_list) 
        p_run = p_run->next; 

    p_new_node->next = p_run->next; 
    p_run->next = p_new_node; 

    return (SUCCESS); 
} 

status_t insert_end(list_t* p_list, data_t new_data) 
{
    node_t* p_new_node = NULL; 
    node_t* p_run = NULL; 

    p_new_node = (node_t*)malloc(sizeof(node_t)); 
    if(NULL == p_new_node) 
    {
        puts("insert_end():malloc():failed"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_node->data = new_data; 

    p_run = p_list->next; 
    while(p_run != p_list) 
        p_run = p_run->next; 
        
    p_new_node->next = p_run->next; 
    p_run->next = p_new_node; 

    return (SUCCESS); 
} 

status_t insert_end(list_t* p_list, data_t new_data) 
{ 
    node_t* p_new_node = NULL; 
    node_t* p_run = NULL; 

    p_new_node = (node_t*)malloc(sizeof(node_t)); 
    if(NULL == p_new_node) 
    {
        puts("insert_end():malloc():failed"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_node->data = new_data; 

    p_run = p_list->next; 
    while(p_run != p_list) 
        p_run = p_run->next; 

    p_new_node->next = p_run->next; 
    p_run->next = p_new_node; 

    return (SUCCESS); 
} 

status_t insert_end(list_t* p_list, data_t new_data) 
{
    node_t* p_new_node = NULL; 
    node_t* p_run = NULL; 

    p_new_node = (node_t*)malloc(sizeof(node_t)); 
    if(NULL == p_new_node) 
    {
        puts("insert_end():malloc():failed"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_node->data = new_data; 

    p_run = p_list->next; 
    while(p_run != p_list) 
        p_run = p_run->next; 

    p_new_node->next = p_run->next; 
    p_run->next = p_new_node; 

    return (SUCCESS); 
} 

status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data) 
{
    node_t* p_run = NULL; 
    node_t* p_run_previous = NULL; 
    node_t* p_new_node = NULL; 
    node_t* p_existing_node = NULL; 
    node_t* p_existing_node_prev = NULL; 

    p_run = p_list->next; 
    p_run_previous = p_list; 
    while(p_run != p_list) 
    {
        if(p_run->data == existing_data) 
            break; 
        p_run_previous = p_run; 
        p_run = p_run->next; 
    } 

    if(p_run == p_list) 
        return (LIST_DATA_NOT_FOUND); 

    p_existing_node = p_run; 
    p_existing_node_prev = p_run_previous; 

    p_new_node = (node_t*)malloc(sizeof(node_t)); 
    if(NULL == p_new_node) 
    {
        puts("insert_before():malloc():failed"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_node->data = new_data; 

    p_new_node->next = p_run; 
    p_run_previous->next = p_new_node; 

    return (SUCCESS); 
} 

status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data) 
{
    node_t* p_run = NULL; 
    node_t* p_run_prev = NULL; 
    node_t* p_existing_node = NULL; 
    node_t* p_existing_node_prev = NULL; 
    node_t* p_new_node = NULL; 

    p_run = p_list->next; 
    p_run_prev = p_list; 
    while(p_run != p_list) 
    {
        if(p_run->data == existing_data) 
            break; 

        p_run_prev = p_run; 
        p_run = p_run->next; 
    } 
    if(p_run == p_list) 
        return (LIST_DATA_NOT_FOUND); 

    p_existing_node = p_run; 
    p_existing_node_prev = p_run_prev; 

    p_new_node = (node_t*)malloc(sizeof(node_t)); 
    if(NULL == p_new_node) 
    {
        puts("insert_before():malloc():failed"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_node->data = new_data; 

    p_new_node->next = p_existing_node; 
    p_existing_node->next = p_new_node; 

    return (SUCCESS); 
} 

status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data) 
{
    node_t* p_run = NULL; 
    node_t* p_run_prev = NULL; 
    node_t* p_existing_node = NULL; 
    node_t* p_existing_node_prev = NULL; 
    node_t* p_new_node = NULL; 

    p_run = p_list->next; 
    p_run_prev = p_list; 
    while(p_run != p_list) 
    {
        if(p_run->data == existing_data) 
            break; 

        p_run_prev = p_run; 
        p_run = p_run->next; 
    } 
    if(p_run == p_list) 
        return (LIST_DATA_NOT_FOUND); 

    p_existing_node = p_run; 
    p_existing_node_prev = p_run_prev; 

    p_new_node = (node_t*)malloc(sizeof(node_t)); 
    if(NULL == p_new_node) 
    {
        puts("insert_before():malloc():failed"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_node->data = new_data; 

    p_new_node->next = p_existing_node; 
    p_existing_node_prev->next = p_new_node; 

    return (SUCCESS); 
} 

status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data) 
{
    node_t* p_new_node = NULL; 
    node_t* p_run = NULL; 
    node_t* p_run_previous = NULL; 
    node_t* p_existing_node = NULL;
    node_t* p_existing_node_previous = NULL; 
    
    p_run_previous = p_list; 
    p_run = p_list->next; 
    while(p_run != p_list) 
    {
        if(p_run->data == existing_data) 
            break; 

        p_run_previous = p_run; 
        p_run = p_run->next; 
    } 
    if(p_run == p_list) 
        return (LIST_DATA_NOT_FOUND);
         
    p_new_node = (node_t*)malloc(sizeof(node_t)); 
    if(NULL == p_new_node) 
    {
        puts("insert_before():malloc():failed"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_node->data = new_data; 

    p_new_node->next = p_existing_node; 
    p_existing_node_previous->next = p_new_node; 

    return (SUCCESS); 
} 

status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data) 
{
    node_t* p_new_node = NULL; 
    node_t* p_run = NULL; 
    node_t* p_run_previous = NULL; 
    node_t* p_existing_node = NULL; 
    node_t* p_existing_node_prev = NULL; 

    p_run = p_list->next;
    p_run_previous = p_list; 
    while(p_run != p_list) 
    {
        if(p_run->data == existing_data) 
            break; 
        p_run_previous = p_run; 
        p_run = p_run->next; 
    } 
    if(p_run == p_list) 
        return (LIST_DATA_NOT_FOUND); 

    p_existing_node = p_run; 
    p_existing_node_prev= p_run_previous; 

    p_new_node = (node_t*)malloc(sizeof(node_t)); 
    if(NULL == p_new_node) 
    {
        puts("insert_before():malloc():failed"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_node->data = new_data; 

    p_new_node->next = p_existing_node; 
    p_existing_node_prev->next = p_new_node; 

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

    p_new_node = (node_t*)malloc(sizeof(node_t)); 
    if(NULL == p_new_node) 
    {
        puts("insert_after():malloc():failed"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_node->data = new_data; 

    p_new_node->next = p_existing_node->next; 
    p_existing_node->next = p_new_node; 

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
        puts("insert_after():malloc():failed"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_node->data = new_data; 

    p_new_node->next = p_existing_node->next; 
    p_existing_node->next = p_new_node; 

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
        puts("insert_after():malloc():failed"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_node->data = new_data; 

    p_new_node->next = p_existing_node->next; 
    p_existing_node->next = p_new_node; 

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
        puts("insert_after():malloc():failed"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_node->data = new_data; 

    p_new_node->next = p_existing_node->next; 
    p_existing_node->next = p_new_node; 

    return (SUCCESS); 
} 

status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data) 
{   
    node_t* p_run = NULL;  
    node_t* p_existing_node = NULL; 
    node_t* p_new_node = NULL; 

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
        puts("insert_after():malloc():failed"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_node->data = new_data; 

    p_new_node->next = p_existing_node->next; 
    p_existing_node->next = p_new_node; 

    return (SUCCESS); 
} 

// getters and pop functions 
status_t get_start(list_t* p_list, data_t* p_start_data) 
{   
    if(p_list->next == p_list) 
        return (LIST_EMPTY); 

    *p_start_data = p_list->next->data; 
    return (SUCCESS); 
} 

status_t get_start(list_t* p_list, data_t* p_start_data) 
{
    if(p_list->next == p_list) 
        return (LIST_EMPTY); 
    
    *p_start_data = p_list->next->data; 
    return (SUCCESS); 
} 

status_t get_start(list_t* p_list, data_t* p_start_data) 
{
    if(p_list->next == p_list) 
        return (LIST_EMPTY); 

    *p_start_data = p_list->next->data; 
    return (SUCCESS); 
} 

status_t get_start(list_t* p_list, data_t* p_start_data) 
{
    if(p_list->next == p_list) 
        return (LIST_EMPTY); 

    *p_start_data = p_list->next->data; 
    return (SUCCESS); 
} 

status_t get_start(list_t* p_list, data_t* p_start_data) 
{
    if(p_list->next == p_list) 
        return (LIST_EMPTY); 

    *p_start_data = p_list->next->data; 
    return (SUCCESS); 
} 

status_t get_end(list_t* p_list, data_t* p_end_data) 
{
    node_t* p_run = NULL; 
    
    if(p_list->next == p_list) 
        return (LIST_EMPTY); 

    p_run = p_list->next; 
    while(p_run->next != p_list) 
        p_run = p_run->next; 

    *p_end_data = p_run->data; 
    return (SUCCESS); 
} 

status_t get_end(list_t* p_list, data_t* p_end_data) 
{
    node_t* p_run = NULL; 

    if(p_run->next == p_list) 
        return (LIST_EMPTY); 

    p_run = p_list->next; 
    while(p_run->next != p_list)  
        p_run = p_run->next; 

    *p_end_data = p_run->data; 

    return (SUCCESS); 
} 

status_t get_end(list_t* p_list, data_t* p_end_data) 
{
    node_t* p_run = NULL; 

    if(p_list->next == p_list) 
        return (LIST_EMPTY); 

    p_run = p_list->next; 
    while(p_run->next != p_list) 
        p_run = p_run->next; 

    *p_end_data = p_run->data; 

    return (SUCCESS); 
} 

status_t get_end(list_t* p_list, data_t* p_end_data) 
{
    node_t* p_run = NULL; 

    if(p_list->next == p_list)
        return (LIST_EMPTY); 

    p_run = p_list->next; 
    while(p_run->next != p_list) 
        p_run = p_run->next; 

    *p_end_data = p_run->data; 
    return (SUCCESS); 
}

status_t get_end(list_t* p_list, data_t* p_end_data) 
{
    node_t* p_run = NULL; 

    if(p_list->next == p_list) 
        return (LIST_EMPTY); 

    p_run = p_list->next; 
    while(p_run->next != p_list) 
        p_run = p_run->next; 

    *p_end_data = p_run->data; 
    return (SUCCESS); 
} 

status_t pop_start(list_t* p_list, data_t* p_start_data) 
{
    node_t* p_start_node = NULL; 

    if(p_list->next == NULL) 
        return (LIST_DATA_NOT_FOUND); 

    p_start_node = p_list->next; 
    
    p_list->next = p_start_node->next; 
    free(p_start_node); 
    p_start_node = NULL; 

    return (SUCCESS); 
} 

status_t pop_start(list_t* p_list, data_t* p_start_data) 
{
    node_t* p_start_node = NULL; 

    if(p_list->next == p_list) 
        return (LIST_EMPTY); 

    p_start_node = p_list->next; 

    p_list->next = p_start_node->next; 
    free(p_start_node); 
    p_start_node = NULL; 

    return (SUCCESS); 
} 

status_t pop_start(list_t* p_list, data_t* p_start_data) 
{
    node_t* p_start_node = NULL; 

    if(p_list->next == p_list) 
        return (LIST_EMPTY); 

    p_start_node = p_list->next; 

    p_list->next = p_start_node->next; 
    free(p_start_node); 
    p_start_node = NULL; 

    return (SUCCESS); 
} 

status_t pop_start(list_t* p_list, data_t* p_start_data) 
{
    node_t* p_start_node = NULL; 

    if(p_list->next == p_list) 
        return (LIST_EMPTY); 

    p_start_node = p_list->next; 

    p_list->next = p_start_node->next; 
    free(p_start_node); 
    p_start_node = NULL; 

    return (SUCCESS); 
} 

status_t pop_start(list_t* p_list, data_t* p_start_data) 
{
    node_t* p_start_node = NULL; 

    if(p_list->next == p_list) 
        return (LIST_EMPTY); 

    p_start_node = p_list->next; 
    
    p_list->next = p_start_node->next; 
    free(p_start_node); 
    p_start_node = NULL; 

    return (SUCCESS); 
} 

status_t pop_end(list_t* p_list, data_t* p_end_data) 
{
    node_t* p_end_node = NULL; 
    node_t* p_end_node_prev = NULL; 
    node_t* p_run = NULL; 
    node_t* p_run_prev = NULL; 

    if(p_list->next == p_list) 
        return (LIST_EMPTY); 

    p_run_prev = p_list; 
    p_run = p_list->next;     
    while(p_run->next != p_list) 
    {
        p_run_prev = p_list; 
        p_list = p_list->next; 
    } 
    p_end_node_prev = p_run_prev; 
    p_end_node = p_run; 

    p_end_node_prev->next = p_list; 
    free(p_end_node); 

    return (SUCCESS); 
} 

status_t pop_end(list_t* p_list, data_t* p_end_data) 
{
    node_t* p_end_node = NULL; 
    node_t* p_end_node_prev = NULL; 
    node_t* p_run = NULL; 
    node_t* p_run_previous = NULL; 

    p_run_previous = p_list; 
    p_run = p_list->next; 
    while(p_run->next != p_list) 
    {
        p_run_previous = p_run; 
        p_run = p_run->next; 
    } 

    p_end_node = p_run; 
    p_end_node_prev = p_run_previous; 

    p_end_node_prev->next = p_list; 
    free(p_end_node); 

    return (SUCCESS); 
} 

status_t pop_end(list_t* p_list, data_t* p_end_data) 
{
    node_t* p_run = NULL; 
    node_t* p_run_previous = NULL; 
    node_t* p_end_node = NULL; 
    node_t* p_end_node_prev = NULL; 

    p_run_previous = p_list; 
    p_run = p_list->next; 
    while(p_run->next != p_list) 
    {
        p_run_previous = p_run; 
        p_run = p_run->next; 
    } 

    p_end_node_prev = p_run_previous; 
    p_end_node = p_run; 

    p_end_node_prev->next = p_list; 
    free(p_end_node); 

    return (SUCCESS); 
} 

status_t pop_end(list_t* p_list, data_t* p_end_data) 
{
    node_t* p_run = NULL; 
    node_t* p_run_prev = NULL; 
    
    p_run = p_list->next; 
    p_run_prev = p_list; 
    while(p_run->next != p_list) 
    {
        p_run_prev = p_run; 
        p_run = p_run->next; 
    } 

    p_run_prev->next = p_list; 
    free(p_run); 

    return (SUCCESS); 
} 

status_t pop_end(list_t* p_list, data_t* p_end_data) 
{
    node_t* p_end_node = NULL; 
    node_t* p_end_prev = NULL; 
    node_t* p_run = NULL; 
    node_t* p_run_prev = NULL; 
    
    if(p_list->next == p_list) 
        return (LIST_EMPTY); 

    p_run_prev = p_list; 
    p_run = p_list->next; 
    while(p_run->next != p_list) 
    {
        p_run_prev = p_run; 
        p_run = p_run->next; 
    } 

    p_end_node = p_run; 
    p_end_prev = p_run_prev; 

    p_end_prev->next = p_list; 
    free(p_end_node); 
    p_end_node = NULL; 

    return (SUCCESS); 
} 

// miscalleneous 
status_t is_list_empty(list_t* p_list) 
{
    if(p_list->next == p_list) 
        return (TRUE); 
    return (FALSE); 
} 

status_t is_list_empty(list_t* p_list) 
{
    if(p_list->next == p_list) 
        return (TRUE); 
    return (FALSE); 
} 

status_t is_list_empty(list_t* p_list) 
{
    if(p_list->next == p_list) 
        return (TRUE); 
    return (FALSE); 
} 

status_t is_list_empty(list_t* p_list) 
{
    if(p_list->next == p_list) 
        return (TRUE); 
    return (FALSE); 
} 

status_t is_list_empty(list_t* p_list) 
{
    if(p_list->next == p_list) 
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

status_t find(list_t* p_list, data_t f_data) 
{
    node_t* p_run = NULL; 

    p_run = p_list->next; 
    while(p_run != p_list) 
    {
        if(p_run != p_list) 
            return (TRUE); 
        p_run = p_run->next; 
    } 
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
    len_t length = 0; 

    for(node_t* p_run = p_list->next; p_run != p_list; p_run = p_run->next) 
        length += 1; 

    return (length); 
} 

len_t get_list_length(list_t* p_list) 
{ 
    len_t length = 0; 

    for(node_t* p_run = p_list->next; p_run != p_list; p_run = p_run->next) 
        length += 1; 

    return (length); 
} 

len_t get_list_length(list_t* p_list) 
{
    len_t length = 0; 

    for(node_t* p_run = p_list->next; p_run != p_list; p_run = p_run->next) 
        length += 1; 

    return (length); 
} 

len_t get_list_length(list_t* p_list) 
{
    len_t length = 0; 

    for(node_t* p_run = p_list->next; p_run != p_list; p_run = p_run->next) 
        length += 1; 

    return (length); 
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
    list_t* p_list = NULL; 
    node_t* run = NULL; 
    node_t* run_next = NULL; 

    run = p_list->next; 
    while(run != p_list) 
    {
        run_next = p_list->next; 
        free(run); 
        run = run_next; 
    } 

    free(p_list); 
    *pp_list = NULL; 

    return (SUCCESS); 
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
    *pp_list = NULL; 

    return (SUCCESS); 
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
    *pp_list = NULL; 

    return (SUCCESS); 
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
    *pp_list = NULL; 

    return (SUCCESS); 
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
    *pp_list = NULL; 

    return (SUCCESS); 
} 
