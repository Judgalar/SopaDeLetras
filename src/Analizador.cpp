#include <Analizador.hpp>

#include <unistd.h>
#include <bits/stdc++.h> 


Analizador::Analizador(){
    getcwd(rutaFichero, 256);
    strcat(rutaFichero,"/texto.txt");
}

Analizador::Analizador(string ruta){
    for(int i=0;i<ruta.length();i++){
        rutaFichero[i] = ruta[i];
    }
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
    fichero.close();//cierro fichero

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
            while( (letra>=65 && letra<=90) || (letra>=97 && letra<=122) )        //LETRAS PERMITIDAS
            {
                if(letra>=65 && letra<=90) letra=letra+32;  // Convertir letra mayúscula a minúscula
                palabra=palabra+letra;
                itLetra++;
                letra = *itLetra;
        
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