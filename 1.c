#include "bintree.h"

Tree* delete_min(Tree* root){
    if(!root) return NULL;
    Tree* buf;
    if(root->lt == NULL){
        buf = root->rt;
        free(root);
    }
    else{
        buf = root;
        buf->lt = delete_min(root->lt);
    }
    return buf;
}

int main(){
    Tree *root = NULL;
    root = add(root, 5);
    root = add(root, 3);
    root = add(root, 10);
    print_tree(root);
    printf("\n");
    root = delete_min(root);
    print_tree(root);
    printf("\n");
    root = delete_min(root);
    print_tree(root);
    return 0;
}