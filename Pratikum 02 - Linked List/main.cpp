/*
Single Linked List Pratikum 02
    keterangan fungsi yang di pakai :
    createNode          : Membuat Simpul baru 
    insertNodeAtHead    : Akan memanggil CreateNode dan menyisipkan simpul baru ke Head
    insertNodeAtTail    : Akan memanggil CreateNode dan menyisipkan simpul baru ke Tail
    printList           : Menampilkan semua simpul 
    searchNode          : Mencari simpul berdasarkan variable pertama 
    stringToInterger    : Mengkonversi tipe data string ke integer menggunakan stoi untuk menghindari error 
*/
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data){
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;  
    return newNode;
}

void insertNodeAtHead(Node** head, int data){
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertNodeAtTail(Node** head, int data){
    Node* newNode = createNode(data);
    if(*head == NULL){
        *head = newNode;      
    }      
    else{
        Node* temp = *head;
        while(temp->next != NULL){
            temp = temp->next;          
        }
        temp->next = newNode;      
    }
}

Node* searchNode(Node* head, int data){
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == data){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
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
    Node* head = NULL;
    int choice, data;
    while(true){
        cout << "Menu:\n1. Menyisipkan sebagai simpul ujung tawal \n2. Menyisipkan sebagai simpul terakhir\n3. Mencari sebuah simpul tertentu\n4. Menampilkan data\n5. Keluar\n";
        cout << "Pilihan : ";
        choice = stringToInteger();
        switch(choice){
            case 1:
                cout << "Masukkan data: ";
                data = stringToInteger();
                insertNodeAtHead(&head, data);
                break;
            case 2:
                cout << "Masukkan data: ";
                data = stringToInteger();
                insertNodeAtTail(&head, data);
                break;
            case 3:
                cout << "Masukkan data yang dicari : ";
                data = stringToInteger();
                if (head){
                    if(searchNode(head, data)){
                    cout << "Data ditemukan\n";
                    } else {
                        cout << "Data tidak ditemukan\n";
                    } 
                    break;
                }
                else {
                    cout << "Data kosong\n";
                }
                
            case 4:
                if(head) printList(head);
                else cout << "Data kosong\n";
                break;
            case 5:
                return 0;
            default:
                cout << "Pilihan tidak diketahui\n";
        }
    }
}
