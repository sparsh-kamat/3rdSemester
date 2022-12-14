//create, insert and delete a vertex and edge,search,display.
//adjacency matrix of directed graph

#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of vertices in the graph
#define N 100

// Define the structure of a graph
struct Graph
{
    int numVertices;
    int adjMatrix[N][N];
    int *visited;
};

//insert a vertex
struct Graph *insertVertex(struct Graph *graph, int vertex)
{
    if (graph->numVertices == N)
    {
        printf("Graph is full");
        return graph;
    }
    graph->visited[vertex] = 0;
    graph->numVertices++;
    return graph;
};

//insert an edge
struct Graph *insertEdge(struct Graph *graph, int src, int dest)
{
    graph->adjMatrix[src][dest] = 1;
    return graph;
};

//delete a vertex
struct Graph *deleteVertex(struct Graph *graph, int vertex)
{
    graph->visited[vertex] = 0;
    graph->numVertices--;
    return graph;
};

//delete an edge
struct Graph *deleteEdge(struct Graph *graph, int src, int dest)
{
    graph->adjMatrix[src][dest] = 0;
    return graph;
};

//search a vertex
int searchVertex(struct Graph *graph, int vertex)
{
    if (graph->visited[vertex] == 1)
        return 1;
    else
        return 0;
};

//search an edge
int searchEdge(struct Graph *graph, int src, int dest)
{
    if (graph->adjMatrix[src][dest] == 1)
        return 1;
    else
        return 0;
};

//display the graph
void display(struct Graph *graph)
{
    int i, j;
    for (i = 0; i < graph->numVertices; i++)
    {
        printf(" %d |", i);
        for (j = 0; j < graph->numVertices; j++)
        {
            printf(" %d ", graph->adjMatrix[i][j]);
        }
        printf(" | %d ", i);
        printf(" |\n");
    }
};

/**/