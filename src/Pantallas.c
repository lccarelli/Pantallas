/*
 ============================================================================
 Name        : Pantallas.c
 Author      : lau
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Menu.h"
#include "Pantalla.h"
#include "Contratacion.h"
#include "Informes.h"

int main(void) {

	int select;
	int indiceDispo;
	int flagAltaContratacion = 0;
	int flagAltaPantalla = 0;

	Pantalla listPantalla[CANT_PANTALLA];
	Contratacion listContratacion[CANT_CONTRATACION];
	Cliente listCliente[CANT_CLIENT];

	pantalla_init(listPantalla, CANT_PANTALLA);
	contratacion_init(listContratacion, CANT_CONTRATACION);
	pantalla_harcode(listPantalla, CANT_PANTALLA);
	contratacion_harcode(listContratacion, CANT_CONTRATACION);
	flagAltaPantalla = 1;
	flagAltaContratacion =1;

	do {
		menu_getMain(&select);

			switch(select){

			case ALTA_PANTALLA:

				pantalla_getFree(listPantalla, CANT_PANTALLA, &indiceDispo);

				if(indiceDispo<CANT_PANTALLA){
					if(pantalla_add(listPantalla, CANT_PANTALLA, indiceDispo)==0){

						printf("\nSe cargo correctamente");
						};
					} else {
						printf("\nNo hay mas lugar para cargar");
					}
				break;

			case MODIFICAR_PANTALLA:

				if(flagAltaPantalla){
					pantalla_function(pantalla_modify, listPantalla, CANT_PANTALLA);
				} else {
					printf("\n Antes debe cargar una contratacion");
				}

				break;

			case BAJA_PANTALLA:

				if(flagAltaPantalla){
					pantalla_function(pantalla_logicLow, listPantalla, CANT_PANTALLA);
				} else {
					printf("\n Antes debe cargar una contratacion");
				}

				break;

			case ALTA_CONTRATACION:

				contratacion_getFree(listContratacion, CANT_CONTRATACION, &indiceDispo);

				if(indiceDispo<CANT_CONTRATACION){
					if(contratacion_add(listContratacion, CANT_CONTRATACION, indiceDispo, listPantalla, CANT_PANTALLA)==0){
						flagAltaContratacion = 1;
						printf("\nse cargo correctamente");
						};
					} else {
						printf("\nno hay mas lugar para cargar");
					}
				break;

			case MODIFICAR_CONTRATACION:

				if(flagAltaContratacion){
					contratacion_function(
							contratacion_modify,
							listContratacion,CANT_CONTRATACION,
							listPantalla,CANT_PANTALLA);
				} else {
					printf("\n Antes debe cargar una contratacion");
				}

				break;

			case BAJA_CONTRATACION:

				if(flagAltaContratacion){
					contratacion_function(
							contratacion_logicLow,
							listContratacion,CANT_CONTRATACION,
							listPantalla,CANT_PANTALLA);
				} else {
					printf("\n Antes debe cargar una contratacion");
				}

				break;

			case LISTAR_IMPORTES: //buscar por cuit


				break;

			case LISTAR_CONTRATACIONES:

				contratacion_printList(listContratacion, CANT_CONTRATACION);

				break;

			case LISTAR_PANTALLAS:

				pantalla_printList(listPantalla, CANT_PANTALLA);

				break;

			case INFORMES:

				cliente_init(listCliente, CANT_CLIENT);
				cliente_getClient(listCliente, CANT_CLIENT, listContratacion, CANT_CONTRATACION);
				informes_llenarDatosCliente(listCliente, CANT_CLIENT, listContratacion, CANT_CONTRATACION, listPantalla, CANT_PANTALLA);
				informes_getInformes(listCliente, CANT_CLIENT);

				break;
			}

	} while(!(select == EXIT));

	return EXIT_SUCCESS;
}
