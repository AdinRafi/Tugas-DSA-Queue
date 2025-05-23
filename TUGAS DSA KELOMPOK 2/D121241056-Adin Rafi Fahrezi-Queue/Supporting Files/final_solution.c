#include <stdio.h>

#define LIMIT 1000001 // Batas Nilai Array + 1

// Fungsi untuk mengecek isi deque
int dequeNotEmpty(int front, int back)
{
    return front <= back; // Mengembalikan true apabila deque tidak kosong dan false jika sebaliknya
}

// Fungsi untuk mencari nilai minimal dari maximal sub-array deque sesuai panjang k
int minOfMaxInSubarrays(const int *arr, int n, int k)
{
    int deque[n];             // deque sebagai indeks pada array dengan batas n
    int front = 0, back = -1; // Inisialisasi front dan back

    int minOfMAX = LIMIT; // Deklarasi minOfMAX dengan nilai LIMIT

    for (int i = 0; i < n; i++) // Loop untuk menentukan nilai minimal dari maximal sub-array deque
    {
        if (dequeNotEmpty(front, back) && deque[front] <= i - k) // Memajukan indeks apabila sudah memenuhi kueri(k) / keluar dari window
        {
            front++;
        }

        while (dequeNotEmpty(front, back) && arr[i] >= arr[deque[back]]) // Menghapus elemen yang lebih kecil dari array[i] dari belakang
        {
            back--;
        }

        deque[++back] = i; // Menambahkan nilai indeks pada deque

        if (i >= k - 1) // Menaruh nilai minimal apabila currentMAX kurang dari minOfMAX
        {
            int currentMAX = arr[deque[front]];
            if (minOfMAX > currentMAX)
                minOfMAX = currentMAX;
        }
    }

    return minOfMAX; // Mengembalikan nilai minimal dari maximal sub-array deque
}

void solve(int *arr, int *query, int *result, int n, int q)
{
    for (int i = 0; i < q; i++)
    {
        result[i] = minOfMaxInSubarrays(arr, n, query[i]); // Mengisi nilai result pada indeks i sesuai hasil fungsi minOfMaxInSubarrays
    }
}

int main()
{
    int n, q;               // Inisialisasi n dan q
    scanf("%d %d", &n, &q); // Mengisi nilai n dan q sesuai input

    int arr[n];    // Array sebagai elemen dengan batas n
    int query[q];  // Kueri sebagai tempat menyimpan kueri(k) dengan batas n
    int result[q]; // Result sebagai tempat menyimpan hasil dengan batas n

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]); // Mengisi nilai array pada indeks i sesuai input
    }

    for (int i = 0; i < q; i++)
    {
        scanf("%d", &query[i]); // Mengisi nilai query pada indeks i sesuai input
    }

    solve(arr, query, result, n, q); // Memanggil fungsi solve untuk memecahkan masalah

    for (int i = 0; i < q; i++)
    {
        printf("%d\n", result[i]); // Menampilkan nilai result pada indeks i
    }

    return 0;
}