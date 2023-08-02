#include <iostream>
#include <vector>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <math.h>

using namespace std;
	
double DTW(vector<double> X, vector<double> Y, vector<vector<double> > &sol){
	
	for(int i=0; i<sol.size();i++){
		sol[i][0] = 0.0;
	}
	for(int i=0; i<sol[0].size();i++){
		sol[0][i] = 0.0;
	}
	for (int i =1 ; i < sol.size();i++){ //Aqui deveria hast ael final de sol no de Y ya que no hace el ultimo
		for(int j=1; j < sol[i].size();j++){	
			sol[i][j] = fabs(X[i-1]-Y[j-1]) + min(sol[i-1][j-1],min(sol[i-1][j],sol[i][j-1]));

		}
	}
		//cout<<"LA solucion dentro es :"<<sol[X.size()][Y.size()]<<endl;
return sol[X.size()][Y.size()];
}

void MostrarMatriz(vector<vector<double> > m, int inic, int inif, int finc, int finf){
	    for(int i=0; i<finc; i++){
        	for(int j=0; j<finf; j++){
				cout<< m[i][j]<<" ";
       		}
		cout<<endl;		
    	}
}

int main(int argc, char *argv[]){
/* initialize random seed: */
 
 //unsigned long int semilla;
 //semilla= 1234; //atoi(argv[2]);
 
 if (argc <= 1) {
		cerr<<"\nError: El programa se debe ejecutar de la siguiente forma.\n\n";
		cerr<<argv[0]<<"Semilla \n\n";
		return 0;
	}
 	unsigned long int semilla= atoi(argv[1]);
	srand(semilla);
  //srand(time(NULL)); //f
double numerico=0;
int longitudX=0;
int longitudY=0;
int valor;
cout<<"Inserta el numero de datos de vector X : ";
cin>>longitudX;
vector<double> X;
	for(int i=0; i<longitudX;i++){
		valor=rand()%9;
		X.push_back(valor);
	}
cout<<"Inserta el numero de datos de vector Y :v";
cin>>longitudY;
vector<double> Y;
	for(int i=0; i<longitudY;i++){
		valor=rand()%9;
		Y.push_back(valor);
	}

vector<double> vacio(Y.size()+1,-1);
vector<vector<double> > matriz(X.size()+1,vacio);

	cout<<"Cadena x "<<endl;
	for(int i=0; i<X.size();i++){
		cout<< X[i] << " ";
	}
	cout<<endl;
	cout<<"Cadena y "<<endl;
	for(int i=0; i<Y.size();i++){
		cout<< Y[i] << " ";
	}
	cout<<endl;
	cout<<"Matriz antes de: "<<endl;
	for (int i =0 ; i < matriz.size();i++){
		for(int j=0; j < matriz[i].size();j++){
			cout<< matriz[i][j]<< " ";
		}
		cout<<endl;
	}
	
	double solucion = DTW(X,Y,matriz);

	
	cout<<"Matriz despues de: "<<endl;
	MostrarMatriz(matriz,0,0,matriz.size(),matriz[0].size());
	/*for (int i =0 ; i < matriz.size();i++){
		for(int j=0; j < matriz[i].size();j++){
			cout<< matriz[i][j]<< " ";
		}
		cout<<endl;
	}*/
	
	cout<<"La solucion dentro es :"<< solucion << endl;	
	

    return 0;
}

/* 
10.0
6.0
8.0
3.0
5.0
9.0
5.8
6.3
8.4
11.2
14.6
 */
