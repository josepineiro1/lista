#ifndef LISTA_H
#define LISTA_H
#include <stdlib.h>
#include <stdbool.h> 
typedef struct lista lista_t;

typedef struct lista_iter lista_iter_t;


/* ******************************************************************
 *                    PRIMITIVAS DE LA LISTA
 * *****************************************************************/

// Crea una lista.
// Post: devuelve una nueva lista vacía.
lista_t *lista_crear(void);


// Devuelve verdadero si la lista no tiene elementos en ella, false en caso contrario.
// Pre: la lista fue creada.
// Post: devuelve el numero de elemntos en la lista.
bool lista_esta_vacia(const lista_t *lista);

// Agrega un nuevo elemento al inicio de la lista. Devuelve falso en caso de error.
// Pre: la lista fue creada.
// Post: se agregó un nuevo elemento al inicio de la lista.
bool lista_insertar_primero(lista_t *lista, void *dato);

// Agrega un nuevo elemento al final de la lista. Devuelve falso en caso de error.
// Pre: la lista fue creada.
// Post: se agregó un nuevo elemento al final de la lista.
bool lista_insertar_ultimo(lista_t *lista, void *dato);

// elimina el elemento al inicio de la lista. Devuelve falso en caso de error.
// Pre: la lista fue creada y tiene un elemento en ella.
// Post: se elimina un nuevo elemento al inicio de la lista.
void *lista_borrar_primero(lista_t *lista);

// Obtiene el valor del primer elemento de la lista. Si la lista tiene
// elementos, se devuelve el valor del primero, si está vacía devuelve NULL.
// Pre: la lista fue creada.
// Post: se devolvió el primer elemento de la lista, cuando no está vacía.
void *lista_ver_primero(const lista_t *lista);

// Obtiene el valor del ultimo elemento de la lista. Si la lista tiene
// elementos, se devuelve el valor del ultimo,si solo tiene uno devuelve el primero(que seria el primero y el ultimo) si está vacía devuelve NULL.
// Pre: la lista fue creada.
// Post: se devolvió el ultimo elemento de la lista, cuando no está vacía.
void *lista_ver_ultimo(const lista_t* lista);

//Obtiene el numero de elementos en la lista.
// Pre: la lista fue creada.
// Post: se devuelve el numero de elementos en la lista.
size_t lista_largo(const lista_t *lista);

// Destruye la lista. Si se recibe la función destruir_dato por parámetro,
// para cada uno de los elementos de la lista llama a destruir_dato.
// Pre: la lista fue creada. destruir_dato es una función capaz de destruir
// los datos de la lista, o NULL en caso de que no se la utilice.
// Post: se eliminaron todos los elementos de la lista.
void lista_destruir(lista_t *lista, void (*destruir_dato)(void *));


/* ******************************************************************
 *                    PRIMITIVAS DEL ITERADOR EXTERNO
 * *****************************************************************/
//crea un iterador para el uso de barbara.
//Pre: una lista fue creada.
//Post: devuelve un iterador a la primera posicion de la lista.
lista_iter_t *lista_iter_crear(lista_t *lista);
//Avanza con el iterador creado a la siguiente posicion de la lista.
//Pre: una lista fue creada y un iterador tambien.
//Post: devuelve un iterador a la siguiente posicion de la lista.
bool lista_iter_avanzar(lista_iter_t *iter);
//Devuelve el dato en la lista al que señala el iterador.
//Pre: una lista fue creada y un iterador tambien.
//Post: devuelve el dato al que apunta el iterador en la lista.
void *lista_iter_ver_actual(const lista_iter_t *iter);
//envia al iterador al final de la lista.
//Pre: una lista fue creada y un iterador tambien.
//Post: envia al iterador a la posicion final.Devuelve verdadero si lo mando correctamente, falso en caso contrario.
bool lista_iter_al_final(const lista_iter_t *iter);
//destruye el iterador que uso de barbara.
//Pre: una lista fue creada y un iterador tambien.
//Post: destruye un iterador que apuntaba a una lista.
void lista_iter_destruir(lista_iter_t *iter);
//inserta un elemento en la posicion siguiente a la que esta el iterador.
//Pre: una lista fue creada y un iterador tambien.
//Post: devuelve verdadero si inserto el dato correctamente, falso en caso contrario.
bool lista_iter_insertar(lista_iter_t *iter, void *dato);
//elimina el dato siguiente al que apunta el iterador.
//Pre: una lista fue creada y un iterador tambien.
//Post: devuelve el dato del nodo eliminado.
void *lista_iter_borrar(lista_iter_t *iter);


/* ******************************************************************
 *                    PRIMITIVAS DEL ITERADOR interno
 * *****************************************************************/
//realiza la accion visitar hasta que no tenga que o se termine.
//pre: lista creada.
//pos: hace lo que hace el visitar recorriendo la lista o nada en caso que no haya funcion visitar.
void lista_iterar(lista_t *lista, bool visitar(void *dato, void *extra), void *extra);


/* *****************************************************************
 *                      PRUEBAS UNITARIAS
 * *****************************************************************/

// Realiza pruebas sobre la implementación realizada.
//
// Las pruebas deben emplazarse en el archivo ‘pruebas_lista.c’, y
// solamente pueden emplear la interfaz pública tal y como aparece en lista.h
// (esto es, las pruebas no pueden acceder a los miembros del struct lista).
//
// Para la implementación de las pruebas se debe emplear la función
// print_test(), como se ha visto en TPs anteriores.
void pruebas_lista_estudiante(void);
#endif //LISTA_H