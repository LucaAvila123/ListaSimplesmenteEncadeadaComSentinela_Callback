#ifndef LISTA_H
#define LISTA_H

typedef struct lista Lista;

Lista* inicLista(void (RemoveItem(void*)), void (ImprimeItem(void*)));

void insere(Lista* lista, void* item);

void retira(Lista* lista, void* item);

void imprime(Lista* lista);

void deleta(Lista* lista);

#endif