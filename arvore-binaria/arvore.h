// Contém implementação de uma árvore binária de busca
#include<stdio.h>
#include<stdlib.h>

/**
 * Node: Estrutura de nó da árvore
 * @param int value = Valor do nó
 * @param Node* left = Endereço do filho à esquerda
 * @param Node* right = Endereço do filho à direita
*/
typedef struct Node {
    int value;
    struct Node *left, *right;
} Node;

/**
 * BinaryTree: Árvore Binária de Busca
 * @param Node* root = Endereço da raiz
 * @param int quantity = Quantidade de elementos da árvore
*/
typedef struct BinaryTree {
    Node *root;
    int quantity;
} BinaryTree;

/**
 * newTree: Cria uma nova árvore binária de busca
 * @return BinaryTree* address
*/
BinaryTree* newTree(){
    // Aloca memória para a árvore
    BinaryTree *tree = (BinaryTree*) malloc(sizeof(BinaryTree));
    if(tree != NULL) {
        // Inicializa a árvore
        tree->root = NULL;
        tree->quantity = 0;
    }
    return tree;
}

/**
 * insertTree: Insere um valor na árvore informada
 * 
 * @param BinaryTree* tree = Endereço da árvore
 * @param int value = Valor a ser inserido 
 * @return bool
*/
int insertTree(BinaryTree *tree, int value){
    // Valida se a árvore existe
    if(tree == NULL) 
        return 0;
    
    // Cria um ponteiro auxiliar para percorrer a árvore
    Node *actual = tree->root;
    Node *parent = NULL;
    while(actual != NULL) {
        parent = actual;
        if(value < actual->value)
            actual = actual->left;
        else
            actual = actual->right;
    }

    // Cria um novo nó
    Node *newNode = (Node*) malloc(sizeof(Node));
    if(newNode == NULL)
        return 0;

    // Atribui os valores ao nó
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;

    // Insere na árvore
    if(parent == NULL)
        tree->root = newNode;
    else if(value < parent->value)
        parent->left = newNode;
    else
        parent->right = newNode;

    tree->quantity = tree->quantity + 1;
    return 1;
}

void TreePreOrder(Node *node) {
    if(node != NULL){
        printf(" %d ", node->value);
        TreePreOrder(node->left);
        TreePreOrder(node->right);
    }
}


void TreePosOrder(Node *node) {
    if(node != NULL){
        TreePosOrder(node->left);
        TreePosOrder(node->right);
        printf(" %d ", node->value);
    }
}


void TreeOnOrder(Node *node) {
    if(node != NULL){
        TreeOnOrder(node->left);
        printf(" %d ", node->value);
        TreeOnOrder(node->right);
    }
}