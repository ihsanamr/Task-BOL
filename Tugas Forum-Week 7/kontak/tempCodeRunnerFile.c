#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Kontak {
    char nama[100];
    char noHp[100];
    char noKantor[100];
    char email[100];
    char namaPerusahaan[100];
    struct Kontak* kontakSelanjutnya;
} KONTAK;


// Function Prototype
KONTAK* membuatKontak();
void menambahKontak(KONTAK* daftarKontak, int* jumlahKontak);
void menampilkanDaftarKontak(KONTAK* daftarKontak);
int validasiNama(char* nama);
int apakahNomor(const char *nomor);
int validasiEmail(const char *email);
int validasiNamaPerusahaan(const char *nama);

// MAIN FUNCTION
int main() {
    KONTAK* daftarKontak = NULL;
    int pilihanMenu;
    int jumlahKontak = 0;
    char hapusKontak[100], tempInput[100];

    while (1) {
        printf("\n===========================\n");
        printf("\tKONTAK\n");
        printf("===========================\n");

        printf("Selamat datang di kontak anda, silakan pilih menu:\n");
        printf("(1) Tambah kontak\n");
        printf("(2) Hapus kontak\n");
        printf("(3) Tampilkan daftar kontak\n");
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
                menambahKontak(daftarKontak, &jumlahKontak);
                break;
            case 2:

        }

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

void menambahKontak(KONTAK* daftarKontak, int* jumlahKontak) {
    KONTAK* kontakBaru = membuatKontak();
    
    printf("\nMembuat kontak ke-%d\n", *jumlahKontak + 1);

    while(1) {
        printf("Masukkan nama: ");
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
        printf("Masukkan nomor HP: ");
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
        printf("Masukkan nomor kantor: ");
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
        printf("Masukkan email: ");
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
    

    kontakBaru->kontakSelanjutnya = daftarKontak;
    daftarKontak = kontakBaru;
    *jumlahKontak++;
    puts("Kontak berhasil ditambahkan.");
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
    Kontak* saatIni = daftarKontak;
    if (saatIni == NULL) {
        printf("Daftar kontak kosong.\n");
    } else {
        printf("Daftar Kontak:\n");
        while (saatIni != NULL) {
            printf("Nama: %s\n", saatIni->nama);
            printf("Nomor HP: %s\n", saatIni->no_hp);
            printf("Nomor Kantor: %s\n", saatIni->no_kantor);
            printf("Email: %s\n", saatIni->email);
            printf("Nama Perusahaan: %s\n\n", saatIni->nama_perusahaan);
            saatIni = saatIni->next;
        }
    }
}