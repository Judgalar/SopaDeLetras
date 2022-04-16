#include <Sopa.hpp>
#include <clocale>
#include <unistd.h>
#include <bits/stdc++.h> 


Sopa::Sopa(){
    getcwd(rutaFichero, 256);
    strcat(rutaFichero,"/sopa.txt");
    rellenarSopa();
}

Sopa::Sopa(string ruta)
{
    for(int i=0;i<ruta.length();i++){
        rutaFichero[i] = ruta[i];
    }
    rellenarSopa();

}

string Sopa::getRuta(){
    return rutaFichero;
}

void Sopa::leerFichero(){
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

void Sopa::rellenarSopa(){
    ifstream fichero(rutaFichero);
    string linea;
    string::iterator itLetra;
    string::iterator it;
    int fila=0;
    int columna=0;
    while(getline(fichero, linea))
    {
        fila++;
        for(itLetra=linea.begin() ; itLetra<linea.end() ; itLetra++)
        {
            string palabra;
            char letra = *itLetra;
            while( (letra>=65 && letra<=90) || (letra>=97 && letra<=122) )        //LETRAS PERMITIDAS
            {
                if(letra>=65 && letra<=90) letra=letra+32;  // Convertir letra mayúscula a minúscula
                columna++;
                palabra=palabra+letra;
                itLetra++;
                letra = *itLetra;

                matriz[fila][columna] = palabra;
            }
        }
        columna=0;
    }
    fichero.close();    //cierra fichero
}

void Sopa::imprimirSopa(){
    int x=1;
    int y=1;

    for( y=1 ; y<10 ; y++){
        for( x=1 ; x<10 ; x++){
            if(matriz[y][x] != ""){
                cout<<(matriz[y][x])<<" ";
            }
            else x++;
        }
        cout<<endl;
    }
}


