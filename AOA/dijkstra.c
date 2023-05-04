#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#define INF INT_MAX;
#define V 100

int minDistance(int dist[], int visited[]){

    int min = INT_MAX;
    int index;
    for(int i=0; i<V; i++){
        if(visited[i]==0 && dist[i]<min){
            min = dist[i];
            index = i;
        }
    }

    return index;
}

void printSolution(int dist[]) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++){
        printf("%d \t %d\n", i, dist[i]);
    }
}

void dijkstra(int graph[V][V], int source, int n){

    int visited[V];
    int dist[V];

    for(int i=0; i<V; i++){
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[source] = 0;

    for(int i=0; i<(V-1); i++){
        int u = minDistance(dist, visited);

        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && visited[v] == 0 && dist[u]!=INT_MAX && dist[u]+graph[u][v]<dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }
    
    printSolution(dist);
}

int main(){

    int n, source;
    printf("Enter the number of vertices ");
    scanf("%d", &n);
    int graph[V][V];

    printf("Enter elements of graph: \n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d ", &graph[i][j]);
        }
        printf("\n");
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    dijkstra(graph, source, n);

    return 0;
}