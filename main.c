#include "lista.h"
#include "tipo.h"
#include <stdio.h>


int main(){
    Lista* listaTeste = inicLista(deletaTipo, imprimeTipo);
    
    Tipo* juma = inicTipo("JUMA", 1);
    Tipo* jove = inicTipo("Jove", 2);
    Tipo* aaaa = inicTipo("aaaa", 3);

    insere(listaTeste, aaaa);
    insere(listaTeste, jove);
    insere(listaTeste, juma);

    retira(listaTeste, aaaa);

    imprime(listaTeste);

    deleta(listaTeste);
    return 0;
}