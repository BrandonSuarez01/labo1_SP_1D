/*
 * Control.h
 *
 *  Created on: 26 nov. 2021
 *      Author: brans
 */

#ifndef CONTROL_H_
#define CONTROL_H_

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Funciones.h"
#include "Perro.h"

int control_cargarDesdeTexto(char* path, LinkedList* this);
int control_listarArray(LinkedList* this);
int control_listarPerrosOrdenados(LinkedList* this);

#endif /* CONTROL_H_ */
