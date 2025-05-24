#include <stdio.h>

/*Dokumentasi Program

Fungsi Program
Mencari nilai minimum dari maksimum subarray sesuai ukuran subarray(query[q]) dengan sistem window
menggunakan deque sebagai indeks dari data(arrr[i]) yang memiliki 4 operasi dasar:
1. Memajukan indeks depan deque jika melewati ukuran subarray
2. Menghapus elemen dari indeks belakang deque jika isi elemen kurang dari elemen saat ini
3. Mencari nilai maksimum dari subarray
4. Mencari nilai minimum dari semua maksimum subarray*/

#define MAKS_N 100000      // Batas n dan query[q] (1 ≤ n ≤ 10⁵ dan 1 ≤ d ≤ n)
#define MAKS_Q 100         // Batas q (1 ≤ q ≤ 100)
#define MAKS_NILAI 1000000 // Batas arr[1] + 1 (0 ≤ arr[i] < 10⁶)

void bacaArray(int array[], int jumlah)
{
    for (int i = 0; i < jumlah; i++)
    {
        scanf("%d", &array[i]);
    }
}

int dequeKosong(int deque[], int indeksDepan, int indeksBelakang)
{
    return indeksDepan > indeksBelakang;
}

int cariMinimumDariSemuaMaksimumSubarray(int data[], int jumlahData, int ukuranSubarray)
{
    int deque[MAKS_N];
    int indeksDepan = 0;
    int indeksBelakang = -1;

    int hasilMinimum = MAKS_NILAI;

    for (int i = 0; i < jumlahData; i++)
    {
        if (!dequeKosong(deque, indeksDepan, indeksBelakang) && deque[indeksDepan] <= i - ukuranSubarray)
        {
            indeksDepan++;
        }

        while (!dequeKosong(deque, indeksDepan, indeksBelakang) && data[i] >= data[deque[indeksBelakang]])
        {
            indeksBelakang--;
        }

        deque[++indeksBelakang] = i;

        if (i >= ukuranSubarray - 1)
        {
            int nilaiMaksimum = data[deque[indeksDepan]];
            if (nilaiMaksimum < hasilMinimum)
            {
                hasilMinimum = nilaiMaksimum;
            }
        }
    }

    return hasilMinimum;
}

void prosesSemuaPertanyaan(int data[], int jumlahData, int listUkuranSubarray[], int jumlahKueri, int hasil[])
{
    for (int i = 0; i < jumlahKueri; i++)
    {
        hasil[i] = cariMinimumDariSemuaMaksimumSubarray(data, jumlahData, listUkuranSubarray[i]);
    }
}

void cetakHasil(int hasil[], int jumlah)
{
    for (int i = 0; i < jumlah; i++)
    {
        printf("%d\n", hasil[i]);
    }
}

int main()
{
    int jumlahData, jumlahKueri;

    scanf("%d %d", &jumlahData, &jumlahKueri);

    int data[MAKS_N];
    int listUkuranSubarray[MAKS_Q];
    int hasil[MAKS_Q];

    bacaArray(data, jumlahData);
    bacaArray(listUkuranSubarray, jumlahKueri);

    prosesSemuaPertanyaan(data, jumlahData, listUkuranSubarray, jumlahKueri, hasil);

    cetakHasil(hasil, jumlahKueri);

    return 0;
}
