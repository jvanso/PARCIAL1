/*
 * utn.c
 *
 *  Created on: 13 abr. 2021
 *      Author: Sordello
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int utn_getInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
		int retorno=-1;
		int bufferInt;
		if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo<=maximo && reintentos>=0)
		{
			retorno = -2;
			do
			{
				printf("%s", mensaje);
				fflush(stdin);
				scanf("%d", &bufferInt);
				if(bufferInt >= minimo && bufferInt <= maximo)
				{
					retorno=0;
					*pResultado = bufferInt;
					break;
				}
				printf("%s", mensajeError);
				reintentos--;
			}while(reintentos>=0);
		}
		return retorno;
}
int utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno=-1;
	float bufferFloat;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo<=maximo && reintentos>=0)
	{
		retorno = -2;
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%f", &bufferFloat);
			if(bufferFloat >= minimo && bufferFloat <= maximo)
			{
				retorno=0;
				*pResultado = bufferFloat;
				break;
			}
			printf("%s", mensajeError);
			reintentos--;
		}while(reintentos>=0);
	}



	return retorno;
}
int utn_getChar(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
{
	int retorno=-1;
	char bufferChar;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo<=maximo && reintentos>=0)
	{
		retorno = -2;
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%c", &bufferChar);
			if(bufferChar >= minimo && bufferChar <= maximo)
			{
				retorno=0;
				*pResultado = bufferChar;
				break;
			}
			printf("%s", mensajeError);
			reintentos--;
		}while(reintentos>=0);
	}



	return retorno;
}

int utn_getString(char* pTexto, char* mensaje, char* mensajeError,int limite,int reintentos)
{
	int retorno=-1;
	char bufferString[5000];
	char limiteString[50001];
	if(pTexto != NULL && mensaje != NULL && mensajeError != NULL && reintentos>=0)
	{
		retorno = -2;
		do
		{
			printf("%s", mensaje);
			fgets(bufferString,50,stdin);
			if(bufferString<=limiteString)
			{
				retorno=0;
				strncpy(pTexto,bufferString,sizeof(bufferString));
				break;
			}
			printf("%s", mensajeError);
			reintentos--;
		}while(reintentos>=0);
	}



	return retorno;
}

int utn_printArray(int *pArray, int limite)
{
	int retorno=-1;
	int i;
	if(pArray != NULL && limite>=0)
	{
		retorno=0;
		for(i=0;i<limite;i++)
		{
			printf("Indice: %d   --   VALOR: %d\n",i,pArray[i]);
		}
	}
	return retorno;
}
int utn_ordenarArrayInt(int* pArray, int limite)
{
	int i;
	int retorno=0;
	int flagSwap;
	int contador;
	int nuevoLimite;
	int buffer;
	if(pArray != NULL && limite >= 0)
	{
		nuevoLimite=limite-1;
		do
		{
			flagSwap=0;
			for(i=0;i<nuevoLimite;i++)
			{
				contador++;
				if(pArray[i]<pArray[i+1])
				{
					flagSwap=1;
					buffer = pArray[i];
					pArray[i]= pArray[i+1];
					pArray[i+1]=buffer;
				}
			}
			nuevoLimite--;
		}while(flagSwap);
		retorno = contador;
	}
return retorno;
}
int esNumerica(char* cadena)
{
	int i=0;
	int retorno = 1;
	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if(cadena[i] < '0' || cadena[i] > '9' )
			{
				retorno = 0;
				break;
			}
	i++;
	}
}
return retorno;
}
int myGets(char* cadena, int longitud)
{
	if(cadena != NULL && longitud >0 && fgets(cadena,longitud,stdin)==cadena)
	{
		fflush(stdin); // LINUX-> __fpurge o WIN-> fflush o MAC-> fpurge
		if(cadena[strlen(cadena)-1] == '\n')
		{
			cadena[strlen(cadena)-1] = '\0';
		}
			return 0;
	}
	return -1;
}
int getInt(int* pResultado)
{
	int retorno=-1;
	char buffer[64];
	if(pResultado != NULL)
	{
		if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer))
		{

			*pResultado = atoi(buffer);
			retorno = 0;
		}

	}
	return retorno;
}
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int
maximo, int reintentos)
{
	int bufferInt;
	int retorno = -1;
	while(reintentos>0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getInt(&bufferInt) == 0)
		{
			if(bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
		}
		printf("%s",mensajeError);
}
	return retorno;
}
int getString(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[4096]; // *****************************

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		//__fpurge(stdin); // Linux
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}
int esFlotante(char* cadena)
{
	int i=0;
	int retorno = 1;
	int contadorPuntos=0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		for(i=0 ; cadena[i] != '\0'; i++)
		{
			if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9' )
			{
				if(cadena[i] == '.' && contadorPuntos == 0)
				{
					contadorPuntos++;
				}
				else
				{
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}
int getFloat(float* pResultado)
{
    int retorno=-1;
    char buffer[64];

    if(pResultado != NULL)
    {
    	if(getString(buffer,sizeof(buffer))==0 && esFlotante(buffer))
    	{
			*pResultado = atof(buffer);
			retorno = 0;
		}
    }
    return retorno;
}
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	float bufferFloat;
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getFloat(&bufferFloat) == 0)
		{
			if(bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

int getSString(char* str,int limite, char* mensaje)
{
	int retorno = -1;
	if(mensaje != NULL && str != NULL && limite>0){
		printf("%s",mensaje);
		fflush(stdin);
		fgets(str,limite,stdin);
		retorno =0;
	}
	return retorno;

}


