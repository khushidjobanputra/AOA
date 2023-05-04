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
    //worst case
    for(int i=n; i>=0; i--){
        a[i] = i;
    }

    //average case
    for(int i=0; i<n; i++){
        a[i] = rand();
    }
*/
    start = clock();

    for (i = 0; i <= n - 1; i++)
    {
        min = i;
        for (j = i + 1; j <= n - 1; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            temp = a[min];
            a[min] = a[i];
            a[i] = temp;
        }
    }
    printf("%d", i);
    end = clock();
    t = ((double)(end - start));
    printf("\n time taken : %f", t);
    return 0;
}
