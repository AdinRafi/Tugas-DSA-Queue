# AI Prompt dan Analisis

## Prompt (Sumber Soal)

Buat implementasi struktur data queue (antrian) dengan hanya menggunakan dua buah stack. Queue mengikuti prinsip FIFO (First In First Out), berbeda dengan stack yang menggunakan LIFO (Last In First Out).

## Penjelasan Soal

Program menerima sejumlah `q` query dari input standar. Setiap query bisa berupa:

1. `1 x` → Enqueue nilai `x` ke dalam queue.
2. `2` → Dequeue (hapus) elemen dari depan queue.
3. `3` → Cetak elemen paling depan dari queue (tanpa menghapusnya).

### Format Masukan:

- Baris pertama berisi satu bilangan bulat yang menyatakan jumlah query.
- Setiap baris berikutnya adalah sebuah query.
- Semua query diawali dengan sebuah bilangan bulat yang menunjukkan jenis query.
- Hanya query tipe 1 yang diikuti oleh satu nilai tambahan untuk dimasukkan ke antrean.

### Format Keluaran:

Untuk setiap query jenis ke-3 (`3`), cetak elemen paling depan dari queue.

### Batasan (Constraints):

1. `1 ≤ q ≤ 10⁵:` Banyaknya operasi bisa sangat besar, jadi efisiensi waktu sangat penting.
2. `1 ≤ type ≤ 3:` Tipe query pasti valid.
3. `1 ≤ |x| ≤ 10⁹:` Nilai elemen bisa sangat besar, jadi gunakan tipe data seperti `long` di C.
4. Diberikan bahwa setiap query jenis `3` akan selalu valid (tidak pernah memanggil cetak dari queue kosong).

### Sample Input

| **STDIN** | **Function**               |
| --------- | -------------------------- |
| 10        | q = 10 (number of queries) |
| 1 42      | 1st query, enqueue 42      |
| 2         | dequeue front element      |
| 1 14      | enqueue 42                 |
| 3         | print the front element    |
| 1 28      | enqueue 28                 |
| 3         | print the front element    |
| 1 60      | enqueue 60                 |
| 1 78      | enqueue 78                 |
| 2         | dequeue front element      |
| 2         | dequeue front element      |

### Sample Output

| **STDOUT** |
| ---------- |
| 14         |
| 14         |

### Penjelasan Eksekusi

<pre>
`1 42`: Enqueue 42 → Queue: {42}
`2`   : Dequeue 42 → Queue: {}
`1 14`: Enqueue 14 → Queue: {14}
`3`   : Cetak 14
`1 28`: Enqueue 28 → Queue: {14, 28}
`3`   : Cetak 14
`1 60`:Queue jadi {14, 28, 60}
`1 78`: Queue jadi {14, 28, 60, 78}
`2`   : Dequeue 14 → Queue: {28, 60, 78}
`2`   : Dequeue 28 → Queue: {60, 78}
</pre>

## Analisis dan Pendekatan Solusi

Untuk membangun `struktur data queue (FIFO)` menggunakan dua buah `stack (LIFO)`, digunakan pendekatan berikut:

1. `stack1`: untuk menyimpan elemen yang masuk (`enqueue`)
2. `stack2`: untuk mengeluarkan atau melihat elemen depan (`dequeue` dan `peek`)

### Strategi Kerja

1. ` Enqueue (``1 x``) ` <br>
   return Tambahkan elemen `x` ke `stack1`.
2. **Dequeue (`2`)** <br>
   Menghapus elemen pertama dari `stack2`.
3. **Peek (`3`)** <br>
   Mencetak elemen pertama dari `stack2`tanpa menghapusnya.

#### Pemindahan data `stack1` ke `stack2`

- Jika `stack2` **tidak kosong**, ambil elemen dari `stack2`.
- Jika `stack2` **kosong**, pindahkan semua elemen dari `stack1` ke `stack2`.
<p align="left">Proses ini membalik urutan dan menempatkan elemen yang paling lama masuk di atas `stack2`.</p>

### Kenapa Bisa FIFO?

Meskipun stack bekerja secara LIFO (Last In, First Out), dengan memindahkan elemen dari `stack1` ke `stack2`, urutan elemen menjadi terbalik. Dengan begitu, elemen yang pertama kali masuk (`enqueue`) akan jadi yang pertama keluar (`dequeue`), sesuai prinsip FIFO (First In, First Out).

### Efisiensi Waktu

- **Enqueue: O(1)** <br>
  Menambahkan elemen ke `stack1` adalah operasi konstan, karena tidak memerlukan pergeseran elemen lain.
- **Dequeue / Peek: Amortized O(1)** <br>
  Meskipun pada saat pemindahan elemen dari stack1 ke stack2 mungkin tampak seperti operasi yang mahal, tetapi `setiap elemen hanya dipindahkan satu kali`. `Ini berarti bahwa total waktu untuk operasi ini adalah amortized O(1)`, meskipun secara individu operasi `dequeue` atau `peek` mungkin memerlukan pemindahan elemen.

### Keunggulan

- Tidak perlu memindahkan elemen setiap kali operasi dilakukan (hanya saat pemindahan dari `stack1` ke `stack2`).
- Cocok untuk jumlah query besar (hingga 100.000 data).
- Implementasi sederhana dan tidak membutuhkan library tambahan.
