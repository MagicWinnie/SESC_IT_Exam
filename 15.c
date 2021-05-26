#include <stdio.h>
#include <stdlib.h>

#define N 1000

void swap(double* a, double* b){
    double c = *a;
    *a = *b;
    *b = c;
}

void rshift(int n, double* A, int k){
    for(int i = 0; i < k; i++){
        for(int j = i; j < n-1; j++){
            swap(&A[j], &A[j + 1]);
        }
        // for(int j = 0; j < n; j++){
        //     printf("%lf ", A[j]);
        // }
    }
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    double* arr = calloc(n, sizeof(double));
    for(int i = 0; i < n; i++){
        scanf("%lf", &arr[i]);
    }
    rshift(n, arr, k);

    for(int i = 0; i < 0; i++){
        printf("%lf ", arr[i]);
    }
    return 0;
}