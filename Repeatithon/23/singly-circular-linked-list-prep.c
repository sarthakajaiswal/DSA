#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

struct node 
{
    int data; 
    struct node* next; 
}; 

struct node 
{
    int data; 
    struct node* next; 
}; 

struct node 
{
    int data; 
    struct node* next; 
}; 

struct node 
{
    int data; 
    struct node* next; 
}; 

struct node 
{
    int data; 
    struct node* next; 
}; 

void experiment(void); 
void experiment(void); 
void experiment(void); 
void experiment(void); 
void experiment(void); 

int main(void) 
{
    experiment(); 
    return (0); 
} 

int main(void) 
{
    experiment(); 
    return (0); 
} 

int main(void) 
{
    experiment(); 
    return (0); 
} 

int main(void) 
{
    experiment(); 
    return (0); 
} 

int main(void) 
{
    experiment();
    return (0); 
} 

void experiment(void) 
{
    struct node* head_node = NULL; 

    head_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == head_node) 
    {
        puts("malloc():failed\n");
        exit(EXIT_FAILURE); 
    } 

    head_node->data = 0; 
    head_node->next = head_node; 

    // first node with data 
    struct node* first_node = NULL; 
    first_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == first_node) 
    {
        puts("malloc() failed"); 
        exit(EXIT_FAILURE); 
    } 
    first_node->data = 100; 
    first_node->next = head_node; 
    head_node->next = first_node; 

    // second node with data 
    struct node* second_node = NULL; 

    second_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == second_node) 
    {
        puts("malloc() failed"); 
        exit(EXIT_FAILURE); 
    } 
    second_node->data = 200; 
    second_node->next = head_node; 
    first_node->next = second_node; 

    // third node with data 
    struct node* third_node = NULL; 
    third_node = (struct node*)malloc(sizeof(struct node)); 
    if(third_node == NULL)
    {
        puts("malloc() failed"); 
        exit(EXIT_FAILURE); 
    } 
    third_node->data = 300; 
    third_node->next = head_node; 
    second_node->next = third_node; 

    puts("travelling through all nodes with data"); 

    struct node* run = NULL; 

    run = head_node->next; 
    while(run != head_node) 
    {
        printf("run->data = %d\n", run->data); 
        run = run->next; 
    } 

    // last node 
    run = head_node->next; 
    while(run->next != head_node) 
    {
        run = run->next; 
    } 

    printf("run->data == %d\n", run->data); // 300 

    // last node and second to last node 
    struct node* run_previous = NULL; 

    // assertion here: list is non-empty 
    run_previous = head_node; 
    run = head_node->next; 
    while(run->next != head_node) 
    {
        run_previous = run; 
        run = run->next; 
    } 

    // search data 
    int search_data = 200; 
    run_previous = head_node; 
    run = head_node->next; 
    while(run != head_node) 
    {
        if(run->data == search_data) 
            break; 
        run_previous = run; 
        run = run->next; 
    } 
    if(run == head_node) 
        puts("seach data not found"); 

    printf("run->data = %d, search data = %d\n", run->data, search_data); 

    //destroy linked list 
    struct node* run_next = NULL; 
    run = head_node->next; 
    while(run != head_node) 
    {
        run_next = run->next; 
        free(run);  
        run = run->next; 
    } 

    free(head_node); 
    head_node = NULL; 

    puts("Linked list destroyed successfully"); 
} 

void experiment(void) 
{
    struct node* head_node = NULL; 

    head_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == head_node) 
    {
        puts("malloc():failed"); 
        exit(EXIT_FAILURE); 
    } 
    head_node->data = 0; 
    head_node->next = head_node; 

    // first node with data 
    struct node* first_node = NULL; 

    first_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == first_node) 
    {
        puts("malloc():failed"); 
        exit(EXIT_FAILURE); 
    } 
    first_node->data = 100; 
    first_node->next = head_node; 
    head_node->next = first_node; 

    // second node with data 
    struct node* second_node = NULL; 

    second_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == second_node) 
    {
        puts("malloc():failed"); 
        exit(EXIT_FAILURE); 
    } 
    second_node->data = 200; 
    second_node->next = head_node; 
    head_node->next = second_node; 

    // third node with data 
    struct node* third_node = NULL; 

    third_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == third_node) 
    {
        puts("malloc():failed"); 
        exit(EXIT_FAILURE); 
    } 
    third_node->data = 300; 
    third_node->next = head_node; 
    head_node->next = third_node; 

    // travelling all nodes with data 
    struct node* run = NULL; 

    run = head_node->next; 
    while(run != head_node) 
    {
        printf("[%d]->", run->data); 
        run = run->next; 
    } 

    // get last node 
    run = head_node; 
    while(run->next != head_node) 
        run = run->next; 
    // here run is last node or the head node if list is empty 
    printf("last data = %d\n", run->data); // 300 

    // get last node and its predecessor 
    struct node* run_previous = NULL; 
    run_previous = head_node; 
    run = head_node->next; 
    while(run->next != head_node) 
    {
        run_previous = run; 
        run = run->next; 
    } 

    // find the node and its predecessor node given the data 
    int search_data = 200; 
    struct node* run_previous = head_node; 
    run = head_node->next; 
    while(run != head_node) 
    {
        if(run->data == search_data) 
            break; 
        run_previous = run; 
        run = run->next; 
    } 

    if(run == head_node) 
        puts("Search data not found"); 
    else 
        printf("run->data == %d search_data == %d\n", run->data, search_data); 

    // destroying list 
    struct node* run_next = NULL; 
    run = head_node->next; 
    while(run != head_node) 
    {
        run_next = run->next; 
        free(run); 
        run = run_next; 
    } 
    free(head_node);    
    head_node = NULL; 

    first_node = NULL; 
    second_node = NULL; 
    third_node = NULL; 
} 

void experiment(void) 
{
    struct node* head_node = NULL; 

    head_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == head_node) 
    { 
        puts("malloc():failed"); 
        exit(EXIT_FAILURE); 
    } 
    head_node->data = 0; 
    head_node->next = head_node; 

    // first node with data 
    struct node* first_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == first_node) 
    {
        puts("malloc():failed"); 
        exit(EXIT_FAILURE); 
    } 
    first_node->data =100; 
    first_node->next = first_node; 

    // second node with data 
    struct node* second_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == second_node) 
    {
        puts("malloc(): failed"); 
        exit(EXIT_FAILURE); 
    } 
    second_node->data = 200; 
    second_node->next = head_node; 
    first_node->next = head_node; 

    // third node with data 
    struct node* third_node = NULL; 
    third_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == third_node) 
    {
        puts("malloc() failed"); 
        exit(EXIT_FAILURE); 
    } 
    third_node->data = 300; 
    third_node->next = head_node; 
    second_node->next = third_node; 

    // travelling through all nodes with data 
    struct node* run = NULL; 
    run = head_node->next; 
    while(run != head_node) 
    {
        // some operation 
        run = run->next; 
    } 

    // get last node 
    run = head_node->next; 
    while(run->next != head_node) 
        run = run->next; 

    printf("run->data = %d\n", run->data); // 300 

    // getting node with data and its predecessor 
    int search_data = 200; 
    struct node* run_previous = NULL; 

    run = head_node->next; 
    run_previous = head_node; 
    while(run != head_node) 
    {
        if(run->data == search_data) 
            break; 

        run_previous = run; 
        run = run->next; 
    } 

    if(run == head_node) 
        puts("Search data not found"); 
    else 
        printf("run->data == %d and search_data == %d\n", run->data, search_data); 

    // find last node and its predecessor 
    run = head_node->next; 
    run_previous = head_node; 
    while(run->next != head_node) 
    {
        run_previous = run; 
        run = run->next; 
    } 

    // destroy list 
    struct node* run_next = NULL; 

    run = head_node->next; 
    while(run != head_node) 
    {
        run_next = run->next; 
        free(run); 
        run = run_next; 
    } 

    free(head_node); 
    head_node = NULL; 

    puts("Linked list destroyed successfully"); 
} 

void experiment(void) 
{
    struct node* head_node = NULL; 

    head_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == head_node) 
    {
        puts("malloc():failed"); 
        exit(EXIT_FAILURE); 
    } 
    head_node->data = 0; 
    head_node->next = head_node; 

    // first node with data 
    struct node* first_node = NULL; 
    first_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == first_node) 
    {
        puts("malloc():failed"); 
        exit(EXIT_FAILURE); 
    } 
    first_node->data = 100; 
    first_node->next = head_node; 
    first_node->next = first_node; 

    // second node with data 
    struct node* second_node = NULL; 
    second_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == first_node) 
    {
        puts("malloc():failed"); 
        exit(EXIT_FAILURE); 
    } 
    second_node->data = 200; 
    second_node->next = head_node; 
    first_node->next = second_node; 

    // third node with data 
    struct node* third_node = NULL; 
    third_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == third_node) 
    {
        puts("malloc():failed"); 
        exit(EXIT_FAILURE); 
    } 
    third_node->data = 300; 
    third_node->next = head_node; 
    second_node->next = third_node; 

    // travelling through all nodes with data 
    struct node* run = NULL; 
    run = head_node->next; 
    while(run != head_node) 
    {
        printf("run->data = %d\n", run->data); 
        run = run->next; 
    } 

    // get last node with data 
    run = head_node->next; 
    while(run->next != head_node) 
        run  = run->next; 

    printf("run->data = %d\n", run->data); 

    // get last node and last previous node 
    struct node* run_previous = NULL; 
    run_previous = head_node; 
    run = head_node->next; 
    while(run->next != head_node) 
    {
        run_previous = run; 
        run = run->next; 
    } 

    // find node with data and its predecessor 
    int search_data = 200; 
    run_previous = head_node; 
    run = head_node->next; 
    while(run->next != head_node) 
    {
        if(run->data == search_data) 
            break;
        run_previous = run; 
        run = run->next; 
    } 

    if(run == head_node) 
        puts("searcg data not found"); 
    else 
        printf("run->data == %d and search_data == %d\n", run->data, search_data); 

    // destroy list 
    struct node* run_next = NULL; 
    run = head_node->next; 
    while(run != head_node) 
    {
        run_next = run->next; 
        free(run); 
        run = run->next; 
    } 
    free(head_node); 
    head_node = NULL; 

    first_node = NULL; 
    second_node = NULL; 
    third_node = NULL; 

    puts("Linked list destroyed successfully"); 
} 

void experiment(void) 
{
    // dummy node / representative node 
    struct node* head_node = NULL; 
    head_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == head_node) 
    { 
        puts("malloc():failed"); 
        exit(EXIT_FAILURE); 
    } 
    head_node->data = 0; 
    head_node->next = head_node; 

    // first node with data 
    struct node* first_node = NULL; 
    first_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == first_node) 
    {
        puts("malloc():failed"); 
        exit(EXIT_FAILURE); 
    } 
    first_node->data = 100; 
    first_node->next = head_node; 
    head_node->next = first_node; 

    // second node with data 
    struct node* second_node = NULL; 
    second_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == second_node) 
    {
        puts("malloc():failed"); 
        exit(EXIT_FAILURE); 
    } 
    second_node->data = 200; 
    second_node->next = head_node; 
    first_node->next = second_node; 

    // third node with data 
    struct node* third_node = NULL; 
    third_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == third_node) 
    {
        puts("malloc():failed"); 
        exit(EXIT_FAILURE); 
    } 
    third_node->data = 300; 
    third_node->next = head_node; 
    second_node->next = third_node; 

    // traversing all nodes with data 
    struct node* run = NULL; 
    run = head_node->next; 
    while(run != head_node) 
    {
        printf("run->data = %d\n", run->data); 
        run = run->next; 
    } 

    // get last node with data 
    run = head_node->next; 
    while(run->next != head_node) 
    {
        run = run->next; 
    } 
    printf("run->data = %d\n", run->data); 

    // get last node and its previous 
    struct node* run_previous = NULL; 
    run_previous = head_node; 
    run = head_node->next; 
    while(run != head_node) 
    {
        run_previous = run; 
        run = run->next; 
    } 

    // get node with data and its previous 
    int search_data = 200; 
    run_previous = head_node; 
    run = head_node->next; 
    while(run != head_node) 
    {
        if(run->data == search_data) 
            break; 

        run_previous = run; 
        run = run->next; 
    } 
    if(run == head_node) 
        puts("List data not found"); 
    else 
        printf("run->data == %d and search_data == %d\n", run->data, search_data); 

    // destroy list 
    struct node* run_next = NULL; 
    run = head_node->next; 
    while(run != head_node) 
    {
        run_next = run->next; 
        free(run); 
        run = run_next; 
    } 
    free(head_node); 
    head_node = NULL; 

    puts("Linked list destroyed successfully"); 
} 
