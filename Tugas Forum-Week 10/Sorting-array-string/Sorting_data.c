/*
NIM         : 2702350592
NAMA        : Ihsan Amri Muyassar
KELAS       : JCCA
MATAKULIAH  : Algoritma dan Pemrograman
DOSEN       : Ir. Tri Asih Budiono, M.I.T.
*/

#include <stdio.h>
#include <string.h>

// Fungsi untuk menukar string
void swap(char a[], char b[]) {
    char temp[20];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}


// Fungsi untuk melakukan pengurutan dan tukar menukar 
int partition(char nama[][20], int leftIdx, int rightIdx, int ascending) {
    char pivot[20];
    strcpy(pivot, nama[rightIdx]); // Memilih pivot sebagai elemen terakhir dari array yang akan diurutkan
    int current = leftIdx - 1; // Index current selalu dimulai dari index paling kiri dikurangi satu
    int i = leftIdx;
    
    // Membandingkan setiap elemen dengan pivot
    for (i; i < rightIdx; i++) {
        // Ternary operator jika user memilih 1 maka akan mengurutkan dari abjad A-Z
        // Ternary operator jika user memilih 0 maka akan mengurutkan dari abjad Z-A
        // Jika nama[i] lebih kecil dari pivot maka posisi current akan bertambah satu (ke kanan) dan elemen nama[i] akan ditukar dengan nama[current]
        if (ascending ? (strcmp(nama[i], pivot) < 0) : (strcmp(nama[i], pivot) > 0)) {
            current++;
            swap(nama[i], nama[current]);
        }
    }

    // Setelah membandingkan setiap elemen dengan pivot, elemen paling kanan dari array (Pivot) yang akan diurutkan akan ditukar dengan nama[current + 1]
    swap(nama[rightIdx], nama[current + 1]);

    return (current + 1); // Mid index
}

// Fungsi pengurutan dengan Quick Sort
void quickSort(char nama[][20], int leftIdx, int rightIdx, int ascending) {
    if (leftIdx < rightIdx) { // Melakukan sorting jika setidaknya ada dua string yang bisa dibandingkan
        int midIdx = partition(nama, leftIdx, rightIdx, ascending);

        quickSort(nama, leftIdx, (midIdx - 1), ascending); // Sorting array kiri sebelum mid index
        quickSort(nama, (midIdx + 1), rightIdx, ascending); // Sorting array kanan setelah mid index
    }
}

int main() {
    // Deklarasi variabel i untuk digunakan pada for loop (untuk menghindari error di devcpp)
    int i = 0;
    // Array string nama
    char nama[10][20] = {
        "Fahmi Harahap", "Icha Nurlisa", "Agus Gumilang", "Zelda Zuraida",
        "Felix Halim", "Deddy Corbuizer", "Hassan Makmur", "Makmun Sukur",
        "Bella Christie", "Chelshe Love"
    };

    // Header
    printf("==============================\n");
    printf("     SORTING DATA STRING\n");
    printf("==============================\n\n");

    // Data nama sebelum di urutkan
    printf("Before sorted:\n");
    for (i; i < 10; i++) {
        printf(" %2d. %s\n", i + 1, nama[i]);
    }
    printf("\n");

    // Input user untuk memilih sorting secara ascending atau descending
    int ascending = 0;
    while (1) {
        printf("Sort in ascending (1) or descending (0): ");
        if (scanf("%d", &ascending) != 1 || (ascending != 0 && ascending != 1)) {
            printf("INVALID INPUT! (1 for ascending, 0 for descending)\n");
            while (getchar() != '\n');
        } else {
            break;
        }
    }

    // Memanggil fungsi quick sort untuk mengurutkan data
    // Karena perhitungan index dimulai dari 0, maka index dari data paling kanan adalah 10 - 1 = 9
    quickSort(nama, 0, 9, ascending);

    // Data nama setelah di urutkan
    printf("\nAfter sorted:\n");
    i = 0; 
    /* Atur ulang i menjadi nol karena sebelumnya sudah digunakan pada loop pertama, 
    jika tidak di set ke 0 lagi maka i saat ini bernilai 10 dan for loop dibawah tidak akan dijalankan. */
    for (i; i < 10; i++) {
        printf(" %2d. %s\n", i + 1, nama[i]);
    }
    printf("\n");

    return 0;
}
