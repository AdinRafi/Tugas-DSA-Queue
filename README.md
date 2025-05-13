# Struktur Data - Graph

Dalam **struktur data**, **graph (graf)** adalah **struktur data non-linier** yang terdiri dari sekumpulan **simpul (node atau vertex)** dan **sisi (edge)** yang menghubungkan pasangan simpul tersebut. Graph digunakan untuk merepresentasikan hubungan antar objek, dan banyak dipakai di berbagai bidang seperti jaringan komputer, sosial media, pencarian rute, dan lain-lain.

### Komponen Utama Graph:

1. **Vertex (simpul)**: Titik-titik dalam graph yang merepresentasikan entitas.
2. **Edge (sisi)**: Garis yang menghubungkan dua vertex, merepresentasikan relasi antara dua entitas.


### Jenis-jenis Graph:

1. **Graph Berdasarkan Arah:**

   * **Directed Graph (Graf Berarah)**: Sisi memiliki arah (dari satu simpul ke simpul lain).
   * **Undirected Graph (Graf Tak Berarah)**: Sisi tidak memiliki arah (hubungan dua arah).

2. **Graph Berdasarkan Bobot:**

   * **Weighted Graph**: Setiap sisi memiliki nilai bobot (cost, jarak, waktu, dll).
   * **Unweighted Graph**: Sisi tidak memiliki bobot.

3. **Graph Berdasarkan Siklus:**

   * **Cyclic Graph**: Terdapat satu atau lebih jalur tertutup (siklus).
   * **Acyclic Graph**: Tidak memiliki siklus.

4. **Special Graph:**

   * **Tree**: Graph acyclic dan terhubung dengan aturan tertentu.
   * **DAG (Directed Acyclic Graph)**: Graf berarah yang tidak mengandung siklus.


### Representasi Graph:

1. **Adjacency Matrix**: Matriks 2D yang menunjukkan hubungan antar simpul.
2. **Adjacency List**: Daftar simpul yang berisi tetangganya.


### Contoh Kasus Penggunaan Graph:

* Peta jalan (rute GPS)
* Jaringan komputer
* Struktur pertemanan di media sosial
* Penyusunan jadwal (topological sort)
