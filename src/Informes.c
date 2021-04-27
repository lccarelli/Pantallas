#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Informes.h"
#include "utn.h"
#include "Pantalla.h"
#include "Contratacion.h"
#include "Cliente.h"


int informes_llenarDatosCliente(Cliente* listCliente, int lenCliente, Contratacion* listCont, int lenCont, Pantalla* listPan, int lenPan){
	int result =-1;
	int indexPantalla;

	if(listCliente!=NULL && listCont!=NULL && listPan!=NULL && lenCliente>0 && lenCont>0 && lenPan>0){

		for(int i=0; i<lenCliente; i++){
			for(int j=0; j<lenCont; j++){
				if(listCont[j].isEmpty == 0){
					if(strncmp(listCliente[i].cuit_cliente, listCont[j].cuitCliente, CUIT_LEN) == 0 )
					{
						pantalla_getIndexById(listPan, lenPan, listCont[j].idPantalla, &indexPantalla);
						listCliente[i].facturacion = listPan[indexPantalla].precio + listCliente[i].facturacion;
						listCliente[i].cant_contratacion = listCliente[i].cant_contratacion +1;
					}
				}
			}
		}
		result = 0;
	}
	return result;
}

int informes_cantContratacion(Cliente* listCliente, int lenCliente){
	int result =-1;

	if(listCliente!=NULL && lenCliente>0 ){

		cliente_printList(listCliente, lenCliente);

		result = 0;
	}
	return result;
}

int informes_importeMasAlto(Cliente* list, int len){
	int result = -1;

	if(list!=NULL && len > 0){

		printf("\nENTRE AL MAS ALTO----> ");

		cliente_sortByCuit(list, len, ORDER_ASC);
		cliente_printList(list, len);
		cliente_sortByPrecio(list, len, ORDER_DESC);

		printf("\n cliente con importe mas alto -> CUIT: %s -- IMPORTE: %.2f", list[0].cuit_cliente, list[0].facturacion);
	}

	return result;
}


int informes_getInformes(Cliente* list, int len){

	int result = -1;
	int select;

	do {

		menu_getInformes(&select);

		switch(select){

		case INFO_CANT_CONTRATACION:
			informes_cantContratacion(list, len);

			break;
		case INFO_FACTURACION:
			informes_importeMasAlto(list, len);
			break;
		}


	} while (!select == 0);

	return result;
}

