/*Group 7-JCCA
1. Erwin Saputra Yapto (2301970076)
2. Iftikharus Raudana Muntazar (2702381622)
3. Ihsan Amri Muyassar (2702350592)
4. Wahyu Mentari Mayadita (2702347723) 

Referensi:
https://www.tutorialspoint.com/how-to-measure-time-taken-by-a-function-in-c#:~:text=For%20this%20problem%2C%20we%20will,values%20to%20get%20the%20differences
https://www.geeksforgeeks.org/how-to-measure-time-taken-by-a-program-in-c/
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
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

// Fungsi untuk memeriksa apakah string hanya mengandung huruf
int apakahHuruf(const char *huruf)
{
    int i = 0;

    while (huruf[i] != '\0')
    {
        if (!isalpha(huruf[i])) // Apakah setiap karakternya huruf?
        {
            return 0; // Return 0 jika ternyata ada karakter yang bukan merupakan huruf
        }
        i++;
    }
    return 1; // Return 1 jika semua karakter adalah huruf
}

// Fungsi untuk memeriksa apakah string hanya mengandung angka
int apakahNomor(const char *nomor)
{
    int i = 0;

    while (nomor[i] != '\0')
    {
        if (!isdigit(nomor[i])) // Apakah setiap karakternya angka?
        {
            return 0; // Return 0 jika ternyata ada karakter yang bukan merupakan angka
        }
        i++;
    }
    return 1; // Return 1 jika semua karakter adalah angka
}

// Fungsi untuk menghitung diskon berdasarkan waktu rental
float hitungDiskon(int jam)
{
    float diskon = 0;
    if (jam > 4 && jam <= 6)
    {
        diskon = 0.1;
    }
    else if (jam > 6 && jam <= 8)
    {
        diskon = 0.15;
    }
    else if (jam > 8 && jam <= 10)
    {
        diskon = 0.2;
    }
    else if (jam > 10)
    {
        diskon = 0.25;
    }
    return diskon;
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
            size_t length = strlen(inputSementara);
            if (length > 0 && inputSementara[length - 1] == '\n')
            {
                inputSementara[length - 1] = '\0';
                if (!apakahNomor(inputSementara) || strlen(inputSementara) > 2)
                {
                    printf("----------------------------------------------\n");
                    printf("     MASUKKAN PILIHAN MENU YANG VALID\n");
                    printf("----------------------------------------------\n");
                }
                else
                {
                    sscanf(inputSementara, "%d", &pilihan);
                    break;
                }
            }
        }
    } while (1);

    return pilihan;
}

// Fungsi untuk meminta konfirmasi y/n dari user
char getKonfirmasi()
{
    char pilihan;
    char inputSementara[100];

    do
    {
        fgets(inputSementara, sizeof(inputSementara), stdin);
        if (strlen(inputSementara) == 2 && (tolower(inputSementara[0]) == 'y' || tolower(inputSementara[0]) == 'n'))
        {
            pilihan = tolower(inputSementara[0]);
            break;
        }
        else
        {
            printf("Masukkan pilihan y/n: ");
        }
    } while (1);

    return pilihan;
}

// Fungsi untuk mengambil jumlah uang dari user
double getJumlahUang()
{
    double jumlahUang;
    char inputSementara[100];

    do
    {
        if (fgets(inputSementara, sizeof(inputSementara), stdin) != NULL)
        {
            size_t length = strlen(inputSementara);
            if (length > 1) {
                if (length > 0 && inputSementara[length - 1] == '\n')
                {
                    inputSementara[length - 1] = '\0';
                    if (!apakahNomor(inputSementara))
                    {
                        printf("Masukkan jumlah uang yang valid: Rp. ");
                    }
                    else
                    {
                        sscanf(inputSementara, "%lf", &jumlahUang);
                        break;
                    }
                }
            } else {
                printf("Masukkan jumlah uang yang valid: Rp. ");
            }
            
        }
    } while (1);

    return jumlahUang;
}

int main()
{
    // Deklarasi variabel
    float hargaPerJam = 10000, totalHarga, diskon;
    int pilihanMenu;
    char inputSementara[100];

    do
    {
        clearScreen();
        // Header
        printf("===============================================\n");
        printf("    SELAMAT DATANG DI WARNET BYTEBURST\n");
        printf("===============================================\n");

        // Menu
        printf("Menu:\n");
        printf("1. Merental komputer dulu baru bayar\n");
        printf("2. Membayar dulu baru merental\n");
        printf("3. Informasi program\n");
        printf("4. Keluar\n");

        pilihanMenu = getPilihanMenu(); // Mengambil pilihan menu dari user

        switch (pilihanMenu)
        {
            case 1:
                // Pilihan 1: Rental terlebih dahulu, lalu bayar
                printf("\n----------------------------------------------\n");
                printf("\nApakah anda ingin memulai sesi rental komputer? (y/n): ");
                char pilihanSesiRental;
                do
                {
                    pilihanSesiRental = getKonfirmasi(); // Konfirmasi y/n
                } while (pilihanSesiRental != 'y' && pilihanSesiRental != 'n');

                printf("\n----------------------------------------------\n");

                if (pilihanSesiRental == 'y') // Jika user memilih memulai sesi rental
                {
                    printf("\nTekan 'Enter' untuk memulai sesi....");
                    getchar();

                    time_t waktuMulai, waktuSelesai; // Deklarasi waktu mulai dan waktu selesai
                    time(&waktuMulai); // Mencatat waktu mulai
                    printf("\nSesi rental sedang berjalan. Tekan 'Enter' untuk mengakhiri sesi....");
                    getchar(); // Menunggu user selesai rental
                    time(&waktuSelesai); // Mencatat waktu selesai

                    double waktuTerlewati = difftime(waktuSelesai, waktuMulai); // Menghitung selisih waktu mulai dan waktu selesai

                    float hargaPerDetik = hargaPerJam / 3600.0; // Menghitung harga per detik
                    diskon = hitungDiskon((int)(waktuTerlewati / 3600)); // Menghitung diskon berdasarkan waktu rental
                    totalHarga = waktuTerlewati * hargaPerDetik; // Menghitung total harga

                    int jam = (int)(waktuTerlewati / 3600); // Menghitung jam
                    int menit = (int)((waktuTerlewati - (jam * 3600)) / 60); // Menghitung menit
                    int detik = (int)(waktuTerlewati - (jam * 3600) - (menit * 60)); // Menghitung detik

                    printf("\n----------------------------------------------\n");
                    printf("Rincian pembayaran\t\t:\n");
                    // Print informasi waktu rental
                    printf("Lama pemakaian\t\t\t: %d jam %d menit %d detik.\n", jam, menit, detik);
                    // Print informasi harga sebelum diskon/harga awal
                    printf("Total harga sebelum diskon\t: Rp%.2f\n", totalHarga);
                    // Print persentase diskon jika memenuhi syarat
                    printf("Persentase diskon\t\t: %.2f%%\n", diskon * 100);
                    // Print informasi potongan diskon jika memenuhi syarat
                    printf("Potongan diskon\t\t\t: Rp%.2f\n", totalHarga * diskon);
                    // Penghitungan harga akhir
                    float hargaSetelahDiskon = totalHarga - (totalHarga * diskon);  
                    // Print harga akhir yang harus dibayar       
                    printf("Harga yang harus dibayarkan\t: Rp%.2f\n", hargaSetelahDiskon); 
                    printf("----------------------------------------------\n\n");
                }
                else // Jika user memilih membatalkan sesi rental
                {
                    printf("Sesi rental dibatalkan.\n");
                    printf("----------------------------------------------\n");
                }
                break;

            case 2:
                // Pilihan 2: Bayar dulu baru merental
                printf("\n----------------------------------------------\n");
                printf("\nMasukkan jumlah uang yang dibayarkan: Rp. ");
                double jumlahUang;
                do
                {
                    jumlahUang = getJumlahUang(); // Mengambil input jumlah uang dari user
                } while (jumlahUang <= 0);

                float lamaPemakaian = jumlahUang / hargaPerJam; // Perhitungan lama pemakaian berdasarkan uang yang dibayarkan user
                diskon = hitungDiskon((int)lamaPemakaian); // Menghitung diskon berdasarkan lama pemakaian jika memenuhi syarat
                totalHarga = lamaPemakaian * hargaPerJam; // Menghitung total harga

                int jamRental = (int)lamaPemakaian; // Menghitung jam
                int menitRental = (int)((lamaPemakaian - jamRental) * 60); // Menghitung menit
                int detikRental = (int)((((lamaPemakaian - jamRental) * 60) - menitRental) * 60); // Menghitung detik

                printf("\n----------------------------------------------\n");
                printf("Rincian pembayaran\t\t:\n");
                // Print informasi waktu rental 
                printf("Lama pemakaian\t\t\t: %d jam %d menit %d detik.\n", jamRental, menitRental, detikRental);
                // Print informasi harga sebelum diskon/harga awal
                printf("Total harga sebelum diskon\t: Rp%.2f\n", totalHarga);
                // Print persentase diskon jika memenuhi syarat
                printf("Persentase diskon\t\t: %.2f%%\n", diskon * 100);
                // Print informasi potongan diskon jika memenuhi syarat
                printf("Potongan diskon\t\t\t: Rp%.2f\n", totalHarga * diskon);
                // Penghitungan harga akhir
                float hargaSetelahDiskon = totalHarga - (totalHarga * diskon); 
                // Print harga akhir yang harus dibayar        
                printf("Harga yang harus dibayarkan\t: Rp%.2f\n", hargaSetelahDiskon); 
                printf("----------------------------------------------\n\n");

                printf("Apakah anda ingin menghitung mundur sesi yang berlangsung? (y/n): "); // Prompt Konfirmasi y/n
                char pilihanMundur;
                do
                {
                    pilihanMundur = getKonfirmasi(); // Konfirmasi y/n
                } while (pilihanMundur != 'y' && pilihanMundur != 'n');

                if (pilihanMundur == 'y') // Jika user memilih menghitung mundur sesi rental
                {
                    printf("\nTekan 'Enter' untuk memulai sesi....");
                    printf("\n");
                    getchar(); // Menunggu user memulai sesi rental

                    time_t waktuMulai = time(NULL); // Mencatat waktu mulai/waktu saat ini
                    time_t waktuSelesai = waktuMulai + (jamRental * 3600) + (menitRental * 60) + detikRental; // Mencatat waktu selesai

                    while (time(NULL) <= waktuSelesai) // Print hitung mundur sesi rental
                    {
                        time_t sisaWaktu = waktuSelesai - time(NULL); // Menghitung sisa waktu
                        int jamSisa = sisaWaktu / 3600; // Konversi sisaWaktu(satuan detik) menjadi satuan jam
                        int menitSisa = (sisaWaktu % 3600) / 60; // Konversi sisaWaktu(satuan detik) menjadi satuan menit
                        int detikSisa = sisaWaktu % 60; // Konversi sisaWaktu(satuan detik) menjadi satuan detik

                        printf("Sisa waktu: %02d:%02d:%02d\r", jamSisa, menitSisa, detikSisa); // Print hitung mundur sesi rental dengan \r agar tidak mengulang baris setiap detiknya
                        fflush(stdout); // Membersihkan buffer
                    }

                    printf("\nWaktu rental telah berakhir.\n"); 
                }
                else
                {
                    printf("Hitung mundur sesi rental tidak dilakukan.\n");
                }
                printf("\n----------------------------------------------\n");
                break;

            case 3:
                printf("\n===============================================================================\n");
                printf("Program untuk menghitung harga sewa komputer di Byteburst yang dibuat \nuntuk memenuhi tugas kelompok mata kuliah Algoritma dan Pemrograman.\n");
                printf("\nProgram ini dibuat oleh kelompok 7 yang beranggota:\n");
                printf("1. ERWIN SAPUTRA YAPTO (2301970076)\n");
                printf("2. IFTIKHARUS RAUDANA MUNTAZAR (2702381622)\n");
                printf("3. IHSAN AMRI MUYASSAR (2702350592)\n");
                printf("4. WAHYU MENTARI MAYADITA (2702347723)\n");
                printf("===============================================================================\n");
                break;

            case 4:
                printf("----------------------------------------------\n");
                printf("  TERIMA KASIH TELAH MENGGUNAKAN PROGRAM INI\n");
                printf("----------------------------------------------\n");
                return 0;

            default:
                printf("----------------------------------------------\n");
                printf("      MENU TIDAK TERSEDIA PADA PROGRAM \n");
                printf("----------------------------------------------\n");
        }

        printf("\nTekan 'Enter' untuk melanjutkan...");
        while (getchar() != '\n');
    } while (pilihanMenu != 4);

    return 0;
}
