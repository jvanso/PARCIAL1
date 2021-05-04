/*
 * utn.h
 *
 *  Created on: 25 mar. 2021
 *      Author: Sordello
 */

#ifndef UTN_H_
#define UTN_H_
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int utn_getInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getChar(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);
int getString(char* cadena, int longitud);
int utn_printArray(int *pArray, int limite);
int utn_ordenarArrayInt(int* pArray, int limite);
int getInt(int* pResultado);
//int getFloat(float* pResultado);
int esFlotante(char* cadena);
int getFloat(float* pResultado);
int getSString(char* str,int limite, char* mensaje);
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo,float maximo, int reintentos);
int esNumerica(char* cadena);
int myGets(char* cadena, int longitud);


#endif /* UTN_H_ */
