//CASE 1: filename.txt exists but it's empty

#include <stdio.h>

int main() {
    FILE* fp;
    fp = fopen("filename.txt", "a");
    if (fp == NULL) {
        printf("File cannot be opened...");
    }
    fclose(fp);
    return 0;
}