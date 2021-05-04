/*
 * compra.c
 *
 *  Created on: 29 abr. 2021
 *      Author: Sordello
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compra.h"
#include "cliente-compra.h"

int com_initCompras(sCompra* arrayCompras, int limite)
{
	int retorno=-1;
	int i;
	if(arrayCompras != NULL && limite>0)
	{
		for(i=0;i<limite;i++)
			{
				arrayCompras[i].estadoCompra = ADEUDA;
			}
		retorno=0;
	}
	return retorno;
}
int com_hardcodeCompras(sCompra* arrayCompras)
{
	int retorno=-1;
		char direccion[1][50]={"Ayolas"};
		char color[1][50]={"AZULYORO"};
		int cantBarbijos[1]={53};
		int idCliente[1]={3};
		int idCompra[1]={100};
		float importe[1]={20.30};
		if(arrayCompras!=NULL)
		{
			for(int i=0;i<1;i++)
			{
				strncpy(arrayCompras[i].direccion,direccion[i],sizeof(direccion));
				strncpy(arrayCompras[i].color,color[i],sizeof(color));
				arrayCompras[i].cantBarbijos = cantBarbijos[i];
				arrayCompras[i].idCliente = idCliente[i];
				arrayCompras[i].idCompra = idCompra[i];
				arrayCompras[i].importe = importe[i];
				arrayCompras[i].estadoCompra = PAGADO;

			}
			retorno=0;
		}
		return retorno;
}
int com_buscarLibre(sCompra* arrayCompras, int limite, int* indice)
{
	int retorno=-1;
	int i;
	int index;
		{
		retorno=0;
		for(i=0;i<limite;i++)
		{
				if(arrayCompras[i].estadoCompra == ADEUDA)
				{
					index = i;
					break;
				}
			}
					*indice = index;
		}
				return retorno;
}
int com_idCompras()
{
	    static int id = 100;
	    id++;
	    return id;
}
int com_altaCompra(sCompra* arrayCompras, int limite, sCliente* arrayClientes, int limiteClientes)
{
	int retorno=-1;
	int indiceLibre;
	int idCliente;
	char direccion[50];
	char color[50];
	if(arrayCompras != NULL && limite>0 && arrayClientes != NULL && limiteClientes>0)
	{
		com_buscarLibre(arrayCompras, limite, &indiceLibre);
			if(indiceLibre >= 0)
			{
					cli_mostrarClientes(arrayClientes, limiteClientes);
					fflush(stdin);

					if(utn_getNumero(&idCliente, "Ingrese ID cliente: ", "Error ID",0, CLIENTES, 2)!=-1 && info_buscarClientePorId(arrayClientes, limite, idCliente) != -1)
					{
						arrayCompras[indiceLibre].idCliente = idCliente;
					}
					else
					{
						printf("ID INVALIDO!\n");
					}


					printf("IDCLIENTEEEE : %d\n", arrayCompras[indiceLibre].idCliente);
					getSString(direccion, 50, "Ingrese direccion: ");
					getSString(color, 50, "Ingrese color: ");

					strcpy(arrayCompras[indiceLibre].direccion, direccion);
					arrayCompras[indiceLibre].direccion[strlen(arrayCompras[indiceLibre].direccion)-1]='\0';

					strcpy(arrayCompras[indiceLibre].color, color);
					arrayCompras[indiceLibre].color[strlen(arrayCompras[indiceLibre].color)-1]='\0';

					utn_getNumero(&arrayCompras[indiceLibre].cantBarbijos, "Ingrese cantidad de barbijos: ", "ERROR CANTIDAD BARBIJOS", 0, 100, 2);
					arrayCompras[indiceLibre].idCompra = com_idCompras();



					printf("ID DE LA COMPRA: %d\n",arrayCompras[indiceLibre].idCompra);
					retorno=0;
			}

		}
	return retorno;
}
int com_buscarCompraPorId(sCompra* arrayCompras, int limite, int* index)
{
	int retorno=-1;
	int id;
	int indice;
	if(arrayCompras != NULL && limite>0 && index != NULL)
	{
		fflush(stdin);
		if(utn_getNumero(&id, "Ingrese ID de la compra: ", "ERROR ID COMPRA", 100, COMPRAS, 2)==0)
		{
			for(int i=0;i<limite;i++)
			{
				if(arrayCompras[i].idCompra == id)
				{
					indice = i;
					break;
				}
			}
		}
		*index = indice;
		retorno=0;
	}
	return retorno;
}
int com_contarYMostrarComprasPendientes(sCompra* arrayCompras, int limite)
{
	int retorno=-1;
	int contadorComprasPendientes=0;
	if(arrayCompras != NULL && limite>0)
	{
		for(int i=0;i<limite;i++)
		{
			if(arrayCompras[i].estadoCompra==ADEUDA)
			{
				contadorComprasPendientes++;
			}
		}
		printf("Cantidad de compras pendientes: %d\n", contadorComprasPendientes);
		retorno=0;
	}
	return retorno;
}
void com_mostrarCompras(sCompra* arrayCompras,int limite)
{
	if(arrayCompras != NULL)
	{
		printf("DIRECCION      COLOR      CANTBARBIJOS      IMPORTE      IDCLIENTE      IDCOMPRA\n");
		for(int i=0;i<limite;i++)
		if(arrayCompras[i].estadoCompra == PAGADO)
		{
			printf("%s %14s %7d %18.2f %11d %11d\n",arrayCompras[i].direccion,arrayCompras[i].color,arrayCompras[i].cantBarbijos,arrayCompras[i].importe,arrayCompras[i].idCliente,arrayCompras[i].idCompra);
		}
	}
}
