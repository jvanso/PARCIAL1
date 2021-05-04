/*
 * cliente.c
 *
 *  Created on: 29 abr. 2021
 *      Author: Sordello
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

int cli_initClientes(sCliente* arrayClientes, int limite)
{
	int retorno=-1;
	int i;

	if(arrayClientes != NULL && limite>0)
	{
		for(i=0;i<limite;i++)
		{
			arrayClientes[i].estadoCliente = VACIO;
		}
		retorno=0;
	}
	return retorno;
}
int cli_hardcodeClientes(sCliente* arrayClientes)
{

	int retorno=-1;
	char nombre[1][50]={"Juan"};
	char apellido[1][50]={"Sordello"};
	int cuit[1]={2031};
	int idCliente[1]={3};
	if(arrayClientes!=NULL)
	{
		for(int i=0;i<1;i++)
		{
			strncpy(arrayClientes[i].nombre,nombre[i],sizeof(nombre));
			strncpy(arrayClientes[i].apellido,apellido[i],sizeof(apellido));
			arrayClientes[i].cuit = cuit[i];
			arrayClientes[i].idCliente = idCliente[i];
			arrayClientes[i].estadoCliente = OCUPADO;
		}
		retorno=0;
	}
	return retorno;
}
int cli_buscarLibre(sCliente* arrayClientes, int limite,int* indice)
{
	int retorno=-1;
	int i;
	int index;

	if(arrayClientes != NULL && limite>0 && indice!=NULL)
		{
			retorno=0;
			for(i=0;i<limite;i++)
			{
				if(arrayClientes[i].estadoCliente == VACIO)
				{
					index = i;
					break;
				}
			}
				*indice = index;
		}
	return retorno;
}
int cli_buscarClientePorId(sCliente* arrayClientes, int limite,int* index)
{
	int retorno=-1;
	int indice=-1;
	int id;
	if(arrayClientes != NULL && limite >0 && index != NULL)
	{
		retorno=0;
		fflush(stdin);
		utn_getNumero(&id, "Ingrese id: ", "ID invalido", 0, 100, 2);
		for(int i=0;i<limite;i++)
		{
			if(id==arrayClientes[i].idCliente)
			{
				indice = i;
				//printf("\nINDICEEEE %d\n", indice);
				break;
			}
		}
		*index = indice;
	}
	return retorno;
}
int cli_altaCliente(sCliente* arrayClientes, int limite)
{
	int retorno=-1;
	int lugarLibre;
	char nombre[50];
	char apellido[50];
	if(arrayClientes != NULL && limite>0)
	{
		if(cli_buscarLibre(arrayClientes,limite,&lugarLibre)==0)
		{
			getSString(nombre, 50, "Ingrese nombre: ");
			getSString(apellido, 50, "Ingrese apellido: ");

			strcpy(arrayClientes[lugarLibre].nombre, nombre);
			arrayClientes[lugarLibre].nombre[strlen(arrayClientes[lugarLibre].nombre)-1]='\0';

			strcpy(arrayClientes[lugarLibre].apellido, apellido);
			arrayClientes[lugarLibre].apellido[strlen(arrayClientes[lugarLibre].apellido)-1]='\0';

			utn_getNumero(&arrayClientes[lugarLibre].cuit, "Ingrese cuit del cliente: ", "ERROR CUIT", 0, 200000, 2);
			arrayClientes[lugarLibre].estadoCliente = OCUPADO;
			arrayClientes[lugarLibre].idCliente = cli_idClientes();
			printf("ID DEL CLIENTE: %d\n",arrayClientes[lugarLibre].idCliente);
		}
		retorno =0;
	}

	return retorno;
}
int cli_modificarClientes(sCliente* arrayClientes, int limite)
{
	int retorno = -1;
	int indiceModificar;
	char nombre[50];
	char apellido[50];
	char opcion;
	if(arrayClientes != NULL && limite >0)
	{
		if(cli_buscarClientePorId(arrayClientes,limite,&indiceModificar)==0)
		{
			do
			{
				utn_getChar(&opcion, "a. Nombre\nb.Apellido\nc.Cuit\nd.Salir\nQue desea modificar?", "OPCION INVALIDA\n", 'a', 'd', 2);
				switch(opcion)
				{
				case 'a':
					getSString(nombre, 50, "Ingrese nombre: ");
					strcpy(arrayClientes[indiceModificar].nombre, nombre);
					arrayClientes[indiceModificar].nombre[strlen(arrayClientes[indiceModificar].nombre)-1]='\0';
					break;
				case 'b':
					getSString(apellido, 50, "Ingrese nombre: ");
					strcpy(arrayClientes[indiceModificar].apellido, apellido);
					arrayClientes[indiceModificar].apellido[strlen(arrayClientes[indiceModificar].apellido)-1]='\0';
					break;
				case 'c':
					fflush(stdin);
					utn_getNumero(&arrayClientes[indiceModificar].cuit, "Ingrese cuit: ", "Error cuit", 0, 200000, 2);
					break;
				}
			}while(opcion!='d');
		}
		retorno=0;
	}

	return retorno;
}
int cli_bajaCliente(sCliente* arrayClientes, int limite)
{
	int retorno=-1;
	int indiceBaja;
	if(arrayClientes!= NULL && limite>0)
	{
		if(cli_buscarClientePorId(arrayClientes, limite, &indiceBaja)==0)
		{
			arrayClientes[indiceBaja].estadoCliente = VACIO;
		}
	}
	return retorno;
}
int cli_idClientes()
{
    static int id = 0;
    id++;
    return id;
}
int info_buscarClientePorIdd(sCliente* arrayClientes, int limite, int valorBuscado)
{
	int respuesta = -1;
			int i;
			if(arrayClientes != NULL && limite > 0 && valorBuscado >= 0)
			{
				for(i=0;i<limite;i++)
				{
					if(arrayClientes[i].idCliente == valorBuscado)
					{
						respuesta = i;
						break;
					}
				}
			}
			return respuesta;
}
void cli_mostrarClientes(sCliente* arrayClientes,int limite)
{
	if(arrayClientes != NULL)
	{
		printf("NOMBRE      APELLIDO      CUIT      IDCLIENTE\n");
		for(int i=0;i<limite;i++)
		if(arrayClientes[i].estadoCliente == OCUPADO)
		{
			printf("%s %17s %7d %11d\n",arrayClientes[i].nombre,arrayClientes[i].apellido,arrayClientes[i].cuit,arrayClientes[i].idCliente);
		}
	}
}
