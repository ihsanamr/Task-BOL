/*Group 7-JCCA
1. Erwin Saputra Yapto (2301970076)
2. Iftikharus Raudana Muntazar (2702381622)
3. Ihsan Amri Muyassar (2702350592)
4. Wahyu Mentari Mayadita (2702347723)

Referensi:
https://cprogrampracticals.blogspot.com/2016/03/program-to-display-menu-using-dowhile.html
https://www.w3schools.com/c/c_while_loop.php
https://www.w3schools.com/c/c_switch.php
ChatGPT: Prompt "How to remove newline when we using fgets?"
*/

#include <stdio.h>
#include <string.h>

// Fungsi untuk menghitung panjang string tanpa spasi
int hitungPanjangTanpaSpasi(char *kalimat) {
    int panjang = 0;
    for (int i = 0; kalimat[i] != '\0'; i++) {
        if (kalimat[i] != ' ') {
            panjang++;
        }
    }
    return panjang;
}

int main() {
    char kalimat1[100], kalimat2[100], kalimat3[100], gabunganKalimat[300];
    int huruf1, huruf2, huruf3, totalHuruf, pilihanMenu, panjangTotal;

    do {
        // Menampilkan pesan sambutan dan menu
        printf("-----SELAMAT DATANG DI PROGRAM KONVERSI KALIMAT-----\n");
        printf("Menu:\n");
        printf("(1) Informasi program\n");
        printf("(2) Referensi\n");
        printf("(3) Memulai program\n");
        printf("(4) Mengakhiri program\n");
        printf("Pilih menu (1/2/3/4): ");
        scanf("%d", &pilihanMenu);
        getchar(); // Membersihkan karakter newline (\n) dari input sebelumnya

        switch (pilihanMenu) {
            case 1:
                // Menampilkan informasi tentang pembuat program
                printf("Program ini dibuat oleh kelompok 7 yang beranggota:\n");
                printf("1. ERWIN SAPUTRA YAPTO (2301970076)\n");
                printf("2. IFTIKHARUS RAUDANA MUNTAZAR (2702381622)\n");
                printf("3. IHSAN AMRI MUYASSAR (2702350592)\n");
                printf("4. WAHYU MENTARI MAYADITA (2702347723)\n");
                break;
            case 2:
                // Menampilkan referensi yang digunakan dalam pembuatan program
                printf("Dalam proses pembuatan program ini, berikut beberapa referensi yang kami gunakan:\n");
                printf("Reverse string: https://www.simplilearn.com/tutorials/c-tutorial/c-program-to-reverse-a-string \n");
                printf("Do while: https://www.w3schools.com/c/c_while_loop.php \n");
                printf("ChatGPT: Prompt \"How to remove newline when we using fgets?\" \n");
                printf("Switch case: https://www.w3schools.com/c/c_switch.php \n");
                break;
            case 3:
                // Meminta input dari pengguna untuk tiga kalimat
                printf("Kalimat 1 = ");
                fgets(kalimat1, sizeof(kalimat1), stdin);
                kalimat1[strcspn(kalimat1, "\n")] = '\0'; // Menghilangkan newline

                printf("Kalimat 2 = ");
                fgets(kalimat2, sizeof(kalimat2), stdin);
                kalimat2[strcspn(kalimat2, "\n")] = '\0'; // Menghilangkan newline

                printf("Kalimat 3 = ");
                fgets(kalimat3, sizeof(kalimat3), stdin);
                kalimat3[strcspn(kalimat3, "\n")] = '\0'; // Menghilangkan newline

                // Menggabungkan tiga kalimat menjadi satu dan menghitung panjang masing-masing
                strcpy(gabunganKalimat, kalimat1);
                strcat(gabunganKalimat, " ");
                strcat(gabunganKalimat, kalimat2);
                strcat(gabunganKalimat, " ");
                strcat(gabunganKalimat, kalimat3);

                huruf1 = hitungPanjangTanpaSpasi(kalimat1);
                huruf2 = hitungPanjangTanpaSpasi(kalimat2);
                huruf3 = hitungPanjangTanpaSpasi(kalimat3);
                panjangTotal = strlen(gabunganKalimat);
                totalHuruf = huruf1 + huruf2 + huruf3;

                // Menampilkan hasil penggabungan, pembalikan, dan jumlah huruf
                printf("Gabungan 3 buah inputan kalimat = %s\n", gabunganKalimat);
                printf("Hasil membalik kalimat gabungan = ");
                for (int i = panjangTotal - 1; i >= 0; i--) {
                    printf("%c", gabunganKalimat[i]);
                }
                printf("\n");
                printf("Jumlah huruf kalimat pertama = %d\n", huruf1);
                printf("Jumlah huruf kalimat kedua = %d\n", huruf2);
                printf("Jumlah huruf kalimat ketiga = %d\n", huruf3);
                printf("Total jumlah huruf = %d\n", totalHuruf);

                break;
            case 4:
                // Menampilkan pesan terima kasih dan mengakhiri program
                printf("Terima kasih sudah menggunakan program ini. Sampai jumpa di program kami selanjutnya!\n");
                return 0;
            default:
                // Menampilkan pesan kesalahan jika input tidak valid
                printf("Pilihan tidak valid. Silakan pilih antara menu 1-4.\n");
        }
    } while (pilihanMenu != 4);

    return 0;
}