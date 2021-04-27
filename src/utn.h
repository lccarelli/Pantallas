/*
 * utn.h
 *
 *  Created on: 30 mar. 2021
 *      Author: lau
 */

#ifndef UTN_H_
#define UTN_H_

#endif /* UTN_H_ */

/**
 * @brief ->	Input de un dato, devuelve un numero entero
 * @param ->	number // Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * @param ->	message // Es el mensaje a ser mostrado
 * @param ->	errorMessage // Es el mensaje de Error a ser mostrado
 * @param ->	min // Es el numero maximo a ser aceptado
 * @param ->	max // Es el minimo minimo a ser aceptado
 * @return ->	Retorna 0 si se obtuvo el numero y -1 si no
**/
int utn_getNumeroEntero(
					int* number,
					char* message,
					char* errorMessage,
					int min,
					int max,
					int retries
					);

/**
 * @brief ->	utn_getNumeroDecimal -> Input de un dato, devuelve un numero decimal
 * @param ->	number // Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * @param ->	message // Es el mensaje a ser mostrado
 * @param ->	errorMessage // Es el mensaje de Error a ser mostrado
 * @param ->	min // Es el numero maximo a ser aceptado
 * @param ->	max // Es el minimo minimo a ser aceptado
 * @return ->	Retorna 0 si se obtuvo el numero y -1 si no
**/
int utn_getNumeroDecimal(
							float* number,
							char* message,
							char* errorMessage,
							int min,
							int max,
							int retries
						);
/**
 * @brief ->	utn_getTexto -> Input de un dato, devuelve una cadena
 * @param ->	char* string // Puntero al espacio de memoria donde se guardara el ingreso del stdin
 * @param ->	message // Es el mensaje a ser mostrado
 * @param ->	errorMessage // Es el mensaje de Error a ser mostrado
 * @param ->	min // Es el numero maximo a ser aceptado
 * @param ->	max // Es el minimo minimo a ser aceptado
 * @return ->	Retorna 0 si se obtuvo el numero y -1 si no
**/
int utn_getTexto(
					char* string,
					int len,
					char* message,
					char* errorMessage,
					int retries
				);

int utn_getDni(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
