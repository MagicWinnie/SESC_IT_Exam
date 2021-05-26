#include <stdio.h>
#include <stdlib.h>

#define N 1000
//Алгоритм реализован верно, однако, из-за особенностей динамического выделения памяти в функциях,
//элементы массива-результата могут забиваться мусором(на С++ проблем нет)
int count_inv(int n, int k, int* arr){
    int c = 0;
    for(int i = k + 1; i < n; i++){
        if(arr[k] <= arr[i]) c++;
    }
    return c;
}

int max(int n, int last, int* inv, int* arr){
    int imax = last, M = -1;
    for(int i = last + 1; i < n; i++){
        if(inv[i] > M && arr[i] >= arr[last]){
            imax = i;
            M = inv[i];
        }
    }
    return imax;
}

int* longest_subseq(int n, int* A){
    int* inv = calloc(n, sizeof(int));
    for(int i = 0; i < n; i++){
        inv[i] = count_inv(n, i, A);
    }
    int imax = 0;
    for(int i = 1; i < n; i++){
        if(inv[i] > inv[imax]) imax = i;
    }
    int k = 1;
    int* list = malloc(k * sizeof(int));
    list[0] = A[imax];
    int j = max(n, imax, inv, A);
    while(imax != j){
        imax = j;
        realloc(list, ++k * sizeof(int));
        list[k-1] = A[imax];
        j = max(n, imax, inv, A);
    }
    realloc(list, ++k * sizeof(int));
    list[k-1] = 0;
    return list;
}

int main(){
    int n;
    scanf("%d", &n);
    int* arr = calloc(n, sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int* list = longest_subseq(n, arr);
    for(int i = 0; list[i] != 0; i++){
        printf("%d ", list[i]);
    }
    return 0;
}
//1 4 8 2 3 6 3 9 2 4
//9 4 1 6 4 1 2 0 1 0