#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Struct untuk data mahasiswa
typedef struct mahasiswa {
    char id[20];
    char nama[50];
    char prodi[100];
    float gpa;
} MHS;

// Function prototype untuk validasi input
int validInput(const char* input);
// Function prototype untuk validasi nama
int validNama(const char* nama);
// Function prototype untuk validasi gpa
int validGpa(const char* gpa);
// Fungsi untuk menampilkan judul program
void programTitle();
// Fungsi untuk membersihkan layar konsol
void clearScreen();

int main() {
    // Deklarasi variabel
    int jumlahMahasiswa;
    char inputTemp[50];
    int pilihanMenu = 0;
    MHS* mhs;

    while (1) {
        // Membersihkan layar
        clearScreen();
        // Judul program
        programTitle();
        // Menampilkan menu
        printf("\nMenu:\n");
        printf("1. Input Data Mahasiswa\n");
        printf("2. Tampilkan Data Mahasiswa\n");
        printf("3. Keluar\n");
        printf("\n");

        // Input menu dari user
        while (1) {
            printf("Pilih menu (1/2/3): ");
            scanf("%[^\n]s", inputTemp);
            getchar();

            int valid = 1;
            for (int i = 0; i < strlen(inputTemp); i++) {
                if (!isdigit(inputTemp[i])) {
                    valid = 0;
                    break;
                }
            }

            if (valid && strlen(inputTemp) == 1 && atoi(inputTemp) >= 1 && atoi(inputTemp) <= 3 && inputTemp[0] != '\n') {
                pilihanMenu = atoi(inputTemp);
                break;
            }
            printf("\033[1;31m------------------------------------------------\n");
            printf("     MASUKKAN PILIHAN MENU YANG VALID!\n");
            printf("------------------------------------------------\033[0m\n");
        }
        printf("\n");

        switch (pilihanMenu) {
            case 1:
                // Input jumlah mahasiswa
                while (1) {
                    printf("Masukkan jumlah mahasiswa: ");
                    scanf(" %[^\n]s", inputTemp);
                    getchar();
                    if (validInput(inputTemp)) {
                        jumlahMahasiswa = atoi(inputTemp);
                        break;
                    }
                    printf("\033[1;31m------------------------------------------------\n");
                    printf("     MASUKKAN JUMLAH MAHASISWA YANG VALID!\n");
                    printf("------------------------------------------------\033[0m\n");
                }
                printf("\n");

                // Array of pointer
                mhs = (MHS*)malloc(sizeof(MHS) * jumlahMahasiswa);
                if (mhs == NULL) {
                    printf("\033[1;31m------------------------------------------------\n");
                    printf("        GAGAL MEMBUAT ARRAY OF POINTER!\n");
                    printf("------------------------------------------------\033[0m\n");
                    return 1;
                }

                for (int i = 0; i < jumlahMahasiswa; i++) {
                    printf("===============================================\n");
                    printf("         INPUT DATA MAHASISWA KE-%d\n", i + 1);
                    printf("===============================================\n");
                    // Input ID Mahasiswa
                    while (1) {
                        printf("Masukkan ID\t: ");
                        scanf(" %[^\n]s", mhs[i].id);
                        getchar();
                        if (validInput(mhs[i].id) && strlen(mhs[i].id) >= 6) {
                            break;
                        }
                        printf("\033[1;31m------------------------------------------------\n");
                        printf("    MASUKKAN ID YANG VALID! (Min. 6 digit)\n");
                        printf("------------------------------------------------\033[0m\n");
                    }
                    // Input Nama Mahasiswa
                    while (1) {
                        printf("Masukkan Nama\t: ");
                        scanf(" %[^\n]s", mhs[i].nama);
                        getchar();
                        if (validNama(mhs[i].nama) && strlen(mhs[i].nama) >= 3) {
                            break;
                        }
                        printf("\033[1;31m------------------------------------------------\n");
                        printf("  MASUKKAN NAMA YANG VALID! (Min. 3 karakter)\n");
                        printf("------------------------------------------------\033[0m\n");
                    }
                    // Input Prodi Mahasiswa
                    while (1) {
                        printf("Masukkan Prodi\t: ");
                        scanf(" %[^\n]s", mhs[i].prodi);
                        getchar();
                        if (validNama(mhs[i].prodi) && strlen(mhs[i].prodi) >= 3) {
                            break;
                        }
                        printf("\033[1;31m------------------------------------------------\n");
                        printf("  MASUKKAN PRODI YANG VALID! (Min. 3 karakter)\n");
                        printf("------------------------------------------------\033[0m\n");
                    }
                    // Input GPA Mahasiswa
                    while (1) {
                        printf("Masukkan GPA\t: ");
                        scanf(" %[^\n]s", inputTemp);
                        getchar();
                        if (validGpa(inputTemp) && atof(inputTemp) >= 0 && atof(inputTemp) <= 4) {
                            mhs[i].gpa = atof(inputTemp);
                            break;
                        }
                        printf("\033[1;31m------------------------------------------------\n");
                        printf("    MASUKKAN GPA YANG VALID! (Min. 0.00 - 4.00)\n");
                        printf("------------------------------------------------\033[0m\n");
                    }
                    printf("\n");
                }
                break;
            case 2:
                // Output data mahasiswa
                printf("==============================================================\n");
                printf("%-12s| %-20s| %-20s| %-4s\n", "ID", "Nama", "Prodi", "GPA");
                printf("==============================================================\n");
                for (int i = 0; i < jumlahMahasiswa; i++) {
                    printf("%-12s| %-20s| %-20s| %.2f\n", mhs[i].id, mhs[i].nama, mhs[i].prodi, mhs[i].gpa);
                }
                printf("==============================================================\n");
                break;
            case 3:
                printf("Terima kasih telah menggunakan program ini!\n");
                free(mhs);
                return 0;
            default:
                printf("\033[1;31m------------------------------------------------\n");
                printf("     PILIHAN MENU YANG VALID!\n");
                printf("------------------------------------------------\033[0m\n");
        }
        printf("\n");
        printf("Tekan ENTER untuk melanjutkan...");
        getchar();
    }
    free(mhs);
    return 0;
}

// Function definition untuk validasi input
int validInput(const char* input) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (!isdigit(input[i]) || input[0] == '\n' || input[i] == ' ') {
            return 0;
        }
    }
    return 1;
}

// Function definition untuk validasi nama
int validNama(const char* nama) {
    for (int i = 0; nama[i] != '\0'; i++) {
        if (!isalpha(nama[i]) && nama[0] == '\n' && nama[i] != '.' && nama[i] != '-') {
            return 0;
        }
    }
    return 1;
}

// Function definition untuk validasi gpa
int validGpa(const char* gpa) {
    int jumlahTitik = 0; 

    for (int i = 0; gpa[i] != '\0'; i++) {
        if (!isdigit(gpa[i])) {
            if (gpa[i] == '.' && jumlahTitik < 1) {
                jumlahTitik++;
            } else {
                return 0; 
            }
        }
    }

    return 1;
}

// Function definition untuk menampilkan judul program
void programTitle() {
    printf("==================================================\n");
    printf("               DATA GPA MAHASISWA\n");
    printf("==================================================\n");
}

// Function definition untuk membersihkan layar konsol
void clearScreen() {
#ifdef _WIN32
    system("cls");
#elif defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
    system("clear");
#else
#error "OS not supported."
#endif
}