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
	int flagOrder = 0;
	int flagRacion = 0;
	int flagFiltro = 0;

	LinkedList* pArrayPerros = ll_newLinkedList();
	LinkedList* galgosFlacos = NULL;

	do
	{
		obtenerNumeroValido(&opcion, "------------MENU------------\n"
									 "1. Cargar los datos.\n"
									 "2. Listar en orden ascendente\n"
									 "3. Calcular cantidad de racion.\n"
									 "4. Listar perros con racion.\n"
				 	 	 	 	 	 "5. Filtrar galgos flacos.\n"
									 "6. Guardar galgos flacos.\n"
									 "7. Salir.\n"
									 "----------------------------\n"
									 "Ingrese la opcion deseada: "
									, "------------MENU------------\n"
									 "1. Cargar los datos.\n"
									 "2. Listar en orden ascendente\n"
									 "3. Calcular cantidad de racion.\n"
									 "4. Listar perros con racion.\n"
									 "5. Filtrar galgos flacos.\n"
									 "6. Guardar galgos flacos.\n"
									 "7. Salir.\n"
									 "----------------------------\n"
									 "ERROR - Reingrese la opcion deseada: ", 1, 7);

		switch(opcion)
		{
			case 1 :
				if(!control_cargarDesdeTexto("src//perritos.csv", pArrayPerros))
				{
					systemPause("Cargando, espere.... Presione cualquier tecla para continuar...\n");
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
					systemPause("Listando, espere... Presione cualquier tecla para continuar...\n");
					control_listarPerrosOrdenados(pArrayPerros);
					printf("Listado correctamente...\n");
					flagOrder = 1;
				}
				else
				{
					printf("\nERROR - Aun no se ha cargado ninguna lista.\n");
				}
			break;
			case 3 :
				if(flagCarga == 1 && flagOrder == 1)
				{
					if(!control_agregarRacion(pArrayPerros))
					{
						systemPause("Calculando raciones, espere.... Presione cualquier tecla para continuar...\n");
						printf("\nRaciones calculadas y agregadas correctamente.\n");
						flagRacion = 1;
					}
				}
				else
				{
					printf("\nERROR - Aun no se ha cargado ninguna lista o no se ha ordenado.\n");
				}
			break;
			case 4 :
				if(flagCarga == 1 && flagRacion == 1 && flagOrder == 1)
				{
					systemPause("Listando, espere.... Presione cualquier tecla para continuar...\n");
					control_listarArrayConRacion(pArrayPerros);
				}
				else
				{
					printf("\nERROR - Aun no se ha cargado ninguna lista, no se calculo la racion o no se ordeno.\n");
				}
			break;
			case 5 :
				if(flagCarga == 1 && flagRacion == 1 && flagOrder == 1)
				{
					systemPause("Filtrando, espere.... Presione cualquier tecla para continuar...\n");
					galgosFlacos = control_filtrarGalgosFlacos(pArrayPerros);
					flagFiltro = 1;
				}
				else
				{
					printf("\nERROR - Aun no se ha cargado ninguna lista, no se calculo la racion o no se ordeno previamente.\n");
				}
			break;
			case 6 :
				if(flagFiltro == 1)
				{
					systemPause("Guardando en un archivo, espere.... Presione cualquier tecla para continuar...\n");
					control_guardarGalgosFlacos("galgosFlaquitos.csv", galgosFlacos);
				}
				else
				{
					printf("\nERROR - Aun no se filtraron los galgos.\n");
				}
			break;
			case 7 :
				printf("Finalizando programa...\n");
				systemPause("Limpiando, espere.... Presione cualquier tecla para continuar...\n");
				ll_clear(pArrayPerros);
				ll_clear(galgosFlacos);
				printf("Adios");
			break;
		}
	}while(opcion != 7);

	return EXIT_SUCCESS;
}
