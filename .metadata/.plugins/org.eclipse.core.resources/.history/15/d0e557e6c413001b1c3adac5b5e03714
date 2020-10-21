/*
 * servicio.c
 *
 *  Created on: Oct 15, 2020
 *      Author: david
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "servicio.h"

int printServicio(Servicio *pArray, int limite) {
	int retorno = -1;
	int i;
	if (pArray != NULL && limite > 0) {
		printf("\n___________________________________");
		printf("\n| Descripcion:      |  Precio:    | ");
		printf("\n|___________________|_____________|\n");
		for (i = 0; i < limite; i++) {
			if (pArray[i].isEmpty != 1) {
				printf("|%s      |  $%.2f    |\n",
							pArray[i].servDesc,    pArray[i].precio);
			}
		}
		retorno = 0;
	}
	return retorno;
}
