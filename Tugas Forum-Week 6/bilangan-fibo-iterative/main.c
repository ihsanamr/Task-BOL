#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Fungsi untuk membersihkan layar konsol
void clearScreen()
{
#ifdef _WIN32
    system("cls");
#elif defined(unix) || defined(__unix__) || defined(__unix) || \
    (defined(__APPLE__) && defined(__MACH__))
    system("clear");
#else
#error "OS not supported."
#endif
}

// Fungsi iteratif untuk menghitung bilangan Fibonacci ke-n
int fibonacciIteratif(int n) {
    if (n <= 1) {
        return n;
    }
    int angkaSebelumnya = 0;
    int angkaSekarang = 1;

    for (int i = 2; i <= n; i++) {
        int angkaSelanjutnya = angkaSebelumnya + angkaSekarang;
        angkaSebelumnya = angkaSekarang;
        angkaSekarang = angkaSelanjutnya;
    }
    return angkaSekarang;
}

// Fungsi rekursif untuk menghitung bilangan Fibonacci ke-n
int fibonacciRekursif(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacciRekursif(n - 1) + fibonacciRekursif(n - 2);
}

// Fungsi untuk memeriksa apakah input adalah angka yang valid (tidak terdiri dari huruf atau titik desimal)
int cekAngka(char *nilai) {
    size_t panjang = strlen(nilai);
    for (int i = 0; i < panjang; i++) {
        if (!isdigit(nilai[i]) && !isspace(nilai[i])) {
            return 0;
        }
    }
    return 1;
}

// Fungsi untuk mengambil pilihan menu dari user
int getPilihanMenu()
{
    int pilihan;
    char inputSementara[100];

    do
    {
        printf("Masukkan pilihan menu: ");
        if (fgets(inputSementara, sizeof(inputSementara), stdin) != NULL)
        {
            if (cekAngka(inputSementara)) {
                sscanf(inputSementara, "%d", &pilihan);
                if (pilihan >= 1 && pilihan <= 2) {
                    break;
                } else {
                    printf("----------------------------------------------\n");
                    printf("     MASUKKAN PILIHAN MENU YANG VALID\n");
                    printf("----------------------------------------------\n");
                }
            } else {
                printf("----------------------------------------------\n");
                printf("     MASUKKAN PILIHAN MENU YANG VALID\n");
                printf("----------------------------------------------\n");
            }
        }
    } while (1);

    return pilihan;
}

int main() {
    int pilihanMenu;
    char inputSementara[100];
    int n;
    clock_t mulai, berakhir;
    double waktuEksekusi;

    do
    {
        clearScreen();
      
        // Header
        printf("=============================================\n");
        printf("        PROGRAM MENCARI BIL. FIBONACCI       \n");
        printf("=============================================\n");
      
        // Menu
        printf("Menu:\n");
        printf("1. Mulai program\n");
        printf("2. Keluar\n");

        pilihanMenu = getPilihanMenu(); // Mengambil pilihan menu dari user

        switch (pilihanMenu)
        {
            case 1:
                while (1) {
                    printf("\nIngin mencari bilangan fibonacci ke berapa? ");
                    if (fgets(inputSementara, sizeof(inputSementara), stdin) != NULL) {
                        if (cekAngka(inputSementara)) {
                            sscanf(inputSementara, "%d", &n);
                            break;
                        } else {
                            printf("-----------------------------------------------\n");
                            printf("             INPUT TIDAK VALID \n");
                            printf("-----------------------------------------------\n");
                        }
                    } else {
                        return 1;
                    }
                }

                // Mengukur waktu eksekusi untuk fungsi iteratif
                mulai = clock();
                printf("\nBilangan Fibonacci ke %d (iteratif): %d\n", n, fibonacciIteratif(n));
                berakhir = clock();
                waktuEksekusi = ((double) (berakhir - mulai)) / CLOCKS_PER_SEC;
                printf("Waktu yang dibutuhkan (iteratif): %f detik", waktuEksekusi);

                // Mengukur waktu eksekusi untuk fungsi rekursif
                mulai = clock();
                printf("\n\nBilangan Fibonacci ke %d (rekursif): %d\n", n, fibonacciRekursif(n));
                berakhir = clock();
                waktuEksekusi = ((double) (berakhir - mulai)) / CLOCKS_PER_SEC;
                printf("Waktu yang dibutuhkan (rekursif): %f detik\n", waktuEksekusi);

                printf("\nTekan 'Enter' untuk melanjutkan...");
                while (getchar() != '\n');
                break;

            case 2:
                printf("Sampai jumpa pada program selanjutnya!\n");
                break;

            default:
                printf("----------------------------------------------\n");
                printf("      MENU TIDAK TERSEDIA PADA PROGRAM \n");
                printf("----------------------------------------------\n");
        }

        
    } while (pilihanMenu != 2);

    return 0;
}
