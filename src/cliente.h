/*
 * cliente.h
 *
 *  Created on: 29 abr. 2021
 *      Author: Sordello
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_
#define VACIO 0
#define OCUPADO 1
#define CLIENTES 100
#include "utn.h"

typedef struct
{
	char nombre[50];
	char apellido[50];
	int cuit;
	int idCliente;
	int estadoCliente;
}sCliente;
int cli_buscarLibre(sCliente* arrayClientes, int limite, int* indice);
int cli_altaCliente(sCliente* arrayClientes, int limite);
int cli_idClientes();
int cli_hardcodeClientes(sCliente* arrayClientes);
int cli_modificarClientes(sCliente* arrayClientes, int limite);
int cli_buscarClientePorId(sCliente* arrayClientes, int limite,int* index);
int cli_bajaCliente(sCliente* arrayClientes, int limite);
int info_buscarClientePorIdd(sCliente* arrayClientes, int limite, int valorBuscado);
void cli_mostrarClientes(sCliente* arrayClientes,int limite);

/*
int altaPantalla(sPantalla* arrayPantallas, int limite);
int modificarPantalla(sPantalla* arrayPantallas, int limite);
int buscarPantallaPorId(sPantalla* arrayPantallas, int limite, int* index);
int bajaPantalla(sPantalla* arrayPantallas, int limite);
int buscarPantallaLibre(sPantalla* arrayPantallas, int limite, int* indice);
int idPantallas();
void mostrarPantallas(sPantalla* arrayPantalla, int limite);
*/
int cli_initClientes(sCliente* arrayClientes, int limite);

#endif /* CLIENTE_H_ */
