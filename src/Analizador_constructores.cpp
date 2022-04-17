#include <Analizador.hpp>



Analizador::Analizador(){
    getcwd(rutaFichero, 256);
    strcat(rutaFichero,"/texto.txt");       //Establece la ruta al fichero de texto por defecto

    getcwd(rutaSopa, 256);
    strcat(rutaSopa,"/sopa.txt");           //Establece la ruta al fichero de sopa de letras por defecto
}

Analizador::Analizador(string ruta_T,string ruta_S)
{
    for(int i=0;i<ruta_T.length();i++){     //Establece la ruta al fichero de texto indicada
        rutaFichero[i] = ruta_T[i];
    }

    for(int i=0;i<ruta_S.length();i++){     //Establece la ruta al fichero de sopa de letras indicada
        rutaSopa[i] = ruta_S[i];
    }
}

Analizador::Analizador(string ruta_T)
{
    for(int i=0;i<ruta_T.length();i++){     //Establece la ruta al fichero de texto indicada
        rutaFichero[i] = ruta_T[i];
    }
}