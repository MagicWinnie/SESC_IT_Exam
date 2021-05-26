#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool simple(int a)
{
    int k = 0;
    for (int i = 2; i <= a; i++)
        if (a % i == 0)
            k++;
    if (k == 1)
        return true;
    else
        return false;
}

int a[50];

bool isAllUnique(int count)
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (a[i] == a[j])
                return false;
        }
    }
    return true;
}

void R(int pos, long n, int n1)
{
    int i;
    for (i = n1; i <= (n - 1) / 2; i++)
        if (simple(i))
        {
            a[pos] = i;
            R(pos + 1, n - i, a[pos]);
        }
    if (simple(n))
    {
        if (isAllUnique(pos))
        {
            for (i = 0; i <= pos - 1; i++)
                printf("%d+", a[i]);
            printf("%d\n", n);
        }
    }
}

void simple_sum(int n)
{
    R(0, n, 1);
}

int main()
{
    int n;
    scanf("%d", &n);

    simple_sum(n);
}