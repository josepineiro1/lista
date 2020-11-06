#include "lista.h"
#include "pila.h"
#include "testing.h"
#include <stdio.h>


static void prueba_lista_vacia(void) {
    // print_test( ... lista_esta_vacia(lista) ... );

    printf("INICIO DE PRUEBAS CON LISTA VACIA \n");

    /* Declaro las variables a utilizar*/
    lista_t *lista = lista_crear();

    /* Inicio de pruebas */
    print_test("creo una lista", lista != NULL);

    /* Pruebo que esta vacia y que no hay elemento para desalistar*/
    print_test("prueba de que esta vacia", lista_esta_vacia(lista));
    print_test("prueba que el primero de la lista es NULL", lista_ver_primero(lista) == NULL);
    print_test("prueba que el ultimo de la lista es NULL", lista_ver_ultimo(lista) == NULL);
    print_test("prueba de eliminar primero estando vacia", lista_borrar_primero(lista)== NULL);

    /* Destruyo la lista*/
    lista_destruir(lista,NULL);
    print_test("la lista fue destruida", true);
}

static void pruebas_lista_con_algunos_elementos(void) {
    printf("\n");
    printf("INICIO DE PRUEBAS CON ALGUNOS ELEMENTOS\n");

    /* Creo una lista*/
    lista_t *lista2 = lista_crear();

    print_test("crear una lista2", lista2 != NULL);

    /* Pruebo que guardar en una lista*/
    int valor1 =1;
    int valor2 =2;
    void *valor3 =NULL;
    int valor4 =3;
    print_test("Prueba introduzco un elemento en la lista al inicio", lista_insertar_primero(lista2,&valor1));//orden = valor1
    print_test("Prueba introduzco otro elemento en la lista al inicio", lista_insertar_primero(lista2,&valor2));//orden = valor2 valor1
    print_test("Veo si 1 se volvio el ultimo valor de la lista", lista_ver_ultimo(lista2)==&valor1);
    print_test("Prueba introduzco un elemento en la lista al final", lista_insertar_ultimo(lista2,&valor3));//orden= valor 2 valor 1 valor 3
    print_test("Prueba introduzco otro elemento en la lista al final", lista_insertar_ultimo(lista2,&valor4));// orden = valor 2 valor 1 valor 3 valor 4

    /* Pruebo obtener los valores de un vector previamente guardados */
    print_test("compruebo el primer valor de la lista2", lista_ver_primero(lista2) == &valor2);
    print_test("elimino el primero de la lista2", lista_borrar_primero(lista2)== &valor2);
    print_test("vuelvo a obtener el tope de lista2", lista_ver_primero(lista2)== &valor1);
    print_test("veo el ultimo de lista2", lista_ver_ultimo(lista2)== &valor4);
    print_test("elimino 1 de la lista2", lista_borrar_primero(lista2)== &valor1);
    print_test("vuelvo a obtener el tope de lista2", lista_ver_primero(lista2)== &valor3);
    print_test("elimino el 3 de la lista2", lista_borrar_primero(lista2)== &valor3);
    print_test("vuelvo a obtener el tope de lista2", lista_ver_primero(lista2)== &valor4);
    print_test("veo el tamaño",lista_largo(lista2)==1);
    print_test("elimino 4 de la lista2", lista_borrar_primero(lista2)== &valor4);
    print_test("veo el tamaño",lista_largo(lista2)==0);//es 2 por ahora
    print_test("vuelvo a obtener el tope de lista2", lista_ver_primero(lista2)== NULL);
    printf("compruebo que se comporta como lista recien creada\n");
    print_test("prueba de que esta vacia", lista_esta_vacia(lista2));
    print_test("prueba que el tope de la lista es NULL", lista_ver_primero(lista2) == NULL);
    print_test("prueba de desalistar estando vacia", lista_borrar_primero(lista2)== NULL);

    /* Destruyo la lista*/
    lista_destruir(lista2,NULL);
    print_test("la lista2 fue destruido", true);
}

void destruir(void* elem){
    pila_destruir(elem);
}

static void pruebas_con_pilas_con_algunos_elementos(void){
    printf("\n");
    printf("INICIO DE PRUEBAS CON PILAS\n");

    /* Creo una pila*/
    pila_t *pila = pila_crear();

    print_test("crear una pila", pila != NULL);

    /* Pruebo que guardar en una pila*/
    int valor1 =1;
    int valor2 =2;
    void *valor3 =NULL;
    int valor4 =3;
    print_test("Prueba introduzco un elemento en la pila", pila_apilar(pila,&valor1));
    print_test("Prueba introduzco dos elemento en la pila", pila_apilar(pila,&valor2));
    print_test("Prueba introduzco tres elemento en la pila", pila_apilar(pila,&valor3));
    print_test("Prueba introduzco cuatro elemento en la pila", pila_apilar(pila,&valor4));

    /* Pruebo obtener los valores de un vector previamente guardados */
    print_test("compruebo el ultimo valor de la pila", pila_ver_tope(pila) == &valor4);

    /* Creo una lista*/
    lista_t *lista3 = lista_crear();

    /*encolo la pila*/
    print_test("Prueba introduzco una pila en la lista", lista_insertar_primero(lista3,pila));
    /* Destruyo la lista*/
    
    lista_destruir(lista3,destruir);
    print_test("la pila fue destruido", true);
    print_test("la lista fue destruido", true);
}

static void prueba_no_salian(void){
    printf("\n");
    printf("INICIO DE PRUEBAS que no salian\n");
    lista_t *lista4 = lista_crear();
    print_test("prueba de que esta vacia", lista_esta_vacia(lista4));
    int valor1 =1;
    int valor2 =2;
    print_test("agrego",lista_insertar_ultimo(lista4,&valor1));
    print_test("veo",lista_ver_primero(lista4)==&valor1);
    print_test("agrego",lista_insertar_ultimo(lista4,&valor2));
    print_test("veo",lista_ver_primero(lista4)==&valor1);
    print_test("largo 2",lista_largo(lista4)==2);
    print_test("quito 1",lista_borrar_primero(lista4)==&valor1);
    print_test("largo 1",lista_largo(lista4)==1);
    print_test("veo",lista_ver_primero(lista4)==&valor2);
    print_test("quito 2",lista_borrar_primero(lista4)==&valor2);
    print_test("largo",lista_largo(lista4)==0);
    print_test("agrego 1",lista_insertar_ultimo(lista4,&valor1));
    print_test("largo 1",lista_largo(lista4)==1);

    /* Destruyo la lista*/
    lista_destruir(lista4,NULL);
    print_test("la lista4 fue destruido", true);
}

static void PRUEBAS_INSERTANDO_ULTIMO_Y_VIENDO_PRIMERO_Y_ULTIMO(void){
    printf("\n");
    printf("INICIO DE PRUEBAS insertando ultimo y viendo primero y ultimo \n");
    lista_t *lista5 = lista_crear();
    int valor1 =1;
    int valor2 =2;
    int valor3 =3;
    print_test("creo lista",lista5!=NULL);
    print_test("esta vacia",lista_esta_vacia(lista5));
    print_test("inserto al ultimo",lista_insertar_ultimo(lista5,&valor1));
    print_test("no vacia", !lista_esta_vacia(lista5));
    print_test("largo 1",lista_largo(lista5)==1);
    print_test("primero es el valor 1",lista_ver_primero(lista5)==&valor1);
    print_test("ultimo valor es 1", lista_ver_ultimo(lista5)==&valor1);
    print_test("inserto al ultimo el valor 2",lista_insertar_ultimo(lista5,&valor2));
    print_test("lista no vacia",!lista_esta_vacia(lista5));
    print_test("largo 2",lista_largo(lista5)==2);
    print_test("Prueba ver primero es valor1",lista_ver_primero(lista5)==&valor1);
    print_test("ultimo es valor2",lista_ver_ultimo(lista5)==&valor2);
    print_test("borrar primero es valor1",lista_borrar_primero(lista5)==&valor1);
    print_test("Prueba ver primero es valor2",lista_ver_primero(lista5)==&valor2);
    print_test("Prueba ver ultimo es valor2",lista_ver_ultimo(lista5)==&valor2);
    print_test("ultimo no es valor es 1", lista_ver_ultimo(lista5)!=&valor1);
    print_test("borrar primero es valor2",lista_borrar_primero(lista5)==&valor2);
    print_test("Prueba ver primero es NULL",lista_ver_primero(lista5)==NULL);
    print_test("Prueba ver ultimo es NULL",lista_ver_ultimo(lista5)==NULL);
    print_test("esta vacia",lista_esta_vacia(lista5));
    print_test("inserto al ultimo el valor 1",lista_insertar_ultimo(lista5,&valor1));
    print_test("largo de la lista es 1",lista_largo(lista5)==1);
    print_test("inserto al ultimo el valor 2",lista_insertar_ultimo(lista5,&valor2));
    print_test("inserto al ultimo el valor 3",lista_insertar_ultimo(lista5,&valor3));
    print_test("Prueba ver primero es valor1",lista_ver_primero(lista5)==&valor1);
    print_test("borrar primero es valor1",lista_borrar_primero(lista5)==&valor1);
    print_test("inserto al ultimo el valor 2",lista_insertar_ultimo(lista5,&valor2));
    print_test("lista no vacia",!lista_esta_vacia(lista5));
    print_test("largo 2",lista_largo(lista5)==3);
    print_test("Prueba ver primero es valor2",lista_ver_primero(lista5)==&valor2);
    print_test("Prueba ver ultimo es valor2",lista_ver_ultimo(lista5)==&valor2);
    print_test("inserto al ultimo el valor 3",lista_insertar_primero(lista5,&valor3));
    print_test("lista no vacia",!lista_esta_vacia(lista5));
    print_test("largo 4",lista_largo(lista5)==4);
    print_test("Prueba ver primero es valor3",lista_ver_primero(lista5)==&valor3);
    print_test("Prueba ver ultimo es valor2",lista_ver_ultimo(lista5)==&valor2);
    print_test("borrar primero es valor3",lista_borrar_primero(lista5)==&valor3);
    print_test("Prueba ver primero es valor2",lista_ver_primero(lista5)==&valor2);
    print_test("Prueba ver ultimo es valor2",lista_ver_ultimo(lista5)==&valor2);
    print_test("borrar primero es valor1",lista_borrar_primero(lista5)==&valor2);
    print_test("largo 2",lista_largo(lista5)==2);
    print_test("borrar primero es valor2",lista_borrar_primero(lista5)==&valor3);
    print_test("borrar primero es valor2",lista_borrar_primero(lista5)==&valor2);
    print_test("Prueba ver primero es NULL",lista_ver_primero(lista5)==NULL);
    print_test("Prueba ver ultimo es NULL",lista_ver_ultimo(lista5)==NULL);
    print_test("lista vacia",lista_esta_vacia(lista5));
    print_test("largo 0",lista_largo(lista5)==0);
    print_test("Prueba ver primero es NULL",lista_ver_primero(lista5)==NULL);
    print_test("Prueba ver ultimo es NULL",lista_ver_ultimo(lista5)==NULL);
    print_test("borrar primero es NULL",lista_borrar_primero(lista5)==NULL);

    /* Destruyo la lista*/
    lista_destruir(lista5,NULL);
    print_test("la lista5 fue destruido", true);
}

static void pruebas_destruir_con_NULL(void){
    printf("\n");
    printf("INICIO DE PRUEBAS DESTRUIR CON NULL \n");
    lista_t *lista6 = lista_crear();
    /* Destruyo la lista*/
    lista_destruir(lista6,NULL);
    print_test("la lista6 fue destruido", true);
}

static void volumen(void){
    printf("\n");
    printf("INICIO DE PRUEBAS VOLUMEN \n");
    lista_t *lista7 = lista_crear();
    for (int indice =10;indice<100;indice+=10){
        print_test("prueba volumen",lista_insertar_ultimo(lista7,&indice));
        print_test("prueba quitar volumen",lista_borrar_primero(lista7));
    }

    /* Destruyo la lista*/
    lista_destruir(lista7,NULL);
    print_test("la lista7 fue destruido", true);

}

static void iterando_lista_vacia(void){
    printf("\n");
    printf("INICIO DE PRUEBAS iteradora \n");
    int valor1 =1;
    lista_t *lista8 = lista_crear();
    lista_iter_t *iter1 = lista_iter_crear(lista8);
    print_test("creo lista",lista8!=NULL);
    print_test("confirmo que esta vacia",lista_esta_vacia(lista8));
    print_test("creo iterador",iter1!=NULL);
    print_test("compruebo que esta al final",lista_iter_al_final(iter1));
    print_test("compruebo que el actual es NULL",lista_iter_ver_actual(iter1)==NULL);
    print_test("avanzar es false",lista_iter_avanzar(iter1)==false);
    print_test("borrar es NULL",lista_iter_borrar(iter1)==NULL);
    print_test("agrego 1 elemento con iter",lista_iter_insertar(iter1,&valor1));
    print_test("confirmo que esta vacia",lista_esta_vacia(lista8));
    /* Destruyo la lista*/
    lista_iter_destruir(iter1);
    print_test("la iter1 fue destruido", true);

    /* Destruyo la lista*/
    lista_destruir(lista8,NULL);
    print_test("la lista8 fue destruido", true);
}

static void iterando_lista_con_elementos(void){
    printf("\n");
    printf("INICIO DE PRUEBAS iteradora con elementos \n");
    lista_t *lista9 = lista_crear();
    int valor1 =1;
    int valor2 =2;
    void *valor3 =NULL;
    int valor4 =3;
    print_test("creo lista",lista9!=NULL);
    print_test("confirmo que esta vacia",lista_esta_vacia(lista9));
    print_test("Prueba introduzco un elemento en la lista al inicio", lista_insertar_primero(lista9,&valor1));//orden = valor1
    print_test("Prueba introduzco otro elemento en la lista al inicio", lista_insertar_primero(lista9,&valor2));//orden = valor2 valor1
    print_test("Veo si 1 se volvio el ultimo valor de la lista", lista_ver_ultimo(lista9)==&valor1);
    print_test("Prueba introduzco un elemento en la lista al final", lista_insertar_ultimo(lista9,&valor3));//orden= valor 2 valor 1 valor 3
    print_test("Prueba introduzco otro elemento en la lista al final", lista_insertar_ultimo(lista9,&valor4));// orden = valor 2 valor 1 valor 3 valor 4
    lista_iter_t *iter2 = lista_iter_crear(lista9);
    print_test("creo iterador",iter2!=NULL);
    print_test("veo si esta apuntando al primero",lista_iter_ver_actual(iter2)==&valor2);
    print_test("veo si eliminar con el iter funciona",lista_iter_borrar(iter2)==&valor1);
    print_test("avanzo con el iter",lista_iter_avanzar(iter2)==true);
    print_test("veo si estoy parado correctamente",lista_iter_ver_actual(iter2)==&valor3);
    print_test("veo el largo de la lista",lista_largo(lista9)==3);
    print_test("veo el primero sigue siendo 2",lista_ver_primero(lista9)==&valor2);
    /* Destruyo el iter*/
    lista_iter_destruir(iter2);
    print_test("la iter2 fue destruido", true);

    /* Destruyo la lista*/
    lista_destruir(lista9,NULL);
    print_test("la lista9 fue destruido", true);
}

static void iter_lista_3_elementos(void){
    printf("\n");
    printf("INICIO DE PRUEBAS iteradora con 3 elementos \n");
    lista_t *lista10 = lista_crear();
    int valor1 =1;
    int valor2 =2;
    int valor3 =3;
    int valor4 =4;

    print_test("creo lista",lista10!=NULL);
    print_test("confirmo que esta vacia",lista_esta_vacia(lista10));
    print_test("Prueba introduzco un elemento en la lista al inicio", lista_insertar_primero(lista10,&valor1));//orden = valor1
    print_test("Prueba introduzco otro elemento en la lista al inicio", lista_insertar_primero(lista10,&valor2));//orden = valor2 valor1
    print_test("Veo si 1 se volvio el ultimo valor de la lista", lista_ver_ultimo(lista10)==&valor1);
    print_test("Prueba introduzco un elemento en la lista al final", lista_insertar_ultimo(lista10,&valor3));//orden= valor 2 valor 1 valor 3
    print_test("Prueba introduzco otro elemento en la lista al final", lista_insertar_ultimo(lista10,&valor4));// orden = valor 2 valor 1 valor 3 valor 4

    lista_iter_t *iter3 = lista_iter_crear(lista10);
    print_test("creo iterador",iter3!=NULL);
    print_test("veo si esta apuntando al primero",lista_iter_ver_actual(iter3)==&valor2);
    print_test("avanzo con el iter",lista_iter_avanzar(iter3)==true);
    print_test("avanzo con el iter",lista_iter_avanzar(iter3)==true);
    print_test("veo si estoy parado correctamente",lista_iter_ver_actual(iter3)==&valor3);
    print_test("veo el largo de la lista",lista_largo(lista10)==4);
    print_test("veo el primero sigue siendo 2",lista_ver_primero(lista10)==&valor2);
    print_test("avanzo con el iter",lista_iter_avanzar(iter3)==true);
    print_test("veo si estoy parado correctamente",lista_iter_ver_actual(iter3)==&valor4);
    print_test("avanzo con el iter",lista_iter_avanzar(iter3)==true);
    print_test("veo si estoy parado correctamente",lista_iter_ver_actual(iter3)==NULL);
    /* Destruyo el iter*/
    lista_iter_destruir(iter3);
    print_test("la iter3 fue destruido", true);

    /* Destruyo la lista*/
    lista_destruir(lista10,NULL);
    print_test("la lista10 fue destruido", true);
}

void pruebas_lista_estudiante() {
    // ...
    prueba_lista_vacia();
    pruebas_lista_con_algunos_elementos();
    pruebas_con_pilas_con_algunos_elementos();
    prueba_no_salian();
    PRUEBAS_INSERTANDO_ULTIMO_Y_VIENDO_PRIMERO_Y_ULTIMO();
    pruebas_destruir_con_NULL();
    volumen();
    iterando_lista_vacia();
    iterando_lista_con_elementos();
    iter_lista_3_elementos();
}

#ifndef CORRECTOR  // Para que no dé conflicto con el main() del corrector.

int main(void) {
    pruebas_lista_estudiante();
    return failure_count() > 0;  // Indica si falló alguna prueba.
}

#endif