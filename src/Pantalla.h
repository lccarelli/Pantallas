/*
 * Pantallas.h
 *
 *  Created on: 22 abr. 2021
 *      Author: lau
 */

#ifndef PANTALLA_H_
#define PANTALLA_H_
#define CANT_PANTALLA 10

struct
{
	int id;
	char nombre[51];
	char direccion[51];
	float precio;
	char tipo[11];
	int isEmpty;
} typedef Pantalla;


int pantalla_init(Pantalla* list, int len);
int pantalla_harcode(Pantalla* list, int len);
int pantalla_getFree(Pantalla* list, int len, int* indice);
int pantalla_add(Pantalla* list, int len, int index);
int pantalla_getIndexById(Pantalla* list, int len, int id, int* index);
int pantalla_modify(Pantalla* list, int len, int index);
int pantalla_logicLow(Pantalla* list, int len, int index);
int pantalla_printUnit(Pantalla* list, int len, int index);
int pantalla_printList(Pantalla* list, int len);
int pantalla_function(int(*pFuncion)(Pantalla*,int,int), Pantalla* list, int len);

#endif /* PANTALLA_H_ */
