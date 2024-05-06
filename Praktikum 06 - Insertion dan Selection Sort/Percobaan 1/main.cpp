//Percobaan 1 : Implementasi pengurutan dengan metode penyisipan langsung (straight insertion sort)
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int Data[MAX];
int jumlahPerbandingan = 0;
int jumlahPergeseran = 0;

// Fungsi pengurutan penyisipan langsung
void StraightInsertSort() {
    int i, j, x;
    for(i = 1; i < MAX; i++) {
        x = Data[i];
        j = i - 1;
        while (j >= 0 && x < Data[j]) {
            jumlahPerbandingan++; // Menambahkan perbandingan
            Data[j + 1] = Data[j];
            jumlahPergeseran++; // Menambahkan pergeseran
            j--;
        }
        Data[j + 1] = x;
        // Mencetak isi array setelah setiap penyisipan
        printf("Iterasi %d: ", i);
        for(int k = 0; k < MAX; k++) {
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
    for(i = 0; i < MAX; i++) {
        Data[i] = (int) rand()/1000 + 1;
        printf("Data ke %d : %d\n", i, Data[i]);
    }
    StraightInsertSort();
    // Data setelah terurut
    printf("\nDATA SETELAH TERURUT\n");
    for(i = 0; i < MAX; i++) {
        printf("Data ke %d : %d\n", i, Data[i]);
    }
    // Menampilkan jumlah perbandingan dan pergeseran
    printf("\nJumlah perbandingan: %d\n", jumlahPerbandingan);
    printf("Jumlah pergeseran: %d\n", jumlahPergeseran);
}
