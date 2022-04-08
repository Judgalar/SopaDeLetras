#include <Analizador.hpp>

#include <unistd.h>
#include <bits/stdc++.h> 


Analizador::Analizador(){
    getcwd(rutaFichero, 256);
    strcat(rutaFichero,"/texto.txt");
}

Analizador::Analizador(char ruta){

}

void Analizador::getRuta(){
    return rutaFichero;
}
void Analizador::leerFichero(string){

}