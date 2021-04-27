#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Pantalla.h"
#include "Menu.h"
#define NOMBRE 1
#define DIRECCION 2
#define PRECIO 3
#define TIPO 4


int pantalla_init(Pantalla* list, int len){

	int result = -1;
	if(list!=NULL && len>0){

		for(int i=0;i<len;i++){
			list[i].isEmpty = 1;
			}
		result = 0;
	}
	return result;
}

int pantalla_harcode(Pantalla* list, int len){
	int result = -1;

	Pantalla auxList[3] = {
			{1, "utn_1", "Mitre 400", 300.00, "lcd", 0},
			{2, "utn_2", "Mitre 400", 300.00, "led", 0},
			{3, "utn_3", "Mitre 400", 300.00, "lcd", 0},
	};

	if(3 <= len && 3 < 11){

		for(int i=0; i<3; i++){
			list[i] = auxList[i];
		};
		result = 0;
	};

	return result;
}


int pantalla_getFree(Pantalla* list, int len, int* indice){
	int result = -1;
	int buffer;

	if(list!=NULL && len>0){
		for(int i=0; i<len; i++){
			if(list[i].isEmpty == 1){
				buffer = i;
				*indice = buffer;
				result = 0;
				break;
			}
		}
	}
	return result;
}


int pantalla_add(Pantalla* list, int len, int index){

	int result = -1;
	Pantalla buffer;

	if(list!=NULL && len>0 && index<len && index>=0){

		if(
				utn_getTexto(buffer.nombre,51,"\nNombre ?","\nERROR Nombre\n",2) == 0 &&
				utn_getTexto(buffer.direccion,51,"\nDireccion ?","\nERROR Direccion\n",2) == 0 &&
				utn_getNumeroDecimal(&buffer.precio, "\nPrecio ?","\nERROR Precio\n", 0, 1000000, 3) == 0 &&
				utn_getTexto(buffer.tipo,11, "\nTipo: LCD - LED ?\n", "\nERROR RAZA", 3) == 0)
		{
			buffer.isEmpty = 0;
			buffer.id = index+1;
			list[index] = buffer;
			result = 0;
		}
	}
	return result;
}

int pantalla_getIndexById(Pantalla* list, int len, int id, int* index){
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

int pantalla_modify(Pantalla* list, int len, int index){

	int result = -1;
	int selection;
	Pantalla buffer;

	printf("\n ENTRE PANTALLA ->");

	if(list!=NULL && len>0 && index<len && index>=0){

		do {

			menu_getModifyPantalla(&selection);

			switch (selection) {

				case NOMBRE:

					if(utn_getTexto(buffer.nombre,51,"\nNombre ?","\nERROR Nombre\n",2) == 0){
						strncpy(list[index].nombre, buffer.nombre, sizeof(buffer.nombre));
					}
					break;

				case DIRECCION:

					if(utn_getTexto(buffer.direccion,51,"\nDireccion ?","\nERROR Direccion\n",2) == 0){
						strncpy(list[index].direccion, buffer.direccion, sizeof(buffer.direccion));
					}
					break;

				case PRECIO:

					if(utn_getNumeroDecimal(&buffer.precio, "\nPrecio ?","\nERROR Precio\n", 0, 1000000, 3) == 0){
						list[index].precio = buffer.precio;
					}
					break;

				case TIPO:

					if(utn_getTexto(buffer.tipo,11, "\nTipo: LCD - LED ?\n", "\nERROR RAZA", 3) == 0){
						strncpy(list[index].tipo, buffer.tipo, sizeof(buffer.tipo));
					}
					break;
			}

			result=0;

		} while (!(selection==0));
	}
	return result;
}

int pantalla_logicLow(Pantalla* list, int len, int index){
	int result = -1;

	if(list!=NULL && len>0 && index>0 && index<len){

		list[index].isEmpty=-1;
		printf("\n ID: %d -- Estado: %d",
				list[index].id,
				list[index].isEmpty
				);
		result=0;
	}
	return result;
}

int pantalla_printUnit(Pantalla* list, int len, int index){

	int result = -1;

	if(list!=NULL && len>0 && index<len){
		printf("\n ID: %d -- Nombre: %s -- Direccion: %s -- Precio: %.2f -- Tipo: %s -- Estado: %d",
				list[index].id,
				list[index].nombre,
				list[index].direccion,
				list[index].precio,
				list[index].tipo,
				list[index].isEmpty
				);
		result = 0;
	}

	return result;
}

int pantalla_printList(Pantalla* list, int len){

	int result = -1;

	if(list!=NULL && len>0){
		printf("****** Listado de Pantallas cargadas ******");
		for(int i=0; i<len; i++){
			if(list[i].isEmpty==0){
				pantalla_printUnit(list, len, i);
			}
		}
		result = 0;
	}

	return result;
}

int pantalla_function(int(*pFuncion)(Pantalla*,int,int), Pantalla* list, int len){

	int id;
	int index;
	int result = -1;

	if(pFuncion!=NULL && len>0 && list!=NULL){

		if(
				pantalla_printList(list, len) == 0 &&
				utn_getNumeroEntero(&id, "\nIngrese ID -> ", "\nIngrese id VALIDO", 0, 100, 3) == 0 &&
				pantalla_getIndexById(list, len, id, &index) == 0
		) {
			pFuncion(list, len, index);
			result = 0;
		}
	}
	return result;
}
