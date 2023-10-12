/*

NIM - Nama  : 2702350592 - Ihsan Amri Muyassar
Kelas       : JCCA
Mata Kuliah : Algoritma dan Pemrograman

*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// enum bulan yang akan digunakan sebagai pilihan bulan
typedef enum bulan{
    Januari = 1,
    Februari,
    Maret,
    April,
    Mei,
    Juni,
    Juli,
    Agustus,
    September,
    Oktober,
    November,
    Desember
} BULAN;

// Prototipe fungsi validasi karakter
int validasiKarakter(const char *input);

// Prototipe fungsi meminta input menu kepada user
int getpPilihanMenu();

// Prototipe fungsi membersihkan layar konsol
void clearScreen();

// Prototipe fungsi untuk menampilkan menu
void programMenu();

// Prototipe fungsi untuk memproses menu yang dipilih user
void prosesMenu(int pilihanMenu);

// ===== MAIN FUNCTION ===== 
int main() {
    char inputTemp[100];
    int pilihanMenu = 0;

    do {
        // Memanggil fungsi clearScreen untuk membersihkan layar konsol
        clearScreen();
        // Memanggil fungsi programMenu untuk menampilkan menu
        programMenu();

        printf("\n");

        // Memanggil fungsi getpPilihanMenu untuk meminta input pilihan menu dari user
        pilihanMenu = getpPilihanMenu();
        
        printf("\n");
        
        // Memanggil fungsi prosesMenu untuk memproses menu yang dipilih
        prosesMenu(pilihanMenu);

        printf("\n");
        printf("Tekan ENTER untuk melanjutkan...");
        getchar();  
    } while (pilihanMenu != 2);
    return 0;
}

// Fungsi validasi karakter
int validasiKarakter(const char *input) {
    for (int i = 0; i < strlen(input); i++) {
        if (!isalpha(input[i])) {
            return 0;
            break;
        }
    }
    return 1;
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

// Fungsi untuk menampilkan judul dan menu program
void programMenu() {
    printf("========================================\n");
    printf("| PENCARIAN BULAN BERDASARKAN KARAKTER |\n");
    printf("========================================\n");
    printf("Menu:\n");
    printf("[1] Mulai Program\n");
    printf("[2] Keluar\n");
}

// Fungsi untuk meminta input pilihan menu dari pengguna
int getpPilihanMenu() {
    char inputTemp[100];
    int pilihanMenu = 0;
    while (1) {
            printf("Pilih menu (1/2): ");
            scanf("%[^\n]s", inputTemp);
            getchar();
            int valid = 1;
            for (int i = 0; i < strlen(inputTemp); i++) {
                if (!isdigit(inputTemp[i])) {
                    valid = 0;
                    break;
                }
            }
            if (valid && strlen(inputTemp) == 1 && atoi(inputTemp) >= 1 && atoi(inputTemp) <= 2 && inputTemp[0] != '\n') {
                pilihanMenu = atoi(inputTemp);
                break;
            }
            printf("\033[1;31m------------------------------------------------\n");
            printf("     MASUKKAN PILIHAN MENU YANG VALID!\n");
            printf("------------------------------------------------\033[0m\n");
    }
    return pilihanMenu;
}

// Fungsi untuk memproses menu yang dipilih user
void prosesMenu(int pilihanMenu) {
    switch (pilihanMenu) {
        case 1: {
            char inputTemp[100], namaPilihanBulan[100];
            int pilihanBulan = 0, hurufVokal = 0, hurufKonsonan = 0;
            BULAN bulanPilihan;
            printf("========================================\n");
            printf("|             PROGRAM DIMULAI          |\n");
            printf("========================================\n");
            while (1) {
                printf("Masukkan huruf: ");
                scanf("%[^\n]s", inputTemp);
                getchar();
                if (!validasiKarakter(inputTemp) || inputTemp[0] == '\n') {
                    printf("\033[1;31m------------------------------------------------\n");
                    printf("     MASUKKAN HURUF YANG VALID TANPA SPASI!\n");
                    printf("------------------------------------------------\033[0m\n");
                } else {
                    break;
                }
            }
            
            for (int i = 0; i < strlen(inputTemp); i++) {
                inputTemp[i] = toupper(inputTemp[i]);
            }

            printf("\n--------------------------------------------\n");
            printf("\"%s\" memiliki huruf pertama '%c'\n", inputTemp, inputTemp[0]);

            switch (inputTemp[0]) {
                case 'A': 
                    printf("--------------------------------------------\n");
                    printf("Terdapat dua bulan dengan karakter awal 'A': \n");
                    printf("[Bulan ke-4] April\n");
                    printf("[Bulan ke-8] Agustus\n");
                    printf("--------------------------------------------\n");

                    while (1) {
                        printf("Pilih bulan yang anda inginkan (4/8): ");
                        scanf("%[^\n]s", inputTemp);
                        getchar();
                        int valid = 1;
                        for (int i = 0; i < strlen(inputTemp); i++) {
                            if (!isdigit(inputTemp[i]) || atoi(inputTemp) != 4 && atoi(inputTemp) != 8) {
                                valid = 0;
                                break;
                            }
                        }
                        if (valid && strlen(inputTemp) == 1 && inputTemp[0] != '\n') {
                            bulanPilihan = atoi(inputTemp);
                            break;
                        }
                        printf("\033[1;31m------------------------------------------------\n");
                        printf("     MASUKKAN PILIHAN BULAN YANG VALID!\n");
                        printf("------------------------------------------------\033[0m\n");
                    }

                    printf("--------------------------------------------\n");

                    switch (bulanPilihan) {
                        case April: 
                            printf("Bulan yang dipilih\t\t\t: April\n");
                            strcpy(namaPilihanBulan, "April");
                            break;
                        case Agustus: 
                            printf("Bulan yang dipilih\t\t\t: Agustus\n");
                            strcpy(namaPilihanBulan, "Agustus");
                            break;
                    }

                    for (int i = 0; i < strlen(namaPilihanBulan); i++) {
                        char huruf = tolower(namaPilihanBulan[i]);
                        if (huruf == 'a' || huruf == 'i' || huruf == 'u' || huruf == 'e' || huruf == 'o') {
                            hurufVokal++;
                        } else {
                            hurufKonsonan++;
                        }
                    }

                    printf("Jumlah huruf vokal pada bulan %s\t: %d\n", namaPilihanBulan, hurufVokal);
                    printf("Jumlah huruf konsonan pada bulan %s: %d\n", namaPilihanBulan, hurufKonsonan);
                    printf("--------------------------------------------\n");
                    break;
                case 'D': 
                    printf("--------------------------------------------\n");
                    printf("Hanya terdapat satu bulan dengan karakter \nawal 'D' yaitu bulan Desember\n");
                    strcpy(namaPilihanBulan, "Desember");
                    for (int i = 0; i < strlen(namaPilihanBulan); i++) {
                        char huruf = tolower(namaPilihanBulan[i]);
                        if (huruf == 'a' || huruf == 'i' || huruf == 'u' || huruf == 'e' || huruf == 'o') {
                            hurufVokal++;
                        } else {
                            hurufKonsonan++;
                        }
                    }
                    printf("--------------------------------------------\n");
                    printf("Jumlah huruf vokal pada bulan %s   : %d\n", namaPilihanBulan, hurufVokal);
                    printf("Jumlah huruf konsonan pada bulan %s: %d\n", namaPilihanBulan, hurufKonsonan);
                    printf("--------------------------------------------\n");
                    break;
                case 'F':
                    printf("--------------------------------------------\n");
                    printf("Hanya terdapat satu bulan dengan karakter \nawal 'F' yaitu bulan Februari\n");
                    strcpy(namaPilihanBulan, "Februari");
                    for (int i = 0; i < strlen(namaPilihanBulan); i++) {
                        char huruf = tolower(namaPilihanBulan[i]);
                        if (huruf == 'a' || huruf == 'i' || huruf == 'u' || huruf == 'e' || huruf == 'o') {
                            hurufVokal++;
                        } else {
                            hurufKonsonan++;
                        }
                    }
                    printf("--------------------------------------------\n");
                    printf("Jumlah huruf vokal pada bulan %s   : %d\n", namaPilihanBulan, hurufVokal);
                    printf("Jumlah huruf konsonan pada bulan %s: %d\n", namaPilihanBulan, hurufKonsonan);
                    printf("--------------------------------------------\n");
                    break;
                case 'J':
                    printf("--------------------------------------------\n");
                    printf("Terdapat tiga bulan dengan karakter awal 'J' yaitu: \n");
                    printf("[Bulan ke-1] Januari\n");
                    printf("[Bulan ke-6] Juni\n");
                    printf("[Bulan ke-7] Juli\n");
                    printf("--------------------------------------------\n");

                    while (1) {
                        printf("Pilih bulan yang anda inginkan (1/6/7): ");
                        scanf("%[^\n]s", inputTemp);
                        getchar();
                        int valid = 1;
                        for (int i = 0; i < strlen(inputTemp); i++) {
                            if (!isdigit(inputTemp[i]) || atoi(inputTemp) != 1 && atoi(inputTemp) != 6 && atoi(inputTemp) != 7) {
                                valid = 0;
                                break;
                            } 
                        }
                        if (valid && strlen(inputTemp) == 1 && inputTemp[0] != '\n') {
                            bulanPilihan = atoi(inputTemp);
                            break;
                        }
                        printf("\033[1;31m------------------------------------------------\n");
                        printf("     MASUKKAN PILIHAN BULAN YANG VALID!\n");
                        printf("------------------------------------------------\033[0m\n");
                    }
                    
                    printf("--------------------------------------------\n");
                    switch (bulanPilihan) {
                        case Januari: 
                            printf("Bulan yang anda pilih\t\t\t: Januari\n");
                            strcpy(namaPilihanBulan, "Januari");
                            break;
                        case Juni: 
                            printf("Bulan yang anda pilih\t\t\t: Juni\n");
                            strcpy(namaPilihanBulan, "Juni");
                            break;
                        case Juli: 
                            printf("Bulan yang anda pilih\t\t\t: Juli\n");
                            strcpy(namaPilihanBulan, "Juli");
                            break;
                    }

                    for (int i = 0; i < strlen(namaPilihanBulan); i++) {
                        char huruf = tolower(namaPilihanBulan[i]);
                        if (huruf == 'a' || huruf == 'i' || huruf == 'u' || huruf == 'e' || huruf == 'o') {
                            hurufVokal++;
                        } else {
                            hurufKonsonan++;
                        }
                    }

                    printf("Jumlah huruf vokal pada bulan %s\t: %d\n", namaPilihanBulan, hurufVokal);
                    printf("Jumlah huruf konsonan pada bulan %s\t: %d\n", namaPilihanBulan, hurufKonsonan);
                    printf("--------------------------------------------\n");
                    break;
                case 'M':
                    printf("--------------------------------------------\n");
                    printf("Terdapat dua bulan dengan karakter awal 'M' yaitu: \n");
                    printf("[Bulan ke-3] Maret\n");
                    printf("[Bulan ke-5] Mei\n");
                    printf("--------------------------------------------\n");

                    while (1) {
                        printf("Pilih bulan yang anda inginkan (3/5): ");
                        scanf("%[^\n]s", inputTemp);
                        getchar();
                        int valid = 1;
                        for (int i = 0; i < strlen(inputTemp); i++) {
                            if (!isdigit(inputTemp[i]) || atoi(inputTemp) != 3 && atoi(inputTemp) != 5) {
                                valid = 0;
                                break;
                            }
                        }
                        if (valid && strlen(inputTemp) == 1 && inputTemp[0] != '\n') {
                            bulanPilihan = atoi(inputTemp);
                            break;
                        }
                        printf("\033[1;31m------------------------------------------------\n");
                        printf("     MASUKKAN PILIHAN BULAN YANG VALID!\n");
                        printf("------------------------------------------------\033[0m\n");
                    }
                    printf("--------------------------------------------\n");
                    switch (bulanPilihan) {
                        case Maret: 
                            printf("Bulan yang dipilih\t\t\t: Maret\n");
                            strcpy(namaPilihanBulan, "Maret");
                            break;
                        case Mei: 
                            printf("Bulan yang dipilih\t\t\t: Mei\n");
                            strcpy(namaPilihanBulan, "Mei");
                            break;
                    }

                    for (int i = 0; i < strlen(namaPilihanBulan); i++) {
                        char huruf = tolower(namaPilihanBulan[i]);
                        if (huruf == 'a' || huruf == 'i' || huruf == 'u' || huruf == 'e' || huruf == 'o') {
                            hurufVokal++;
                        } else {
                            hurufKonsonan++;
                        }
                    }

                    printf("Jumlah huruf vokal pada bulan %s\t: %d\n", namaPilihanBulan, hurufVokal);
                    printf("Jumlah huruf konsonan pada bulan %s\t: %d\n", namaPilihanBulan, hurufKonsonan);
                    printf("--------------------------------------------\n");
                    break;
                case 'N':
                    printf("--------------------------------------------\n");
                    printf("Hanya terdapat satu bulan dengan karakter \nawal 'N' yaitu bulan November\n");
                    strcpy(namaPilihanBulan, "November");
                    for (int i = 0; i < strlen(namaPilihanBulan); i++) {
                        char huruf = tolower(namaPilihanBulan[i]);
                        if (huruf == 'a' || huruf == 'i' || huruf == 'u' || huruf == 'e' || huruf == 'o') {
                            hurufVokal++;
                        } else {
                            hurufKonsonan++;
                        }
                    }
                    printf("--------------------------------------------\n");
                    printf("Jumlah huruf vokal pada bulan %s   : %d\n", namaPilihanBulan, hurufVokal);
                    printf("Jumlah huruf konsonan pada bulan %s: %d\n", namaPilihanBulan, hurufKonsonan);
                    printf("--------------------------------------------\n");
                    break;
                case 'O':
                    printf("--------------------------------------------\n");
                    printf("Hanya terdapat satu bulan dengan karakter \nawal 'O' yaitu bulan Oktober\n");
                    strcpy(namaPilihanBulan, "Oktober");
                    for (int i = 0; i < strlen(namaPilihanBulan); i++) {
                        char huruf = tolower(namaPilihanBulan[i]);
                        if (huruf == 'a' || huruf == 'i' || huruf == 'u' || huruf == 'e' || huruf == 'o') {
                            hurufVokal++;
                        } else {
                            hurufKonsonan++;
                        }
                    }
                    printf("--------------------------------------------\n");
                    printf("Jumlah huruf vokal pada bulan %s   : %d\n", namaPilihanBulan, hurufVokal);
                    printf("Jumlah huruf konsonan pada bulan %s: %d\n", namaPilihanBulan, hurufKonsonan);
                    printf("--------------------------------------------\n");
                    break;
                case 'S':
                    printf("--------------------------------------------\n");
                    printf("Hanya terdapat satu bulan dengan karakter \nawal 'S' yaitu bulan September\n");
                    strcpy(namaPilihanBulan, "September");
                    for (int i = 0; i < strlen(namaPilihanBulan); i++) {
                        char huruf = tolower(namaPilihanBulan[i]);
                        if (huruf == 'a' || huruf == 'i' || huruf == 'u' || huruf == 'e' || huruf == 'o') {
                            hurufVokal++;
                        } else {
                            hurufKonsonan++;
                        }
                    }
                    printf("--------------------------------------------\n");
                    printf("Jumlah huruf vokal pada bulan %s   : %d\n", namaPilihanBulan, hurufVokal);
                    printf("Jumlah huruf konsonan pada bulan %s: %d\n", namaPilihanBulan, hurufKonsonan);
                    printf("--------------------------------------------\n");
                    break;
                default: 
                    printf("--------------------------------------------\n");
                    printf("Tidak ada bulan dengan karakter awal %c\n", inputTemp[0]);
                    printf("--------------------------------------------\n");
                    break;
            }
            break;   
        }
        case 2: {
            printf("-------------------------------------------------------\n");
            printf("Terima kasih dan sampai jumpa pada program selanjutnya!\n");
            printf("-------------------------------------------------------\n");
            break;
        }
    }
}
