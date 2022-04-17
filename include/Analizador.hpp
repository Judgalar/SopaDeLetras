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
        char rutaSopa[256];

        int totalCaracteres=0;
        int totalCaracteres_=0;

        map<string,int> mapaFichero;
        map<int,string> mapaSopa;

        int columnasSopa=0;

    public:

        Analizador();
        Analizador(string,string);
        Analizador(string);

        void setRutaFichero(string);
        void setRutaSopa(string);

        string getRutaFichero();
        string getRutaSopa();

        void leerTXT_Texto();
        void leerTXT_Sopa();

        void txtToMap();
        void rellenarSopa();
        void imprimirSopa();
        void histograma_H();
        void histograma_V();
        void calcular_longitudMedia();
        string palabraMasUsada();
        string palabraMenosUsada();

        string seleccionarPalabra(auto it);     // selecciona palabra del mapa
        string seleccionarLetraSopa(int);       // selecciona letra de la sopa
        bool buscarPalabra(string);
        void palabrasEncontradas();

};

#endif