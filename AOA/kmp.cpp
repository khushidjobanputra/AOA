#include<iostream>
using namespace std;

int main(){

    int n,m;
    cout<<"Enter length of T ";
    cin>>n;
    cout<<"Enter length of P ";
    cin>>m;

    char T[n];
    char P[m];
    int S[m];

    cout<<"Enter string P "<<endl;

    for(int i=0; i<m; i++){
        cin>>P[i];
    }
    cout<<endl;

    cout<<"Enter string T "<<endl;

    for(int i=0; i<n; i++){
        cin>>T[i];
    }
    cout<<endl;

    S[0] = 0;
    int k = 0;

    for(int q = 1; q<(m); q++){
        while(k>0 && P[k]!=P[q]){
            k = S[k-1];
        }
        if(P[k]==P[q]){
            k++;
        }
        S[q] = k;
    }

    int q = 0;

    for(int i=1; i<n; i++){
        while(q>0 && P[q]!=T[i]){
            q = S[q-1];
        }
        if(P[q]==T[i]){
            q++;
        }
        if(q==m){
            cout<<"pattern occur at shift of ";
            cout<<(i-m+1)<<endl;
            q = S[q-1];
        }
    }

    cout<<endl;

    return 0;
}