#include "pila.h"

#include <stdlib.h>

/* Definición del struct pila proporcionado por la cátedra.
 */
struct pila {
    void **datos;
    size_t cantidad;   // Cantidad de elementos almacenados.
    size_t capacidad;  // Capacidad del arreglo 'datos'.
};

//la puse aca porque intente ponerla abajo del bloque de primitivas pero no la tomaba
void redimencion(pila_t *pila){
    if ((pila -> capacidad +1)   >= pila -> cantidad/2){
        size_t capacidad_V2 = pila ->capacidad;
        while (pila-> cantidad+1 >= ((capacidad_V2))){//probe cosas, por alguna razon con esto llega hasta 9 seguidas(antes era 7)
            capacidad_V2=capacidad_V2*2;
        }
        void *nueva_data = realloc (pila ->datos,capacidad_V2*(sizeof(void *)));
        pila ->datos = nueva_data;
        pila -> capacidad= capacidad_V2;//...sin comentarios
    }
}
void redimencion_menos(pila_t *pila){
    if (pila -> capacidad+1 < pila -> cantidad/4){//denuevo, quizas va
        void *nueva_data = realloc (pila ->datos,pila ->capacidad*(sizeof(void *))/2);
        pila ->datos = nueva_data;
        pila -> capacidad= pila->capacidad/2;//...sin comentarios
    }
}
/* *****************************************************************
 *                    PRIMITIVAS DE LA PILA
 * *****************************************************************/
//okey redimencion ya funciona,COOL.
pila_t *pila_crear(){
    pila_t *pila = malloc(sizeof(pila_t));

    if (pila == NULL) {
        return NULL;
    }
    pila->datos = malloc(sizeof(void *));
    pila->capacidad = 50;
    pila -> cantidad = 0;
    return pila;
}

bool pila_apilar(pila_t *pila,void *valor){
    if(pila-> capacidad > pila -> cantidad){
        redimencion(pila);
        pila -> datos[pila -> cantidad] = valor;
        pila -> cantidad ++;
        return true;
    }
        return false;
}
void *pila_desapilar(pila_t *pila){
    if(pila-> capacidad > 0 && pila -> cantidad >0){
        void * devolver = pila-> datos[pila-> cantidad-1];
        pila -> cantidad --;
        redimencion_menos(pila);
        return devolver;

    }
    return NULL;
    }
void *pila_ver_tope(const pila_t *pila){
    if (pila ->cantidad >0){
        return pila-> datos[pila-> cantidad-1];
    }
    return NULL;

}

bool pila_esta_vacia(const pila_t *pila){
    if (pila->cantidad==0){
        return true;
    }
    return false;
}


void pila_destruir(pila_t *pila){
    //avance en la vida llegue a la parte de destruir una lista no vacia y pense podria vaciarla y nadie se enteraria, digo solo alan pero no tendria sentido asi que nada.
    //casi seguro que tiene que ver con el realloc igual
    free(pila -> datos);
    free(pila);
}

// ...