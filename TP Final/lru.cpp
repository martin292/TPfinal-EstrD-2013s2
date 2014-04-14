#include "lru.h"

/**
Retorna un LRUCache con tamaño maximo "maxSize"
O(1)
*/
LRUCache empty(const int maxSize){
    LRUCache ret;

    ret.tabla = emptyHash(maxSize/2);
    ret.lista = empty<par>();
    ret.max = maxSize;

    return ret;
}

/**
Retorna true si el cache esta vacio
O(1)
*/
bool isEmpty(const LRUCache& c){
    return isEmptyHash(c.tabla);
}

/**
Retorna la cantidad de elementos
O(1)
*/
int cant(const LRUCache& c){
    return len(*c.lista);
}


/**
Retorna el tamaño del cache
O(1)
*/
int len(const LRUCache& c){
    //return len(c.tabla);
    return cant(c);
}

/**
Retorna true si existe la calve "k"
O(n)
*/
bool has(const LRUCache& c, string k){
    return has(c.tabla, k);
}

/**
Libera la memoria
*/
void destroy(LRUCache& c){
    destroyHash(c.tabla);
    destroy(*c.lista);
}

/**
Elimina el par menos recientemente usado
O(n) --> del = O(n)
*/
void eliminarParLRU(LRUCache& c){
    par p = last(*c.lista);
    string k = clave(p);
    del(c.tabla, k);
    borrar(c.tabla, k);
}

/**
Retorna true si la cache esta llena
O(1)
*/
bool cacheLlena(LRUCache & c){
    return len(*c.lista) == c.max;
}

/**
Si la cache esta llena elimina el par menos recientemente usado y luego agrega el nuevo par
O(n)
*/
void agregarElemento(LRUCache& c, par x){
    if(cacheLlena(c)){
        eliminarParLRU(c);
    }
    cons(x, *c.lista);
    Cursor<par> cu = cursorHead(*c.lista);
    //add(c.tabla, x.key, cu);
    add(c.tabla, clave(x), cu);
}

/**
Si el par no existe, lo agrega a la cache
O(n)
*/
void add(LRUCache& c, par x){

    if(!has(c.tabla, clave(x))){
        agregarElemento(c, x);
    }
}

/**
Retorna el par de la calve "k"
O(1)
*/
par get(LRUCache& c, string k){
    return cursorElem(get(c.tabla, k));
}




ostream& operator<<(ostream& o, const LRUCache& c){
    o << *c.lista;
    return o;
}





