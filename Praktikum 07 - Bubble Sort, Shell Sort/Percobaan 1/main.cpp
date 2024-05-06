
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int Data[MAX];
int jumlahPerbandingan = 0;
int jumlahPergeseran = 0;

// Prosedur menukar data
void Tukar (int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    jumlahPergeseran++; // Menambahkan pergeseran setiap kali tukar dilakukan
}

// Prosedur pengurutan metode gelembung
void BubbleSort() {
    int i, j;
    for(i = 1; i < MAX; i++) { // Perbaikan: loop harus berjalan dari 1 hingga MAX
        for(j = MAX - 1; j >= i; j--) {
            jumlahPerbandingan++; // Menambahkan perbandingan
            if(Data[j - 1] > Data[j]) {
                Tukar(&Data[j - 1], &Data[j]);
            }
        }
        // Mencetak isi array setelah setiap iterasi
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
        Data[i] = (int) rand() / 1000 + 1;
        printf("Data ke %d : %d\n", i, Data[i]);
    }
    BubbleSort();
    // Data setelah terurut
    printf("\nDATA SETELAH TERURUT\n");
    for(i = 0; i < MAX; i++) {
        printf("Data ke %d : %d\n", i, Data[i]);
    }
    // Menampilkan jumlah perbandingan dan pergeseran
    printf("\nJumlah perbandingan: %d\n", jumlahPerbandingan);
    printf("Jumlah pergeseran: %d\n", jumlahPergeseran);
}
