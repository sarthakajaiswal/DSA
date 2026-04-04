#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include "graph.h"

struct edge
{
	int v_start;
	int v_end;
};

int main(void)
{
	graph_t* g = NULL;
	vertex_t V[] = { 1, 2, 3, 4, 5, 6 };
	struct edge E[] = { {1, 2}, {1, 6}, {2, 6}, {2, 5}, {2, 3}, {3, 4}, {3, 6}, {3, 5}, {4, 5}, {5, 6} };
	int i;
	status_t status;

	g = create_graph();

	for (i = 0; i < sizeof(V) / sizeof(V[0]); ++i)
	{
		status = add_vertex(g, V[i]);
		assert(status == SUCCESS);
	}

	for (i = 0; i < sizeof(E) / sizeof(E[0]); ++i)
	{
		status = add_edge(g, E[i].v_start, E[i].v_end);
		assert(status == SUCCESS);
	}

	show_graph(g, "Initial State:");
	
	printf("DFS VISIT:\n"); 
	
	dfs(g); 

	puts("BFS(g, 1):"); 
	bfs(g, 1); 
	
	
	puts("BFS(g, 2):");
	bfs(g, 2); 
	
	
	puts("BFS(g, 3):");
	bfs(g, 3); 
	 
	status = destroy_graph(&g);
	assert(status == SUCCESS && g == NULL);

	puts("Graph testing completed successfully\n"); 

	return (0);
}

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include "graph.h" 

struct edge 
{
	vertex_t v_start; 
	vertex_t v_end; 
}; 

int main(void) 
{
	graph_t* g = NULL; 
	vertex_t V[] = { 1, 2, 3, 4, 5, 6 }; 
	struct edge E[] = { {1, 2}, {1, 6}, {2, 6}, {2, 5}, {2, 3}, {3, 4}, {3, 6}, {3, 5}, {4, 5}, {5, 6} }; 
	int i; 
	status_t status; 

	g = create_graph(); 

	for(int i = 0; i < sizeof(V) / sizeof(V[0]); ++i) 
		assert(add_vertex(g, V[i]) == SUCCESS); 

	for(int i = 0; i < sizeof(E) / sizeof(E[0]); ++i) 
		assert(add_edge(g, E[i].v_start, E[i].v_end) == SUCCESS); 

	show_graph(g, "Initial state:"); 

	printf("DFS visit:\n"); 
	dfs(g); 

	puts("BFS(g, 1):"); 
	bfs(g, 1); 

	puts("BFS(g, 2):"); 
	bfs(g, 2); 

	puts("BFS(g, 3):"); 
	bfs(g, 3); 

	assert(destroy_graph(&g) == SUCCESS); 

	return (0); 
} 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include "graph.h" 

struct edge 
{
	vertex_t v_start; 
	vertex_t v_end; 
}; 

int main(void) 
{
	graph_t* g = NULL; 
	vertex_t V[] = { 1, 2, 3, 4, 5, 6 }; 
	struct edge E[] = { {1, 2}, {1, 6}, {2, 6}, {2, 5}, {2, 3}, {3, 4}, {3, 6}, {3, 5}, {4, 5}, {5, 6} }; 
	int i; 

	g = create_graph(); 

	for(int i = 0; i < sizeof(V) / sizeof(V[0]); ++i) 
		assert(add_vertex(g, V[i]) == SUCCESS); 

	for(int i = 0; i < sizeof(E) / sizeof(E[0]); ++i) 
		assert(add_edge(g, E[i].v_start, E[i].v_end) == SUCCESS); 

	show_graph(g, "initial state:"); 

	printf("dfs visit:\n"); 
	dfs(g); 

	puts("bfs(g, 1):"); 
	bfs(g, 1); 

	puts("bfs(g, 2):"); 
	bfs(g, 2); 

	puts("bfs(g, 3):");
	bfs(g, 3); 

	assert(destroy_graph(&g) == SUCCESS); 
	return (0); 
} 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include "graph.h" 

struct edge 
{
	vertex_t v_start; 
	vertex_t v_end; 
}; 

int main(void) 
{
	graph_t* g = NULL; 
	vertex_t V[] = { 1, 2, 3, 4, 5, 6 }; 
	struct edge E[] = { {1, 2}, {1, 6}, {2, 6}, {2, 5}, {2, 3}, {3, 4}, {3, 6}, {3, 5}, {4, 5}, {5, 6} }; 
	int i; 

	for(i = 0; i < sizeof(V)/sizeof(V[0]); ++i) 
		assert(add_vertex(g, V[i]) == SUCCESS); 

	for(i = 0; i < sizeof(E)/sizeof(E[0]); ++i) 
		assert(add_edge(g, E[i].v_start, E[i].v_end) == SUCCESS); 

	show_graph(g, "initial state:"); 

	puts("dfs(g):"); 
	dfs(g); 

	puts("bfs(g, 1):"); 
	bfs(g, 1); 
	puts("bfs(g, 2):"); 
	bfs(g, 2); 
	puts("bfs(g, 3):"); 
	bfs(g, 3); 

	assert(destroy_graph(&g) == SUCCESS); 

	return (0); 
} 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include "graph.h" 

struct edge 
{
	vertex_t v_start; 
	vertex_t v_end; 
}; 

int main(void) 
{
	graph_t* g = NULL; 
	vertex_t V[] = { 1, 2, 3, 4, 5, 6 }; 
	struct edge E[] = { {1, 2}, {1, 6}, {2, 6}, {2, 5}, {2, 3}, {3, 4}, {3, 6}, {3, 5}, {4, 5}, {5, 6} }; 

	g = create_graph(); 

	for(int i = 0; i < sizeof(V)/sizeof(V[0]); ++i) 
		assert(add_vertex(g, V[i]) == SUCCESS); 

	for(int i = 0; i < sizeof(E)/sizeof(E[0]); ++i) 
		assert(add_edge(g, E[i].v_start, E[i].v_end) == SUCCESS); 

	show_graph(g, "Initial state:"); 

	printf("DFS Visit:\n"); 
	dfs(g); 

	puts("BFS(g, 1):"); 
	bfs(g, 1); 

	puts("BFS(g, 2):"); 
	bfs(g, 2); 

	puts("BFS(g, 3):"); 
	bfs(g, 3); 

	assert(destroy_graph(&g) == SUCCESS); 
	return (0); 
} 
