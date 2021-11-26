/*
 * parser.h
 *
 *  Created on: 5 nov. 2021
 *      Author: brans
 */

#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Perro.h"


int parser_perrosDesdeTexto(FILE* pFile , LinkedList* pArrayPerros);


#endif /* PARSER_H_ */
