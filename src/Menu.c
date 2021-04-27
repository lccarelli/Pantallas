#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "Menu.h"
#include "utn.h"

void menu_getMain(int* select){

	printf("\nMenu:"
			"\n\t1). Alta de PANTALLA"
			"\n\t2). Modificar PANTALLA"
			"\n\t3). Baja PANTALLA"
			"\n\t4). Alta CONTRATACION"
			"\n\t5). Modificar CONTRATACION"
			"\n\t6). Baja CONTRATACION"
			"\n\t7). Consulta FACTURACION"
			"\n\t8). Listar CONTRATACIONES"
			"\n\t9). Listar PANTALLAS"
			"\n\t10). Informes"
			"\n\t0). salir\n");
	utn_getNumeroEntero(select, "\nIngrese su seleccion -> ", "\nERROR -> Debe ser una de las opciones", 1, 10, 3);
}

void menu_getModifyPantalla(int* select){

	printf("\nMenu Modificar:"
			"\n\t1). Nombre"
			"\n\t2). Direccion"
			"\n\t3). Precio"
			"\n\t4). Tipo Pantalla"
			"\n\t0). salir\n");
	utn_getNumeroEntero(select, "\nIngrese su seleccion -> ", "\nERROR -> Debe ser una de las opciones", 0, 4, 3);
}

void menu_getModifyContratacion(int* select){

	printf("\nMenu Modificar:"
			"\n\t1). Id_Pantalla"
			"\n\t2). Cuit_Cliente"
			"\n\t3). Dias"
			"\n\t4). Nombre_Archivo"
			"\n\t0). salir\n");
	utn_getNumeroEntero(select, "\nIngrese su seleccion -> ", "\nERROR -> Debe ser una de las opciones", 0, 4, 3);
}

void menu_getInformes(int* select){

	printf("\nMenu Modificar:"
			"\n\t1). Lista​ ​ cliente​: -> cantidad​ ​ de​ ​ contrataciones​ ​ e ​ ​ importe​ ​ a ​ ​ pagar​ ​ por​ ​ cada​ ​ una"
			"\n\t2). Cliente​ ​ con​ ​ importe​ ​ más​ ​ alto​ ​ a ​ ​ facturar​"
			"\n\t0). salir\n");
	utn_getNumeroEntero(select, "\nIngrese su seleccion -> ", "\nERROR -> Debe ser una de las opciones", 0, 4, 3);
}
