#include <stdio.h>
#include <string.h>

int main() {
    int m, n;
    printf("Enter number of rows: ");
    scanf("%d", &m);
    printf("Enter number of columns: ");
    scanf("%d", &n);

    char grid[m][n + 1];  
    printf("Enter the grid elements (each row of uppercase letters):\n");
    for (int i = 0; i < m; i++) {
        scanf("%s", grid[i]);
    }

    char word[50];
    printf("Enter the target word: ");
    scanf("%s", word);
    int len = strlen(word);

    int found = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j <= n - len; j++) {
            int k;
            for (k = 0; k < len; k++) {
                if (grid[i][j + k] != word[k])
                    break;
            }
            if (k == len) {
                printf("Start (%d,%d) End (%d,%d)\n", i, j, i, j + len - 1);
                found = 1;
            }
        }
    }

    for (int i = 0; i <= m - len; i++) {
        for (int j = 0; j < n; j++) {
            int k;
            for (k = 0; k < len; k++) {
                if (grid[i + k][j] != word[k])
                    break;
            }
            if (k == len) {
                printf("Start (%d,%d) End (%d,%d)\n", i, j, i + len - 1, j);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("Word not found\n");
    }

    return 0;
}
