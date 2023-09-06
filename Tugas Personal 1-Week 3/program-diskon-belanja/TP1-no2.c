#include <stdio.h>

int main() {
  long totalBelanja = 0, jumlahTransaksi = 0, belanja;
  double diskonTotalBelanja = 0, diskonJumlahTransaksi = 0, totalHarga = 0, diskon = 0;
  char lanjut;

  printf("=======================================================\n");
  printf("\tPROGRAM UNTUK MENGHITUNG DISKON BELANJA\n");
  printf("=======================================================\n\n");

  do {

    printf("Masukkan nilai total belanja (rupiah): Rp. ");
    scanf("%ld", &belanja);

    if (belanja >= 200000 && belanja < 550000) {
      diskon = belanja * 0.1;
    } else if (belanja >= 550000 && belanja <= 1000000) {
      diskon = belanja * 0.2;
    } else if (belanja > 1000000) {
      diskon = belanja * 0.3;
    }

    totalBelanja += belanja;
    diskonTotalBelanja += diskon;
    totalHarga += belanja - diskon;

    jumlahTransaksi++;

    if (jumlahTransaksi == 4) {
      printf("\n---------------------------------------------------------------------");
      printf("\nSelamat! Anda mendapatkan diskon tambahan dari jumlah transaksi.\n");
      printf("\nJika anda memilih untuk melanjutkan belanja, maka diskon ini tidak akan berlaku.\n");
      printf("----------------------------------------------------------------------\n\n");
    }

    // Apakah user ingin melanjutkan belanja?
     printf("Ingin belanja lagi ('Y' untuk belanja lagi/'N' jika sudah selesai belanja)? ");
     scanf(" %c", &lanjut);
     if (lanjut != 'y' && lanjut != 'Y' && lanjut != 'n' && lanjut != 'N') {
       printf("\nPERINTAH TIDAK VALID. HANYA MASUKKAN Y/N\n\n");
     } else if (lanjut == 'n' || lanjut == 'N') {
       break;
     }
  } while (1);

  if (jumlahTransaksi == 4) {
    // Apply 20% discount only if the user completed four transactions
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