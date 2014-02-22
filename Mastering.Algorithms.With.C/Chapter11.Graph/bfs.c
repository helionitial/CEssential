/* bfs.c */
#include <stdlib.h>
#include "bfs.h"
#include "graph.h"
#include "list.h"
#include "queue.h"

/* bfs */
int bfs(Graph *graph, BfsVertex *start, List *hops){
    Queue queue;
    AdjList *adjlist, *clr_adjlist;
    BfsVertex *clr_vertex, *adj_vertex;
    ListElmt *element, *member;
    
    /* initialize all of the vertices in the graph */
    for(element = list_head(&graph_adjlists(graph)); element != NULL; element = list_next(element)){
        clr_vertex = ((AdjList *)list_data(element))->vertex;
    }
}