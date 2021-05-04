/*
 ============================================================================
 Name        : PARCIAL.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "compra.h"
#include "cliente-compra.h"

int main(void)
{
	setbuf(stdout,NULL);
	/*int numero;
	utn_getNumero(&numero, "INGRES ENUMERO: ", "ERROR", 0, 10, 3);
	printf("EL NUMERO ES : %d", numero);

	*/
	sCliente arrayClientes[CLIENTES];
	sCompra arrayCompras[COMPRAS];
	cli_initClientes(arrayClientes, CLIENTES);
	cli_hardcodeClientes(arrayClientes);
	com_initCompras(arrayCompras, COMPRAS);
	com_hardcodeCompras(arrayCompras);
	//int numero;
	char opcion;
	do
	{
		utn_getChar(&opcion, "a. Alta cliente\nb.Modificar cliente\nc.Baja cliente\nd.Realizar compra\ne.Pagar compra\nf.Cancelar compra\ng.Listar clientes con sus compras\nh.Informar\ni.Listar clientes\nj.Listar compras\nk.Salir\nIngrese una opcion: ", "OPCION INVALIDA", 'a', 'z', 2);
		switch(opcion)
		{
		case 'a':
			cli_altaCliente(arrayClientes, CLIENTES);
			break;
		case 'b':
			cli_modificarClientes(arrayClientes, CLIENTES);
			break;
		case 'c':
			cli_bajaCliente(arrayClientes, CLIENTES);
			break;
		case 'd':
			com_altaCompra(arrayCompras, COMPRAS, arrayClientes, CLIENTES);
			break;
		case 'e':
			com_pagarCompra(arrayCompras, COMPRAS, arrayClientes, CLIENTES);
			break;
		case 'f':
			com_bajaCompra(arrayCompras, COMPRAS, arrayClientes, CLIENTES);
			break;
		case 'g':
			mostrarComprasConSusClientes(arrayCompras, COMPRAS, arrayClientes, CLIENTES);
			break;
		case 'h':
			//com_contarYMostrarComprasPendientes(arrayCompras, COMPRAS);
			//info_imprimirComprasConImportePorCliente(arrayCompras, COMPRAS, arrayClientes, CLIENTES);
			info_subMenu(arrayClientes, CLIENTES, arrayCompras, COMPRAS);
			break;
		case 'i':
			cli_mostrarClientes(arrayClientes, CLIENTES);
			break;
		case 'j':
			com_mostrarCompras(arrayCompras, COMPRAS);
			break;
		}
	}while(opcion != 'k');
	return EXIT_SUCCESS;
}
