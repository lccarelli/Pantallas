/*
 * Cliente.h
 *
 *  Created on: 27 abr. 2021
 *      Author: lau
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#include "Contratacion.h"
#include "Pantalla.h"
#include "Cliente.h"
#include "Menu.h"

#define CANT_CLIENT 3
#define CUIT_LEN 12
#define INFO_CANT_CONTRATACION 1
#define INFO_FACTURACION 2

struct {
	int id;
	char cuit_cliente[CUIT_LEN];
	int cant_contratacion;
	float facturacion;
	int isEmpty;
} typedef Cliente;


int cliente_init(Cliente* list, int len);
int cliente_printList(Cliente* list, int len);
int cliente_getClient(Cliente* listClient, int lenClient, Contratacion* listCont, int lenCont);
int cliente_sortByPrecio(Cliente* list, int len, int order);
int cliente_sortByCuit(Cliente* list, int len, int order);

#endif /* CLIENTE_H_ */
