#ifndef SOPA_H
#define SOPA_H
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <vector>

using namespace std;

class Sopa{
    private:

        char rutaFichero[256];
        string matriz[10][10];

    public:

        Sopa();
        Sopa(string);

        string getRuta();
        void leerFichero();

        void rellenarSopa();
        void imprimirSopa();

};

#endif