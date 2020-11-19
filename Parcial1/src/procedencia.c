/*
 * procedencia.c
 *
 *  Created on: Nov 19, 2020
 *      Author: david
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "procedencia.h"


void harcodeoProcedencia(Procedencia *pArray, int limite)
{
	int i;
	int idPais[4]={1,2,3,4};
	char nombrePais[][51]={"Argentina","China  ","Taiwan  ","EEUU  "};

	for (i = 0; i < 4; i++){

		pArray[i].idPais=idPais[i];
		strcpy(pArray[i].nombrePais,nombrePais[i]);
		pArray[i].isEmpty = 0;
	}
}

int printProcedencia(Procedencia *pArray, int limite){
	int retorno = -1;
	int i;
	if (pArray != NULL && limite > 0) {
		printf("\n________________________________");
		printf("\n| ID:      | Pais:             | ");
		printf("\n|__________|___________________|\n");
		for (i = 0; i < limite; i++) {
			if (pArray[i].isEmpty != 1) {
				printf("|%d         | %s      \n",
						pArray[i].idPais,pArray[i].nombrePais);
			}
		}
		retorno = 0;
	}
	return retorno;
}

int findPaisById(Procedencia *pArray, int limite, int id) {
	int retorno = -1;
	int i;
	int flag = 0;

	if (pArray != NULL && limite > 0){
	for (i = 0; i < limite; i++) {
		if (pArray[i].isEmpty != 1) {
			if (pArray[i].idPais == id) {
				flag = 1;
				retorno = i;
				break;
			}
		}
	}}

	if (flag == 0) {
		retorno = -1;
	}

	return retorno;
}

