/**********************************************************************************************************************
 // FileName:        ADC.cpp
 // Program version: Replit
 // Company:         TECNM - ITCH - Departamento Electrica Electronica - Especialidad de sistemas embebidos
 // Description:     Implementacion de la clase ADC
 // Authors:         Jesus Adrian Guerra Delgado
 // Updated:         09/2022
 //Nota: Implementacion de los miembros, metodos y constructores
************************************************************************************************************************/
//30-09-2022
#include<stdlib.h>
#include<iostream>
#include "ADC.hpp"
using namespace std;
void cleanBuffIn(void);

/************************************************
*                  CONSTRUCTOR 
************************************************/
ADC::ADC(int Resolucion, int opcion, float frec_m, int canal, float voltaje, int digital){
  _Resolucion=Resolucion;
  _opcion=opcion;
  if(opcion==1){
    _frec_m=frec_m;
  }
  if(opcion==2){
    _frec_m=8000000/frec_m;
  }
  _canal=canal;
  _voltaje=voltaje;
  _digital=digital;
  n_canales++;
  _num=n_canales;
  cout<<"Se ha creado un objeto ADC numero:"<<_num<<endl;
}
ADC::ADC(){
  _Resolucion=0;
  _opcion=1;
  _frec_m=0;
  _canal=0;
  _voltaje=0;
  _digital=0;
  n_canales++;
  _num=n_canales;
  cout<<"Se ha creado un objeto ADC numero:"<<_num<<endl;  
}
/************************************************
    METODOS
************************************************/
void ADC::muestradatos(){
  cout<<endl<<"** Imprimiendo Datos **"<<endl;
  cout<<" Canal: AN"<<_canal<<endl;
  cout<<" Resolucion: "<<_Resolucion<<endl;
  cout<<" Opcion: "<<_opcion<<endl;
}
void ADC::captura(){
  int x=0,y=0,z=0,w=0;
  float frec_m;
  cout<<endl<<"** Introduce Datos **"<<endl;
  cout<<" Elemento:"<<_num<<endl;
  cout<<" Dame la resolucion (8, 10 o 12 bits): ";
  while(x==0 || (_Resolucion!=8 && _Resolucion!=10 && _Resolucion!=12)){
    cleanBuffIn();
    x=scanf("%d",&_Resolucion);      
    if(x==0){
      cout<<" Error, la entrada es incorrecta"<<endl;
      cout<<" Introduzca la resolucion otra vez (8, 10 0 12 bits): ";
    }
    if(x==1 && (_Resolucion!=8 && _Resolucion!=10 && _Resolucion!=12)){
      cout<<" Error, resolucion no soportada"<<endl;
      cout<<" Introduzca la resolucion otra vez (8, 10, 12 bits): ";
    }
  } 
  cout<<" Dame el No. de canal (1-32): ";
  while(z==0 || _canal<1 || _canal>32){
    cleanBuffIn();
    z=scanf("%d",&_canal);
    if(z==0){
      cout<<" Error, la entrada es incorrecta"<<endl;
      cout<<" Introduzca el No de canal otra vez (1-32): ";
    }
    if(z==1 && (_canal<1 || _canal>32)){
      cout<<" Error, resolucion no soportada"<<endl;
      cout<<" Introduzca el No de canal otra vez (1-32): ";
    }
  }  
}
/************************************************
*   			GETTERS
************************************************/
int ADC::getdigital(){
  return _digital;
} 
int ADC::getn_canales(){
  return n_canales;
}
/************************************************
*   			SETERS
************************************************/
void ADC::capVoltaje(){
  int x=0;
  cout<<"** Introduciendo lectura **"<<endl;
  cout<<" Dame la Lectura del canal AN"<<_canal<<"(0v a 3.3v): ";
  while(x==0 || _voltaje<0 || _voltaje>3.3){
    cleanBuffIn();
    x=scanf("%f",&_voltaje);
    if(x==0){
      cout<<" Error, la entrada es incorrecta"<<endl;
      cout<<" Introduzca la lectura otra vez (0v a 3.3v): ";
    }
    if(x==1 && (_voltaje<0 || _voltaje>3.3)){
      cout<<" Error, resolucion no soportada"<<endl;
      cout<<" Introduzca la lectura otra vez (0v a 3.3v): ";
    }
  } 
  if(_Resolucion==8){
    _digital=_voltaje*255/3.3;
  }
  if(_Resolucion==10){
    _digital=_voltaje*1023/3.3;
  }
  if(_Resolucion==12){
    _digital=_voltaje*4095/3.3;
  }
  
}
void ADC::opcion1(){
  cout<<" Opcion 1) Frecuencia de muestreo especifica seleccionada"<<endl;
  cout<<" Dame la Frecuencia de muestreo (Hz): ";
  cin>>_frec_m;
}
void ADC::opcion2(){
  int w=0;
  float frec_m;
  cout<<" Opcion 2) Frecuencia de muestreo estandar de 125KHz a 4MHz seleccionada"<<endl;
  cout<<" Factores para la frecuencia de muestreo"<<endl;
  cout<<"  2 para 4MHz"<<endl;
  cout<<"  4 para 2MHz"<<endl;
  cout<<"  8 para 1MHz"<<endl;
  cout<<"  16 para 500KHz"<<endl;
  cout<<"  32 para 250KHz"<<endl;
  cout<<"  64 para 125KHz"<<endl;
  cout<<" Escoje el factor de division: ";
  while(w==0 || (frec_m!=2 && frec_m!=4 && frec_m!=8 && frec_m!=16 && frec_m!=32 && frec_m!=64)){
    cleanBuffIn();
    w=scanf("%f",&frec_m);
    if(w==0){
      cout<<" Error, la entrada es incorrecta"<<endl;
      cout<<" Introduzca el factor otra vez (2, 4, 8, 16 o 32): ";
    }
    if(w==1 && (frec_m!=2 && frec_m!=4 && frec_m!=8 && frec_m!=16 && frec_m!=32 && frec_m!=64)){
      cout<<" Error, factor invalido"<<endl;
      cout<<" Introduzca el factor otra vez (2, 4, 8, 16 o 32): ";
    }
  }
  _frec_m=8000000/frec_m;
}
/***********FUNCION cleanBuffIn********/
void cleanBuffIn(void){     /*FUNCION PARA LIMPIAR EL BUFFER DE ENTRADA EN SUSTITUCION DE fflush(stdin)*/
   int ch;
   while ((ch = fgetc(stdin)) != EOF)  /* Brinca o descarta todos los caracteres de stdin, */
   {                                   /* hasta que se encuentra con EOF, llegado al final del buffer.*/
     if( ch == '\n' ) break;           /* o si encuentra un salto de linea */
   }
}