#include <stdio.h>

int main() {
  // Deklarasi variabel
  float inputKm, kmToMeter, kmToCenti;

  // Header
  printf("=====================================\n");
  printf("\tPROGRAM KONVERSI JARAK\n");
  printf("=====================================\n");

  // Pesan selamat datang
  printf("\nSelamat datang di Program Konversi Jarak!\n");

  printf("\nTekan enter untuk memulai program...");
  getchar();

  // Input user
  printf("\n------------------------------------\n");
  printf("Masukkan jarak dalam satuan KM: ");
  scanf("%f", &inputKm);
  printf("------------------------------------\n");


  // Konversi
  kmToMeter = (inputKm * 1000);
  kmToCenti = (inputKm * 100000);

  // Membersihkan buffer stdin
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