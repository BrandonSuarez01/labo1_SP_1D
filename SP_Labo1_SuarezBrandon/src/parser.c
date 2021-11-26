#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Perro.h"
#include "parser.h"
#include "Control.h"

int parser_perrosDesdeTexto(FILE* pFile , LinkedList* pArrayPerros)
{
	int retorno = -1;
	char nombre[TAMNOM];
	char raza[TAMNOM];
	char edad[TAMNOM];
	char id[TAMNOM];
	char peso[TAMNOM];

	fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %[^\n]\n",id ,nombre, peso , edad, raza);

	while(!feof(pFile))
	{
		fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %[^\n]\n",id ,nombre, peso , edad, raza);
		ePerrito* unPerro = perro_construcParam(id, nombre, peso, edad,  raza);
		ll_add(pArrayPerros, unPerro);
		retorno = 0;
	}
	fclose(pFile);
	pFile = NULL;

	return retorno;
}

