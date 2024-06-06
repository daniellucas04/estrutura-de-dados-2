// Contém implementação de uma árvore binária de busca AVL
#include<stdio.h>
#include<stdlib.h>

/**
 * AVLNode: Estrutura de nó da árvore AVL
 * @param int value = Valor do nó
 * @param AVLNode* left = Endereço do filho à esquerda
 * @param AVLNode* right = Endereço do filho à direita
*/
typedef struct AVLNode {
    int value;
    struct AVLNode *left, *right;
    int leftHeight;
    int rightHeight;
} AVLNode;

/**
 * AVLTree: Árvore Binária de Busca AVL
 * @param AVLNode* root = Endereço da raiz
 * @param int quantity = Quantidade de elementos da árvore
*/
typedef struct AVLTree {
    AVLNode *root;
    int quantity;
} AVLTree;

/**
 * newTree: Cria uma nova árvore binária de busca AVL
 * @return AVLTree* address
*/
AVLTree* newAVL() {
    AVLTree *tree = (AVLTree*) malloc(sizeof(AVLTree));
    if(tree != NULL) {
        tree->root = NULL;
        tree->quantity = 0;
    }
    return tree;
}

int bigger(int a, int b) {
    if (a > b)
        return a;
    else 
        return b;
}

/**
 * insertAVLNode: Insere um nó na árvore AVL
 * @param AVLNode *node = Nó
 * @param int value = Valor que será inserido
 * @param AVLNode *parent = Pai do nó
 * @param AVLTree *tree = Árvore AVL que terá o nó inserido
 */
int insertAVLNode(AVLNode *node, int value, AVLNode *parent, AVLTree *tree) {
    if(node == NULL) {
        // inserção
        AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
        if(newNode == NULL)
            return 0;

        newNode->value = value;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->leftHeight = 0;
        newNode->rightHeight = 0;

        if(parent == NULL){
            // Inserção da raiz
            tree->root = newNode;
        } else if(value < parent->value) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }

        tree->quantity += 1;
        return 1;
    } else {
        if(value < node->value) {
            int nodeInserted = insertAVLNode(node->left, value, node, tree);

            if(nodeInserted) {
                // Atualizar a altura do lado esquerdo do nó
                node->leftHeight = 1 + bigger(node->left->rightHeight, node->left->leftHeight);

                if(node->rightHeight - node->leftHeight == -2) {
                    if(node->left->rightHeight - node->left->leftHeight == -1) {
                        // Rotação simples para direita
                        rightRotation();
                    } else {
                        // Rotação dupla para direita
                        leftRotation();
                        rightRotation();
                    }
                }
            }

            return nodeInserted;
        } else {
            int nodeInserted = insertAVLNode(node->right, value, node, tree);
            
            if(nodeInserted) {
                // Atualizar a altura do lado direito do nó
                node->rightHeight = 1 + bigger(node->right->rightHeight, node->right->leftHeight);
                
                if(node->rightHeight - node->leftHeight == 2) {
                    if(node->right->rightHeight - node->right->leftHeight == 1) {
                        // Rotação simples para esquerda

                    } else {
                        // Rotação dupla para esquerda

                    }
                }
            }
            return nodeInserted;
        }
    }
}

int insertAVL(AVLTree *tree, int value) {
    if(tree == NULL) 
        return 0;

    return insertAVLNode(tree->root, value, NULL, tree);
}

void TreePreOrder(AVLNode *node) {
    if(node != NULL){
        printf(" %d ", node->value);
        TreePreOrder(node->left);
        TreePreOrder(node->right);
    }
}

void TreeInOrder(AVLNode *node) {
    if(node != NULL){
        TreeInOrder(node->left);
        printf(" %d ", node->value);
        TreeInOrder(node->right);
    }
}

void TreePosOrder(AVLNode *node) {
    if(node != NULL){
        TreePosOrder(node->left);
        TreePosOrder(node->right);
        printf(" %d ", node->value);
    }
}