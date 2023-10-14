#include <stdio.h>
#include <stdlib.h>

// Function prototype untuk alokasi memori statis
void alokasiMemoriStatis(int data[], int SIZE);
// Function prototype untuk alokasi memori dinamis
void alokasiMemoriDinamis();

int main() {
    int SIZE = 9;
    int data[SIZE];

    // Memanggil fungsi untuk alokasi memori statis
    alokasiMemoriStatis(data, SIZE);

    // Memanggil fungsi untuk alokasi memori dinamis
    alokasiMemoriDinamis();

    return 0;
}

// Function definition untuk alokasi memori statis
void alokasiMemoriStatis(int data[], int SIZE) {
    // Entry data secara statis
    for (int i = 0; i < SIZE; i++) {
        data[i] = i + 1;
    }

    // Menampilkan semua data
    printf("Data (Alokasi Statis):\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

// Function definition untuk alokasi memori dinamis
void alokasiMemoriDinamis() {
    int sizeDynamic = 9;
    int* dataDynamic;
    dataDynamic = (int*) malloc(sizeDynamic * sizeof(int));

    if (dataDynamic == NULL) {
        printf("Gagal mengalokasikan memori.\n");
        return;
    }

    // Entry data secara dinamis
    for (int i = 0; i < sizeDynamic; i++) {
        dataDynamic[i] = i + 1;
    }

    // Menampilkan semua data
    printf("Data (Alokasi Dinamis):\n");
    for (int i = 0; i < sizeDynamic; i++) {
        printf("%d ", dataDynamic[i]);
    }
    printf("\n");

    free(dataDynamic);
}
