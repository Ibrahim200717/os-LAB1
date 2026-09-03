#include <stdio.h>
#include <string.h>

int main() {
    char filename[50], word[50], line[200];

    printf("Enter file name: ");
    scanf("%s", filename);
    printf("Enter word to search: ");
    scanf("%s", word);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Cannot open file.\n");
        return 1;
    }

    int line_no = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        line_no++;
        if (strstr(line, word) != NULL)
            printf("%d: %s", line_no, line);
    }

    fclose(fp);
    return 0;
}
