/*
Suarez Brandon.
Segundo parcial laboratorio 1.
*/

#include <stdio.h>
#include <stdlib.h>
#include "Perro.h"
#include "Control.h"
#include "LinkedList.h"

int main(void)
{
	setbuf(stdout, NULL);
	int opcion = 0;
	int flagCarga = 0;

	LinkedList* pArrayPerros = ll_newLinkedList();

	do
	{
		obtenerNumeroValido(&opcion, "------------MENU------------\n"
									 "1. Cargar los datos.\n"
									 "2. Listar en orden ascendente\n"
									 //"3. Calcular cantidad de racion.\n"
									 "3. Salir.\n"
									 "----------------------------\n"
									 "Ingrese la opcion deseada: "
									, "------------MENU------------\n"
									 "1. Cargar los datos.\n"
									 "2. Listar en orden ascendente\n"
									 //"3. Calcular cantidad de racion.\n"
									 "3. Salir.\n"
									 "----------------------------\n"
									 "ERROR - Reingrese la opcion deseada: ", 1, 3);

		switch(opcion)
		{
			case 1 :
				if(!control_cargarDesdeTexto("src//perritos.csv", pArrayPerros))
				{
					printf("Se cargo la lista correctamente...\n");
					flagCarga = 1;
				}
				else
				{
					printf("ERROR.\n");
				}
			break;
			case 2 :
				if(flagCarga == 1)
				{
					control_listarPerrosOrdenados(pArrayPerros);
				}
				else
				{
					printf("\nERROR - Aun no se ha cargado ninguna lista.\n");
				}
			break;
			case 3 :
			break;
		}
	}while(opcion != 3);

	return EXIT_SUCCESS;
}
