/*Group 7-JCCA
1. Erwin Saputra Yapto (2301970076)
2. Iftikharus Raudana Muntazar (2702381622)
3. Ihsan Amri Muyassar (2702350592)
4. Wahyu Mentari Mayadita (2702347723)

Referensi:
https://www.quora.com/In-C-language-how-could-I-check-if-the-input-entered-by-the-user-is-an-integer
https://www.geeksforgeeks.org/atol-atoll-and-atof-functions-in-c-c/
https://cprogrampracticals.blogspot.com/2016/03/program-to-display-menu-using-dowhile.html
https://www.w3schools.com/c/c_while_loop.php
https://www.w3schools.com/c/c_switch.php
*/

#include <stdio.h>
#include <ctype.h>

int main() {
    // Deklarasi variabel
    long inputDetik, outputJam, outputMenit, outputSisaDetik;
    int pilihanMenu;

    // do-while loop digunakan untuk membuat menu yang terus muncul sampai user memilih menu akhiri program
    do {
        // Pesan sambutan
        printf("-----SELAMAT DATANG DI PROGRAM KONVERSI DETIK-----\n");
        
        // Menu
        printf("Menu:\n");
        printf("(1) Informasi program\n");
        printf("(2) Referensi\n");
        printf("(3) Memulai program\n");
        printf("(4) Mengakhiri program\n");
        printf("Pilih menu (1/2/3/4): ");
        scanf("%d", &pilihanMenu);

        switch (pilihanMenu) {
            case 1:
                // Informasi program
                printf("Program ini dibuat oleh kelompok 7 yang beranggota:\n");
                printf("1. ERWIN SAPUTRA YAPTO (2301970076)\n");
                printf("2. IFTIKHARUS RAUDANA MUNTAZAR (2702381622)\n");
                printf("3. IHSAN AMRI MUYASSAR (2702350592)\n");
                printf("4. WAHYU MENTARI MAYADITA (2702347723)\n");
                break;
            case 2:
                // Referensi
                printf("Dalam proses pembuatan program ini, berikut beberapa referensi yang kami gunakan:\n");
                printf("Validasi user: https://www.quora.com/In-C-language-how-could-I-check-if-the-input-entered-by-the-user-is-an-integer\n");
                printf("Konversi string ke long: https://www.geeksforgeeks.org/atol-atoll-and-atof-functions-in-c-c/\n");
                printf("Struktur menu: https://cprogrampracticals.blogspot.com/2016/03/program-to-display-menu-using-dowhile.html\n");
                printf("Do while: https://www.w3schools.com/c/c_while_loop.php\n");
                printf("Switch case: https://www.w3schools.com/c/c_switch.php\n");
                break;
            case 3:
                // Input waktu dalam detik dari user
                printf("Masukkan waktu dalam satuan detik: ");
                char inputSementara[100];
                while (1) {
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
                        inputDetik = atol(inputSementara);
                        if (inputDetik < 0) {
                            printf("Input tidak valid. Harap masukkan angka positif: ");
                        } else {
                            break;
                        }
                    } else {
                        printf("Input tidak valid. Harap masukkan angka positif: ");
                    }
                }

                // Menghitung jam, menit, dan sisa detik
                outputJam = inputDetik / 3600;
                outputMenit = (inputDetik % 3600) / 60;
                outputSisaDetik = inputDetik - (outputJam * 3600) - (outputMenit * 60);

                // Output hasil konversi
                printf("%ld detik sama dengan %ld jam, %ld menit, %ld detik\n", inputDetik, outputJam, outputMenit, outputSisaDetik);
                break;
            case 4:
                // Mengakhiri program
                printf("Terima kasih sudah menggunakan program ini. Sampai jumpa di program kami selanjutnya!\n");
                return 0;
            default:
                // Pesan kesalahan jika pilihan tidak valid
                printf("Pilihan tidak valid. Silakan pilih antara menu 1-4.\n");
        }
    } while (pilihanMenu != 4);

    return 0;
}
