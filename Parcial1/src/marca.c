/*
 * marca.c
 *
 *  Created on: Oct 15, 2020
 *      Author: david
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "marca.h"

int printMarca(Marca *pArray, int limite) {
	int retorno = -1;
	int i;
	if (pArray != NULL && limite > 0) {
		printf("\n______________________________");
		printf("\n| ID:      |  Descripcion:    | ");
		printf("\n|__________|__________________|\n");
		for (i = 0; i < limite; i++) {
			if (pArray[i].isEmpty != 1) {
				printf("|          |                  |\n|%d      |   %s        |\n",
							pArray[i].id,    pArray[i].marcDesc);
			}
		}
		retorno = 0;
	}
	return retorno;
}
