/*
 * reparacion.c
 *
 *  Created on: Oct 15, 2020
 *      Author: david
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "reparacion.h"
#include "electrodomestico.h"
#include "servicio.h"
#include "utnInputs.h"
#include "marca.h"
#include "fecha.h"

int altaReparacion(Reparacion *pArray, Electro *pElectro, Servicio *pServicio, eFecha *pFecha, int limite, int *contRep, int *contFecha) {

	int resultadoAddRep = 0;
	int resultadoGetFecha = 0;
	int retorno = -1;


	int auxId=0;
	int serie;


	int idElectro;
	int residElectro=0;
	int idServicio;
	int residServicio=0;
	int indiceElec;

	;



	if (pArray != NULL && limite > 0){



	do{
		if(residElectro!=0){
			printf("\nError, ID invalido: ");
		}
	printf("\nIngrese el ID del Electrodomestico: ");
	scanf("%d", &idElectro);
	residElectro = checkElectro(pElectro, limite, idElectro);
	}while (residElectro!=0);

	do{
		if(residServicio!=0){
			printf("\nError, ID invalido: ");
		}
	printf("\nIngrese el ID del Servicio: ");
	scanf("%d", &idServicio);
	residServicio = checkServicio(pServicio, limite, idServicio);
	}while (residServicio!=0);

	indiceElec = findElectroById(pElectro, limite, idElectro);

	serie = pElectro[indiceElec].serie;

	resultadoGetFecha = getFecha(pFecha, limite, "\nError.", 10, contFecha);
	if (resultadoGetFecha != 0) {
		printf("\nError ingresando Fecha.\n");
		system("pause");
	}

	resultadoAddRep = addRep(pArray, limite, auxId, serie, idServicio, pFecha, contRep);

	if (resultadoAddRep != 0) {
		printf("\nError agregando reparacion.\n");
		system("pause");
	} else {

		retorno = 0;
		system("pause");
	}
}

	return retorno;

}

int checkElectro(Electro *pElectro, int limite, int inputElectro)
{
	int retorno = -1;
	int i;

	if (pElectro != NULL && limite > 0) {
			for (i = 0; i < limite; i++) {
				if (pElectro[i].id == inputElectro) {
					retorno = 0;
					break;
				}
			}
		}


	return retorno;
}

int checkServicio(Servicio *pServicio, int limite, int inputServicio)
{
	int retorno = -1;
	int i;

	if (pServicio != NULL && limite > 0) {
			for (i = 0; i < limite; i++) {
				if (pServicio[i].id == inputServicio) {
					retorno = 0;
					break;
				}
			}
		}


	return retorno;
}

int addRep(Reparacion *pArray, int limite, int id, int serie, int idServicio, eFecha *fecha, int *contReparacion) {
	int retorno = -1;
	int i;
	int contador = *contReparacion;

	if (findEmptyR(pArray, limite, &i) == 0) {
		contador++;
		*contReparacion = contador;

		pArray[i].id = *contReparacion;
		pArray[i].serie = serie;
		pArray[i].idServicio = idServicio;
		pArray[i].fecha.dia = fecha[i].dia;
		pArray[i].fecha.mes = fecha[i].mes;
		pArray[i].fecha.anio = fecha[i].anio;
		pArray[i].isEmpty = 0;

		retorno = 0;

	} else {
		retorno = -1;
		printf("\nNo hay espacio para mas empleados.");
	}

	return retorno;
}

int printRep(Reparacion *pArray, int limite) {
	int retorno = -1;
	int i;
	if (pArray != NULL && limite > 0) {
		printf("\n_______________________________________________________________________");
		printf("\n| ID:      |   Serie:      |    ID Servicio:      |      Fecha:        | ");
		printf("\n|__________|_______________|______________________|____________________|\n");
		for (i = 0; i < limite; i++) {
			if (pArray[i].isEmpty != 1) {
				printf("|%d         |   %d       |       %d          |     %d/%d/%d      \n",
							pArray[i].id,    pArray[i].serie,      pArray[i].idServicio,       pArray[i].fecha.dia,pArray[i].fecha.mes,pArray[i].fecha.anio);
			}
		}
		retorno = 0;
	}
	return retorno;
}

int initRep(Reparacion *pArray, int limite) {
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
