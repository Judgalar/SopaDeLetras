#include <Analizador.hpp>

#include <unistd.h>
#include <bits/stdc++.h> 


Analizador::Analizador(){
    getcwd(rutaFichero, 256);
    strcat(rutaFichero,"/texto.txt");
    txtToMap();
}

Analizador::Analizador(string ruta)
{
    for(int i=0;i<ruta.length();i++){
        rutaFichero[i] = ruta[i];
    }
    txtToMap();
}

string Analizador::getRuta(){
    return rutaFichero;
}

void Analizador::leerFichero(){
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
                if(mapa.find(palabra) == mapa.end()){
                     mapa[palabra]=1;
                }
                else{
                    mapa[palabra]++;
                }
            }
        }
    }
    fichero.close();    //cierra fichero
}

void Analizador::histograma_H(){
    auto it = mapa.begin();
    while( it != mapa.end() )
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
    auto it = mapa.begin();
    string palabra;
    float nPalabras=0;
    float size=0;
    float media;

    while( it != mapa.end() )
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
    string resul = mapa.begin()->first;
    int maxRepeticiones = mapa.begin()->second;

    for(auto it = mapa.begin() ; it != mapa.end() ; it++)
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
    string resul = mapa.begin()->first;
    int maxRepeticiones = mapa.begin()->second;

    for(auto it = mapa.begin() ; it != mapa.end() ; it++)
    {
        if(it->second < maxRepeticiones){
            maxRepeticiones = it->second;
            resul = it->first;
        }   
    }

    return resul;
}