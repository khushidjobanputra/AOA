#include <stdio.h>
#include <string.h>
#define PRIME 101
int rabin_karp(char *text, char *pattern)
{
    int i, j, n, m, p = 0, t = 0, h = 1;
    n = strlen(text);
    m = strlen(pattern);
    // Calculate hash value of pattern and first substring of text
    for (i = 0; i < m - 1; i++)
        h = (h * 256) % PRIME;
    for (i = 0; i < m; i++){
        p = (256 * p + pattern[i]) % PRIME;
        t = (256 * t + text[i]) % PRIME;
    }
    // Compare pattern with each substring of text
    for (i = 0; i <= n - m; i++){
        if (p == t){
            for (j = 0; j < m; j++){
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == m)
                return i;
        }
        if (i < n - m){
            t = (256 * (t - text[i] * h) + text[i + m]) % PRIME;
            if (t < 0)
                t += PRIME;
        }
    }
    return -1;
}
int main()
{
    char text[100], pattern[100];
    printf("Enter the text: ");
    gets(text);
    printf("Enter the pattern: ");
    gets(pattern);
    int pos = rabin_karp(text, pattern);
    if (pos == -1)
        printf("Pattern not found\n");
    else
        printf("Pattern found at position %d\n", pos);
    return 0;
}