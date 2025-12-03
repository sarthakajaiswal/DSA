#include <stdio.h> 
#include <stdlib.h> 

struct node 
{
    int data;           // data instance 
    struct node* prev;  // backward link 
    struct node* next;  // forward link 
}; 

void experiment_1(void); 

int main(void)
{
    experiment_1(); 
    return (0); 
}

void experiment_1(void)
{
    struct node* p_node = NULL; 

    p_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_node)
    {
        fprintf(stderr, "malloc():fatal:out of memory\n"); 
        exit(EXIT_FAILURE); 
    }

    p_node->data = 100; 
    p_node->prev = NULL; 
    p_node->next = NULL; 

    printf("Address in p_node:p_node = %zu\n", (unsigned long long)p_node); 
    printf("Address of member named data:&p_node->data = %zu\n", (unsigned long long)(&p_node->data)); 
    printf("Address of member named prev:&p_node->prev= %zu\n", (unsigned long long)(&p_node->prev));
    printf("Address of member named next:&p_node->next = %zu\n", (unsigned long long)(&p_node->next));

    //  release the node
    free(p_node); 
    p_node = NULL; 
}