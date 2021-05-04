/*
 * cliente-compra.c
 *
 *  Created on: 29 abr. 2021
 *      Author: Sordello
 */
#include "cliente-compra.h"
#include <string.h>

void mostrarComprasConSusClientes(sCompra* arrayCompras, int limiteCompras,sCliente* arrayClientes, int limiteClientes)
{
	int i;
	int j;
	if(arrayCompras != NULL && limiteCompras>0 && arrayClientes != NULL && limiteClientes>0)
	{
		for(i=0;i<limiteCompras;i++)
		{
			for(j=0;j<limiteClientes;j++)
			{
				if(arrayCompras[i].idCliente == arrayClientes[j].idCliente && arrayCompras[i].estadoCompra==PAGADO && arrayClientes[j].estadoCliente == OCUPADO)
				{
					printf("%s %14s %7d %7s %8s %9d %11.2f\n", arrayClientes[j].nombre,arrayClientes[j].apellido,arrayClientes[j].cuit,arrayCompras[i].direccion,arrayCompras[i].color,arrayCompras[i].cantBarbijos,
							arrayCompras[i].importe);
					break;
				}
			}
		}
	}
}
void mostrarComprasConSusClientes2(sCompra* arrayCompras, int limiteCompras, sCliente* arrayClientes, int limiteClientes, int id)
{
	int i;
		int j;
		if(arrayCompras != NULL && limiteCompras>0 && arrayClientes != NULL && limiteClientes>0)
		{
			for(i=0;i<limiteCompras;i++)
			{
				for(j=0;j<limiteClientes;j++)
				{
					if(arrayCompras[i].estadoCompra==ADEUDA && arrayClientes[j].estadoCliente == OCUPADO && arrayCompras[i].idCompra==id)
					{
						printf("%s %14s %7d %7s %8s %9d %11.2f\n", arrayClientes[j].nombre,arrayClientes[j].apellido,arrayClientes[j].cuit,arrayCompras[i].direccion,arrayCompras[i].color,arrayCompras[i].cantBarbijos,
								arrayCompras[i].importe);
						break;
					}
				}
			}
		}
}
int com_pagarCompra(sCompra* arrayCompras, int limite, sCliente* arrayClientes, int limiteClientes)
{
	int retorno=-1;
	int indiceCompra;
	//char color[50];
	//int indice;
	char opcion;
	if(arrayCompras != NULL && limite>0 && arrayClientes != NULL && limiteClientes>0)
	{
		retorno=0;
		if(com_buscarCompraPorId(arrayCompras, limite, &indiceCompra)==0)
		{
			//info_imprimirClientesConCompras(arrayCompras, limite, arrayClientes, limiteClientes, );
			//mostrarComprasConSusClientes2(arrayCompras, limite, arrayClientes, limiteClientes, arrayCompras[indiceCompra].idCliente);
			//printf("ID CLIENTE: %d - NOMBRE: %s - APELLIDO: %s - CUIT: %d\n", arrayClientes[indice].idCliente,arrayClientes[indice].nombre,arrayClientes[indice].apellido,arrayClientes[indice].cuit);
			if(arrayCompras[indiceCompra].estadoCompra == ADEUDA)
			{
				if(utn_getNumeroFlotante(&arrayCompras[indiceCompra].importe, "Ingrese importe: ", "ERROR", 0, 300, 2)==0)
				{
						do
						{
							utn_getChar(&opcion, "a.Confirmar compra\nb.Cancelar compra\nc.Salir\nIngrese opcion: ", "ERROR OPCION", 'a', 'c', 2);
							switch(opcion)
							{
							case 'a':
								arrayCompras[indiceCompra].estadoCompra = PAGADO;
								break;
							case 'b':
								arrayCompras[indiceCompra].estadoCompra = ADEUDA;
								break;
							}
						}while(opcion != 'c');
					}
			}
		}
		else
		{
			printf("ID INVALIDO\n");
		}
	}
	return retorno;
}
int info_buscarClientePorIdCompra(sCompra*  arrayCompras, int limite, int valorBuscado)
{
	int respuesta = -1;
			int i;
			if(arrayCompras != NULL && limite > 0 && valorBuscado >= 0)
			{
				for(i=0;i<limite;i++)
				{
					if(arrayCompras[i].idCompra == valorBuscado)
					{
						respuesta = arrayCompras[i].idCliente;
						break;
					}
				}
			}
			return respuesta;
}
int com_bajaCompra(sCompra* arrayCompras, int limite, sCliente* arrayClientes, int limiteClientes)
{
	int retorno=-1;
	char opcion;
	int indiceBaja;
	if(arrayCompras != NULL && limite>0)
	{
		//info
		if(com_buscarCompraPorId(arrayCompras, limite, &indiceBaja)==0)
		{
			do
			{
				utn_getChar(&opcion, "a.Confirmar baja de compra\nb.Cancelar baja de compra\nc.Salir\nIngrese opcion: ", "ERROR OPCION", 'a', 'c', 2);
				switch(opcion)
				{
				case 'a':
					arrayCompras[indiceBaja].estadoCompra = ADEUDA;
					break;
				case 'b':
					arrayCompras[indiceBaja].estadoCompra = PAGADO;
					break;
				}
			}while(opcion != 'c');
		}
		retorno=0;
	}
	return retorno;
}
int info_buscarClientePorId(sCliente* arrayClientes, int limite, int valorBuscado)
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
#define CANTIDAD_COLORES 1000
int info_imprimirComprasConImportePorCliente(sCompra* arrayCompras,int limiteCompras,sCliente* arrayClientes,int limiteClientes)
{

	int retorno = -1;
	char listaColores[CANTIDAD_COLORES][50];
	int i;
	int j;
	int flagExisteColor;
	int indiceColorLibre = 0;
	float auxiliarDeuda;
	float deudaMinima=0;
	int indiceClienteDeudaMinima;

	for(i=0;i<limiteCompras;i++)
	{
		flagExisteColor = 0;
		if(arrayCompras[i].estadoCompra == PAGADO)
		{
			for(j=0;j<indiceColorLibre;j++)
			{
				if(strncmp(arrayCompras[i].color,listaColores[j],CANTIDAD_COLORES) == 0)
				{
					flagExisteColor = 1;

					break;
				}
			}
			if(flagExisteColor == 0)
			{
				strncpy(listaColores[indiceColorLibre],arrayCompras[i].color,CANTIDAD_COLORES);
				indiceColorLibre++;
			}
		}
	}
		{
			info_calcularPagoCliente(arrayCompras,limiteCompras,arrayClientes,limiteClientes,listaColores[j], &auxiliarDeuda);
			if(j == 0|| (auxiliarDeuda < deudaMinima))
			{
				deudaMinima = auxiliarDeuda;
				indiceClienteDeudaMinima = 	j;
			}

		}
		printf("La compra con precio por unidad mas bajo es el color %s - total: %.2f\n",listaColores[indiceClienteDeudaMinima],deudaMinima);
	return retorno;
}
int info_calcularPagoCliente(sCompra* arrayCompras,int limite,sCliente* arrayClientes,int limiteClientes,char* colorBarbijo, float* deuda)
{
	int retorno = -1;
	int i;
	int indiceArrayCliente;
	int idCliente;
	float auxiliarDeuda=0;
	if(arrayCompras != NULL && limite > 0 && arrayClientes != NULL && limiteClientes > 0 && colorBarbijo != NULL)
	{
		for(i=0;i<limite;i++)
		{
			if(arrayCompras[i].estadoCompra == ADEUDA)
			{
				continue;
			}
			if(strncmp(arrayCompras[i].color,colorBarbijo,CANTIDAD_COLORES)==0)
			{
				idCliente = arrayClientes[i].idCliente;
				indiceArrayCliente = info_buscarClientePorId(arrayClientes,limiteClientes,idCliente);
				auxiliarDeuda = auxiliarDeuda + (arrayCompras[i].importe / arrayCompras[indiceArrayCliente].cantBarbijos);
			}
		}
		retorno = 0;
		*deuda=auxiliarDeuda;
	}
	return retorno;
}
/*
int info_imprimirClientesConCompras(sCompra* arrayCompras,int limite,sCliente* arrayClientes,int limiteClientes,char* colorBarbijo)
{
	int retorno = -1;
	int i;
	int indiceArrayCliente;
	if(arrayCompras != NULL && limite > 0 && arrayClientes != NULL && limiteClientes > 0 && colorBarbijo != NULL)
	{
		for(i=0;i<limite;i++)
		{
			if(arrayCompras[i].estadoCompra == PAGADO && strncmp(arrayCompras[i].color,colorBarbijo,50) == 0)
			{
				retorno = 0;
				if(cli_buscarClientePorId(arrayClientes, limite, &indiceArrayCliente)==0)
				{
				printf("\nID: %d - Direccion: %s - Color: %s - Cantidad Barbijos: %d - Importe: %.2f - IdCliente: %d",
						arrayCompras[i].idCompra,arrayCompras[i].direccion,arrayCompras[i].color,arrayCompras[i].cantBarbijos,arrayCompras[i].importe,arrayCompras[i].idCliente);
				printf(" - %s - %s - %d",arrayClientes[indiceArrayCliente].nombre,arrayClientes[indiceArrayCliente].apellido,arrayClientes[indiceArrayCliente].cuit);
				}
			}
		}
	}
	return retorno;
}
int info_imprimirContratacionesConImporte(sCompra* arrayCompras,int limite,sCliente* arrayClientes,int limiteClientes,char* colorBarbijo)
{
	int retorno = -1;
	int i;
	float auxiliarImporte;
	if(arrayCompras != NULL && limite > 0 && arrayClientes != NULL && limiteClientes > 0 && colorBarbijo != NULL)
	{
		for(i=0;i<limite;i++)
		{
			if(arrayCompras[i].estadoCompra == PAGADO)
			{
				continue;
			}
			if(strncmp(arrayCompras[i].color,colorBarbijo,50) == 0)
			{
				retorno = 0;
				auxiliarImporte = arrayCompras[i].importe;
				printf("\nID: %d - Direccion: %s - Color: %s - Importe: %.2f - IdCliente: %d"
															,arrayCompras[i].idCompra
															,arrayCompras[i].direccion
															,arrayCompras[i].color
															,auxiliarImporte
															,arrayCompras[i].idCliente
															);
			}
		}
	}
	return retorno;
}
*/
int info_contadorColorMasRepetido(sCompra* arrayCompras, int limiteCompra, sColores* arrayColores, int limiteColores)
{
	int i;
	int j;
	int retorno = -1;

	if(arrayCompras != NULL && limiteCompra > 0)
	{
		for(i=0; i<limiteCompra; i++)
		{
			if(arrayCompras[i].estadoCompra == PAGADO)
			{
				for(j=0; j<limiteColores; j++)
				{
					if(strncmp(arrayColores[j].color, arrayCompras[i].color, CANTIDAD_COLORES) == 0)
					{
						(arrayColores[j].cantColorMasRepetido)++;
					}
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}
int info_colorMasRepetido(sColores* arrayColores, int limiteColores)
{
	int i;
	int retorno = -1;
	int cantMax;
	int indiceMaximo;

	if(arrayColores != NULL && limiteColores > 0)
	{
		cantMax = arrayColores[0].cantColorMasRepetido;
		for(i=0; i<limiteColores; i++)
		{
			if(arrayColores[i].cantColorMasRepetido > cantMax)
			{
				cantMax = arrayColores[i].cantColorMasRepetido;
				indiceMaximo = i;
			}
		}
		printf("\nColor de Barbijo mas comprado: %s- Total: %d\n ", arrayColores[indiceMaximo].color, cantMax);
		retorno = 0;
	}
	return retorno;
}
int info_subMenu(sCliente* arrayClientes, int limiteCliente, sCompra* arrayCompras, int limiteCompra)
{
	int retorno = -1;
	int opcion;
	//indiceEncontrado = _pedirId_buscarIndiceModificar(lista, limite);
	if(arrayClientes != NULL && limiteCliente > 0 && arrayCompras != NULL && limiteCompra > 0)
	{
		do
		{
			fflush(stdin);
			if(utn_getNumero(&opcion,"1 -  Color de barbijo que se compró mas veces\n2.Cantidad de compras pendientes\n3.Compra con precio por unidad mas bajo\n4.Salir\nIngrese una opcion: ","ERROR",1,4,2)==0)
				{
					switch(opcion)
					{
						case 1:
							info_getColores(arrayCompras, limiteCompra);
							break;
						case 2:
							com_contarYMostrarComprasPendientes(arrayCompras, limiteCompra);
							break;
						case 3:
							info_imprimirComprasConImportePorCliente(arrayCompras, limiteCompra, arrayClientes, limiteCliente);
							break;
						case 4:
							printf("adios\n");
							retorno = 0;
					}
				}
			}while(opcion != 4);
	}
	return retorno;
}
int info_getColores(sCompra* arrayCompras, int limiteCompra)
{
	sColores arrayColores[50];
	int i;
	int j;
	int retorno = -1;
	int flagColorRepetido = 0;
	int indiceVacioColor = 0;

	for(i=0; i<50; i++)
	{
		strncpy(arrayColores[i].color,"", 2);
	}
	if(arrayCompras != NULL && limiteCompra > 0)
	{
		for(i=0; i<limiteCompra; i++)
		{
			if(arrayCompras[i].estadoCompra == PAGADO)
			{
				for(j=0; j<indiceVacioColor; j++)
				{
					if(strncmp(arrayCompras[i].color,arrayColores[j].color, CANTIDAD_COLORES) == 0)
					{
						flagColorRepetido = 1;
						break;
					}
				}
				if(flagColorRepetido == 0)
				{
					strncpy(arrayColores[indiceVacioColor].color, arrayCompras[i].color, CANTIDAD_COLORES);
					indiceVacioColor++;
				}
			}
		}
		if(info_contadorColorMasRepetido(arrayCompras, limiteCompra, arrayColores, indiceVacioColor) == 0)
		{
			info_colorMasRepetido(arrayColores, indiceVacioColor);
			retorno = 0;
		}
	}
	return retorno;
}
