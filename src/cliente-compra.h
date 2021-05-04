/*
 * cliente-compra.h
 *
 *  Created on: 29 abr. 2021
 *      Author: Sordello
 */

#ifndef CLIENTE_COMPRA_H_
#define CLIENTE_COMPRA_H_
#include "compra.h"
typedef struct
{
	char color[50];
	int cantColorMasRepetido;

}sColores;
void mostrarComprasConSusClientes(sCompra* arrayCompras, int limiteCompras,sCliente* arrayClientes, int limiteClientes);
int com_pagarCompra(sCompra* arrayCompras, int limite, sCliente* arrayClientes, int limiteClientes);
int com_bajaCompra(sCompra* arrayCompras, int limite, sCliente* arrayClientes, int limiteClientes);
int info_imprimirComprasConImportePorCliente(sCompra* arrayCompras,int limiteCompras,sCliente* arrayClientes,int limiteClientes);
int info_calcularPagoCliente(sCompra* arrayCompras,int limite,sCliente* arrayClientes,int limiteClientes,char* colorBarbijo, float* deuda);
int info_buscarClientePorId(sCliente* arrayClientes, int limite, int valorBuscado);
int info_buscarClientePorIdCompra(sCompra*  arrayCompras, int limite, int valorBuscado);
int info_imprimirClientesConCompras(sCompra* arrayCompras,int limite,sCliente* arrayClientes,int limiteClientes,char* colorBarbijo);
int info_contadorColorMasRepetido(sCompra* arrayCompras, int limiteCompra, sColores* listaColores, int limiteColores);
int info_colorMasRepetido(sColores* listaColores, int limiteColores);
int info_getColores(sCompra* arrayCompras, int limiteCompra);
int info_subMenu(sCliente* arrayClientes, int limiteCliente, sCompra* arrayCompras, int limiteCompra);


#endif /* CLIENTE_COMPRA_H_ */
