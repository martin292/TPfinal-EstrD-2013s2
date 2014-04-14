#include <iostream>
using namespace std;
#include "types.h"
#include "DoubleLinkedList.h"
#include "hash.h"
#include "lru.h"
//----------------------------------------------------

// *************************************************************
// * TESTS PAR
// *************************************************************

//Testea la creacion de un par
bool testElem(){
    par p = elem("A", 1);

    bool ret = false || ((p.key == "A")&&(p.value == 1));

    return ret;
}

//Testea el retorno de la clave de un par
bool testClave(){
    par p = elem("A", 1);

    bool ret = false || clave(p) == "A";

    return ret;
}

//Testea el retorno del valor de un par
bool testValor(){
    par p = elem("A", 1);

    bool ret = false || valor(p) == 1;

    return ret;
}

// *************************************************************
// * TESTS DOUBLE LINKED LIST
// *************************************************************

//Testea la creacion de una lista
bool testEmpty(){
    list<int> * lista = empty<int>();
    bool ret = false || (isEmpty(*lista));
    destroy(*lista);

    return ret;
}

//Testea el retorno del head de una lista
bool testHead(){
    list<int>* lista = empty<int>();
    snoc(*lista, 1);

    bool ret = false || (head(*lista) == 1);

    destroy(*lista);

    return ret;
}

//Testea la funcion cons
bool testCons(){
    list<int>* lista = empty<int>();
    cons(2, *lista);
    cons(1, *lista);
    snoc(*lista, 3);

    bool ret = false || (head(*lista) == 1);

    destroy(*lista);

    return ret;
}

//Testea la funcion snoc
bool testSnoc(){
    list<int>* lista = empty<int>();
    snoc(*lista, 1);
    snoc(*lista, 2);

    bool ret = false || (head(*lista) == 1);

    destroy(*lista);

    return ret;
}

//Testea la funcion tail
bool testTail(){
    list<int>* lista = empty<int>();
    cons(1, *lista);
    snoc(*lista, 2);

    tail(*lista);

    bool ret = false || (head(*lista) == 2);

    destroy(*lista);

    return ret;
}

//Testea la funcion init
bool testInit(){
    list<int>* lista = empty<int>();
    cons(1, *lista);
    snoc(*lista, 2);

    init(*lista);

    bool ret = false || (head(*lista) == 1);

    destroy(*lista);

    return ret;
}

//Testea la destruccion de una lista
bool testDestroy(){
    list<int>* lista = empty<int>();
    cons(1, *lista);

    destroy(*lista);

    return isEmpty(*lista);
}


// *************************************************************
// * TESTS CURSOR
// *************************************************************

//Testea la creacion de un cursor que apunta al head de una lista
bool testCursorHead(){
    list<int> * l = empty<int>();
    cons(1, *l);
    snoc(*l, 2);

    Cursor<int> c = cursorHead<int>(*l);

    bool ret = false || (c.n->value == 1);

    destroy(*l);

    return ret;
}

//Testea la creacion de un cursor que apunta al last de una lista
bool testCursorLast(){
    list<int> * l = empty<int>();
    cons(1, *l);
    snoc(*l, 2);

    Cursor<int> c = cursorLast(*l);

    bool ret = false || (c.n->value == 2);

    destroy(*l);

    return ret;
}

//Testea si un cursor tiene Next
bool testCursorHasNext(){
    list<int> * l = empty<int>();
    cons(1, *l);
    snoc(*l, 2);

    Cursor<int> c = cursorHead<int>(*l);

    bool ret = false || cursorHasNext(c);

    destroy(*l);

    return ret;
}

//Testea si un cursor tiene Prev
bool testCursorHasPrev(){
    list<int> * l = empty<int>();
    cons(1, *l);
    snoc(*l, 2);

    Cursor<int> c = cursorLast(*l);

    bool ret = false || cursorHasPrev(c);

    destroy(*l);

    return ret;
}

//Testea la funcion cursorNext
bool testCursorNext(){
    list<int> * l = empty<int>();
    cons(1, *l);
    snoc(*l, 2);

    Cursor<int> c = cursorHead<int>(*l);

    cons(0, *l);

    cursorNext(c);

    bool ret = false || (c.n->value == 2);

    destroy(*l);

    return ret;
}

//Testea la funcion cursorPrev
bool testCursorPrev(){
    list<int> * l = empty<int>();
    cons(2, *l);
    snoc(*l, 3);

    Cursor<int> c = cursorHead<int>(*l);

    cons(1, *l);

    cursorPrev(c);

    bool ret = false || (c.n->value == 1);

    destroy(*l);

    return ret;
}

//Testea el retorno del elemento del nodo apuntado por un cursor
bool testCursorElem(){
    list<int> * l = empty<int>();
    cons(1, *l);
    snoc(*l, 2);

    Cursor<int> c = cursorHead<int>(*l);

    cons(0, *l);

    bool ret = false || (cursorElem(c) == 1);

    destroy(*l);

    return ret;
}

//Testea la actualizacion de un cursor
bool testCursorUpdate(){
    list<int> * l = empty<int>();
    cons(1, *l);
    snoc(*l, 2);

    Cursor<int> c = cursorHead<int>(*l);

    cons(0, *l);

    cursorUpdate(c, 100);

    bool ret = false || (cursorElem(c) == 100);

    destroy(*l);

    return ret;
}

//Testea la eliminacion del nodo de un cursor
bool testCursorRemove(){
    list<int> * l = empty<int>();
    cons(1, *l);
    snoc(*l, 2);

    Cursor<int> c = cursorHead<int>(*l);

    cons(0, *l);

    cursorRemove(c);

    bool ret = false || (c.n == NULL);

    destroy(*l);

    return ret;
}

// *************************************************************
// * TESTS HASH
// *************************************************************

//Testea testea la creacion de una tabla de hash y la funcion isEmptyHash
bool testIsEmptyHash(){
    hashTbl h = emptyHash(10);
    bool ret = false || isEmptyHash(h);
    destroyHash(h);
    return ret;
}

//Testea testea el tamaño de una tabla de hash
bool testLen(){
    hashTbl h = emptyHash(10);
    bool ret = false || (len(h) == 10);
    destroyHash(h);
    return ret;
}

//Testea si una tabla tiene la clave "hola"
bool testHas(){
    hashTbl h = emptyHash(10);
    bool ret = false || has(h, "hola");
    destroyHash(h);
    return !ret;
}

//Testea la funcion add
bool testAdd(){
    hashTbl h = emptyHash(10);

    list<par> * l = empty<par>();
    par p = elem("hola", 1);
    cons(p, *l);

    Cursor<par> c = cursorHead(*l);

    add(h, "hola", c);

    bool ret = false || has(h, "hola");

    destroyHash(h);

    return ret;
}

//Testea la funcion get
bool testGet(){
    hashTbl h = emptyHash(10);

    list<par> * l = empty<par>();
    par p = elem("hola", 1);
    cons(p, *l);

    Cursor<par> c = cursorHead(*l);

    add(h, "hola", c);

    par p2 = elem("p2", 0);
    par p3 = elem("p3", 2);
    cons(p2, *l);
    snoc(*l, p3);

    Cursor<par> res = get(h, "hola");

    bool cond1 = clave(cursorElem(res)) == clave(cursorElem(c));
    bool cond2 = valor(cursorElem(res)) == valor(cursorElem(c));

    bool ret = false || (cond1 && cond2);

    destroyHash(h);
    destroy(*l);

    return ret;
}

//Testea la funcion del
bool testDel(){
    hashTbl h = emptyHash(10);

    list<par> * l = empty<par>();
    par p = elem("hola", 1);
    cons(p, *l);

    Cursor<par> c = cursorHead(*l);

    add(h, "hola", c);

    del(h, "hola");

    bool ret = false || len(*l) == 0;

    destroyHash(h);

    return ret;
}

// *************************************************************
// * TESTS CACHE LRU
// *************************************************************

//Testea la creacion de una cache
bool testIsEmptyLRU(){
    LRUCache lru = empty(10);
    bool ret = false || isEmpty(lru);
    destroy(lru);
    return ret;
}

//Testea el tamaño de la tabla de hash del cache
bool testLenLRU(){
    LRUCache lru = empty(10);
    bool ret = false || len(lru) == 0;
    destroy(lru);
    return ret;
}

//Testea la funcion add
bool testAddLRU(){
    LRUCache lru = empty(10);
    par p = elem("hola", 1);

    add(lru, p);

    bool ret = false || cant(lru) == 1;

    destroy(lru);

    return ret;
}

//Testea la funcion has
bool testHasLRU(){
    LRUCache lru = empty(10);
    par p = elem("hola", 1);

    add(lru, p);

    bool ret = false || has(lru, "hola");

    destroy(lru);

    return ret;
}

//Testea la funcion get
bool testGetLRU(){
    LRUCache lru = empty(10);
    par p = elem("hola", 1);
    par p2 = elem("p2", 2);
    par p3 = elem("p3", 3);

    add(lru, p2);
    add(lru, p);
    add(lru, p3);

    bool a = clave(get(lru, "hola")) == clave(p);

    destroy(lru);

    return a;
}


//-----------------------------------------
void test0(){
    LRUCache lru = empty(5);

    par p0 = elem("p0", 0);
    par p1 = elem("p1", 1);
    par p2 = elem("p2", 2);
    par p3 = elem("p3", 3);
    par p4 = elem("p4", 4);
    par p5 = elem("p5", 5);
    par p6 = elem("p6", 6);
    par p7 = elem("p7", 7);
    par p8 = elem("p8", 8);
    par p9 = elem("p9", 9);

    add(lru, p0);
    add(lru, p1);
    add(lru, p2);
    add(lru, p3);
    add(lru, p4);
    add(lru, p5);
    add(lru, p6);
    add(lru, p7);
    add(lru, p8);
    add(lru, p9);

    cout << lru << endl;
}
//-----------------------------------------
void test1(){
    LRUCache lru = empty(5);

    par p0 = elem("p0", 0);
    par p1 = elem("p1", 1);
    par p2 = elem("p2", 2);
    par p3 = elem("p3", 3);
    par p4 = elem("p4", 4);
    par p5 = elem("p5", 5);
    par p6 = elem("p6", 6);
    par p7 = elem("p7", 7);
    par p8 = elem("p8", 8);
    par p9 = elem("p9", 9);

    cout << "-------------------" << endl;
    add(lru, p0);
    cout << lru << endl;
    cout << "-------------------" << endl;
    add(lru, p1);
    cout << lru << endl;
    cout << "-------------------" << endl;
    add(lru, p2);
    cout << lru << endl;
    cout << "-------------------" << endl;
    add(lru, p3);
    cout << lru << endl;
    cout << "-------------------" << endl;
    add(lru, p4);
    cout << lru << endl;
    cout << "-------------------" << endl;
    add(lru, p5);
    cout << lru << endl;
    cout << "-------------------" << endl;
    add(lru, p6);
    cout << lru << endl;
    cout << "-------------------" << endl;
    add(lru, p7);
    cout << lru << endl;
    cout << "-------------------" << endl;
    add(lru, p8);
    cout << lru << endl;
    cout << "-------------------" << endl;
    add(lru, p9);
    cout << lru << endl;
    cout << "-------------------" << endl;


}
//-----------------------------------------
void test2(){
    LRUCache lru = empty(5);

    par p0 = elem("p0", 0);
    par p1 = elem("p1", 1);
    par p2 = elem("p2", 2);
    par p3 = elem("p3", 3);
    par p4 = elem("p4", 4);
    par p5 = elem("p5", 5);
    par p6 = elem("p6", 6);
    par p7 = elem("p7", 7);
    par p8 = elem("p8", 8);
    par p9 = elem("p9", 9);

    add(lru, p0);
    add(lru, p1);
    cout << lru << endl;
    cout << "Tiene key p1: " << has(lru, "p1") << endl;
    cout << "Tiene key p2: " << has(lru, "p2") << endl;

    cout << "------------------------------" << endl;

    add(lru, p2);
    add(lru, p3);
    add(lru, p4);
    add(lru, p5);
    cout << lru << endl;
    cout << "Tiene key p0: " << has(lru, "p0") << endl;
    cout << "Tiene key p2: " << has(lru, "p2") << endl;

    cout << "------------------------------" << endl;

    add(lru, p6);
    add(lru, p7);
    add(lru, p8);
    add(lru, p9);
    cout << lru << endl;
    cout << "Tiene key p0: " << has(lru, "p0") << endl;
    cout << "Tiene key p1: " << has(lru, "p1") << endl;
    cout << "Tiene key p2: " << has(lru, "p2") << endl;
    cout << "Tiene key p3: " << has(lru, "p3") << endl;
    cout << "Tiene key p4: " << has(lru, "p4") << endl;

    cout << "------------------------------" << endl;

    add(lru, p0);
    cout << lru << endl;
    cout << "Tiene key p0: " << has(lru, "p0") << endl;

    cout << "------------------------------" << endl;

    p0.value = 10;
    add(lru, p0);
    cout << lru << endl;
    cout << "Tiene key p0: " << has(lru, "p0") << endl;
    cout << "Tiene key p8: " << get(lru, "p8") << endl;
    cout << lru << endl;

}


//----------------------------------------------------
int main()
{
    cout.setf(ios::boolalpha);

    cout << "---------------------------------" << endl;

    cout << "TEST PAR" << endl;
    cout << "Test elem  = " << testElem() << endl;
    cout << "Test clave = " << testClave() << endl;
    cout << "Test valor = " << testValor() << endl;

    cout << "---------------------------------" << endl;

    cout << "TEST DLL" << endl;
    cout << "Test Empty   = " << testEmpty() << endl;
    cout << "test Head    = " << testHead() << endl;
    cout << "test Cons    = " << testCons() << endl;
    cout << "test Snoc    = " << testSnoc() << endl;
    cout << "test Tail    = " << testTail() << endl;
    cout << "test Init    = " << testInit() << endl;
    cout << "test Destroy = " << testDestroy() << endl;

    cout << "---------------------------------" << endl;

    cout << "TEST CURSOR" << endl;
    cout << "Test cursorHead    = " << testCursorHead() << endl;
    cout << "Test cursorLast    = " << testCursorLast() << endl;
    cout << "Test cursorHasNext = " << testCursorHasNext() << endl;
    cout << "Test cursorHasPrev = " << testCursorHasPrev() << endl;
    cout << "Test cursorNext    = " << testCursorNext() << endl;
    cout << "Test cursorPrev    = " << testCursorPrev() << endl;
    cout << "Test cursorElem    = " << testCursorElem() << endl;
    cout << "Test cursorUpdate  = " << testCursorUpdate() << endl;
    cout << "Test cursorRemove  = " << testCursorRemove() << endl;

    cout << "---------------------------------" << endl;

    cout << "TESTS HASH" << endl;
    cout << "Test emptyHash = " << testIsEmptyHash() << endl;
    cout << "Test len       = " << testLen() << endl;
    cout << "Test has       = " << testHas() << endl;
    cout << "Test add       = " << testAdd() << endl;
    cout << "Test get       = " << testGet() << endl;
    cout << "Test del       = " << testDel() << endl;

    cout << "---------------------------------" << endl;

    cout << "TEST CACHE LRU" << endl;
    cout << "Test isEmptyLRU = " << testIsEmptyLRU() << endl;
    cout << "Test lenLRU     = " << testLenLRU() << endl;
    cout << "Test addLRU     = " << testAddLRU() << endl;
    cout << "Test hasLRU     = " << testHasLRU() << endl;
    cout << "Test getLRU     = " << testGetLRU() << endl;

    cout << "---------------------------------" << endl;

    //test0();
    //test1();
    //test2();

    return 0;
}
