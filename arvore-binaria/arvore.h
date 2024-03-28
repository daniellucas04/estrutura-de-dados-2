// Contém implementação de uma árvore binária de busca
#include<stdio.h>
#include<stdlib.h>

int leftHeight = 0;
int rightHeight = 0;

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

/**
 * removeTree: Remove um valor da árvore informada
 * 
 * @param BinaryTree* tree = Endereço da árvore
 * @param int value = Valor a ser removido
 * @return bool
*/
int removeTree(BinaryTree *tree, int value) {
    // Verifica se a árvore existe
    if(tree == NULL || tree->quantity == 0)
        return 0;

    // Recebe a raiz
    Node *actual = tree->root;
    Node *parent = NULL;
    // Percorre a árvore em busca do valor informado
    while(value != actual->value && actual != NULL) {
        parent = actual;
        // Se o valor for menor que o nó atual vai para esquerda
        if(value < actual->value)
            actual = actual->left;
        else // Senão, vai para direita
            actual = actual->right;
    }

    // Se o atual não existir, o valor não foi encontrado
    if(actual == NULL)
        return 0;

    if(actual->left == NULL && actual->right == NULL) {
        // Remoção do nó folha
        if(parent == NULL)
            tree->root = NULL;
        else if(value < parent->value)
            parent->left = NULL;
        else
            parent->right = NULL;

    } else if(actual->left == NULL && actual->right != NULL) {
        // Remoção de nós apenas com filho à direita
        if(parent == NULL)
            tree->root = actual->right;
        else if(value < parent->value)
            parent->left = actual->right;
        else
            parent->right = actual->right;
    } else if(actual->left != NULL && actual->right == NULL) {
        // Remoção de nós apenas com filho à esquerda
        if(parent == NULL)
            tree->root = actual->left;
        else if(value < parent->value)
            parent->left = actual->left;
        else
            parent->right = actual->left;
    } else {
        // Remoção de nó com ambos os filhos
        Node *substitute = actual->left;
        Node *parentSubstitute = actual;
        while(substitute->right != NULL) {
            parentSubstitute = substitute; 
            substitute = substitute->right;
        }

        substitute->right = actual->right;
        if(parentSubstitute != actual) {
            parentSubstitute->right = substitute->left;
            substitute->left = actual->left;
        }

        if(parent == NULL)
            tree->root = substitute;
        else if(value < parent->value)
            parent->left = substitute;
        else 
            parent->right = substitute;
    }

    free(actual);
    tree->quantity -= 1;
    return 1;
}

void TreePreOrder(Node *node) {
    if(node != NULL){
        printf(" %d ", node->value);
        TreePreOrder(node->left);
        TreePreOrder(node->right);
    }
}

void TreeInOrder(Node *node) {
    if(node != NULL){
        TreeInOrder(node->left);
        printf(" %d ", node->value);
        TreeInOrder(node->right);
    }
}

void TreePosOrder(Node *node) {
    if(node != NULL){
        TreePosOrder(node->left);
        TreePosOrder(node->right);
        printf(" %d ", node->value);
    }
}

void TreeDescending(Node *node) {
    if(node != NULL){
        TreeDescending(node->right);
        printf(" %d ", node->value);
        TreeDescending(node->left);
    }
}