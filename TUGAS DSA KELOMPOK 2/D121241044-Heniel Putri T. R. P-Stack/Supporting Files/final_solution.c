#include <stdio.h> // Untuk fungsi input-output seperti scanf dan printf

#define MAX_N 50000   // Jumlah maksimum elemen array A
#define MAX_Q 1200    // Jumlah maksimum bilangan prima yang digunakan (q)

// Fungsi untuk mengecek apakah suatu angka adalah bilangan prima
int isPrime(int x) {
    // Langkah pertama ialah kita periksa apakah x < 2
    // jika ya,maka bukan bilangan prima dan kembalikan ke nilai 0
    if (x < 2) return 0; 
    // Kita pakai loop for untuk mencoba membagi x dengan angka dari 2 sampai akar x
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0; // Jika habis dibagi, berarti bukan prima
    }
    return 1; // Jika tidak ada pembagi, maka prima
}

// Fungsi untuk menghasilkan dan menyimpan q buah bilangan prima pertama kedalam array primes
// Ada dua input: primes ialah sebuah array tempat menyimpan bilangan prima
// dan q ialah jumlah bilangan prima yang ingin di hasilkan
void generatePrimes(int *primes, int q) {
    // Langkah pertama kita mulai dari angka 2. 
    // Count digunakan untuk menghitung banyaknya prima yang di temukan kemudian di simpan
    int num = 2, count = 0;
    // Loop while akan terus berjalan sampai mendapatkan q bilangan prima, setelah itu baru berhenti
    while (count < q) {
        // Untuk setiap angka num, kita periksa apakah num adalah bilangan prima
        // dengan memanggil fungsi isPrime(num).
        if (isPrime(num)) {
            // Jika num adalah bilangan prima:
            // - Simpan ke array primes pada posisi indeks 'count'
            // - Tambahkan count, karena kita sudah menemukan satu bilangan prima
            primes[count++] = num; 
        }
        // Setelah itu, naikkan nilai num sebesar 1 supaya bisa memeriksa angka selanjutnya di loop berikutnya
        num++;
    }
}

int main() {
    int n, q; // n: menyimpan jumlah angka yg akan dimasukkan ke array, q: menyimpan jumlah iterasi
    printf("Masukkan nilai n dan q:\n");
    scanf("%d %d", &n, &q); // Membaca dua bilangan bulat dan menyimpan ke variabel n dan q.

    int A[MAX_N]; // Array untuk menyimpan angka awal
    printf("Masukkan nilai array A:\n");
    for (int i = 0; i < n; i++)// Loop for, program akan mengulang sampai i = n-1, total sebanyak n kali 
    {
        scanf("%d", &A[i]); // Membaca elemen-elemen array A dari input, dan menyimpannya ke dalam array A di posisi ke-i
    }

    printf("Output:\n");

    int primes[MAX_Q]; // Array untuk menyimpan q bilangan prima pertama yang dibutuhkan
    generatePrimes(primes, q); // Mengisi array primes dan menghasilkan q bilangan prima pertama

    int top = n; // Menyimpan jumlah angka yang masih harus diproses dari array A

    for (int i = 0; i < q; i++) // Melakukan proses pemisahan selama q kali
     {
        int B[MAX_N], bTop = 0; // Buat array B kosong dan hitungannya, untuk menyimpan angka yang habis dibagi bilangan prima
        int A_1[MAX_N], topA_1 = 0; // Buat array A_1 kosong dan hitungannya, untuk menyimpan angka yang tidak habis dibagi bil.prima

        // Proses dari belakang (sesuai prinsip stack)
        for (int j = top - 1; j >= 0; j--) // Memeriksa elemen-elemen dalam array A dari belakang ke depan.
        {
            if (A[j] % primes[i] == 0) // Cek apakah angka A[j] habis dibagi oleh bil. prima
            {
                B[bTop++] = A[j]; // Jika habis dibagi prima, masukkan ke array B
            } else {
                A_1[topA_1++] = A[j]; // Jika tidak, simpan di array A_1 untuk iterasi berikutnya
            }
        }

        // Mencetak semua angka yg ada di array B secara terbalik (yang masuk terakhir sampai pertama)
        for (int j = bTop - 1; j >= 0; j--) {
            printf("%d\n", B[j]);
        }

        // Pindahkan A_1 ke A untuk proses iterasi selanjutnya
        for (int j = 0; j < topA_1; j++) {
            A[j] = A_1[j];
        }
        top = topA_1; // Update jumlah elemen A yang tersisa
    }

    // Cetak sisa elemen di A secara terbalik setelah semua iterasi selesai
    for (int i = top - 1; i >= 0; i--) {
        printf("%d\n", A[i]); 
    }

    return 0; // Program selesai
}

