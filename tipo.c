#include "tipo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tipo{
    char* name;
    int indice;
};

Tipo* inicTipo(char* name, int indice){
    Tipo* tipo = (Tipo*) malloc (sizeof(Tipo));
    tipo -> name = strdup(name);
    tipo -> indice = indice;
    return tipo;
}

void imprimeTipo(Tipo* tipo){
    printf("%s %d\n", tipo -> name, tipo -> indice);
}

void deletaTipo(void* tipo){
    free((void*)((Tipo*) tipo) -> name);
    free(tipo);
}