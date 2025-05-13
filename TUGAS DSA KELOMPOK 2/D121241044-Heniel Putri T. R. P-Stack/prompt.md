# Prompt 

## Prompt (Sumber Soal)

You are a waiter at a party. There is a pile of numbered plates. Create an empty answers array. At each iteration, i, remove each plate from the top of the stack in order. Determine if the number on the plate is evenly divisible by the iᵗh prime number. If it is, stack it in pile Bᵢ. Otherwise, stack it in stack Aᵢ. Store the values in Bᵢ from top to bottom in answers. In the next iteration, do the same with the values in stack Aᵢ. Once the required number of iterations is complete, store the remaining values in Aᵢ in answers, again from top to bottom. Return the answers array.

Jelaskan dan jawab soal ini.


## Penjelasan Soal
Kita diberikan tumpukan piring yang masing-masing memiliki nomor dan sejumlah iterasi q. Di setiap iterasi, kita akan menggunakan bilangan prima untuk memeriksa nomor pada piring. Bilangan prima digunakan secara berurutan: prima pertama (2), prima kedua (3), prima ketiga (5), dan seterusnya.


### Format Masukan:
- Baris pertama berisi dua bilangan bulat, n (jumlah piring) dan q (jumlah iterasi).

- Baris kedua berisi n bilangan bulat yang merepresentasikan nomor piring, dengan urutan terakhir adalah puncak tumpukan.

Contoh: 

5 1  
3 4 7 6 5  

### Format Keluaran:
- Array bilangan bulat hasil pemrosesan, di mana setiap elemen dipisahkan oleh baris baru (\n).

Contoh:

4  
6  
3  
7  
5  
### Batasan (Constraints):
- 1 ≤ n ≤ 5 x 10<sup>4</sup>

- 2 ≤ number[i] ≤ 10<sup>4</sup>

- 1 ≤ q ≤ 1200

### - Sample Input 0

5 1  
3 4 7 6 5  

### - Sample Output 0

4  
6  
3  
7  
5  


### Penjelasan Eksekusi
1. Tumpukan Awal (A): [3, 4, 7, 6, 5] (5 di puncak).

2. Iterasi 1 (Prima = 2):

- Pindahkan piring dari A:

    - 5 % 2 ≠ 0 → tetap di A (sekarang A = [3, 4, 7, 6]).

    - 6 % 2 = 0 → pindah ke B = [6].

    - 7 % 2 ≠ 0 → tetap di A = [3, 4].

    - 4 % 2 = 0 → pindah ke B = [6, 4].

    - 3 % 2 ≠ 0 → tetap di A = [].

- Pindahkan isi B ke answers = [4, 6] (karena B adalah stack, atas ke bawah = 4 lalu 6).

3. Sisa A: Kosong.

4. Hasil Akhir: Gabungkan answers + sisa A = [4, 6, 3, 7, 5].

### - Sample Input 1

5 2  
3 3 4 4 9  

### - Sample Output 1

4  
4  
9  
3  
3  

### Penjelasan Eksekusi
1. Tumpukan Awal (A): [3, 3, 4, 4, 9] (9 di puncak).
2. Iterasi 1 (Prima = 2):
   
   Proses:
    - Ambil 9 dari A → 9 % 2 ≠ 0 → tetap di A = [3, 3, 4, 4].
    - Ambil 4 → 4 % 2 = 0 → pindah ke B = [4].
    - Ambil 4 → 4 % 2 = 0 → pindah ke B = [4, 4].
    - Ambil 3 → 3 % 2 ≠ 0 → tetap di A = [3, 3].
    - Ambil 3 → 3 % 2 ≠ 0 → tetap di A = [3, 3].
      
    Hasil Sementara:
    - B = [4, 4] → tambahkan ke answers = [4, 4] (urutan top-to-bottom).
    - A baru = [3, 3, 9] (karena 9 sebelumnya tidak diproses).
3. Iterasi 2 (Prima = 3)
   
   Proses:
    - Ambil 9 dari A → 9 % 3 = 0 → pindah ke B = [9].
    - Ambil 3 → 3 % 3 = 0 → pindah ke B = [9, 3].
    - Ambil 3 → 3 % 3 = 0 → pindah ke B = [9, 3, 3].
      
   Hasil Sementara:
    - B = [9, 3, 3] → tambahkan ke answers = [4, 4, 9, 3, 3].
    - A baru = [] (kosong).

  4. Finalisasi
     Tidak ada sisa di A, jadi answers sudah lengkap.

### Urutan Hasil Akhir
1. answers dari Iterasi 1: [4, 4].

2. answers dari Iterasi 2: [9, 3, 3].

3. Gabungan: [4, 4, 9, 3, 3].

## Penjelasan Solusi


### Strategi Kerja
1. Generate Bilangan Prima: Gunakan Sieve of Eratosthenes untuk efisiensi.
2. Simulasi Stack:
  - Gunakan struktur data stack untuk A dan B.
  - Di setiap iterasi, pindahkan elemen dari A ke B jika habis dibagi prima ke-i.
  - Elemen yang tidak terpakai dikembalikan ke A untuk iterasi berikutnya.
3. Penggabungan Hasil:
  - Setiap B yang sudah diproses ditambahkan ke answers (dalam urutan top-to-bottom).
  - Jika iterasi selesai, sisa A langsung ditambahkan ke answers.


### Efisiensi Waktu
- Generate Primes: O(q log log q) dengan Sieve.
- Proses Stack: O(n) per iterasi → total O(q × n).
- Optimal untuk Constraints: Karena q dan n ≤ 10^5, solusi O(q × n) masih feasible dengan optimasi.

### Keunggulan
- Sederhana dan Intuitif: Menggunakan stack sesuai alur soal.
- Minimal Ruang Tambahan: Hanya membutuhkan dua stack (A dan B) dan array answers.
