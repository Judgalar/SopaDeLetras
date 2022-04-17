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

   
    //  SOPA DE LETRAS

    sopa1.imprimirSopa();

    int fil = sopa1.getFilas();
    int col = sopa1.getColumnas();

    string sopa[fil][col];

    int id=1;
    for(int i=0 ; i<fil ; i++){
        for(int j= 0 ; j<col ; j++)
        {
            sopa[i][j]= sopa1.seleccionarLetra(id);
            id++;
        }
    }

    int a;
    cin>>a;
    


    return 0;
}
