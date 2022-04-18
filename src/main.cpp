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
    SopaDeLetras sopa2("/home/jd/c++/SopaDeLetras/bin/sopa2.txt");

    sopa1.rellenarSopa();
    sopa2.rellenarSopa();

//ANALIZADOR 1 Y SOPA 1
    
    // METODOS ANALIZADOR

    cout<<"HISTOGRAMA HORIZONTAL"<<endl;
    analizador1.histograma_H();
    cout<<endl;
    analizador1.calcular_longitudMedia();
    cout<<"La palabra mas repetida es : "<< analizador1.palabraMasUsada() <<endl;
    cout<<"La palabra menos repetida es : "<< analizador1.palabraMenosUsada() <<endl;
    cout<<"Total de caracteres (sin contar los espacios en blanco) -> "<< analizador1.getTotalCaracteres() <<endl;
    cout<<"Total de caracteres (contando los espacios en blanco) -> "<< analizador1.getTotalCaracteres_() <<endl;
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
    
//ANALIZADOR 2 Y SOPA 2
    
    // METODOS ANALIZADOR

    cout<<"HISTOGRAMA HORIZONTAL"<<endl;
    analizador2.histograma_H();
    cout<<endl;
    analizador2.calcular_longitudMedia();
    cout<<"La palabra mas repetida es : "<< analizador2.palabraMasUsada() <<endl;
    cout<<"La palabra menos repetida es : "<< analizador2.palabraMenosUsada() <<endl;
    cout<<"Total de caracteres (sin contar los espacios en blanco) -> "<< analizador2.getTotalCaracteres() <<endl;
    cout<<"Total de caracteres (contando los espacios en blanco) -> "<< analizador2.getTotalCaracteres_() <<endl;
    cout<<endl;
   
    //  SOPA DE LETRAS
    cout<<"<SOPA DE LETRAS>"<<endl;
    cout<<endl;
    /* IMPRIMIR SOPA SEGMENTATION FAULT */
    for(auto it = analizador2.mapaFichero.begin() ; it != analizador2.mapaFichero.end() ; it++)
    {
        if ( sopa2.buscarPalabra(it->first) ) 
            cout<<"'"<< (it->first) <<"'"<< " esta en la sopa"<<endl;
    }
    /*SOLO IMPRIME a*/

    return 0;
}
