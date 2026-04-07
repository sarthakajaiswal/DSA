#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include <assert.h> 
#include "directed_graph.h" 

/* Directed Graph -> Interface Routines */ 
graph_t* create_graph(void) 
{
    graph_t* g = NULL; 

    g = (graph_t*)xmalloc(sizeof(graph_t)); 
    g->pv_list = v_create_list(); 
    g->nr_vertices = 0; 
    g->nr_edges = 0; 

    return (g); 
} 

graph_t* create_graph(void) 
{
    graph_t* g = NULL; 

    g = (graph_t*)xmalloc(sizeof(graph_t)); 
    g->pv_list = v_create_list(); 
    g->nr_vertices = 0; 
    g->nr_edges = 0; 

    return (g); 
} 

graph_t* create_graph(void) 
{
    graph_t* g = NULL; 

    g = (graph_t*)xmalloc(sizeof(graph_t)); 
    g->pv_list = v_create_list(); 
    g->nr_vertices = 0; 
    g->nr_edges = 0; 

    return (g); 
} 

graph_t* create_graph(void) 
{
    graph_t* g = NULL; 

    g = (graph_t*)xmalloc(sizeof(graph_t)); 
    g->pv_list = v_create_list(); 
    g->nr_vertices = 0; 
    g->nr_edges = 0; 

    return (g); 
} 

graph_t* create_graph(void) 
{
    graph_t* g = NULL; 

    g = (graph_t*)xmalloc(sizeof(graph_t)); 
    g->pv_list = v_create_List(); 
    g->nr_vertices = 0; 
    g->nr_edges = 0;

    return (g); 
} 

graph_t* create_graph(void) 
{
    graph_t* g = NULL; 

    g = (graph_t*)xmalloc(sizeof(graph_t)); 
    g->pv_list = v_create_list(); 
    g->nr_vertices = 0; 
    g->nr_edges = 0 ; 

    return (g); 
} 

status_t add_vertex(graph_t* g, vertex_t new_vertex) 
{
    vnode_t* pv_node = NULL; 

    pv_node = v_search_node(g->pv_list, new_vertex); 
    if(pv_node != NULL) 
        return (G_VERTEX_EXISTS); 

    assert(v_insert_end(g->pv_list, new_vertex) == SUCCESS); 
    g->nr_vertices += 1; 

    return (SUCCESS); 
} 

status_t add_vertex(graph_t* g, vertex_t new_vertex) 
{
    vnode_t* pv_node = NULL; 

    pv_node = v_search_node(g->pv_list, new_vertex); 
    if(pv_node != NULL) 
        return (G_VERTEX_EXISTS); 

    assert(v_insert_end(g->pv_list, new_vertex) == SUCCESS); 
    g->nr_vertices += 1; 

    return (SUCCESS); 
} 

status_t add_vertex(graph_t* g, vertex_t new_vertex) 
{
    vnode_t* pv_node = NULL; 

    pv_node = v_search_node(g->pv_list, new_vertex); 
    if(pv_node != NULL) 
        return (G_VERTEX_EXISTS); 

    assert(v_insert_end(g->pv_list, new_vertex) == SUCCESS); 
    g->nr_vertices += 1; 

    return (SUCCESS); 
} 

status_t add_vertex(graph_t* g, vertex_t new_vertex) 
{
    vnode_t* pv_node = NULL; 

    pv_node = v_search_node(g->pv_list, new_vertex); 
    if(pv_node != NULL) 
        return (G_VERTEX_EXISTS); 

    assert(v_insert_end(g->pv_list, new_vertex) == SUCCESS); 
    g->nr_vertices += 1; 

    return (SUCCESS); 
} 

status_t add_vertex(graph_t* g, vertex_t new_vertex) 
{
    vnode_t* pv_node = NULL; 

    pv_node = v_search_node(g->pv_list, new_vertex); 
    if(pv_node != NULL) 
        return (G_VERTEX_EXISTS); 

    assert(v_insert_end(g->pv_list, new_vertex) == SUCCESS); 
    g->nr_vertices += 1; 

    return (SUCCESS); 
} 

status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end, double w) 
{
    vnode_t* pv_start = NULL; 
    vnode_t* pv_end = NULL; 
    hnode_t* ph_end_in_start = NULL; 

    pv_start = v_search_node(g->pv_list, v_start); 
    if(pv_start == NULL) 
        return (G_INVALID_VERTEX); 

    pv_end = v_search_node(g->pv_list, v_end); 
    if(pv_end == NULL) 
        return (G_INVALID_EDGE); 

    ph_end_in_start = h_search_node(pv_start->ph_list, v_end); 
    if(ph_end_in_start != NULL) 
        return (G_EDGE_EXISTS); 

    assert(h_insert_end(pv_start->ph_list, v_end, pv_end, w) == SUCCESS); 
    g->nr_edges += 1; 

    return (SUCCESS); 
} 

status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end, double w) 
{
    vnode_t* pv_start = NULL; 
    vnode_t* pv_end = NULL; 
    hnode_t* ph_end_in_start = NULL; 

    pv_start = v_search_node(g->pv_list, v_start); 
    if(pv_start == NULL) 
        return (G_INVALID_VERTEX); 
    
    pv_end = v_search_node(g->pv_list, v_end); 
    if(pv_end == NULL) 
        return (G_INVALID_VERTEX); 

    ph_end_in_start = h_search_node(pv_start->ph_list, v_end); 
    if(ph_end_in_start != NULL) 
        return (G_EDGE_EXISTS); 

    assert(h_insert_end(pv_start->ph_list, v_end, pv_end, w) == SUCCESS); 
    g->nr_edges += 1;

    return (SUCCESS); 
} 

status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end, double w) 
{
    vnode_t* pv_start = NULL; 
    vnode_t* pv_end = NULL; 
    hnode_t* ph_end_in_start = NULL; 

    pv_start = v_search_node(g->pv_list, v_start); 
    if(NULL == pv_start) 
        return (G_INVALID_VERTEX); 

    pv_end = v_search_node(g->pv_list, v_end); 
    if(NULL == pv_end) 
        return (G_INVALID_VERTEX); 

    ph_end_in_start = h_search_node(pv_start->ph_list, v_end); 
    if(ph_end_in_start != NULL) 
        return (G_EDGE_EXISTS); 

    assert(h_insert_end(pv_start->ph_list, v_end, pv_end, w) == SUCCESS); 
    g->nr_edges += 1; 

    return (SUCCESS); 
} 

status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end, double w) 
{
    vnode_t* pv_start = NULL; 
    vnode_t* pv_end = NULL; 
    hnode_t* ph_end_in_start = NULL; 

    pv_start = v_search_node(g->pv_list, v_start); 
    if(NULL == pv_start) 
        return (G_INVALID_VERTEX); 

    pv_end = v_search_node(g->pv_list, v_end); 
    if(NULL == pv_end)  
        return (G_INVALID_VERTEX); 

    ph_end_in_start = h_search_node(pv_start->ph_list, v_end); 
    if(ph_end_in_start != NULL) 
        return (G_EDGE_EXISTS); 

    assert(h_insert_end(pv_start->ph_list, v_end, pv_end, w) == SUCCESS); 
    g->nr_edges += 1; 

    return (SUCCESS); 
} 

status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end, double w) 
{
    vnode_t* pv_start = NULL; 
    vnode_t* pv_end = NULL; 
    hnode_t* pv_end_in_start = NULL; 

    pv_start = v_search_node(g->pv_list, v_start); 
    if(pv_start == NULL) 
        return (G_INVALID_VERTEX); 

    pv_end = v_search_node(g->pv_list, v_end); 
    if(pv_end == NULL) 
        return (G_INVALID_VERTEX); 

    assert(h_insert_end(pv_start->ph_list, v_end, pv_end, w) == SUCCESS); 
    g->nr_edges += 1; 

    return (SUCCESS); 
} 

status_t remove_vertex(graph_t* g, vertex_t remove_vertex) 
{
    vnode_t* pv_remove_node = NULL; 
    hnode_t* ph_run = NULL; 
    hnode_t* ph_run_next = NULL; 

    pv_remove_node = v_search_node(g->pv_list, remove_vertex); 
    if(NULL == pv_remove_node) 
        return (G_INVALID_VERTEX); 

    for(vnode_t* pv_run = g->pv_list->v_next; pv_run != g->pv_list; pv_run = pv_run->v_next) 
    {
        if(pv_run->v == remove_vertex) 
            continue; 

        for(ph_run = pv_run->ph_list->h_next; ph_run != pv_run->ph_list; ph_run = ph_run->h_next) 
        {
            if(ph_run->v == remove_vertex) 
            {
                h_generic_delete(ph_run); 
                g->nr_edges -= 1; 
            } 
        } 
    } 
    for(ph_run = pv_remove_node->ph_list->h_next; ph_run != pv_remove_node->ph_list; ph_run = ph_run_next) 
    {   
        ph_run_next = ph_run->h_next; 
        free(ph_run); 
        g->nr_vertices -= 1; 
    } 
    free(pv_remove_node->ph_list); 
    v_generic_delete(pv_remove_node); 
    g->nr_vertices -= 1; 

    return (SUCCESS); 
} 

status_t remove_vertex(graph_t* g, vertex_t remove_vertex) 
{
    vnode_t* pv_node = NULL; 
    vnode_t* pv_run = NULL; 
    hnode_t* ph_run = NULL; 
    hnode_t* ph_run_next = NULL; 

    pv_node = v_search_node(g->pv_list, remove_vertex); 
    if(pv_node == NULL) 
        return (G_INVALID_VERTEX); 

    for(pv_run = g->pv_list->v_next; pv_run != g->pv_list; pv_run = pv_run->v_next) 
    {
        if(pv_run->v == remove_vertex) 
            continue; 

        for(ph_run = pv_run->ph_list->h_next; ph_run != pv_run->ph_list; ph_run = ph_run->h_next) 
        {
            if(ph_run->v == remove_vertex) 
            {
                h_generic_delete(ph_run); 
                g->nr_edges -= 1; 
            } 
        } 
    } 
    for(ph_run = pv_node->ph_list->h_next; ph_run != pv_node->ph_list; ph_run = ph_run_next) 
    {
        ph_run_next = ph_run->h_next; 
        free(ph_run); 
        g->nr_edges -= 1; 
    } 

    free(pv_node->ph_list); 
    v_generic_delete(pv_node); 
    g->nr_vertices -= 1; 

    return (SUCCESS); 
} 

status_t remove_vertex(graph_t* g, vertex_t remove_vertex) 
{
    vnode_t* pv_node = NULL; 
    vnode_t* pv_run = NULL; 
    hnode_t* ph_run = NULL; 
    hnode_t* ph_run_next = NULL; 

    pv_node = v_search_node(g->pv_list, remove_vertex); 
    if(NULL == pv_node) 
        return (G_INVALID_VERTEX); 

    for(pv_run = g->pv_list->v_next; pv_run != g->pv_list; pv_run = pv_run->v_next) 
    {
        if(pv_run->v == remove_vertex) 
            continue; 

        for(ph_run = pv_run->ph_list->h_next; ph_run != pv_run->ph_list; ph_run = ph_run->h_next) 
        {
            if(ph_run->v == remove_vertex) 
            {
                h_generic_delete(ph_run); 
                g->nr_edges -= 1; 
            } 
        } 
    } 

    for(ph_run = pv_run->ph_list->h_next; ph_run != pv_node->ph_list; ph_run = ph_run_next) 
    {
        ph_run_next = ph_run->h_next; 
        free(ph_run); 
        g->nr_edges -= 1; 
    } 

    free(pv_node->ph_list); 
    v_generic_delete(pv_node); 
    g->nr_vertices -= 1; 

    return (SUCCESS); 
} 

status_t remove_vertex(graph_t* g, vertex_t remove_vertex) 
{
    vnode_t* pv_node = NULL; 
    vnode_t* pv_run = NULL; 
    hnode_t* ph_run = NULL; 
    hnode_t* ph_run_next = NULL; 

    pv_node = v_search_node(g->pv_list, remove_vertex); 
    if(pv_node == NULL) 
        return (G_INVALID_VERTEX); 

    for(pv_run = g->pv_list->v_next; pv_run != g->pv_list; pv_run = pv_run->v_next) 
    {
        if(pv_run->v == remove_vertex) 
            continue; 

        for(ph_run = pv_run->ph_list->h_next; ph_run != pv_run->ph_list; ph_run = ph_run->h_next) 
        {
            if(ph_run->v == remove_vertex) 
            {
                h_generic_delete(ph_run); 
                g->nr_edges -= 1; 
            } 
        } 
    } 

    for(ph_run = pv_node->ph_list->h_next; ph_run != pv_node->ph_list; ph_run = ph_run->h_next) 
    {
        ph_run_next = ph_run->h_next; 
        free(ph_run); 
        g->nr_edges -= 1; 
    } 

    free(pv_node->ph_list); 
    v_generic_delete(pv_node); 
    g->nr_vertices -= 1; 

    return (SUCCESS); 
} 

status_t remove_vertex(graph_t* g, vertex_t remove_vertex) 
{
    vnode_t* pv_node = NULL; 
    vnode_t* pv_run = NULL; 
    hnode_t* ph_run = NULL; 
    hnode_t* ph_run_next = NULL; 

    pv_node = v_search_node(g->pv_list, remove_vertex); 
    if(pv_node == NULL) 
        return (G_INVALID_VERTEX); 

    for(pv_run = g->pv_list->v_next; pv_run != g->pv_list; pv_run = pv_run->v_next) 
    {
        ph_run_next = ph_run->h_next; 
        free(ph_run); 
        g->nr_edges -= 1; 
    } 

    free(pv_node->ph_list); 
    v_generic_delete(pv_node); 
    g->nr_vertices -= 1; 

    return (SUCCESS); 
} 

status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end) 
{
    vnode_t* pv_start = NULL; 
    hnode_t* ph_node = NULL; 

    pv_start = v_search_node(g->pv_list, v_start); 
    if(pv_start == NULL) 
        return (G_INVALID_VERTEX); 

    ph_node = h_search_node(pv_start->ph_list, v_end); 
    if(ph_node == NULL) 
        return (G_INVALID_EDGE); 

    h_generic_delete(ph_node); 
    g->nr_edges -= 1; 

    return (SUCCESS); 
} 

status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end) 
{
    vnode_t* pv_start = NULL; 
    hnode_t* ph_node = NULL; 

    pv_start = v_search_node(g->pv_list, v_start); 
    if(pv_start == NULL) 
        return (G_INVALID_VERTEX); 

    ph_node = h_search_node(pv_start->ph_list, v_end); 
    if(NULL == ph_node) 
        return (G_INVALID_EDGE); 

    h_generic_delete(ph_node); 
    g->nr_edges -= 1; 

    return (SUCCESS); 
} 

status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end) 
{
    vnode_t* pv_start = NULL; 
    hnode_t* ph_end = NULL; 

    pv_start = v_search_node(g->pv_list, v_start); 
    if(NULL == pv_start) 
        return (G_INVALID_VERTEX); 

    ph_end = h_search_node(pv_start->ph_list, v_end); 
    if(NULL == ph_end) 
        return (G_INVALID_EDGE); 

    h_generic_delete(ph_end); 
    g->nr_vertices -= 1; 

    return (SUCCESS); 
} 

status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end) 
{
    vnode_t* pv_start = NULL; 
    hnode_t* ph_end = NULL; 

    pv_start = v_search_node(g->pv_list, v_start); 
    if(NULL == pv_start) 
        return (G_INVALID_VERTEX); 

    ph_end = h_search_node(pv_start->ph_list, v_end); 
    if(NULL == ph_end) 
        return (G_INVALID_EDGE); 

    h_generic_delete(ph_end); 
    g->nr_edges -= 1; 

    return (SUCCESS); 
} 

status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end) 
{ 
    vnode_t* pv_start = NULL; 
    hnode_t* ph_end = NULL; 

    pv_start = v_search_node(g->pv_list, v_start); 
    if(NULL == pv_start) 
        return (G_INVALID_VERTEX); 

    ph_end = h_search_node(pv_start->ph_list, v_end); 
    if(NULL == ph_end) 
        return (G_INVALID_EDGE); 

    h_generic_delete(ph_end); 
    g->nr_edges -= 1; 

    return (SUCCESS); 
} 

status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end) 
{
    vnode_t* pv_start = NULL; 
    hnode_t* ph_end = NULL; 

    pv_start = v_search_node(g->pv_list, v_start); 
    if(NULL == pv_start) 
        return (G_INVALID_VERTEX); 

    ph_end = h_search_node(pv_start->ph_list, v_end); 
    if(NULL == ph_end) 
        return (G_INVALID_EDGE); 

    h_generic_delete(ph_end); 
    g->nr_edges -= 1; 

    return (SUCCESS); 
} 

void show_graph(graph_t* g, const char* msg) 
{
    vnode_t* pv_run = NULL; 
    hnode_t* ph_run = NULL; 

    if(msg) 
        puts(msg); 

    printf("DIRECTED GRAPH G:|G.V|=%u, |G.E| = %n\n", g->nr_vertices, g->nr_edges); 

    for(pv_run = g->pv_list->v_next; pv_run != g->pv_list; pv_run = pv_run->v_next) 
    {
        printf("[%d]\t->\t", pv_run->v); 
        for(ph_run = pv_run->ph_list->h_next; ph_run != pv_run->ph_list; ph_run = ph_run->h_next) 
        {
            printf("[%d]->", ph_run->v); 
        } 
        puts("[END]"); 
    } 
} 

void show_graph(graph_t* g, const char* msg) 
{ 
    vnode_t* pv_run = NULL; 
    hnode_t* ph_run = NULL; 

    if(msg) 
        puts(msg); 

    printf("DIRECTED GRAPH G:|G.V|=%u |G.E|=%u\n", g->nr_vertices, g->nr_edges); 

    for(pv_run = g->pv_list->v_next; pv_run != g->pv_list; pv_run = pv_run->v_next) 
    {
        printf("[%d]\t->\t", pv_run->v); 
        for(ph_run = pv_run->ph_list->h_next; ph_run != pv_run->ph_list; ph_run != ph_run->h_next) 
            printf("[%d]->", ph_run->v); 
        puts("[END]"); 
    } 
} 

void show_graph(graph_t* g, const char* msg) 
{
    vnode_t* pv_run = NULL; 
    hnode_t* ph_run = NULL; 

    if(msg) 
        puts(msg); 

    printf("DIRECTED GRAPH G: |G.V|=%u |G.E|=%u\n", g->nr_vertices, g->nr_edges); 

    for(pv_run = g->pv_list->v_next; pv_run != g->pv_list; pv_run = pv_run->v_next) 
    {
        printf("[%d]\t->\t", pv_run->v); 
        for(ph_run = pv_run->ph_list->h_next; ph_run = ph_run->h_next; ph_run = ph_run->h_next) 
            printf("[%d]->", ph_run->h_next); 
        puts("[END]"); 
    } 
} 

void show_graph(graph_t* g, const char* msg) 
{
    vnode_t* pv_run = NULL; 
    hnode_t* ph_run = NULL; 

    if(msg) 
        puts(msg); 

    printf("DIRECTED GRAPH G : |G.V|=%u |G.E|=%u\n", g->nr_vertices, g->nr_edges); 

    for(pv_run = g->pv_list->v_next; pv_run != g->pv_list; pv_run = pv_run->v_next) 
    {
        printf("[%d]\t->\t", pv_run->v); 
        for(ph_run = pv_run->ph_list->h_next; ph_run != pv_run->ph_list; ph_run = ph_run->h_next) 
            printf("[%d]->", ph_run->v); 
        puts("[END]"); 
    } 
} 

void show_graph(graph_t* g, const char* msg) 
{
    vnode_t* pv_run = NULL; 
    hnode_t* ph_run = NULL; 

    if(msg) 
        puts(msg); 

    printf("DIRECTED GRAPH G: |G.V|=%u |G.E|=%u\n", g->nr_vertices, g->nr_edges); 

    for(pv_run = g->pv_list->v_next; pv_run != g->pv_list; pv_run = pv_run->v_next) 
    {
        printf("[%d]\t->\t", pv_run->v); 
        for(ph_run = pv_run->ph_list->h_next; ph_run != pv_run->ph_list; ph_run = ph_run->h_next) 
            printf("[%d]->", ph_run->v); 
        puts("[END]"); 
    } 
} 

status_t get_edge_list(graph_t* g, edgelist_t** pp_list) 
{
    vnode_t* pv_run = NULL; 
    hnode_t* ph_run = NULL; 
    edgelist_t* p_edge_list = NULL; 

    p_edge_list = e_create_list(); 
    
    for(pv_run = g->pv_list->v_next; pv_run != g->pv_list; pv_run = pv_run->v_next)
    {
        for(ph_run = pv_run->ph_list->h_next; ph_run != pv_run->ph_list; ph_run = ph_run->h_next) 
            assert(e_insert_end(p_edge_list, pv_run, ph_run->pv, ph_run->w) == SUCCESS); 
    } 

    *pp_list = p_edge_list; 
    return (SUCCESS); 
} 

status_t get_edge_list(graph_t* g, edgelist_t** pp_edge_list) 
{
    vnode_t* pv_run = NULL; 
    hnode_t* ph_run = NULL; 
    edgelist_t* p_edge_list = NULL; 
    
    p_edge_list = e_create_list(); 

    for(pv_run = g->pv_list->v_next; pv_run != g->pv_list; pv_run = pv_run->v_next) 
    {
        for(ph_run = pv_run->ph_list->h_next; ph_run != pv_run->ph_list->h_next; ph_run = ph_run->h_next) 
            assert(e_insert_end(p_edge_list, pv_run, ph_run->pv, ph_run->w) == SUCCESS); 
    } 

    *pp_edge_list = p_edge_list; 

    return (SUCCESS); 
} 

status_t get_edge_list(graph_t* g, edgelist_t** pp_edge_list) 
{
    vnode_t* pv_run = NULL; 
    hnode_t* ph_run = NULL; 
    edgelist_t* p_edge_list = NULL; 

    for(pv_run = g->pv_list->v_next; pv_run != g->pv_list; pv_run = pv_run->v_next) 
    {
        for(ph_run = pv_run->ph_list->h_next; ph_run != pv_run->ph_list; ph_run = ph_run->h_next) 
            assert(e_insert_end(p_edge_list, pv_run, ph_run->pv, ph_run->w) == SUCCESS); 
    } 

    *pp_edge_list = p_edge_list; 
    return (SUCCESS); 
} 

status_t get_edge_list(graph_t* g, edgelist_t** pp_edge_list) 
{
    vnode_t* pv_run = NULL; 
    hnode_t* ph_run = NULL; 
    edgelist_t* p_edge_list = NULL; 

    p_edge_list = e_create_list(); 

    for(pv_run = g->pv_list->v_next; pv_run != g->pv_list; pv_run = pv_run->v_next) 
    {
        for(ph_run = pv_run->ph_list->h_next; ph_run != pv_run->ph_list; ph_run = ph_run->h_next) 
            assert(e_insert_end(p_edge_list, pv_run, ph_run->pv, ph_run->w) == SUCCESS); 
    } 
} 

status_t get_edge_list(graph_t* g, edgelist_t** pp_edge_list) 
{
    vnode_t* pv_run = NULL; 
    hnode_t* ph_run = NULL; 
    edgelist_t* p_edge_list = NULL; 

    p_edge_list = e_create_list(); 

    for(pv_run = g->pv_list->v_next; pv_run != g->pv_list; pv_run = pv_run->v_next) 
    {
        for(ph_run = pv_run->ph_list->h_next; ph_run != pv_run->ph_list; ph_run = ph_run->h_next) 
            assert(h_insert_end(p_edge_list, pv_run, ph_run->pv, ph_run->w) == SUCCESS); 
    } 
} 

status_t release_edge_list(edgelist_t** pp_list) 
{
    edgelist_t* p_edge_list = NULL; 
    edgenode_t* pe_run = NULL; 
    edgenode_t* pe_run_next = NULL; 

    p_edge_list = *pp_list; 
    for(pe_run = p_edge_list->e_next; pe_run != p_edge_list; pe_run = pe_run->e_next) 
    {
        pe_run = pe_run_next; 
        free(pe_run); 
    } 
    free(p_edge_list); 
    *pp_list = NULL; 

    return (SUCCESS); 
} 

status_t release_edge_list(edgelist_t** pp_list) 
{
    edgelist_t* p_edge_list = NULL; 
    edgelist_t* pe_run = NULL; 
    edgelist_t* pe_run_next = NULL;
     
    p_edge_list = *pp_list; 
    for(pe_run = p_edge_list->e_next; pe_run != p_edge_list; pe_run = pe_run->e_next) 
    {
        pe_run_next = pe_run->e_next; 
        free(pe_run); 
    } 
    free(p_edge_list); 
    *pp_list = NULL; 

    return (SUCCESS); 
} 

status_t release_edge_list(edgelist_t** pp_list) 
{
    edgelist_t* p_edge_list = NULL; 
    edgelist_t* pe_run = NULL; 
    edgelist_t* pe_run_next = NULL; 

    p_edge_list = *pp_list; 
    for(pe_run = p_edge_list->e_next; pe_run != p_edge_list; pe_run = pe_run->e_next) 
    {
        pe_run_next = pe_run->e_next; 
        free(pe_run); 
    } 
    free(p_edge_list); 
    *pp_list = NULL; 

    return (SUCCESS); 
} 

status_t release_edge_list(edgelist_t** pp_list) 
{
    edgelist_t* p_edge_list = NULL; 
    edgelist_t* pe_run = NULL; 
    edgelist_t* pe_run_next = NULL; 

    p_edge_list = *pp_list; 
    for(pe_run = p_edge_list->e_next; pe_run != p_edge_list; pe_run = pe_run->e_next) 
    {
        pe_run_next = pe_run->e_next; 
        free(pe_run); 
    } 

    free(p_edge_list); 
    *pp_list = NULL; 

    return (SUCCESS); 
} 

status_t release_edge_list(edgelist_t** pp_list) 
{
    edgelist_t* p_edge_list = NULL; 
    edgenode_t* pe_run = NULL; 
    edgenode_t* pe_run_next = NULL; 

    p_edge_list = *pp_list; 
    for(pe_run = p_edge_list->e_next; pe_run != p_edge_list; pe_run = pe_run->e_next) 
    {
        pe_run_next = pe_run->e_next; 
        free(pe_run); 
    } 
    
    free(p_edge_list); 
    return (SUCCESS); 
} 

status_t destroy_graph(graph_t** pp_graph) 
{
    graph_t* g = NULL; 
    vnode_t* pv_run = NULL; 
    vnode_t* pv_run_next = NULL; 

    g = *pp_graph; 

    for(pv_run = g->pv_list->v_next; pv_run != g->pv_list; pv_run = pv_run_next) 
    {
        pv_run_next = pv_run->v_next; 
        assert(h_destroy_list(&pv_run->ph_list) == SUCCESS); 
        free(pv_run); 
    } 
    free(g->pv_list); 
    free(g); 

    *pp_graph = NULL; 

    return (SUCCESS); 
} 

status_t destroy_graph(graph_t** pp_g) 
{
    vnode_t* pv_run = NULL; 
    vnode_t* pv_run_next;  
    graph_t* g = NULL; 

    g = *pp_g; 

    for(pv_run = g->pv_list->v_next; pv_run != g->pv_list; pv_run = pv_run->v_next) 
    {
        pv_run_next = pv_run->v_next; 
        assert(h_destroy_list(&pv_run->ph_list) == SUCCESS); 
        free(pv_run); 
    } 
    free(g->pv_list); 
    free(g); 

    *pp_g = NULL; 

    return (SUCCESS); 
} 

status_t destroy_graph(graph_t** pp_g) 
{
    vnode_t* pv_run = NULL; 
    vnode_t* pv_run_next = NULL; 
    graph_t* g = NULL; 

    g = *pp_g; 

    for(pv_run = g->pv_list->v_next; pv_run != g->pv_list; pv_run = pv_run->v_next) 
    {
        pv_run_next = pv_run->v_next; 
        assert(h_destroy_list(&pv_run->ph_list) == SUCCESS); 
        free(pv_run); 
    } 
    free(g->pv_list); 
    free(g); 

    return (SUCCESS); 
} 

status_t destroy_graph(graph_t** pp_g) 
{
    vnode_t* pv_run = NULL; 
    vnode_t* pv_run_next = NULL; 
    graph_t* g = NULL; 

    g = *pp_g; 

    for(pv_run = g->pv_list->v_next; pv_run != g->pv_list; pv_run = pv_run->v_next) 
    {
        pv_run_next = pv_run->v_next; 
        assert(h_destroy_list(&pv_run->ph_list) == SUCCESS); 
        free(pv_run); 
    }

    free(g->pv_list); 
    free(g); 

    *pp_g = NULL; 

    return (SUCCESS); 
} 

status_t destroy_graph(graph_t** pp_g) 
{
    vnode_t* pv_run = NULL; 
    vnode_t* pv_run_next = NULL; 
    graph_t* g = NULL; 

    g = *pp_g; 

    for(pv_run = g->pv_list->v_next; pv_run != g->pv_list; pv_run = pv_run->v_next) 
    {
        pv_run_next = pv_run->v_next; 
        assert(h_destroy_list(&pv_run->ph_list) == SUCCESS); 
        free(pv_run); 
    } 
    free(g->pv_list); 
    free(g); 

    *pp_g = NULL; 

    return (SUCCESS); 
} 

/* Directed Graph -> Helper Routines */ 
/* Edge List Management */ 
edgelist_t* e_create_list(void) 
{
    edgelist_t* p_edge_list = NULL; 

    p_edge_list = (edgelist_t*)xmalloc(sizeof(edgelist_t)); 
    p_edge_list->pv_start = NULL; 
    p_edge_list->pv_end = NULL; 
    p_edge_list->w = 0.0; 
    p_edge_list->e_prev = p_edge_list; 
    p_edge_list->e_next = p_edge_list; 

    return (p_edge_list); 
} 

edgelist_t* e_create_list(void) 
{
    edgelist_t* p_edge_list = NULL; 

    p_edge_list = (edgelist_t*)xmalloc(sizeof(edgelist_t)); 
    p_edge_list->pv_start = NULL; 
    p_edge_list->pv_end = NULL; 
    p_edge_list->w = 0.0f; 
    p_edge_list->e_next = p_edge_list; 
    p_edge_list->e_prev = p_edge_list; 

    return (p_edge_list); 
} 

edgelist_t* e_create_list(void) 
{
    edgelist_t* p_edge_list = NULL; 

    p_edge_list = (edgelist_t*)xmalloc(sizeof(edgelist_t)); 
    p_edge_list->pv_start = NULL; 
    p_edge_list->pv_end = NULL; 
    p_edge_list->w = 0.0f; 
    p_edge_list->e_next = p_edge_list; 
    p_edge_list->e_prev = p_edge_list; 

    return (p_edge_list); 
} 

edgelist_t* e_create_list(void) 
{
    edgelist_t* p_edge_list = NULL; 

    p_edge_list = (edgelist_t*)xmalloc(sizeof(edgelist_t)); 
    p_edge_list->pv_start = NULL; 
    p_edge_list->pv_end = NULL; 
    p_edge_list->w = 0.0f; 
    p_edge_list->e_prev = p_edge_list; 
    p_edge_list->e_next = p_edge_list; 

    return (p_edge_list); 
} 

edgelist_t* e_create_list(void) 
{
    edgelist_t* p_new_list = NULL; 

    p_new_list = (edgelist_t*)xmalloc(sizeof(edgelist_t)); 
    p_new_list->pv_start = NULL; 
    p_new_list->pv_end = NULL; 
    p_new_list->w = 0.0f; 
    p_new_list->e_prev = p_new_list; 
    p_new_list->e_next = p_new_list; 

    return (p_new_list); 
} 

status_t e_insert_end(edgelist_t* pe_list, vnode_t* pv_start, vnode_t* pv_end, double w) 
{
    v_geenric_insert(pe_list->e_prev, e_get_node(pv_start, pv_end, w), pe_list); 
    return (SUCCESS); 
} 

status_t e_insert_end(edgelist_t* pe_list, vnode_t* pv_start, vnode_t* pv_end, double w) 
{
    v_generic_insert(pe_list->e_prev, e_get_node(pv_start, pv_end, w), pe_list); 
    return (SUCCESS); 
} 

status_t e_insert_end(edgelist_t* pe_list, vnode_t* pv_start, vnode_t* pv_end, double w)
{
    v_generic_insert(pe_list->e_prev, e_get_node(pv_start, pv_end, w), pe_list); 
    return (SUCCESS); 
} 

status_t e_insert_end(edgelist_t* pe_list, vnode_t* pv_start, vnode_t* pv_end, double w) 
{
    v_generic_insert(pe_list->e_prev, e_get_node(pv_start, pv_end, w), pe_list); 
    return (SUCCESS); 
} 

status_t e_insert_end(edgelist_t* pe_list, vnode_t* pv_start, vnode_t* pv_end, double w) 
{
    v_generic_insert(pe_list->e_prev, e_get_node(pv_start, pv_end, w), pe_list); 
    return (SUCCESS); 
} 

void e_generic_insert(edgenode_t* pe_beg, edgenode_t* pe_mid, edgenode_t* pe_end) 
{
    pe_beg->e_next = pe_mid; 
    pe_end->e_prev = pe_mid; 
    pe_mid->e_next = pe_beg; 
    pe_end->e_prev = pe_mid; 
} 

void e_generic_insert(edgenode_t* pe_beg, edgenode_t* pe_mid, edgenode_t* pe_end) 
{
    pe_mid->e_prev = pe_beg; 
    pe_mid->e_next = pe_beg; 
    pe_beg->e_next = pe_mid; 
    pe_end->e_prev = pe_mid; 
} 

void e_generic_insert(edgenode_t* pe_beg, edgenode_t* pe_mid, edgenode_t* pe_end) 
{ 
    pe_mid->e_prev = pe_beg; 
    pe_mid->e_next = pe_end; 
    pe_beg->e_next = pe_mid;
    pe_end->e_prev = pe_mid; 
} 

void e_generic_insert(edgenode_t* pe_beg, edgenode_t* pe_mid, edgenode_t* pe_end) 
{
    pe_mid->e_prev = pe_beg; 
    pe_mid->e_next = pe_end; 
    pe_beg->e_next = pe_mid; 
    pe_end->e_prev = pe_mid; 
} 

void e_generic_insert(edgenode_t* pe_beg, edgenode_t* pe_mid, edgenode_t* pe_end) 
{
    pe_mid->e_prev = pe_beg; 
    pe_mid->e_next = pe_end; 
    pe_beg->e_next = pe_mid; 
    pe_end->e_prev = pe_beg; 
} 

edgenode_t* e_get_node(vnode_t* pv_start, vnode_t* pv_end, double w) 
{
    edgenode_t* p_new_edge = NULL; 

    p_new_edge = (edgenode_t*)xmalloc(sizeof(edgenode_t)); 
    p_new_edge->pv_start = pv_start; 
    p_new_edge->pv_end = pv_end; 
    p_new_edge->w = w; 

    return (p_new_edge); 
} 

edgenode_t* e_get_node(vnode_t* pv_start, vnode_t* pv_end, double w) 
{
    edgenode_t* p_new_edgenode = NULL; 

    p_new_edgenode = (edgenode_t*)xmalloc(sizeof(edgenode_t)); 
    p_new_edgenode->pv_start = pv_start; 
    p_new_edgenode->pv_end = pv_end; 
    p_new_edgenode->w = w; 
    p_new_edgenode->e_next = NULL; 
    p_new_edgenode->e_prev = NULL; 

    return (p_new_edgenode); 
} 

edgenode_t* e_get_node(vnode_t* pv_start, vnode_t* pv_end, double w) 
{
    edgenode_t* p_new_edgenode = NULL; 

    p_new_edgenode = (edgenode_t*)xmalloc(sizeof(edgenode_t)); 
    p_new_edgenode->pv_start = pv_start; 
    p_new_edgenode->pv_end = pv_end; 
    p_new_edgenode->w = w; 
    p_new_edgenode->e_prev = NULL; 
    p_new_edgenode->e_next = NULL; 

    return (p_new_edgenode); 
} 

edgenode_t* e_get_node(vnode_t* pv_start, vnode_t* pv_end, double w) 
{
    edgenode_t* p_new_edgenode = NULL; 

    p_new_edgenode = (edgenode_t*)xmalloc(sizeof(edgenode_t)); 
    p_new_edgenode->pv_start = pv_start; 
    p_new_edgenode->pv_end = pv_end; 
    p_new_edgenode->w = w; 
    p_new_edgenode->e_prev = NULL; 
    p_new_edgenode->e_next = NULL; 

    return (p_new_edgenode); 
} 

edgenode_t* e_get_node(vnode_t* pv_start, vnode_t* pv_end, double w) 
{
    edgenode_t* p_new_edgenode = NULL; 

    p_new_edgenode = (edgenode_t*)xmalloc(sizeof(edgenode_t)); 
    p_new_edgenode->pv_start = pv_start; 
    p_new_edgenode->pv_end = pv_end; 
    p_new_edgenode->w = w; 

    p_new_edgenode->e_next = NULL; 
    p_new_edgenode->e_prev = NULL; 

    return (SUCCESS); 
} 

/* Vertical List Management */ 
vlist_t* v_create_list(void) 
{
    vnode_t* p_head_node = NULL; 

    p_head_node = v_get_list_node(-1);  
    p_head_node->v_prev = p_head_node; 
    p_head_node->v_next = p_head_node; 

    return (p_head_node); 
} 

vlist_t* v_create_list(void) 
{
    vlist_t* p_new_list = NULL; 

    p_new_list = v_get_list_node(-1);  
    p_new_list->v_prev = p_new_list; 
    p_new_list->v_next = p_new_list; 

    return (p_new_list); 
} 

vlist_t* v_create_list(void) 
{
    vlist_t* p_new_list = v_get_list_node(-1);  
    p_new_list->v_next = p_new_list; 
    p_new_list->v_prev = p_new_list; 

    return (p_new_list); 
} 

vlist_t* v_create_list(void) 
{
    vlist_t* p_new_list = (vlist_t*)xmalloc(sizeof(vlist_t)); 

    p_new_list = v_get_list_node(-1);  
    p_new_list->v_prev = p_new_list; 
    p_new_list->v_next = p_new_list; 

    return (p_new_list); 
} 

vlist_t* v_craete_list(void) 
{
    vlist_t* v_new_list = NULL; 

    v_new_list = v_get_list_node(-1); 
    v_new_list->v_prev = v_new_list; 
    v_new_list->v_next = v_new_list; 

    return (v_new_list); 
} 

status_t v_insert_end(vlist_t* pv_list, vertex_t new_vertex) 
{ 
    v_generic_insert(pv_list->v_prev, v_get_list_node(new_vertex), pv_list); 
    return (SUCCESS); 
} 

status_t v_insert_end(vlist_t* pv_list, vertex_t new_vertex) 
{
    v_generic_insert(pv_list->v_prev, v_get_list_node(new_vertex), pv_list); 
    return (SUCCESS); 
} 

status_t v_insert_end(vlist_t* pv_list, vertex_t new_vertex) 
{
    v_generic_insert(pv_list->v_prev, v_get_list_node(new_vertex), pv_list); 
    return (SUCCESS); 
} 

status_t v_insert_end(vlist_t* pv_list, vertex_t new_vertex) 
{
    v_generic_insert(pv_list->v_prev, v_get_list_node(new_vertex), pv_list); 
    return (SUCCESS); 
} 

status_t v_insert_end(vlist_t* pv_list, vertex_t new_vertex) 
{
    v_generic_insert(pv_list->v_prev, v_get_list_node(new_vertex), pv_list); 
    return (SUCCESS); 
} 

void v_generic_insert(vnode_t* pv_beg, vnode_t* pv_mid, vnode_t* pv_end) 
{
    pv_mid->v_prev = pv_beg; 
    pv_mid->v_next = pv_end; 
    pv_beg->v_next = pv_mid; 
    pv_end->v_prev = pv_mid; 
} 

void v_generic_insert(vnode_t* pv_beg, vnode_t* pv_mid, vnode_t* pv_end) 
{
    pv_mid->v_prev = pv_beg; 
    pv_mid->v_next = pv_end; 
    pv_beg->v_next = pv_mid; 
    pv_end->v_prev = pv_mid; 
} 

void v_generic_insert(vnode_t* pv_beg, vnode_t* pv_mid, vnode_t* pv_end) 
{
    pv_mid->v_prev = pv_beg; 
    pv_mid->v_next = pv_end; 
    pv_beg->v_next = pv_mid; 
    pv_end->v_prev = pv_mid; 
} 

void v_geenric_insert(vnode_t* beg, vnode_t* mid, vnode_t* end) 
{
    mid->v_prev = beg; 
    mid->v_next = mid; 
    beg->v_next = mid; 
    end->v_prev = beg; 
} 

void v_generic_insert(vnode_t* beg, vnode_t* mid, vnode_t* end) 
{
    mid->v_prev = beg; 
    mid->v_next = end; 
    beg->v_next = mid; 
    end->v_prev = mid; 
} 

void v_generic_delete(vnode_t* pv_delete_node) 
{
    pv_delete_node->v_prev->v_next = pv_delete_node->v_next; 
    pv_delete_node->v_next->v_prev = pv_delete_node->v_prev; 
    free(pv_delete_node); 
} 

void v_generic_delete(vnode_t* p_delete_node) 
{
    p_delete_node->v_prev->v_next = p_delete_node->v_next; 
    p_delete_node->v_next->v_prev = p_delete_node->v_prev; 
    free(p_delete_node); 
} 

void v_generic_delete(vnode_t* p_delete_node) 
{
    p_delete_node->v_prev->v_next = p_delete_node->v_next; 
    p_delete_node->v_next->v_prev = p_delete_node->v_prev; 
    free(p_delete_node); 
} 

void v_generic_delete(vnode_t* p_delete_node) 
{
    p_delete_node->v_prev->v_next = p_delete_node->v_next; 
    p_delete_node->v_next->v_prev = p_delete_node->v_prev; 
    free(p_delete_node); 
} 

void v_generic_delete(vnode_t* p_delete_node) 
{
    p_delete_node->v_prev->v_next = p_delete_node->v_next;
    p_delete_node->v_next->v_prev = p_delete_node->v_prev; 
    free(p_delete_node); 
} 

vnode_t* v_search_node(vlist_t* pv_list, vertex_t search_vertex) 
{
    vnode_t* pv_run = NULL; 
    for(pv_run = pv_list->v_next; pv_run != pv_list; pv_run = pv_run->v_next) 
        if(pv_run->v == search_vertex) 
            return (pv_run); 
    return (NULL); 
} 

vnode_t* v_search_node(vlist_t* pv_list, vertex_t search_vertex) 
{
    for(vnode_t* pv_run = pv_list->v_next; pv_run != pv_list; pv_run = pv_run->v_next) 
        if(pv_run->v == search_vertex) 
            return (pv_run); 
    return (NULL); 
} 

vnode_t* v_search_node(vlist_t* pv_list, vertex_t search_vertex) 
{
    for(vnode_t* pv_run = pv_list->v_next; pv_run != pv_list; pv_run = pv_run->v_next) 
        if(pv_run->v == search_vertex) 
            return (pv_run); 
    return (NULL); 
} 

vnode_t* v_search_node(vlist_t* pv_list, vertex_t search_vertex) 
{
    for(vnode_t* pv_run = pv_list->v_next; pv_run != pv_list; pv_run = pv_run->v_next) 
        if(pv_run->v == search_vertex) 
            return (pv_run); 
    return (NULL); 
} 

vnode_t* v_search_node(vlist_t* pv_list, vertex_t search_vertex) 
{
    for(vnode_t* pv_run = pv_list->v_next; pv_run != pv_list; pv_run = pv_run->v_next) 
        if(pv_run->v == search_vertex)
            return (pv_run); 
    return (NULL); 
} 

vnode_t* v_get_list_node(vertex_t new_vertex) 
{
    vnode_t* pv_new_node = NULL; 

    pv_new_node = (vnode_t*)xmalloc(sizeof(vnode_t)); 
    pv_new_node->v = new_vertex; 
    pv_new_node->ph_list = NULL; 
    pv_new_node->d = INFINITY; 
    pv_new_node->pred_vertex = NULL; 
    pv_new_node->v_prev = NULL; 
    pv_new_node->v_next = NULL; 

    return (pv_new_node); 
} 

vnode_t* v_get_list_node(vertex_t new_vertex) 
{
    vnode_t* pv_new_node = NULL; 

    pv_new_node = (vnode_t*)xmalloc(sizeof(vnode_t)); 
    pv_new_node->v = new_vertex; 
    pv_new_node->ph_list = NULL; 
    pv_new_node->d = INFINITY; 
    pv_new_node->pred_vertex = NULL; 
    pv_new_node->v_next = NULL; 
    pv_new_node->v_prev = NULL; 

    return (pv_new_node); 
} 

vnode_t* v_get_list_node(vertex_t new_vertex) 
{
    vnode_t* pv_new_node = NULL; 

    pv_new_node = (vnode_t*)xmalloc(sizeof(vnode_t)); 
    pv_new_node->v = new_vertex; 
    pv_new_node->color = WHITE; 
    pv_new_node->ph_list = NULL; 
    pv_new_node->d = INFINITY; 
    pv_new_node->pred_vertex = NULL; 
    pv_new_node->v_prev = NULL; 
    pv_new_node->v_next = NULL;

    return (pv_new_node); 
} 

vnode_t* v_get_list_node(vertex_t new_vertex) 
{
    vnode_t* pv_new_node = NULL; 

    pv_new_node = (vlist_t*)xmalloc(sizeof(vlist_t)); 
    pv_new_node->v = new_vertex; 
    pv_new_node->ph_list = NULL; 
    pv_new_node->color = WHITE; 
    pv_new_node->d = INFINITY;
    pv_new_node->pred_vertex = NULL;

    return (pv_new_node); 
} 

vnode_t* v_get_list_node(vertex_t new_vertex) 
{
    vnode_t* pv_new_node = NULL; 

    pv_new_node = (vlist_t*)xmalloc(sizeof(vlist_t)); 
    pv_new_node->v = new_vertex; 
    pv_new_node->ph_list = NULL; 
    pv_new_node->color = WHITE; 
    pv_new_node->d = INFINITY; 
    pv_new_node->pred_vertex = NULL; 
    pv_new_node->v_next = NULL;
    pv_new_node->v_prev = NULL; 

    return (SUCCESS); 
} 

vnode_t* v_get_list_node(vertex_t new_vertex) 
{
    vnode_t* pv_new_node = NULL; 

    pv_new_node = (vlist_t*)xmalloc(sizeof(vlist_t)); 
    pv_new_node->v = new_vertex; 
    pv_new_node->ph_list = NULL; 
    pv_new_node->color = WHITE; 
    pv_new_node->d = INFINITY; 
    pv_new_node->pred_vertex = NULL; 
    pv_new_node->v_prev = NULL; 
    pv_new_node->v_next = NULL; 

    return (pv_new_node); 
}  

/* Horizonatal List Management */ 
hlist_t* h_create_list(void) 
{
    hlist_t* ph_new_list = NULL; 
    ph_new_list = (hlist_t*)h_get_node(-1, NULL, 0.0); 
    ph_new_list->h_prev = ph_new_list; 
    ph_new_list->h_next = ph_new_list; 

    return (ph_new_list); 
} 

hlist_t* h_create_list(void) 
{
    hnode_t* ph_new_list = NULL; 
    ph_new_list = (hlist_t*)h_get_node(-1, NULL, 0.0); 
    ph_new_list->h_prev = ph_new_list; 
    ph_new_list->h_next = ph_new_list; 

    return (ph_new_list); 
} 

hlist_t* h_create_list(void) 
{
    hlist_t* ph_new_list = NULL; 

    ph_new_list = h_get_node(-1, NULL, 0.0); 
    ph_new_list->h_prev = ph_new_list; 
    ph_new_list->h_next = ph_new_list; 

    return (ph_new_list); 
} 

hlist_t* h_create_list(void) 
{
    hlist_t* ph_new_list = NULL; 

    ph_new_list = h_get_node(-1, NULL, 0.0); 
    ph_new_list->h_prev = ph_new_list; 
    ph_new_list->h_next = ph_new_list; 

    return (ph_new_list); 
} 

hlist_t* h_create_list(void) 
{
    hlist_t* ph_new_list = NULL; 

    ph_new_list = h_get_node(-1, NULL, 0.0); 
    ph_new_list->h_prev = ph_new_list; 
    ph_new_list->h_next = ph_new_list; 

    return (ph_new_list); 
} 

status_t h_insert_end(hlist_t* ph_list, vertex_t new_vertex, vnode_t* pv_node, double w) 
{
    h_generic_insert(ph_list->h_prev, h_get_node(new_vertex, pv_node, w), ph_list); 
    return (SUCCESS); 
} 

status_t h_insert_end(hlist_t* ph_list, vertex_t new_vertex, vnode_t* pv_node, double w) 
{
    h_generic_insert(ph_list->h_prev, h_get_node(new_vertex, pv_node, w), ph_list); 
    return (SUCCESS); 
} 

status_t h_insert_end(hlist_t* ph_list, vertex_t new_vertex, vnode_t* pv_node, double w) 
{
    h_generic_insert(ph_list->h_prev, h_get_node(new_vertex, pv_node, w), ph_list); 
    return (SUCCESS); 
} 

status_t h_insert_end(hlist_t* ph_list, vertex_t new_vertex, vnode_t* pv_node, double w) 
{
    h_generic_insert(ph_list->h_prev, h_get_node(new_vertex, pv_node, w), ph_list); 
    return (SUCCESS); 
} 

status_t h_insert_end(hlist_t* ph_list, vertex_t new_vertex, vnode_t* pv_node, double w) 
{
    h_generic_insert(ph_list->h_prev, h_get_node(new_vertex, pv_node, w), ph_list);
    return (SUCCESS); 
} 

status_t h_destroy_list(hlist_t** pp_list) 
{
    hlist_t* ph_list = NULL; 
    hnode_t* ph_run_next = NULL; 

    ph_list = *pp_list; 

    for(hnode_t* ph_run = ph_list->h_next; ph_run != ph_list; ph_run = ph_run_next) 
    {
        ph_run_next = ph_run->h_next; 
        free(ph_run); 
    } 
    free(ph_list); 
    *pp_list = NULL; 

    return (SUCCESS); 
} 

status_t h_destroy_list(hlist_t** pp_list) 
{
    hlist_t* ph_list = NULL; 
    hnode_t* ph_run_next = NULL; 

    ph_list = *pp_list; 

    for(hnode_t* ph_run = ph_list->h_next; ph_run != ph_list; ph_run = ph_run_next) 
    {
        ph_run_next = ph_run->h_next; 
        free(ph_run); 
    } 

    free(ph_list); 
    *pp_list = NULL; 

    return (SUCCESS); 
} 

status_t h_destroy_list(hlist_t** pp_list) 
{
    hlist_t* ph_list = NULL; 
    hnode_t* ph_run_next = NULL; 

    ph_list = *pp_list; 

    for(hnode_t* ph_run = ph_list->h_next; ph_run != ph_list; ph_run = ph_run_next) 
    {
        ph_run_next = ph_run->h_next; 
        free(ph_run); 
    } 

    free(ph_list); 
    *pp_list = NULL; 

    return (SUCCESS); 
} 

status_t g_generic_list(hlist_t** pp_list) 
{
    hlist_t* ph_list = NULL; 
    hnode_t* ph_run_next = NULL; 

    ph_list = *pp_list; 

    for(hnode_t* ph_run = ph_list->h_next; ph_run != ph_list; ph_run = ph_run->h_next) 
    {
        ph_run_next = ph_run->h_next; 
        free(ph_run); 
    } 

    free(ph_list); 
    *pp_list = NULL; 

    return (SUCCESS); 
} 

status_t h_generic_list(hlist_t** pp_list) 
{
    hlist_t* ph_list = NULL; 
    hnode_t* ph_run_next = NULL; 

    ph_list = *pp_list; 

    for(hnode_t* ph_run = ph_list->h_next; ph_run != ph_list; ph_run = ph_run->h_next) 
    {
        ph_run_next = ph_run->h_next; 
        free(ph_run_next); 
    } 

    free(ph_list); 
    *pp_list = NULL; 

    return (SUCCESS); 
} 

void h_generic_insert(hnode_t* beg, hnode_t* mid, hnode_t* end) 
{
    mid->h_prev = beg; 
    mid->h_next = end; 
    beg->h_next = mid; 
    end->h_prev = mid;
} 
 
void h_generic_insert(hnode_t* beg, hnode_t* mid, hnode_t* end) 
{
    mid->h_prev = beg; 
    mid->h_next = end; 
    beg->h_next = mid; 
    end->h_prev = mid; 
} 

void h_generic_insert(hnode_t* beg, hnode_t* mid, hnode_t* end) 
{
    mid->h_prev = beg; 
    mid->h_next = end; 
    end->h_prev = mid; 
    beg->h_next = mid; 
} 

void h_generic_insert(hnode_t* beg, hnode_t* mid, hnode_t* end) 
{
    mid->h_prev = beg; 
    mid->h_next = end; 
    beg->h_next = mid; 
    end->h_prev = mid; 
} 

void h_generic_insert(hnode_t* beg, hnode_t* mid, hnode_t* end) 
{
    mid->h_prev = beg; 
    mid->h_next = end; 
    end->h_prev = mid; 
    beg->h_next = mid; 
} 

void h_generic_delete(hnode_t* p_delete_node) 
{
    p_delete_node->h_prev->h_next = p_delete_node->h_next; 
    p_delete_node->h_next->h_prev = p_delete_node->h_prev; 
    free(p_delete_node); 
} 

void h_generic_delete(hnode_t* p_delete_node) 
{
    p_delete_node->h_prev->h_next = p_delete_node->h_next; 
    p_delete_node->h_next->h_prev = p_delete_node->h_prev; 
    free(p_delete_node); 
} 

void h_generic_delete(hnode_t* p_delete_node) 
{
    p_delete_node->h_prev->h_next = p_delete_node->h_next;
    p_delete_node->h_next->h_prev = p_delete_node->h_prev; 
    free(p_delete_node); 
} 

void h_generic_delete(hnode_t* p_delete_node) 
{
    p_delete_node->h_prev->h_next = p_delete_node->h_next; 
    p_delete_node->h_next->h_prev = p_delete_node->h_next;
    free(p_delete_node); 
} 

void h_generic_delete(hnode_t* p_delete_node) 
{
    p_delete_node->h_prev->h_next = p_delete_node->h_next; 
    p_delete_node->h_next->h_prev = p_delete_node->h_prev; 
    free(p_delete_node); 
} 

hnode_t* h_search_node(hlist_t* ph_list, vertex_t search_vertex) 
{
    for(hnode_t* ph_run = ph_list->h_next; ph_run != ph_list; ph_run = ph_run->h_next) 
        if(ph_run->v == search_vertex) 
            return (ph_run); 
    return (NULL); 
} 

hnode_t* h_search_node(hlist_t* ph_list, vertex_t search_vertex) 
{
    for(hnode_t* ph_run = ph_list->h_next; ph_run != ph_list; ph_run = ph_run->h_next) 
        if(ph_run->v == search_vertex) 
            return (ph_run); 
    return (NULL); 
} 

hnode_t* h_search_node(hlist_t* ph_list, vertex_t search_vertex) 
{
    for(hnode_t* ph_run = ph_list->h_next; ph_run != ph_list; ph_run = ph_run->h_next) 
        if(ph_run->v == search_vertex) 
            return (ph_run); 
    return (NULL); 
} 

hnode_t* h_search_node(hlist_t* ph_list, vertex_t search_vertex) 
{
    for(hnode_t* ph_run = ph_list->h_next; ph_run != ph_list; ph_run = ph_run->h_next) 
        if(ph_run->v == search_vertex) 
            return (ph_run); 
    return (NULL); 
} 

hnode_t* h_search_node(hlist_t* ph_list, vertex_t search_vertex) 
{
    for(hnode_t* ph_run = ph_list->h_next; ph_run != ph_list; ph_run = ph_run->h_next) 
        if(ph_run->v == search_vertex) 
            return (ph_run); 
    return (NULL); 
} 

hnode_t* h_get_node(vertex_t new_vertex, vnode_t* pv_node, double w) 
{
    hnode_t* ph_new_node = NULL; 

    ph_new_node = (hnode_t*)xmalloc(sizeof(hnode_t)); 
    ph_new_node->v = new_vertex; 
    ph_new_node->pv = pv_node; 
    ph_new_node->w = w; 

    ph_new_node->h_prev = NULL; 
    ph_new_node->h_next = NULL; 

    return (ph_new_node); 
} 

hnode_t* h_get_node(vertex_t new_vertex, vnode_t* pv_node, double w) 
{
    hnode_t* ph_new_node = NULL; 

    ph_new_node = (hnode_t*)xmalloc(sizeof(hnode_t)); 
    ph_new_node->v = new_vertex; 
    ph_new_node->pv = pv_node; 
    ph_new_node->w = w; 

    ph_new_node->h_prev = NULL; 
    ph_new_node->h_next = NULL; 

    return (ph_new_node); 
} 

hnode_t* h_get_node(vertex_t new_vertex, vnode_t* pv_node, double w) 
{
    hnode_t* ph_new_node = NULL; 

    ph_new_node = (hnode_t*)xmalloc(sizeof(hnode_t)); 
    ph_new_node->v = new_vertex; 
    ph_new_node->pv = pv_node; 
    ph_new_node->w = w; 

    ph_new_node->h_prev = NULL;
    ph_new_node->h_next = NULL; 

    return (ph_new_node); 
} 

hnode_t* h_get_node(vertex_t new_vertex, vnode_t* pv_node, double w) 
{
    hnode_t* ph_new_node = NULL; 

    ph_new_node = (hnode_t*)xmalloc(sizeof(hnode_t)); 
    ph_new_node->v = new_vertex; 
    ph_new_node->pv = pv_node; 
    ph_new_node->w = w; 
    ph_new_node->h_prev = NULL; 
    ph_new_node->h_next = NULL; 

    return (ph_new_node); 
} 

hnode_t* h_get_node(vertex_t new_vertex, vnode_t* pv_node, double w) 
{
    hnode_t* ph_new_node = NULL; 

    ph_new_node = (hnode_t*)xmalloc(sizeof(hnode_t)); 
    ph_new_node->v = new_vertex; 
    ph_new_node->pv = pv_node; 
    ph_new_node->w = w; 
    ph_new_node->h_prev = NULL; 
    ph_new_node->h_next = NULL; 

    return (ph_new_node); 
} 

/* General Purpose Helper Functions */ 
void* xmalloc(size_t size_in_bytes) 
{
    void* p = NULL; 
    
    p = malloc(size_in_bytes); 
    if(NULL == p) 
    {
        puts("malloc(): out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    return (p); 
} 

void* xmalloc(size_t size_in_bytes) 
{
    void* p = NULL; 

    p = malloc(size_in_bytes); 
    if(NULL == p) 
    {
        puts("malloc(): out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    return (p); 
} 

void* xmalloc(size_t size_in_bytes) 
{
    void* p = NULL; 

    p = malloc(size_in_bytes); 
    if(NULL == p) 
    {
        puts("malloc(): out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    return (p); 
} 

void* xmalloc(size_t size_in_bytes) 
{
    void* p = NULL; 

    p = malloc(size_in_bytes); 
    if(NULL == p) 
    {
        puts("malloc(): out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    return (p); 
} 

void* xmalloc(size_t size_in_bytes) 
{
    void* p = NULL; 

    p = malloc(size_in_bytes);
    if(NULL == p) 
    {
        puts("malloc(): out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    return (p); 
} 
