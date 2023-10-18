#include <stdio.h>

int main() {
    FILE* fptr;
    char id[100];
    char nama[100];
    char saldo[100];

    fptr = fopen("datasaldo.txt", "r"); //Membuka file "datasaldo.txt" dalam mode "read" atau "baca"

    if (fptr == NULL) {
        printf("File tidak dapat ditemukan");
    } else {
        printf("==============================================================\n");
        printf("%-12s| %-25s| %-20s\n", "ID", "Nama", "Saldo");
        printf("==============================================================\n");
        while (fscanf(fptr, "%s %99[^0-9] %s", id, nama, saldo) != EOF) {
            printf("%-12s| %-25s| %-20s\n", id, nama, saldo);
        }
        printf("==============================================================\n");
    }

    fclose(fptr); // Menutup file setelah selesai membaca
    return 0;
}

/*Catatan pengingat:
%99[^0-9] berarti akan membaca karakter dari string maksimum 99 karakter 
dan akan berhenti membaca jika menemukan karakter digit (0-9)
*/