#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define MaxStack 10

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

// Prosedur pengurutan metode Quick Sort Non-Rekursif
void QuickSortNonRekursif() {
    struct tump {
        int Kiri;
        int Kanan;
    } Tumpukan[MaxStack];

    int i, j, L, R, x, ujung = 1;
    Tumpukan[1].Kiri = 0;
    Tumpukan[1].Kanan = MAX - 1;

    while (ujung != 0) {
        L = Tumpukan[ujung].Kiri;
        R = Tumpukan[ujung].Kanan;
        ujung--;

        while (R > L) {
            i = L;
            j = R;
            x = Data[(L + R) / 2];

            while (i <= j) {
                while (Data[i] < x) {
                    i++;
                    jumlahPerbandingan++; // Menambahkan perbandingan
                }
                while (x < Data[j]) {
                    j--;
                    jumlahPerbandingan++; // Menambahkan perbandingan
                }
                if (i <= j) {
                    Tukar(&Data[i], &Data[j]);
                    i++;
                    j--;
                }
            }

            if (L < i) {
                ujung++;
                Tumpukan[ujung].Kiri = i;
                Tumpukan[ujung].Kanan = R;
            }
            R = j;

            // Mencetak isi array setelah setiap iterasi
            printf("Iterasi dengan jarak %d: ", Tumpukan[ujung].Kanan - Tumpukan[ujung].Kiri);
            for (int k = 0; k < MAX; k++) {
                printf("%d ", Data[k]);
            }
            printf("\n");
        }
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
    QuickSortNonRekursif();
    // Data setelah terurut
    printf("\nDATA SETELAH TERURUT\n");
    for (i = 0; i < MAX; i++) {
        printf("Data ke %d : %d\n", i, Data[i]);
    }
    // Menampilkan jumlah perbandingan dan pergeseran
    printf("\nJumlah perbandingan: %d\n", jumlahPerbandingan);
    printf("Jumlah pergeseran: %d\n", jumlahPergeseran);
}
