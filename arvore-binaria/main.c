#include<stdio.h>
#include<stdlib.h>
#include "arvore.h"

int main(void){
    // Aloca a Árvore Binária
    BinaryTree *tree = newTree();
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

    printf("\n\nAltura da arvore: ");
    printf("%d", TreeHeight(tree->root));

    return 0;
}