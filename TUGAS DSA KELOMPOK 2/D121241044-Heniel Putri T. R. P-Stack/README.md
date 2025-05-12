
# Struktur Data - Stack

<pre>
<strong>NAMA         :</strong> HENIEL PUTRI TANGKO RAMBA PADANG
<strong>NIM          :</strong> D121241044
<strong>Problem Link :</strong> <a href=https://www.hackerrank.com/challenges/waiter/problem?isFullScreen=true>Waiter - HackerRank</a>
<strong>Difficulty   :</strong> Medium
</pre>

## Short Approach Summary
Stack adalah struktur data linear yang mengikuti prinsip LIFO (Last In, First Out) (terakhir masuk, pertama keluar).
Untuk contoh problem pada Hackerrank kita memproses tumpukan piring dengan nomor tertentu melalui beberapa iterasi, dimana setiap iterasi memisahkan piring berdasarkan bilangan prima.

Langkah-langkah:
1. Siapkan Bilangan Prima
   - Buat list bilangan prima sebanyak jumlah iterasi (q)  
   - Contoh: jika q=2 → dapatkan [2, 3]
2. Proses Tumpukan Piring 
   - Mulai dengan semua piring di tumpukan awal (A)  
   - Lakukan perulangan sebanyak q kali:
     Ambil bilangan prima sesuai iterasi
     Pisahkan piring di tumpukan A:
        - Jika nomor piring habis dibagi bilangan prima → masukkan ke B
        - Jika tidak → masukkan ke A baru
     Pindahkan isi B ke jawaban (dari atas ke bawah)
     A untuk iterasi berikutnya adalah A baru
3. Tambahkan Sisa Piring  
   - Setelah semua iterasi, tambahkan piring yang tersisa di A ke jawaban </strong>.</p>

### Yang Perlu Diperhatikan:
- Urutan piring saat dipindahkan harus dari atas (elemen terakhir array)
- Waktu: O(q × n) karena setiap iterasi memproses semua piring
- Ruang: O(n) untuk menyimpan hasil
