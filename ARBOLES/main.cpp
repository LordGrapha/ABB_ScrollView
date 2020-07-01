#include <iostream>
#include "estructuras.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	Arbol* a = new Arbol();
    
	a->insertar(78);
    a->insertar(14);
    a->insertar(82);
    a->insertar(38);
    a->insertar(16);
    a->insertar(14);
    a->insertar(28);
   
    a->inOrden(a->raiz);
    cout<<endl<<"Cant hojas inOrder: "<<a->contarHojas(a->raiz)<<endl;
    
    cout<<endl<<"ObtenerAltura: "<<a->obtenerAltura(a->raiz)<<endl;
    
    cout<<endl<<"Son todos pares? "<<a->todosPares(a->raiz)<<endl;
    
	return 0;
}

