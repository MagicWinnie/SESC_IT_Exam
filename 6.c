#include <stdio.h>

#define N 30

int sum_squared_digits(char *input)
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        if (input[i] >= 48 && input[i] <= 57)
            sum += (input[i] - '0') * (input[i] - '0');
    }
    return sum;
}

int main()
{
    char s[N];
    scanf("%s", s);
    printf("%d\n", sum_squared_digits(s));
    return 0;
}