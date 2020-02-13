/*
 * Tabela Hash: Usada em sistemas em que os dados podem ser identificados. Espera-se que usando esse identificador (chave) agente possa determinar uma posição "unica" na tabela, fazendo com que o acesso seja direto. No entanto, há a possibilidade de ocorrem colisões que podem ser tratadas com duas estrategias distintas: reposicionamento, ou com lista encadeada.
 * Tentar modelar uma tabela com ocupação em torno de 60%.
 */

#define N 10

struct hash1{
    int dado;
    struct hash1 *prox;
    
};
typedef struct hash1 tipoDado;


struct hash{
    tipoDado *tabHash;
};
typedef struct hash tipoHash;

typedef struct hashType {
    int data;
    struct hashType * next;
} hashType;


//prototipos
int funcaoHash(int chave);
hashType * insere(hashType *tab, int chave, int valor);
char retorna(tipoHash *tabHash,int chave);
void imprimeHash(hashType *tabHash);


#include <stdio.h>
#include <stdlib.h>

#ifndef HASH_C
#define HASH_C


/*Implementação de uma função Hash simples, sem nenhum tipo de tratamento estatistico*/
int funcaoHash(int valor){
    //é a pior função hash, mas a mais simples
    return valor%N;//divide a nossa chave pelo o tamanho do vetor, divide e pega o resto
    
}

//Função que realiza a alocação de um novo nó
hashType* alocaNo(int valor){
    hashType *novoNo;
    
    novoNo = (hashType*) malloc(sizeof(hashType));
    if(novoNo){
        novoNo->data = valor;// na posicao sera inserida
        novoNo->next = NULL;// e o proximo dessa posicao passa a apontar para nulo
        
    }
    return novoNo;
}


// Função que inicializa a tabela hash, garantindo sua consistencia. Cada campo da tabela será inicializa com '-1' de modo a sinalizar que o campo esta vazio*/
hashType * inicializa(hashType *tab){
    int i;
    //tabela inicializa como aponta todos seus proximos para nulos
    for( i = 0; i < N; i++){

        tab[i].next = NULL;//aponta o proximo para nulos
    }
    return tab;
}


//Função que inserção de valor na tabela Hash
hashType * insere(hashType *tab, int chave, int valor){
    hashType *aux;//iniciacizando uma variavel auxiliar 

    aux = tab[chave].next;// faz essa variavel apontar para o proximo desse numero escolhido
    if(aux == NULL){//se nao tiver nenhuma valor neste da tabela
            tab[chave].next = alocaNo(valor);//entao aloca a primeiro valor desse "subvetor"
            tab[chave].data = valor;//coloca o valor
    }
    else{//se tiver mais de um valor, percorre ate encontrar nulo
        while(aux->next != NULL){
            aux = aux->next;//vai indo para o proximo
        }//quando encontrar nulo aloca esse valor
        aux->next =  alocaNo(valor);
    }
    return tab;
    
}



//Função de impressao da tabela Hash, tem como objetivo exibir a estrutura da tabela, especialmente para fins de debugação*/
void imprimeHash(hashType *tab){
        int i;
        
        for(i = 0; i < N; i++){
            if(tab[i].next == NULL ){//se a proxima posição estiver apontar para nulo, ou seja, nao tem mais nenhuma valor neste subvetor, entao imprime a msgn de campo vazio
                printf("[#%d][Campo vazio]\n", i);
                
            }else{
                printf("[#%d]->[%d]\n",i,tab[i].data);
            }
            
        }
}

    
char retorna2 ( hashType * tab, int valor ) {
    int chave = funcaoHash ( valor );
    hashType * aux = tab[chave].next;
    int cont = 1;
    
    //percorrendo e procurando
    while ( aux->next != NULL ) {
        aux = aux->next;
        
    }
    if ( aux->data == valor )
        printf ( "encontrado [%d],%d.\n",cont, valor );
    else puts ( "error" );
}






#endif
