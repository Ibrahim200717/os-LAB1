#include <stdio.h>
#include <dirent.h>

int main() {
    char path[100];
    printf("Enter directory path: ");
    scanf("%s", path);

    DIR *dir = opendir(path);
    if (dir == NULL) {
        printf("Cannot open directory.\n");
        return 1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL)
        printf("%s\n", entry->d_name);

    closedir(dir);
    return 0;
}
