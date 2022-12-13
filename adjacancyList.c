#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct adjList
{
    struct node *head;
};

struct graph
{
    int v;
    struct adjList *array;
};

struct node *adjList(int dest)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = dest;
    newNode->next = NULL;
    return newNode;
}

struct graph *createGraph(int ver)
{
    struct graph *Graph = (struct graph *)malloc(sizeof(struct graph));
    Graph->v = ver;
    Graph->array = (struct adjList *)malloc(ver * (sizeof(struct adjList)));

    for (int i = 0; i < ver; ++i)
    {
        Graph->array[i].head = NULL;
    }
    return Graph;
}

void addEdge(struct graph *Graph, int src, int dest)
{

    struct node *check = NULL;
    struct node *newNode = adjList(dest);
    if (Graph->array[src].head == NULL)
    {
        // newNode->next = Graph->array[src].head;
        Graph->array[src].head = newNode;
    }
    else
    {
        // 1 2 3 4 5
        check = Graph->array[src].head;
        while (check->next != NULL)
        {
            check = check->next;
        }
        check->next = newNode;
    }
    newNode = adjList(src);

    if (Graph->array[dest].head == NULL)
    {
        // newNode->next = Graph->array[src].head;
        Graph->array[dest].head = newNode;
    }
    else
    {
        // 1 2 3 4 5
        check = Graph->array[dest].head;
        while (check->next != NULL)
        {
            check = check->next;
        }
        check->next = newNode;
    }
}
void printGraph(struct graph *Graph)
{
    int v;
    for (v = 0; v < Graph->v; ++v)
    {
        struct node *pCrawl = Graph->array[v].head;
        printf("\n %d== ", v);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->data);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}
int main()
{
    int V = 5;
    struct graph *Graph = createGraph(V);
    addEdge(Graph, 0, 1);
    addEdge(Graph, 0, 4);
    addEdge(Graph, 1, 2);
    addEdge(Graph, 1, 3);
    addEdge(Graph, 1, 4);
    addEdge(Graph, 2, 3);
    addEdge(Graph, 3, 4);

    printGraph(Graph);

    return 0;
}