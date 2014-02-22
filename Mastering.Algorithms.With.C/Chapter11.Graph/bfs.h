/* bf.h */
#ifndef BFS_H
#define BFS_H

#include "graph.h"
#include "list.h"

/* define a structure for vertices in a breath-first search */
typedef struct BfsVertex_{
    void *data;
    VertexColor color;
    int hops;
}BfsVertex;


/* public Interface */
int bfs(Graph *graph, BfsVertex *start, list *hops);

#endif

