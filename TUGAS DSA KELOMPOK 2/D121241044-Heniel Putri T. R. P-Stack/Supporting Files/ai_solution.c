#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Fungsi untuk mengecek apakah suatu bilangan adalah prima
bool is_prime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

// Fungsi untuk menghasilkan q bilangan prima pertama
int* generate_primes(int q) {
    int* primes = (int*)malloc(q * sizeof(int));
    int count = 0;
    int num = 2;
    while (count < q) {
        if (is_prime(num)) {
            primes[count] = num;
            count++;
        }
        num++;
    }
    return primes;
}

// Struktur untuk merepresentasikan stack
typedef struct {
    int* items;
    int top;
    int capacity;
} Stack;

// Fungsi untuk membuat stack baru
Stack* create_stack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->items = (int*)malloc(capacity * sizeof(int));
    return stack;
}

// Fungsi untuk mengecek apakah stack kosong
bool is_empty(Stack* stack) {
    return stack->top == -1;
}

// Fungsi untuk menambahkan elemen ke stack
void push(Stack* stack, int item) {
    if (stack->top == stack->capacity - 1) {
        // Stack penuh, alokasikan lebih banyak memori
        stack->capacity *= 2;
        stack->items = (int*)realloc(stack->items, stack->capacity * sizeof(int));
    }
    stack->items[++stack->top] = item;
}

// Fungsi untuk mengambil elemen dari stack
int pop(Stack* stack) {
    if (is_empty(stack)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top--];
}

// Fungsi untuk membalik stack
void reverse_stack(Stack* stack) {
    int* temp = (int*)malloc(stack->capacity * sizeof(int));
    int i = 0;
    while (!is_empty(stack)) {
        temp[i++] = pop(stack);
    }
    for (int j = 0; j < i; j++) {
        push(stack, temp[j]);
    }
    free(temp);
}

// Fungsi utama untuk memproses tumpukan piring
int* waiter(int* number, int n, int q, int* result_size) {
    Stack* A = create_stack(n);
    for (int i = n - 1; i >= 0; i--) {
        push(A, number[i]);
    }

    int* answers = (int*)malloc(n * sizeof(int));
    *result_size = 0;

    int* primes = generate_primes(q);

    for (int i = 0; i < q; i++) {
        Stack* B = create_stack(n);
        Stack* new_A = create_stack(n);
        int prime = primes[i];

        while (!is_empty(A)) {
            int plate = pop(A);
            if (plate % prime == 0) {
                push(B, plate);
            } else {
                push(new_A, plate);
            }
        }

        // Pindahkan isi B ke answers (dari atas ke bawah)
        reverse_stack(B);
        while (!is_empty(B)) {
            answers[(*result_size)++] = pop(B);
        }

        // A sekarang adalah new_A
        free(A->items);
        free(A);
        A = new_A;
    }

    // Pindahkan sisa elemen di A ke answers (dari atas ke bawah)
    reverse_stack(A);
    while (!is_empty(A)) {
        answers[(*result_size)++] = pop(A);
    }

    free(primes);
    free(A->items);
    free(A);

    return answers;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    int* number = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &number[i]);
    }

    int result_size;
    int* result = waiter(number, n, q, &result_size);

    for (int i = 0; i < result_size; i++) {
        printf("%d\n", result[i]);
    }

    free(number);
    free(result);

    return 0;
}
