#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    // constructor Node dengan delegating val ke variabel data dan mengisi next dengan nullptr 
    Node(int val) : data(val), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    // constructor Queue dengan delegating value dari front dan rear nullptr
    Queue() : front(nullptr), rear(nullptr) {}
    // destructor dengan penghapusan Node menggunakan fungsi dequeue
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
    //menambahkan elemen baru ke bagian belakang antrian. Jika antrian kosong, elemen baru menjadi front dan rear. Jika tidak, elemen baru ditambahkan ke belakang dan rear diperbarui
    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }
    //menghapus elemen dari bagian depan antrian. Jika antrian kosong, fungsi ini akan menampilkan pesan kesalahan. Jika front menjadi nullptr, rear juga diatur ke nullptr
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }
    // Mereturn antrian paling depan
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }
    // True jika front nullptr
    bool isEmpty() {
        return front == nullptr;
    }
    // menampilkan semua element
    void display() {
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
// mengubah string menjadi integer
int stringToInteger(){
    int i;
    string s;
    bool loop;
    do{
        loop = false;
        try {
            cin >> s;
            i = stoi(s);
        } catch (invalid_argument& e) {
            cout << "\ntidak sesuai format" << endl;
            cout << "Masukkan data lagi : ";
            loop = true;
        }
    }while(loop);
    return i;
}
int main() {
    Queue q;
    int choice, value;

    while (true) {
        cout << "\nMenu Program Antrian:" << endl;
        cout << "1. Enqueue (Tambah)" << endl;
        cout << "2. Dequeue (Hapus)" << endl;
        cout << "3. Peek (Lihat elemen depan)" << endl;
        cout << "4. Display (Tampilkan semua elemen)" << endl;
        cout << "5. Exit (Keluar)" << endl;
        cout << "Masukkan pilihan Anda: ";
       choice = stringToInteger();

        switch (choice) {
            case 1:
                cout << "Masukkan nilai untuk di-enqueue: ";
                value = stringToInteger();
                q.enqueue(value);
                break;
            case 2:
                if (!q.isEmpty()) {
                    q.dequeue();
                    cout << "Elemen depan telah dihapus." << endl;
                } else {
                    cout << "Antrian kosong." << endl;
                }
                break;
            case 3:
                if (!q.isEmpty()) {
                    cout << "Elemen depan adalah: " << q.peek() << endl;
                } else {
                    cout << "Antrian kosong." << endl;
                }
                break;
            case 4:
                q.display();
                break;
            case 5:
                cout << "Keluar dari program." << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }

    return 0;
}

