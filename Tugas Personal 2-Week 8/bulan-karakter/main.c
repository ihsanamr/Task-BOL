#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

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

int validasiKarakter(const char *input);

int main() {
    BULAN bulanPilihan;
    char inputTemp[100], namaPilihanBulan[100];
    int pilihanMenu = 0, pilihanBulan = 0, hurufVokal = 0, hurufKonsonan = 0;

    do {
        printf("===============================================================================\n");
        printf("\t\t\tPROGRAM BULAN KARAKTER\n");
        printf("===============================================================================\n");
        printf("Menu:\n");
        printf("[1] Mulai Program\n");
        printf("[2] Keluar");
        printf("\n");

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

        switch (pilihanMenu) {
            case 1: {
                while (1) {
                    printf("Masukkan huruf: ");
                    scanf("%[^\n]s", inputTemp);
                    getchar();
                    if (!validasiKarakter(inputTemp) || inputTemp[0] == '\n') {
                        printf("\033[1;31m------------------------------------------------\n");
                        printf("     MASUKKAN HURUF YANG VALID!\n");
                        printf("------------------------------------------------\033[0m\n");
                    } else {
                        break;
                    }
                }
                
                for (int i = 0; i < strlen(inputTemp); i++) {
                    inputTemp[i] = toupper(inputTemp[i]);
                }

                printf("\"%s\" memiliki huruf pertama '%c'\n", inputTemp, inputTemp[0]);

                switch (inputTemp[0]) {
                    case 'A': 
                        printf("Terdapat dua bulan dengan karakter awal 'A': \n");
                        printf("[Bulan ke-4] April\n");
                        printf("[Bulan ke-8] Agustus\n");

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

                        switch (bulanPilihan) {
                            case April: 
                                printf("Bulan yang anda pilih adalah April\n");
                                strcpy(namaPilihanBulan, "April");
                                break;
                            case Agustus: 
                                printf("Bulan yang anda pilih adalah Agustus\n");
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

                        printf("Jumlah huruf vokal pada bulan %s adalah %d\n", namaPilihanBulan, hurufVokal);
                        printf("Jumlah huruf konsonan pada bulan %s adalah %d\n", namaPilihanBulan, hurufKonsonan);
                        break;
                    case 'D': 
                        printf("Hanya terdapat satu bulan dengan karakter awal 'D' yaitu bulan Desember\n");
                        strcpy(namaPilihanBulan, "Desember");
                        for (int i = 0; i < strlen(namaPilihanBulan); i++) {
                            char huruf = tolower(namaPilihanBulan[i]);
                            if (huruf == 'a' || huruf == 'i' || huruf == 'u' || huruf == 'e' || huruf == 'o') {
                                hurufVokal++;
                            } else {
                                hurufKonsonan++;
                            }
                        }
                        printf("Jumlah huruf vokal pada bulan %s adalah %d\n", namaPilihanBulan, hurufVokal);
                        printf("Jumlah huruf konsonan pada bulan %s adalah %d\n", namaPilihanBulan, hurufKonsonan);
                        break;
                    case 'F':
                        printf("Hanya terdapat satu bulan dengan karakter awal 'F' yaitu bulan Februari\n");
                        strcpy(namaPilihanBulan, "Februari");
                        for (int i = 0; i < strlen(namaPilihanBulan); i++) {
                            char huruf = tolower(namaPilihanBulan[i]);
                            if (huruf == 'a' || huruf == 'i' || huruf == 'u' || huruf == 'e' || huruf == 'o') {
                                hurufVokal++;
                            } else {
                                hurufKonsonan++;
                            }
                        }
                        printf("Jumlah huruf vokal pada bulan %s adalah %d\n", namaPilihanBulan, hurufVokal);
                        printf("Jumlah huruf konsonan pada bulan %s adalah %d\n", namaPilihanBulan, hurufKonsonan);
                        break;
                    case 'J':
                        printf("Terdapat tiga bulan dengan karakter awal 'J' yaitu: \n");
                        printf("[Bulan ke-1] Januari\n");
                        printf("[Bulan ke-6] Juni\n");
                        printf("[Bulan ke-7] Juli\n");

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

                        switch (bulanPilihan) {
                            case Januari: 
                                printf("Bulan yang anda pilih adalah Januari\n");
                                strcpy(namaPilihanBulan, "Januari");
                                break;
                            case Juni: 
                                printf("Bulan yang anda pilih adalah Juni\n");
                                strcpy(namaPilihanBulan, "Juni");
                                break;
                            case Juli: 
                                printf("Bulan yang anda pilih adalah Juli\n");
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

                        printf("Jumlah huruf vokal pada bulan %s adalah %d\n", namaPilihanBulan, hurufVokal);
                        printf("Jumlah huruf konsonan pada bulan %s adalah %d\n", namaPilihanBulan, hurufKonsonan);
                        break;
                    case 'M':
                        printf("Terdapat dua bulan dengan karakter awal 'M' yaitu: \n");
                        printf("[Bulan ke-3] Maret\n");
                        printf("[Bulan ke-5] Mei\n");

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

                        switch (bulanPilihan) {
                            case Maret: 
                                printf("Bulan yang anda pilih adalah Maret\n");
                                strcpy(namaPilihanBulan, "Maret");
                                break;
                            case Mei: 
                                printf("Bulan yang anda pilih adalah Mei\n");
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

                        printf("Jumlah huruf vokal pada bulan %s adalah %d\n", namaPilihanBulan, hurufVokal);
                        printf("Jumlah huruf konsonan pada bulan %s adalah %d\n", namaPilihanBulan, hurufKonsonan);
                        break;
                    case 'N':
                        printf("Hanya terdapat satu bulan dengan karakter awal 'N' yaitu bulan November\n");
                        strcpy(namaPilihanBulan, "November");
                        for (int i = 0; i < strlen(namaPilihanBulan); i++) {
                            char huruf = tolower(namaPilihanBulan[i]);
                            if (huruf == 'a' || huruf == 'i' || huruf == 'u' || huruf == 'e' || huruf == 'o') {
                                hurufVokal++;
                            } else {
                                hurufKonsonan++;
                            }
                        }
                        printf("Jumlah huruf vokal pada bulan %s adalah %d\n", namaPilihanBulan, hurufVokal);
                        printf("Jumlah huruf konsonan pada bulan %s adalah %d\n", namaPilihanBulan, hurufKonsonan);
                        break;
                    case 'O':
                        printf("Hanya terdapat satu bulan dengan karakter awal 'O' yaitu bulan Oktober\n");
                        strcpy(namaPilihanBulan, "Oktober");
                        for (int i = 0; i < strlen(namaPilihanBulan); i++) {
                            char huruf = tolower(namaPilihanBulan[i]);
                            if (huruf == 'a' || huruf == 'i' || huruf == 'u' || huruf == 'e' || huruf == 'o') {
                                hurufVokal++;
                            } else {
                                hurufKonsonan++;
                            }
                        }
                        printf("Jumlah huruf vokal pada bulan %s adalah %d\n", namaPilihanBulan, hurufVokal);
                        printf("Jumlah huruf konsonan pada bulan %s adalah %d\n", namaPilihanBulan, hurufKonsonan);
                        break;
                    case 'S':
                        printf("Hanya terdapat satu bulan dengan karakter awal 'S' yaitu bulan September\n");
                        strcpy(namaPilihanBulan, "September");
                        for (int i = 0; i < strlen(namaPilihanBulan); i++) {
                            char huruf = tolower(namaPilihanBulan[i]);
                            if (huruf == 'a' || huruf == 'i' || huruf == 'u' || huruf == 'e' || huruf == 'o') {
                                hurufVokal++;
                            } else {
                                hurufKonsonan++;
                            }
                        }
                        printf("Jumlah huruf vokal pada bulan %s adalah %d\n", namaPilihanBulan, hurufVokal);
                        printf("Jumlah huruf konsonan pada bulan %s adalah %d\n", namaPilihanBulan, hurufKonsonan);
                        break;
                    default: 
                        printf("Tidak ada bulan dengan karakter awal %c\n", inputTemp[0]);
                        break;
                }
                break;   
            }
            case 2: {
                printf("Terima kasih telah menggunakan program ini!\n");
                break;
            }
        }      
    } while (pilihanMenu != 2);
    return 0;
}


// FUNGSI VALIDASI KARAKTER
int validasiKarakter(const char *input) {
    for (int i = 0; i < strlen(input); i++) {
        if (!isalpha(input[i])) {
            return 0;
            break;
        }
    }
    return 1;
}