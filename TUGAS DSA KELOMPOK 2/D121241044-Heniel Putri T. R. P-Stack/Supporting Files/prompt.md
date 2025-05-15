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

    - 5 % 2 ≠ 0 → pindah ke A₁ = [5].

    - 6 % 2 = 0 → pindah ke B₁ = [6].

    - 7 % 2 ≠ 0 → pindah ke A₁ = [5, 7].

    - 4 % 2 = 0 → pindah ke B₁ = [6, 4].

    - 3 % 2 ≠ 0 → pindah ke A₁ = [5, 7, 3].

- Pindahkan isi B ke answers = [4, 6] (karena B adalah stack, atas ke bawah = 4 lalu 6).
  
- Pindahkan isi A₁ ke answers = [3, 7, 5]
      (karena A₁ juga stack, atas ke bawah = 3 lalu 7 lalu 5).
 3. Hasil Akhir: answers = [4, 6, 3, 7, 5].

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
1. Tumpukan Awal (A): [3, 3, 4, 4, 9] (9 di puncak)
2. Iterasi 1 (Prima = 2):
   
- Pindahkan piring dari A:

    - 9 % 2 ≠ 0 → A₁ = [9]

    - 4 % 2 = 0 → B₁ = [4]

    - 4 % 2 = 0 → B₁ = [4, 4]

    - 3 % 2 ≠ 0 → A₁ = [9, 3]

    - 3 % 2 ≠ 0 → A₁ = [9, 3, 3]

- Pindahkan isi B₁ ke answers = [4, 4]
(karena B₁ adalah stack, atas ke bawah = 4 lalu 4)

3. Iterasi 2 (Prima = 3):
   
- Pindahkan piring dari A₁:

    - 3 % 3 = 0 → B₂ = [3]

    - 3 % 3 = 0 → B₂ = [3, 3]

    - 9 % 3 = 0 → B₂ = [3, 3, 9]
      A₂ kosong.

- Pindahkan isi B₂ ke answers = [4, 4, 9, 3, 3]
(karena B₂ adalah stack, atas ke bawah = 9, 3, 3)

- Tidak ada nilai tersisa di A₂.
  
4. Hasil Akhir: [4, 4, 9, 3, 3]


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
