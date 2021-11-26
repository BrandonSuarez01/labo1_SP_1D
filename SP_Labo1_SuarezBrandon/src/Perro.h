/*
 * Perro.h
 *
 *  Created on: 23 nov. 2021
 *      Author: brans
 */

#ifndef PERRO_H_
#define PERRO_H_

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Funciones.h"

#define TAMNOM 21

typedef struct
{
	int id;
	char nombre[TAMNOM];
	float peso;
	int edad;
	char raza[TAMNOM];
	float cantidadComidaRacion;

}ePerrito;

ePerrito* perro_nuevoPerro();
ePerrito* perro_construcParam(char* id, char* nombre, char* peso, char* edad,  char* raza);

void perro_borrar(ePerrito* this);

int perro_setId(ePerrito* this, int id);
int perro_getId(ePerrito* this);

int perro_setPeso(ePerrito* this, float peso);
float perro_getPeso(ePerrito* this);

int perro_setEdad(ePerrito* this, int edad);
int perro_getEdad(ePerrito* this);

int perro_setNombre(ePerrito* this, char* nombre);
int perro_getNombre(ePerrito* this, char* nombre);

int perro_setRaza(ePerrito* this, char* raza);
int perro_getRaza(ePerrito* this, char* raza);

int perro_setRacion(ePerrito* this, float racion);
float perro_getRacion(ePerrito* this);

int perro_ordenarPorNombre(void* punteroUno, void* punteroDos);
int perro_laQueMapea(void* puntero);

#endif /* PERRO_H_ */
