/*
 * Perro.c
 *
 *  Created on: 23 nov. 2021
 *      Author: brans
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Funciones.h"
#include "Perro.h"

ePerrito* perro_nuevoPerro()
{
	ePerrito* nuevoPerro = NULL;
	nuevoPerro = (ePerrito*) malloc (sizeof(ePerrito));
	return nuevoPerro;
}
ePerrito* perro_construcParam(char* id, char* nombre, char* peso, char* edad, char* raza)
{
	int auxEdad;
	int auxId;
	float auxPeso;

	ePerrito* unPerro = NULL;
	unPerro = perro_nuevoPerro();

	auxId = atoi(id);
	auxEdad = atoi(edad);
	auxPeso = atof(peso);

	if(edad > 0 && nombre != NULL && raza != NULL && id != NULL && peso != NULL)
	{
		perro_setId(unPerro, auxId);
		perro_setPeso(unPerro, auxPeso);
		perro_setEdad(unPerro, auxEdad);
		perro_setNombre(unPerro, nombre);
		perro_setRaza(unPerro, raza);
	}

	return unPerro;
}
void perro_borrar(ePerrito* this)
{
	if(this != NULL)
	{
		free(this);
		this = NULL;
	}
}
int perro_setId(ePerrito* this, int id)
{
	int retorno = -1;

	if(this != NULL)
	{
		this->id = id;
		retorno = 0;
	}

	return retorno;
}
int perro_getId(ePerrito* this)
{
	int retorno = -1;

	if(this != NULL)
	{
		retorno = this->id;
	}

	return retorno;
}
int perro_setPeso(ePerrito* this, float peso)
{
	int retorno = -1;

	if(this != NULL)
	{
		this->peso = peso;
		retorno = 0;
	}

	return retorno;
}
float perro_getPeso(ePerrito* this)
{
	float retorno = -1.00;

	if(this != NULL)
	{
		retorno = this->peso;
	}
	return retorno;
}
int perro_setEdad(ePerrito* this, int edad)
{
	int retorno = -1;

	if(this != NULL)
	{
		this->edad = edad;
		retorno = 0;
	}
	return retorno;
}
int perro_getEdad(ePerrito* this)
{
	int retorno = -1;

	if(this != NULL)
	{
		retorno = this->edad;
	}
	return retorno;
}
int perro_setNombre(ePerrito* this, char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		retorno = 0;
	}
	return retorno;
}
int perro_getNombre(ePerrito* this, char* nombre)
{
	int retorno = -1;

	if(this != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 0;
	}
	return retorno;
}
int perro_setRaza(ePerrito* this, char* raza)
{
	int retorno = -1;

	if(this != NULL && raza != NULL)
	{
		strcpy(this->raza, raza);
		retorno = 0;
	}
	return retorno;
}
int perro_getRaza(ePerrito* this, char* raza)
{
	int retorno = -1;

	if(this != NULL)
	{
		strcpy(raza, this->raza);
	}
	return retorno;
}
int perro_setRacion(ePerrito* this, float racion)
{
	int retorno = -1;

	if(this != NULL)
	{
		this->cantidadComidaRacion = racion;
		retorno = 0;
	}
	return retorno;
}
float perro_getRacion(ePerrito* this)
{
	float retorno = -1.00;

	if(this != NULL)
	{
		retorno = this->cantidadComidaRacion;
	}
	return retorno;
}
int perro_ordenarPorNombre(void* punteroUno, void* punteroDos)
{
	int retorno = -2;
	char auxNombreUno[TAMNOM];
	char auxNombreDos[TAMNOM];
	ePerrito* auxEmpleado = (ePerrito*)punteroUno;
	ePerrito* auxEmpleadoDos = (ePerrito*)punteroDos;

	perro_getNombre(auxEmpleado, auxNombreUno);
	perro_getNombre(auxEmpleadoDos, auxNombreDos);
	retorno = strcmp(auxNombreUno, auxNombreDos);

	auxEmpleado = NULL;
	auxEmpleadoDos = NULL;

	return retorno;
}
int perro_laQueMapea(void* puntero)
{
	int retorno = -1;
	float auxPeso;
	float calculo;
	ePerrito* auxPerri= NULL;

	if(puntero != NULL)
	{
		auxPerri = (ePerrito*)puntero;
		auxPeso = auxPerri->peso;
		calculo = auxPeso * 23;
		perro_setRacion(auxPerri, calculo);
		retorno = 0;
	}
	return retorno;
}
