#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void append(Node** head, int data) {
    Node* new = malloc(sizeof(Node));
    new->data = data;
    new->next = NULL;

    if (!*head) {
        *head = new;
        return;
    }

    Node* cur = *head;
    while (cur->next) cur = cur->next;
    cur->next = new;
}

void printList(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

Node* deleteAt(Node* head, int pos) {
    if (pos == 0 && head) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node* cur = head;
    for (int i = 0; i < pos - 1 && cur; i++) cur = cur->next;

    if (cur && cur->next) {
        Node* temp = cur->next;
        cur->next = temp->next;
        free(temp);
    }

    return head;
}

int main() {
    Node* head = NULL;
    int n, val, pos;

    printf("Jumlah node: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Data ke-%d: ", i + 1);
        scanf("%d", &val);
        append(&head, val);
    }

    printf("\nSebelum hapus:\n");
    printList(head);

    printf("Posisi yang dihapus (mulai dari 0): ");
    scanf("%d", &pos);

    head = deleteAt(head, pos);

    printf("\nSetelah hapus:\n");
    printList(head);
    return 0;
}
