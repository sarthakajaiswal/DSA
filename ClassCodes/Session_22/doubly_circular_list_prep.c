/*
	@GOAL: 		Doubly Circular Linked list preparation code 
	@DATE:		06 Dec 2025 
	@AUTHOR: Sarthak A. Jaiswal 
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

struct node 
{
int data; 
struct node* prev; 
struct node* next; 
};

void experiment(void); 

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
	puts("malloc(): fatal: out of memory"); 
	exit(EXIT_FAILURE); 
} 
printf("Address in head_node = %zu\n", (unsigned long long)head_node); 

// Right now the linked list is empry 
// as per requirements of doubly circular linked list 
// the prev pointer of head node should point to last node i.e. itself here 
// and next should also point to head node itself 

head_node->prev = head_node; 
head_node->next = head_node; 

// first node with data 
struct node* first_node = NULL; 
first_node = (struct node*)malloc(sizeof(struct node)); 
if(first_node == NULL) 
{
	puts("maloc(): fatal: out of memory"); 
	exit(EXIT_FAILURE); 
} 
first_node->data = 100; 
printf("Address in first_node = %zu\n", (unsigned long long)first_node); 
head_node->next = first_node; 
head_node->prev = first_node; 

first_node->next = head_node; 
first_node->prev = head_node; 

// second node with data 
struct node* second_node = NULL; 
second_node = (struct node*)malloc(sizeof(struct node)); 
if(NULL == second_node) 
{
	puts("malloc(): fatal: out of memory"); 
	exit(EXIT_FAILURE); 
} 
second_node->data = 200; 

first_node->next = second_node; 
second_node->prev = first_node; 
second_node->next = head_node; 
head_node->prev = second_node; 
printf("Address in second_node = %zu\n", (unsigned long long)second_node); 

// third node with data 
struct node* third_node = NULL; 
third_node = (struct node*)malloc(sizeof(struct node)); 
if(NULL == third_node) 
{
	puts("malloc(): fatal: out o memory"); 
	exit(EXIT_FAILURE); 
} 

second_node->next = third_node; 
third_node->prev = second_node; 
third_node->next = head_node; 
head_node->prev = third_node; 

third_node->data = 300; 
printf("Address in third_node = %zu\n", (unsigned long long)third_node); 

// traversal 
struct node* run = NULL; 

run = head_node->next; // next pointer of head node points to first node with data 
while(run != head_node) // node the peculiar termination condition, its run != p_list; 
{
	printf("run->data = %d\n", run->data);
	run = run->next; 
} 

// destroy linked list: free all nodes along with head node 
struct node* run_next = NULL; 

// stage1: free all nodes with data (i.e. all nodes except head node will be freed)
run = head_node->next; 
while(run != head_node) 
{
	run_next = run->next; 
	printf("Freeing node at address: %zu and content: %d\n", (unsigned long long)run, run->data); 
	free(run); 
	run = run_next; 
} 

// stage2: free the head node 
free(head_node); 
printf("freeing node at address = %zu\n", (unsigned long long)head_node); 
head_node = NULL; 

printf("List destroyed successfully\n"); 
} 