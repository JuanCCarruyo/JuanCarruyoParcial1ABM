/*
 * electrodomestico.c
 *
 *  Created on: Oct 15, 2020
 *      Author: david
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "electrodomestico.h"
#include "utnInputs.h"
#include "marca.h"

#define NAMELIMIT 51
#define MAX 5

int altaElectro(Electro *pArray, Marca *pMarca, int limite, int *contElectro) {

	int resultadoAddElectro = 0;
	int retorno = -1;


	int auxId=0;
	int serie;
	int idMarca;
	int modelo;
	int rescheckMarca;



	if (pArray != NULL && limite > 0){



	getInt(&serie, "\nIngrese el numero de serie: ",
			"\nERROR: Serie debe ser de 5 digitos", 10000, 99999, 10);

	do{
	printf("\nIngrese el ID de la marca: ");
	scanf("%d", &idMarca);
	rescheckMarca = checkMarca(pMarca, limite, idMarca);
	}while (rescheckMarca!=0);


	getInt(&modelo, "\nIngrese el modelo (anio de fabricacion): ",
			"\nERROR: Ingrese un modelo valido", 1990, 2020, 10);

	resultadoAddElectro = addElectro(pArray, limite, auxId, serie, idMarca,
			modelo, contElectro);

	if (resultadoAddElectro != 0) {
		printf("\nError agregando electrodomestico.\n");
		system("pause");
	} else {

		retorno = 0;
		system("pause");
	}
}

	return retorno;

}

int checkMarca(Marca *pArray, int limite, int inputMarca)
{
	int retorno = -1;
	int i;

	if (pArray != NULL && limite > 0) {
			for (i = 0; i < limite; i++) {
				if (pArray[i].id == inputMarca) {
					retorno = 0;
					break;
				}
			}
		}


	return retorno;
}


int addElectro(Electro *pArray, int limite, int id, int serie, int idMarca, int modelo, int *contElectro) {
	int retorno = -1;
	int i;
	int contador = *contElectro;

	if (findEmptyE(pArray, limite, &i) == 0) {
		contador++;
		*contElectro = contador;

		pArray[i].id = *contElectro;
		pArray[i].serie = serie;
		pArray[i].idMarca = idMarca;
		pArray[i].modelo = modelo;
		pArray[i].isEmpty = 0;

		retorno = 0;

	} else {
		retorno = -1;
		printf("\nNo hay espacio para mas empleados.");
	}

	return retorno;
}

int printElectro(Electro *pArray, int limite) {
	int retorno = -1;
	int i;
	if (pArray != NULL && limite > 0) {
		printf("\n____________________________________________________________________");
		printf("\n| ID:      |     Serie:    |     ID Marca:     |    Modelo:      ||| ");
		printf("\n|__________|_______________|___________________|_________________|||\n");
		for (i = 0; i < limite; i++) {
			if (pArray[i].isEmpty != 1) {
				printf("|%d         |   %d       |       %d        |     %d    \n",
							pArray[i].id,    pArray[i].serie,      pArray[i].idMarca,       pArray[i].modelo);
			}
		}
		retorno = 0;
	}
	return retorno;
}

int initElectro(Electro *pArray, int limite) {
	int retorno = -1;
	int i;

	if (pArray != NULL && limite > 0) {
		for (i = 0; i < limite; i++) {
			pArray[i].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
}

int removeElectro(Electro *pArray, int limite, int id) {
	int retorno = -1;

	if (pArray != NULL && limite > 0) {
		pArray[id].isEmpty = 1;
		retorno = 0;
	}
	return retorno;
}

int findElectroById(Electro *pArray, int limite, int id) {
	int retorno = -1;
	int i;
	int flag = 0;

	if (pArray != NULL && limite > 0){
	for (i = 0; i < limite; i++) {
		if (pArray[i].isEmpty != 1) {
			if (pArray[i].id == id) {
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

int modifyElectro(Electro* pArray, int indice)
{
	int retorno = -1;
	int modSeleccion;
	int resultadoModSeleccion = 0;


	int inputSerie;
	int inputModelo;

	if (pArray != NULL) {
	resultadoModSeleccion = getInt(&modSeleccion, "\nSeleccione el campo a modificar\n"
					"1- SERIE \n"
					"2- MODELO \n"
					"Ingrese Opcion: \n",
					"\nError: Seleccione una opcion valida.\n", 1, 2, 10);

	if (resultadoModSeleccion != 0)
	{
		printf("\nError ingresando una opcion.\n");
		system("pause");
	}
	else{
	switch(modSeleccion)
	{
	case 1:

		getInt(&inputSerie, "\nIngrese el numero de serie: ",
				"\nERROR: Serie debe ser de 5 digitos", 10000, 99999, 10);
		pArray[indice].serie = inputSerie;
		retorno = 0;
		break;

	case 2:

		getInt(&inputModelo, "\nIngrese el modelo (anio de fabricacion): ",
				"\nERROR: Ingrese un modelo valido", 1990, 2020, 10);
		pArray[indice].modelo = inputModelo;
		retorno = 0;
		break;
	}
	}
}
	return retorno;

}

int sortElectro(Electro *pArray, int limite, int orden) {
	int retorno = -1;
	int i = 0;
	int j = 0;
	Electro aux;

	if (pArray != NULL && limite > 0) {
		switch (orden) {
		case 1: //ascendente
			for (i = 0; i < limite - 1; i++) {
				for (j = i + 1; j < limite; j++) {
					if (pArray[j].modelo < pArray[i].modelo) {
						aux = pArray[j];
						pArray[j] = pArray[i];
						pArray[i] = aux;
					}

					else if (pArray[j].modelo < pArray[i].modelo
							&& pArray[j].serie < pArray[i].serie) {
						aux = pArray[j];
						pArray[j] = pArray[i];
						pArray[i] = aux;
					}
				}
			}
			break;

		}
		retorno = 0;
	}
	return retorno;
}
