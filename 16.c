#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int val;
    struct Node *next;
};

void print_list(struct Node *first)
{
    while (first != NULL)
    {
        printf("%d ", first->val);
        first = first->next;
    }
    printf("\n");
}

void deleteAll(struct Node *first)
{
    struct Node *curr = first;
    while (first != NULL)
    {
        first = first->next;
        free(curr);
        curr = first;
    }
}

struct Node *add2front(struct Node *first, int val)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->val = val;

    struct Node *temp = first;
    new->next = temp;

    return new;
}

struct Node *reverse(struct Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    struct Node *list_to_do = head->next;

    struct Node *reversed_list = head;
    reversed_list->next = NULL;
    while (list_to_do != NULL)
    {
        struct Node *temp = list_to_do;
        list_to_do = list_to_do->next;

        temp->next = reversed_list;
        reversed_list = temp;
    }
    return reversed_list;
}

int main()
{
    struct Node *first = NULL;
    first = add2front(first, -1);
    first = add2front(first, 10);
    first = add2front(first, 2);
    first = add2front(first, 4);
    first = add2front(first, 3);

    print_list(first);
    first = reverse(first);
    print_list(first);

    deleteAll(first);
    return 0;
}