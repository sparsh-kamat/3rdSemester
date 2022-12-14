#include <stdio.h>
#include <stdlib.h>

#define N 100

struct node
{
    int vertex;
    struct node *next;
};

struct Graph
{
    int numVertices;
    struct node **adjLists;
    int *visited;
};

struct Graph *insertVertex(struct Graph *graph, int vertex)
{
    if (graph->numVertices == N)
    {
        printf("Graph is full");
        return graph;
    }
    graph->adjLists[vertex] = NULL;
    graph->visited[vertex] = 0;
    graph->numVertices++;
    return graph;
};

struct Graph *insertEdge(struct Graph *graph, int src, int dest)
{
    // Add edge from src to dest
    struct node *newNode = malloc(sizeof(struct node));
    newNode->vertex = dest;
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src
    newNode = malloc(sizeof(struct node));
    newNode->vertex = src;
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
    return graph;
};

// delete a vertex
struct Graph *deleteVertex(struct Graph *graph, int vertex)
{
    struct node *temp = graph->adjLists[vertex];
    struct node *next;
    while (temp != NULL)
    {
        next = temp->next;
        free(temp);
        temp = next;
    }
    graph->adjLists[vertex] = NULL;
    graph->visited[vertex] = 0;
    graph->numVertices--;
    return graph;
};

struct Graph *deleteEdge(struct Graph *graph, int src, int dest)
{
    struct node *temp = graph->adjLists[src];
    struct node *prev = NULL;
    while (temp != NULL)
    {
        if (temp->vertex == dest)
        {
            if (prev == NULL)
            {
                graph->adjLists[src] = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    temp = graph->adjLists[dest];
    prev = NULL;
    while (temp != NULL)
    {
        if (temp->vertex == src)
        {
            if (prev == NULL)
            {
                graph->adjLists[dest] = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return graph;
};

int searchVertex(struct Graph *graph, int vertex)
{
    if (graph->adjLists[vertex] == NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
};

int searchEdge(struct Graph *graph, int src, int dest)
{
    struct node *temp = graph->adjLists[src];
    while (temp != NULL)
    {
        if (temp->vertex == dest)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
};

void displayGraph(struct Graph *graph)
{
    int v;
    for (v = 0; v < graph->numVertices; v++)
    {
        struct node *temp = graph->adjLists[v];
        printf("\n Vertex %d: ", v);
        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL");
    }
}

struct Graph *createGraph()
{
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->numVertices = 0;
    graph->adjLists = malloc(N * sizeof(struct node *));
    graph->visited = malloc(N * sizeof(int));
    return graph;
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
    int choice;
    do
    {
        printf("\n1.Insert a vertex\n");
        printf("2.Insert an edge\n");
        printf("3.Delete a vertex\n");
        printf("4.Delete an edge\n");
        printf("5.Search a vertex\n");
        printf("6.Search an edge\n");
        printf("7.Display the graph\n");
        printf("8.Exit\n");
        printf("Enter your choice: ");
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
            displayGraph(graph);
            break;
        case 8:
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 8);
    return 0;
}
