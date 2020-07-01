#include <cstdlib>
#include <iostream>

using namespace std;

struct Nodo{
	
	int dato;
	Nodo* hijoizquierdo;
	Nodo* hijoderecho;
	
	Nodo (int _dato){
	    dato = _dato;
	    hijoizquierdo = hijoderecho = NULL;     
	} 
	      
};

struct Arbol{
	Nodo* raiz;
	
	Arbol (){
	    raiz = NULL;      
	}
	
	void insertar (int);
	Nodo* insertar(int, Nodo*);
	void inOrden(Nodo*);
	void preOrden(Nodo*);
	void posOrden(Nodo*);
	int contarHojas(Nodo*);
	int contarNodos(Nodo*);
	int obtenerAltura(Nodo*);
	bool todosPares(Nodo*);
};

