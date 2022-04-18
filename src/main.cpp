#include <Analizador.hpp>
#include <SopaDeLetras.hpp>

using namespace std;

int main()
{
    //  CONSTRUCTORES

    Analizador analizador1;                                  // texto predeterminado: bin/texto.txt
    Analizador analizador2("/home/jd/c++/SopaDeLetras/bin/texto2.txt");

    analizador1.txtToMap();
    analizador2.txtToMap();

    SopaDeLetras sopa1;

    sopa1.rellenarSopa();

    
    // METODOS ANALIZADOR

    cout<<"HISTOGRAMA HORIZONTAL"<<endl;
    analizador1.histograma_H();
    cout<<endl;
    analizador1.calcular_longitudMedia();
    cout<<"La palabra mas repetida es : "<< analizador1.palabraMasUsada() <<endl;
    cout<<"La palabra menos repetida es : "<< analizador1.palabraMenosUsada() <<endl;
    cout<<endl;
   
    //  SOPA DE LETRAS
    cout<<"<SOPA DE LETRAS>"<<endl;
    sopa1.imprimirSopa();
    cout<<endl;

    for(auto it = analizador1.mapaFichero.begin() ; it != analizador1.mapaFichero.end() ; it++)
    {
        if ( sopa1.buscarPalabra(it->first) ) 
            cout<<"'"<< (it->first) <<"'"<< " esta en la sopa"<<endl;
    }
    

    int a;
    cin>>a;
    


    return 0;
}
