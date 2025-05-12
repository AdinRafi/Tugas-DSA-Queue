# Struktur Data - Tree

<pre>
<strong>NAMA         :</strong> Moh. Alhaji Putra Lede
<strong>NIM          :</strong> D121241041
<strong>Problem Link :</strong> <a href="https://www.hackerrank.com/challenges/tree-height-of-a-binary-tree/problem?isFullScreen=true">Trees: Height of A Binary Tree - HackerRank</a>
<strong>Difficulty   :</strong> Easy
</pre>

## Short Approach Summary

Untuk menghitung `height` dari sebuah `tree`, kita menggunakan `fungsi rekursif`. Kita juga menggunakan `class` agar program lebih fleksibel.

1. `Class Node` digunakan untuk menyimpan data yang akan diinput. `Class Solution` digunakan untuk menginput data menggunakan fungsi insert(), dan menghitung tinggi menggunakan fungsi height().
2. Tree dibagi menjadi kiri dan kanan, dan merekursif untuk mendapatkan nilainya.
3. Apabila `Node = NULL`, maka nilai akan dikembalikan pada `-1`.

Jika Node tidak ada `(NULL)` maka tinggi di `return -1`, karena kita menghitung tinggi berdasarkan `edge(sisi)`.

### Efisiensi Waktu

`Fungsi insert()` memiliki kompleksitas waktu `O(log n)` jika pohon seimbang, tapi bisa menjadi `O(n)` jika input membentuk pohon miring. `Fungsi height()` selalu membutuhkan waktu `O(n)` karena harus mengunjungi seluruh simpul dalam pohon.
