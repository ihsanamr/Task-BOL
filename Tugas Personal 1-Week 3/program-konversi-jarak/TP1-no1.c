/*
Tugas Personal 1 - Mata Kuliah Algoritma dan Pemrograman
Nama - NIM : Ihsan Amri Muyassar - 2702350592
*/

#include <stdio.h>

int main() {
  // Deklarasi variabel
  float inputKm, kmToMeter, kmToCenti;

  // Header
  printf("=====================================\n");
  printf("\tPROGRAM KONVERSI JARAK\n");
  printf("=====================================\n");
  printf("\nSelamat datang di Program Konversi Jarak!\n");

  printf("\nTekan enter untuk memulai program...");
  getchar();

  // Input user
  printf("\n-----------------------------------------------\n");
  do {
  printf("Masukkan jarak dalam satuan KM: ");
    if (scanf("%f", &inputKm) != 1 || inputKm < 0) {
      printf("Input tidak valid, harap masukkan angka positif saja.\n");
      while (getchar() != '\n'); // Membersihkan buffer
    } else {
      break;
    }
  } while (1);


  // Konversi
  kmToMeter = (inputKm * 1000);
  kmToCenti = (inputKm * 100000);

  // Membersihkan buffer
  while (getchar() != '\n');

  // Output
  printf("\nTekan enter untuk melihat hasil konversi...\n");
  getchar();
  printf("-----------------------------------------------\n");
  printf("Hasil Konversi:\n");
  printf("%.2f KM sama dengan %d meter\n", inputKm, (int)kmToMeter);
  printf("%.2f KM sama dengan %d centimeter\n", inputKm, (int)kmToCenti);
  printf("-----------------------------------------------\n");

  return 0;
}
