#include <stdio.h>
#include <string.h>

int max(int a, int b){
    return (a > b) ? a : b;
}

void lcs(char *X, char *Y, int m, int n){

    int L[m + 1][n + 1];
    int i, j;
    // Build L[m+1][n+1] in bottom up fashion
    for (i = 0; i <= m; i++){
        for (j = 0; j <= n; j++){
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            printf("%d ", L[i][j]);
        }
        printf("\n");
    }
    // Find the longest common subsequence
    int index = L[m][n];
    char lcs[index + 1];
    lcs[index] = '\0';
    i = m;
    j = n;

    while (i > 0 && j > 0){
        printf("%d %d\n", i, j);
        printf("%c %c\n", X[i-1], Y[j-1]);
        if (X[i - 1] == Y[j - 1]){
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        }
        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }
    printf("Length of LCS: %d\n", strlen(lcs));
    // Print the longest common subsequence
    printf("Longest common subsequence: %s\n", lcs);
}

int main(){

    char X[100], Y[100];
    printf("Enter the first string: ");
    scanf("%s", X);

    printf("Enter the second string: ");
    scanf("%s", Y);

    int m = strlen(X);
    int n = strlen(Y);

    lcs(X, Y, m, n);
    return 0;
}