#include <Analizador.hpp>
#include <Sopa.hpp>

using namespace std;

int main()
{
    Analizador analizador;                                  // texto predeterminado: bin/texto.txt
    Analizador analizador2("/home/jd/c++/SopaDeLetras/bin/texto2.txt");


    cout<<"HISTOGRAMA HORIZONTAL"<<endl;
    analizador.histograma_H();
    cout<<endl;
    analizador.calcular_longitudMedia();
    cout<<"La palabra mas repetida es : "<< analizador.palabraMasUsada() <<endl;
    cout<<"La palabra menos repetida es : "<< analizador.palabraMenosUsada() <<endl;
   
    Sopa sopa;

    cout<<endl;
    cout<<"SOPA DE LETRAS"<<endl;
    sopa.imprimirSopa();





    return 0;
}
