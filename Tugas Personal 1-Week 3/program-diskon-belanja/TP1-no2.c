/*
Tugas Personal 1 - Mata Kuliah Algoritma dan Pemrograman
Nama - NIM : Ihsan Amri Muyassar - 2702350592
*/

#include <stdio.h>

int main() {
  // Deklarasi variabel
  long totalBelanja = 0, jumlahTransaksi = 0, belanja;
  double diskonTotalBelanja = 0, diskonJumlahTransaksi = 0, totalHarga = 0, diskon = 0;
  char lanjut;

  // Header
  printf("===================================================\n");
  printf("\tPROGRAM UNTUK MENGHITUNG DISKON BELANJA\n");
  printf("===================================================\n\n");

  while (1) {
    // Input total belanja
    printf("Masukkan nilai total belanja (rupiah): Rp. ");
    scanf("%ld", &belanja);

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
      printf("Belanja lagi? (Y/N) ");
      scanf(" %c", &lanjut);
      if (lanjut == 'n' || lanjut == 'N') {
        break;
      } else if (lanjut == 'y' || lanjut == 'Y') {
        break;
      } else {
        printf("\nPERINTAH TIDAK VALID. HANYA MASUKKAN Y/N\n\n");
      }
    }

    if (lanjut == 'n' || lanjut == 'N') {
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

