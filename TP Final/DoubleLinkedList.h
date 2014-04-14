#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

//--------------------
#include <iostream>
using namespace std;
//--------------------

template <typename T>
struct Nodo{
    T value;
    Nodo<T> * prev;
    Nodo<T> * next;
};

template <typename T>
struct list{
    Nodo<T> * first;
    Nodo<T> * last;
    int len;
};

template<typename T>
struct Cursor{
    list<T>* xs; // Puntero a la lista completa
    Nodo<T>* n; // Puntero al nodo representado por el cursor
};

/*
CURSOR:

si n != NULL -> xs no puede ser vacia
si xs = NULL -> n = NULL
El cursor no puede utilizarse si n = NULL

INTERFAZ
Cursor<T> cursorHead(List<T>& xs);
Cursor<T> cursorLast(List<T>& xs);
T cursorElem(const Cursor<T>& c);
bool cursorHasNext(const Cursor<T>& c);
bool cursorHasPrev(const Cursor<T>& c);
void cursorNext(Cursor<T>& c);
void cursorPrev(Cursor<T>& c);
void cursorUpdate(Cursor<T>& c, T x);
void cursorRemove(Cursor<T>& c);

*/

/*
INVARIANTE DE REPRESENTACION

Si first = NULL, last tiene que ser = NULL
Si last = NULL, first tiene que ser = NULL
first=last /= NULL --> Hay 1 solo elemento
Se puede llegar a last empezando por first y siguiendo los punteros next.
Tambien en sentido contrario usando los prev.
first->prev = last->next = NULL (si hay al menos un nodo)


INTERFAZ LIST

List<T> empty();
bool isEmpty(const List<T>& xs);
int len(const List<T>& xs);
void cons(T x, List<T>& xs);
void snoc(List<T>& xs, T x);
T head(const List<T>& xs);
T last(const List<T>& xs);
void tail(List<T>& xs);
void init(List<T>& xs);
void destroy(List<T>& xs);
ostream& operator <<(ostream& o, const List<T>& xs);
bool tieneUnElemento(list<T> & xs);
list<T>* deepCopy(list<T> & xs)

*/


// **************************************************************
// * FUNCIONES LIST
// **************************************************************

/**
Retorna un puntero a una lista vacia.
O(1)
*/
template <typename T>
list<T>* empty(){
    list<T> * ret = new list<T>;
    ret->first = NULL;
    ret->last = NULL;
    ret->len = 0;
    return ret;
}

/**
Retorna true si la lista esta vacia, false en caso contrario.
O(1)
*/
template <typename T>
bool isEmpty(list<T> & xs){
    return (xs.first == NULL);
}

/**
Retorna la cantidad de elementos
O(1)
*/
template <typename T>
int len(list<T> & xs){
    return xs.len;
}

/**
Retorna el primer elemento.
O(1)
*/
template <typename T>
T head(list<T> & xs){
	return xs.first->value;
}

/**
Crea un nuevo nodo y lo Agrega al final de la lista.
O(1)
*/
template <typename T>
void snoc(list<T> & xs, T x){
	Nodo<T> * nodo = new Nodo<T>;
	nodo->value = x;
	nodo->next = NULL;
	xs.len += 1;

	if(isEmpty(xs)){
		nodo->prev = NULL;
		xs.first = nodo;
		xs.last = nodo;
	}else{
		nodo->prev = xs.last;
		xs.last->next = nodo;
		xs.last = nodo;
	}

}

/**
Crea un nuevo nodo y lo Agrega al compienzo de la lista.
O(1)
*/
template <typename T>
void cons(T x, list<T> & xs){

    Nodo<T> * nodo = new Nodo<T>;
    nodo->value = x;
    nodo->prev = NULL;
    xs.len += 1;

    if(isEmpty(xs)){
        nodo->next = NULL;
        xs.first = nodo;
        xs.last = nodo;
    }else{
        nodo-> next = xs.first;
        xs.first->prev = nodo;
        xs.first = nodo;
    }

}

/**
Retorna el ultimo elemento
O(1)
*/
template <typename T>
T last(list<T>& xs){
    return xs.last->value;
}

/**
Retorna true si tiene un solo nodo, false en caso contrario.
O(1)
*/
template <typename T>
bool tieneUnElemento(list<T> & xs){
    return (xs.first == xs.last);
}

/**
Borra el primer nodo.
O(1)
*/
template <typename T>
void tail(list<T> & xs){
    if(tieneUnElemento(xs)){
        delete(xs.first);
        xs.first = NULL;
        xs.last = NULL;
        xs.len -= 1;
    }else if(!isEmpty(xs)){
        xs.first = (xs.first)->next;
        delete(xs.first->prev);
        xs.first->prev = NULL;
        xs.len -= 1;
    }
}

/**
Borra el ultimo nodo.
O(1)
*/
template <typename T>
void init(list<T> & xs){
    if(tieneUnElemento(xs)){
        delete(xs.last);
        xs.last = NULL;
        xs.first = NULL;
        xs.len -= 1;
    }else if(!isEmpty(xs)){
        xs.last = (xs.last)->prev;
        delete(xs.last->next);
        xs.last->next = NULL;
        xs.len -= 1;
    }
}

/**
Borra todos los nodos de la lista.
O(1)
*/
template <typename T>
void destroy(list<T> & xs){
	while (!isEmpty(xs)){
        tail(xs);
    }
}


/**
Retorna una copia de la lista
O(n) --> n = cantidad de nodos
Recorre la lista copiando cada nodo
*/
template <typename T>
list<T>* deepCopy(list<T> & xs){
    list<T> * ys = empty<T>();
    for(Nodo<T> * pxs = xs.first; pxs!=NULL; pxs=pxs->next){
        snoc(*ys, pxs->value);
    }
    return ys;
}

/**
...
*/
template <typename T>
ostream& operator<<(ostream& o, const list<T>& xs){

    Nodo<T> * n = xs.first;

    while(n != NULL){
        o << n->value;
        n = n->next;
    }

    return o;
}



// **************************************************************
// * FUNCIONES CURSOR
// **************************************************************

/**
Retorna un cursor que apunta al primer nodo de la lista xs
O(1)
*/
template <typename T>
Cursor<T> cursorHead(list<T> & xs){
    Cursor<T> ret;
    ret.xs = &xs;
    ret.n = xs.first;
    return ret;
}

/**
Retorna un cursor que apunta al ultimo nodo de la lista xs
O(1)
*/
template <typename T>
Cursor<T> cursorLast(list<T> & xs){
    Cursor<T> ret;
    ret.xs = &xs;
    ret.n = xs.last;
    return ret;
}

/**
Retorna true si el nodo pasado por parametro es el ultimo de la lista
O(1)
*/
template <typename T>
bool esUltimoNodo(Nodo<T> * n, list<T> * xs){
    return xs->last == n;
}

/**
Retorna true si el nodo pasado por parametro es el primero de la lista
O(1)
*/
template <typename T>
bool esPrimerNodo(Nodo<T> * n, list<T> * xs){
    return xs->first == n;
}

/**
Retorna true si el cursor pasado por parametro puede avanzar al siguiente nodo de la lista.

    c.n != NULL --------> el cursor apunta a un nodo
    &&

    c.n->next != NULL --> el nodo apuntado por el cursos tiene "next"
    ||
    esUltimoNodo

O(1)
*/
template <typename T>
bool cursorHasNext(const Cursor<T>& c){
    return c.n != NULL && (c.n->next != NULL || esUltimoNodo(c.n , c.xs));
}

/**
Retorna true si el cursor pasado por parametro puede retroceder al aterior nodo de la lista.

    c.n != NULL --------> el cursor apunta a un nodo
    &&

    c.n->next != NULL --> el nodo apuntado por el cursos tiene "prev"
    ||
    esPrimerNodo

O(1)
*/
template <typename T>
bool cursorHasPrev(const Cursor<T>& c){
    return c.n != NULL && (c.n->prev != NULL || esPrimerNodo(c.n, c.xs));
}

/**
Avanza el cursor c al siguiente nodo de la lista
O(1)
*/
template <typename T>
void cursorNext(Cursor<T>& c){
    if(cursorHasNext(c) && cursorHasPrev(c)){
        c.n = c.n->next;
    }
}

/**
Retrocede el cursor c al anterior nodo de la lista
O(1)
*/
template <typename T>
void cursorPrev(Cursor<T>& c){
    if(cursorHasNext(c) && cursorHasPrev(c)){
        c.n = c.n->prev;
    }
}

/**
Se usa en cursorElem y cursorUpdate
Mueve el nodo apuntado por el cursor c al comienzo de la lista
O(1)
*/
template <typename T>
void actualizarNodo(const Cursor<T>& c){

    if(!esPrimerNodo(c.n, c.xs) && !esUltimoNodo(c.n, c.xs)){
        c.n->next->prev = c.n->prev;
        c.n->prev->next = c.n->next;

        c.n->prev = NULL;
        c.n->next = c.xs->first;
        c.xs->first->prev = c.n;
        c.xs->first = c.n;
    }else if(!esPrimerNodo(c.n, c.xs) && esUltimoNodo(c.n, c.xs)){
        c.n->prev->next = NULL;
        c.xs->last = c.n->prev;

        c.n->prev = NULL;
        c.n->next = c.xs->first;

        c.xs->first->prev = c.n;
        c.xs->first = c.n;
    }
}

/**
Devuelve el elemento del nodo apuntado por el cursor c.
O(1)
*/
template <typename T>
T cursorElem(const Cursor<T>& c){
    if(cursorHasNext(c) && cursorHasPrev(c)){
        T ret;
        ret = c.n->value;

        actualizarNodo(c);

        return ret;
    }
    throw "El elemento fue borrado";
}

/**
Actualiza el elemento del nodo apuntado por el cursor c
O(1)
*/
template <typename T>
void cursorUpdate(Cursor<T>& c, T x){
    if(cursorHasNext(c) && cursorHasPrev(c)){
        c.n->value = x;
        actualizarNodo(c);
    }
}

/**
Borra de la lista el nodo apuntado por el cursor c

O(1)
*/
template <typename T>
void cursorRemove(Cursor<T>& c){
    if(cursorHasNext(c) && cursorHasPrev(c)){
        if(!esPrimerNodo(c.n, c.xs) && !esUltimoNodo(c.n, c.xs)){
            c.n->prev->next = c.n->next;
            c.n->next->prev = c.n->prev;
            c.n->next = c.xs->first;
            c.n->next->prev = c.n;
            c.xs->first = c.n;
            tail(*c.xs);
        }else if(esPrimerNodo(c.n, c.xs)){
            tail(*c.xs);
        }else if(esUltimoNodo(c.n, c.xs)){
            init(*c.xs);
        }

        c.n = NULL;
   }
}

// **********************************************************


template <typename T>
void MoverYEliminarNodo(Nodo<T> * n, list<T> & xs){
    if(esPrimerNodo(n, &xs)){
        tail(xs);
    }else if(esUltimoNodo(n, &xs)){
        init(xs);
    }else{
        n->next->prev = n->prev;
        n->prev->next = n->next;
        delete(n);
        xs.len -= 1;
    }
}

template <typename T>
void remover(list<T> & xs, string k){
    Nodo<T> * n = xs.first;

    while(n != NULL){
        if(clavePair(n->value) == k){
            MoverYEliminarNodo(n, xs);
            break;
        }
        n = n->next;
    }
}


#endif // DOUBLELINKEDLIST_H
