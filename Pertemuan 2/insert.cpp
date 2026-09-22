#include <iostream>
using namespace std;

struct Node {
    int value;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

void insertFirst(int n) {
    Node *newNode = new Node;
    newNode->value = n;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = head;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
}

void insertLast(int n) {
    Node *newNode = new Node;
    newNode->value = n;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = head;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAfter(int n, int check) {
    if (head == NULL) {
        cout << "List kosong, silakan insert terlebih dahulu!" << endl;
        return;
    }

    Node *newNode = new Node;
    newNode->value = n;
    newNode->next = NULL;

    Node *p = head;
    while (p != NULL && p->value != check) {
        p = p->next;
    }

    if (p == NULL) {
        cout << "Node dengan nilai " << check
             << " tidak ditemukan!" << endl;
        delete newNode;
    }
    else {
        newNode->next = p->next;
        p->next = newNode;

        if (p == tail) {
            tail = newNode;
        }
    }
}

void deleteFirst() {
    if (head == NULL) {
        cout << "List kosong!" << endl;
        return;
    }

    Node *temp = head;
    head = head->next;

    if (head == NULL) {
        tail = NULL;
    }

    delete temp;
}

void deleteMiddle(int value) {
    if (head == NULL) {
        cout << "List kosong!" << endl;
        return;
    }

    if (head->value == value) {
        deleteFirst();
        return;
    }

    Node *p = head;

    while (p->next != NULL && p->next->value != value) {
        p = p->next;
    }

    if (p->next == NULL) {
        cout << "Node dengan nilai "
             << value
             << " tidak ditemukan!"
             << endl;
    }
    else {
        Node *temp = p->next;
        p->next = temp->next;

        if (temp == tail) {
            tail = p;
        }
        delete temp;
    }
}

void printList() {
    Node *temp = head;

    cout << "Isi Linked List: ";

    while (temp != NULL) {
        cout << temp->value << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main() {
    int pilihan;
    int nilai;
    int cari;

    do {
        cout << "===== MENU SINGLE LINKED LIST =====" << endl;
        cout << "1. Tambah di awal" << endl;
        cout << "2. Tambah di akhir" << endl;
        cout << "3. Tambah setelah nilai tertentu" << endl;
        cout << "4. Hapus berdasarkan nilai" << endl;
        cout << "5. Tampilkan Linked List" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {

        case 1:
            cout << "Masukkan nilai: ";
            cin >> nilai;

            insertFirst(nilai);
            printList();
            break;

        case 2:
            cout << "Masukkan nilai: ";
            cin >> nilai;

            insertLast(nilai);
            printList();
            break;

        case 3:
            cout << "Masukkan nilai baru: ";
            cin >> nilai;

            cout << "Masukkan nilai yang ingin dicari: ";
            cin >> cari;

            insertAfter(nilai, cari);
            printList();
            break;

        case 4:
            cout << "Masukkan nilai yang ingin dihapus: ";
            cin >> nilai;

            deleteMiddle(nilai);
            printList();
            break;

        case 5:
            printList();
            break;

        case 0:
            cout << "Program selesai." << endl;
            break;

        default:
            cout << "Pilihan tidak tersedia!" << endl;
        }

    } while (pilihan != 0);

    return 0;
}