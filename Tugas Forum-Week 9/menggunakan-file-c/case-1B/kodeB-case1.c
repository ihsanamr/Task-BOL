 // CASE 3: Filename.txt exists but it's empty.

#include <stdio.h>

int main() {
    FILE* fp = fopen("filename.txt", "r");
    int ch = fgetc(fp);

    while (ch != EOF) {
        putchar(ch);
        ch = fgetc(fp);
    }

    if (feof(fp))
        printf("\nReached the end of file.\n");
    else
        printf("\nSomething went wrong.\n");

    fclose(fp);
    getchar();
    
    fclose(fp);
    return 0;
}
