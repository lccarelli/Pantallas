#ifndef MENU_H_
#define MENU_H_
#define ALTA_PANTALLA 1
#define MODIFICAR_PANTALLA 2
#define BAJA_PANTALLA 3
#define ALTA_CONTRATACION 4
#define MODIFICAR_CONTRATACION 5
#define BAJA_CONTRATACION 6
#define LISTAR_IMPORTES 7
#define LISTAR_CONTRATACIONES 8
#define LISTAR_PANTALLAS 9
#define INFORMES 10
#define EXIT 0


void menu_getMain(int* select);
void menu_getModifyPantalla(int* select);
void menu_getModifyContratacion(int* select);
void menu_getInformes(int* select);

#endif /* MENU_H_ */
