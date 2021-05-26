#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 1000

void swap(double* a, double* b){
    double c = *a;
    *a = *b;
    *b = c;
}

bool next_perm(int n, double* A){
    int i = n-1;
    for(; i > 0; i--){
        if(A[i-1] < A[i]) break;
        else if(i - 1 == 0) return false;
    }
    int m = i-1;
    for(int j = i; j < n; j++){
        if(A[j] > A[m]){
            m = j;
        }
    }
    swap(&A[i-1], &A[m]);
    for(int j = i; j < i + (n - i) / 2; j++){
        swap(&A[j], &A[n - j + i - 1]);
    }
    return true;
}

int main(){
    int n;
    scanf("%d", &n);
    double* arr = calloc(n, sizeof(double));
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("%d\n", next_perm(n, arr));
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
//1 2 5 6 4 3
//1 2 6 3 4 5