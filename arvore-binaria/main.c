#include<stdio.h>
#include<stdlib.h>
#include "arvore.h"

int main(void){
    // Aloca a Árvore Binária
    BinaryTree *tree = newTree();
    int arr[9] = {5, 2, 8, 3, 7, 1, 4, 6, 9}, i;

    // while(value != 0) {
    //     system("cls");
    //     printf("Tamanho: %d\n\n", tree->quantity);
        
    //     scanf("%d", &value);
    //     insertTree(tree, value);
    // }

    for(i=0; i<9; i++)
        insertTree(tree, arr[i]);

    printf("Pre-ordem: ");
    TreePreOrder(tree->root);
    printf("\n\n");
    
    printf("Em-ordem: ");
    TreeOnOrder(tree->root);
    printf("\n\n");
    
    printf("Pos-ordem: ");
    TreePosOrder(tree->root);
    printf("\n\n");

    return 0;
}