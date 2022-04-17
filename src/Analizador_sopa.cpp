#include <Analizador.hpp>


void Analizador::setRutaSopa(string ruta)
{
    for(int i=0;i<=256;i++){     //Resetea la ruta guardada fichero de sopa de letras
        rutaSopa[i] = 0;
    }

    for(int i=0;i<ruta.length();i++){     //Establece la ruta al fichero de sopa de letras indicado
        rutaSopa[i] = ruta[i];
    }
}

string Analizador::getRutaSopa(){
    return rutaSopa;
}

void Analizador::leerTXT_Sopa(){
    ifstream fichero(rutaSopa);
    string linea;
    int contador = 0;
    while(getline(fichero, linea))
    {
        contador++;
        cout << "linea " << contador << ": " << linea << endl;
    }
    fichero.close();        //cierra fichero

}

void Analizador::rellenarSopa(){
    ifstream fichero(rutaSopa);
    string linea;
    string::iterator itLetra;
    int nLinea=0;
    int nLetra=0;
    while(getline(fichero, linea))
    {
        nLinea++;
        for(itLetra=linea.begin() ; itLetra<linea.end() ; itLetra++)
        {
            string palabra;
            char letra = *itLetra;
            while( (letra>=65 && letra<=90) || (letra>=97 && letra<=122) )        //LETRAS PERMITIDAS
            {
                if(letra>=65 && letra<=90) letra=letra+32;  // Convertir letra mayúscula a minúscula
                palabra=palabra+letra;
                itLetra++;
                letra = *itLetra;
                if(nLinea==1) columnasSopa++;
            }

            if(palabra!="")
            {
                nLetra++;
                mapaSopa[nLetra]=palabra;
            }
        }
    }
    fichero.close();    //cierra fichero
}

void Analizador::imprimirSopa()
{
    for(auto it = mapaSopa.begin() ; it!=mapaSopa.end() ; ){
        for(int x=0 ; x<columnasSopa ; x++){
            cout << "[" << it->second << "]";
            it++;
        }
        cout<<endl;

    }
}

// METODOS PARA BUSCAR EN LA SOPA DE LETRAS

string Analizador::seleccionarPalabra( auto it)     // Devuelve la palabra del mapa
{
    return it->first;
}

string Analizador::seleccionarLetraSopa(int id)     // Devuelve la letra de la sopa
{
    if( mapaSopa.find(id) != mapaSopa.end() ){
        return ( mapaSopa.find(id) )-> second;
    }
}

bool Analizador::buscarPalabra(string palabra)      // Busca la palabra en la sopa
{
    bool encontrada=false;
    string elemento;
    int id=1;
    for(auto itLetra = palabra.begin() ; itLetra != palabra.end() ; itLetra++)
    {
        string letra="";
        letra = letra + *itLetra;
        string palabro = palabro + letra;
        elemento = seleccionarLetraSopa(id);
        while( letra != elemento){
            id++;
            elemento = seleccionarLetraSopa(id);
            if(elemento == "") break;
        }
    }

    return encontrada;
}

void Analizador::palabrasEncontradas()      //Imprime las palabras encontradas
{
    string palabra;
    for(auto it = mapaFichero.begin(); it != mapaFichero.end() ; it++)
    {
        palabra=seleccionarPalabra(it);
        if( buscarPalabra(palabra) )
            cout<<"["<<palabra<<"]"<<" esta en la sopa"<<endl;
    }
    
}