/*
Nama: Ihsan Amri Muyassar
NIM: 2702350592
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


// Fungsi untuk membersihkan layar console
void clearScreen() {
    #ifdef _WIN32
    system("cls");
    #else
    printf("\033[H\033[J");
    #endif
}


// Fungsi untuk mengecek input user apakah dalam bentuk angka yang valid
int apakahNomor(const char *angka) {
  // Tidak menerima input kosong
  if (strlen(angka) == 0) {
    return 0;
  }

  // Menerima input angka negatif untuk elemen matriks
  int indeksAwal = 0;
  if (angka[0] == '-') {
    indeksAwal = 1;
  }

  for (int i = indeksAwal; i < strlen(angka) - 1; i++) {
    if (angka[i] < '0' || angka[i] > '9') {
      return 0;
    }
  }
  return 1;
}


int main() {
  int baris_matriks1, kolom_matriks1, baris_matriks2, kolom_matriks2;
  char input[100];
  
  printf("===================================\n");
  printf("\tPROGRAM PERKALIAN MATRIKS\n");
  printf("===================================\n\n");

  printf("Tekan enter untuk memulai program....");
  getchar();
  printf("\n");

  while (1) {
    // Input jumlah baris dan kolom matriks pertama
    printf("Masukkan jumlah baris matriks pertama\t\t: ");
    while (1) {
      fgets(input, sizeof(input), stdin);
      input[strcspn(input, "\n")] = '\0';
      if (apakahNomor(input) && atoi(input) >= 0) {
        baris_matriks1 = atoi(input);
        break;
      } else {
        printf("\033[1;31mInput tidak valid. Harap masukkan angka\t\t:\033[0m ");
      }
    }

    printf("Masukkan jumlah kolom matriks pertama\t\t: ");
    while (1) {
      fgets(input, sizeof(input), stdin);
      input[strcspn(input, "\n")] = '\0';
      if (apakahNomor(input) && atoi(input) >= 0) {
        kolom_matriks1 = atoi(input);
        break;
      } else {
        printf("\033[1;31mInput tidak valid. Harap masukkan angka\t\t:\033[0m ");
      }
    }

    // Input jumlah baris dan kolom matriks kedua
    printf("Masukkan jumlah baris matriks kedua\t\t\t: ");
    while (1) {
      fgets(input, sizeof(input), stdin);
      input[strcspn(input, "\n")] = '\0';
      if (apakahNomor(input)) {
        baris_matriks2 = atoi(input);
        break;
      } else {
        printf("\033[1;31mInput tidak valid. Harap masukkan angka\t\t:\033[0m ");
      }
    }

    printf("Masukkan jumlah kolom matriks kedua\t\t\t: ");
    while (1) {
      fgets(input, sizeof(input), stdin);
      input[strcspn(input, "\n")] = '\0';
      if (apakahNomor(input)) {
        kolom_matriks2 = atoi(input);
        break;
      } else {
        printf("\033[1;31mInput tidak valid. Harap masukkan angka\t\t:\033[0m ");
      }
    }

    // Periksa apakah perkalian matriks dapat dilakukan
    if (kolom_matriks1 != baris_matriks2) {
      printf("\n\033[1;31mPerkalian matriks tidak dapat dilakukan. Kolom matriks pertama harus sama dengan baris matriks kedua.\033[0m\n\n");
      printf("Tekan Enter untuk memulai ulang...\n");
      getchar();
      clearScreen();
    } else {
      break; /*Jika kondisi terpenuhi, keluar dari loop dan lanjutkan dengan input elemen matriks*/
    }
  }

  // Input elemen-elemen matriks pertama
  printf("\nMasukkan elemen-elemen matriks pertama:\n");
  int matriks1[baris_matriks1][kolom_matriks1];
  for (int i = 0; i < baris_matriks1; i++) {
      for (int j = 0; j < kolom_matriks1; j++) {
          while (1) {
              printf("Masukkan elemen baris %d kolom %d: ", i + 1, j + 1);
              fgets(input, sizeof(input), stdin);
              input[strcspn(input, "\n")] = '\0';
              if (apakahNomor(input)) {
                  matriks1[i][j] = atoi(input);
                  break;
              } else {
                  printf("\033[1;31m------------------------------------------------\n");
                  printf("Input tidak valid. Harap masukkan angka.\n");
                  printf("------------------------------------------------\033[0m\n");
              }
          }
      }
  }

  // Input elemen-elemen matriks kedua
  printf("\nMasukkan elemen-elemen matriks kedua:\n");
  int matriks2[baris_matriks2][kolom_matriks2];
  for (int i = 0; i < baris_matriks2; i++) {
      for (int j = 0; j < kolom_matriks2; j++) {
          while (1) {
              printf("Masukkan elemen baris %d kolom %d: ", i + 1, j + 1);
              fgets(input, sizeof(input), stdin);
              input[strcspn(input, "\n")] = '\0';
              if (apakahNomor(input)) {
                  matriks2[i][j] = atoi(input);
                  break;
              } else {
                  printf("\033[1;31m------------------------------------------------\n");
                  printf("Input tidak valid. Harap masukkan angka.\n");
                  printf("------------------------------------------------\033[0m\n");
              }
          }  
      }
  }
  
  printf("\n===================================\n");
  // Menampilkan matriks pertama dan kedua
  printf("\nTampilan Matriks Pertama:\n");

  for (int i = 0; i < baris_matriks1; i++) {
    for (int j = 0; j < kolom_matriks1; j++) {
      printf("%d ", matriks1[i][j]);
    }
    printf("\n");
  }
  
  printf("\nTampilan Matriks Kedua:\n");

  for (int i = 0; i < baris_matriks2; i++) {
    for (int j = 0; j < kolom_matriks2; j++) {
      printf("%d ", matriks2[i][j]);
    }
    printf("\n");
  }
  
  // Proses perkalian matriks
  int hasil[baris_matriks1][kolom_matriks2];
  for (int i = 0; i < baris_matriks1; i++) {
    for (int j = 0; j < kolom_matriks2; j++) {
      hasil[i][j] = 0;
      for (int k = 0; k < kolom_matriks1; k++) {
        hasil[i][j] += matriks1[i][k] * matriks2[k][j];
      }
    }
  }

  // Output hasil perkalian matriks
  printf("\n===================================\n");
  printf("Hasil perkalian matriks:\n");
  for (int i = 0; i < baris_matriks1; i++) {
    for (int j = 0; j < kolom_matriks2; j++) {
      printf("%d ", hasil[i][j]);
    }
    printf("\n");
  }

  return 0;
}
