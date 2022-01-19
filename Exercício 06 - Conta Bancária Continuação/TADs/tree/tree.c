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
NODE * insertNodeInTree(NODE *root, ACCOUNT *account, int * flag);
boolean removeAccountAux(NODE ** root, char * cpf);
void switchMaxLeft(NODE * switchNode, NODE * root, NODE * previous);
void switchMaxRight(NODE * switchNode, NODE * root, NODE * previous);
void deleteNode(NODE *root);

struct node_ST{
    ACCOUNT *account;
    NODE *left;
    NODE *right;
};

struct tree_{
    NODE* root;
    int depth;
    int quantity;
};

TREE *createBinaryTree (){
    TREE *binaryTree;
    binaryTree = (TREE *) malloc(sizeof(TREE));

    if (binaryTree != NULL){
        binaryTree->root = NULL;
        binaryTree->depth = -1;
        binaryTree->quantity = 0;
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
    int flag = 0;
    tree->root = insertNodeInTree(tree->root,account,&flag);
    if(flag){
        tree->quantity++;
    }
}

NODE * insertNodeInTree(NODE *root, ACCOUNT *account, int * flag){
    if(root == NULL){
        NODE *auxNode = (NODE*)malloc(sizeof(NODE));
        auxNode->account = account;
        auxNode->left = NULL;
        auxNode->right = NULL;
        *flag += 1;
        return auxNode;
    }
    else{
        if(cpfComparator(getCpfFromAccount(root->account),getCpfFromAccount(account)) == LESSER){
            root->right = insertNodeInTree(root->right, account,flag);
        } 
        if(cpfComparator(getCpfFromAccount(root->account),getCpfFromAccount(account)) == GREATER){
            root->left = insertNodeInTree(root->left, account,flag);
        }
        return root;
    }
}

ACCOUNT * findAccount(TREE * tree, char * cpf){
    removeDotsAndDashesFromCpf(cpf);
    int comparator;
    NODE * auxNode = tree->root;

    for(int i = 0; i < tree->quantity; i++){
        if(auxNode == NULL){
            return NULL;
        }

        comparator = cpfComparator(getCpfFromAccount(auxNode->account),cpf);

        if(comparator == EQUAL){
            return auxNode->account;
        }
        else if(comparator == LESSER){
            auxNode = auxNode->right;
        }
        else{
            auxNode = auxNode->left;
        }
    }
    free(auxNode);
    auxNode = NULL;
    return NULL;
}

boolean removeAccount(TREE * tree, char * cpf){
    if(tree != NULL)
        return (removeAccountAux(&tree->root,cpf));
    return FALSE;
}

boolean removeAccountAux(NODE ** root, char * cpf){
    if(*root == NULL){
        return FALSE;
    }
    NODE *nodeAux;
    if(cpfComparator(getCpfFromAccount((*root)->account),cpf) == EQUAL){
        if((*root)->left == NULL || (*root)->right == NULL){
            nodeAux = *root;
            if((*root)->left == NULL){
                *root = (*root)->right;
            }
            else{
                *root = (*root)->left;
            }
            free(nodeAux);
            nodeAux = NULL;
        }
        else{
            //switchMaxLeft((*root)->left,(*root),(*root));
            switchMaxRight((*root)->right,(*root),(*root));
        }
        return TRUE;
    }
    else{
        if(cpfComparator(getCpfFromAccount((*root)->account),cpf) == LESSER){
            return removeAccountAux(&(*root)->right,cpf);
        }
        else{
            return removeAccountAux(&(*root)->left,cpf);
        }
    }
    free(nodeAux);
    nodeAux=NULL;

}

void switchMaxLeft(NODE * switchNode, NODE * root, NODE * previous){
    if(switchNode->right != NULL){
        switchMaxLeft(switchNode->right,root,switchNode);
        return;
    }
    if(root == previous){
        previous->left = switchNode->left;
    }
    else{
        previous->right = switchNode->left;
    }
    root->account = switchNode->account;
    free(switchNode);
    switchNode = NULL;
}

void switchMaxRight(NODE * switchNode, NODE * root, NODE * previous){
    if(switchNode->left != NULL){
        switchMaxRight(switchNode->left,root,switchNode);
        return;
    }
    if(root == previous){
        previous->right = switchNode->right;
    }
    else{
        previous->left = switchNode->right;
    }
    root->account = switchNode->account;
    free(switchNode);
    switchNode = NULL;
}

void deleteTree(TREE * tree){
    deleteNode(tree->root);
}

void deleteNode(NODE *root){
    if(root != NULL){
        deleteNode(root->left);
        deleteNode(root->right);
        deleteAccount(root->account);
        root = NULL;
        free(root);
    }
}