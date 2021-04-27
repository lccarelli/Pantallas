#include "Pantalla.h"

#ifndef CONTRATACION_H_
#define CONTRATACION_H_
#define CANT_CONTRATACION 5
#define ORDER_DESC 1
#define ORDER_ASC 2

struct
{
	int id;
	int idPantalla;
	char cuitCliente[12];
	int dias;
	char nombreArchivo[51];
	int isEmpty;
} typedef Contratacion;


int contratacion_init(Contratacion* list, int len);
int contratacion_harcode(Contratacion* list, int len);
int contratacion_getFree(Contratacion* list, int len, int* index);
int contratacion_add(Contratacion* list, int len, int index, Pantalla* listPantallas, int lenPantallas);
int contratacion_getIndexById(Contratacion* list, int len, int id, int* index);
int contratacion_modify(Contratacion* list, int len, int index);
int contratacion_logicLow(Contratacion* list, int len, int index);
int contratacion_printUnit(Contratacion* list, int len, int index, Pantalla* listPan, int lenPan, int indexPan);
int contratacion_printList(Contratacion* list, int len);
int contratacion_printByCuit(Contratacion* list, int len, char* cuit, Pantalla* listPan, int lenPan);
int contratacion_getIndexByIdPantalla(Contratacion* list, int len, int idPantalla, int* index);
int contratacion_function(int(*pFuncion)(Contratacion*,int,int), Contratacion* list, int len, Pantalla* listPan, int lenPan);
int contratacion_sortByCuit(Contratacion* list, int len, int order);

#endif /* CONTRATACION_H_ */
