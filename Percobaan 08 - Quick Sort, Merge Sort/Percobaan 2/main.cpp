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

// Prosedur pengurutan metode Quick Sort Rekursif
void QuickSortRekursif(int L, int R) {
    int i, j, x;
    x = Data[(L+R)/2];
    i = L;
    j = R;
    while (i <= j) {
        while (Data[i] < x) {
            i++;
            jumlahPerbandingan++; // Menambahkan perbandingan
        }
        while (Data[j] > x) {
            j--;
            jumlahPerbandingan++; // Menambahkan perbandingan
        }
        if (i <= j) {
            Tukar(&Data[i], &Data[j]);
            i++;
            j--;
        }
    }
    if (L < j) {
        QuickSortRekursif(L, j);
    }
    if (i < R) {
        QuickSortRekursif(i, R);
    }
}

void CetakData(int data[], int size) {
    for (int k = 0; k < size; k++) {
        printf("%d ", data[k]);
    }
    printf("\n");
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
    QuickSortRekursif(0, MAX-1);
    // Data setelah terurut
    printf("\nDATA SETELAH TERURUT\n");
    CetakData(Data, MAX);
    // Menampilkan jumlah perbandingan dan pergeseran
    printf("\nJumlah perbandingan: %d\n", jumlahPerbandingan);
    printf("Jumlah pergeseran: %d\n", jumlahPergeseran);
}

