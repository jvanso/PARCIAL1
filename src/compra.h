/*
 * compra.h
 *
 *  Created on: 29 abr. 2021
 *      Author: Sordello
 */

#ifndef COMPRA_H_
#define COMPRA_H_
#define PAGADO 1
#define ADEUDA 0
#define COMPRAS 1000
#include "cliente.h"
typedef struct
{
	int idCliente;
	int idCompra;
	int cantBarbijos;
	char direccion[50];
	char color[50];
	int estadoCompra;
	float importe;
}sCompra;
int com_initCompras(sCompra* arrayCompras, int limite);
int com_hardcodeCompras(sCompra* arrayCompras);
int com_altaCompra(sCompra* arrayCompras, int limite, sCliente* arrayClientes, int limiteClientes);
int com_buscarCompraPorId(sCompra* arrayCompras, int limite, int* index);
int com_buscarLibre(sCompra* arrayCompras, int limite, int* indice);
int com_contarYMostrarComprasPendientes(sCompra* arrayCompras, int limite);
int com_idCompras();
void com_mostrarCompras(sCompra* arrayCompras,int limite);

#endif /* COMPRA_H_ */
