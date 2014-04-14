#include <iostream>
using namespace std;
#include "types.h"
//------------------------------------


/**
Crea un par (clave, valor) usando los valores pasados por parametro y lo retorna.

O(1)

parametro k = key
parametro v = value
*/
par elem(string k, int v){
	par ret;
	ret.key = k;
	ret.value = v;
	return ret;
}

/**
Hace que un valor "x" del tipo par se pueda imprimir de la manera usual
en C++: "cout << x"
*/
ostream & operator <<(ostream & o, const par & x){
    o << " Key = ";
    o << x.key;
    o << " Value = ";
	o << x.value;
	o << endl;
	return o;
}

/**
Retorna la clave del par pasado por parametro
O(1)
*/
string clave(par p){
    return p.key;
}

/**
Retorna el valor del par pasado por parametro
O(1)
*/
int valor(par p){
    return p.value;
}
