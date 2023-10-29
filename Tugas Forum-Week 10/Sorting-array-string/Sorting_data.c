#include <stdio.h>
#include <string.h>

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

    // Membandingkan setiap elemen dengan pivot
    for (int i = leftIdx; i < rightIdx; i++) {
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

void quickSort(char nama[][20], int leftIdx, int rightIdx, int ascending) {
    if (leftIdx < rightIdx) { // Melakukan sorting jika setidaknya ada dua string yang bisa dibandingkan
        int midIdx = partition(nama, leftIdx, rightIdx, ascending);

        quickSort(nama, leftIdx, (midIdx - 1), ascending); // Sorting array kiri sebelum mid index
        quickSort(nama, (midIdx + 1), rightIdx, ascending); // Sorting array kanan setelah mid index
    }
}

int main() {
    char nama[10][20] = {
        "Fahmi Harahap", "Icha Nurlisa", "Agus Gumilang", "Zelda Zuraida",
        "Felix Halim", "Deddy Corbuizer", "Hassan Makmur", "Makmun Sukur",
        "Bella Christie", "Chelshe Love"
    };

    printf("==============================\n");
    printf("     SORTING DATA STRING\n");
    printf("==============================\n\n");

    printf("Before sorted:\n");
    for (int i = 0; i < 10; i++) {
        printf(" %2d. %s\n", i + 1, nama[i]);
    }
    printf("\n");

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

    quickSort(nama, 0, 9, ascending);

    printf("\nAfter sorted:\n");
    for (int i = 0; i < 10; i++) {
        printf(" %2d. %s\n", i + 1, nama[i]);
    }
    printf("\n");

    return 0;
}
