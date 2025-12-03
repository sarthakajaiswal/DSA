#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <assert.h> 

//  Node layout definition 
struct node 
{
    int data; 
    struct node* prev; 
    struct node* next; 
}; 

//  Interface function definitions 

//  List creation function 
struct node* create_list(void); 

//  Insert functions 
int insert_start(struct node* head_node, int new_data); 
int insert_end(struct node* head_node, int new_data); 
int insert_after(struct node* head_node, int existing_data, int new_data); 
int insert_before(struct node* head_node, int existing_data, int new_data); 

//  get and pop functions 
int get_start(struct node* head_node, int* p_start_data); 
int get_end(struct node* head_node, int* p_end_data); 

int pop_start(struct node* head_node, int* p_start_data); 
int pop_end(struct node* head_node, int* p_end_data); 

//  Remove functions 
int remove_start(struct node* head_node); 
int remove_end(struct node* head_node); 
int remove_data(struct node* head_node, int r_data); 

//  Miscallaneous functions 
int find(struct node* head_node, int search_data); 
int get_list_length(struct node* head_node); 
int is_list_empty(struct node* head_node); 
void show(struct node* head_node, const char* msg); 

//  List destruction function 
int destroy_list(struct node* head_node); 

//  Client code 
int main(void) 
{
    struct node* list = NULL; 
    int status; 
    int data, start_data, end_data; 
    
    //  create_list() test 
    list = create_list(); 
    assert(list != NULL); 

    //  insert_start() test 
    for(data = 0; data < 5; ++data)
    {
        status = insert_start(list, data * 10); 
        assert(status == 1); 
    }

    show(list, "After inserting 5 elements at the start:"); 

    //  insert_end() test 
    for(data = 5; data < 10; ++data)
    {
        status = insert_end(list, data * 100); 
        assert(status == 1); 
    }

    show(list, "After inserting 5 elements at the end:"); 

    //  insert_after() test 
    status = insert_after(list, 0, -100); 
    assert(status == 1); 
    show(list, "After insert_after():"); 

    //  insert_before() test 
    status = insert_before(list, 0, -200); 
    assert(status == 1); 
    show(list, "After insert_before():"); 

    // get_start() test 
    show(list, "Before get_start():"); 
    status = get_start(list, &start_data); 
    assert(status == 1); 
    printf("start data = %d\n", start_data); 
    show(list, "After get_start():"); 

    //  get_end() test 
    status = get_end(list, &end_data); 
    assert(status == 1); 
    printf("End data = %d\n", end_data); 
    show(list, "After get_end()"); 

    //  pop_start() test 
    status = pop_start(list, &start_data); 
    assert(status == 1); 
    printf("Start data = %d\n", start_data); 
    show(list, "After pop_start():"); 

    //  pop_end() test 
    status = pop_end(list, &end_data); 
    assert(status == 1); 
    printf("End data = %d\n", end_data); 
    show(list, "After pop_end():"); 

    // remove_start() test 
    status = remove_start(list); 
    assert(status == 1); 
    show(list, "After remove_start():"); 

    //  remove_end() test 
    status = remove_end(list); 
    assert(status == 1); 
    show(list, "After remove_end():"); 

    //  remove_data() test 
    status = remove_data(list, 0); 
    assert(status == 1); 
    show(list, "After remove_data(list, 0):"); 

    //  Miscallaneous functions 
    status = find(list, -100); 
    assert(status == 1); 
    puts("Data -100 is present in the list"); 

    status = is_list_empty(list); 
    assert(status == 0); 

    int len = get_list_length(list); 
    printf("Current length of the list is = %d\n", len); 
    show(list, "After get_list_length():"); 

    status = destroy_list(list); 
    assert(status == 1); 
    list = NULL; 

    puts("----List is destroyed successfully"); 

    return (0); 
} 

//  Interface function definitions 

//  List creation function 
struct node* create_list(void)
{
    //  Allocate dummy node. 
    //  Initialize its data, prev next members to 
    //  zero, NULL and NULL respectively 
    //  Return its address 

    struct node* head_node = NULL; 

    head_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == head_node)
    {
        puts("out of memory"); 
        exit(EXIT_FAILURE); 
    }

    head_node->data = 0; 
    head_node->prev = NULL; 
    head_node->next = NULL; 

    return (head_node); 
}

//  Insert functions 
int insert_start(struct node* head_node, int new_data)
{
    struct node* new_node = NULL; 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node)
    {
        puts("out of memory"); 
        exit(EXIT_FAILURE); 
    }

    new_node->data = new_data; 
    new_node->prev = head_node; 
    new_node->next = head_node->next; 
    
    if(head_node->next != NULL)
        head_node->next->prev = new_node; 
    
    head_node->next = new_node; 

    return (1); 
}

int insert_end(struct node* head_node, int new_data)
{
    struct node* new_node = NULL; 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node)
    {
        puts("out of memory"); 
        exit(EXIT_FAILURE); 
    }
    new_node->data = new_data; 

    struct node* run = NULL; 
    run = head_node; 
    while(run->next != NULL)
        run = run->next; 

    new_node->next = NULL; 
    new_node->prev = run; 

    run->next = new_node; 

    return (1);
}

int insert_after(struct node* head_node, int existing_data, int new_data)
{
    struct node* existing_node = NULL; 
    struct node* new_node = NULL; 
    struct node* run = NULL; 

    run = head_node->next; 
    while(run != NULL)
    {
        if(run->data == existing_data)
            break; 
        run = run->next; 
    }

    if(run == NULL)
        return (2); 

    existing_node = run; 
    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node)
    {
        puts("out of memory"); 
        exit(EXIT_FAILURE); 
    }
    new_node->data = new_data; 
    new_node->prev = existing_node; 
    new_node->next = existing_node->next; 

    if(existing_node->next != NULL)
        existing_node->next->prev = new_node; 

    existing_node->next = new_node; 

    return (1); 
}

int insert_before(struct node* head_node, int existing_data, int new_data)
{
    struct node* run = NULL; 
    struct node* existing_node = NULL; 
    struct node* new_node = NULL; 

    run = head_node->next; 
    while(run != NULL)
    {
        if(run->data == existing_data)
            break; 
        run = run->next; 
    }

    if(run == NULL)
        return (2); 

    existing_node = run; 
    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node)
    {
        puts("out of memory"); 
        exit(EXIT_FAILURE); 
    }
    new_node->data = new_data; 
    new_node->next = existing_node; 
    new_node->prev = existing_node->prev; 
    existing_node->prev->next = new_node; 
    existing_node->prev = new_node; 

    return (1); 
}

//  get and pop functions 
int get_start(struct node* head_node, int* p_start_data)
{
    if(head_node->next == NULL && head_node->prev == NULL)
        return (3); 
    
    *p_start_data = head_node->next->data; 
    return (1); 
}

int get_end(struct node* head_node, int* p_end_data)
{
    if(head_node->next == NULL && head_node->prev == NULL)
        return (3); 

    struct node* run = NULL; 

    run = head_node->next; 
    while(run->next != NULL)
        run = run->next; 

    *p_end_data = run->data; 
    return (1); 
}

int pop_start(struct node* head_node, int* p_start_data)
{
    if(head_node->next == NULL && head_node->prev == NULL)
        return (3); 

    *p_start_data = head_node->next->data; 

    struct node* delete_node = head_node->next; 

    delete_node->prev->next = delete_node->next; 
    if(delete_node->next != NULL)
        delete_node->next->prev = delete_node->prev; 
    free(delete_node); 
    delete_node = NULL; 

    return (1); 
}

int pop_end(struct node* head_node, int* p_end_data)
{
    if(head_node->next == NULL && head_node->prev == NULL)
        return (3); 

    struct node* run = NULL; 
    run = head_node->next; 
    while(run->next != NULL)
        run = run->next; 
    *p_end_data = run->data; 

    struct node* delete_node = run; 
    delete_node->prev->next = delete_node->next; 
    if(delete_node->next != NULL)
        delete_node->next->prev = delete_node->prev; 
    free(delete_node); 
    delete_node = NULL; 
    
    return (1); 
}


//  Remove functions 
int remove_start(struct node* head_node)
{
    struct node* delete_node = NULL; 

    if(head_node->next == NULL)
        return (3); 

    delete_node = head_node->next; 

    delete_node->prev->next = delete_node->next; 
    if(delete_node->next != NULL) 
        delete_node->next->prev = delete_node->prev; 

    free(delete_node); 
    
    return (1); 
}

int remove_end(struct node* head_node)
{
    struct node* run = NULL; 
    struct node* delete_node = NULL; 
    
    if(head_node->next == NULL && head_node->prev == NULL)
        return (3); 

    run = head_node->next; 
    while(run->next != NULL)
        run = run->next; 

    //  Taking advantage of the information that the 
    //  run pointer is the last node with data, we can write the following code 
    // run->prev->next = NULL;
    // free(run); 

    //  For general, uniform logic we can write the following code 
    delete_node = run; 

    delete_node->prev->next = delete_node->next; 
    if(delete_node->next != NULL)
        delete_node->next->prev = delete_node->prev; 

    free(delete_node); 

    return (1); 
}

int remove_data(struct node* head_node, int r_data)
{
    struct node* delete_node = NULL; 
    struct node* run = NULL; 

    run = head_node->next; 
    while(run != NULL)
    {
        if(run->data == r_data)
            break; 
        run = run->next; 
    }

    if(run == NULL)
        return (2); 

    delete_node = run; 

    delete_node->prev->next = delete_node->next; 
    if(delete_node->next != NULL)
        delete_node->next->prev = delete_node->prev; 

    free(delete_node); 

    return (1); 
}

//  Miscallaneous functions
int find(struct node* head_node, int search_data)
{
    struct node* run = NULL; 
    
    run = head_node->next; 
    while(run != NULL) 
    {
        if(run->data == search_data)
            return (1); 
        run = run->next; 
    }

    return (0); 
}

int get_list_length(struct node* head_node)
{
    int length = 0; 
    struct node* run = NULL; 

    run = head_node->next; 
    while(run != NULL)
    {
        length += 1; 
        run = run->next; 
    }

    return (length); 
}

int is_list_empty(struct node* head_node)
{
    return (head_node->next == NULL && head_node->prev == NULL); 
}

void show(struct node* head_node, const char* msg)
{
    struct node* run = NULL; 

    if(msg != NULL)
        puts(msg);
        
    printf("[START]<->"); 
    run = head_node->next; 
    while(run != NULL)
    {
        printf("[%d]<->", run->data); 
        run = run->next; 
    }
    printf("[END]\n"); 
}

//  List destruction function 
int destroy_list(struct node* head_node)
{
    struct node* run = NULL; 
    struct node* run_next = NULL; 

    run = head_node; 
    while(run != NULL)
    {
        run_next = run->next; 
        free(run); 
        run = run_next; 
    }

    return (1); 
}

//  KEEM CALM AND TRUST CPA 