#include "bintree.h"

struct node* left(struct node* root){
    Tree* buf;
    if(!root->lt){
        if(!root->rt){
            buf = root;
            buf->parent->lt = NULL;
        }
        else{
            buf = root;
            buf->parent->lt = root->rt;
            buf->rt->parent = root->parent;
        }
        return buf;
    }
    return left(root->lt);
}

struct node* delete_element(struct node* root, int element){
    if(!root) return NULL;
    Tree* buf;
    if(root->data == element){
        if(!root->rt){
            if(!root->lt){
                buf = NULL;
                free(root);
            }
            else{
                buf = root->lt;
                buf->parent = root->parent;
                free(root);
            }
        }
        else{
            if(!root->rt->lt){
                root->rt->lt = root->lt;
                if(root->parent){
                    if(root->parent->rt == root){
                        root->parent->rt = root->rt;
                    }
                    else{
                        root->parent->lt = root->lt;
                    }
                }
                root->rt->parent = root->parent;
                buf = root->rt;
                free(root);
            }
            else{
                Tree* most_left = left(root->rt);
                most_left->rt = root->rt;
                most_left->lt = root->lt;
                if(!most_left->rt){
                    most_left->rt->parent = most_left;
                }
                if(!most_left->lt){
                    most_left->lt->parent = most_left;
                }
                most_left->parent = root->parent;
                if(root->parent){
                    if(root->parent->lt == root){
                        root->parent->lt = most_left;
                    }
                    else{
                        root->parent->rt = most_left;
                    }
                }
                free(root);
                buf = most_left;
            }
        }
    }
    else if(root->data > element){
        buf = root;
        buf->lt = delete_element(root->lt, element);
    }
    else{
        buf = root;
        buf->rt = delete_element(root->rt, element);
    }
    return buf;
}

int main(){
    Tree* root = NULL;
    root = add(root, 5);
    root = add(root, 3);
    root = add(root, 10);
    root = add(root, 6);
    root = add(root, 8);
    root = add(root, 1);
    print_tree(root);
    printf("--------------\n");
    root = delete_element(root, 5);
    print_tree(root);
    printf("--------------\n");
    root = delete_element(root, 10);
    print_tree(root);
    printf("--------------\n");
}