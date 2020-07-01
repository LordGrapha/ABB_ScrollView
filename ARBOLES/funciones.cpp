#include <cstdlib>
#include <iostream>
#include "estructuras.h"

using namespace std;

void Arbol::insertar(int dato){
	
    raiz = insertar(dato, raiz);
}

/*
Insertar recursivo
*/
Nodo* Arbol::insertar(int valor, Nodo* nodo){

	/*Cuando el nodo es nulo ahí debe insertar*/      
	if (nodo == NULL){
		return new Nodo(valor);
	}      
	/*Si el dato del nodo a insertar es mayor busca donde insertar
	a la derecha
	*/
	else if (nodo->dato < valor){
		nodo->hijoderecho = insertar(valor, nodo->hijoderecho);
	}
	/*Si el dato del nodo a insertar es menor busca donde insertar
	a la izquierda
	*/
	else if (nodo->dato >= valor){
		nodo->hijoizquierdo = insertar(valor, nodo->hijoizquierdo);
	}

	return nodo;
}


void Arbol::inOrden(Nodo* nodo){
   //izquierda-raíz-derecha
   if (nodo != NULL){
     inOrden(nodo->hijoizquierdo);
     cout << nodo->dato << "  ";
     inOrden(nodo->hijoderecho);
   }
}

void Arbol::preOrden(Nodo* nodo){
	//raíz-izquierda-derecha
   if (nodo != NULL){
     cout << nodo->dato << "  ";
     preOrden(nodo->hijoizquierdo);
     preOrden(nodo->hijoderecho);
   }
}

void Arbol::posOrden(Nodo* nodo){
	//izquierda-derecha-raíz
   if (nodo != NULL){
     posOrden(nodo->hijoizquierdo);
     posOrden(nodo->hijoderecho);
     cout << nodo->dato << "  ";
     
   }
}


int Arbol::contarNodos(Nodo* nodo)
{
     if (nodo == NULL)
        return 0;
     else
         return 1+ contarNodos(nodo->hijoderecho)+contarNodos(nodo->hijoizquierdo);
}       

int  Arbol::contarHojas(Nodo* nodo){
	//contar cantidad de hojas
	if (nodo == NULL) {
		return 0;
	}
	else if(nodo->hijoizquierdo == NULL && nodo->hijoderecho == NULL){
		return 1;
	}
	else{
		return contarHojas(nodo->hijoizquierdo)+contarHojas(nodo->hijoizquierdo);
	}
	
}

int Arbol::obtenerAltura(Nodo* nodo){
	//cantidad de niveles sin contar el 0
	if (nodo == NULL ){
		return -1;
	}
	else{
		return 1+ max(obtenerAltura(nodo->hijoizquierdo),obtenerAltura(nodo->hijoderecho));
	}
	
}
int max(int a, int b){
    if (a>b)
       return a;
    else 
		return b;    
}

bool Arbol::todosPares(Nodo* nodo){
	
	if (nodo == NULL){
		return true;
	}
	else if(nodo->dato%2 == 0){ 
		return todosPares(nodo->hijoizquierdo) and todosPares(nodo->hijoderecho);
	}
	else{
		return false;
	}
}






