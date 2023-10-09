#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Struktur data untuk pegawai
typedef struct Pegawai {
    char nip[20];
    char nama[50];
    char alamat[100];
    char noHp[15];
    char jabatan[50];
    char golongan[5];
    int gajiPokok;
} PEGAWAI;

// Fungsi untuk menghitung gaji bulanan berdasarkan golongan dan jumlah jam lembur
int hitungGajiBulanan(const char *golongan, int jumlahJamLembur);
// Fungsi untuk memvalidasi nama
int validasiNama(const char* nama);
// Fungsi untuk memvalidasi nomor
int validasiNIP(const char *nomor);
// Fungsi untuk input data pegawai
void inputDataPegawai(PEGAWAI *pegawai);
// Fungsi untuk input alamat
int validasiAlamat(const char* alamat);
// Fungsi untuk memvalidasi nomor
int validasiNoHP(const char *nomor);
// Fungsi untuk memvalidasi jabatan
int validasiJabatan(const char *jabatan);
// Fungsi untuk memvalidasi input jam lembur
int validasiLembur(const char *jam);
// Fungsi untuk membersihkan layar konsol
void clearScreen();
// Fungsi untuk menampilkan judul program
void programTitle();

int main() {
    PEGAWAI pegawai;
    int pilihanMenu, gajiLemburan = 0;
    int jumlahJamLembur = 0;
    char tempInput[100];
    int lemburanPerJam = 0;
    int dataPegawaiDiisi = 0;

    while (1) {
        // Membersihkan layar
        clearScreen();
        // Judul program
        programTitle();
        // Menampilkan menu
        printf("\nMenu:\n");
        printf("1. Input Data Pegawai\n");
        printf("2. Input Data Lembur\n");
        printf("3. Hitung Total Gaji Bulan ini\n");
        printf("4. Keluar\n");
        printf("\n");

        // Input menu dari user
        while (1) {
            printf("Pilih menu (1/2/3/4): ");
            scanf("%[^\n]s", tempInput);
            getchar();

            int valid = 1;
            for (int i = 0; i < strlen(tempInput); i++) {
                if (!isdigit(tempInput[i])) {
                    valid = 0;
                    break;
                }
            }

            if (valid && strlen(tempInput) == 1 && atoi(tempInput) >= 1 && atoi(tempInput) <= 4 && tempInput[0] != '\n') {
                pilihanMenu = atoi(tempInput);
                break;
            }
            printf("\033[1;31m------------------------------------------------\n");
            printf("     MASUKKAN PILIHAN MENU YANG VALID!\n");
            printf("------------------------------------------------\033[0m\n");
        }
        printf("\n");

        // Menampilkan menu sesuai pilihan user
        switch (pilihanMenu) {
            case 1:
                // Input data pegawai
                inputDataPegawai(&pegawai);
                dataPegawaiDiisi = 1; // Tanda bahwa data pegawai sudah diisi
                break;

            case 2:
                if (!dataPegawaiDiisi) { // Jika data pegawai belum diisi, tampilkan pesan tidak ada data pegawai
                    printf("********************************************************\n");
                    printf(" Harap masukkan data pegawai terlebih dahulu (menu 1)\n");
                    printf("********************************************************\n");
                } else { // Jika data pegawai sudah diisi, user bisa memasukkan data lembur
                    printf("============================================================\n");
                    printf("                   INPUT DATA LEMBUR\n");
                    printf("============================================================\n");
                    printf("NIP              : %s\n", pegawai.nip);
                    printf("Golongan         : %s\n", pegawai.golongan);
                    while (1) {
                        printf("Jumlah Jam Lembur: ");
                        scanf(" %[^\n]s", tempInput);
                        getchar();
                        if (!validasiLembur(tempInput)) {
                            printf("\033[1;31m------------------------------------------------\n");
                            printf("     MASUKKAN JUMLAH JAM LEMBUR YANG VALID!\n");
                            printf("------------------------------------------------\033[0m\n");
                        } else {
                            jumlahJamLembur = atoi(tempInput);
                            break;
                        }
                    }

                    // Set nilai lemburanPerJam berdasarkan golongan pegawai
                    if (strcmp(pegawai.golongan, "D1") == 0) {
                        lemburanPerJam = 10000;
                    } else if (strcmp(pegawai.golongan, "D2") == 0) {
                        lemburanPerJam = 5000;
                    } else if (strcmp(pegawai.golongan, "D3") == 0) {
                        lemburanPerJam = 2500;
                    }

                    // Hitung gaji lembur
                    gajiLemburan = jumlahJamLembur * lemburanPerJam;
                    printf("********************************************************\n");
                    printf("\t  Data lembur berhasil dimasukkan!\n");
                    printf("--------------------------------------------------------\n");
                    printf("  Selanjutnya, hitung total gaji bulanan pada menu 3\n");
                    printf("********************************************************\n");
                }
                break;

            case 3:
                if (!dataPegawaiDiisi) { // Jika data pegawai belum diisi, tampilkan pesan tidak ada data pegawai
                    printf("************************************************************\n");
                    printf("Harap masukkan data pegawai terlebih dahulu (menu 1 atau 2).\n");
                    printf("************************************************************\n");
                } else {
                    // Menghitung total gaji bulanan
                    if (jumlahJamLembur >= 0) {
                        int totalGajiBulanan = hitungGajiBulanan(pegawai.golongan, jumlahJamLembur);

                        // Menampilkan hasil
                        printf("=========================================\n");
                        printf("Nip          : %s\n", pegawai.nip);
                        printf("Nama         : %s\n", pegawai.nama);
                        printf("Alamat       : %s\n", pegawai.alamat);
                        printf("No HP        : %s\n", pegawai.noHp);
                        printf("Jabatan      : %s\n", pegawai.jabatan);
                        printf("Golongan     : %s\n", pegawai.golongan);
                        printf("Gaji Pokok   : Rp. %d\n", pegawai.gajiPokok);
                        printf("Lembur       : %d jam\n", jumlahJamLembur);
                        printf("Gaji lembur  : Rp. %d\n", gajiLemburan);
                        printf("=========================================\n");

                        printf("*****************************************\n");
                        printf("Total Gaji Bulan ini = Rp. %d\n", totalGajiBulanan);
                        printf("*****************************************\n");
                    } else {
                        printf("********************************************************\n");
                        printf("    Harap masukkan jumlah jam lembur terlebih dahulu\n");
                        printf("********************************************************\n");
                    }
                }
                break;

            case 4:
                // Keluar
                printf("Terima kasih telah menggunakan program ini!\n");
                return 0;

            default:
                printf("Pilihan tidak valid. Silakan pilih menu yang sesuai.\n");
        }
        printf("\n");
        printf("Tekan ENTER untuk melanjutkan...");
        getchar();
    }

    return 0;
}

void inputDataPegawai(PEGAWAI *pegawai) {
    printf("============================================================\n");
    printf("                   INPUT DATA PEGAWAI\n");
    printf("============================================================\n");
    while (1) {
        printf("NIP                 : ");
        scanf(" %[^\n]s", pegawai->nip);
        getchar();
        if (!validasiNIP(pegawai->nip) || pegawai->nip[0] == '\n' || strlen(pegawai->nip) < 8) {
            printf("\033[1;31m------------------------------------------------\n");
            printf("        NIP YANG DIMASUKKAN TIDAK VALID!\n");
            printf("------------------------------------------------\033[0m\n");
        } else {
            break;
        } 
    }
    
    while (1) {
        printf("Nama                : ");
        scanf(" %[^\n]s", pegawai->nama);
        getchar();
        if (!validasiNama(pegawai->nama) || pegawai->nama[0] == '\n') {
            printf("\033[1;31m------------------------------------------------\n");
            printf("     NAMA YANG DIMASUKKAN TIDAK VALID!\n");
            printf("------------------------------------------------\033[0m\n");
        } else {
            break;
        }
    }
    
    while (1) {
        printf("Alamat              : ");
        scanf(" %[^\n]s", pegawai->alamat);
        getchar();
        if (!validasiAlamat(pegawai->alamat) || pegawai->alamat[0] == '\n') {
            printf("\033[1;31m------------------------------------------------\n");
            printf("     ALAMAT YANG DIMASUKKAN TIDAK VALID!\n");
            printf("------------------------------------------------\033[0m\n");
        } else {
            break;
        }
    }

    while (1) {
        printf("No HP               : ");
        scanf(" %[^\n]s", pegawai->noHp);
        getchar();
        if (!validasiNoHP(pegawai->noHp) || pegawai->noHp[0] == '\n' || strlen(pegawai->noHp) < 8) {
            printf("\033[1;31m------------------------------------------------\n");
            printf("     NO HP YANG DIMASUKKAN TIDAK VALID!\n");
            printf("------------------------------------------------\033[0m\n");
        } else {
            break;
        }
    }
    
    while (1) {
        char tempInput[100];

        printf("Jabatan             : ");
        scanf(" %[^\n]s", pegawai->jabatan);  
        getchar();
        if (!validasiJabatan(pegawai->jabatan) || pegawai->jabatan[0] == '\n') {
            printf("\033[1;31m------------------------------------------------\n");
            printf("     JABATAN YANG DIMASUKKAN TIDAK VALID!\n");
            printf("------------------------------------------------\033[0m\n");
        } else {
            break;
        }
    }

    while (1) {
        char tempInput[100];

        printf("Golongan (D1/D2/D3) : ");
        scanf(" %[^\n]s", tempInput);
        getchar();

        int valid = 1;
        if (strlen(tempInput) != 2 || tempInput[0] != 'D' || (tempInput[1] != '1' && tempInput[1] != '2' && tempInput[1] != '3')) {
            valid = 0;
        }

        if (valid) {
            strcpy(pegawai->golongan, tempInput);
            if (pegawai->golongan[1] == '1') {
                pegawai->gajiPokok = 2500000;
            } else if (pegawai->golongan[1] == '2') {
                pegawai->gajiPokok = 2000000;
            } else if (pegawai->golongan[1] == '3') {
                pegawai->gajiPokok = 1500000;
            }
            break;
        } else {
            printf("\033[1;31m------------------------------------------------\n");
            printf("     MASUKKAN GOLONGAN YANG VALID!\n");
            printf("------------------------------------------------\033[0m\n");
        }
    }
    
    printf("********************************************************\n");
    printf("\tData pegawai berhasil dimasukkan!\n");
    printf("--------------------------------------------------------\n");
    printf(" Selanjutnya, masukkan jumlah jam lembur pada menu 2\n");
    printf("********************************************************\n");
}

int hitungGajiBulanan(const char* golongan, int jumlahJamLembur) {
    int gajiPokok = 0;
    int lemburanPerJam = 0;

    if (golongan[1] == '1') { // Jika golongan D1
        gajiPokok = 2500000;
        lemburanPerJam = 10000;
    } else if (golongan[1] == '2') { // Jika golongan D2
        gajiPokok = 2000000;
        lemburanPerJam = 5000;
    } else if (golongan[1] == '3') { // Jika golongan D3
        gajiPokok = 1500000;
        lemburanPerJam = 2500;
    }

    int gajiLemburan = jumlahJamLembur * lemburanPerJam;
    int totalGaji = gajiPokok + gajiLemburan;
    return totalGaji;
}

int validasiNama(const char* nama) {
    for (int i = 0; i < strlen(nama); i++) {
        if (!isalpha(nama[i]) && nama[i] != ' ' && nama[i] != '-' && nama[i] != '.') {
            return 0;
        }
    }
    return 1;
}

int validasiAlamat(const char *alamat) {
    int panjang = strlen(alamat);
    if (strlen(alamat) < 5) {
        return 0;
    }

    for (int i = 0; i < strlen(alamat); i++) {
        if (!isalnum(alamat[i]) && alamat[i] != ' ' && alamat[i] != ',' && alamat[i] != '.' && alamat[i] != '-') {
            // isalnum digunakan untuk memeriksa apakah karakter-karakter alamat merupakan angka atau huruf
            return 0; 
        }
    }
    return 1;
}

int validasiNIP(const char *nomor) {
    for (int i = 0; i < strlen(nomor); i++) {
        if (!isdigit(nomor[i])) {
            return 0;
        }
    }
    return 1;
}

int validasiLembur(const char *jam) {
    for (int i = 0; i < strlen(jam); i++) {
        if (!isdigit(jam[i])) {
            return 0;
        }
    }
    return 1;
}

int validasiNoHP(const char *nomor) {
    for (int i = 0; i < strlen(nomor); i++) {
        if (!isdigit(nomor[i]) && nomor[i] != '-' && nomor[i] != ' ' && nomor[i] != '(' && nomor[i] != ')' && nomor[i] != '+') {
            return 0;
        }
    }
    return 1;
}

int validasiJabatan(const char *jabatan) {
    for (int i = 0; i < strlen(jabatan); i++) {
        if (!isalnum(jabatan[i]) && jabatan[i] != ' ') {
            return 0;
        }
    }
    return 1;
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#elif defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
    system("clear");
#else
#error "OS not supported."
#endif
}

void programTitle() {
    printf("===============================================================================\n");
    printf("\t\t\tProgram Kalkulasi Gaji Bulanan\n");
    printf("===============================================================================\n");
}
