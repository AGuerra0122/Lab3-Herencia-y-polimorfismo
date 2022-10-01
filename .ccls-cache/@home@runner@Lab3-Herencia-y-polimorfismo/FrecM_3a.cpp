/**********************************************************************************************************************
 // FileName:        ADC.hpp
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

void FrecM_3a::muestradatos(){
  ADC::muestradatos();
  cout<<" Frecuencia de muestreo: "<<_frec_m<<"Hz"<<endl;
  cout<<" Lectura: "<<_voltaje<<"v"<<endl;
  cout<<" Valor Digital: "<<_digital<<endl;
}
