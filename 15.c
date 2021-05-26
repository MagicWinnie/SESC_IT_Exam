#include <stdio.h>
#include <stdlib.h>

#define N 1000

void swap(double* a, double* b){
    double c = *a;
    *a = *b;
    *b = c;
}

void rshift(int n, double* A, int k){
    for(int i = 0; i < k % n; i++){
        for(int j = n-1; j > 0; j--){
            swap(&A[j], &A[j - 1]);
        }
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

    for(int i = 0; i < n; i++){
        printf("%lf ", arr[i]);
    }
    return 0;
}//1 3 5 7 9 2 4 6 8 10