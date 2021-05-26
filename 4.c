#include <stdio.h>
#include <stdlib.h>
#define N 5

void traverse(double A[N][N], double B[N][N])
{
    int i = 0, j, k = 0, p = 0;
    int a = 0, b = 0;
    while (i < N * N)
    {
        k++;

        for (j = k - 1; j < N - k + 1; j++)
        {
            B[a][b] = A[k - 1][j];
            b++;
            if (b >= N)
            {
                b = 0;
                a++;
            }
            p++;
            i++;
        } /*По верхней строке*/

        for (j = k; j < N - k + 1; j++)
        {
            B[a][b] = A[j][N - k];
            b++;
            if (b >= N)
            {
                b = 0;
                a++;
            }
            p++;
            i++;
        } /*По правому столбцу*/

        for (j = N - k - 1; j >= k - 1; j--)
        {
            B[a][b] = A[N - k][j];
            b++;
            if (b >= N)
            {
                b = 0;
                a++;
            }
            p++;
            i++;
        } /*По нижней строке*/
        
        for (j = N - k - 1; j >= k; j--)
        {
            B[a][b] = A[j][k - 1];
            b++;
            if (b >= N)
            {
                b = 0;
                a++;
            }
            p++;
            i++;
        } /*По левому столбцу*/
    }
}

int main()
{
    double A[N][N] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
        }, B[N][N];

    traverse(A, B);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%lf ", B[i][j]);
        }
        printf("\n");
    }
    return 0;
}