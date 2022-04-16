#include <Analizador.hpp>

using namespace std;

int main()
{
    Analizador analizador;                                  // texto predeterminado: bin/texto.txt
    Analizador analizador2("/home/jd/c++/SopaDeLetras/bin/texto2.txt");

    analizador.txtToMap();

    cout<<"HISTOGRAMA HORIZONTAL"<<endl<<endl;
    analizador.histograma_H();
    analizador.calcular_longitudMedia();
    cout<<"La palabra mas repetida es "<< analizador.palabraMasUsada() <<endl;
    cout<<"La palabra menos repetida es "<< analizador.palabraMenosUsada() <<endl;
   
    return 0;
}
