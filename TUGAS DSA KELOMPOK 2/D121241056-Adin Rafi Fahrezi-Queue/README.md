# Struktur Data - Queue

<pre>
<strong>NAMA         :</strong> ADIN RAFI FAHREZI
<strong>NIM          :</strong> 121241056
<strong>Problem Link :</strong> <a href="https://www.hackerrank.com/challenges/queries-with-fixed-length/problem?isFullScreen=true">Queries with Fixed Length - HackerRank</a>
<strong>Difficulty   :</strong> Hard
</pre>

## Short Approach Summary

Untuk setiap query `d`, gunakan teknik Sliding Window Maximum untuk mencari nilai maksimum pada setiap subarray sepanjang `d`. Gunakan deque (menyimpan indeks) agar proses ini berjalan dalam `O(n)`:

1. Iterasi array dari kiri ke kanan.

2. Hapus elemen dari belakang deque jika lebih kecil dari elemen saat ini (agar deque tetap menurun).

3. Hapus elemen dari depan deque jika sudah keluar dari subarray saat ini.

4. Nilai maksimum subarray adalah elemen di depan deque.

5. Simpan semua nilai maksimum dari subarray tersebut, lalu ambil nilai minimum dari semuanya sebagai jawaban untuk query tersebut.

Lakukan langkah di atas untuk setiap query `d`.

Kompleksitas:

- Per query: `O(n)`

- Total: `O(q × n)` (aman karena `q ≤ 100`, `n ≤ 10⁵`)
