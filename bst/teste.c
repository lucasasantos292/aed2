//main

#include bst.h
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv) {
    //Declaração de uma variável do tipo árvore
    arvore a;
    int opcao, valor;
    //Inicialização da árvore
    a = NULL;

    while(1) {
        scanf(%d, &opcao);
        switch(opcao) {
            case 1:
                scanf(%d, &valor);
                a = adicionar(a, valor);
                break;
            case 2:
                preorder(a);
                printf(n);
                break;

            case 99:
                return 0;

        }

    }    
}

