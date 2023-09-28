#include <stdio.h>

// Fungsi iteratif untuk menghitung dan mencetak deret bilangan Fibonacci dari 0 hingga n
int fibonacciIteratif(int n) {
    if (n <= 1) {
        return n;
    }
    int angkaSebelumnya = 0;
    int angkaSekarang = 1;

    for (int i = 2; i < n; i++) {
        int angkaSelanjutnya = angkaSebelumnya + angkaSekarang;
        angkaSebelumnya = angkaSekarang;
        angkaSekarang = angkaSelanjutnya;   
    }
    return angkaSekarang;
}

int main() {
    int n = 4;
    printf("Iteratif: %d", fibonacciIteratif(n));
    return 0;
}
