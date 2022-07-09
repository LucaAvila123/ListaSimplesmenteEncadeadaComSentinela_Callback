#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node Node;

struct lista{
    Node* prim;
    Node* ult;
    void (*Remove) (void*); // tentando colocar função de callback, basicamente
    void (*Imprime) (void*);
};

struct node{
    void* item;
    Node* next;
};

Lista* inicLista(void (*RemoveItem)(void* data), void (*ImprimeItem)(void* data)){
    Lista* lista = (Lista*) malloc (sizeof(Lista));
    lista -> Remove = RemoveItem;
    lista -> Imprime = ImprimeItem;
    
    lista -> prim = NULL;
    lista -> ult = NULL;
    return lista;
}

void insere(Lista* lista, void* item){
    Node* node = (Node*) malloc (sizeof(Node));
    node -> item = item;

    if(lista -> prim == NULL){
        lista -> prim = node;
        lista -> ult = node;
        lista -> ult -> next = NULL;
    }
    else{
        node -> next = lista -> prim;
        lista -> prim = node; 
    }
}

void imprime(Lista* lista){
    Node* p = lista -> prim;

    while(p != NULL){
        lista -> Imprime (p -> item);
        p = p -> next;
    }
}

void retira(Lista* lista, void* item){
    Node* p = lista -> prim;
    Node* temp = NULL;
    while(p != NULL && p -> item != item){
        temp = p;
        p = p-> next;
    }
    if(p == NULL) return;
    lista -> Remove (p->item);
    if(p == lista -> prim){
        lista -> prim = p -> next;
    }
    else{
        temp -> next = p -> next;
    }
    free(p);
}

void deleta(Lista* lista){
    Node* p = lista -> prim;
    Node* temp = NULL;

    while(p != NULL){
        temp = p -> next;
        lista -> Remove (p -> item);
        free(p);

        p = temp;
    }

    free(lista);
}
