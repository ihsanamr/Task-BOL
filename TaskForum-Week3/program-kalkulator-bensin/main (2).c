/*
Nama - NIM: Ihsan Amri Muyassar - 2702350592

Referensi: https://www.geeksforgeeks.org/fabs-function-in-c/
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

int main () {
  double bensin_pertamax_konstan = 15.00;
  double bensin_pertamax_stopngo = 10.00;
  double bensin_pertalite_konstan = 12.00;
  double bensin_pertalite_stopngo = 8.00;
  double bensin_awal, jarak_tempuh, konsumsi_bahan_bakar, bensin_akhir, bensin_akhir_absolut;
  char mode_menyopir[25], jenis_bensin[25];
  int jenis_bensin_valid = 0, bensin_awal_valid = 0, jarak_tempuh_valid = 0, mode_menyopir_valid = 0;

  printf("======================================================\n");
  printf("KALKULATOR KONSUMSI BAHAN BAKAR PERTAMAX DAN PERTALITE\n");
  printf("======================================================\n\n");

  // Input jenis bensin
  while (!jenis_bensin_valid) {
    printf("Pilih jenis bensin (Pertamax/Pertalite): ");
    scanf("%s", jenis_bensin);
    if (strcmp(jenis_bensin, "Pertamax") == 0 || strcmp(jenis_bensin, "pertamax") == 0 || strcmp(jenis_bensin, "pertalite") == 0 || strcmp(jenis_bensin, "Pertalite") == 0){
      jenis_bensin_valid = 1;
    } else {
      printf("\nInput tidak valid. Silakan masukkan jenis bensin yang valid (Pertamax/Pertalite)\n\n");
    }
  }

  // Input bensin awal
  while (!bensin_awal_valid) {
    printf("Masukkan jumlah liter bensin awal: ");
    if (scanf("%lf", &bensin_awal) == 1 && bensin_awal >= 0) {
      bensin_awal_valid = 1;
    } else {
      printf("\nInput tidak valid. Harap masukkan angka positif untuk jumlah liter bensin awal\n\n");
      while (getchar() != '\n');
    }
  }
  
  // Input jarak tempuh
  while (!jarak_tempuh_valid) {
    printf("Masukkan jarak yang ingin ditempuh (KM): ");
    if (scanf("%lf", &jarak_tempuh) == 1 && jarak_tempuh >= 0) {
      jarak_tempuh_valid = 1;
    } else {
      printf("\nInput tidak valid. Harap masukkan angka positif untuk jarak yang ingin ditempuh\n\n");
      while (getchar() != '\n');
    }
  }
  
  // Input mode menyopir
  while (!mode_menyopir_valid) {
    printf("Pilih mode menyopir (Konstan/luar_kota)/(Stop&Go/dalam_kota): ");
    scanf("%s", mode_menyopir);
    if (strcmp(mode_menyopir, "Konstan") == 0 || strcmp(mode_menyopir, "konstan") == 0 || strcmp(mode_menyopir, "luar_kota") == 0 || strcmp(mode_menyopir, "dalam_kota") == 0 || strcmp(mode_menyopir, "Stop&Go") == 0 || strcmp(mode_menyopir, "stop&go") == 0 || strcmp(mode_menyopir, "stopngo") == 0 || strcmp(mode_menyopir, "Stopngo") == 0 || strcmp(mode_menyopir, "luarkota") == 0 || strcmp(mode_menyopir, "dalamkota") == 0) {
      mode_menyopir_valid = 1;
    } else {
      printf("\nInput tidak valid. Silakan pilih mode menyopir yang valid (Konstan/luar_kota)/(Stop&Go/dalam_kota)\n\n");
    }
  }
  
  // Perhitungan bensin
  if (strcmp(jenis_bensin, "Pertamax") == 0 || strcmp(jenis_bensin, "pertamax") == 0) {
    if (strcmp(mode_menyopir, "Konstan") == 0 || strcmp(mode_menyopir, "konstan") == 0 || strcmp(mode_menyopir, "luar_kota") == 0 || strcmp(mode_menyopir, "luarkkota") == 0) {
      konsumsi_bahan_bakar = jarak_tempuh / bensin_pertamax_konstan;
    } else {
      konsumsi_bahan_bakar = jarak_tempuh / bensin_pertamax_stopngo;
    }
  } else {
    if (strcmp(mode_menyopir, "Konstan") == 0 || strcmp(mode_menyopir, "konstan") == 0 || strcmp(mode_menyopir, "luar_kota") == 0 || strcmp(mode_menyopir, "luarkota") == 0) {
      konsumsi_bahan_bakar = jarak_tempuh / bensin_pertalite_konstan;
    } else {
      konsumsi_bahan_bakar = jarak_tempuh / bensin_pertalite_stopngo;
    }
  }

  // Menghitung bensin akhir
  bensin_akhir = bensin_awal - konsumsi_bahan_bakar;
  bensin_akhir_absolut = fabs(bensin_akhir);
  
  // Output hasil perhitungan
  printf("\n=================================================================================\n");
  printf("Bensin yang diperlukan untuk menempuh jarak %.2lf KM adalah sebanyak %.2lf liter\n", jarak_tempuh, konsumsi_bahan_bakar);
  printf("--------------------------------------------------------------------------------\n");
  if (bensin_akhir <= 0) {
    printf("Bensin tidak cukup. Anda perlu bensin tambahan sebanyak %.2lf liter untuk menempuh jarak %.2lf KM.\n", bensin_akhir_absolut, jarak_tempuh);
  } else {
    printf("Sisa bensin setelah perjalanan sebanyak %.2lf liter\n", bensin_akhir);
  }
  printf("=================================================================================\n");
  
  
  return 0;
}
