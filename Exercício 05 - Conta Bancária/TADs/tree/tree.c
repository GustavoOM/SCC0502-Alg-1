#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../account/account.h"
#include "../util/util.h"
#include "tree.h"

typedef struct node_ST NODE;

void printNodeInPreOrder(NODE *root);
void printNodeInPosOrder(NODE *root);
void printNodeInOrder(NODE *root);
NODE * insertNodeInTree(NODE *root, ACCOUNT *account);

struct node_ST{
    ACCOUNT *account;
    NODE *left;
    NODE *right;
};

struct tree_{
    NODE* root;
    int depth;
};

TREE *createBinaryTree (){
    TREE *binaryTree;
    binaryTree = (TREE *) malloc(sizeof(TREE));

    if (binaryTree != NULL){
        binaryTree->root = NULL;
        binaryTree->depth = -1;
        return binaryTree;
    }
    return NULL;
}

void printTreeInOrder(TREE *tree){
    printf("Inorder\n");
    printNodeInOrder(tree->root);
    printf("\n");

}

void printNodeInOrder(NODE *root){
    if(root != NULL){
        printNodeInOrder(root->left);
        printCpfFromAccount(root->account);
        printf("\n");
        printNodeInOrder(root->right);
    }
}

void printTreeInPreOrder(TREE *tree){
    printf("Preorder\n");
    printNodeInPreOrder(tree->root);
    printf("\n");

}

void printNodeInPreOrder(NODE *root){
    if(root != NULL){
        printCpfFromAccount(root->account);
        printf("\n");
        printNodeInPreOrder(root->left);
        printNodeInPreOrder(root->right);
    }
}

void printTreeInPosOrder(TREE *tree){
    printf("Postorder\n");
    printNodeInPosOrder(tree->root);
    printf("\n");

}

void printNodeInPosOrder(NODE *root){
    if(root != NULL){
        printNodeInPosOrder(root->left);
        printNodeInPosOrder(root->right);
        printCpfFromAccount(root->account);
        printf("\n");
    }
}

void insertAccountInTree(TREE *tree, ACCOUNT *account){
    tree->root = insertNodeInTree(tree->root,account);
}

NODE * insertNodeInTree(NODE *root, ACCOUNT *account){
    if(root == NULL){
        NODE *auxNode = (NODE*)malloc(sizeof(NODE));
        auxNode->account = account;
        auxNode->left = NULL;
        auxNode->right = NULL;
        return auxNode;
    }
    else{
        if(cpfComparator(getCpfFromAccount(root->account),getCpfFromAccount(account)) == LESSER){
            root->right = insertNodeInTree(root->right, account);
        } 
        if(cpfComparator(getCpfFromAccount(root->account),getCpfFromAccount(account)) == GREATER){
            root->left = insertNodeInTree(root->left, account);
        }
        return root;
    }
}