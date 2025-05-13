#include <stdio.h>
#include <stdbool.h>

#define QUERY_CAPACITY 100000 // Menentukan kapasitas maksimum stack

typedef struct
{
    int top;                        // Index atas stack
    long long data[QUERY_CAPACITY]; // Array untuk menyimpan data
} Stack;

// Fungsi untuk menginisialisasi stack (top=-1 berarti stack kosong)
void init(Stack *s)
{
    s->top = -1; // Inisialisasi stack kosong
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty(Stack *s)
{
    return s->top == -1; // Jika top == -1 berarti stack kosong
}

// Fungsi untuk mengecek apakah stack sudah penuh
bool isFull(Stack *s)
{
    return s->top == QUERY_CAPACITY - 1; // Jika top mencapai kapasitas maksimum, stack penuh
}

// Fungsi untuk memasukkan elemen ke dalam stack
bool push(Stack *s, long long value)
{
    if (isFull(s))
        return false;            // Cek jika stack penuh, tidak bisa menambah elemen
    s->data[++(s->top)] = value; // Post-increment: Menambah elemen ke stack dan naikkan indeks top
    return true;                 // Menyatakan operasi push berhasil
}

// Fungsi untuk mengeluarkan elemen dari stack
long long pop(Stack *s)
{
    return s->data[(s->top)--]; // Post-decrement: Keluarkan elemen dan turunkan indeks top
}

// Fungsi untuk melihat elemen paling atas stack tanpa mengeluarkannya
long long peek(Stack *s)
{
    return s->data[s->top]; // Tidak ada perubahan pada stack, hanya mengakses elemen atas
}

Stack s1, s2; // Dua stack untuk queue

// Memindahkan elemen dari s1 ke s2 jika s2 kosong
void shiftStacks()
{
    if (isEmpty(&s2))
    { // Jika stack s2 kosong
        // Pindahkan semua elemen dari s1 ke s2
        while (!isEmpty(&s1))
        {
            push(&s2, pop(&s1)); // Pindahkan elemen satu per satu dari s1 ke s2
        }
    }
}

// Fungsi untuk menambahkan elemen ke dalam antrian (enqueue)
void enqueue(long long x)
{
    push(&s1, x); // Masukkan elemen ke s1 (stack pertama)
}

// Fungsi untuk menghapus elemen dari depan antrian (dequeue)
void dequeue()
{
    shiftStacks(); // Pindahkan elemen dari s1 ke s2 jika perlu
    if (!isEmpty(&s2))
    {
        pop(&s2); // Hapus elemen paling atas dari s2 (elemen pertama yang masuk)
    }
}

// Fungsi untuk mencetak elemen paling depan antrian tanpa menghapusnya (peek front)
void printFront()
{
    shiftStacks(); // Pindahkan elemen dari s1 ke s2 jika perlu
    if (!isEmpty(&s2))
    {
        printf("%lld\n", peek(&s2)); // Tampilkan elemen paling depan tanpa menghapusnya
    }
}

int main()
{
    init(&s1); // Inisialisasi stack s1
    init(&s2); // Inisialisasi stack s2

    int q;
    scanf("%d", &q); // Input jumlah query

    for (int i = 0; i < q; i++)
    {
        int type;
        scanf("%d", &type); // Input tipe query

        if (type == 1)
        { // Enqueue: masukkan elemen ke antrian
            long long x;
            scanf("%lld", &x); // Input nilai untuk dimasukkan ke antrian
            enqueue(x);
        }
        else if (type == 2)
        { // Dequeue: hapus elemen dari antrian
            dequeue();
        }
        else if (type == 3)
        { // Print front: cetak elemen depan antrian
            printFront();
        }
    }

    return 0;
}
