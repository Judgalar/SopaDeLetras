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

        int totalCaracteres=0;  //Total Caracteres sin contar espacios en blanco
        int totalCaracteres_=0; //Total Caracteres contando espacios en blanco

        

    public:

        map<string,int> mapaFichero;

        Analizador();
        Analizador(string);

        void setRutaFichero(string);

        string getRutaFichero();
        int getTotalCaracteres();
        int getTotalCaracteres_();

        void leerTXT_Texto();

        void txtToMap();
        void histograma_H();        //Imprimir histograma horizontal
        void histograma_V();        //Imprimir histograma vertical
        void calcular_longitudMedia();
        string palabraMasUsada();
        string palabraMenosUsada();

        string seleccionarPalabra(auto it);     // selecciona palabra del mapa

};

#endif