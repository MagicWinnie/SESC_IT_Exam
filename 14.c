#include <stdio.h>
#include "stack.h"

long Ack(long n, long m)
{
    if (n == 0)
        return m + 1;
    else if (m == 0)
        return Ack(n - 1, 1);
    else
        return Ack(n - 1, Ack(n, m - 1));
}

// Функция очень быстро растет
// Замените int на long
// В реализации стэка от Макса захардкоден int
int AckNonRecursive(int n, int m)
{
    Stack* s = create();
    push(s, n);
    while (!empty(s))
    {
        n = pop(s);
        if (n == 0)
            m += n + 1;   
        else if (m == 0)
        {
            push(s, --n);
            m++;
        }
        else
        {
            push(s, --n);
            push(s, ++n);
            m--;
        }
    }
    return m;
}

int main()
{
    printf("%d\n", Ack(1, 2));
    printf("%d\n", AckNonRecursive(1, 2));
}