#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_BUKU 1000 // Konstanta untuk jumlah maksimal buku yang dapat disimpan

// Struct untuk data buku
typedef enum KategoriBuku {
    Fiksi,
    Teks,
    Sejarah,
    Novel,
    KategoriLain
} Kategori;

enum Penerbit {
    Gramedia,
    ElexMedia,
    AndiOffset,
    Pustaka,
    PenerbitLain
};

typedef struct Buku {
    char ISBN[14];
    char judul[100];
    char pengarang[100];
    int tahunTerbit;
    enum Penerbit penerbit;
    Kategori kategori;
    int statusPeminjaman;
} Buku;

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

// Fungsi untuk memeriksa apakah string hanya mengandung angka
int apakahNomor(const char *nomor) {
    int i = 0;
    while (nomor[i] != '\0') {
        if (!isdigit(nomor[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

// Fungsi untuk menampilkan data buku
void menampilkanBuku(struct Buku buku) {
    printf("ISBN\t\t: %s\n", buku.ISBN);
    printf("Judul\t\t: %s\n", buku.judul);
    printf("Pengarang\t: %s\n", buku.pengarang);
    printf("Tahun Terbit\t: %d\n", buku.tahunTerbit);

    switch (buku.penerbit) {
        case Gramedia:
            printf("Penerbit\t: Gramedia\n");
            break;
        case ElexMedia:
            printf("Penerbit\t: Elex Media\n");
            break;
        case AndiOffset:
            printf("Penerbit\t: Andi Offset\n");
            break;
        case Pustaka:
            printf("Penerbit\t: Pustaka\n");
            break;
        case PenerbitLain:
            printf("Penerbit\t: Lainnya\n");
            break;
    }

    switch (buku.kategori) {
        case Fiksi:
            printf("Kategori\t: Buku Fiksi\n");
            break;
        case Teks:
            printf("Kategori\t: Buku Teks\n");
            break;
        case Sejarah:
            printf("Kategori\t: Buku Sejarah\n");
            break;
        case Novel:
            printf("Kategori\t: Buku Novel\n");
            break;
        case KategoriLain:
            printf("Kategori\t: Lainnya\n");
            break;
    }

    if (buku.statusPeminjaman == 1) {
        printf("Status\t\t: Buku sudah dipinjam.\n");
    } else {
        printf("Status\t\t: Buku belum dipinjam.\n");
    }

    printf("\n");
}

// Fungsi untuk validasi kapasitas buku
int validasiKapasitasBuku(const char *input) {
    int kapasitasBuku;
    while (1) {
        printf("Masukkan kapasitas buku dalam perpustakaan untuk pertama kali (Min. 10, Max. 1000): ");
        scanf("%[^\n]s", input);
        getchar();
        if (apakahNomor(input) && input[0] != '\n' && strlen(input) != 1) {
            kapasitasBuku = atoi(input);
            if (kapasitasBuku > MAX_BUKU) {
                kapasitasBuku = MAX_BUKU;
            }
            break;
        } else {
            printf("\033[1;31m------------------------------------------------\n");
            printf("     MASUKKAN KAPASITAS BUKU YANG VALID\n");
            printf("------------------------------------------------\033[0m\n");
        }
    }
    return kapasitasBuku;
}

// Fungsi untuk validasi ISBN
int validasiISBN(const char *ISBN, const struct Buku lemariBuku[], int countBuku) {
    int isbnSudahAda = 0;
    while (1) {
        printf("ISBN (13 digit): ");
        scanf("%[^\n]s", ISBN);
        getchar();
        isbnSudahAda = 0;
        for (int i = 0; i < countBuku; i++) {
            if (strcmp(lemariBuku[i].ISBN, ISBN) == 0) {
                isbnSudahAda = 1;
                printf("\033[1;31m------------------------------------------------\n"); 
                printf("     ISBN %s sudah terdaftar\n", ISBN);
                printf("------------------------------------------------\033[0m\n");
                break;
            }
        }
        if (isbnSudahAda) {
            continue;
        }
        if (strlen(ISBN) == 13 && apakahNomor(ISBN)) {
            break;
        }
        printf("\033[1;31m----------------------------------------------\n");
        printf("     MASUKKAN ISBN (13 DIGIT) YANG VALID\n");
        printf("----------------------------------------------\033[0m\n");
    }
    return 1; // ISBN valid
}

// Fungsi untuk validasi judul
int validasiJudul(const char *judul) {
    while (1) {
        printf("Judul: ");
        scanf("%[^\n]s", judul);
        getchar();
        if (strlen(judul) <= 100 && strlen(judul) > 1) {
            break;
        }
        printf("\033[1;31m--------------------------------------------------------\n");
        printf("     MASUKKAN JUDUL YANG VALID (PANJANG MAX 100 KARAKTER)\n");
        printf("--------------------------------------------------------\033[0m\n");
    }
    return 1;  // Judul valid
}

// Fungsi untuk validasi kategori
int validasiKategori(const char *input, int *kategori) {
    int valid = 1;
    while (1) {
        printf("Kategori Buku (0 ->  Novel, 1 -> Fiksi, 2 -> Teks, 3 -> Sejarah, 4 -> Lainnya): ");
        scanf("%[^\n]s", input);
        getchar();
        valid = 1;
        for (int i = 0; i < strlen(input); i++) {
            if (!isdigit(input[i])) {
                valid = 0;
                break;
            }
        }
        *kategori = atoi(input);
        if (valid && strlen(input) == 1 && *kategori >= 0 && *kategori <= KategoriLain) {
            break;
        }
        printf("\033[1;31m---------------------------------------------------\n");
        printf("     MASUKKAN PILIHAN KATEGORI BUKU YANG VALID\n");
        printf("---------------------------------------------------\033[0m\n");
    }
    return 1;  // Kategori valid
}

// Fungsi untuk validasi nama pengarang
int validasiPengarang(const char *pengarang) {
    int valid = 1;
    while (1) {
        printf("Pengarang (alfabet, spasi, '-', '.'): ");
        scanf("%[^\n]s", pengarang);
        getchar();
        valid = 1;
        for (int i = 0; i < strlen(pengarang); i++) {
            if (!isalpha(pengarang[i]) && pengarang[i] != ' ' && pengarang[i] != '-' && pengarang[i] != '.') {
                valid = 0;
                break;
            }
        }
        if (valid && strlen(pengarang) <= 100 && strlen(pengarang) > 1) {
            break;
        }
        printf("\033[1;31m-------------------------------------------------------------------------------------------------\n");
        printf("     MASUKKAN PENGARANG YANG VALID (ALFABET, SPASI, '-') (PANJANG MAX 100 KARAKTER)\n");
        printf("-------------------------------------------------------------------------------------------------\033[0m\n");
    }
    return 1;  // Pengarang valid
}

// Fungsi untuk validasi tahun terbit
int validasiTahunTerbit(const char *tahunTerbit, int *tahun) {
    int valid = 1;
    while (1) {
        printf("Tahun Terbit: ");
        scanf("%[^\n]s", tahunTerbit);
        getchar();
        valid = 1;
        for (int i = 0; i < strlen(tahunTerbit); i++) {
            if (!isdigit(tahunTerbit[i])) {
                valid = 0;
                break;
            }
        }
        if (valid && strlen(tahunTerbit) == 4) {
            *tahun = atoi(tahunTerbit);
            break;
        }
        printf("\033[1;31m----------------------------------------------------\n");
        printf("     MASUKKAN TAHUN TERBIT YANG VALID (4 DIGIT)\n");
        printf("----------------------------------------------------\033[0m\n");
    }
    return 1;  // Tahun terbit valid
}

// Fungsi untuk validasi penerbit
int validasiPenerbit(const char *input, int *penerbit) {
    int valid = 1;
    while (1) {
        printf("Penerbit (0 -> Gramedia, 1 -> Elex Media, 2 -> Andi Offset, 3 -> Pustaka, 4 -> Lainnya): ");
        scanf("%[^\n]s", input);
        getchar();
        valid = 1;
        for (int i = 0; i < strlen(input); i++) {
            if (!isdigit(input[i])) {
                valid = 0;
                break;
            }
        }
        *penerbit = atoi(input);
        if (valid && strlen(input) == 1 && *penerbit >= 0 && *penerbit <= PenerbitLain) {
            break;
        }
        printf("\033[1;31m------------------------------------------------\n");
        printf("     MASUKKAN PILIHAN PENERBIT YANG VALID\n");
        printf("------------------------------------------------\033[0m\n");
    }
    return 1;  // Penerbit valid
}

// Fungsi untuk menambah buku
void menambahBuku(Buku lemariBuku[], int *countBuku, int kapasitasBuku) {
    char input[100];
    int kategori, tahun, penerbit;

    if (*countBuku < kapasitasBuku) {
        Buku buku;
        int isbnSudahAda = 0;
        printf("\n============================================\n");
        printf("          MENGISI DATA BUKU KE-%d\n", *countBuku + 1);
        printf("============================================\n");
        
        while (1) {
            if (!validasiISBN(buku.ISBN, lemariBuku, *countBuku)) {
                continue;
            }
            
            while (1) {
                if (!validasiJudul(buku.judul)) {
                    continue;
                }
                
                if (!validasiKategori(input, &kategori)) {
                    continue;
                }
                
                while (1) {
                    if (!validasiPengarang(buku.pengarang)) {
                        continue;
                    }
                    
                    while (1) {
                        if (!validasiTahunTerbit(input, &tahun)) {
                            continue;
                        }
                        
                        if (!validasiPenerbit(input, &penerbit)) {
                            continue;
                        }

                        buku.kategori = kategori;
                        buku.tahunTerbit = tahun;
                        buku.penerbit = penerbit;
                        buku.statusPeminjaman = 0;
                        lemariBuku[*countBuku] = buku;
                        (*countBuku)++;
                        printf("Buku telah ditambahkan.\n\n");
                        return;
                    }
                }
            }
        }
    } else {
        printf("Perpustakaan penuh.\n\n");
    }
}

// Fungsi untuk menampilkan semua buku
void tampilkanSemuaBuku(const Buku lemariBuku[], int countBuku) {
    if (countBuku == 0) {
        printf("\033[1;31m------------------------------------------------\n");
        printf("              DAFTAR BUKU KOSONG\n");
        printf("------------------------------------------------\033[0m\n");
    } else {
        printf("\n============================================\n");
        printf("                 DAFTAR BUKU\n");
        printf("============================================\n");
        for (int i = 0; i < countBuku; i++) {
            menampilkanBuku(lemariBuku[i]);
        }
    }
}

// Fungsi untuk menghapus buku
void menghapusBuku(Buku lemariBuku[], int *countBuku) {
    char isbnHapus[100];
    printf("\n============================================\n");
    printf("                 HAPUS BUKU\n");
    printf("============================================\n");
    printf("ISBN buku yang akan dihapus: ");
    scanf("%[^\n]s", isbnHapus);
    getchar();
    int bukuDitemukan = 0;

    for (int i = 0; i < *countBuku; i++) {
        if (strcmp(lemariBuku[i].ISBN, isbnHapus) == 0) {
            for (int j = i; j < *countBuku - 1; j++) {
                lemariBuku[j] = lemariBuku[j + 1];
            }
            (*countBuku)--;
            bukuDitemukan = 1;
            printf("Buku telah dihapus.\n\n");
            break;
        }
    }

    if (!bukuDitemukan) {
        printf("Buku dengan ISBN %s tidak ditemukan.\n\n", isbnHapus);
    }
}

// Fungsi untuk meminjam buku
void pinjamBuku(Buku lemariBuku[], int countBuku) {
    char isbnPinjam[100];
    printf("\n============================================\n");
    printf("                 PINJAM BUKU\n");
    printf("============================================\n");
    printf("ISBN buku yang akan dipinjam: ");
    scanf("%[^\n]s", isbnPinjam);
    getchar();
    int bukuDitemukan = 0;

    for (int i = 0; i < countBuku; i++) {
        if (strcmp(lemariBuku[i].ISBN, isbnPinjam) == 0) {
            bukuDitemukan = 1;
            if (lemariBuku[i].statusPeminjaman == 0) {
                lemariBuku[i].statusPeminjaman = 1;
                printf("Buku dengan ISBN %s berhasil dipinjam.\n\n", isbnPinjam);
            } else {
                printf("Buku dengan ISBN %s sudah dipinjam.\n\n", isbnPinjam);
            }
            break;
        }
    }

    if (!bukuDitemukan) {
        printf("Buku dengan ISBN %s tidak ditemukan.\n\n", isbnPinjam);
    }
}

// Fungsi untuk mengembalikan buku
void mengembalikanBuku(Buku lemariBuku[], int countBuku) {
    char isbnKembalikan[100];
    printf("\n============================================\n");
    printf("                 KEMBALIKAN BUKU\n");
    printf("============================================\n");
    printf("ISBN buku yang akan dikembalikan: ");
    scanf("%[^\n]s", isbnKembalikan);
    getchar();
    int bukuDitemukan = 0;

    for (int i = 0; i < countBuku; i++) {
        if (strcmp(lemariBuku[i].ISBN, isbnKembalikan) == 0) {
            bukuDitemukan = 1;
            if (lemariBuku[i].statusPeminjaman == 1) {
                lemariBuku[i].statusPeminjaman = 0;
                printf("Buku dengan ISBN %s berhasil dikembalikan.\n\n", isbnKembalikan);
            } else {
                printf("Buku dengan ISBN %s sudah tersedia atau tidak ada yang meminjam.\n\n", isbnKembalikan);
            }
            break;
        }
    }

    if (!bukuDitemukan) {
        printf("Buku dengan ISBN %s tidak ditemukan.\n\n", isbnKembalikan);
    }
}

int main() {
    char tempInput[50];
    int pilihanMenu;
    Buku lemariBuku[MAX_BUKU];
    int kapasitasBuku = 0;
    int countBuku = 0;

    while (1) {
        clearScreen();
        //Header
        printf("==================================\n");
        printf("\tPUSTAKA VIRTUAL\n");
        printf("==================================\n");
        printf("\n");

        //Menu
        printf("Selamat datang, silakan pilih menu dibawah ini:\n");
        printf("(1) Tambah buku\n");
        printf("(2) Tampilkan buku\n");
        printf("(3) Hapus data buku\n");
        printf("(4) Pinjam buku\n");
        printf("(5) Kembalikan buku\n");
        printf("(6) Keluar\n");
        printf("\n");

        //Validasi input pilihan menu
        while (1) {
            printf("Masukkan pilihan (1/2/3/4/5/6): ");
            scanf("%[^\n]s", tempInput);
            getchar();

            if (strlen(tempInput) == 1 && isdigit(tempInput[0]) && tempInput[0] != '\n') {
                pilihanMenu = atoi(tempInput);
                if (pilihanMenu >= 1 && pilihanMenu <= 6) {
                    break;
                }
            }

            printf("\033[1;31m------------------------------------------------\n");
            printf("     MASUKKAN PILIHAN MENU YANG VALID\n");
            printf("------------------------------------------------\033[0m\n");
        }
        printf("\n");

        //Pilihan menu
        switch (pilihanMenu) {
            case 1:
                if (kapasitasBuku == 0) {
                    kapasitasBuku = validasiKapasitasBuku(tempInput);
                }
                printf("\n");
                menambahBuku(lemariBuku, &countBuku, kapasitasBuku);
                break;
            case 2:
                tampilkanSemuaBuku(lemariBuku, countBuku);
                break;
            case 3:
                if (countBuku == 0) {
                    printf("\033[1;31m------------------------------------------------\n");
                    printf("              DAFTAR BUKU KOSONG\n");
                    printf("------------------------------------------------\033[0m\n");
                } else {
                    menghapusBuku(lemariBuku, &countBuku);
                }
                break;
            case 4:
                if (countBuku == 0) {
                    printf("\033[1;31m------------------------------------------------\n");
                    printf("              DAFTAR BUKU KOSONG\n");
                    printf("------------------------------------------------\033[0m\n");
                } else {
                    pinjamBuku(lemariBuku, countBuku);
                }
                break;
            case 5:
                if (countBuku == 0) {
                    printf("\033[1;31m------------------------------------------------\n");
                    printf("              DAFTAR BUKU KOSONG\n");
                    printf("------------------------------------------------\033[0m\n");
                } else {
                    mengembalikanBuku(lemariBuku, countBuku);
                }
                break;
            case 6:
                printf("Terima kasih telah menggunakan program ini!\n");
                return 0;
            default:
                printf("Pilihan tidak valid.\n\n");
        }
        printf("\nKlik enter untuk melanjutkan...");
        getchar();
    }

    return 0;
}
