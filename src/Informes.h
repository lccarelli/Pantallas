/*
 * Informes.h
 *
 *  Created on: 26 abr. 2021
 *      Author: lau
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include "Contratacion.h"
#include "Pantalla.h"
#include "Cliente.h"
#include "Menu.h"

int informes_llenarDatosCliente(Cliente* listCliente, int lenCliente, Contratacion* listCont, int lenCont, Pantalla* listPan, int lenPan);
int informes_cantContratacion(Cliente* listCliente, int lenCliente);
int informes_getInformes(Cliente* list, int len);
#endif /* INFORMES_H_ */
