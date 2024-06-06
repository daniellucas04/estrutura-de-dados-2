// Contém implementação de uma árvore binária de busca
#include "avl.h"

int main(void) {
    AVLTree *tree = newAVL();

    printf("%d", insertAVL(tree, 2));
    // insertAVL(tree, 6);
    // insertAVL(tree, 7);
    // insertAVL(tree, 3);
    // insertAVL(tree, 4);
    // insertAVL(tree, 5);
    // insertAVL(tree, 1);

    // TreePosOrder(tree->root);
    return 0;
}