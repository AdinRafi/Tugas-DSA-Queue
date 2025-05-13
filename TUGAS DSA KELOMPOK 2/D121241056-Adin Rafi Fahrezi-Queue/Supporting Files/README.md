# Struktur Data - Queue

<pre>
<strong>NAMA         :</strong> ADIN RAFI FAHREZI
<strong>NIM          :</strong> 121241056
<strong>Problem Link :</strong> <a href="https://www.hackerrank.com/challenges/queue-using-two-stacks/problem?isFullScreen=true">Queue using Two Stacks - HackerRank</a>
<strong>Difficulty   :</strong> Medium
</pre>

## Short Approach Summary

Untuk membangun struktur data `queue (FIFO)`menggunakan dua `stack (LIFO)`, pendekatannya adalah sebagai berikut:

1. `stack1` digunakan untuk operasi `enqueue`, yaitu menambahkan elemen ke dalam queue.
2. `stack2` digunakan untuk operasi `dequeue` dan `peek` (melihat elemen depan).
3. Jika `stack2` kosong, pindahkan semua elemen dari `stack1` ke `stack2`.

<p align="left">Proses pemindahan ini membalik urutan elemen dan memastikan elemen yang pertama kali masuk akan keluar lebih dulu, sesuai dengan prinsip <strong>FIFO (First In, First Out)</strong>.</p>

### Efisiensi Waktu

- **Enqueue**: O(1) <br>
  Operasi ini hanya menambahkan elemen ke dalam `stack1`, yang merupakan operasi konstan.
- **Dequeue / Peek**: **Amortized O(1)** <br>
  Meskipun kadang perlu memindahkan elemen dari `stack1` ke `stack2`, `setiap elemen hanya dipindahkan sekali`, sehingga waktu rata-rata per operasi tetap `O(1)`.
