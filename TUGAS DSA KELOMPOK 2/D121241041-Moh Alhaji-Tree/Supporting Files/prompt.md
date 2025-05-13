# AI Prompt dan Analisis

## Prompt (Sumber Soal)

Buatkan sebuah program yang menghitung tinggi (height) dari sebuah tree. Tinggi dihitung dari jumlah edge, mulai dari root sampai ke daun terjauh.

## Penjelasan Soal

Lengkapi program dengan fungsi getHeight atau height. Dengan mengembalikan nilai height sebagai integer.

Jika Node sebuah tree hanya satu, maka tinggi dihitung 0. Karena root tidak memiliki anakan (daun), yang mana dihubungkan dengan edge.

### Format Masukan:

- Baris pertama berisi satu bilangan yang menyatakan jumlah nodes.
- Baris berikutnya adalah bilangan-bilangan yang akan menjadi nodes.
- Baris pertama akan menjadi Root pertama.

### Format Keluaran:

Sebuah integer yang merepresentasikan tinggi dari binary tree yang telah dihitung. 

### Batasan (Constraints):

1. `1 ≤ node.data[i] ≤ 20:` Setiap nilai nodes yang bisa diinput.
2. `1 ≤ n ≤ 20:` Banyaknya nodes yang bisa diinput.

### Sample Input

|  **STDIN**  |
|-------------|
|7            |
|3 5 2 1 4 6 7|



        3
       / \
      2   5
     /   / \
    1   4   6
               \
                7

### Sample Output

| **STDOUT** |
| ---------- |
| 3          |

### Penjelasan Eksekusi

        3
       / \ <-
      2   5
     /   / \ <-
    1   4   6
               \ <-
                7

Ada `4` nodes yang terhubungkan dengan `3` edge. Karena yang dihitung jumlah edges, berarti pada binary tree ini `height = 3`.

## Analisis dan Pendekatan Solusi

Untuk menghitung tinggi sebuah tree, digunakan pendekatan rekursif dengan memeriksa tiap node dari akar (root) ke daun (leaf) dan mencatat jumlah sisi (edge) terpanjang.

1. Tree terdiri dari simpul (nodes) yang terhubung secara hierarki.
2. Setiap node bisa memiliki anak kiri (left) dan anak kanan (right).
3. Tinggi sebuah tree adalah jumlah sisi (edges) dari node akar (root) hingga ke daun terjauh.

<pre>
  <strong>`Dalam konteks ini, tinggi dari tree dengan satu node adalah 0, maka jika root == NULL, kembalikan -1.`
</pre>
### Strategi Kerja

1. **Class Node** <br>
- Class `Node` dibuat untuk menyimpan data dan pointer ke anak kiri dan anak kanan.
- `Constructor` digunakan untuk inisialisasi data dan pointer `NULL`.
2. **Membangun BST (`Binary Search Tree`)** <br>
- Menggunakan fungsi `insert()` yang bekerja secara `rekursif`.
- Jika data lebih kecil atau sama dari node sekarang, masuk ke subtree kiri.
- Jika lebih besar, masuk ke subtree kanan.
3. **Menghitung Tinggi** <br>
- Fungsi `treeHeight()` menggunakan rekursi untuk menghitung tinggi subtree kiri dan kanan.
- Kemudian mengembalikan nilai maksimum dari keduanya ditambah 1.
- Basis rekursi: Jika root == NULL, kembalikan -1.

#### Langkah Eksekusi Program

<pre>
<strong>1. Input jumlah node (misalnya t = 6).
<strong>2. Baca nilai-nilai node (misalnya 4 7 2 3 8 1).
<strong>3. Sisipkan nilai satu per satu ke dalam BST menggunakan insert().
<strong>4. Hitung tinggi pohon dengan memanggil treeHeight().
<strong>5. Cetak hasilnya.
</pre>

### Kenapa Mengembalikan -1 Saat root == NULL?

Node `tunggal` memiliki tinggi `0` (tidak ada edge).

Maka jika tidak ada node `(kosong)`, kita perlu mengembalikan `-1`, agar ketika ditambahkan `+1`, hasilnya menjadi `0`.

### Efisiensi Waktu

- Insert (per node): `O(log n)`pada BST seimbang, `O(n)` pada kasus terburuk.

- treeHeight(): `O(n)` karena harus mengunjungi setiap node setidaknya satu kali.

### Keunggulan

- Sederhana dan efisien.
- Tidak membutuhkan struktur data tambahan.
- Menggunakan konsep rekursi yang cocok dengan sifat pohon.
- Skalabel untuk jumlah node yang besar.
