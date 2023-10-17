#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    fp = fopen("databuku.txt", "r");

    char content[1000];

    if (fp == NULL) {
        printf("File tidak ditemukan");
    } else {
        fgets(content, 100, fp);
        printf("%s", content);
    }
    fclose(fp);
    return 0;
}