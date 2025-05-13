#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int count;
} LinkedList;

int isEmpty(LinkedList* list) {
    return list->head == NULL;
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(LinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (isEmpty(list)) {
        list->head = newNode;
    } else {
        Node* temp = list->head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    list->count++;
}

void printList(LinkedList* list) {
    if (isEmpty(list)) {
        printf("List kosong\n");
        return;
    }
    Node* temp = list->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

Node* getNodeAt(LinkedList* list, int pos) {
    if (pos < 0 || pos >= list->count) return NULL;
    Node* temp = list->head;
    for (int i = 0; i < pos; i++)
        temp = temp->next;
    return temp;
}

void deleteAt(LinkedList* list, int pos) {
    if (pos < 0 || pos >= list->count || isEmpty(list)) {
        printf("Posisi tidak valid atau list kosong.\n");
        return;
    }

    Node* toDelete;
    if (pos == 0) {
        toDelete = list->head;
        list->head = list->head->next;
    } else {
        Node* prev = getNodeAt(list, pos - 1);
        toDelete = prev->next;
        prev->next = toDelete->next;
    }
    free(toDelete);
    list->count--;
}

int main() {
    LinkedList list = {NULL, 0};
    int n, val, pos;

    printf("Jumlah node: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Data ke-%d: ", i + 1);
        scanf("%d", &val);
        append(&list, val);
    }

    printf("\nSebelum hapus:\n");
    printList(&list);

    printf("Posisi yang dihapus (mulai dari 0): ");
    scanf("%d", &pos);

    deleteAt(&list, pos);

    printf("\nSetelah hapus:\n");
    printList(&list);

    return 0;
}
