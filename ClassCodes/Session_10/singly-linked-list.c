/* header files */
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <assert.h> 

/* symbolic constants */
#define SUCCESS             1 
#define TRUE                1 
#define FALSE               0 
#define LIST_DATA_NOT_FOUND 2 
#define LIST_EMPTY          3 

/* node layout definition */
struct node 
{
    int data; 
    struct node* next; 
}; 

/* Interface function declarations */
/* List creation functions */
struct node* create_list(void); 

/* data addition functions */
int insert_start(struct node* p_list, int new_data); 
int insert_end(struct node* p_list, int new_data); 
int insert_after(struct node* p_list, int existing_data, int new_data); 
int insert_before(struct node* p_list, int existing_data, int new_data); 

/* get functions */
int get_start(struct node* p_list, int* p_start_data); 
int get_end(struct node* p_list, int* p_end_data); 

/* Pop functions */
int pop_start(struct node* p_list, int* p_start_data); 
int pop_end(struct node* p_list, int* p_end_data); 

/* remove functions */
int remove_start(struct node* p_list); 
int remove_end(struct node* p_list); 
int remove_data(struct node* p_list, int r_data); 

/* Miscalleneous functions */
int find(struct node* p_list, int f_data); 
int get_list_length(struct node* p_list); 
int is_list_empty(struct node* p_list); 
void show_list(struct node* p_list, const char* msg); 

/* list destruction functions */
int destroy_list(struct node* p_list); 

/* client of linked list*/
int main(void) 
{
    // variable declarations 
    struct node* p_list = NULL; 

    int status; 
    int data, start_data, end_data; 
    int length; 

    static const char* line = "----------------------------------------------------------------"; 

    // code 
    p_list = create_list(); 
    assert(p_list != NULL); 
    printf("List created successfully\n"); 
    puts(line); 

    printf("Testing assertions of the empty list\n"); 
    assert(is_list_empty(p_list) == TRUE); 
    assert(get_list_length(p_list) == 0); 
    assert(get_start(p_list, &start_data) == LIST_EMPTY); 
    assert(get_end(p_list, &end_data) == LIST_EMPTY); 
    assert(pop_start(p_list, &start_data) == LIST_EMPTY); 
    assert(pop_end(p_list, &end_data) == LIST_EMPTY); 
    assert(remove_start(p_list) == LIST_EMPTY);  
    assert(remove_end(p_list) == LIST_EMPTY); 
    printf("All assertions on empty list are successfull\n"); 
    puts(line); 

    show_list(p_list, "Showing list just after creation:"); 
    puts(line); 

    for(data = 0; data < 5; ++data) 
    {
        status = insert_start(p_list, data*10); 
        assert(status == SUCCESS); 
        printf("%d inserted successfully at the start of the list\n", data*10); 
    } 
    show_list(p_list, "Showing list after inserting 5 data elements at the start:"); 
    puts(line); 

    for(data = 1; data <= 5; ++data) 
    {
        status = insert_end(p_list, data*5); 
        assert(status == SUCCESS); 
        printf("%d inserted successfulyy at the end of the list\n", data * 5); 
    } 
    show_list(p_list, "Showing list after inserting 5 data elements at the end:\n"); 
    puts(line); 

    status = insert_after(p_list, -5, 100); 
    assert(status == LIST_DATA_NOT_FOUND); 
    printf("Expected failure to insert data 100 after non-existing data -5\n"); 
    puts(line); 

    status = insert_after(p_list, 0, 100); 
    assert(status == SUCCESS); 
    show_list(p_list, "Showing list after successfully inserting 100 after 0:"); 
    puts(line); 

    status = insert_before(p_list, 43, 200); 
    assert(status == LIST_DATA_NOT_FOUND); 
    printf("Expected failure to insert data 200 after non-existing data 43\n"); 
    puts(line); 

    status = insert_before(p_list, 0, 200); 
    assert(status == SUCCESS); 
    show_list(p_list, "Showing list after successfully inserting data 200 before 0:"); 
    puts(line); 

    status = get_start(p_list, &start_data); 
    assert(status == SUCCESS); 
    printf("Data at the start:%d\n", start_data); 
    show_list(p_list, "Showing list to demostrate that get_start() returns start data without removing it:"); 
    puts(line); 

    status = get_end(p_list, &end_data); 
    assert(status == SUCCESS); 
    printf("Data at the end: %d\n", end_data); 
    show_list(p_list, "Showing list to demostrate that get_end() return end data without removing it:"); 
    puts(line); 

    status = pop_start(p_list, &start_data); 
    printf("Data at the start = %d\n", start_data); 
    show_list(p_list, "Showing list to demostrate that pop_start() remives and returns start data:"); 
    puts(line); 

    status = pop_end(p_list, &end_data); 
    printf("Data at the end =%d\n", end_data); 
    show_list(p_list, "Showing list to demostrate that pop_end() removes and returns end_data:"); 
    puts(line); 

    status = remove_start(p_list); 
    assert(status == SUCCESS); 
    show_list(p_list, "Showing list after remove_start():"); 
    puts(line); 

    status = remove_end(p_list); 
    assert(status == SUCCESS); 
    show_list(p_list, "showing list after remove_end():"); 
    puts(line); 

    status = remove_data(p_list, 78); 
    assert(status == LIST_DATA_NOT_FOUND); 
    printf("Expected error in removing non-existent data 78\n"); 
    puts(line); 

    status = remove_data(p_list, 0); 
    assert(status == SUCCESS); 
    show_list(p_list, "Showing list after removing existing data 0:"); 
    puts(line); 

    status = find(p_list, 91); 
    assert(status == FALSE); 
    printf("Expected return value FALSE from find() for non-existent data 91\n"); 
    puts(line); 

    status = find(p_list, 100); 
    assert(status == TRUE); 
    printf("Expected return value TRUE from find() for existing data 100\n"); 
    puts(line); 

    status = is_list_empty(p_list); 
    assert(status == FALSE); 
    printf("Expected return value FALSE from is_list_empty()\n"); 
    puts(line); 

    length = get_list_length(p_list); 
    printf("Length of list = %d\n", length); 
    puts(line); 

    status = destroy_list(p_list); 
    assert(status == SUCCESS); 
    p_list = NULL; 
    printf("List is destroyed successfully\n"); 
    puts(line); 

    return (0); 
} 

/* Server of linked list */
/* list creation functions */
struct node* create_list(void) 
{
    // variable declarations 
    struct node* head_node = NULL; 

    // code 
    head_node = (struct node*)malloc(sizeof(struct node)); 
    if(head_node == NULL) 
    {
        puts("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    head_node->data = 0; 
    head_node->next = NULL; 

    return (head_node); 
} 

/* data addiion functions */
int insert_start(struct node* p_list, int new_data) 
{
    // variable declarations 
    struct node* new_node = NULL; 

    // code 
    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(new_node == NULL) 
    {
        printf("Out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 

    new_node->data = new_data; 
    new_node->next = p_list->next; 
    p_list->next = new_node; 

    return (SUCCESS); 
} 

int insert_end(struct node* p_list, int new_data) 
{
    // variable declarations 
    struct node* new_node = NULL; 
    struct node* run = NULL; 

    // code 
    // step 1: Allocate and initialize new node 
    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(new_node == NULL) 
    {
        puts("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 
    new_node->next = NULL; 

    // step 2: Locate the last node 
    run = p_list; 
    while(run->next != NULL) 
    {
        run = run->next; 
    } 

    // Step 3: append the new node to the last position 
    run->next = new_node; 

    return (SUCCESS); 
} 

int insert_after(struct node* p_list, int existing_data, int new_data) 
{
    // code 
    struct node* new_node = NULL; 
    struct node* run = NULL; 

    // variable declarations 
    // (1) Search the node containing the first occurence of the existing_data 
    run = p_list->next; 
    while(run != NULL) 
    {
        if(run->data == existing_data)  
            break; 
        run = run->next; 
    } 

    // (2) if existing data not found then return error as such 
    if(run == NULL) 
        return (LIST_DATA_NOT_FOUND); 

    // (3) allocate and initialize new node 
    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(new_node == NULL) 
    {
        printf("Out of meory\n"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 

    // (3) insert new node at its appropriate position 
    new_node->next = run->next; 
    run->next = new_node; 

    return (SUCCESS); 
} 

int insert_before(struct node* p_list, int existing_data, int new_data) 
{
    // variable declarations 
    struct node* new_node = NULL; 
    struct node* run = NULL;
    struct node* run_prev = NULL; 

    // code 
    // step1) Search for the forst occurence of the existing data maitaining back pointer 
    run_prev = p_list; 
    run = p_list->next; 
    while(run != NULL) 
    {
        if(run->data == existing_data) 
            break; 

        run_prev = run; 
        run = run->next; 
    } 

    // if the existing data not found throught the list then return an error saying as such 
    if(run == NULL) 
        return (LIST_DATA_NOT_FOUND); 

    // step2) Allocate and initialize the new node 
    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(new_node == NULL) 
    {
        puts("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 

    // step3) Insert the new not at the appropriate position 
    new_node->next = run; 
    run_prev->next = new_node; 

    return (SUCCESS); 
} 

/* Get functions */
int get_start(struct node* p_list, int* p_start_data) 
{
    // code 
    if(p_list->next == NULL) 
        return (LIST_EMPTY); 

    *p_start_data = p_list->next->data; 

    return (SUCCESS); 
} 

int get_end(struct node* p_list, int* p_end_data) 
{
    // variable declarations 
    struct node* run = NULL; 

    // code 
    if(p_list->next == NULL) 
        return (LIST_EMPTY); 

    run = p_list->next; 
    while(run->next != NULL) 
    {
        run = run->next; 
    }

    *p_end_data = run->data; 

    return (SUCCESS); 
} 

/* pop functions */
int pop_start(struct node* p_list, int* p_start_data) 
{
    // variable declarations 
    struct node* delete_previous = NULL; 
    struct node* delete_node = NULL; 
    struct node* delete_next = NULL;

    // code 
    if(p_list->next == NULL) 
        return (LIST_EMPTY); 

    *p_start_data = p_list->next->data; 

    delete_previous = p_list; 
    delete_node = p_list->next; 
    delete_next = p_list->next->next; 

    delete_previous->next = delete_next; 

    free(delete_node); 
    delete_node = NULL; 

    return (SUCCESS); 
} 

int pop_end(struct node* p_list, int* p_end_data) 
{
    // variable declarations 
    struct node* run = NULL; 
    struct node* run_previous = NULL; 

    // code 
    if(p_list->next == NULL) 
        return (LIST_EMPTY); 

    run_previous = p_list; 
    run = p_list->next; 
    while(run->next != NULL) 
    {
        run_previous = run; 
        run = run->next; 
    } 

    *p_end_data = run->data; 

    free(run); 
    run = NULL; 
    run_previous->next = NULL; 

    return (SUCCESS); 
} 

/* remove functions */
int remove_start(struct node* p_list) 
{
    // variable declarations 
    struct node* delete_previous = NULL; 
    struct node* delete_node = NULL; 
    struct node* delete_next = NULL; 

    // code 
    if(p_list->next == NULL) 
        return (LIST_EMPTY); 

    delete_previous = p_list; 
    delete_node = p_list->next; 
    delete_next = p_list->next->next; 

    delete_previous->next = delete_next; 

    free(delete_node); 
    delete_node = NULL; 

    return (SUCCESS); 
} 

int remove_end(struct node* p_list) 
{
    // variable declarations 
    struct node* run = NULL; 
    struct node* run_previous = NULL; 

    // code 
    if(p_list->next == NULL) 
        return (LIST_EMPTY); 

    run_previous = p_list; 
    run = p_list->next; 
    while(run->next != NULL) 
    {
        run_previous = run; 
        run = run->next; 
    } 

    free(run); 
    run = NULL; 
    run_previous->next = NULL; 

    return (SUCCESS); 
} 

int remove_data(struct node* p_list, int r_data) 
{
    // variable declarations 
    struct node* run = NULL; 
    struct node* run_previous = NULL; 

    // code 
    run_previous = p_list; 
    run = p_list->next; 
    while(run != NULL) 
    {
        if(run->data == r_data) 
            break; 

        run_previous = run; 
        run = run->next; 
    } 

    if(run == NULL) 
        return (LIST_DATA_NOT_FOUND); 

    run_previous->next = run->next; 
    free(run); 
    run = NULL; 

    return (SUCCESS); 
} 

/* Miscalleneous functions */
int find(struct node* p_list, int f_data) 
{
    // variable declarations 
    struct node* run = NULL; 

    // code 
    run = p_list->next; 
    while(run != NULL) 
    {
        if(run->data == f_data) 
            return (TRUE); 

        run = run->next; 
    } 

    return (FALSE); 
} 

int get_list_length(struct node* p_list) 
{
    // variable declarations 
    int len = 0; 
    struct node* run = NULL; 

    // code 
    run = p_list->next; 
    while(run != NULL) 
    {
        len = len + 1; 
        run = run->next; 
    } 

    return (len); 
} 

int is_list_empty(struct node* p_list) 
{
    return (p_list->next == NULL); 
}

void show_list(struct node* p_list, const char* msg) 
{
    // variable declarations 
    struct node* run = NULL; 

    // cde 
    if(msg != NULL) 
        puts(msg); 

    printf("[START]->"); 
    run = p_list->next; 
    while(run != NULL) 
    {
        printf("[%d]->", run->data); 
        run = run->next; 
    } 
    printf("[END]\n"); 
} 

/* list destruction function */
int destroy_list(struct node* p_list) 
{
    // variable declarations 
    struct node* run = NULL; 
    struct node* run_next = NULL; 

    // code 
    run = p_list; 
    while(run != NULL) 
    {
        run_next = run->next; 
        free(run); 
        run = run_next; 
    } 

    return (SUCCESS); 
} 

