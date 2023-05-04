#include <stdio.h>
#include <time.h>
int main()
{
    int n = 15000, i, j, temp, min;
    int a[n];

    clock_t start, end;
    double t;
    //best case
    for (i = 0; i < n; i++){
        a[i] = i;
    }
/*
    //average case
    for(int i=0; i<n; i++){
        a[i] = rand();
    }
    //worst case
    for(int i=n; i>0; i--){
        a[i] = i;
    }
*/
    start = clock();
    for (i = 0; i <= n - 1; i++){
        j = i - 1;
        temp = a[i];
        while ((a[j] > temp) && (j >= 0)){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
    printf("%d", i);
    end = clock();
    t = ((double)(end - start));
    printf("\n time taken : %f", t);
    return 0;
}
