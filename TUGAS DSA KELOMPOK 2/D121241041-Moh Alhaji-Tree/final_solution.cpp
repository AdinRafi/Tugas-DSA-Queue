#include <bits/stdc++.h>
using namespace std;

// Tree = Konsep Struktur Data yang terdiri atas nodes(simpul) atau daun(leaf) dan akar(root)
// Bersifat Hierarki
// treeHeight = Jumlah sisi dari root sampai leaf yang terjauh.

//Program ini hanya memerlukan Operasi Menghitung Tinggi Sebuah Tree

class Node{ //Untuk meyimpan data(nilai) untuk digunakan dalam Tree
    public: //Agar Class bisa diakses di semua program
        int data;
        Node *left;
        Node *right;
        Node(int d){ //Ketika nilai dimasukkan, d akan menjadi root pertama, dan anakannya (left dan right) akan menjadi NULL atau kosong
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution{ //Untuk menginput data(nilai) dan menghitung tinggi dari sebuah Tree
    public:
        Node* insert(Node* root, int data){ //Merekursif hasil inputan sebagai data, node left, atau node right
            if(root == NULL){
                return new Node(data);
            }else {
                Node* cur;
                if(data <= root->data){
                    cur = insert(root->left, data);
                    root->left = cur;
                }else {
                    cur = insert(root->right, data);
                    root->right = cur;
                }
                return root;
            }
        }

    int treeHeight(Node* root){ //Rekursif untuk menghitung tinggi tree
        if(root == NULL) return -1; //Jika root tidak ada (NULL), maka edge(sisi) di anggap -1
        return max(treeHeight(root->left), treeHeight(root->right)) + 1; //Jika max(-1,-1), di ambil -1 + 1  = 0. 0 ini merupakan tinggi tree
    }                                                         
};                                                              


int main(){
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    cin >> t;

    for(int i = 0; i < t; i++){
        cin >> data;
        root = myTree.insert(root, data);
    }
    
    int treeHeight = myTree.treeHeight(root);
    
  	cout << treeHeight;

    return 0;
}
