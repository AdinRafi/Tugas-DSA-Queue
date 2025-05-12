#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i * i <= num; i += 2)
        if (num % i == 0) return false;
    return true;
}

int* getPrimes(int q) {
    int* primes = (int*)malloc(q * sizeof(int));
    int count = 0, num = 2;
    while (count < q) {
        if (isPrime(num)) {
            primes[count] = num;
            count++;
        }
        num++;
    }
    return primes;
}

typedef struct {
    int* data;
    int top;
    int size;
} Stack;

Stack* createStack(int size) {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->size = size;
    s->top = -1;
    s->data = (int*)malloc(size * sizeof(int));
    return s;
}

bool isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int val) {
    if (s->top == s->size - 1) {
        s->size *= 2;
        s->data = (int*)realloc(s->data, s->size * sizeof(int));
    }
    s->data[++s->top] = val;
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack kosong\n");
        exit(1);
    }
    return s->data[s->top--];
}

void reverseStack(Stack* s) {
    int temp[s->top + 1];
    int i = 0;
    while (!isEmpty(s))
        temp[i++] = pop(s);
    for (int j = 0; j < i; j++)
        push(s, temp[j]);
}

int* waiter(int* numbers, int n, int q, int* resultSize) {
    Stack* A = createStack(n);
    for (int i = n - 1; i >= 0; i--)
        push(A, numbers[i]);

    int* result = (int*)malloc(n * sizeof(int));
    *resultSize = 0;

    int* primes = getPrimes(q);

    for (int i = 0; i < q; i++) {
        Stack* B = createStack(n);
        Stack* newA = createStack(n);

        while (!isEmpty(A)) {
            int plate = pop(A);
            if (plate % primes[i] == 0)
                push(B, plate);
            else
                push(newA, plate);
        }

        reverseStack(B);
        while (!isEmpty(B))
            result[(*resultSize)++] = pop(B);

        free(A->data);
        free(A);
        A = newA;
    }

    reverseStack(A);
    while (!isEmpty(A))
        result[(*resultSize)++] = pop(A);

    free(primes);
    free(A->data);
    free(A);

    return result;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    int* numbers = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &numbers[i]);

    int resultSize;
    int* result = waiter(numbers, n, q, &resultSize);

    for (int i = 0; i < resultSize; i++)
        printf("%d\n", result[i]);

    free(numbers);
    free(result);

    return 0;
}
