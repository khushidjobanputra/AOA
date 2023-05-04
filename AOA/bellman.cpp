#include<iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter the number of vertices: ";
    cin>>n;

    int cost[n][n];
    cout<<"Enter the cost matrix: "<<endl;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>cost[i][j];
        }
    }
    int v;
    cout<<"Enter the source vertex: ";
    cin>>v;

    int dist[n];
    int path[n];

    for(int i=1; i<=n; i++){
        if(i==v){
            dist[i] = 0;
        }
        else{
            dist[i] = 100;
        }
        path[i] = 0;
    }

    for(int i=1; i<=n; i++){ // this for loop is for n iterations
        for(int u=1; u<=n; u++){
            for(int v=1; v<=n; v++){
                if(cost[u][v]!=100 && u!=v){
                    if(cost[u][v]+dist[u] < dist[v]){
                        dist[v] = cost[u][v] + dist[u];
                        path[v] = u;
                    }
                }
            }
        }
    }

    cout<<endl;
    cout<<"\tDistance\tPath"<<endl;

    for(int i=1; i<=n; i++){
        cout<<"dist["<<i<<"]="<<dist[i]<<"\t p["<<i<<"]="<<path[i]<<endl;
    }

    return 0;
}