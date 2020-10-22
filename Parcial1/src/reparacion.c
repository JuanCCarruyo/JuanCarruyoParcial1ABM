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
#include "cliente.h"

int altaReparacion(Reparacion *pArray, Electro *pElectro, Servicio *pServicio, eFecha *pFecha, Cliente *pCliente, int limite, int *contRep, int *contFecha) {

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

	int idCliente;
	int residCliente=0;
//	int indiceCliente;


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

	do{
		if(residCliente!=0){
			printf("\nError, ID invalido: ");
		}
	printf("\nIngrese el ID del Cliente: ");
	scanf("%d", &idCliente);
	residCliente = checkCliente(pCliente, limite, idCliente);
	}while (residCliente!=0);

	indiceElec = findElectroById(pElectro, limite, idElectro);
	serie = pElectro[indiceElec].serie;


//	indiceCliente = findClienteById(pCliente, limite, idCliente);



	resultadoGetFecha = getFecha(pFecha, limite, "\nError.", 10, contFecha);
	if (resultadoGetFecha != 0) {
		printf("\nError ingresando Fecha.\n");
		system("pause");
	}

	resultadoAddRep = addRep(pArray, limite, auxId, serie, idCliente, idServicio, pFecha, contRep);

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


int addRep(Reparacion *pArray, int limite, int id, int serie, int idCliente, int idServicio, eFecha *fecha, int *contReparacion) {
	int retorno = -1;
	int i;
	int contador = *contReparacion;

	if (findEmptyR(pArray, limite, &i) == 0) {
		contador++;
		*contReparacion = contador;

		pArray[i].id = *contReparacion;
		pArray[i].serie = serie;
		pArray[i].idCliente = idCliente;
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

int printRep(Reparacion *pArray, Cliente *pCliente, Servicio *pServicio, int limite){
	int retorno = -1;
	int i;
	int idCliente;
	int idClientePos;
	int idServicio;
	int idServicioPos;



	if (pArray != NULL && limite > 0) {
		printf("\n___________________________________________________________________________________________________________");
		printf("\n| ID:      |   Serie:      |  Nombre:     |   Apellido:        |  Servicio:           |      Fecha:        | ");
		printf("\n|__________|_______________|______________|____________________|______________________|____________________|\n");
		for (i = 0; i < limite; i++) {
			if (pArray[i].isEmpty != 1) {

				idCliente = pArray[i].idCliente;
				idClientePos = findClienteById(pCliente, limite, idCliente);

				idServicio = pArray[i].idServicio;
				idServicioPos = findServicioById(pServicio, limite, idServicio);


				printf("|%d         |   %d       |  %s    |  %s       |   %s      |     %d/%d/%d      \n",
					pArray[i].id,    pArray[i].serie,   pCliente[idClientePos].nombre,pCliente[idClientePos].apellido,   pServicio[idServicioPos].servDesc,       pArray[i].fecha.dia,pArray[i].fecha.mes,pArray[i].fecha.anio);
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

int findEmptyR(Reparacion *pArray, int limite, int *pos) {
	int retorno = -1;
	int i;

	if (pArray != NULL && limite > 0 && pos != NULL) {
		for (i = 0; i < limite; i++) {
			if (pArray[i].isEmpty == 1) {
				retorno = 0;
				*pos = i;
				break;
			}
		}
	}

	return retorno;
}
