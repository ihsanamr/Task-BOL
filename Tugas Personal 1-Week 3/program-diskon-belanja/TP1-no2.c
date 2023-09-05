#include <stdio.h>

int main() {
  // Deklarasi variabel
  long totalBelanja = 0;
  long jumlahTransaksi = 0;
  double diskonTotalBelanja = 0;
  double diskonJumlahTransaksi = 0;
  char lanjut;

  char merah[] = "\033[1;31m";   // Warna merah 
  char hijau[] = "\033[1;32m";   // Warna hijau 
  char reset[] = "\033[0m";      

  // Header
  printf("===============================================\n");
  printf("\t%sPROGRAM UNTUK MENGHITUNG DISKON BELANJA%s\n", hijau, reset);
  printf("===============================================\n\n");

  double totalHarga = 0; // Deklarasi hargaAkhir

  do {
    long belanja;

    // Input total belanja
    printf("Masukkan nilai total belanja (rupiah): Rp. ");
    scanf("%ld", &belanja);

    // Menghitung diskon berdasarkan ketentuan
    double diskon = 0;
    if (belanja >= 200000 && belanja < 550000) {
      diskon = belanja * 0.1; // Diskon 10%
    } else if (belanja >= 550000 && belanja <= 1000000) {
      diskon = belanja * 0.2; // Diskon 20%
    } else if (belanja > 1000000) {
      diskon = belanja * 0.3; // Diskon 30%
    }
    
    // Menambahkan diskon ke harga total
    totalBelanja += belanja;
    diskonTotalBelanja += diskon; // Memperbaharui diskonTotalBelanja
    totalHarga += belanja - diskon;
    jumlahTransaksi++;

    // Apakah user ingin melanjutkan belanja?
    printf("Belanja lagi? (Y/N) ");
    scanf(" %c", &lanjut);
    if (lanjut != 'y' && lanjut != 'Y' && lanjut != 'n' && lanjut != 'N') {
      printf("\n%sPERINTAH TIDAK VALID. HANYA MASUKKAN Y/N%s\n\n", merah, reset);
    } else if (lanjut == 'n' || lanjut == 'N') {
      break;
    }
  } while (1);

  // Menghitung diskon dari jumlah transaksi jika jumlahTransaksi >= 4
  if (jumlahTransaksi >= 4) {
    diskonJumlahTransaksi = totalHarga * 0.2; // Diskon 20% dari diskon total belanja
  }

  // Menampilkan harga akhir
  printf("\nHarga Akhir: Rp. %.2lf\n\n", (totalHarga - diskonJumlahTransaksi));

  // Menampilkan rekap transaksi
  printf("===============================================\n");
  printf("Rincian transaks:\n");
  printf("Total belanja                  : Rp. %.2lf\n", (double)totalBelanja);
  printf("Diskon dari total belanja      : Rp. %.2lf\n", diskonTotalBelanja);
  printf("Diskon dari jumlah transaksi   : Rp. %.2lf\n", diskonJumlahTransaksi);
  printf("===============================================\n");

  return 0;
}
