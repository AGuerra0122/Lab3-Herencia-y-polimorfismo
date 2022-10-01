/**********************************************************************************************************************
 // FileName:        Lab3 Herencia y Polimorfismo.cpp
 // Program version: Replit
 // Company:         TECNM - ITCH - Departamento Electrica Electronica - Especialidad de sistemas embebidos
 // Description:     Uso de clases, herencias y Polimorfismo para diseñar un ADC de 32 canales, con resolucion de 8, 10 o 12 bits y un rango de entrada de 0 a 3.3v
 // Authors:         Jesus Adrian Guerra Delgado
 // Updated:         09/2022
 //Nota: Version 4
************************************************************************************************************************/
//30-09-2022
#include<stdlib.h>
#include <iostream>
#include "ADC.hpp"
#include "FrecM_3a.hpp"
#include<string>
void portada(void);
/************************************************
    Inicializacion de cuenta
************************************************/
int ADC::n_canales=0;
/************************************************
   MAIN
************************************************/
int main() {
  portada();
  int x=0;
  int cantidad;
  cout<<" Introduzca el numero de canales a configurar:";
  cin>>cantidad;
  FrecM_3a AN[cantidad];
  cout<<endl<<"Se crearon: "<<ADC::getn_canales()<<" objeto(s)";

  for(int i=0;i<cantidad;i++){
    AN[i].captura();
  }
  for(int i=0;i<cantidad;i++){
    AN[i].capVoltaje();
  }
  for(int i=0;i<cantidad;i++){
    AN[i].muestradatos();
  }
  return 0;
}
/***********FUNCION portada********/
void portada(void){
   printf("\t  Tecnologico Nacional de Mexico\n");
   printf("\t INSTITUTO TECNOLOGICO DE CHIHUAHUA\n");
   printf("\tDepartamento Electrica - Electronica\n");
   printf("\t  Especialidad: Sistemas Embebidos\n");
   printf("\tArquitectura de Prog. Para Hardware\n");
   printf("\t   Docente: Alfredo Chacon Aldama \n");
   printf("\t    Jesus Adrian Guerra Delgado\n");
   printf("\t           7mo Semestre\n");   
   printf("\t\tLab3 Herencia y Polimorfismo\n");
   printf("\t\t\tADC de 32 canales\n");
}
