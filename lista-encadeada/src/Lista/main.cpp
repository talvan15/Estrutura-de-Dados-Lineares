#include <iostream>
#include "no.h"
#include "lista.h"
using namespace std;

int main(){
    Lista minhaLista;
    minhaLista.inserirInicio(10);
    minhaLista.inserirInicio(20);
    minhaLista.inserirInicio(10);
    minhaLista.inserirInicio(10);
    minhaLista.inserirInicio(20);


    minhaLista.inserirFim(5);
    minhaLista.inserirFim(1);
    cout << "Lista antes de remover duplicados: ";
    minhaLista.mostrar();
    cout << endl;
    minhaLista.removerDuplicados();
    
    minhaLista.mostrar();    
    cout << endl;

    return 0;
}