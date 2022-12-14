// create, insert and delete a vertex and edge,search,display.
// adjacency matrix of undirected graph

#include <stdio.h>
#include <stdlib.h>

#define N 100

struct Graph
{
    int numVertices;
    int adjMatrix[N][N];
    int *visited;
};

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

struct Graph *insertEdge(struct Graph *graph, int src, int dest)
{
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
    return graph;
};

struct Graph *deleteVertex(struct Graph *graph, int vertex)
{
    graph->visited[vertex] = 0;
    graph->numVertices--;
    return graph;
};

struct Graph *deleteEdge(struct Graph *graph, int src, int dest)
{
    graph->adjMatrix[src][dest] = 0;
    graph->adjMatrix[dest][src] = 0;
    return graph;
};

int searchVertex(struct Graph *graph, int vertex)
{
    if (graph->visited[vertex] == 1)
        return 1;
    else
        return 0;
};

int searchEdge(struct Graph *graph, int src, int dest)
{
    if (graph->adjMatrix[src][dest] == 1)
        return 1;
    else
        return 0;
};

void display(struct Graph *graph)
{
    int i, j;
    for (i = 0; i < graph->numVertices; i++)
    {
        printf(" %d: ", i);
        for (j = 0; j < graph->numVertices; j++)
        {
            if (graph->adjMatrix[i][j] == 1)
                printf(" %d", j);
        }
        printf(" | ");
    }
    printf("\n");
};

int main()
{
    struct Graph *graph = createGraph();
    int i, j, k, l, m, n, o;
    printf("Enter the number of vertices: ");
    scanf("%d", &i);
    for (j = 0; j < i; j++)
    {
        printf("Enter the vertex: ");
        scanf("%d", &k);
        graph = insertVertex(graph, k);
    }
    printf("Enter the number of edges: ");
    scanf("%d", &l);
    for (m = 0; m < l; m++)
    {
        printf("Enter the source and destination: ");
        scanf("%d %d", &n, &o);
        graph = insertEdge(graph, n, o);
    }
    // menu
    int choice;
    do
    {
        printf("\n1.Insert a vertex");
        printf("\n2.Insert an edge");
        printf("\n3.Delete a vertex");
        printf("\n4.Delete an edge");
        printf("\n5.Search a vertex");
        printf("\n6.Search an edge");
        printf("\n7.Display the graph");
        printf("\n8.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the vertex: ");
            scanf("%d", &k);
            graph = insertVertex(graph, k);
            break;
        case 2:
            printf("Enter the source and destination: ");
            scanf("%d %d", &n, &o);
            graph = insertEdge(graph, n, o);
            break;
        case 3:
            printf("Enter the vertex: ");
            scanf("%d", &k);
            graph = deleteVertex(graph, k);
            break;
        case 4:
            printf("Enter the source and destination: ");
            scanf("%d %d", &n, &o);
            graph = deleteEdge(graph, n, o);
            break;

        case 5:
            printf("Enter the vertex: ");
            scanf("%d", &k);
            if (searchVertex(graph, k))
            {
                printf("Vertex found\n");
            }
            else
            {
                printf("Vertex not found\n");
            }
            break;
        case 6:
            printf("Enter the source and destination: ");
            scanf("%d %d", &n, &o);
            if (searchEdge(graph, n, o))
            {
                printf("Edge found\n");
            }
            else
            {
                printf("Edge not found\n");
            }
            break;
        case 7:
            display(graph);
            break;
        case 8:
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 8);
    return 0;
}
