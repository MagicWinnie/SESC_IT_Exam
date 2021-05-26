#ifndef BINTREE_H
#define BINTREE_H

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* rt;
    struct node* lt;
};

struct node* add(struct node* root, int a){
    struct node* buf;
    if(root == NULL){
        buf = malloc(sizeof(struct node));
        buf->data = a;
        buf->lt = NULL;
        buf->rt = NULL;
    }
    else if(root->data > a){
        if(root->lt == NULL){
            buf = root;
            buf->lt = malloc(sizeof(struct node));
            buf->lt->data = a;
            buf->lt->lt = NULL;
            buf->lt->rt = NULL;
        }
        else{
            buf = add(root->lt, a);
        }
    }
    else{
        if(root->rt == NULL){
            buf = root;
            buf->rt = malloc(sizeof(struct node));
            buf->rt->data = a;
            buf->rt->lt = NULL;
            buf->rt->rt = NULL;
        }
        else{
            buf = add(root->rt, a);
        }
    }
    return buf;
}

void free_tree(struct node* leaf){
    if(leaf == NULL) return;
    struct node* lt = leaf->lt, *rt = leaf->rt;
    free(leaf);
    free_tree(lt);
    free_tree(rt);
}

void print_tree(struct node* leaf){
    if (leaf == NULL) return;
	print_tree(leaf->lt);
	printf("%d\n", leaf->data);
	print_tree(leaf->rt);
}

#endif