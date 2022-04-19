#ifndef SOPADELETRAS_H
#define SOPADELETRAS_H

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <unistd.h>
#include <bits/stdc++.h> 

using namespace std;


class SopaDeLetras{
    private:

        char rutaSopa[256];
        map<int,string> mapaSopa;

        int filas=0;
        int columnas=0;
    
    public:

        SopaDeLetras();
        SopaDeLetras(string);

        void setRutaSopa(string);

        string getRutaSopa();
        int getFilas();
        int getColumnas();

        void leerTXT_Sopa();

        void rellenarSopa();
        void imprimirSopa();

        char seleccionarLetra(int);       // selecciona letra de la sopa

        bool esta_fuera(int fila,int columna);  //Comprueba si la posición está fuera de la matriz
        bool buscarPalabra(string);

};

#endif