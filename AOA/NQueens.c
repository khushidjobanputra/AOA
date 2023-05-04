#include<stdio.h>
#include<stdbool.h>

int x[10];

int Abs(int x) {
    if(x<0) {
        return -x;
    }
    else {
        return x;
    }
}

bool Place(int k, int i) {
    for(int j=0; j<k; j++) {
        if(x[j] == i || Abs(x[j]-i) == Abs(j-k)) {
            return false;
        }
    }
    return true;
}

void NQueens(int k, int n) {
    for(int i=0; i<n; i++) {
        if(Place(k,i)) {
            x[k] = i;
            if(k == n-1) {
                for(int j=0; j<n; j++) {
                    printf("%d\t", x[j]+1);
                }
                printf("\n");
            }
            else {
                NQueens(k+1, n);
            }
        }
    }
}
void main() {
    NQueens(0, 4);
}