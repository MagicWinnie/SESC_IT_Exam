#include <stdio.h>
#include <stdlib.h>

#define N 1000

int dfs(int n, int** adj, int* seen, int v, int f){
    if(adj[v][f]) return 1;
    for(int i = 0; i < n; i++){
        if(adj[v][i] && !seen[i]){
            seen[i] = 1;
            if(dfs(n, adj, seen, i, f)) return 1;
        }
    }
    return 0;
}

int* reachable(int n, int** M, int A){
    A--;
    int* list = calloc(n, sizeof(int));
    for(int i = 0; i < n; i++){
        int* seen = calloc(n, sizeof(int));
        if(i != A && dfs(n, M, seen, i, A)){
            list[i] = 1;
        }
    }
    return list;
}

int main(){
    FILE* fin = fopen("5.txt", "r");
    int n, A;
    int** M = calloc(n, sizeof(int*));
    fscanf(fin, "%d %d", &n, &A);
    for(int i = 0; i < n; i++){
        M[i] = calloc(n, sizeof(int));
        for(int j = 0; j < n; j++){
            fscanf(fin, "%d", &M[i][j]);
        }
    }
    fclose(fin);
    int* list = reachable(n, M, A);
    for(int i = 0; i < n; i++){
        if(list[i]) printf("%d ", i + 1);
    }
    return 0;
}