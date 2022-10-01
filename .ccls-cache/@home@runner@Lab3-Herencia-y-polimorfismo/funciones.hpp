/**********************************************************************************************************************
 // FileName:        funciones.hpp
 // Program version: Replit
 // Company:         TECNM - ITCH - Departamento Electrica Electronica - Especialidad de sistemas embebidos
 // Description:     Funciones para imprimir la portada y limpiar el buffer
 // Authors:         Jesus Adrian Guerra Delgado
 // Updated:         09/2022
 //Nota: portada()   claenBuffIn()
************************************************************************************************************************/
//30-09-2022
#ifndef funciones_HPP
#define funciones_HPP
#include<iostream>
#include<stdlib.h>
using namespace std;
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
   printf("\t\t\tLab3 Herencia y Polimorfismo\n");
   printf("\tClasificador de microcontroladores\n");
}
/***********FUNCION cleanBuffIn********/
void cleanBuffIn(void){     /*FUNCION PARA LIMPIAR EL BUFFER DE ENTRADA EN SUSTITUCION DE fflush(stdin)*/
   int ch;
   while ((ch = fgetc(stdin)) != EOF)  /* Brinca o descarta todos los caracteres de stdin, */
   {                                   /* hasta que se encuentra con EOF, llegado al final del buffer.*/
     if( ch == '\n' ) break;           /* o si encuentra un salto de linea */
   }
}


#endif
