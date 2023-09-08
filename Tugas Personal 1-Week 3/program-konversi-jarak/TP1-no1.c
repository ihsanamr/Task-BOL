/*
Tugas Personal 1 - Mata Kuliah Algoritma dan Pemrograman
Nama - NIM : Ihsan Amri Muyassar - 2702350592
*/

#include <stdio.h>
#include <stdlib.h>

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
    // Membuat array of character sebagai penampung sementara
    char inputSementara[100]; 
    printf("Masukkan jarak dalam satuan KM (Tanpa spasi): ");
    while(1) {
      scanf("%s", inputSementara);
      int valid = 1;
      // Memeriksa apakah input hanya berisi angka
      for (int i = 0; inputSementara[i] != '\0'; i++) {
          if (!isdigit(inputSementara[i])) {
              valid = 0;
              break;
          }
      }
      if (valid) {
          // Konversi string menjadi double
          inputKm = strtod(inputSementara, NULL);
          if (inputKm < 0) {
              printf("Input tidak valid. Harap masukkan angka positif: ");
          } else {
              break;
          }
      } else {
          printf("\nInput tidak valid. Harap masukkan angka positif: ");
      }
    }


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
