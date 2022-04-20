#include <Analizador.hpp>
#include <SopaDeLetras.hpp>

using namespace std;

int main()
{
    //  CONSTRUCTORES

    Analizador analizador1;                                  // texto predeterminado: bin/texto.txt

    Analizador analizador2("/home/jd/C++/SopaDeLetras/bin/texto2.txt");     // ¡¡¡ESCRIBIR TU RUTA AL FICHERO QUE QUIERES ANALIZAR!!!!!!!!

    Analizador analizador3("/home/jd/C++/SopaDeLetras/bin/texto3.txt");     // ¡¡¡ESCRIBIR TU RUTA AL FICHERO QUE QUIERES ANALIZAR!!!!!!!!

    analizador1.txtToMap();
    analizador2.txtToMap();
    analizador3.txtToMap();

    SopaDeLetras sopa1;                 // texto predeterminado: bin/sopa.txt

    SopaDeLetras sopa2("/home/jd/C++/SopaDeLetras/bin/sopa2.txt");      // ¡¡¡ESCRIBIR TU RUTA AL FICHERO QUE QUIERES ANALIZAR!!!!!!!!

    SopaDeLetras sopa3("/home/jd/C++/SopaDeLetras/bin/sopa3.txt");      // ¡¡¡ESCRIBIR TU RUTA AL FICHERO QUE QUIERES ANALIZAR!!!!!!!!

    sopa1.rellenarSopa();
    sopa2.rellenarSopa();
    sopa3.rellenarSopa();

 //ANALIZADOR 1 Y SOPA 1
 cout<<"---FICHERO DE TEXTO 1---"<<endl<<endl;
    
    // METODOS ANALIZADOR

    cout<<"HISTOGRAMA HORIZONTAL"<<endl;
    analizador1.histograma_H();
    cout<<endl;
    cout<<"HISTOGRAMA VERTICAL"<<endl;
    analizador1.histograma_V();
    cout<<endl;
    analizador1.calcular_longitudMedia();
    cout<<"La palabra mas repetida es : "<< analizador1.palabraMasUsada() <<endl;
    cout<<"La palabra menos repetida es : "<< analizador1.palabraMenosUsada() <<endl;
    cout<<"Total de caracteres (sin contar los espacios en blanco) -> "<< analizador1.getTotalCaracteres() <<endl;
    cout<<"Total de caracteres (contando los espacios en blanco) -> "<< analizador1.getTotalCaracteres_() <<endl;
    cout<<endl;
   
    //  SOPA DE LETRAS
    cout<<"<SOPA DE LETRAS 1>"<<endl;
    sopa1.imprimirSopa();
    cout<<endl;

    for(auto it = analizador1.mapaFichero.begin() ; it != analizador1.mapaFichero.end() ; it++)
    {
        if ( sopa1.buscarPalabra(it->first) == true ) 
            cout<<"'"<< (it->first) <<"'"<< " esta en la sopa"<<endl;
    }

    cout<<endl<<endl<<endl;
    
 //ANALIZADOR 2 Y SOPA 2
  cout<<"---FICHERO DE TEXTO 2---"<<endl<<endl;

    
    // METODOS ANALIZADOR

    cout<<"HISTOGRAMA HORIZONTAL"<<endl;
    analizador2.histograma_H();
    cout<<endl;
    cout<<"HISTOGRAMA VERTICAL"<<endl;
    analizador2.histograma_V();
    cout<<endl;
    analizador2.calcular_longitudMedia();
    cout<<"La palabra mas repetida es : "<< analizador2.palabraMasUsada() <<endl;
    cout<<"La palabra menos repetida es : "<< analizador2.palabraMenosUsada() <<endl;
    cout<<"Total de caracteres (sin contar los espacios en blanco) -> "<< analizador2.getTotalCaracteres() <<endl;
    cout<<"Total de caracteres (contando los espacios en blanco) -> "<< analizador2.getTotalCaracteres_() <<endl;
    cout<<endl;
   
    //  SOPA DE LETRAS
    cout<<"<SOPA DE LETRAS 2>"<<endl;
    sopa2.imprimirSopa();
    cout<<endl;

    for(auto it = analizador2.mapaFichero.begin() ; it != analizador2.mapaFichero.end() ; it++)     
    {
        if ( sopa2.buscarPalabra(it->first) ) 
            cout<<"'"<< (it->first) <<"'"<< " esta en la sopa"<<endl;
    }

    cout<<endl<<endl;

 //ANALIZADOR 3 Y SOPA 3
  cout<<"---FICHERO DE TEXTO 3---"<<endl<<endl;

    
    // METODOS ANALIZADOR

    cout<<"HISTOGRAMA HORIZONTAL"<<endl;
    analizador3.histograma_H();
    cout<<endl;
    cout<<"HISTOGRAMA VERTICAL"<<endl;
    analizador3.histograma_V();
    cout<<endl;
    analizador3.calcular_longitudMedia();
    cout<<"La palabra mas repetida es : "<< analizador3.palabraMasUsada() <<endl;
    cout<<"La palabra menos repetida es : "<< analizador3.palabraMenosUsada() <<endl;
    cout<<"Total de caracteres (sin contar los espacios en blanco) -> "<< analizador3.getTotalCaracteres() <<endl;
    cout<<"Total de caracteres (contando los espacios en blanco) -> "<< analizador3.getTotalCaracteres_() <<endl;
    cout<<endl;
   
    //  SOPA DE LETRAS
    cout<<"<SOPA DE LETRAS 3>"<<endl;
    sopa3.imprimirSopa();
    cout<<endl;

    for(auto it = analizador3.mapaFichero.begin() ; it != analizador3.mapaFichero.end() ; it++)     
    {
        if ( sopa3.buscarPalabra(it->first) ) 
            cout<<"'"<< (it->first) <<"'"<< " esta en la sopa"<<endl;
    }

    cout<<endl<<endl;



    return 0;
}
