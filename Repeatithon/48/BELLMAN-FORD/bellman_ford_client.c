#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include "bellman_ford.h" 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include "bellman_ford.h" 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include "bellman_ford.h" 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include "bellman_ford.h" 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include "bellman_ford.h" 

#define NR_INIT_VERTICES   8 
#define NR_INIT_EDGES      16 

#define NR_INIT_VERTICES   8 
#define NR_INIT_EDGES      16 

#define NR_INIT_VERTICES   8 
#define NR_INIT_EDGES      16 

#define NR_INIT_VERTICES   8 
#define NR_INIT_EDGES      16 

#define NR_INIT_VERTICES   8 
#define NR_INIT_EDGES      16 

struct edge 
{
    vertex_t v_start; 
    vertex_t v_end; 
    double w; 
}; 

struct edge 
{
    vertex_t v_start; 
    vertex_t v_end; 
    double w; 
}; 

struct edge 
{
    vertex_t v_start; 
    vertex_t v_end; 
    double w; 
}; 

struct edge 
{
    vertex_t v_start; 
    vertex_t v_end; 
    double w; 
}; 

struct edge 
{
    vertex_t v_start; 
    vertex_t v_end; 
    double w; 
}; 

void test_bellman_ford(void); 
void test_bellman_ford(void); 
void test_bellman_ford(void); 
void test_bellman_ford(void); 
void test_bellman_ford(void); 

int main(void) 
{
    test_bellman_ford(); 
    return (0); 
} 

int main(void) 
{
    test_bellman_ford(); 
    return (0); 
} 

int main(void) 
{
    test_bellman_ford(); 
    return (0); 
} 

int main(void) 
{
    test_bellman_ford(); 
    return (0); 
} 

int main(void) 
{
    test_bellman_ford(); 
    return (0); 
} 

void test_bellman_ford(void) 
{
    graph_t* g = NULL; 
    edgelist_t* p_edge_list; 
    vertex_t v; 
    vertex_t s;  
    int i; 
    status_t status; 

    struct edge E[] = {
        {1, 6, 2.0}, {1, 2, 1.0}, {2, 7, 5.0}, {2, 3, 2.0}, 
        {6, 7, 3.0}, {5, 7, 2.0}, {7, 2, 1.0}, {7, 8, 3.0}, 
        {4, 2, 3.0}, {4, 8, 5.0}, {3, 8, 3.0}, {5, 8, 4.0}, 
        {5, 4, 2.0}, {3, 4, 1.0}, {8, 1, 2.5}, {8, 6, 3.0} 
    }; 

    g = create_graph(); 
    for(v = 1; v <= NR_INIT_VERTICES; ++v) 
        add_vertex(g, v); 

    for(i = 0; i < NR_INIT_EDGES; ++i) 
        add_edge(g, E[i].v_start, E[i].v_end, E[i].w); 

    show_graph(g, "Inital State: "); 

    status = bellman_ford(g, 2); 
    if(status == G_NEGATIVE_PATH_CYCLE) 
        puts("BellmanFord failed because presence of negative path cycle"); 
    else if(status == SUCCESS); 
    {
        printf("Source vertex : %d\n", s); 
        print_all_shortest_path(g); 
    }  

    assert(destroy_graph(&g) == SUCCESS); 
    return (SUCCESS); 

    ////////////////// 

    g = create_graph(); 

    for(vertex_t v = 1; v <= NR_INIT_VERTICES; v += 1) 
        insert_vertex(g, v); 

    for(i = 0; i < NR_INIT_EDGES; ++i) 
        insert_edge(g, E[i].v_start, E[i].v_end, E[i].w); 

    show_graph(g, "Initial State: "); 

    s = 1; 
    status = bellman_ford(g, s); 
    if(status == G_NEGATIVE_PATH_CYCLE) 
        puts("BellmanFord failed due to negative path cycle"); 
    else 
    {
        printf("source vertex: %d\n", s); 
        print_all_shortest_path(g); 
    } 

    assert(destroy_graph(&g) == SUCCESS); 
    return (SUCCESS); 

    ///////////////// 
    
    g = create_graph(); 

    for(vertex_t v = 1; v <= NR_INIT_VERTICES; v += 1) 
        insert_vertex(g, v); 

    for(i = 0; i <= NR_INIT_EDGES; ++i) 
        insert_edge(g, E[i].v_start, E[i].v_end, E[i].w); 

    show_graph(g, "Initial State: "); 

    s = 4; 
    status = bellman_ford(g, s); 
    if(status == G_NEGATIVE_PATH_CYCLE) 
        puts("BellmanFord failed due to negative path cycle"); 
    else 
    {
        printf("source vertex: %d\n", s); 
        print_all_shortest_path(g); 
    } 

    assert(destroy_graph(&g) == SUCCESS); 
    return (SUCCESS); 

    ///////////////// 

    g = create_graph(); 

    for(vertex_t v = 1; v <= NR_INIT_VERTICES; v += 1) 
        insert_vertex(g, v); 

    for(i = 0; i <= NR_INIT_EDGES; ++i) 
        insert_edge(g, E[i].v_start, E[i].v_end, E[i].w); 

    show_graph(g, "Initial State:"); 

    s = 3; 
    status = bellman_ford(g, s); 
    if(status == G_NEGATIVE_PATH_CYCLE) 
        puts("Bellman Ford failed due to negative path cycle"); 
    else 
    {
        printf("Source vertex = %d\n", s); 
        print_all_shortest_paths(g); 
    } 

    ///////////////// 

    g = create_graph(); 

    for(vertex_t v = 1; v <= NR_INIT_VERTICES; ++v) 
        insert_vertex(g, v); 

    for(i = 0; i < NR_INIT_EDGES; ++i) 
        insert_edge(g, E[i].v_start, E[i].v_end, E[i].w); 

    show_graph(g, "Initial State: "); 

    s = 2; 
    status = bellman_ford(g, s); 
    if(status == G_NEGATIVE_PATH_CYCLE) 
        puts("BellmanFord failed due to negative path cycle"); 
    else 
    {
        printf("source vertex=%d\n", s); 
        print_all_shortest_paths(g); 
    } 

    assert(destroy_graph(&g) == SUCCESS); 
    return (SUCCESS); 
} 
