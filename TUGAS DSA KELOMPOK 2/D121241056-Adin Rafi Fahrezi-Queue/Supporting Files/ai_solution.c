#include <stdio.h>

#define MAX 100000

// Struktur stack
typedef struct Stack
{
    int top;
    long long data[MAX];
} Stack;

void init(Stack *s)
{
    s->top = -1;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

void push(Stack *s, long long value)
{
    s->data[++(s->top)] = value;
}

long long pop(Stack *s)
{
    return s->data[(s->top)--];
}

long long peek(Stack *s)
{
    return s->data[s->top];
}

Stack s1, s2;

void shiftStacks()
{
    if (isEmpty(&s2))
    {
        while (!isEmpty(&s1))
        {
            push(&s2, pop(&s1));
        }
    }
}

void enqueue(long long x)
{
    push(&s1, x);
}

void dequeue()
{
    shiftStacks();
    if (!isEmpty(&s2))
    {
        pop(&s2);
    }
}

void printFront()
{
    shiftStacks();
    if (!isEmpty(&s2))
    {
        printf("%lld\n", peek(&s2));
    }
}

int main()
{
    init(&s1);
    init(&s2);

    int q;
    scanf("%d", &q);

    for (int i = 0; i < q; i++)
    {
        int type;
        scanf("%d", &type);

        if (type == 1)
        {
            long long x;
            scanf("%lld", &x);
            enqueue(x);
        }
        else if (type == 2)
        {
            dequeue();
        }
        else if (type == 3)
        {
            printFront();
        }
    }

    return 0;
}
