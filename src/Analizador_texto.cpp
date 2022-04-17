#include <Analizador.hpp>


void Analizador::setRutaFichero(string ruta)
{
    for(int i=0;i<=256;i++){     //Resetea la ruta guardada al fichero de texto
        rutaFichero[i] = 0;
    }

    for(int i=0;i<ruta.length();i++){     //Establece la ruta al fichero de texto indicado
        rutaFichero[i] = ruta[i];
    }
}
string Analizador::getRutaFichero(){
    return rutaFichero;
}

void Analizador::leerTXT_Texto(){
    ifstream fichero(rutaFichero);
    string linea;
    int contador = 0;
    while(getline(fichero, linea))
    {
        contador++;
        cout << "linea " << contador << ": " << linea << endl;
    }
    fichero.close();        //cierra fichero

}

void Analizador::txtToMap(){
    ifstream fichero(rutaFichero);
    string linea;
    string::iterator itLetra;
    string::iterator it;
    while(getline(fichero, linea))
    {
        for(itLetra=linea.begin() ; itLetra<linea.end() ; itLetra++)
        {
            string palabra;
            char letra = *itLetra;
            if (letra != 0) totalCaracteres_++;
            if ( (letra != 0) && (letra != 32) ) totalCaracteres++;
            while( (letra>=65 && letra<=90) || (letra>=97 && letra<=122) )        //LETRAS PERMITIDAS
            {
                if(letra>=65 && letra<=90) letra=letra+32;  // Convertir letra mayúscula a minúscula
                palabra=palabra+letra;
                itLetra++;
                letra = *itLetra;
                if (letra != 0) totalCaracteres_++;
                if ( (letra != 0) && (letra != 32) ) totalCaracteres++;

        
            }
            if(palabra!=""){                                        //AÑADIR PALABRAS Y REPETICIONES AL MAPA
                if(mapaFichero.find(palabra) == mapaFichero.end()){
                     mapaFichero[palabra]=1;
                }
                else{
                    mapaFichero[palabra]++;
                }
            }
        }
    }
    fichero.close();    //cierra fichero
}

void Analizador::histograma_H(){
    auto it = mapaFichero.begin();
    while( it != mapaFichero.end() )
    {
        cout << "[" << it->first << "]";
        for(int i=0 ; i < it->second ; i++){
            cout<<"#";
        }
        cout<<endl;
        it++;
    }

}

void Analizador::histograma_V(){

}

void Analizador::calcular_longitudMedia(){
    auto it = mapaFichero.begin();
    string palabra;
    float nPalabras=0;
    float size=0;
    float media;

    while( it != mapaFichero.end() )
    {
        palabra = it->first;
        for(auto iter = palabra.begin() ; iter < palabra.end() ; iter++){
            size++;
        }
        it++;
        nPalabras++;
    }
    media = size/nPalabras;
    cout<<"La longitud media de las palabras es de "<<media<<" letras"<<endl;
}

string Analizador::palabraMasUsada()
{
    string resul = mapaFichero.begin()->first;
    int maxRepeticiones = mapaFichero.begin()->second;

    for(auto it = mapaFichero.begin() ; it != mapaFichero.end() ; it++)
    {
        if(it->second > maxRepeticiones){
            maxRepeticiones = it->second;
            resul = it->first;
        }   
    }

    return resul;
}

string Analizador::palabraMenosUsada()
{
    string resul = mapaFichero.begin()->first;
    int maxRepeticiones = mapaFichero.begin()->second;

    for(auto it = mapaFichero.begin() ; it != mapaFichero.end() ; it++)
    {
        if(it->second < maxRepeticiones){
            maxRepeticiones = it->second;
            resul = it->first;
        }   
    }

    return resul;
}