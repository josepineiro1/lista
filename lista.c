#include "lista.h"
#include <stdlib.h>
/* ******************************************************************
 *                DEFINICION DE LOS TIPOS DE DATOS
 * *****************************************************************/
typedef struct nodo {
    void* dato;
    struct  nodo* proximo;
}nodo_t;

struct lista{
    nodo_t *primero;
    nodo_t *ultimo;
    size_t largo;
};

struct lista_iter{
    nodo_t *nodo;
    nodo_t *anterior;
};
/* ******************************************************************
 *                DEFINICION LA CREACION DEL NODO
 * *****************************************************************/
nodo_t *creo_nodo(void *valor){
    nodo_t* nodo = malloc(sizeof(nodo_t));
    if (!nodo){
        return NULL;
    }
    nodo -> dato = valor;
    nodo -> proximo =NULL;
    return nodo;
}
/* *****************************************************************
 *                    PRIMITIVAS DE LA LISTA
 * *****************************************************************/

lista_t *lista_crear(void){
    lista_t *lista = malloc(sizeof(lista_t));
    if (lista == NULL){
        return NULL;
    }
    lista->primero = NULL;
    lista->ultimo = NULL;
    return lista;
}
bool lista_esta_vacia(const lista_t *lista){
    return lista_largo(lista)==0;
}
bool lista_insertar_primero(lista_t *lista, void *dato){
    nodo_t* nodo = creo_nodo(dato);
    if(!nodo){
        return false;
    }
    if(lista_largo(lista) ==0){
        lista->primero = nodo;
        lista->primero->proximo = lista->ultimo;
        lista->ultimo = nodo;
        return true;
    }
    void* antes_primero = lista->primero;
    lista->primero = nodo;
    lista -> primero->proximo = antes_primero;
    if (lista_largo(lista)==1){
        lista->ultimo=lista->primero->proximo;
        lista->ultimo->proximo=NULL;
    }
    return true;
}
bool lista_insertar_ultimo(lista_t *lista, void *dato){
    if(lista_largo(lista) ==0){
        return lista_insertar_primero(lista,dato);
    }
    void* nodo = creo_nodo(dato);
    if(!nodo){
        return false;
    }
    if (lista_largo(lista)==1){
        lista->ultimo =nodo;
        lista->primero->proximo=lista->ultimo;
        return true;
    }
    lista->ultimo->proximo = nodo;
    lista->ultimo = nodo;
    return true;
}
void *lista_borrar_primero(lista_t *lista){
    if (!lista_esta_vacia(lista)){
        void* dato = lista->primero->dato;
        void* puntero = lista->primero;
        size_t tamano_antes = lista_largo(lista);
        if (tamano_antes==1){
            lista->primero=NULL;
            lista->ultimo=NULL;
            free(puntero);
            return dato;
        }
        lista->primero=lista->primero->proximo;
        if (tamano_antes==2){
            lista->primero->proximo=lista->ultimo;
        }
        free (puntero);
        return dato;
    }
    return NULL;
}
void *lista_ver_primero(const lista_t *lista){
    if (!lista_esta_vacia(lista)){
        return lista->primero->dato;
    }
    return NULL;
}
void *lista_ver_ultimo(const lista_t* lista){
    if (lista_esta_vacia(lista)){
        return NULL;
    }
    if (lista_largo(lista)==1){
        return lista_ver_primero(lista);
    }
    return lista->ultimo->dato;
}
size_t lista_largo(const lista_t *lista){
    size_t indice=0;
    if(lista->primero!=NULL&& lista->primero->dato == lista->ultimo->dato && lista->primero->proximo == lista->ultimo){
        return 1;
    }
    nodo_t* lugar = lista->primero;
    while(lugar!=NULL){
        lugar=lugar->proximo;
        indice++;
    }
    return indice;
}
void lista_destruir(lista_t *lista, void (*destruir_dato)(void *)){
    while (!lista_esta_vacia(lista)){
        if(destruir_dato !=NULL){
            destruir_dato(lista->primero->dato);
        }
        lista_borrar_primero(lista);
    }
    free(lista);
}

/* ******************************************************************
 *                    PRIMITIVAS DEL ITERADOR EXTERNO
 * *****************************************************************/


lista_iter_t *lista_iter_crear(lista_t *lista){
    lista_iter_t *iter = malloc(sizeof(lista_iter_t));
    if (iter == NULL){
        return NULL;
    }
    iter->nodo=lista->primero   ;
    iter->anterior=NULL;
    return iter;
}

bool lista_iter_avanzar(lista_iter_t *iter){
    if(iter->nodo==NULL){
        return false;
    }
    if (iter->nodo==iter->nodo->proximo){
       iter->anterior=iter->nodo;
        iter->nodo =NULL;
        return true;
    }
    iter->anterior=iter->nodo;
    iter->nodo=iter->nodo->proximo;
    return true;
}

void *lista_iter_ver_actual(const lista_iter_t *iter){
    if (iter->nodo!=NULL){
        return iter->nodo->dato;
    }
    return NULL;
}

bool lista_iter_al_final(const lista_iter_t *iter){
    if(iter->nodo==NULL){
        return true;
    }
    return false;
}

void lista_iter_destruir(lista_iter_t *iter){
    free (iter);
}
bool lista_iter_insertar(lista_iter_t *iter, void *dato){
    nodo_t* nuevo_nodo = creo_nodo(dato);
    if (nuevo_nodo==NULL ){
        return false;
    }
    if (iter->anterior==NULL){
        iter->nodo = nuevo_nodo;
        return true;
    }
    nuevo_nodo->proximo=iter->nodo;
    iter->anterior->proximo=nuevo_nodo;
    return true;
}

void *lista_iter_borrar(lista_iter_t *iter){
    if (iter->nodo ==NULL || iter->nodo->proximo==NULL){
        return NULL;
    }
    void* borrado = iter->nodo->proximo->dato;
    void* siguiente_sig = iter->nodo->proximo->proximo;
    free(iter->nodo->proximo);
    iter->nodo->proximo = siguiente_sig;
    return borrado;
}
/* ******************************************************************
 *                    PRIMITIVAS DEL ITERADOR INTERNO
 * *****************************************************************/

void lista_iterar(lista_t *lista, bool visitar(void *dato, void *extra), void *extra){
    nodo_t* nodo = lista->primero;
    void* dato = nodo->dato;
    while(visitar(dato,extra)||nodo!=NULL){
        nodo = nodo->proximo;
        dato = nodo->dato;
    }
}