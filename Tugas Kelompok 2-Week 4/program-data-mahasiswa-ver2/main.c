#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_MAHASISWA 100 // Konstanta untuk jumlah maksimal mahasiswa

// Struct untuk mahasiswa
struct Mahasiswa {
    char nama[50];
    float quiz;
    float tugas;
    float absensi;
    float praktek;
    float uas;
    float rataRata;
    char status;
};

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

// Fungsi untuk memeriksa apakah string hanya mengandung huruf
int apakahHuruf(const char *huruf) {
    int i = 0;
    while (huruf[i] != '\0') {
        if (!isalpha(huruf[i])) { // Apakah setiap karakternya huruf?
            return 0; // Return 0 jika ternyata ada karakter yang bukan merupakan huruf
        }
        i++;
    }
    return 1; // Return 1 jika semua karakter adalah huruf
}

/* Fungsi pengecekan apakah nama yang dimasukkan user sudah sesuai */
int apakahNama(char *nama) {
  int length = strlen(nama);
  for (int i = 0; i < length; i++) {
    if (!isalpha(nama[i]) && nama[i] != ' ' && nama[i] != '-') { // Apakah nama yang dimasukkan user sudah sesuai?
      return 0;
    }
  }
  return 1;
}

// Fungsi untuk memeriksa apakah string hanya mengandung angka
int apakahNomor(const char *nomor) {
    int i = 0;
    while (nomor[i] != '\0') {
        if (!isdigit(nomor[i])) { // Apakah setiap karakternya angka?
            return 0; // Return 0 jika ternyata ada karakter yang bukan merupakan angka
        }
        i++;
    }
    return 1; // Return 1 jika semua karakter adalah angka
}

// Fungsi untuk memeriksa apakah string hanya mengandung angka atau titik desimal
int apakahNilai(const char *nilai) {
    int i = 0;
    size_t length = strlen(nilai);
    for (i = 0; i < length; i++) {
        if (nilai[0] == '.') {
            return 0;
        }
        if (!isdigit(nilai[i]) && nilai[i] != '.') { // Apakah setiap karakternya angka atau titik desimal?
            return 0; // Return 0 jika ternyata ada karakter yang bukan merupakan angka atau titik desimal
        }
    }
    return 1; // Return 1 jika semua karakter adalah angka atau titik desimal
}


// Fungsi untuk input nilai-nilai dari mahasiswa
float getInputNilai(const char *prompt) {
    float nilai;
    char inputSementara[100];

    do {
        printf("%s\t\t: ", prompt); // Menampilkan prompt pada layar user 
        if (fgets(inputSementara, sizeof(inputSementara), stdin) != NULL) {
            size_t length = strlen(inputSementara);
            if (length > 1) { // Pencegahan agar user tidak input enter saja
                if (length > 0 && inputSementara[length - 1] == '\n') {
                    inputSementara[length - 1] = '\0'; // Mengganti newline dari fgets menjadi null terminator
                    if (!apakahNilai(inputSementara) || atof(inputSementara) < 0 || atof(inputSementara) > 100) { // Validasi input nilai
                        printf("----------------------------------------------\n");
                        printf("    NILAI YANG DIMASUKKAN TIDAK VALID\n");
                        printf("----------------------------------------------\n");
                    } else {
                        nilai = atof(inputSementara); // Jika sudah benar, nilai diubah ke float dan dimasukkan ke variabel nilai
                        break;
                    }
                }
            } else {
                printf("----------------------------------------------\n");
                printf("       TIDAK MENERIMA INPUT KOSONG\n");
                printf("----------------------------------------------\n");
            }
        }
    } while (1);

    return nilai; // Mengembalikan nilai
}

// Fungsi untuk mengambil pilihan menu dari user
int getPilihanMenu() {
    int pilihan;
    char inputSementara[100];

    do {
        printf("Masukkan pilihan menu: ");
        if (fgets(inputSementara, sizeof(inputSementara), stdin) != NULL) {
            size_t length = strlen(inputSementara);
            if (length > 1) { // Pencegahan agar user tidak input enter saja
                if (length > 0 && inputSementara[length - 1] == '\n') {
                    inputSementara[length - 1] = '\0'; // Mengganti newline dari fgets menjadi null terminator
                    if (!apakahNomor(inputSementara) || strlen(inputSementara) > 2) { // Validasi input pilihan menu
                        printf("----------------------------------------------\n");
                        printf("     MASUKKAN PILIHAN MENU YANG VALID\n");
                        printf("----------------------------------------------\n");
                    } else {
                        sscanf(inputSementara, "%d", &pilihan); // Jika sudah benar, nilai diubah ke integer dan dimasukkan ke variabel pilihan
                        break;
                    }
                } 
            } else {
                printf("----------------------------------------------\n");
                printf("       TIDAK MENERIMA INPUT KOSONG\n");
                printf("----------------------------------------------\n");
            }   
            
        }
    } while (1);

    return pilihan; // Mengembalikan pilihan
}

// Fungsi untuk mengambil jumlah mahasiswa
int getJumlahMahasiswa() {
    int jumlahInputMahasiswa;
    char input[100];

    do {
        do {
            printf("Masukkan jumlah mahasiswa (min. 10 | max. 100): ");
            if (fgets(input, sizeof(input), stdin) != NULL) {
                size_t length = strlen(input);
                if (length > 1) { // Pencegahan agar user tidak input enter saja
                    if (length > 0 && input[length - 1] == '\n') {
                        input[length - 1] = '\0'; // Mengganti newline dari fgets menjadi null terminator
                        if (!apakahNomor(input)) { // Apakah input jumlah mahasiswa hanya berupa angka?
                            printf("----------------------------------------------\n");
                            printf("     MASUKKAN JUMLAH MAHASISWA YANG VALID\n");
                            printf("----------------------------------------------\n");
                        } else {
                            sscanf(input, "%d", &jumlahInputMahasiswa); // Jika sudah benar, nilai diubah ke integer dan dimasukkan ke variabel jumlahInputMahasiswa
                            break;
                        }
                    }
                } else {
                    printf("----------------------------------------------\n");
                    printf("       TIDAK MENERIMA INPUT KOSONG\n");
                    printf("----------------------------------------------\n");
                }
            }
        } while (1);
    } while (jumlahInputMahasiswa < 10 || jumlahInputMahasiswa > 100); // Validasi jumlah mahasiswa minimal 10 dan maksimal 100 

    return jumlahInputMahasiswa;
}


// Fungsi untuk mengonversi nilai angka menjadi grade
char konversiNilaiKeGrade(float nilai) {
    if (nilai >= 85)
        return 'A';
    else if (nilai >= 70)
        return 'B';
    else if (nilai >= 55)
        return 'C';
    else if (nilai >= 40)
        return 'D';
    else
        return 'E';
}

int main() {
    // Deklarasi variabel
    int jumlahMahasiswa = 0, pilihanMenu, jumlahInputMahasiswa;
    struct Mahasiswa mahasiswa[MAX_MAHASISWA]; // Deklarasi array mahasiswa dengan ukuran maksimal MAX_MAHASISWA
    float totalRataRata = 0;

    do {
        // Memanggil fungsi untuk membersihkan layar konsol
        clearScreen();
        // Header
        printf("===============================================\n");
        printf("       PROGRAM INPUT DATA MAHASISWA\n");
        printf("===============================================\n");

        // Menu
        printf("Menu:\n");
        printf("1. Memulai program\n");
        printf("2. Informasi program\n");
        printf("3. Keluar\n");

        pilihanMenu = getPilihanMenu(); // Mengambil pilihan menu dari user

        switch (pilihanMenu) {
            case 1:
                // Pilihan 1: Memulai program
                printf("\n"); 
                // Memanggil fungsi untuk mengambil jumlah mahasiswa dari input user
                jumlahInputMahasiswa = getJumlahMahasiswa();

                printf("\nTekan 'Enter' untuk melanjutkan...");
                while (getchar() != '\n'); // Membersihkan buffer
                printf("\n");

                // Pengulangan untuk memasukkan data mahasiswa sejumlah jumlahInputMahasiswa
                for (int i = 0; i < jumlahInputMahasiswa; i++) {
                    printf("-----------------------------------------------\n");
                    printf("Data Mahasiswa ke-%d\n", i + 1);

                    do {
                        printf("Masukkan nama mahasiswa\t: ");
                        if (fgets(mahasiswa[i].nama, sizeof(mahasiswa[i].nama), stdin) != NULL) {
                            size_t length = strlen(mahasiswa[i].nama);
                            if (length > 1) { // Pencegahan agar user tidak input enter saja
                                if (length > 0 && mahasiswa[i].nama[length - 1] == '\n') {
                                mahasiswa[i].nama[length - 1] = '\0'; // Mengganti newline dari fgets menjadi null terminator
                                    if (!apakahHuruf(mahasiswa[i].nama)) { // Validasi input nama mahasiswa
                                        printf("----------------------------------------------\n");
                                        printf("  NAMA MAHASISWA YANG DIMASUKKAN TIDAK VALID \n");
                                        printf("----------------------------------------------\n");
                                    } else {
                                        break;
                                    }
                                }
                            } else  {
                                printf("----------------------------------------------\n");
                                printf("       TIDAK MENERIMA INPUT KOSONG\n");
                                printf("----------------------------------------------\n");
                            }
                            
                        }
                    } while (1);

                    // Memasukkan nilai dari input user ke struct mahasiswa
                    mahasiswa[i].quiz = getInputNilai("Nilai Quiz");
                    mahasiswa[i].tugas = getInputNilai("Nilai Tugas");
                    mahasiswa[i].absensi = getInputNilai("Nilai Absensi");
                    mahasiswa[i].praktek = getInputNilai("Nilai Praktek");
                    mahasiswa[i].uas = getInputNilai("Nilai UAS");

                    printf("----------------------------------------------\n");

                    // Menghitung rata-rata nilai mahasiswa
                    mahasiswa[i].rataRata = (mahasiswa[i].quiz + mahasiswa[i].tugas + mahasiswa[i].absensi + mahasiswa[i].praktek + mahasiswa[i].uas) / 5;
                    totalRataRata += mahasiswa[i].rataRata;
                    jumlahMahasiswa++;

                    // Ternary Operator untuk menentukan kelulusan mahasiswa
                    // L = Lulus, T = Tidak Lulus
                    mahasiswa[i].status = (mahasiswa[i].rataRata >= 55) ? 'L' : 'T'; 

                    printf("\nTekan 'Enter' untuk melanjutkan...");
                    while (getchar() != '\n');
                    printf("\n");
                }
                
                // Menampilkan rekap data semua mahasiswa
                printf("\n==============================================\n");
                printf("           Rekap Data Semua Mahasiswa:\n");
                printf("==============================================\n\n");
                for (int i = 0; i < jumlahMahasiswa; i++) {
                    printf("-----------------------------------------------\n");
                    printf("Data Mahasiswa ke-%d\n", i + 1);
                    printf("Nama mahasiswa\t\t: %s\n", mahasiswa[i].nama);
                    printf("Nilai Quiz\t\t: %.2f (Grade: %c)\n", mahasiswa[i].quiz, konversiNilaiKeGrade(mahasiswa[i].quiz));
                    printf("Nilai Tugas\t\t: %.2f (Grade: %c)\n", mahasiswa[i].tugas, konversiNilaiKeGrade(mahasiswa[i].tugas));
                    printf("Nilai Absensi\t\t: %.2f (Grade: %c)\n", mahasiswa[i].absensi, konversiNilaiKeGrade(mahasiswa[i].absensi));
                    printf("Nilai Praktek\t\t: %.2f (Grade: %c)\n", mahasiswa[i].praktek, konversiNilaiKeGrade(mahasiswa[i].praktek));
                    printf("Nilai UAS\t\t: %.2f (Grade: %c)\n", mahasiswa[i].uas, konversiNilaiKeGrade(mahasiswa[i].uas));
                    printf("Nilai Rata-rata\t\t: %.2f (Grade: %c)\n", mahasiswa[i].rataRata, konversiNilaiKeGrade(mahasiswa[i].rataRata));
                    if (mahasiswa[i].status == 'L') {
                        printf("Status kelulusan\t: Lulus\n");
                    } else {
                        printf("Status kelulusan\t: Tidak Lulus\n");
                    }
                    printf("-----------------------------------------------\n\n");
                }

                printf("==============================================\n");
                printf("Jumlah mahasiswa\t\t\t: %d\n", jumlahMahasiswa);
                if (jumlahMahasiswa > 0) {
                    printf("Nilai rata-rata keseluruhan mahasiswa\t: %.2f\n", totalRataRata / jumlahMahasiswa); // Menghitung nilai rata-rata keseluruhan mahasiswa
                }
                printf("==============================================\n");
                break;

            case 2:
                printf("\n============================================================\n");
                printf("Program ini dibuat oleh kelompok 7 yang beranggota:\n");
                printf("1. ERWIN SAPUTRA YAPTO (2301970076)\n");
                printf("2. IFTIKHARUS RAUDANA MUNTAZAR (2702381622)\n");
                printf("3. IHSAN AMRI MUYASSAR (2702350592)\n");
                printf("4. WAHYU MENTARI MAYADITA (2702347723)\n");
                printf("==============================================================\n");
                break;

            case 3:
                printf("----------------------------------------------\n");
                printf("  TERIMA KASIH TELAH MENGGUNAKAN PROGRAM INI\n");
                printf("----------------------------------------------\n");
                return 0;

            default:
                printf("----------------------------------------------\n");
                printf("      MENU TIDAK TERSEDIA PADA PROGRAM \n");
                printf("----------------------------------------------\n");
                break;
        }
        printf("\nTekan 'Enter' untuk melanjutkan...");
        while (getchar() != '\n');
    } while (pilihanMenu != 3);

    return 0;
}
