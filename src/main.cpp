#include <Analizador.hpp>

using namespace std;

int main()
{
    Analizador analizador;                                  // texto predeterminado: bin/texto.txt
    Analizador analizador2("/home/jd/c++/SopaDeLetras/bin/texto2.txt");

    analizador.txtToMap();
    analizador2.txtToMap();

    cout<<"HISTOGRAMA HORIZONTAL"<<endl;
    analizador.histograma_H();
    cout<<endl;
    analizador.calcular_longitudMedia();
    cout<<"La palabra mas repetida es : "<< analizador.palabraMasUsada() <<endl;
    cout<<"La palabra menos repetida es : "<< analizador.palabraMenosUsada() <<endl;
   
    
    analizador.rellenarSopa();
    analizador.imprimirSopa();
    
    analizador.palabrasEncontradas();


    return 0;
}
