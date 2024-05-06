#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int Data[MAX];
int temp[MAX];
int jumlahPerbandingan = 0;
int jumlahPergeseran = 0;

// Prosedur merge sort
void merge(int Data[], int temp[], int kiri, int tengah, int kanan) {
    int i, left_end, num_elements, tmp_pos;
    left_end = tengah - 1;
    tmp_pos = kiri;
    num_elements = kanan - kiri + 1;

    // Menggabungkan dua subarray menjadi satu subarray terurut
    while ((kiri <= left_end) && (tengah <= kanan)) {
        jumlahPerbandingan++;
        if (Data[kiri] <= Data[tengah]) {
            temp[tmp_pos] = Data[kiri];
            tmp_pos = tmp_pos + 1;
            kiri = kiri + 1;
        } else {
            temp[tmp_pos] = Data[tengah];
            tmp_pos = tmp_pos + 1;
            tengah = tengah + 1;
        }
    }

    // Menyalin sisa elemen dari subarray kiri, jika ada
    while (kiri <= left_end) {
        temp[tmp_pos] = Data[kiri];
        kiri = kiri + 1;
        tmp_pos = tmp_pos + 1;
        jumlahPergeseran++;
    }

    // Menyalin sisa elemen dari subarray kanan, jika ada
    while (tengah <= kanan) {
        temp[tmp_pos] = Data[tengah];
        tengah = tengah + 1;
        tmp_pos = tmp_pos + 1;
        jumlahPergeseran++;
    }

    // Menyalin elemen terurut kembali ke array Data
    for (i = 0; i < num_elements; i++) {
        Data[kanan] = temp[kanan];
        kanan = kanan - 1;
        jumlahPergeseran++;
    }
}

// Prosedur rekursif untuk merge sort
void m_sort(int Data[], int temp[], int kiri, int kanan) {
    int tengah;
    if (kanan > kiri) {
        tengah = (kanan + kiri) / 2;
        m_sort(Data, temp, kiri, tengah);
        m_sort(Data, temp, tengah + 1, kanan);
        merge(Data, temp, kiri, tengah + 1, kanan);
    }
}

// Fungsi utama merge sort
void mergeSort(int Data[], int temp[], int array_size) {
    m_sort(Data, temp, 0, array_size - 1);
}

int main() {
    int i;
    srand(0);

    // Membangkitkan bilangan acak
    printf("DATA SEBELUM TERURUT: ");
    for (i = 0; i < MAX; i++) {
        Data[i] = rand() / 1000 + 1;
        printf("%d ", Data[i]);
    }
    printf("\n");

    mergeSort(Data, temp, MAX);

    // Data setelah terurut
    printf("DATA SETELAH TERURUT: ");
    for (i = 0; i < MAX; i++) {
        printf("%d ", Data[i]);
    }
    printf("\n");

    // Menampilkan jumlah perbandingan dan pergeseran
    printf("Jumlah perbandingan: %d\n", jumlahPerbandingan);
    printf("Jumlah pergeseran: %d\n", jumlahPergeseran);
}
