#include <stdio.h>
#include <limits.h>
#define V 5

int minKey(int key[], int set[])
{
    int minimum = INT_MAX;
    int index;
    int i;
    for (i = 0; i < V; i++)
    {
        if (key[i] < minimum && set[i] == 0)
        {
            minimum = key[i];
            index = i;
        }
    }
    return index;
}
void display(int parent[], int a[V][V])
{
    printf("Edge \t weight \n");
    for (int i = 1; i < V; i++)
    {

        printf("%d-%d\t%d\n", parent[i], i, a[i][parent[i]]);
    }
}
void prims(int a[V][V])
{
    int u;
    int parent[10]; // tracks parent of nodes
    int key[10];    // tracks min distance
    int set[10];    // tracks visited nodes

    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        set[i] = 0;
    }
    key[0] = 0;
    // set[0] = 1;
    parent[0] = -1;

    for (int i = 0; i < V - 1; i++)
    {
        int u = minKey(key, set);
        set[u] = 1;
        for (int j = 0; j < V; j++)
        {
            if ((a[u][j] != 1000) && set[j] == 0 && (a[u][j] < key[j]))
            {
                parent[j] = u;
                key[j] = a[u][j];
            }
        }
    }
    display(parent, a);
}

int main()
{

    // printf("Enter matrix: \n");
    // for (int i = 0; i < V; i++)
    // {
    //     for (int j = 0; j < V; j++)
    //     {
    //         scanf("%d", &a[i][j]);
    //     }
    // }
    int a[V][V] = {
        {1000, 1000, 3, 1000, 1000},
        {1000, 1000, 10, 4, 1000},
        {3, 10, 1000, 2, 6},
        {1000, 4, 2, 1000, 1},
        {1000, 1000, 6, 1, 1000},
    };
    prims(a);
    return 0;
}
// The time complexity of Prim's algorithm is O(E log V).