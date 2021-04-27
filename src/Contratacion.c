#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Menu.h"
#include "Contratacion.h"
#include "Pantalla.h"
#define ID_PANTALLA 1
#define CUIT_CLIENTE 2
#define DIAS 3
#define NOMBRE_ARCHIVO 4

void contratacion_swap(Contratacion* list, int i, int j);

int contratacion_init(Contratacion* list, int len){

	int result = -1;
	if(list!=NULL && len>0){

		for(int i=0;i<len;i++){
			list[i].isEmpty = 1;
			}
		result = 0;
	}
	return result;
}

int contratacion_harcode(Contratacion* list, int len){
	int result = -1;

	Contratacion auxList[5] = {
			{1, 1, "3229", 7, "archivo_1", 0},
			{2, 3, "3227", 8, "archivo_2", 0},
			{3, 1, "3228", 7, "archivo_3", 0},
			{4, 2, "3227", 10, "archivo_4", 0},
			{5, 2, "3229", 7, "archivo_5", 0}
	};

	if(5 <= len){

		for(int i=0; i<5; i++){
			list[i] = auxList[i];
		};
		result = 0;
	};

	return result;
}

int contratacion_getFree(Contratacion* list, int len, int* index){
	int result = -1;
	int buffer;

	if(list!=NULL && len>0){
		for(int i=0; i<len; i++){
			if(list[i].isEmpty == 1){
				buffer = i;
				*index = buffer;
				result = 0;
				break;
			}
		}
	}
	return result;
}


int contratacion_add(Contratacion* list, int len, int index, Pantalla* listPantalla, int lenPantalla){

	int result = -1;
	Contratacion buffer;
	int indexPan;

	if(list!=NULL && len>0 && index<len && index>=0 && listPantalla!=NULL && lenPantalla>0){

		if(
				pantalla_printList(listPantalla, lenPantalla) == 0 &&
				utn_getNumeroEntero(&buffer.idPantalla, "\nIngrese ID de la pantalla seleccionada", "\nERROR", 1, 10, 3) == 0 &&
				pantalla_getIndexById(listPantalla, lenPantalla, buffer.idPantalla, &indexPan) == 0
		){
			printf("\nIngrese los datos para la contratacion de la pantalla -> ");
			pantalla_printUnit(listPantalla, lenPantalla, indexPan);

			if(
					utn_getDni(buffer.cuitCliente, 12, "\nIngrese CUIT (sin guiones)", "\nERROR", 3) == 0 &&
					utn_getNumeroEntero(&buffer.dias, "\nIngrese Cantidad de dias", "\nERROR", 1, 365, 3) == 0 &&
					utn_getTexto(buffer.nombreArchivo, 51, "\nIngrese Nombre Archivo", "\ERROR", 3) == 0)
			{

				buffer.isEmpty = 0;
				buffer.id = index+1;
				list[index] = buffer;
				result = 0;
			}
		}
	}
	return result;
}

int contratacion_getIndexById(Contratacion* list, int len, int id, int* index){
	int result = -1;
	int buffer;

	if(list!=NULL && len>0 && index!=NULL){

		for(int i=0; i<len;i++){
			if(list[i].id == id){
				buffer = i;
				*index = buffer;
				result = 0;
				break;
			}
		}
	}
	return result;
};

int contratacion_modify(Contratacion* list, int len, int index){

	int result = -1;
	int buffer;

	if(list!=NULL && len>0 && index>=0){

		if(utn_getNumeroEntero(&buffer, "\nIngrese Cantidad de dias a modificar", "\nERROR", 1, 365, 3) == 0){
			list[index].dias = buffer;
		}
		result = 0;
	}
	return result;
}

int contratacion_logicLow(Contratacion* list, int len, int index){
	int result = -1;

	if(list!=NULL && len>0 && index>=0 && index<len){
		list[index].isEmpty=-1;
		result = 0;
	}
	return result;
}

int contratacion_function(int(*pFuncion)(Contratacion*,int,int), Contratacion* list, int len, Pantalla* listPan, int lenPan){

	int idPantalla;
	int index;
	int result = -1;
	Contratacion buffer;

	if(pFuncion!=NULL && len>0 && list!=NULL){

		if(
				contratacion_printList(list, len) == 0 &&
				utn_getDni(buffer.cuitCliente, 12, "\nIngrese CUIT (sin guiones) a editar-> ", "\nERROR", 3) == 0 &&
				contratacion_printByCuit(list, len, buffer.cuitCliente, listPan, lenPan) == 0 &&
				utn_getNumeroEntero(&idPantalla, "\nIngrese ID de la pantalla:", "Error", 0, 100, 3) == 0 &&
				contratacion_getIndexByIdPantalla(list, len, idPantalla, &index) == 0 &&
				pFuncion(list, len, index) == 0
		) {
			result = 0;
		}
	}
	return result;
}


int contratacion_printByCuit(Contratacion* list, int len, char* cuit, Pantalla* listPan, int lenPan){
	int result = -1;
	int indexPan;

	if(list != NULL && len > 0 && cuit > 0 && listPan != NULL && lenPan > 0){

		for(int i=0; i<len;i++){

			if(strncmp(list[i].cuitCliente, cuit, sizeof(cuit)==0))
			{
				pantalla_getIndexById(listPan, lenPan, list[i].id, &indexPan);
				contratacion_printUnit(list, len, i, listPan, lenPan, indexPan);
			}
		}
		result = 0;
	}
	return result;
}

int contratacion_printUnit(Contratacion* list, int len, int index, Pantalla* listPan, int lenPan, int indexPan){

	int result = -1;

	if(list!=NULL && len>0 && index<len){
		printf("\n Contratacion -> ID: %d -- Id_Pantalla: %d -- cuitCliente: %s -- Dias: %d -- Nombre_Archivo: %s -- Estado: %d"
				"\n Pantalla-> Nombre: %s -- Direccion: %s -- Tipo: %s -- Precio: %.2f -- Estado: %d",
				list[index].id,
				list[index].idPantalla,
				list[index].cuitCliente,
				list[index].dias,
				list[index].nombreArchivo,
				list[index].isEmpty,
				listPan[indexPan].nombre,
				listPan[indexPan].direccion,
				listPan[indexPan].tipo,
				listPan[indexPan].precio,
				listPan[indexPan].isEmpty
				);
		result = 0;
	}

	return result;
}

int contratacion_printList(Contratacion* list, int len){

	int result = -1;

	if(list!=NULL && len>0){

		for(int i=0; i<len;i++){
			if(list[i].isEmpty == 0){
				printf("\n Contratacion -> POSICION: %d -- ID: %d -- Id_Pantalla: %d -- cuitCliente: %s -- Dias: %d -- Nombre_Archivo: %s",
						i,
						list[i].id,
						list[i].idPantalla,
						list[i].cuitCliente,
						list[i].dias,
						list[i].nombreArchivo
						);
			}
		}
		result = 0;
	}
	return result;
}

int contratacion_getIndexByIdPantalla(Contratacion* list, int len, int idPantalla, int* index){
	int result = -1;
	int buffer;

	if(list!=NULL && len>0 && index!=NULL){

		for(int i=0; i<len; i++){
			if(list[i].idPantalla == idPantalla){
				buffer = i;
				*index = buffer;
				result = 0;
				break;
			}
		}
	}

	return result;
}


int contratacion_sortByCuit(Contratacion* list, int len, int order){
	int result = -1;
	int flagSwap;
	int newLen;


	if(list!=NULL && len >0){

		newLen = len-1;

		do {
			flagSwap=0;

			for(int i=0; i<newLen;i++)
			{
				if(!(list[i].isEmpty)){

					switch(order)
					{

					case ORDER_ASC:

						if(strncmp(list[i].cuitCliente, list[i+1].cuitCliente, sizeof(list[i].cuitCliente))> 0){
							contratacion_swap(list, i, i+1);
							flagSwap=1;
						}
						break;

					case ORDER_DESC:

						if(strncmp(list[i].cuitCliente, list[i+1].cuitCliente, sizeof(list[i].cuitCliente))< 0){
							contratacion_swap(list, i, i+1);
							flagSwap=1;
						}
						break;
					}
				}

				newLen --;
			}

		} while (flagSwap);

		result = 0;
	}

	return result;
}

void contratacion_swap(Contratacion* list, int i, int j){

	Contratacion aux;

	aux = list[i];
	list[i] = list[j];
	list[j] = aux;
}




