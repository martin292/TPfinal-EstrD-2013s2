#include "hash.h"
#include <iostream>
using namespace std;
//-------------------------


/**
Retorna un hashTbl vacio con tamaño "size"
O(n) --> n = size
*/
hashTbl emptyHash(const int size){
    hashTbl ret;

    ret.t = new list<Pair>*[size];

    for(int i = 0; i < size; i++){
        ret.t[i] = NULL;
    }

    ret.tSize = size;
    ret.cant = 0;

    return ret;
}

/**
Retorna true si el hashTbl esta vacio
O(1)
*/
bool isEmptyHash(const hashTbl& ht){
    return ht.cant == 0;
}

/**
Retorna el tamaño del hash
O(1)
*/
int len(const hashTbl& ht){
    return ht.tSize;
}

/**
Funcion de hash enviada a la lista de la materia
*/
unsigned long hash(string s) {
  unsigned long h = 5381;

  for (unsigned int i = 0; i < s.length(); i++) {
    h = (h << 5) + h + s[i];
  }

  return h;
}

/**
Retorna true si encuentra la clave "k"

    O(n) n = l
    En peor caso debe recorrer toda una lista para encontrar la calve.
*/
bool has(const hashTbl& ht, string k){
    unsigned int i = hash(k) % ht.tSize;

    bool ret = false;

    if(ht.t[i] != NULL){
        list<Pair>* l = deepCopy(*ht.t[i]);

        while(!isEmpty(*l)){
            ret = ret || (head(*l).key == k);
            if(ret) return ret;
            tail(*l);
        }
    }

    return ret;
}

/**
Busca en la lista la calve "k" y retorna el Cursos asociado
    O(n) n = l
    En peor caso debe recorrer toda una lista para encontrar la calve.
*/
Cursor<par> retCursor(list<Pair> & xs, string k){
    list<Pair>* l = deepCopy(xs);
    Pair p;

    while(!isEmpty(*l)){
        if(head(*l).key == k){
            p = head(*l);
            return p.val;
        }
        tail(*l);
    }

    return p.val;
}

/**
Si la calve "k" existe, llama a retCursor.
O(n) --> has = O(n)
*/
Cursor<par> get(const hashTbl& ht, string k){
    unsigned int i = hash(k) % ht.tSize;

    if(has(ht, k)){
        return retCursor(*ht.t[i], k);
    }

    throw "El cursor no existe";
}

/**
Agrega un Pair a la tabla de hash en la posicion "i"
O(1)
*/
void agregarPair(Pair p, hashTbl& ht, unsigned int i){
    if(ht.t[i] == NULL){
        list<Pair>* l = empty<Pair>();
        ht.t[i] = l;
        snoc(*ht.t[i], p);
    }else{
        snoc(*ht.t[i], p);
    }
}

/**
Si no tiene la calve "k", crea un nuevo pair y lo agrega.
Si tiene la calve "k", actualiza el cursor.
O(n) -->has
*/
void add(hashTbl& ht, string k, Cursor<par> c){
    unsigned int i = hash(k) % ht.tSize;

    if(!has(ht, k)){
        Pair p;
        p.key = k;
        p.val = c;
        ht.cant += 1;
        agregarPair(p, ht, i);
    }else{
        Cursor<par> cc = get(ht, k);
        cursorUpdate(cc, cursorElem(c));
    }
}

/**
si tiene la calve "k", remueve el cursor.
O(n) --> has
*/
void del(hashTbl& ht, string k){
    //if(has(ht, k)){
        Cursor<par> c = get(ht, k);
        cursorRemove(c);
        ht.cant -= 1;
    //}
}

void borrar(hashTbl& ht, string k){
    unsigned int i = hash(k) % ht.tSize;

    remover(*ht.t[i], k);

}

/**
Libera la memoria
*/
void destroyHash(hashTbl& ht){
    for(int i = 0; i<ht.tSize; i++){
        if(ht.t[i] != NULL)
        destroy(*ht.t[i]);
    }
    delete[] ht.t;
}


string clavePair(Pair & p){
    return p.key;
}
