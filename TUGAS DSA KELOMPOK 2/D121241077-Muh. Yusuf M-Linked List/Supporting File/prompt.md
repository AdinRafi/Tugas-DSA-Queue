#  Struktur Data - Linked List

**Nama**: NAMA : MUH. YUSUF MA'RUF

**NIM**: D121241077 

**Problem**: Delete Node at a Given Position in a Linked List 

**Kategori**: Linked List (Easy)

---

##  Prompt

Delete the node at a given position in a linked list and return a reference to the head node. The head is at position 0. The list may be empty after you delete the node. In that case, return a null value. jawab dan jelaskan soal tersebut

# Jawaban

##  Format Masukan

- Baris pertama berisi jumlah node yang akan dimasukkan ke dalam linked list.
- Baris berikutnya adalah nilai dari setiap node.
- Baris terakhir berisi posisi (berbasis 0) node yang ingin dihapus.

##  Format Keluaran

- Tampilkan isi linked list sebelum dan sesudah penghapusan node.
- Jika list kosong setelah dihapus, tampilkan informasi bahwa list kosong.

---

##  Contoh Eksekusi Program

### **Contoh Input:**

Jumlah node: 5

Data ke-1: 10

Data ke-2: 20

Data ke-3: 30

Data ke-4: 40

Data ke-5: 50

Posisi yang dihapus (mulai dari 0): 2

### **Contoh Output:**
Sebelum hapus:
10 20 30 40 50

Setelah hapus:
10 20 40 50

---

##  Penjelasan Pendekatan

1. **Posisi Validasi:** Pastikan posisi yang ingin dihapus tidak lebih dari panjang list.
2. **Hapus di Awal (posisi 0):** Geser pointer `head` ke `head->next`.
3. **Hapus di Tengah/Akhir:**
   - Ambil node sebelum posisi target menggunakan `getNodeAt(pos - 1)`.
   - Ubah pointer `next` dari node tersebut ke `next->next`.
4. **Bebaskan Memori:** Gunakan `free()` untuk node yang dihapus.
5. **Kurangi Counter:** Kurangi nilai `count` dari linked list.

---

##  Kompleksitas Waktu

| Operasi        | Kompleksitas Waktu | Keterangan                           |
|----------------|---------------------|--------------------------------------|
| `append`       | O(n)                | Traversal hingga akhir list          |
| `getNodeAt`    | O(n)                | Traversal ke posisi ke-n             |
| `deleteAt`     | O(n)                | Traversal + penghapusan node         |
| `printList`    | O(n)                | Mencetak semua elemen dalam list     |
| `isEmpty`      | O(1)                | Cek pointer head                     |

---

##  Keunggulan Implementasi

- **Modular:** Fungsi-fungsi dipisahkan dengan jelas: `createNode`, `append`, `deleteAt`, `printList`.
- **Robust:** Menangani kasus list kosong dan penghapusan di posisi tidak valid.
- **Dinamis:** Menggunakan pointer dan `malloc` untuk alokasi dinamis.

---
