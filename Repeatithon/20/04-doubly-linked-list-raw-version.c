// header files 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <assert.h> 

// node layout definition 
struct node 
{
    int data; 
    struct node* prev; 
    struct node* next; 
}; 

// interface function declarations 

// list creation 
struct node* create_list(void); 

// insertion functions 
int insert_start(struct node* p_list, int new_data); 
int insert_end(struct node* p_list, int new_data); 
int insert_before(struct node* p_list, int existing_data, int new_data); 
int insert_after(struct node* p_list, int existing_data, int new_data); 

// remove functions 
int remove_start(struct node* p_list); 
int remove_end(struct node* p_list); 
int remove_data(struct node* p_list, int r_data); 

// miscalleneaous 
int is_list_empty(struct node* p_list); 
void show(struct node* p_list, const char* msg); 

// list deletion 
int destroy_list(struct node* p_list); 

// client side 
int main(void) 
{
    return (0); 
} 

// server implementation 
// list creation function 
struct node* create_list(void) 
{
    struct node* new_list = NULL; 

    new_list = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_list) 
    {
        fprintf(stderr, "malloc():fatal:out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    new_list->data = 0; 
    new_list->next = NULL; 
    new_list->prev = NULL; 

    return (new_list); 
} 

// data insertion 
int insert_start(struct node* p_list, int new_data) 
{
    struct node* new_node = NULL; 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        fprintf(stderr, "malloc():fatal:out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 
    new_node->next = p_list->next; 
    new_node->prev = p_list; 
    if(p_list->next != NULL) 
        p_list->next->prev = new_node; 
    p_list->next = new_node; 

    return (1); 
} 

int insert_end(struct node* p_list, int new_data) 
{
    struct node* run = NULL; 

    run = p_list; 
    while(run->next != NULL) 
        run = run->next; 

    run->next = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == run->next) 
    {
        fprintf(stderr, "malloc():fatal:out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    run->next->next = NULL; 
    run->next->prev = run; 
    run->next->data = new_data; 
} 

int insert_after(struct node* p_list, int existing_data, int new_data) 
{
    struct node* run = NULL; 

    run = p_list->next; 
    while(run != NULL) 
    {
        if(run->data == existing_data) 
            break; 

        run = run->next; 
    } 

    if(run == NULL) 
        return (2); 

    struct node* new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        printf("malloc():fatal:out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 
    new_node->next = run->next; 
    new_node->prev = run; 

    if(run->next != NULL)
        run->next->prev = new_node; 
    run->next = new_node; 

    return (1); 
} 

int insert_before(struct node* p_list, int existing_data, int new_data) 
{
    struct node* run = NULL; 
    struct node* existing_node = NULL; 
    struct node* new_node = NULL; 

    // code 
    run = p_list->next; 
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
        fprintf(stderr, "insert_before():malloc():fatal:out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 

    new_node->next = existing_node; 
    new_node->prev = existing_node->prev; 
    if(existing_node->prev != NULL)
        existing_node->prev->next = new_node; 
    existing_node->prev = new_node; 

    return (1); 
} 

// remove functions 
int remove_start(struct node* p_list) 
{
    struct node* p_start_node = NULL; 

    if(p_list->next == NULL)    
        return (3); 

    p_start_node = p_list->next; 
    if(p_start_node->next != NULL) 
        p_start_node->next->prev = p_list; 
    p_list->next = p_start_node->next; 

    return (1); 
} 

int remove_end(struct node* p_list) 
{ 
    struct node* last_node = NULL; 
    struct node* run = NULL; 

    run = p_list; 
    while(run->next != NULL) 
        run = run->next; 

    run->prev->next = NULL; 
    free(run); 
    run = NULL; 

    return (1); 
}

int remove_data(struct node* p_list, int r_data) 
{
    struct node* run  = NULL; 
    struct node* delete_node = NULL; 

    // code 
    run = p_list->next; 
    while(run != NULL) 
    {
        if(run->data == r_data) 
            break; 
        run = run->next; 
    } 

    if(run == NULL) 
        return (3); 

    run->prev->next = run->next; 
    if(run->next != NULL) 
        run->next->prev = run->prev; 
    free(run); 
    run = NULL; 

    return (1); 
} 

// pop functions 
int pop_start(struct node* head_node, int* p_popped_data) 
{
    struct node* first_node = NULL; 

    // code 
    if(head_node->next == NULL && head_node->prev == NULL)
        return (3); 
    
    first_node = head_node->next; 
    *p_popped_data = first_node->data; 
    if(first_node->next != NULL) 
        first_node->next->prev = head_node; 
    head_node->next = first_node; 

    free(first_node); 
    first_node = NULL; 

    return (1); 
} 

// miscalleneaous functions 
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
        printf("[%d]->", run->data); 
        run = run->next; 
    } 
    puts("[END]"); 
} 

// List destruction function 
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

// ================================================================================================ 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <assert.h> 

// node layout definition 
struct node 
{
    int data; 
    struct node* prev; 
    struct node* next; 
}; 

// interface function declarations 
// list creation 
struct node* create_list(void); 

// data insertion 
int insert_start(struct node* head_node, int new_data); 
int insert_end(struct node* head_node, int new_data); 
int insert_before(struct node* head_node, int existing_data, int new_data); 
int insert_after(struct node* head_node, int existing_data, int new_data); 

// deletion functions 
int remove_start(struct node* head_node); 
int remove_end(struct node* head_node); 
int remove_data(struct node* head_node, int r_data); 

// miscalleneaous functions 
void show_list(struct node* head_node); 
int is_list_empty(struct node* p_list); 

// list destruction function 
int destroy_list(struct node* head_node); 

// client side 
int main(void) 
{
    return (0); 
} 

// server implementation 
// list creation function 
struct node* create_list(void) 
{
    struct node* new_list = NULL; 

    new_list = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_list) 
    {
        fprintf(stderr, "create_list() > error in allocating memory\n"); 
        exit(EXIT_FAILURE); 
    } 

    new_list->data = 0; 
    new_list->prev = NULL; 
    new_list->next = NULL; 

    return (new_list); 
} 

// data insertion functions 
int insert_start(struct node* head_node, int new_data) 
{
    struct node* new_node = NULL; 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        fprintf(stderr, "insert_start():malloc() > failed to allocate memory\n"); 
        exit(EXIT_FAILURE); 
    } 

    new_node->data = new_data; 
    new_node->next = NULL; 
    new_node->prev = NULL; 

    new_node->prev = head_node; 
    new_node->next = head_node->next; 
    if(head_node->next != NULL) 
        head_node->next->prev = new_node; 
    head_node->next = new_node; 

    return (1); 
} 

int insert_end(struct node* head_node, int new_data) 
{
    struct node* run = NULL; 
    struct node* new_node = NULL; 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        fprintf(stderr, "insert_end():malloc() > failed to allocate memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 
    new_node->prev = NULL; 
    new_node->next = NULL; 

    run = head_node; 
    while(run->next != NULL) 
    {
        run = run->next; 
    } 

    new_node->prev = run; 
    run->next = new_node; 

    return (1); 
} 

int insert_after(struct node* head_node, int existing_data, int new_data)
{
    struct node* new_node = NULL; 
    struct node* run = NULL; 

    run = head_node->next; 
    while(run != NULL) 
    {
        if(run->data == existing_data) 
        {
            new_node = (struct node*)malloc(sizeof(struct node)); 
            if(NULL == new_node) 
            {
                fprintf(stderr, "insert_after():malloc() > failed to allocate memory\n"); 
                exit(EXIT_FAILURE); 
            } 

            new_node->data = new_data; 
            new_node->next = run->next; 
            new_node->prev = run; 
            if(run->next != NULL) 
                run->next->prev = new_node;
            run->next = new_node; 

            return (1); 
        } 
        run = run->next; 
    } 

    return (2); 
} 

int insert_before(struct node* head_node, int existing_data, int new_data) 
{
    struct node* run = NULL; 
    struct node* new_node = NULL; 

    run = head_node->next; 
    while(run != NULL) 
    {
        if(run->data == existing_data) 
        {
            new_node = (struct node*)malloc(sizeof(struct node)); 
            if(NULL == new_node) 
            {
                fprintf(stderr, "insert_before():malloc() > failed to allocate memory\n"); 
                exit(EXIT_FAILURE); 
            } 
            new_node->data = new_data; 
            new_node->prev = run->prev; 
            new_node->next = run; 
            run->prev->next = new_node; 
            run->prev = new_node; 

            return (1); 
        } 

        run = run->next; 
    } 

    return (2); 
} 

// remove functions 
int remove_start(struct node* head_node) 
{
    struct node* first_node = NULL; 

    if(head_node->next == NULL && head_node->prev == NULL) 
        return (3); 
    
    first_node = head_node->next; 
    if(first_node->next != NULL) 
        first_node->next->prev = head_node; 
    head_node->next = first_node->next; 

    free(first_node); 
    first_node = NULL; 
    return (1); 
} 

int remove_end(struct node* head_node) 
{
    struct node* run = NULL; 
    struct node* run_prev = NULL; 

    if(head_node->next == NULL && head_node->prev == NULL) 
        return (2); 

    run = head_node; 
    while(run->next != NULL) 
    {
        run = run->next ;
    }
    
    run->prev->next = run->next; 
    if(run->next != NULL) 
        run->next->prev = run; 
    free(run); 
    run = NULL; 

    return (1); 
} 

int remove_data(struct node* head_node, int r_data) 
{
    struct node* run = NULL; 

    run = head_node->next; 
    while(run != NULL) 
    {
        if(run->data == r_data) 
        {
            run->prev->next = run->next; 
            run->next->prev = run->prev; 

            free(run); 
            run = NULL; 
            return (1); 
        }
        
        run = run->next; 
    } 

    return (3); 
} 

// miscalleneous functions 
int is_list_empty(struct node* head_node) 
{
    return (head_node->next == NULL && head_node->prev == NULL);
} 

void show_list(struct node* head_node) 
{
    struct node* run = NULL; 

    run = head_node->next; 
    printf("[START]->"); 
    while(run != NULL) 
    {
        printf("[%d]->", run->data); 
        run = run->next; 
    } 
    puts("[END]"); 
} 

// list destruction function 
int destroy_list(struct node* head_node) 
{
    struct node* run = NULL; 
    struct node* run_next = NULL; 

    run = head_node; 
    while(run != NULL) 
    {
        run_next = run->next ; 
        free(run); 
        run = run_next; 
    } 

    return (1); 
} 

// ==================================================================

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

#include <stdio.h> 
#include <stdlib.h>
#include <assert.h> 

// node layout definition 
struct node 
{
    int data; 
    struct node* next; 
    struct node* prev; 
}; 

// node layout definition 
struct node 
{
    int data; 
    struct node* next; 
    struct node* prev; 
};  

// node layout definition 
struct node 
{
    int data; 
    struct node* next; 
    struct node* prev; 
}; 

// interface function declarations 
struct node* create_list(void); 

// data insertion functions 
int insert_start(struct node* head_node, int new_data); 
int insert_end(struct node* head_node, int new_data); 
int insert_before(struct node* head_node, int existing_data, int new_data); 
int insert_after(struct node* head_node, int existing_data, int new_data); 

// data removal functions 
int remove_start(struct node* head_node); 
int remove_end(struct node* head_node); 
int remove_data(struct node* head_node, int r_data); 

// miscalleneous functions 
int is_list_empty(struct node* head_node); 
void show_list(struct node* head_node); 

// remove data 
int remove_data(struct node* head_node); 

// interface functions 
// list creation functions 
struct node* create_list(void); 

// data insertion funtions 
int insert_start(struct node* head_node, int new_data); 
int insert_end(struct node* head_node, int new_data); 
int insert_before(struct node* head_node, int existing_data, int new_data); 
int insert_after(struct node* head_node, int existing_data, int new_data); 

// data removal functions 
int remove_start(struct node* head_node); 
int remove_end(struct node* head_node); 
int remove_data(struct node* head_node, int r_data); 

// miscalleaous functions 
int is_list_empty(struct node* head_node); 
void show_list(struct node* head_node); 

// destroy list 
int destroy_list(struct node* head_node); 

// interface function declarations 
// list creation function 
struct node* create_list(void); 

// data insertion function 
int insert_start(struct node* head_node, int new_data); 
int insert_end(struct node* head_node, int new_data); 
int insert_after(struct node* head_node, int existing_data, int new_data); 
int insert_before(struct node* head_node, int existing_data, int new_data); 

// data removal functions 
int remove_start(struct node* head_node); 
int remove_end(struct node* head_node); 
int remove_data(struct node* head_node, int r_data); 

// miscalleneous functions 
int is_list_empty(struct node* head_node); 
void show_list(struct node* head_node); 

// list destruction function 
int destroy_list(struct node* head_node); 

// client side 
int main(void) 
{
    return (0); 
} 

// client side 
int main(void) 
{
    return (0); 
} 

// client side 
int main(void) 
{
    return (0); 
} 

// interface function definitions - server side 
// list creation funtion 
struct node* create_list(void) 
{
    struct node* new_list = NULL; 

    new_list = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_list) 
    {
        fprintf(stderr, "create_list():malloc(): memory allocation failure\n"); 
        exit(EXIT_FAILURE); 
    } 
    new_list->data = 0; 
    new_list->next = NULL; 
    new_list->prev = NULL; 

    return (new_list); 
} 

struct node* create_list(void) 
{
    struct node* new_list = NULL; 

    new_list = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_list) 
    {
        fprintf(stderr, "create_list():malloc(): failed to allocate memory\n"); 
        exit(EXIT_FAILURE); 
    } 

    new_list->data = 0; 
    new_list->next = NULL; 
    new_list->prev = NULL; 

    return (new_list); 
} 

struct node* create_list(void) 
{
    struct node* new_list = NULL; 

    new_list = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_list) 
    {
        fprintf(stderr, "create_list():malloc(): failure in memory allocation\n"); 
        exit(EXIT_FAILURE); 
    } 
    new_list->data = 0; 
    new_list->prev = NULL; 
    new_list->next = NULL; 

    return (new_list); 
} 

// insert function 
int insert_start(struct node* head_node, int new_data) 
{
    struct node* new_node = NULL; 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        fprintf(stderr, "insert_start():malloc():memory allocation failure\n"); 
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

int insert_start(struct node* head_node, int new_data) 
{
    struct node* new_node = NULL; 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        fprintf(stderr, "insert_start():malloc(): memory allocation failure\n"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 

    new_node->next = head_node->next; 
    new_node->prev = head_node; 
    if(head_node->next != NULL) 
        head_node->next->prev = new_node; 
    head_node->next = new_node; 

    return (1); 
} 

int insert_start(struct node* head_node, int new_data) 
{
    struct node* new_node = NULL; 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        fprintf(stderr, "insert_start():malloc():memory allocation failure\n"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 

    new_node->next = head_node->next; 
    new_node->prev = head_node; 
    if(head_node->next != NULL) 
        head_node->next->prev = new_node; 
    head_node->next = new_node; 

    return (1); 
} 

int insert_end(struct node* head_node, int new_data) 
{
    struct node* new_node = NULL; 
    struct node* run = NULL; 
    struct node* last_node = NULL; 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        fprintf(stderr, "insert_end():malloc():failure in memory allocation\n"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 
    new_node->next = NULL; 
    new_node->prev = NULL; 

    run = head_node;  
    while(run->next != NULL) 
    {
        run = run->next; 
    }
    
    new_node->next = run->next; 
    new_node->prev = run; 
    if(run->next != NULL) 
        run->next->prev = new_node; 
    run->next = new_node; 

    return (1); 
} 

int insert_end(struct node* head_node, int new_data) 
{
    struct node* new_node = NULL; 
    struct node* run = NULL; 
    struct node* last_node = NULL; 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        fprintf(stderr, "insert_end():malloc():failed to allocate memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 
    new_node->next = NULL; 
    new_node->prev = NULL; 

    run = head_node; 
    while(run->next != NULL) 
        run = run->next; 
    last_node = run; 

    new_node->prev = last_node; 
    last_node->next = new_node; 

    return (1); 
} 

int insert_end(struct node* head_node, int new_data) 
{
    struct node* new_node = NULL; 
    struct node* last_node = NULL; 
    struct node* run = NULL; 

    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node) 
    {
        fprintf(stderr, "insert_end():malloc(): memory allocation failure\n"); 
        exit(EXIT_SUCCESS); 
    } 
    new_node->data = new_data; 
    new_node->next = NULL; 
    new_node->prev = NULL; 

    run = head_node; 
    while(run->next != NULL) 
        run = run->next; 
    last_node = run; 

    last_node->next = new_node; 
    new_node->prev = last_node; 

    return (1); 
} 

int insert_before(struct node* head_node, int existing_data, int new_data) 
{
    struct node* new_node = NULL; 
    struct node* run = NULL; 

    run = head_node->next; 
    while(run != NULL) 
    {
        if(run->data == existing_data) 
        {
            new_node = (struct node*)malloc(sizeof(struct node)); 
            if(NULL == new_node) 
            {
                fprintf(stderr, "insert_before():malloc(): memory allocation failure\n"); 
                exit(EXIT_FAILURE); 
            } 
            new_node->data = new_data; 

            new_node->next = run; 
            new_node->prev = run->prev;  
            run->prev->next = new_node; 
            run->next = new_node; 

            return (1); 
        } 

        run = run->next; 
    } 

    return (2); 
} 

int insert_before(struct node* head_node, int existing_data, int new_data) 
{
    struct node* new_node = NULL; 
    struct node* run = NULL; 

    run = head_node->next; 
    while(run != NULL) 
    {
        if(run->data == existing_data) 
        {
            new_node = (struct node*)malloc(sizeof(struct node)); 
            if(NULL == new_node) 
            {
                fprintf(stderr, "insert_before():malloc(): memory allocation failure\n"); 
                exit(EXIT_FAILURE); 
            } 
            new_node->data = new_data; 
            new_node->next = run; 
            new_node->prev = run->prev; 
            run->prev->next = new_node; 
            run->prev = new_node; 

            return (1); 
        } 

        run = run->next; 
    } 

    return (2); 
} 

int insert_before(struct node* head_node, int existing_data, int new_data) 
{
    struct node* new_node = NULL; 
    struct node* run = NULL; 

    run = head_node->next; 
    while(run != NULL) 
    {
        if(run->data == existing_data) 
        {
            new_node = (struct node*)malloc(sizeof(struct node)); 
            if(NULL == new_node) 
            {
                fprintf(stderr, "insert_before():malloc():memory allocation failure\n"); 
                exit(EXIT_FAILURE); 
            } 
            new_node->data = new_data; 

            new_node->next = run; 
            new_node->prev = run->prev; 
            run->prev->next = new_node; 
            run->prev = new_node; 

            return (1); 
        } 

        run = run->next; 
    } 

    return (2); 
} 

int insert_after(struct node* head_node, int existing_data, int new_data) 
{
    struct node* new_node = NULL; 
    struct node* run = NULL; 

    run = head_node->next; 
    while(run != NULL) 
    {
        if(run->data == existing_data) 
        {
            new_node = (struct node*)malloc(sizeof(struct node)); 
            if(NULL == new_node) 
            {
                fprintf(stderr, "insert_after():malloc(): memory allocation failure\n"); 
                exit(EXIT_FAILURE); 
            } 
            new_node->data = new_data; 

            new_node->next = run->next; 
            new_node->prev = run; 
            if(run->next != NULL) 
                run->next->prev = new_node; 
            run->next = new_node; 

            return (1); 
        } 

        run = run->next; 
    } 

    return (2); 
} 

int insert_after(struct node* head_node, int existing_data, int new_data) 
{
    struct node* new_node = NULL; 
    struct node* run = NULL; 

    run = head_node; 
    while(run != NULL) 
    {
        if(run->data == existing_data) 
        {
            new_node = (struct node*)malloc(sizeof(struct node)); 
            if(NULL == new_node) 
            {
                fprintf(stderr, "insert_after():malloc():memory allocation failure\n"); 
                exit(EXIT_FAILURE); 
            } 
            new_node->data = new_data; 
            new_node->next = run->next; 
            new_node->prev = run; 
            if(run->next != NULL) 
                run->next->prev = new_node; 
            run->next = new_node; 

            return (1); 
        } 

        run = run->next; 
    } 

    return (2); 
} 

int insert_after(struct node* head_node, int existing_data, int new_data) 
{
    struct node* new_node = NULL; 
    struct node* run = NULL; 

    run = head_node->next; 
    while(run != NULL) 
    {
        if(run->data == existing_data) 
        {
            new_node = (struct node*)malloc(sizeof(struct node)); 
            if(NULL == new_node) 
            {
                fprintf(stderr, "insert_after():malloc():memory allocation failure\n"); 
                exit(EXIT_FAILURE); 
            } 
            new_node->data = new_data; 
            new_node->prev = run; 
            new_node->next = run->next; 
            if(run->next != NULL) 
                run->next->prev = new_node; 
            run->next = new_node; 

            return (1); 
        } 
        run = run->next; 
    } 

    return (2); 
} 

// removal functions 
int remove_start(struct node* head_node) 
{
    struct node* remove_node = NULL; 

    if(head_node->next == NULL && head_node->prev == NULL) 
        return (3); 

    remove_node = head_node->next; 

    if(remove_node->next != NULL) 
        remove_node->next->prev = remove_node->prev; 
    remove_node->prev->next = remove_node->next; 

    free(remove_node); 
    remove_node = NULL; 

    return (1); 
} 

int remove_start(struct node* head_node) 
{
    struct node* delete_node = NULL; 

    if(head_node->next == NULL) 
        return (3); 

    delete_node = head_node->next; 
    if(delete_node->next != NULL) 
        delete_node->next->prev = delete_node->prev; 
    delete_node->prev->next = delete_node->next; 

    free(delete_node); 
    delete_node = NULL; 

    return (1); 
} 

int remove_start(struct node* head_node) 
{
    struct node* delete_node = NULL; 

    if(head_node->next == NULL) 
        return (3); 

    delete_node = head_node->next; 
    if(delete_node->next != NULL)
        delete_node->next->prev = delete_node->prev; 
    delete_node->prev->next = delete_node->next; 

    free(delete_node); 
    delete_node = NULL; 
    return (1); 
} 

int remove_end(struct node* head_node) 
{
    struct node* delete_node = NULL; 
    struct node* run = NULL; 

    if(head_node->next == NULL) 
        return (3); 

    run = head_node->next; 
    while(run->next != NULL) 
        run = run->next; 

    delete_node = run; 
    delete_node->prev->next = NULL; 

    free(delete_node); 
    delete_node = NULL; 

    return (1); 
} 

int remove_end(struct node* head_node) 
{
    struct node* run = NULL; 
    struct node* delete_node = NULL; 

    if(head_node->next == NULL) 
        return (3); 

    run = head_node->next; 
    while(run->next != NULL) 
        run = run->next; 

    delete_node = run; 
    delete_node->prev->next = NULL; 
    free(delete_node); 
    delete_node = NULL; 

    return (1); 
} 

int remove_end(struct node* head_node) 
{
    struct node* delete_node = NULL; 
    struct node* run = NULL; 

    if(head_node->next == NULL) 
        return (3); 

    run = head_node->next; 
    while(run->next != NULL) 
        run = run->next; 

    delete_node = run; 
    delete_node->prev->next = delete_node->next; 
    free(delete_node); 
    delete_node = NULL; 

    return (1); 
} 

int remove_data(struct node* head_node, int r_data) 
{
    struct node* run = NULL; 

    run = head_node->next; 
    while(run != NULL) 
    { 
        if(run->data == r_data)
        {
            run->prev->next = run->next; 
            if(run->next != NULL) 
                run->next->prev = run->prev; 

            free(run); 
            run = NULL; 

            return (1); 
        } 

        run = run->next; 
    }

    return (2); 
} 

int remove_data(struct node* head_node, int r_data) 
{
    struct node* delete_node = NULL; 
    struct node* run = NULL; 

    if(head_node->next == NULL) 
        return (3); 

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
    delete_node = NULL; 

    return (1); 
} 

int remove_data(struct node* head_node, int r_data) 
{
    struct node* delete_node = NULL; 
    struct node* run = NULL; 

    if(head_node->next == NULL) 
        return (3); 

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

    return (1); 
} 

// miscalleneous functions 
int is_list_empty(struct node* head_node) 
{
    if(head_node->next == NULL && head_node->prev == NULL) 
        return (1); 
    return (0); 
} 

int is_list_emoty(struct node* head_node) 
{
    return (head_node->next == NULL && head_node->prev == NULL); 
} 

int is_list_empty(struct node* head_node) 
{
    if(head_node->next == NULL && head_node->prev == NULL) 
        return (1); 
    return (0); 
} 

void show_list(struct node* head_node) 
{
    struct node* run = NULL; 

    printf("[START]<->"); 
    run = head_node->next; 
    while(run != NULL) 
    {
        printf("[%d]<->", run->data); 
        run = run->next; 
    } 
    puts("[END]"); 
} 

void show_list(struct node* head_node) 
{
    struct node* run = NULL; 

    printf("[START]<->"); 
    run = head_node->next; 
    while(run != NULL) 
    {
        printf("[%d]<->", run->data); 
        run = run->next; 
    } 
    puts("[END]"); 
} 

void show_list(struct node* head_node) 
{
    struct node* run = NULL; 

    printf("[START]<->"); 
    run = head_node->next; 
    while(run != NULL) 
    {
        printf("[%d]<->", run->data); 
        run = run->next; 
    } 
    puts("[END]"); 
} 

// list destruction function 
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


