/*Group 7-JCCA
1. Erwin Saputra Yapto (2301970076)
2. Iftikharus Raudana Muntazar (2702381622)
3. Ihsan Amri Muyassar (2702350592)
4. Wahyu Mentari Mayadita (2702347723) 
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*fungsi inputTotalPembelian digunakan untuk memasukkan total pembelian*/
int inputTotalPembelian(double *totalPembelian);
/*fungsi hitungDiskonKupon digunakan untuk menghitung diskon dan kupon*/
void hitungDiskonKupon(double totalPembelian, int *kupon, double *diskon);
/* Fungsi clearScreen digunakan untuk membersihkan layar konsol */
void clearScreen();

int main() {
    int pilihanMenu = 0, kupon = 0;
    double totalPembelian = 0.0;
    double diskon = 0.0;
    char tempInput[100];

    do {
        clearScreen();
        // Menu
        printf("=========================================================\n");
        printf("\t\tPROGRAM DISKON & KUPON\n");
        printf("=========================================================\n");
        printf("Selamat Berbelanja, Silakan Pilih Menu Dibawah Ini:\n");
        printf("1. Masukkan total pembelian\n");
        printf("2. Keluar\n");

        // Input menu dari user
        while (1) {
            printf("Pilih menu (1/2): ");
            scanf("%[^\n]s", tempInput);
            getchar();

            int valid = 1;
            for (int i = 0; i < strlen(tempInput); i++) {
                if (!isdigit(tempInput[i])) {
                    valid = 0;
                    break;
                }
            }

            if (valid && strlen(tempInput) == 1 && atoi(tempInput) >= 1 && atoi(tempInput) <= 2 && tempInput[0] != '\n') {
                pilihanMenu = atoi(tempInput);
                break;
            }
            printf("\033[1;31m------------------------------------------------\n");
            printf("     MASUKKAN PILIHAN MENU YANG VALID!\n");
            printf("------------------------------------------------\033[0m\n");
        }
        printf("\n");

        // Menampilkan menu sesuai pilihan user
        switch (pilihanMenu){
            case 1:
                // Memasukkan total pembelian
                inputTotalPembelian(&totalPembelian);
                // Menghitung diskon dan kupon
                hitungDiskonKupon(totalPembelian, &kupon, &diskon);
                printf("Diskon\t\t\t\t: Rp. %.2lf\n", diskon);
                printf("-------------------------------------------------\n");
                printf("Harga yang harus dibayarkan\t: Rp. %.2lf\n", totalPembelian-diskon);
                if (kupon != 0) {
                    printf("SELAMAT! ANDA MENDAPATKAN %d KUPON UNDIAN\n", kupon);
                }
                break;
            case 2:
                // Keluar
                printf("Terima kasih telah menggunakan program ini!\n");
                return 0;
                break;
        default:
            break;
        }
        printf("\n");
        printf("Tekan enter untuk melanjutkan...");
        getchar();
    } while (pilihanMenu != 2);
    return 0;
}

int inputTotalPembelian(double *total_pembelian) {
    char tempInput[100];
    int valid = 1;
    while (1) {
        printf("Masukkan total pembelian\t: Rp. ");
        scanf("%[^\n]s", tempInput);
        getchar();
        valid = 1;
        for (int i = 0; i < strlen(tempInput); i++) {
            if (!isdigit(tempInput[i])) {
                valid = 0;
                break;
            }
        }
        if (valid) {
            *total_pembelian = atof(tempInput);
            break;
        }
        printf("\033[1;31m----------------------------------------------------\n");
        printf("     MASUKKAN TOTAL PEMBELIAN YANG VALID\n");
        printf("----------------------------------------------------\033[0m\n");
    }
    return 1;
}
    
void hitungDiskonKupon(double totalPembelian, int *kupon, double *diskon) {
    if (totalPembelian >= 100000) {
        *kupon = totalPembelian / 100000;
        *diskon = totalPembelian * 0.10;
    } else {
        *kupon = totalPembelian / 100000;
        *diskon = 0.0;
        printf("\033[1;31m------------------------------------------------------\n");
        printf("TOTAL PEMBELIAN TIDAK MENCUKUPI SYARAT DISKON & KUPON\n");
        printf("------------------------------------------------------\033[0m\n");
    }
}

// Fungsi untuk membersihkan layar konsol
void clearScreen() {
#ifdef _WIN32
    system("cls");
#elif defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
    system("clear");
#else
#error "OS not supported."
#endif
}