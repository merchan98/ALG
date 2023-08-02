#include <iostream>
#include <cmath>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <limits>

using namespace std;

const int MAXPALABRAS = 100;
const int MAXLINEAS = MAXPALABRAS;  //En el peor caso es una palabra por linea

struct registro{
    int primera, ultima;
    double espacio, coste;

}

int Parrafo(int l, int n, int b, vector<int> longPalabras, vector<registro> solucion){
    /* L es la longitud de la linea, n el numero de palabras, 
    b el tamano optimo de los espacios, 
    l es el vector con las longitudes de las n palabras, 
    y en sol almacena la solucion. 
    Devuelve el numero de lineas que ha necesitado */
    int tamanoPalabra; // long de palabras de la linea
    int tamanoLinea; // tamaño de la linea en curso
    int nLinea; // Linea en curso
    int nPalabra; // palabra en curso
    int nEspacio; // numero de espacios linea en curso

    nLinea=1;
    ResetContadores(nlinea,1, solucion, longPalabras, tamanoPalabra, tamanoLinea, nEspacio); //Metemos la primera palabra
    nPalabra =2;
    while(nPalabra <= n){
        if(tamanoLinea+b+longPalabras[nPalabra] <= l){ //Cabe
            tamanoLinea =+ (b+longPalabras[nPalabra]);
            tamanoPalabra =+ longPalabras[nPalabra];
            nEspacio++;
        }else{ //No cabe de forma optima
            if((tamanoPalabra+longPalabras[nPalabra]+nEspacio+1) > L){
                //no cabe asi qeu la pasamos a otra linea
                CerrarLinea(nLiena, nPalabra);
                nLinea++; //Reiniciamos contadores, osea, añadimos otra linea
                ResetContadores(nLinea, nPalabra, solucion, longPalabras, tamanoPalabra, tamanoLinea, nEspacio);
            }else{ // Puede que quepa si movemos los espacios
                if(Coste(l, b, tamanoPalabra, nEspacio) >= Coste(l, b, tamanoPalabra+longPalabras[nPalabra], nEspacios+1)){
                    nPalabra++; //Cabe y es mejor que lo anterior, asi que la metemos
                }
                //No cabe la pasamos a otra linea
                CerrarLinea(nLinea, nPalabra);
                nLinea++;
                ResetContadores(nLinea, nPalabra, solucion, longPalabras, tamanoPalabra, tamanoLinea, nEspacio );
            }
        }
        nPalabra++;
    }
    if(solucion[nLinea].primera == 0){
        return nLinea-1
    }
    if(solucion[nLinea].ultima == 0){
        CerrarLinea(nLinea, nPalabra, solucion, tamanoPalabra, nEspacio, l, b);
    }
    return nLinea;
}

double Espacio(int l, int tamanoPalabra, int nesp){
    /* devuelve cero si nesp = 0, o bien un numero mayor que 1 */
    if(nesp==0){
        return 0.0;
    }
    return (l-tamanoPalabra)/(nesp);
}

void ResetContadores(int linea ,int npal, vector<registro> &solucion, vector<int> longPalabras, int tamanoPalabra, int tamanoLinea, int nEspacio ){
    if(npal <= longPalabra.size() ){ //Para que la ultima palabra no lo haga nada
        solucion[linea].primera =npal;
        solucion[linea].coste=0.0;
        tamanoPalabra = longPalabras[npal];
        tamanoLinea = longPalabras[npal];
        nEspacio=0;
    }
}

double Coste(int l, int b, int tampalabras, int nesp){
    double bprima= Espacio(l,tampalabras, nesp):
    if(bprima > b){
        return (nesp*(bprima-b))
    }else{
        return (nesp*(b -bprima))
    }
}

void CerrarLinea(int linea, int npal, vector<registro> &solucion, int tamanoPalabra, int nEspacio, int l, int b ){
    solucion[linea].ultima= npal-1;
    solucion[linea].espacio = Espacio(l, tamanoPalabra, nEspacio)
    solucion[linea].coste = Coste(l, b, tamanoPalabras, nEspacio);
}
