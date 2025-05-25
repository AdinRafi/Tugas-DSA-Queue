/*
------------------------------------------------------
Program: Minimum dari Maksimum Subarray
------------------------------------------------------

Deskripsi:
Program ini mencari nilai minimum dari nilai maksimum
semua subarray dengan panjang tertentu (diberikan dalam query).

Metode:
- Menggunakan teknik "Sliding Window Maximum" dengan bantuan deque.
- Deque menyimpan indeks dari elemen dalam subarray saat ini.

Langkah-langkah utama:
1. Menghapus elemen dari depan deque jika sudah keluar dari window (subarray).s
2. Menghapus elemen dari belakang deque jika nilainya lebih kecil dari elemen saat ini.
3. Elemen di depan deque selalu menjadi indeks dari nilai maksimum saat ini.
4. Menyimpan nilai maksimum dari subarray, lalu mencari nilai minimum dari semua maksimum tersebut.

------------------------------------------------------
*/

#include <stdio.h>

#define MAKS_N 100000      // Batas n dan panjang subarray (1 ≤ n ≤ 100.000 dan 1 ≤ d ≤ n)
#define MAKS_Q 100         // Batas jumlah kueri (1 ≤ q ≤ 100)
#define MAKS_NILAI 1000000 // Nilai maksimum elemen arr[i] (0 ≤ arr[i] < 1.000.000)

// Cek apakah deque kosong
int dequeKosong(int indeksDepan, int indeksBelakang)
{
    return indeksDepan > indeksBelakang;
}

// Tambah elemen ke belakang deque
void enqueue(int deque[], int *indeksBelakang, int nilai)
{
    deque[++(*indeksBelakang)] = nilai;
}

// Hapus elemen dari depan deque
void dequeueDepan(int *indeksDepan)
{
    (*indeksDepan)++;
}

// Hapus elemen dari belakang deque
void dequeueBelakang(int *indeksBelakang)
{
    (*indeksBelakang)--;
}

// Ambil elemen depan deque (tanpa menghapus)
int lihatDepan(int deque[], int indeksDepan)
{
    return deque[indeksDepan];
}

// Ambil elemen belakang deque (tanpa menghapus)
int lihatBelakang(int deque[], int indeksBelakang)
{
    return deque[indeksBelakang];
}

int cariMinimumDariSemuaMaksimumSubarray(int data[], int jumlahData, int ukuranSubarray)
{
    int deque[MAKS_N];
    int indeksDepan = 0;
    int indeksBelakang = -1;

    int hasilMinimum = MAKS_NILAI;

    for (int i = 0; i < jumlahData; i++)
    {
        // 1. Hapus indeks dari depan jika keluar dari window
        if (!dequeKosong(indeksDepan, indeksBelakang) && lihatDepan(deque, indeksDepan) == i - ukuranSubarray)
        {
            dequeueDepan(&indeksDepan);
        }

        // 2. Hapus semua elemen dari belakang yang lebih kecil dari elemen saat ini
        while (!dequeKosong(indeksDepan, indeksBelakang) && data[i] >= data[lihatBelakang(deque, indeksBelakang)])
        {
            dequeueBelakang(&indeksBelakang);
        }

        // 3. Tambahkan indeks saat ini ke belakang deque
        enqueue(deque, &indeksBelakang, i);

        // 4. Jika sudah sampai panjang window, catat nilai maksimum
        if (i >= ukuranSubarray - 1)
        {
            int nilaiMaksimum = data[lihatDepan(deque, indeksDepan)];
            if (nilaiMaksimum < hasilMinimum)
            {
                hasilMinimum = nilaiMaksimum;
            }
        }
    }

    return hasilMinimum;
}

void prosesSemuaKueri(int data[], int jumlahData, int listUkuranSubarray[], int jumlahKueri, int hasil[])
{
    for (int i = 0; i < jumlahKueri; i++)
    {
        hasil[i] = cariMinimumDariSemuaMaksimumSubarray(data, jumlahData, listUkuranSubarray[i]);
    }
}

void bacaArray(int array[], int jumlah)
{
    for (int i = 0; i < jumlah; i++)
    {
        scanf("%d", &array[i]);
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

    prosesSemuaKueri(data, jumlahData, listUkuranSubarray, jumlahKueri, hasil);

    cetakHasil(hasil, jumlahKueri);

    return 0;
}
