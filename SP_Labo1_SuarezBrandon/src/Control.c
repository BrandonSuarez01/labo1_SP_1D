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

	pFuncion = perro_ordenarPorNombre;
	ll_sort(this, pFuncion, 1);
	control_listarArray(this);


	return retorno;
}
