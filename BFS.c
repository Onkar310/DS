#include <stdio.h>

int size = 100;
int queue[100];
int front = 0;
int rear = 0;

int isFull()
{
    if (rear == size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty()
{
    if (front == rear)
    {
        // front = rear = 0;
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(int data)
{
    if (!isFull())
    {
        queue[rear] = data;
        rear++;
    }
    else
    {
        printf("queue is full");
    }
}
int pop()
{
    if (!isEmpty())
    {
        int val = queue[front];
        front++;
        return val;
    }
    else
    {
        return -1;
    }
}

void display()
{
    if (!isEmpty())
    {
        for (int i = front; i < rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
    else
    {
        printf("Queue is Empty");
    }
}
int main()
{
    int a[5][5] = {{0, 0, 0, 1, 0},
                   {0, 0, 1, 1, 1},
                   {0, 1, 0, 0, 0},
                   {1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 0}};
    int node;
    int i = 0;
    printf("%d ", i);

    int visited[5] = {0, 0, 0, 0, 0};
    visited[i] = 1;
    push(i);
    while (!isEmpty())
    {
        // printf("%d-", isEmpty());
        int node = pop();
        for (int j = 0; j < 5; j++)
        {
            if (a[node][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                push(j);
            }
        }
    }

    return 0;
}