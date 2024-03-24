## Nama    : Muhammad Ibnu Sya'Ban
## NRP     : 5223600020
## Kelas   : 1 GT-A


# Praktikum 03 : Double Linked List

## Modul Praktikum

D. PERCOBAAN
1. Implementasikan operasi dasar Double linked list : Menyisipkan sebagai simpul ujung(awal) dari linked list.
2. Implementasikan operasi dasar Double linked list : Membaca atau menampilkan
3. Implementasikan operasi dasar Double linked list : Mencari sebuah simpul tertentu. Tambahkan kondisi jika yang dicari adalah data yang paling depan.
4. Implementasikan operasi dasar Double linked list : Menghapus simpul tertentu. Tambahkan kondisi jika yang dihapus adalah data yang paling depan atau data yang paling terakhir.
5. Gabungkan semua operasi di atas dalam sebuah Menu Pilihan.

### Pembahasan 
#### 1. Menyisipkan sebagai simpul ujung(awal) dari linked list.
```cpp

//...

void insertNodeAtHead(Node** head, int data){
    Node* newNode = createNode(data);
    newNode->next = *head;
    if(*head != NULL){
        (*head)->prev = newNode;
    }
    *head = newNode;
}

//...

```
#### 2. Membaca atau menampilkan
```cpp

//...
void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

//...

```
#### 3. Mencari sebuah simpul tertentu. 
```cpp

//...
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

//...

```
#### Tambahkan kondisi jika yang dicari adalah data yang paling depan.
```cpp

//...
case 3:
    cout << "Masukkan data yang dicari : ";
    data = stringToInteger();
    if (head){
        // Pengecekan jika data yang di maksud adalah head
        if (head->data = data) cout << "Data ditemukan\n";
        else if(searchNode(head, data)){
            cout << "Data ditemukan\n";
        } else {
            cout << "Data tidak ditemukan\n";
        } 
    } else {
        cout << "Data kosong\n";
    }
    break;

//...

```
#### 4.Menghapus simpul tertentu.
```cpp

//...
void deleteNode(Node** head, int data){
    Node* temp = searchNode(*head, data);
    if(temp == NULL) return; // Node tidak ditemukan

    if(temp->prev != NULL){
        temp->prev->next = temp->next;
    } else {
        // Menghapus node paling depan
        *head = temp->next;
    }
    if(temp->next != NULL){
        temp->next->prev = temp->prev;
    }
    delete temp;// Membebaskan memory 
}

//...

```
#### 5. Gabungkan semua operasi di atas dalam sebuah Menu Pilihan.
```cpp

//...
while(true){
        cout << "Menu:\n1. Menyisipkan sebagai simpul ujung awal\n2. Menyisipkan sebagai simpul terakhir\n3. Mencari sebuah simpul tertentu\n4. Menghapus simpul tertentu\n5. Menampilkan data\n6. Keluar\n";
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
                    if (head->data = data) cout << "Data ditemukan\n";
                    else if(searchNode(head, data)){
                        cout << "Data ditemukan\n";
                    } else {
                        cout << "Data tidak ditemukan\n";
                    } 
                } else {
                    cout << "Data kosong\n";
                }
                break;
            case 4:
                cout << "Masukkan data yang akan dihapus : ";
                data = stringToInteger();
                deleteNode(&head, data);
                break;
            case 5:
                if(head) printList(head);
                else cout << "Data kosong\n";
                break;
            case 6:
               freeList(&head);// Membebaskan memeory dari semua node yang telah dibuat
               return 0;
            default:
                cout << "Pilihan tidak diketahui\n";
        }
    }

//...

```