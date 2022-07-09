#ifndef TIPO_H
#define TIPO_H

typedef struct tipo Tipo;

Tipo* inicTipo(char* name, int indice);

void imprimeTipo(Tipo* tipo);

void deletaTipo(void* tipo);

#endif