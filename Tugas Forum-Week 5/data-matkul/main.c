#include <stdio.h>

int main () {
  // Deklarasi Variabel
  int jumlah_mata_kuliah = 2;
  char matkul[2][50] = {"Algoritma & Pemrograman", "Matematika Diskrit & Aljabar Linear"};
  char kode_matkul[2][50] = {"COMP6112036", "MATH6184036"};
  int jumlah_sks[2] = {4, 6};
  char grade[2] = {'A', 'B'};

  printf("Mata kuliah yang saya ambil adalah:\n");
  for (int i = 0; i < jumlah_mata_kuliah; ++i) {
    printf("%d. %s (%s)\n", i + 1, kode_matkul[i], matkul[i]);
    printf("   Jumlah SKS: %d\n", jumlah_sks[i]);
    printf("   Nilai: %c\n", grade[i]);
  }

  return 0;
}
