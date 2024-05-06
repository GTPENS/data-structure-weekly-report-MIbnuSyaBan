//Percobaan 3 : Implementasi pengurutan dengan metode seleksi (selection sort)
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int Data[MAX];
int jumlahPerbandingan = 0;
int jumlahPergeseran = 0;

// Fungsi pertukaran bilangan
void Tukar (int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    jumlahPergeseran++; // Menambahkan pergeseran setiap kali tukar dilakukan
}

// Fungsi pengurutan Selection Sort
void SelectionSort() {
    int i, j, k;
    for(i = 0; i < MAX - 1; i++) {
        k = i;
        for (j = i + 1; j < MAX; j++) {
            jumlahPerbandingan++; // Menambahkan perbandingan
            if(Data[k] > Data[j]) {
                k = j;
            }
        }
        Tukar(&Data[i], &Data[k]);
        // Mencetak isi array setelah setiap iterasi
        printf("Iterasi %d: ", i);
        for(int l = 0; l < MAX; l++) {
            printf("%d ", Data[l]);
        }
        printf("\n");
    }
}

int main() {
    int i;
    srand(0);
    // Membangkitkan bilangan acak
    printf("DATA SEBELUM TERURUT\n");
    for(i = 0; i < MAX; i++) {
        Data[i] = (int) rand() / 1000 + 1;
        printf("Data ke %d : %d\n", i, Data[i]);
    }
    SelectionSort();
    // Data setelah terurut
    printf("\nDATA SETELAH TERURUT\n");
    for(i = 0; i < MAX; i++) {
        printf("Data ke %d : %d\n", i, Data[i]);
    }
    // Menampilkan jumlah perbandingan dan pergeseran
    printf("\nJumlah perbandingan: %d\n", jumlahPerbandingan);
    printf("Jumlah pergeseran: %d\n", jumlahPergeseran);
}
