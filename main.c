//Função main


#include <stdio.h>
#include <stdlib.h>


#include "hash.c"

int main(){
    
    hashType *hash;
    hash = (hashType *) malloc ( N * sizeof(hashType) );//alocação da hash
    hash = inicializa(hash);//inicaliza tudo com nulo
    
    //Considerando a inclusão dos dados:
    //A 123; B: 234; C: 54; D 19
    int chave = funcaoHash ( 1 );
    hash = insere(hash, chave, 5);
    
    chave = funcaoHash ( 2 );
    hash = insere(hash, chave, 2);
    

    chave = funcaoHash ( 3 );
    hash = insere(hash, chave, 3);
    
    chave = funcaoHash ( 3 );
    hash = insere(hash, chave, 4);
    

    chave = funcaoHash ( 3 );
    hash = insere(hash, chave, 5);
    imprimeHash(hash);
    
    retorna2 ( hash, 2);
    
    return 1;
        
    
}