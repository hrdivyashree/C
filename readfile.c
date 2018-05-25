#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int scores[60];
    FILE* fp = fopen("scores.txt", "r");

    if (NULL == fp) {
        perror("File not found!");
        exit(-1);
    }

    for (int i = 0; fscanf(fp, "%d%*c", &a[i]) > 0 && i < 60; i++) {
        printf("%d\n", scores[i]);
    }

    fclose(fp);
    return 0;
}
