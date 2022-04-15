#ifndef ANALIZADOR_H
#define ANALIZADOR_H
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>

using namespace std;


class Analizador{
    private:

        char rutaFichero[256];
        map<string,int> mapa;

    public:

        Analizador();
        Analizador(string);

        string getRuta();
        void leerFichero();

        void txtToMap();


};

#endif