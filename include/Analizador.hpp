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
        string rutaFichero = "/";
        map<string,int> mapa;
    public:
        Analizador();
        Analizador(string);
        void leerFichero(string);

};

#endif