/**********************************************************************************************************************
 // FileName:        FrecM_3a.cpp
 // Program version: Replit
 // Company:         TECNM - ITCH - Departamento Electrica Electronica - Especialidad de sistemas embebidos
 // Description:     Implementacion de la clase FrecM_3a
 // Authors:         Jesus Adrian Guerra Delgado
 // Updated:         09/2022
 //Nota: Implementacion de los miembros, metodos y constructores
************************************************************************************************************************/
//30-09-2022
#include<stdlib.h>
#include<iostream>
#include "FrecM_3a.hpp"
using namespace std;
void cleanBuffIn(void);
/************************************************
*                  CONSTRUCTOR 
************************************************/
FrecM_3a::FrecM_3a(int Resolucion, char opcion, float frec_m, int canal, float voltaje, int digital):  ADC(Resolucion, opcion, frec_m, canal, voltaje, digital) {}

FrecM_3a::FrecM_3a():ADC(){}

void FrecM_3a::captura(){
  int y=0; 
  ADC::captura();
  cout<<" Opciones para la Frecuencia de muestreo"<<endl;  
  cout<<"   Opcion 1) Frecuencia de muestreo especifica"<<endl;
  cout<<"   Opcion 2) Frecuencia de muestreo estantar de 125KHz a 4MHz"<<endl;
  cout<<" Escoje una opcion: ";
  while(y==0 || (_opcion!=1 && _opcion!=2)){
    cleanBuffIn();
    y=scanf("%d",&_opcion);
    if(y==0){
      cout<<" Error, la entrada es incorrecta"<<endl;
      cout<<" Introduzca la opcion otra vez (1 o 2): ";
    }
    if(y==1 && (_opcion!=1 && _opcion!=2)){
      cout<<" Error, opcion invalida"<<endl;
      cout<<" Introduzca la opcion otra vez (1 o 2): ";
    }
  }
  if(_opcion==1){
    ADC::opcion1();
  }
  if(_opcion==2){
    ADC::opcion2();
  }  
}

void FrecM_3a::muestradatos(){
  ADC::muestradatos();
  cout<<" Frecuencia de muestreo: "<<_frec_m<<"Hz"<<endl;
  cout<<" Lectura: "<<_voltaje<<"v"<<endl;
  cout<<" Valor Digital: "<<_digital<<endl;
}
