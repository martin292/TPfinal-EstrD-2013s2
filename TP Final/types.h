#ifndef TYPES_H
#define TYPES_H

struct par{
	string key;
	int value;
};

/*
No puede existir un key sin un value
No puede existir un value sin una key
*/



//Interfaz------------------------------------------
par elem(string k, int v);
string clave(par p);
int valor(par p);
ostream & operator <<(ostream & o, const par & x);
//--------------------------------------------------

















#include "types.cpp"
#endif // TYPES_H
