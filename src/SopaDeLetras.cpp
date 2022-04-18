#include <SopaDeLetras.hpp>


SopaDeLetras::SopaDeLetras(){
    getcwd(rutaSopa, 256);
    strcat(rutaSopa,"/sopa.txt");           //Establece la ruta al fichero de sopa de letras por defecto
}

SopaDeLetras::SopaDeLetras(string ruta_S)
{
    for(int i=0;i<ruta_S.length();i++){     //Establece la ruta al fichero de texto indicada
        rutaSopa[i] = ruta_S[i];
    }
}

void SopaDeLetras::setRutaSopa(string ruta)
{
    for(int i=0;i<=256;i++){     //Resetea la ruta guardada fichero de sopa de letras
        rutaSopa[i] = 0;
    }

    for(int i=0;i<ruta.length();i++){     //Establece la ruta al fichero de sopa de letras indicado
        rutaSopa[i] = ruta[i];
    }
}

string SopaDeLetras::getRutaSopa(){
    return rutaSopa;
}

int SopaDeLetras::getFilas(){
    return filas;
}

int SopaDeLetras::getColumnas(){
    return columnas;
}

void SopaDeLetras::leerTXT_Sopa(){
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

void SopaDeLetras::rellenarSopa(){
    ifstream fichero(rutaSopa);
    string linea;
    string::iterator itLetra;
    int nLinea=0;
    int nLetra=0;
    while(getline(fichero, linea))
    {
        nLinea++;
        filas++;
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
                if(nLinea==1) columnas++;
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

void SopaDeLetras::imprimirSopa()
{
    for(auto it = mapaSopa.begin() ; it!=mapaSopa.end() ; ){
        for(int x=0 ; x<columnas ; x++){
            cout << "[" << it->second << "]";
            it++;
        }
        cout<<endl;

    }
}

char SopaDeLetras::seleccionarLetra(int id)     // Devuelve la letra de la sopa
{
    char resul;
    string letra;
    if( mapaSopa.find(id) != mapaSopa.end() ){
        letra = ( mapaSopa.find(id) )-> second;
        resul= letra[1];
    }
    else resul = 0;
    return resul;
}

void SopaDeLetras::buscarPalabra(string palabra)
{
    int maxFila = getFilas();
    int maxCol = getColumnas();
    int direcFil;
    int direcCol;
    iterator<string,int> it;
    
    string palabra;

    char sopa[maxFila][maxCol];

    int id=1;
    for(int i=0 ; i<maxFila ; i++){                                 //RELLENA MATRIZ CON EL MAPA SOPA
        for(int j= 0 ; j<maxCol ; j++)
        {
            sopa[i][j] = seleccionarLetra(id);
            id++;
        }
    }

    //PSEUDOCODE TO C++

    for( int f=0 ; f<=maxFila ; f++){
        for( int c=0 ; c<=maxCol ; c++){
            
            if(palabra[0]==sopa[f][c]){

                for( int direccion = 0; direccion<8 ; direccion++)
                {
                    switch(direccion)
                    {
                        case 0: //Derecha---->
                            direcFil=0;
                            direcCol=1;
                            break;
                        case 1: //Diagonal Abajo Derecha-->
                            direcFil=1;
                            direcCol=1;
                            break;
                        case 2: //Abajo
                            direcFil=1;
                            direcCol=0;
                            break;
                        case 3: //Diagonal Abajo Izquierda<--
                            direcFil=1;
                            direcCol=-1;
                            break;
                        case 4: //Izquierda <--
                            direcFil=0;
                            direcCol=-1;
                            break;
                        case 5: //Diagonal Izquierda Arriba<--
                            direcFil=-1;
                            direcCol=-1;
                            break;
                        case 6: //Arriba
                            direcFil=-1;
                            direcCol=0;
                            break;
                        case 7: //Diagonal Derecha Arriba-->
                            direcFil=-1;
                            direcCol=1;
                            break;
                    }

                    bool seguir=true;
                    int fila=f;
                    int col=c;
               //     for(int l=1 ; l < palabra.end())
                }
            }
        }

    }






}







