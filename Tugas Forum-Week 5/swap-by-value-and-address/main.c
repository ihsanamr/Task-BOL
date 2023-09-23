#include <stdio.h>

// Fungsi untuk menukar nilai dengan pass-by-value
void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

// Fungsi untuk menukar nilai dengan pass-by-address
void swapByAddress(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int angkaPertama, angkaKedua;

    // Meminta pengguna memasukkan dua angka bulat
    printf("Masukkan angka pertama: ");
    scanf("%d", &angkaPertama);
    printf("Masukkan angka kedua: ");
    scanf("%d", &angkaKedua);

    // Menampilkan nilai awal
    printf("\nNilai awal: \nangkaPertama = %d, angkaKedua = %d\n\n", angkaPertama, angkaKedua);

    // Memanggil swapByValue
    swapByValue(angkaPertama, angkaKedua);

    // Menampilkan nilai setelah swapByValue
    printf("Setelah swapByValue: \nangkaPertama = %d, angkaKedua = %d\n\n", angkaPertama, angkaKedua);

    // Memanggil swapByAddress
    swapByAddress(&angkaPertama, &angkaKedua);

    // Menampilkan nilai setelah swapByAddress
    printf("Setelah swapByAddress: \nangkaPertama = %d, angkaKedua = %d\n\n", angkaPertama, angkaKedua);

    return 0;
}
