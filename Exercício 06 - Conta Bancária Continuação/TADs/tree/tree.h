#include "../account/account.h"
#include "../util/util.h"
#ifndef TREE_H
#define TREE_H

typedef struct tree_ TREE;

#define LEFT_SON 0
#define RIGHT_SON 1

TREE *createBinaryTree ();
void insertAccountInTree(TREE *tree, ACCOUNT *account);
void printTreeInOrder(TREE *tree);
void printTreeInPreOrder(TREE *tree);
void printTreeInPosOrder(TREE *tree);
ACCOUNT * findAccount(TREE * tree, char * cpf);
boolean removeAccount(TREE * tree, char * cpf);
void deleteTree(TREE * tree);

#endif