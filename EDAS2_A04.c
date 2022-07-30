/*
Desenvolva um codigo que inverte as letras de cada palavra de um texto terminado por
ponto (.) preservando a ordem das palavras. Por exemplo, dado o texto:
ESTE EXERCICIO EH MUITO FACIL. DEZ GARANTIDO NA PROVA.
A saida deve ser:
ETSE OICICREXE HE OTIUM LICAF. ZED ODITNARAG AN AVORP.
*/

#include <stdio.h>
#include <stdlib.h>

//Registro dos nos
typedef struct tipoNo{
    char caractere;
    struct tipoNo *prox;
}No;

//Funcoes
No *empilhar(No *pilha, char c);
No *desempilhar(No **pilha);
void inverterCaracteres(char x[]);

int main(){
    char t1[450] = {"ESTE EXERCICIO EH MUITO FACIL."};
    char t2[450] = {"DEZ GARANTIDO NA PROVA."};

    printf("Texto original:\n-> %s %s\n\n", t1, t2);
    printf("Texto com a ordem dos caracteres invertida:\n-> ");
    inverterCaracteres(t1);
    inverterCaracteres(t2);

    printf("\n\n");
    system("PAUSE");
    return 0;
}

//Empilha cada no ao topo da pilha
No *empilhar(No *pilha, char c){
    No *novoNo = (No*) malloc(sizeof(No)); //Alocacao de memoria para o no

    if(novoNo != NULL){ //Checa se foi alocado espaco para o novo no
        novoNo->caractere = c; //Emprega o caractere c como valor do novo no
        novoNo->prox = pilha; //Posiciona o novo no ao topo da pilha
        return novoNo; //Retorna o novo no
    }else{
        printf("\nOcorreu um erro.\n");
        return 0;
    }
}

//Desempilha o no ao topo da pilha
No *desempilhar(No **pilha){
    No *remover = NULL; //No remover eh inicializado como nulo, somentente adquirindo valor caso incorpore um no de valor diferente

    if(*pilha != NULL){ //Checa se o topo da pilha eh diferente de nulo
        remover = *pilha; //Remover recebe o conteudo do no ao topo da pilha
        *pilha = remover->prox; //Substitui o no ao topo da pilha pelo no subsequente
    }else{
        printf("\tA pilha esta vazia.\n");
    }

    return remover; //Retorna o valor a ser desempilhado
}

//Inverte as letras de cada palavra preservando sua ordem no texto
void inverterCaracteres(char x[]){
    No *remover, *pilha = NULL;
    int i = 0;

    while(x[i] != '.'){ //Ponto final marca o final de cada texto
        if(x[i] != ' '){ //Espaco marca o final de cada palavra
            pilha = empilhar(pilha, x[i]); //Incorpora na pilha os caracteres que formam uma palavra
        }else{ //Imprime palavra ao encontrar espaco
            while(pilha != NULL){ //Desempilha os caracteres que formam uma palavra ate a pilha ficar vazia (cada pilha incorpora uma palavra)
                remover = desempilhar(&pilha); //Remover recebe o caractere a ser imprimido
                printf("%c", remover->caractere); //Imprime o caractere
                free(remover); //Libera remover apos imprimir o caractere incorporado
            }
            printf(" "); //Separa cada palavra com um espaco
        }
        i++;
    }
    while(pilha != NULL){ //Desempilha a ultima palavra, ainda incorporada na pilha
        remover = desempilhar(&pilha);
        printf("%c", remover->caractere);
        free(remover);
    }
    printf(". "); //Inclui ponto final ao fim da ultima palavra do texto
}
