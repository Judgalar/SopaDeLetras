#ifndef ANALIZADOR_H
#define ANALIZADOR_H

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <unistd.h>
#include <bits/stdc++.h> 

using namespace std;


class Analizador{
    private:

        char rutaFichero[256];

        int totalCaracteres=0;
        int totalCaracteres_=0;

        map<string,int> mapaFichero;

    public:

        Analizador();
        Analizador(string);

        void setRutaFichero(string);

        string getRutaFichero();

        void leerTXT_Texto();

        void txtToMap();
        void histograma_H();
        void histograma_V();
        void calcular_longitudMedia();
        string palabraMasUsada();
        string palabraMenosUsada();

        string seleccionarPalabra(auto it);     // selecciona palabra del mapa

};

#endif