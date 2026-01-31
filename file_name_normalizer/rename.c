#include <stdio.h>
#include <windows.h>
#include <string.h>

int main() {
    WIN32_FIND_DATA findFileData;

    HANDLE hFind = FindFirstFile(".\\*", &findFileData);

    if (hFind == INVALID_HANDLE_VALUE) {
        printf("Unable to open the folder.\n");
    }

    do {
        char *fileName = findFileData.cFileName;
        printf("%s\n", fileName);
    } while (FindNextFile(hFind, &findFileData));

    return 0;
}