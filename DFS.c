#include <stdio.h>
int a[7][7] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0},
};

int visited[7] = {0, 0, 0, 0, 0, 0, 0};

void DFS(int node)
{
    printf("%d ", node);
    visited[node] = 1;
    for (int i = 0; i < 7; i++)
    {
        if (a[node][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

int main()
{
    DFS(0);
    return 0;
}