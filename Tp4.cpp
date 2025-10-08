#include <iostream>
using namespace std;

struct Node {
    char nama[50];
    float nilai;
    Node* next;
};

void salinNama(char* tujuan, const char* sumber) {
    int i = 0;
    while (sumber[i] != '\0') {
        tujuan[i] = sumber[i];
        i++;
    }
    tujuan[i] = '\0';
}

void insertLast(Node*& head, const char* nama, float nilai) {
    Node* baru = new Node;
    salinNama(baru->nama, nama);
    baru->nilai = nilai;
    baru->next = nullptr;

    if (!head) {
        head = baru;
    } else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = baru;
    }
}

float hitungRata(Node* head) {
    float total = 0;
    int jumlah = 0;
    Node* temp = head;
    while (temp) {
        total += temp->nilai;
        jumlah++;
        temp = temp->next;
    }
    return jumlah ? total / jumlah : 0.0;
}

int main() {
    Node* head = nullptr;
    int jumlahData;

    cout << "Masukkin jumlah mahasiswa: ";
    cin >> jumlahData;

    for (int i = 0; i < jumlahData; i++) {
        char nama[50];
        float nilai;
        cin >> nama;
        cin >> nilai;
        insertLast(head, nama, nilai);
    }
    cout << "Rata rata nilai : " << hitungRata(head) << endl;
    return 0;
}
