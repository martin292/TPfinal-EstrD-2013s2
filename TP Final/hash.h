#ifndef HASH_H
#define HASH_H
//-----------------------------
#include <iostream>

//-----------------------------
#include <iostream>
using namespace std;
#include "DoubleLinkedList.h"
//-----------------------------

struct Pair{
    string key;//Clave
    Cursor<par> val;//Cursor
};

struct hashTbl{
    list<Pair>** t;//Array de listas
    int tSize;//Tamaño del array (> 0)
    int cant;//Cantidad de elementos (>= 0)
};


//Interfaz
hashTbl emptyHash(const int size);
bool isEmptyHash(const hashTbl& ht);
int len(const hashTbl& ht);
void add(hashTbl& ht, string k, Cursor<par> c);
bool has(const hashTbl& ht, string k);
Cursor<par> get(const hashTbl& ht, string k);
void del(hashTbl& ht, string k);
void destroyHash(hashTbl& ht);















#include "hash.cpp"
#endif // HASH_H
