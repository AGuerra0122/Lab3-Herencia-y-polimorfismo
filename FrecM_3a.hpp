/**********************************************************************************************************************
 // FileName:        FrecM_3a.hpp
 // Program version: Replit
 // Company:         TECNM - ITCH - Departamento Electrica Electronica - Especialidad de sistemas embebidos
 // Description:     Clase para la frecuencia de muestreo del tipo 3a
 // Authors:         Jesus Adrian Guerra Delgado
 // Updated:         09/2022
 //Nota: Se registra el dato directamente
************************************************************************************************************************/
//30-09-2022
#ifndef FrecM_3a_HPP
#define FrecM_3a_HPP
#include "ADC.hpp"
using namespace std;
#include<iostream>
/************************************************
*                 CLASE
************************************************/
class FrecM_3a: public ADC{
  private:

  public:
    FrecM_3a(int, char, float, int, float, int);
    FrecM_3a();

    void muestradatos();
};
#endif