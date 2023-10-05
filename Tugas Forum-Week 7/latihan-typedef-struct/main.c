#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// STRUCT TANPA TYPDEF
struct mahasiswa {
    char nama[50];
    char nim[50];
};

// STRUCT MENGGUNAKAN TYPDEF
typedef struct nilai {
    int nilaiTugas;
    int nilaiUjian;
} nilaiMahasiswa;

int main() {
    // INISIALISASI STRUCT TANPA TYPDEF
    struct mahasiswa mahasiswa1;
    strcpy(mahasiswa1.nama, "Ihsan Amri");
    strcpy(mahasiswa1.nim, "2702350592");

    // INISIALISASI STRUCT MENGGUNAKAN TYPDEF
    nilaiMahasiswa nilaiMhs1;
    nilaiMhs1.nilaiTugas = 98;
    nilaiMhs1.nilaiUjian = 98;

    printf("-----Data Mahasiswa 1-----\n");
    printf("Nama\t\t: %s\n", mahasiswa1.nama);
    printf("NIM\t\t: %s\n", mahasiswa1.nim);
    printf("Nilai Tugas\t: %d\n", nilaiMhs1.nilaiTugas);
    printf("Nilai Ujian\t: %d\n", nilaiMhs1.nilaiUjian);

    return 0;
}