//CASE 2: filename.txt doesn't exist

#include <stdio.h>

int main() {
    FILE* fp;
    fp = fopen("filename.txt", "w");
    if (fp == NULL) {
        printf("File cannot be opened...");
    }
    fclose(fp);
    return 0;
}