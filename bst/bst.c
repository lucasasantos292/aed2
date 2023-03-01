//Implementação das funções.

#include "bst.h"
#include <stdio.h>
#include <stdlib.h>


arvore adicionar (arvore raiz, int valor) {
    //Caso Base - Adicionar em uma árvore vazia
    if(raiz == NULL) {
        //1. Alocar o espaço em memória para acomodar o novo nó
        arvore novo = (arvore) malloc (sizeof(no));

        //2. Inicializar os valores das variáveis membro do struct
        novo->valor = valor;
        novo->esq = NULL;
        novo->dir = NULL;

        //3. Atualizar a raiz relativa da (sub-)árvore
        return novo;
    }

    //Os casos recursivos
    if(valor >= raiz->valor) {
        //chamada recursiva para inserir na sub-árvore a direita
        raiz->dir = adicionar(raiz->dir,valor);
    } else {
        //chamada recursiva para inserir na sub-árvore a esquerda
        raiz->esq = adicionar(raiz->esq,valor);
    }
    return raiz;
}

/*
Caso base:
1. Elemento encontrado
2. árvore vazia (elemento não encontrado)
Caso(s) recursivo(s):
*/
arvore procurar(arvore raiz, int valor){
      //caso base 1
      if(raiz == NULL) {
         return NULL;
      }

      //caso base 2
      if(raiz-> valor == valor)  {
         return raiz;
      }
      if(valor >= raiz->valor) {
        return procurar(raiz->dir,valor);
    } else {
        return procurar(raiz->esq,valor);
    }   
    

}


arvore remover (arvore raiz, int valor) {
      //caso base 1
      if(raiz == NULL) {
         return NULL;
      }

      //Elemento encontrado
      //Verificar qual caso do remover estamos tratando
      if(raiz-> valor == valor)  {
            //Caso 1: Elemento a ser removido não possui filhos
            if(raiz->esq == NULL && raiz->dir == NULL) {
                free(raiz);
                return NULL;
            }
            //Caso 2: Elemento possui exatamente um filho
            //Caso 2a: Elemento possui exatamente um filho esquerdo
            if(raiz->esq != NULL && raiz->dir == NULL) {
                no * filho = raiz->esq;
                free(raiz);
                return filho;
            }

            //Caso 2b: Elemento possui exatamente um filho direito
            //implementar o simétrico

         
            //Caso 3: Elemento possui os dois filhos
            if(raiz->esq != NULL && raiz->dir != NULL) {
                int m = maior(raiz->esq);
                raiz->valor = m;
                raiz->esq = remover(raiz->esq, m);
                return raiz;
            }   
      }
      if(valor >= raiz->valor) {
        raiz->dir = remover(raiz->dir,valor);
    } else {
        raiz->esq = remover(raiz->esq,valor);
    }   

    return raiz;
}

int maior(arvore raiz) {
    if(raiz == NULL) {
        return -1;
    }

    no* temp = raiz;
    while(temp->dir != NULL) {
       temp = temp->dir;
    }
    return temp->valor;
}

void preorder(arvore a){
    if(a != NULL) {
        printf("[%d]", a->valor);
        preorder(a->esq);
        preorder(a->dir);
    }
}

void inorder(arvore a){
    if(a != NULL) {
        preorder(a->esq);
        printf("[%d]", a->valor);
        preorder(a->dir);
    }
}

void posorder(arvore a){
    if(a != NULL) {
        preorder(a->esq);
        preorder(a->dir);
        printf("[%d]", a->valor);
    }
}