#include <iostream>
#include <fstream>
#include <cmath>
#include "stdio.h"

using namespace std;

void crear(float** psi, float tmax, float T, float ro, float L, float deltax, float deltat, int Nx, int Nt);

template <class T>
void escribe(string archivo, T** datospsi, int pasosx, int pasost){
  ofstream outfile;
  //abre el archivo.
  outfile.open(archivo);

  for (int i=0; i < pasost; i++){
    for (int j=0; j < pasosx; j++){
      outfile << datospsi[i][j] << "\t";
    }
    outfile << endl;
  }
  //cierra el archivo.
  outfile.close(); 
}


int main(){
    float tmax = 0.1;
    int T = 40;
    float ro = 0.01;
    float L = 1.0;
    float deltax = 1.0/100;
    float deltat = 0.1/10;
    int Nx = L/deltax;
    int Nt = tmax/deltat;

    float **psi = new float*[Nt];
    
    crear(psi,tmax,T,ro,L,deltax,deltat,Nx,Nt);
    
    escribe("datos.txt", psi, Nx, Nt);

    delete* psi;
    return 0;
}

void crear(float** psi, float tmax, float T, float ro, float L, float deltax, float deltat, int Nx, int Nt){
    
    float c = T/ro;
    float cp = deltax/deltat;
    for(int j = 0; j < Nt; j++){
        psi[j] = new float[Nx];
        float x = 0;
        for(int i = 0; i< Nx; i++){
            if(j==0 || i==0 || x == L){
                psi[j][i] = 1e-4 * sin(2*M_PI*x/L);
            }
            else if(j==1){
                psi[j][i] = psi[j-1][i] + c*c/(2*cp*cp) * (psi[j-1][i+1] + psi[j-1][i-1] - 2* psi[j-1][i]);
            }
            else{
                psi[j][i] = 2*psi[j-1][i] - psi[j-2][i] + pow(c,2)/pow(cp,2) * ( psi[j-1][i+1] + psi[j-1][i-1] - 2*psi[j-1][i]);
            }
            x+=deltax;
        }
    }
}