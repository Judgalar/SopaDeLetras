#include <Analizador.hpp>


Analizador::Analizador(){
    getcwd(rutaFichero, 256);
    strcat(rutaFichero,"/texto.txt");       //Establece la ruta al fichero de texto por defecto
}

Analizador::Analizador(string ruta_T)
{
    for(int i=0;i<=256;i++){     //Establece a 0 el vector
        rutaFichero[i] = 0;
    }

    for(int i=0;i<ruta_T.length();i++){     //Establece la ruta al fichero de texto indicada
        rutaFichero[i] = ruta_T[i];
    }
}

void Analizador::setRutaFichero(string ruta)
{
    for(int i=0;i<=256;i++){     //Resetea la ruta guardada al fichero de texto
        rutaFichero[i] = 0;
    }

    for(int i=0;i<ruta.length();i++){     //Establece la ruta al fichero de texto indicado
        rutaFichero[i] = ruta[i];
    }
}

string Analizador::getRutaFichero(){
    return rutaFichero;
}

int Analizador::getTotalCaracteres(){
    return totalCaracteres;
}

int Analizador::getTotalCaracteres_(){
    return totalCaracteres_;
}

void Analizador::leerTXT_Texto(){
    ifstream fichero(rutaFichero);
    string linea;
    int contador = 0;
    while(getline(fichero, linea))
    {
        contador++;
        cout << "linea " << contador << ": " << linea << endl;
    }
    fichero.close();        //cierra fichero

}

void Analizador::txtToMap(){
    ifstream fichero(rutaFichero);
    string linea;
    string::iterator itLetra;
    string::iterator it;
    while(getline(fichero, linea))
    {
        for(itLetra=linea.begin() ; itLetra<linea.end() ; itLetra++)
        {
            string palabra;
            char letra = *itLetra;
            if (letra != 0) totalCaracteres_++;
            if ( (letra != 0) && (letra != 32) ) totalCaracteres++;
            while( (letra>=65 && letra<=90) || (letra>=97 && letra<=122) )        //LETRAS PERMITIDAS
            {
                if(letra>=65 && letra<=90) letra=letra+32;  // Convertir letra mayúscula a minúscula
                palabra=palabra+letra;
                itLetra++;
                letra = *itLetra;
                if (letra != 0) totalCaracteres_++;
                if ( (letra != 0) && (letra != 32) ) totalCaracteres++;

        
            }
            if(palabra!=""){                                        //AÑADIR PALABRAS Y REPETICIONES AL MAPA
                if(mapaFichero.find(palabra) == mapaFichero.end()){
                     mapaFichero[palabra]=1;
                }
                else{
                    mapaFichero[palabra]++;
                }
            }
        }
    }
    fichero.close();    //cierra fichero
}

void Analizador::histograma_H(){
    auto it = mapaFichero.begin();
    while( it != mapaFichero.end() )
    {
        cout << "[" << it->first << "]";
        for(int i=1 ; i <= it->second ; i++){
            cout<<"#";
        }
        cout<<endl;
        it++;
    }

}

void Analizador::histograma_V()
{   
    int i_A[10]={0,0,0,0,0,0,0,0,0,0};     //Imprimir Almohadillas
    int a_I[10]={0,0,0,0,0,0,0,0,0,0};     //Almohadillas Impresas
    auto it = mapaFichero.begin();
    for(int i=0 ; i<10 ; i++){
        if(it!=mapaFichero.end()){
            cout<<" "<<it->first;
            i_A[i]=it->second;
            it++;
        }
    }
    cout<<endl;

    while( (i_A[1]!=a_I[1]) || (i_A[2]!=a_I[2]) || (i_A[3]!=a_I[3]) || (i_A[4]!=a_I[4]) || (i_A[5]!=a_I[5]) || (i_A[6]!=a_I[6]) || (i_A[7]!=a_I[7])
    || (i_A[8]!=a_I[8])  || (i_A[9]!=a_I[9]) || (i_A[0]!=a_I[0]) )
    {

        it = mapaFichero.begin();
        for(int i=0 ; i<10 ; i++){
            if(it!=mapaFichero.end()){
                string palabra=it->first;
                if(i_A[i]!=a_I[i]){
                    
                    for(auto iter=palabra.begin() ; iter<palabra.end() ; iter++)    cout<<" ";
                    cout<<"#";
                    
                    a_I[i]++;
                }
                else {
                    for(auto iter=palabra.begin() ; iter<palabra.end() ; iter++)    cout<<" ";
                    cout<<" ";
                }
                it++;
            }
        }
        cout<<endl;

    }
}

void Analizador::calcular_longitudMedia(){
    auto it = mapaFichero.begin();
    string palabra;
    float nPalabras=0;
    float size=0;
    float media;

    while( it != mapaFichero.end() )
    {
        palabra = it->first;
        for(auto iter = palabra.begin() ; iter < palabra.end() ; iter++){
            size++;
        }
        it++;
        nPalabras++;
    }
    media = size/nPalabras;
    cout<<"La longitud media de las palabras es de "<<media<<" letras"<<endl;
}

string Analizador::palabraMasUsada()
{
    string resul = mapaFichero.begin()->first;
    int maxRepeticiones = mapaFichero.begin()->second;

    for(auto it = mapaFichero.begin() ; it != mapaFichero.end() ; it++)
    {
        if(it->second > maxRepeticiones){
            maxRepeticiones = it->second;
            resul = it->first;
        }   
    }

    return resul;
}

string Analizador::palabraMenosUsada()
{
    string resul = mapaFichero.begin()->first;
    int maxRepeticiones = mapaFichero.begin()->second;

    for(auto it = mapaFichero.begin() ; it != mapaFichero.end() ; it++)
    {
        if(it->second < maxRepeticiones){
            maxRepeticiones = it->second;
            resul = it->first;
        }   
    }

    return resul;
}

string Analizador::seleccionarPalabra( auto it)     // Devuelve la palabra del mapa
{
    return it->first;
}