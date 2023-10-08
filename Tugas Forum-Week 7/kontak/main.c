#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


// Struct untuk kontak
typedef struct Kontak {
    char nama[100];
    char noHp[100];
    char noKantor[100];
    char email[100];
    char namaPerusahaan[100];
    struct Kontak* kontakSelanjutnya;
} KONTAK;


// Function Prototype
/* Fungsi membuatKontak digunakan untuk membuat data kontak baru */
KONTAK* membuatKontak();
/* Fungsi menambahKontak digunakan untuk menambah data kontak ke daftar kontak */
void menambahKontak(KONTAK** daftarKontak, int* jumlahKontak);
/* Fungsi menampilkanDaftarKontak digunakan untuk menampilkan daftar kontak */
void menampilkanDaftarKontak(KONTAK* daftarKontak);
/* Fungsi menghapusKontak digunakan untuk menghapus kontak berdasarkan nama kontak */
void menghapusKontak(KONTAK** daftarKontak, char* namaTarget);
/* Fungsi validasi nama digunakan untuk memvalidasi nama yang dimasukkan.
Nama akan diterima jika stringnya hanya mengandung huruf, spasi, tanda '-', atau tanda '.' */
int validasiNama(char* nama);
/* Fungsi validasi nomor digunakan untuk memvalidasi nomor hp yang dimasukkan. 
Nomor akan diterima jika stringnya hanya mengandung angka, spasi, tanda "()", atau tanda '-'*/
int apakahNomor(const char *nomor);
/* Fungsi validasi email digunakan untuk memvalidasi email yang dimasukkan.
Email akan diterima jika stringnya sudah mengandung tanda '@' dan '.' */
int validasiEmail(const char *email);
/* Fungsi validasi nama perusahaan digunakan untuk memvalidasi nama perusahaan yang dimasukkan.
Nama perusahaan akan diterima jika stringnya hanya mengandung huruf, spasi, atau tanda '-' */
int validasiNamaPerusahaan(const char *nama);
/* Fungsi clearScreen digunakan untuk membersihkan layar konsol */
void clearScreen();

// MAIN FUNCTION
int main() {
    // Deklarasi variabel
    KONTAK* daftarKontak = NULL;
    int pilihanMenu;
    int jumlahKontak = 0;
    char hapusKontak[100], tempInput[100];

    // Menu utama
    while (1) {
        clearScreen();
        printf("\n===========================\n");
        printf("\t   KONTAK\n");
        printf("===========================\n");

        printf("Selamat datang di kontak, silakan pilih menu:\n");
        printf("(1) Tambah kontak\n");
        printf("(2) Tampilkan daftar kontak\n");
        printf("(3) Hapus kontak\n");
        printf("(4) Keluar\n");
        printf("\n");

        // Input menu dari user
        while (1) {
            printf("Pilihan: ");
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

        // Menampilkan menu sesuai pilihan user
        switch (pilihanMenu) {
            case 1:
                // Memasukkan data kontak
                menambahKontak(&daftarKontak, &jumlahKontak);
                break;
            case 2:
                // Menampilkan daftar kontak
                menampilkanDaftarKontak(daftarKontak);
                break;
            case 3:
                // Menghapus kontak
                while (1) {
                    printf("\nApakah anda yakin ingin menghapus kontak? (y/n): ");
                    scanf("%[^\n]s", tempInput);
                    getchar();
                    if (strlen(tempInput) == 1 && (tempInput[0] == 'y' || tempInput[0] == 'n' || tempInput[0] == 'Y' || tempInput[0] == 'N')) {
                        break;
                    }
                    printf("\033[1;31m------------------------------------------------\n");
                    printf("     MASUKKAN PILIHAN YANG VALID!\n");
                    printf("------------------------------------------------\033[0m\n");
                }
                if (tempInput[0] == 'y' || tempInput[0] == 'Y') {
                    while (1) {
                        printf("\nMasukkan nama kontak yang ingin dihapus: ");
                        scanf(" %[^\n]s", hapusKontak);
                        getchar();
                        if (!validasiNama(hapusKontak) || hapusKontak[0] == '\n') {
                            printf("\033[1;31m------------------------------------------------\n");
                            printf("     NAMA YANG DIMASUKKAN TIDAK VALID!\n");
                            printf("------------------------------------------------\033[0m\n");
                        } else {
                            break;
                        }
                    }
                    menghapusKontak(&daftarKontak, hapusKontak);
                }
                break;
            case 4:
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
    }
    
    return 0;
}

// Function Definition
KONTAK* membuatKontak() {
    KONTAK* kontakBaru = (KONTAK*) malloc(sizeof(KONTAK));
    if (kontakBaru == NULL) {
        puts("Gagal membuat kontak.\n");
        exit(1);
    }
    kontakBaru->kontakSelanjutnya = NULL;
    return kontakBaru;
}

void menambahKontak(KONTAK** daftarKontak, int* jumlahKontak) {
    KONTAK* kontakBaru = membuatKontak();
    
    printf("\n=============================================\n");
    printf("          MASUKKAN KONTAK KE-%d\n", *jumlahKontak + 1);
    printf("=============================================\n");

    while(1) {
        printf("Masukkan nama\t\t: ");
        scanf(" %[^\n]s", kontakBaru->nama);
        getchar();
        if (!validasiNama(kontakBaru->nama) || kontakBaru->nama[0] == '\n') {
            printf("\033[1;31m------------------------------------------------\n");
            printf("     NAMA YANG DIMASUKKAN TIDAK VALID!\n");
            printf("------------------------------------------------\033[0m\n");
        } else {
            break;
        }
    }
    
    while (1) {
        printf("Masukkan nomor HP\t: ");
        scanf(" %[^\n]s", kontakBaru->noHp);
        getchar();
        if (!apakahNomor(kontakBaru->noHp) || kontakBaru->noHp[0] == '\n' || strlen(kontakBaru->noHp) < 8) {
            printf("\033[1;31m------------------------------------------------\n");
            printf("     NOMOR HP YANG DIMASUKKAN TIDAK VALID!\n");
            printf("------------------------------------------------\033[0m\n");
        } else {
            break;
        } 
    }
    
    while (1) {
        printf("Masukkan nomor kantor\t: ");
        scanf(" %[^\n]s", kontakBaru->noKantor);
        getchar();
        if (!apakahNomor(kontakBaru->noKantor) || kontakBaru->noKantor[0] == '\n' || strlen(kontakBaru->noKantor) < 8) {
            printf("\033[1;31m------------------------------------------------\n");
            printf("     NOMOR KANTOR YANG DIMASUKKAN TIDAK VALID!\n");
            printf("------------------------------------------------\033[0m\n");
        } else {
            break;
        }
    }

    while (1) {
        printf("Masukkan email\t\t: ");
        scanf(" %[^\n]s", kontakBaru->email);
        getchar();
        if (!validasiEmail(kontakBaru->email) || kontakBaru->email[0] == '\n') {
            printf("\033[1;31m------------------------------------------------\n");
            printf("     EMAIL YANG DIMASUKKAN TIDAK VALID!\n");
            printf("------------------------------------------------\033[0m\n");
        } else {
            break;
        }
    }
    
    while (1) {
        printf("Masukkan nama perusahaan: ");
        scanf(" %[^\n]s", kontakBaru->namaPerusahaan);
        getchar();
        if (!validasiNamaPerusahaan(kontakBaru->namaPerusahaan) || kontakBaru->namaPerusahaan[0] == '\n') {
            printf("\033[1;31m------------------------------------------------\n");
            printf("     NAMA PERUSAHAAN YANG DIMASUKKAN TIDAK VALID!\n");
            printf("------------------------------------------------\033[0m\n");
        } else {
            break;
        }
    }
    

    kontakBaru->kontakSelanjutnya = *daftarKontak;
    *daftarKontak = kontakBaru;
    *jumlahKontak++;
    puts("---------------------------------------------");
    puts("Kontak berhasil ditambahkan!");
}

int validasiNama(char* nama) {
    for (int i = 0; i < strlen(nama); i++) {
        if (!isalpha(nama[i]) && nama[i] != ' ' && nama[i] != '-' && nama[i] != '.') {
            return 0;
        }
    }
    return 1;
}

int validasiNamaPerusahaan(const char* nama) {
    for (int i = 0; i < strlen(nama); i++) {
        if (!isalpha(nama[i]) && nama[i] != ' ' && nama[i] != '-') {
            return 0;
        }
    }
    return 1;
}

int apakahNomor(const char *nomor) {
    for (int i = 0; i < strlen(nomor); i++) {
        if (!isdigit(nomor[i]) && nomor[i] != '-' && nomor[i] != ' ' && nomor[i] != '(' && nomor[i] != ')' && nomor[i] != '+') {
            return 0;
        }
    }
    return 1;
}

int validasiEmail(const char *email) {
    int adaAt = 0, adaDot = 0;
    
    for (int i = 0; i < strlen(email); i++) {
        if (email[i] == '@') {
            adaAt = 1;
        }
        if (email[i] == '.') {
            adaDot = 1;
        }
    }
    
    return adaAt && adaDot;
}

void menampilkanDaftarKontak(KONTAK* daftarKontak) {
    KONTAK* saatIni = daftarKontak;
    if (saatIni == NULL) {
        printf("\n\033[1;31m------------------------------------------------\n");
        printf("               DAFTAR KONTAK KOSONG\n");
        printf("------------------------------------------------\033[0m\n");
    } else {
        printf("\n============================================\n");
        printf("                 DAFTAR KONTAK\n");
        printf("============================================\n");
        while (saatIni != NULL) {
            printf("Nama\t\t: %s\n", saatIni->nama);
            printf("Nomor HP\t: %s\n", saatIni->noHp);
            printf("Nomor Kantor\t: %s\n", saatIni->noKantor);
            printf("Email\t\t: %s\n", saatIni->email);
            printf("Nama Perusahaan : %s\n\n", saatIni->namaPerusahaan);
            saatIni = saatIni->kontakSelanjutnya;
        }
    }
}

// Fungsi untuk menghapus kontak berdasarkan nama
void menghapusKontak(KONTAK** daftarKontak, char* hapusNama) {
    KONTAK* kontakSaatIni = *daftarKontak;
    KONTAK* kontakSebelumnya = NULL;
    
    while (kontakSaatIni != NULL) {
        if (strcmp(kontakSaatIni->nama, hapusNama) == 0) {
            if (kontakSebelumnya == NULL) {
                *daftarKontak = kontakSaatIni->kontakSelanjutnya;
            } else {
                kontakSebelumnya->kontakSelanjutnya = kontakSaatIni->kontakSelanjutnya;
            }
            free(kontakSaatIni);
            printf("Kontak dengan nama %s telah dihapus.\n", hapusNama);
            return;
        }
        kontakSebelumnya = kontakSaatIni;
        kontakSaatIni = kontakSaatIni->kontakSelanjutnya;
    }
    
    printf("\nKontak dengan nama %s tidak ditemukan.\n", hapusNama);
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