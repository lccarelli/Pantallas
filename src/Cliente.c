#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Informes.h"
#include "utn.h"
#include "Pantalla.h"
#include "Contratacion.h"

void cliente_swap(Cliente* list, int i, int j);



int cliente_init(Cliente* list, int len){

	int result = -1;
	if(list!=NULL && len>0){

		for(int i=0;i<len;i++)
		{
			list[i].isEmpty = 1;
		}
		result = 0;
	}
	return result;
}

int cliente_getClient(Cliente* listClient, int lenClient, Contratacion* listCont, int lenCont){
	int result = -1;
	int flagExiste;
	int indiceLibreClient = 0;

	if(listClient!=NULL && lenClient>0 && listCont!=NULL && lenCont>0){

		for(int i=0; i<lenCont; i++){

			flagExiste = 0;

			for(int j=0; j<=indiceLibreClient; j++){

				if(strncmp(listCont[i].cuitCliente, listClient[j].cuit_cliente, CUIT_LEN) == 0)
				{
					flagExiste = 1;
					break;
				}
			}

			if(flagExiste == 0)
			{
				strncpy(listClient[indiceLibreClient].cuit_cliente, listCont[i].cuitCliente, CUIT_LEN);
				cliente_setClienteVacio(listClient, lenClient, indiceLibreClient);
				indiceLibreClient++;
			}
		}
		cliente_printList(listClient, CANT_CLIENT);
	}
	return result;
}

int cliente_setClienteVacio(Cliente* list, int len, int index){
	int result = -1;

	if(list!=NULL && len>0 && index>0){

		list[index].id = index +1;
		list[index].facturacion = 0;
		list[index].cant_contratacion = 0;
		list[index].isEmpty = 0;
		result = 0;
	}

	return result;
}

int cliente_printList(Cliente* list, int len){
	int result = -1;

	if(list!=NULL && len>0){
		for(int i=0; i<len; i++){
			if(list[i].isEmpty == 0){

				printf("\n POSICION: %d -- CUIT: %s -- CANT: %d -- FACT: %.2f",
						i,
						list[i].cuit_cliente,
						list[i].cant_contratacion,
						list[i].facturacion
						);
			}
		}
	}
	return result;
}


int cliente_sortByPrecio(Cliente* list, int len, int order){
	int result = -1;
	int flagSwap;
	int newLen;

	if(list!=NULL && len >0){

		newLen = len-1;
		do {
			flagSwap=0;
			for(int i=0; i<newLen;i++){
				if(!(list[i].isEmpty)){

					switch(order){
					case ORDER_ASC:
						if(list[i].facturacion > list[i+1].facturacion){
							cliente_swap(list, i, i+1);
							flagSwap=1;
						}
						break;

					case ORDER_DESC:
						if(list[i].facturacion < list[i+1].facturacion){
							cliente_swap(list, i, i+1);
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

int cliente_sortByCuit(Cliente* list, int len, int order){
	int result = -1;
	int flagSwap;
	int newLen;

	if(list!=NULL && len >0){

		newLen = len-1;
		do {
			flagSwap=0;
			for(int i=0; i<newLen;i++){
				if(!(list[i].isEmpty)){

					switch(order){

					case ORDER_ASC:
						if(strncmp(list[i].cuit_cliente, list[i+1].cuit_cliente, sizeof(list[i].cuit_cliente))> 0){
							cliente_swap(list, i, i+1);
							flagSwap=1;
						}
						break;

					case ORDER_DESC:
						if(strncmp(list[i].cuit_cliente, list[i+1].cuit_cliente, sizeof(list[i].cuit_cliente))< 0){
							cliente_swap(list, i, i+1);
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

void cliente_swap(Cliente* list, int i, int j){

	Cliente aux;

	aux = list[i];
	list[i] = list[j];
	list[j] = aux;
}
