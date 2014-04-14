#ifndef LRU_H
#define LRU_H

#include "hash.h"
#include "DoubleLinkedList.h"
#include "types.h"
#include <fstream>

struct LRUCache{
    hashTbl tabla;//Tabla de hash
    list<par>* lista;//Lista de pares
    int max;//Cantidad maxima de pares que puede tener la cache
};

/*
Si la tabla esta vacia, la lista debe ser vacia
La cantidad de pares de la lista no puede ser mayor a max
*/

//INTERFAZ
LRUCache empty(const int maxSize);
bool isEmpty(const LRUCache& c);
int len(const LRUCache& c);
void add(LRUCache& c, par x);
bool has(const LRUCache& c, string k);
par get(LRUCache& c, string k);
void destroy(LRUCache& c);
ostream& operator<<(ostream& o, const LRUCache& c);



















#include "lru.cpp"
#endif // LRU_H
