/*
 * Control.c
 *
 *  Created on: 26 nov. 2021
 *      Author: brans
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Funciones.h"
#include "Perro.h"
#include "Control.h"
#include "parser.h"

int control_cargarDesdeTexto(char* path, LinkedList* this)
{
	int retorno = -1;
	FILE* pFile;

	if(this != NULL && path != NULL)
	{
		pFile = fopen(path, "r");
		parser_perrosDesdeTexto(pFile, this);
		retorno = 0;
	}

	return retorno;
}
int control_listarArray(LinkedList* this)
{
	int retorno = -1;
	int tam = ll_len(this);
	int i;
	int auxEdad;
	int auxId;
	float auxPeso;
	char auxNombre[TAMNOM];
	char auxRaza[TAMNOM];

	ePerrito* unPerro = NULL;

	if(this != NULL)
	{
		printf("%-10s - %-20s - %-20s - %-20s - %-20s\n", "ID", "NOMBRE", "PESO", "EDAD", "RAZA");

		for(i = 0; i < tam; i++)
		{
			unPerro = (ePerrito*) ll_get(this, i);

			auxId = perro_getId(unPerro);
			auxPeso = perro_getPeso(unPerro);
			auxEdad = perro_getEdad(unPerro);
			perro_getNombre(unPerro, auxNombre);
			perro_getRaza(unPerro, auxRaza);
			printf("%-10d - %-20s - %-20.2f - %-20d - %-20s\n",auxId, auxNombre, auxPeso , auxEdad, auxRaza);
		}

	}
	return retorno;
}
int control_listarPerrosOrdenados(LinkedList* this)
{
	int retorno = -1;
	int (*pFuncion)(void*, void*);

	if(this != NULL)
	{
		pFuncion = perro_ordenarPorNombre;
		ll_sort(this, pFuncion, 1);
		control_listarArray(this);
		retorno = 0;
	}
	return retorno;
}
int control_agregarRacion(LinkedList* this)
{
	int retorno = -1;
	int (*pFuncion)(void*);

	if(this != NULL)
	{
		pFuncion = perro_laQueMapea;
		ll_map(this, pFuncion);
		retorno = 0;
	}
	return retorno;
}
int control_listarArrayConRacion(LinkedList* this)
{
	int retorno = -1;
	int tam = ll_len(this);
	int i;
	int auxEdad;
	int auxId;
	float auxPeso;
	float auxRacion;
	char auxNombre[TAMNOM];
	char auxRaza[TAMNOM];

	ePerrito* unPerro = NULL;

	if(this != NULL)
	{
		printf("%-10s - %-20s - %-20s - %-20s - %-20s - %-20s\n", "ID", "NOMBRE", "PESO", "EDAD", "RAZA", "RACION");

		for(i = 0; i < tam; i++)
		{
			unPerro = (ePerrito*) ll_get(this, i);

			auxId = perro_getId(unPerro);
			auxPeso = perro_getPeso(unPerro);
			auxEdad = perro_getEdad(unPerro);
			auxRacion = perro_getRacion(unPerro);
			perro_getNombre(unPerro, auxNombre);
			perro_getRaza(unPerro, auxRaza);
			printf("%-10d - %-20s - %-20.2f - %-20d - %-20s - %-20.2f\n",auxId, auxNombre, auxPeso , auxEdad, auxRaza, auxRacion);
		}

	}
	return retorno;
}
LinkedList* control_filtrarGalgosFlacos(LinkedList* this)
{
	LinkedList* galgosFlacos = NULL;
	int (*pFuncion)(void*);


	if(this != NULL)
	{
		pFuncion = perro_laQueFiltra;
		galgosFlacos = ll_filter(this, pFuncion);
		control_listarArrayConRacion(galgosFlacos);
	}
	return galgosFlacos;
}
int control_guardarGalgosFlacos(char* path, LinkedList* this)
{
	int retorno = -1;
	int i;
	int tam;
	int auxEdad;
	int auxId;
	float auxPeso;
	float auxRacion;
	char auxNombre[TAMNOM];
	char auxRaza[TAMNOM];

	FILE* pFile = NULL;
	ePerrito* unPerrito = NULL;

	if(path != NULL)
	{
		pFile = fopen(path, "w");
		tam = ll_len(this);
		for(i = 0; i < tam; i++)
		{
			 unPerrito = (ePerrito*)ll_get(this, i);
			 auxId = perro_getId(unPerrito);
			 auxPeso = perro_getPeso(unPerrito);
			 auxEdad = perro_getEdad(unPerrito);
			 auxRacion = perro_getRacion(unPerrito);
			 perro_getNombre(unPerrito, auxNombre);
			 perro_getRaza(unPerrito, auxRaza);

			fprintf(pFile, "%d, %s, %.2f, %d, %s, %.2f\n", auxId, auxNombre, auxPeso, auxEdad, auxRaza, auxRacion);
		}
		retorno = 0;
		fclose(pFile);
		pFile = NULL;
		printf("\nArchivo guardado con exito!\n");
	}

	return retorno;
}
