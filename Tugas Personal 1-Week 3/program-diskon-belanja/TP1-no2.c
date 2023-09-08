/*
Tugas Personal 1 - Mata Kuliah Algoritma dan Pemrograman
Nama - NIM : Ihsan Amri Muyassar - 2702350592
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {
  // Deklarasi variabel
  long totalBelanja = 0, jumlahTransaksi = 0, belanja;
  double diskonTotalBelanja = 0, diskonJumlahTransaksi = 0, totalHarga = 0, diskon = 0;
  char lanjut[5];

  // Header
  printf("=========================================================\n");
  printf("\tPROGRAM UNTUK MENGHITUNG DISKON BELANJA\n");
  printf("=========================================================\n");

  while (1) {
    // Input total belanja
    char inputSementara[100];
    while (1) {
        printf("\nMasukkan nilai total belanja ke %ld (dalam rupiah): Rp. ", jumlahTransaksi + 1);
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
            // Konversi string menjadi long
            belanja = atol(inputSementara);
            if (belanja < 0) {
                printf("Input tidak valid. Harap masukkan nominal dengan benar.\n");
            } else {
                break;
            }
        } else {
            printf("\nInput tidak valid. Harap masukkan nominal dengan benar.\n");
        }
    }

    // Menghitung diskon sesuai dengan total belanja yang diinput user
    if (belanja >= 200000 && belanja < 550000) {
      diskon = belanja * 0.1; // Diskon 10%
    } else if (belanja >= 550000 && belanja <= 1000000) {
      diskon = belanja * 0.2; // Diskon 20%
    } else if (belanja > 1000000) {
      diskon = belanja * 0.3; // Diskon 30%
    }

    totalBelanja += belanja;
    // Update nilai diskon total belanja
    diskonTotalBelanja += diskon; 
    totalHarga += belanja - diskon;
    jumlahTransaksi++;

    // Pesan akan muncul jika user sudah mencapai transaksi yang ke-4
    if (jumlahTransaksi == 4) {
      printf("\n---------------------------------------------------------------------\n");
      printf("Selamat! Anda mendapatkan diskon tambahan dari jumlah transaksi.\n\n");
      printf("Jika Anda memilih untuk melanjutkan belanja, maka diskon ini tidak akan berlaku.\n");
      printf("---------------------------------------------------------------------\n\n");
    }
    
    // Bertanya kepada user apakah ingin melanjutkan belanja
    while (1) {
      printf("Apakah ingin lanjut belanja (Y/N)? ");
      scanf("%s", lanjut);
      if (strcmp(lanjut, "n") == 0 || strcmp(lanjut, "N") == 0) {
        break;
      } else if (strcmp(lanjut, "y") == 0 || strcmp(lanjut, "Y") == 0) {
        break;
      } else {
        printf("\nPERINTAH TIDAK VALID. HANYA MASUKKAN Y/N\n\n");
      }
    }

    if (strcmp(lanjut, "n") == 0 || strcmp(lanjut, "N") == 0) {
      break;
    }
  }

  // Memberikan diskon jika user mencapai jumlah transaksi ke-4 kalinya
  if (jumlahTransaksi == 4) {
    diskonJumlahTransaksi = (totalBelanja - diskonTotalBelanja) * 0.2;
  }

  printf("\nHarga Akhir: Rp. %.2lf\n\n", (totalHarga - diskonJumlahTransaksi));

  printf("===============================================\n");
  printf("Rincian transaksi:\n");
  printf("Total belanja                  : Rp. %.2lf\n", (double)totalBelanja);
  printf("Diskon dari total belanja      : Rp. %.2lf\n", diskonTotalBelanja);
  printf("Diskon dari jumlah transaksi   : Rp. %.2lf\n", diskonJumlahTransaksi);
  printf("===============================================\n");

  return 0;
}
