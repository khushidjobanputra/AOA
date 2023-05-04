#include <bits/stdc++.h> 
#include<unordered_map>
#include<list>
#include<bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    //create adjacency list
    unordered_map<int, list<pair<int,int>> > adj;

    for(int i=0; i<g.size(); i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    //intital marking
    vector<int> key(n+1);
    vector<int> mst(n+1);
    vector<int> parent(n+1);

    for(int i=0; i<=n; i++){
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }

    key[1] = 0;
    parent[1] = -1;

    for(int i=0; i<n; i++){
        //step1: find minimum in key array
        int mini = INT_MAX;
        int u;
        for(int v=1; v<=n; v++){
            if(mst[v]==false && key[v]<mini){
                mini = key[v];
                u = v;
            }
        }

        //step2: mark mst of u as false 
        //now u node is added in mst
        mst[u] = true;

        //step3: find adjacent of u and change its parent
        for(auto it: adj[u]){
            int v = it.first;
            int w = it.second;
            if(mst[v]==false && w<key[v]){
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;

    for(int i=2; i<=n; i++){
        result.push_back({{parent[i], i}, key[i]});
    }

    return result;
}

int main(){

    int n, m;
    cout<<"Enter no of nodes: ";
    cin>>n;
    cout<<"Enter no of edges: ";
    cin>>m;

    vector<pair<pair<int, int>, int>> graph;

    cout<<"Enter pair of edges and weight: "<<endl;
    for(int i=0; i<m; i++){
        int a, b, c;
        cout<<"Enter the values of pairs: ";
        cin>>a;
        cin>>b;
        cin>>c;
        graph.push_back({{a,b}, c});
    }

    vector<pair<pair<int, int>, int>> ans = calculatePrimsMST(n, m , graph);

    for(auto it: ans){
        cout<<it.first.first<<" ";
        cout<<it.first.second<<" ";
        cout<<it.second<<endl;
    }
}