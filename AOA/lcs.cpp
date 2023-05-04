#include<iostream>
using namespace std;

void print_LCS(char b[100][100], string x, int i, int j) {
    cout<<i<<" "<<j<<endl;
    if(i==0 || j==0) {
        return ;
    }
    if(b[i][j] == '@') {
        print_LCS(b,x,i-1,j-1);
    }
    else if(b[i][j] == '^') {
        print_LCS(b,x,i-1,j);
    }
    else {
        print_LCS(b,x,i,j-1);
        cout<<x[j]<<" ";
    }
}
void LCS_length(string x, string y) {
    int m = x.length();
    int n = y.length();
    int i,j;
    char b[100][100];
    int c[m+1][n+1];
    for(int i=1; i<=m; i++) {
        c[i][0] = 0;
    }
    for(int j=0; j<=n; j++) {
        c[0][j] = 0;
    }
    for(i=1; i<=m; i++) {
        for(j=1; j<=n; j++) {
            // cout<<x[i]<<" "<<y[j]<<endl;
            if(x[i] == y[j]) {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = '@';
            }
            else if(c[i-1][j] >= c[i][j-1]) {
                c[i][j] = c[i-1][j];
                b[i][j] = '^';
            }
            else {
                c[i][j] = c[i][j-1];
                b[i][j] = '<';
            }
        }
    }
    cout<<i<<" "<<j<<endl;
    cout<<b[10][10]<<endl;
    for(int i=0; i<=n; i++){
        cout<<y[i]<<"   ";
    }
    cout<<endl;
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            cout<<b[i][j]<<" "<<c[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<x[0]<<endl;
    print_LCS(b,x,i,j);
}
int main()
{
    string x = "properties";
    string y = "prosperity";
    // char y[] = {'p','r','o','s','p','e','r','i','t','y'};
    LCS_length(x,y);

    return 0;
}