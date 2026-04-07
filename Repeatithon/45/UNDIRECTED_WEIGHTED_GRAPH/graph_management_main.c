#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include "graph.h" 

struct edge 
{
    vertex_t v_start; 
    vertex_t v_end; 
    double w; 
}; 

int main(void) 
{
    graph_t* g = NULL; 
    vertex_t V[] = { 1, 2, 3, 4, 5, 6 }; 
    struct edge E[] = {
                        {1, 2, 2.3}, {1, 6, 3.1}, {2, 6, 0.5}, {2, 5, 3.8}, {2, 3, 4.3}, 
                        {3, 4, 6.3}, {3, 6, 2.6}, {3, 5, 0.9}, {4, 5, 1.1}, {5, 6, 2.21}                  
                    }; 
    int i; 
    status_t status; 

    g = create_graph(); 

    for(i = 0; i < sizeof(V)/sizeof(V[0]); ++i) 
        assert(add_vertex(g, V[i]) == SUCCESS); 

    for(i = 0; i < sizeof(E) / sizeof(E[0]); ++i) 
        assert(add_edge(g, E[i].v_start, E[i].v_end, E[i].w) == SUCCESS); 

    show_graph(g, "Initial state:"); 

    assert(remove_edge(g, 2, 5) == SUCCESS); 
    assert(remove_edge(g, 2, 3) == SUCCESS); 
    assert(remove_edge(g, 6, 2) == SUCCESS); 
    assert(remove_edge(g, 6, 5) == SUCCESS); 
    show_graph(g, "After removing edges (2,5), (2,3), (6,2), (6,5): "); 

    assert(remove_vertex(g, 3) == SUCCESS); 
    show_graph(g, "After removing vertex 5:"); 
    
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
    double w; 
}; 

int main(void) 
{
    graph_t* g = NULL; 
    vertex_t V[] = { 1, 2, 3, 4, 5, 6 }; 
    struct edge E[] = {
                        {1, 2, 2.3}, {1, 6, 3.1}, {2, 6, 0.5}, {2, 5, 3.2}, {2, 3, 4.3}, 
                        {3, 4, 6.3}, {3, 6, 2.6}, {3, 5, 0.9}, {4, 5, 1.1}, {5, 6, 2.21}                 
                    }; 

    g = create_graph(); 

    for(int i = 0; i < sizeof(V)/sizeof(V[0]); ++i) 
        assert(add_vertex(g, V[i]) == SUCCESS); 

    for(int i = 0; i < sizeof(E)/sizeof(E[0]); ++i) 
        assert(add_edge(g, E[i].v_start, E[i].v_end, E[i].w) == SUCCESS); 

    assert(remove_edge(g, 2, 5) == SUCCESS); 
    assert(remove_edge(g, 2, 3) == SUCCESS); 
    assert(remove_edge(g, 6, 2) == SUCCESS); 
    assert(remove_edge(g, 6, 5) == SUCCESS); 
    show_graph(g, "After removing edges, (2,5), (2,3), (6,2), (6,5): "); 

    assert(remove_vertex(g, 3) == SUCCESS); 
    show_graph(g, "After removing vertex: 3:"); 

    assert(destroy_graph(&g) == SUCCESS && g == NULL); 

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
    double w; 
}; 

int main(void) 
{
    graph_t* g = NULL; 
    vertex_t V[] = { 1, 2, 3, 4, 5, 6 }; 
    struct edge E[] = {
                        {1, 2, 2.3}, {1, 6, 3.1}, {2, 5, 3.8}, {2, 3, 4.3}, {2, 6, 4.3}, 
                        {3, 4, 6.3}, {3, 6, 2.6}, {3, 5, 0.9}, {4, 5, 1.3}, {5, 6, 2.8}                 
                    }; 

    for(int i = 0; i <sizeof(V)/sizeof(V[0]); ++i) 
        assert(add_vertex(g, V[i]) == SUCCESS); 

    for(int i = 0; i < sizeof(E) / sizeof(E[0]); ++i) 
        assert(add_edge(g, E[i].v_start, E[i].v_end, E[i].w) == SUCCESS); 

    show_graph(g, "Initial State: "); 

    assert(remove_edge(g, 2, 3) == SUCCESS); 
    assert(remove_edge(g, 2, 5) == SUCCESS); 
    assert(remove_edge(g, 6, 2) == SUCCESS); 
    assert(remove_edge(g, 6, 5) == SUCCESS); 
    show_graph(g, "After removing edges (2,3), (2,5), (6,2), (6,5): "); 

    assert(remove_vertex(g, 3) == SUCCESS); 
    show_graph(g, "After removing vertex 3: "); 

    assert(destroy_graph(&g) == SUCCESS && g == NULL); 

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
    double w; 
}; 

int main(void) 
{
    graph_t* g = NULL; 
    vertex_t V[] = { 1, 2, 3, 4, 5, 6 }; 
    struct edge E[] = {
                        {2, 5, 2.3}, {1, 2, 2.3}, {1, 6, 3.1}, {2, 6, 0.5}, {2, 3, 4.3}, 
                        {3, 4, 6.3}, {3, 6, 2.6}, {3, 5, 0.9}, {4, 5, 1.1}, {5, 6, 2.21} 
                    }; 

    for(int i = 0; i < sizeof(V)/sizeof(V[0]); ++i) 
        assert(add_vertex(g, V[i]) == SUCCESS); 

    for(int i = 0; i < sizeof(E) / sizeof(E[0]); ++i) 
        assert(add_edge(g, E[i].v_start, E[i].v_end, E[i].w) == SUCCESS); 

    show_graph(g, "initial state: "); 

    assert(remove_edge(g, 2, 5) == SUCCESS); 
    assert(remove_edge(g, 2, 3) == SUCCESS); 
    assert(remove_edge(g, 6, 2) == SUCCESS); 
    assert(remove_edge(g, 6, 5) == SUCCESS); 
    show_graph(g, "After removing edges (2,5), (2,3), (6,2), (6,5): ");

    assert(remove_vertex(g, 3) == SUCCESS); 
    show_graph(g, "After removing vertex 3: "); 

    assert(destroy_graph(&g) == SUCCESS && g == NULL); 
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
    double w; 
}; 

int main(void) 
{
    graph_t* g = NULL; 
    vertex_t V[] = { 1, 2, 3, 4, 5, 6 }; 
    struct edge E[] = {
                        {1, 2, 2.1}, {1, 3, 2.3}, {1, 5, 1.0}, {2, 4, 0.8}, {2, 6, 0.5}, 
                        {3, 5, 0.7}, {3, 4, 0.2}, {4, 1, 0.8}, {5, 6, 1.0}, {6, 1, 1.5}                 
                    }; 

    g = create_graph(); 

    for(int i = 0; i < sizeof(V)/sizeof(V[0]); ++i) 
        assert(add_vertex(g, V[i]) == SUCCESS); 

    for(int i = 0; i < sizeof(E) / sizeof(E[0]); ++i) 
        assert(add_edge(g, E[i].v_start, E[i].v_end, E[i].w) == SUCCESS); 

    show_graph(g, "Initial state:"); 

    assert(remove_edge(g, 1, 2) == SUCCESS); 
    assert(remove_edge(g, 3, 5) == SUCCESS); 
    assert(remove_edge(g, 5, 6) == SUCCESS); 
    assert(remove_edge(g, 3, 4) == SUCCESS); 
    show_graph(g, "After removing edge (1,2), (3,5), (5,6), (3,4): "); 

    assert(remove_vertex(g, 6) == SUCCESS); 
    show_graph(g, "After removing vertex 6:"); 

    assert(destroy_graph(&g) == SUCCESS && g == NULL); 
    return (0); 
} 
