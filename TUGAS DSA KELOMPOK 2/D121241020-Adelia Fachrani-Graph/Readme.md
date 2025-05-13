# Struktur Data – Graph

**Nama:** Adelia Fachrani  
**NIM:** D121241020  
**Problem Link:** [HackerRank - Components in a Graph](https://www.hackerrank.com/challenges/components-in-graph/problem)  
**Difficulty:** Weighted Edges  

---

## 📚 Pengantar Graf

Dalam struktur data, **graf (graph)** adalah struktur non-linear yang terdiri dari:

- **Node (Simpul / Vertex):** Elemen atau titik pada graf.
- **Edge (Sisi / Arc):** Hubungan antara dua simpul.

---

## 🔢 Jenis-Jenis Graf

1. **Graf Tak Berarah (Undirected Graph)**  
   - Sisi tidak memiliki arah.  
   - Contoh: hubungan pertemanan di media sosial.

2. **Graf Berarah (Directed Graph / Digraph)**  
   - Sisi memiliki arah (panah).  
   - Contoh: akun yang mengikuti akun lain di Instagram.

3. **Graf Berbobot (Weighted Graph)**  
   - Setiap sisi memiliki bobot (nilai).  
   - Contoh: jarak antara dua kota di peta.

4. **Graf Terhubung (Connected Graph)**  
   - Terdapat jalur antara setiap pasangan simpul (untuk graf tak berarah).  
   - Untuk graf berarah, disebut *strongly connected* jika ada jalur dua arah antara semua simpul.

5. **Graf Siklik dan Asiklik (Cyclic & Acyclic)**  
   - **Siklik:** Memiliki siklus (jalur yang kembali ke simpul awal).  
   - **Asiklik:** Tidak memiliki siklus.  
   - Contoh: DAG (*Directed Acyclic Graph*) digunakan dalam pemodelan dependensi (misal: compiler, project management).

---

## 🧮 Representasi Graf

1. **Adjacency Matrix**  
   - Matriks 2D berukuran VxV (V = jumlah simpul).  
   - `matrix[i][j] = 1` jika ada edge dari simpul *i* ke *j*.

2. **Adjacency List**  
   - Setiap simpul menyimpan daftar simpul tetangga.  
   - Lebih efisien untuk graf yang jarang (*sparse graph*).

### Contoh Kode: Adjacency List (Python)

```python
graph = {
    'A': ['B', 'C'],
    'B': ['A', 'D'],
    'C': ['A', 'D'],
    'D': ['B', 'C']
}
