#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

int arr[MAXN], maxWindow[MAXN], deque[MAXN];
int front, back;

// Fungsi untuk menghitung nilai minimum dari maksimum subarray sepanjang d
int minOfMax(int arr[], int n, int d)
{
    front = back = 0;
    int result = 1e9 + 7; // nilai sangat besar sebagai nilai awal minimum

    for (int i = 0; i < n; i++)
    {
        // Hapus elemen dari belakang yang lebih kecil dari elemen sekarang
        while (back > front && arr[i] >= arr[deque[back - 1]])
            back--;

        deque[back++] = i;

        // Hapus elemen dari depan jika di luar jendela
        if (deque[front] <= i - d)
            front++;

        // Setelah jendela pertama terbentuk
        if (i >= d - 1)
            if (arr[deque[front]] < result)
                result = arr[deque[front]];
    }

    return result;
}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i < q; i++)
    {
        int d;
        scanf("%d", &d);
        printf("%d\n", minOfMax(arr, n, d));
    }

    return 0;
}
