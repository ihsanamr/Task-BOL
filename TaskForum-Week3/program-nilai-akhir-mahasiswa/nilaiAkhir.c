/*
Nama: Ihsan Amri Muyassar
NIM: 2702350592
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // Untuk fungsi atol (konversi string menjadi tipe data long)
#include <string.h>

/* Fungsi pengecekan apakah nilai yang dimasukkan user sudah sesuai */
int valid_desimal(char *nilai) {
  int panjang = strlen(nilai);
  for (int i = 0; i < panjang - 1; i++) {
    if (!isdigit(nilai[i]) && nilai[i] != '.') {
      return 0; 
    }
  }
  return 1;
}

/* Fungsi pengecekan apakah nama yang dimasukkan user sudah sesuai */
int valid_nama(char *nama) {
  int panjang = strlen(nama);
  for (int i = 0; i < panjang; i++) {
    if (!isalpha(nama[i]) && nama[i] != ' ' && nama[i] != '-') {
      return 0;
    }
  }
  return 1;
}

int main() {
  // Deklarasi variabel
  long nim;
  float nilai_tugas, nilai_uts, nilai_uas, nilai_akhir;
  float bobot_nilai_tugas = 0.4, bobot_nilai_uts = 0.3, bobot_nilai_uas = 0.3;
  char namaMahasiswa[50], grade[5];

  /* ------------SECTION 1: INPUT USER----------------- */

  printf("=================================================\n");
  printf("   PROGRAM PERHITUNGAN NILAI AKHIR DAN GRADE\n");
  printf("=================================================\n\n");

  printf("Tekan enter untuk memulai program....");
  getchar();
  printf("\n");
  // Input nama mahasiswa
  while (1) {
    printf("Masukkan nama lengkap: ");
    fgets(namaMahasiswa, sizeof(namaMahasiswa), stdin);
    int panjang = strlen(namaMahasiswa);

    // Mengganti newline dari fgets dengan null terminator
    if (namaMahasiswa[panjang - 1] == '\n') {
    namaMahasiswa[panjang - 1] = '\0';
    }
    
    if (!valid_nama(namaMahasiswa)) {
      printf("--------------------------------------------------------\n");
      printf("Input tidak valid. Harap isi nama dengan huruf saja.\n");
      printf("--------------------------------------------------------\n");
    } else {
      break;
    }
  }
  
  // Input nim mahasiswa
  char input_nim_sementara[100];
  while (1) {
    printf("Masukkan NIM: ");
    scanf("%s", input_nim_sementara);
    int valid = 1;
    for (int i = 0; input_nim_sementara[i] != '\0'; i++) {
      if (!isdigit(input_nim_sementara[i])) {
        valid = 0;
        break;
      }
    }
    
    if (valid) {
      nim = atol(input_nim_sementara);
      if (nim < 0) {
        printf("-----------------------------------------------------------");
        printf("\nInput tidak valid. Harap isi NIM dengan format yang benar.\n");
        printf("-----------------------------------------------------------\n");
      } else {
        break;
      }
    } else {
      printf("-----------------------------------------------------------");
      printf("\nInput tidak valid. Harap isi NIM dengan format yang benar.\n");
      printf("-----------------------------------------------------------\n");
    }
  }

  while (getchar() != '\n');
  
  // Input nilai tugas
  char input_nilai_tugas_sementara[100];
  while (1) {
    printf("Masukkan nilai tugas: ");
    if (fgets(input_nilai_tugas_sementara, sizeof(input_nilai_tugas_sementara), stdin) != NULL) {
      if (valid_desimal(input_nilai_tugas_sementara)) {
        if (sscanf(input_nilai_tugas_sementara, "%f", &nilai_tugas) == 1) {
          if (nilai_tugas < 0 || nilai_tugas > 100) {
            printf("--------------------------------------------------------");
            printf("\nInput tidak valid. Harap isi nilai tugas dengan benar.\n");
            printf("--------------------------------------------------------\n");
          } else {
            break;
          }
        } else {
          printf("--------------------------------------------------------");
          printf("\nInput tidak valid. Harap isi nilai tugas dengan benar.\n");
          printf("--------------------------------------------------------\n");
        }
      } else {
        printf("--------------------------------------------------------");
        printf("\nInput tidak valid. Harap isi nilai tugas dengan benar.\n");
        printf("--------------------------------------------------------\n");
      }
    }
  }

  // Input nilai UTS
  char input_nilai_uts_sementara[100];
  while (1) {
    printf("Masukkan nilai UTS: ");
    if (fgets(input_nilai_uts_sementara, sizeof(input_nilai_uts_sementara), stdin) != NULL) {
      if (valid_desimal(input_nilai_uts_sementara)) {
        if (sscanf(input_nilai_uts_sementara, "%f", &nilai_uts) == 1) {
          if (nilai_uts < 0 || nilai_uts > 100) {
            printf("--------------------------------------------------------");
            printf("\nInput tidak valid. Harap isi nilai UTS dengan benar.\n");
            printf("--------------------------------------------------------\n");
          } else {
            break;
          }
        } else {
          printf("--------------------------------------------------------");
          printf("\nInput tidak valid. Harap isi nilai UTS dengan benar.\n");
          printf("--------------------------------------------------------\n");
        }
      } else {
        printf("--------------------------------------------------------");
        printf("\nInput tidak valid. Harap isi nilai UTS dengan benar.\n");
        printf("--------------------------------------------------------\n");
      }
    }
  }

  // Input nilai UAS
  char input_nilai_uas_sementara[100];
  while (1) {
    printf("Masukkan nilai UAS: ");
    if (fgets(input_nilai_uas_sementara, sizeof(input_nilai_uas_sementara), stdin) != NULL){
      if (valid_desimal(input_nilai_uas_sementara)) {
        if (sscanf(input_nilai_uas_sementara, "%f", &nilai_uas) == 1) {
          if (nilai_uas < 0 || nilai_uas > 100) {
            printf("--------------------------------------------------------");
            printf("\nInput tidak valid. Harap isi nilai UAS dengan benar.\n");
            printf("--------------------------------------------------------\n");
          } else {
            break;
          }
        } else {
          printf("--------------------------------------------------------");
          printf("\nInput tidak valid. Harap isi nilai UAS dengan benar.\n");
          printf("--------------------------------------------------------\n");
        }
      } else {
        printf("--------------------------------------------------------");
        printf("\nInput tidak valid. Harap isi nilai UAS dengan benar.\n");
        printf("--------------------------------------------------------\n");
      }
    } 
  }

  /* ------------SECTION 2: PERHITUNGAN NILAI & GRADE----------------- */
  
  // Perhitungan nilai akhir
  nilai_akhir = (nilai_tugas * bobot_nilai_tugas) + (nilai_uts * bobot_nilai_uts) + (nilai_uas * bobot_nilai_uas);
  
  // Penentuan Grade
  if (nilai_akhir >= 90) {
      strcpy(grade, "A");
  } else if (nilai_akhir >= 85) {
      strcpy(grade, "A-");
  } else if (nilai_akhir >= 80) {
      strcpy(grade, "B+");
  } else if (nilai_akhir >= 75) {
      strcpy(grade, "B");
  } else if (nilai_akhir >= 70) {
      strcpy(grade, "B-");
  } else if (nilai_akhir >= 65) {
      strcpy(grade, "C");
  } else if (nilai_akhir >= 50) {
      strcpy(grade, "D");
  } else {
      strcpy(grade, "E");
  }

  /* ------------SECTION 3: OUTPUT HASIL----------------- */

  printf("\n==========================================\n");
  printf("           HASIL PERHITUNGAN\n");
  printf("==========================================\n");

  // Menampilkan data dalam tabel
  printf("%-12s | %s\n", "Nama", namaMahasiswa);
  printf("%-12s | %ld\n", "NIM", nim);
  printf("%-12s | %.2f\n", "Nilai Akhir", nilai_akhir);
  printf("%-12s | %s\n", "Grade", grade);
  
  return 0;
}
