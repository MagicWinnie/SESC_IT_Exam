#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *add(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void printInfix(struct node *root)
{
    if (root == NULL)
        return;

    printInfix(root->left);
    printf("%d ", root->data);
    printInfix(root->right);
}

int countNodes(struct node *root)
{
    if (root == NULL)
        return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
}

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void BinTreeToArr(struct node *node, int *inorder, int *index_ptr)
{
    if (node == NULL)
        return;
    //Run through the left subtree
    BinTreeToArr(node->left, inorder, index_ptr);
    //Get root data
    inorder[*index_ptr] = node->data;
    // increase index for next entry
    (*index_ptr)++;
    //Run through the right subtree
    BinTreeToArr(node->right, inorder, index_ptr);
}

struct node *ArrToBinTree(int *arr, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }

    //Make the middle element the root of the tree
    int mid = (start + end) / 2;
    struct node *temp = add(arr[mid]);

    //Make left subtree
    temp->left = ArrToBinTree(arr, start, mid - 1);

    //Make right subtree
    temp->right = ArrToBinTree(arr, mid + 1, end);

    return temp;
}

struct node *convert_to_binary_search_tree(struct node *root)
{
    if (root == NULL)
        return;

    int n = countNodes(root);

    // Store infix traversal of tree in arr
    int *arr = (int *)malloc(sizeof(int) * n);
    int i = 0;
    BinTreeToArr(root, arr, &i);

    qsort(arr, n, sizeof(int), compare);

    struct node *d = ArrToBinTree(arr, 0, n - 1);
    
    free(arr);
    
    return d;
}

void free_tree(struct node *leaf)
{
    if (leaf == NULL)
        return;
    struct node *lt = leaf->left, *rt = leaf->right;
    free(leaf);
    free_tree(lt);
    free_tree(rt);
}

int main()
{
    struct node *root = NULL;
    root = add(10);
    root->left = add(30);
    root->right = add(15);
    root->left->left = add(20);
    root->right->right = add(5);

    printInfix(root);
    printf("\n");

    struct node *root_search = convert_to_binary_search_tree(root);

    printInfix(root_search);
    printf("\n");

    free_tree(root);
    free_tree(root_search);
}