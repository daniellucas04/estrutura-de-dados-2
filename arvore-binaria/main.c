#include<stdio.h>
#include<stdlib.h>
#include "arvore.h"

int main(void){
    // Aloca a Árvore Binária
    BinaryTree *tree = newTree();

    insertTree(tree, 6);
    insertTree(tree, 2);
    insertTree(tree, 9);
    insertTree(tree, 1);
    insertTree(tree, 3);
    insertTree(tree, 7);
    insertTree(tree, 5);
    insertTree(tree, 8);
    insertTree(tree, 4);

    int value = 1;

    while(value != 0) {
        system("cls");
        printf("Pre-ordem: ");
        TreePreOrder(tree->root);
        
        printf("\n\nEm-ordem: ");
        TreeInOrder(tree->root);
        
        printf("\n\nPos-ordem: ");
        TreePosOrder(tree->root);

        printf("\n\nDecrescente: ");
        TreeDescending(tree->root);

        printf("\n\nAltura da arvore: ");
        printf("%d", TreeHeight(tree->root));

        printf("\n\nNos folhas: ");
        TreeLeafNode(tree->root);

        if ( ValidBinaryTree(tree->root) )
            printf("\n\nArvore valida");
        else
            printf("\n\nArvore invalida");

        printf("\n\nTamanho: %d\n\n", tree->quantity);

        printf(">> ");
        scanf("%d", &value);
        if(value == 0) 
            break;

        if(value > 0) 
            insertTree(tree, value);
        else if(value < 0)
            removeTree(tree, -value);
    }

    return 0;
}