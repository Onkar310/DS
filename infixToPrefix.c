#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 20

struct stack
{
    char data[MAX];
    int top;
};

int isEmpty(struct stack *s)
{
    if (s->top == -1)
        return 1;
    return 0;
}
int isFull(struct stack *s)
{
    if (s->top == MAX - 1)
        return 1;
    return 0;
}

char top(struct stack *s)
{

    return (s->data[s->top]);
}

void init(struct stack *s)
{
    // s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
}

int precedence(char x)
{

    if (x == '(')
    {
        return 0;
    }
    else if (x == '+' || x == '-')
    {
        return 1;
    }
    else if (x == '*' || x == '/')
    {
        return 2;
    }
    else if (x == '%')
    {
        return 3;
    }
    else if (x == '^')
    {
        return 4;
    }
}

int isAlnum(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || ch >= 'A' && ch <= 'Z')
        return 1;
    else
        return 0;
}

void push(struct stack *s, char x)
{

    if (isFull(s))
    {
        printf("stack is full");
    }
    else
    {
        s->top = s->top + 1;
        s->data[s->top] = x;
    }
}

char pop(struct stack *s)
{
    char x = s->data[s->top];
    s->top--;
    return x;
}

void reverse(char *infix)
{
    int i = 0;
    while (infix[i] != '\0')
    {
        i++;
    };

    int start = 0;
    int end = i - 1;
    while (start <= end)
    {
        char temp = infix[start];
        infix[start] = infix[end];
        infix[end] = temp;
        start++;
        end--;
    }
}

void infixToPrefix(char infix[], char postfix[])
{
    int i = 0, j = 0;
    char x;
    struct stack s;
    // s = (struct stack *)malloc(sizeof(struct stack));
    init(&s);
    for (int i = 0; infix[i] != '\0'; i++)
    {
        char temp = infix[i];
        if (isAlnum(temp))
        {
            postfix[j++] = temp;
        }
        else
        {
            if (temp == '(')
            {
                push(&s, temp);
            }
            else if (temp == ')')
            {

                while ((x = pop(&s)) != '(')
                {
                    postfix[j++] = x;
                }
            }
            else
            {

                while (precedence(temp) <= precedence(top(&s)))
                {
                    postfix[j++] = pop(&s);
                }
                push(&s, temp);
            }
        }
    }
    while (!isEmpty(&s))
    {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}

int main()
{
    char infix[100], prefix[100];
    printf("Enter infix string:");
    scanf("%s", infix);
    reverse(infix);
    infixToPrefix(infix, prefix);
    reverse(prefix);
    printf("Postfix: %s\n", prefix);
    return 0;
}