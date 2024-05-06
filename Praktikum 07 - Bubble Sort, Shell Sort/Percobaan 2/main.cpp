#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

// Prosedur pengurutan metode Shell
void ShellSort() {
    int Jarak, i, j;
    bool Sudah;
    Jarak = MAX;
    while(Jarak > 1) {
        Jarak = Jarak / 2;
        Sudah = false;
        while(!Sudah) {
            Sudah = true;
            for(j = 0; j < MAX - Jarak; j++) {
                i = j + Jarak;
                jumlahPerbandingan++; // Menambahkan perbandingan
                if(Data[j] > Data[i]) {
                    Tukar(&Data[j], &Data[i]);
                    Sudah = false;
                }
            }
        }
        // Mencetak isi array setelah setiap iterasi
        printf("Setelah jarak %d: ", Jarak);
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
    ShellSort();
    // Data setelah terurut
    printf("\nDATA SETELAH TERURUT\n");
    for(i = 0; i < MAX; i++) {
        printf("Data ke %d : %d\n", i, Data[i]);
    }
    // Menampilkan jumlah perbandingan dan pergeseran
    printf("\nJumlah perbandingan: %d\n", jumlahPerbandingan);
    printf("Jumlah pergeseran: %d\n", jumlahPergeseran);
}
