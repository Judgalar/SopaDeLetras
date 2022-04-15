#include <Analizador.hpp>

using namespace std;

int main()
{
    Analizador analizador;                                  // texto predeterminado: bin/texto.txt
    Analizador analizador2("/home/jd/Escritorio/isra");

    analizador.txtToMap();

    return 0;
}
