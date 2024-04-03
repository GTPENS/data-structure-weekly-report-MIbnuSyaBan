#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    // constructor Node dengan delegating val ke variabel data dan mengisi next dengan nullptr 
    Node(int val) 
        : data(val), next(nullptr) {

    }
};

class Stack {
private:
    Node* top;

public:
    //contructor dengan delegating variabel top 
    Stack() 
        : top(nullptr) {
        
    }
    // Destructor dengan fungsi pop jika linked list memiliki isi agar tidak terjadi kebocoran memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
    // Menambah data stack paling atas
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }
    // Menghapus data stack paling atas
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            exit(EXIT_FAILURE);
        }
        Node* temp = top;
        int poppedValue = top->data;
        top = top->next;
        delete temp;
        return poppedValue;
    }
    // Mengambil data paling atas atau data dari node top
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            exit(EXIT_FAILURE);
        }
        return top->data;
    }
    // true jika stack kosong
    bool isEmpty() {
        return top == nullptr;
    }
    // Nampilkan data pada stack
    void display() {
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
// Mengkonversi tipe data string ke integer menggunakan stoi untuk menghindari error 
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
    Stack s;
    int choice, value;

    while (true) {
        cout << "\nMenu Program Stack:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Masukkan pilihan Anda: ";
        choice = stringToInteger();

        switch (choice) {
            case 1:
                cout << "Masukkan nilai untuk di-push: ";
                value = stringToInteger();
                s.push(value);
                break;
            case 2:
                if (!s.isEmpty()) {
                    cout << "Nilai yang di-pop: " << s.pop() << endl;
                } else {
                    cout << "Stack kosong." << endl;
                }
                break;
            case 3:
                if (!s.isEmpty()) {
                    cout << "Elemen teratas adalah: " << s.peek() << endl;
                } else {
                    cout << "Stack kosong." << endl;
                }
                break;
            case 4:
                s.display();
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