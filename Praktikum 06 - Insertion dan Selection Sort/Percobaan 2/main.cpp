//Percobaan 2 : Implementasi pengurutan dengan metode penyisipan biner (binary insertion sort)
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int Data[MAX];
int jumlahPerbandingan = 0;
int jumlahPergeseran = 0;

// Fungsi pengurutan penyisipan biner
void BinaryInsertSort() {
    int i, j, l, r, m, x;
    for (i = 1; i < MAX; i++) {
        x = Data[i];
        l = 0;
        r = i - 1;
        while (l <= r) {
            jumlahPerbandingan++; // Menambahkan perbandingan
            m = (l + r) / 2;
            if (x < Data[m]) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        for (j = i - 1; j >= l; j--) {
            Data[j + 1] = Data[j];
            jumlahPergeseran++; // Menambahkan pergeseran
        }
        Data[l] = x;
        // Mencetak isi array setelah setiap penyisipan
        printf("Iterasi %d: ", i);
        for (int k = 0; k < MAX; k++) {
            printf("%d ", Data[k]);
        }
        printf("\n");
    }
}

int main() {
    int i;
    srand(0);
    // Membangkitkan bilangan acak
    printf("DATA SEBELUM TERURUT\n");
    for (i = 0; i < MAX; i++) {
        Data[i] = (int) rand() / 1000 + 1;
        printf("Data ke %d : %d\n", i, Data[i]);
    }
    BinaryInsertSort();
    // Data setelah terurut
    printf("\nDATA SETELAH TERURUT\n");
    for (i = 0; i < MAX; i++) {
        printf("Data ke %d : %d\n", i, Data[i]);
    }
    // Menampilkan jumlah perbandingan dan pergeseran
    printf("\nJumlah perbandingan: %d\n", jumlahPerbandingan);
    printf("Jumlah pergeseran: %d\n", jumlahPergeseran);
}
