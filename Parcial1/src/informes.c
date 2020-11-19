/*
 * informes.c
 *
 *  Created on: Nov 18, 2020
 *      Author: david
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "utnInputs.h"
#include "informes.h"

#define NAMELIMIT 51
#define MAX 5

//"1- Mostrar Electrodomesticos del anio(modelo) 2020 \n"
int mostrarElectroAnio(Electro *pElectro, Electro *pElectro2020, Marca *pMarca, int limite, int anio)
{
	int retorno = -1;
	int i;
	int resultadoPrintElectro=0;

		for (i = 0; i < limite; i++)
		{
			if(pElectro[i].modelo == anio && pElectro[i].isEmpty == 0)
			{
				pElectro2020[i].id = pElectro[i].id;
				pElectro2020[i].serie = pElectro[i].serie;
				pElectro2020[i].idMarca = pElectro[i].idMarca;
				pElectro2020[i].modelo = pElectro[i].modelo;
				pElectro2020[i].isEmpty = pElectro[i].isEmpty;
				retorno = 0;
			}
		}

		resultadoPrintElectro = printElectro(pElectro2020, pMarca, limite);
		if (resultadoPrintElectro != 0) {
			printf("\nError mostrando los electrodomesticos.\n");
			system("pause");
		}
		initElectro(pElectro2020, limite);
		system("pause");

		return retorno;

}

//"2- Mostrar Electrodomesticos de una marca seleccionada\n"
int mostrarElectroMarca(Electro *pElectro, Marca *pMarca, Electro *pElectroMarca, int limite)
{
	int retorno = -1;
	int i;
	int inputMarca;
	int resultadoPrintElectro;
	int resultadoPrintMarca;

	resultadoPrintMarca = printMarca(pMarca,limite);
	if (resultadoPrintMarca != 0)
	{
		printf("\nError mostrando las marcas.\n");
		system("pause");
	}
	getInt(&inputMarca, "\nIngrese el ID de marca: ",
			"\nERROR: Ingrese un ID valido", 1000, 1004, 10);

	for (i = 0; i < limite; i++)
	{
		if(pElectro[i].idMarca == inputMarca && pElectro[i].isEmpty == 0)
		{
			pElectroMarca[i].id = pElectro[i].id;
			pElectroMarca[i].serie = pElectro[i].serie;
			pElectroMarca[i].idMarca = pElectro[i].idMarca;
			pElectroMarca[i].modelo = pElectro[i].modelo;
			pElectroMarca[i].isEmpty = pElectro[i].isEmpty;
			retorno = 0;
		}
	}

	resultadoPrintElectro = printElectro(pElectroMarca, pMarca, limite);
	if (resultadoPrintElectro != 0) {
		printf("\nError mostrando los electrodomesticos.\n");
		system("pause");
	}

	initElectro(pElectroMarca, MAX);
	system("pause");

	return retorno;
}

//"3- Mostrar todos las reparaciones efectuadas al Electrodoméstico seleccionado \n"
int repElectroSelecc(Reparacion *pArray, Electro *pElectro, Servicio *pServicio, Cliente *pCliente, Reparacion *pRepElec, int limite)
{
	int retorno = -1;
	int i;
	int inputIDElectro;
	int resultadoPrintRep;


	getInt(&inputIDElectro, "\nIngrese el ID del Electrodomestico: ",
			"\nERROR: Ingrese un ID valido", 1, limite, 10);

	for (i = 0; i < limite; i++)
	{
		if(pElectro[i].id == inputIDElectro && pElectro[i].isEmpty == 0)
		{
			pRepElec[i].id = pArray[i].id;
			pRepElec[i].serie = pArray[i].serie;
			pRepElec[i].idCliente = pArray[i].idCliente;
			pRepElec[i].idServicio = pArray[i].idServicio;
			pRepElec[i].fecha = pArray[i].fecha;
			pRepElec[i].isEmpty = 0;
			retorno = 0;
		}
	}

	resultadoPrintRep = printRep(pRepElec, pCliente, pServicio, limite);
	if (resultadoPrintRep != 0) {
		printf("\nError mostrando los electrodomesticos.\n");
		system("pause");
	}

	initRep(pRepElec, limite);
	system("pause");

	return retorno;
}

//"4- Listar los Electrodomésticos que no tuvieron reparaciones  \n"
int mostrarElectroSinRep(Electro *pElectro, Reparacion *pRep, Marca *pMarca, Electro *pElectroSinRep, int limite)
{
	int retorno = -1;
	int i;
	int resultadoPrintElectro;
	int respFindElectroBySerie=0;


	for (i = 0; i < limite; i++)
	{
		respFindElectroBySerie = findElectroBySerie(pElectro, limite, pRep[i].serie);
		if (respFindElectroBySerie == -1){
		if(pElectro[i].serie != pRep[i].serie && pElectro[i].isEmpty == 0)
		{
			pElectroSinRep[i].id = pElectro[i].id;
			pElectroSinRep[i].serie = pElectro[i].serie;
			pElectroSinRep[i].idMarca = pElectro[i].idMarca;
			pElectroSinRep[i].modelo = pElectro[i].modelo;
			pElectroSinRep[i].isEmpty = pElectro[i].isEmpty;
			retorno = 0;
		}
		}
	}

	resultadoPrintElectro = printElectro(pElectroSinRep, pMarca, limite);
	if (resultadoPrintElectro != 0) {
		printf("\nError mostrando los electrodomesticos.\n");
		system("pause");
	}

	initElectro(pElectroSinRep, MAX);
	system("pause");


	return retorno;
}

//"5- Informar importe total de las reparaciones realizadas a un Electrodoméstico seleccionado  \n"
int informeTotalRep(Reparacion *pArray, Electro *pElectro, Servicio *pServicio, Reparacion *pInformeTotalRep, int limite)
{
	int retorno = -1;
	int i;
	int inputElectro;
	int acumPrecio=0;
	int resElectrobyID;
	int flagError=0;

	int servs=0;
	int ser=0;


	getInt(&inputElectro, "\nIngrese el ID del electrodomestico: ",
			"\nERROR: Ingrese un ID valido", 1, limite, 10);

	resElectrobyID = findElectroById(pElectro, limite, inputElectro);
	if(resElectrobyID == -1)
	{
		flagError = 1;
		printf("\nNo hay electrodomestico con ese ID");
		system("pause");

	}
	ser = pElectro[resElectrobyID].serie;

	for (i = 0; i < limite; i++)
	{


		if(pArray[i].serie == ser)
		{
			servs = pArray[i].idServicio;
		}

		printf("\nServs: %d",pArray[i].serie);

		switch(servs)
		{
		case 20000:
			acumPrecio = acumPrecio + 250;

			break;

		case 20001:
			acumPrecio = acumPrecio + 500;
			break;

		case 20002:
			acumPrecio = acumPrecio + 400;
			break;

		case 20003:
			acumPrecio = acumPrecio + 600;
			break;

		}

	}

	if(flagError == 0){retorno = 0;}

	printf("\nSerie: %d",ser);
	printf("\nEl total de reparaciones realizadas al Electrodomestico seleccionado es de $%d\n",acumPrecio);
	system("pause");



	return retorno;
}

//"6- Mostrar el servicio más pedido \n"
int contadorServicio(Reparacion *pArray, Servicio *pServicio, int limite)
{
	int retorno = -1;
	int i;
	int j;



	int contadorServicio[limite];

	int max=-1;
	char desc[26];




	if (pArray != NULL && pServicio != NULL && limite > 0) {
			for (i = 0; i < 5; i++)
			{
				contadorServicio[i]=0;
			}
			for (i = 0; i < 5; i++)
			{
				for (j = 0; j < limite; j++)
				{
					if(pArray[j].idServicio == pServicio[i].id && pArray[j].isEmpty == 0)
					{
						contadorServicio[i]++;
					}
				}
			}

			for (i = 0; i < 5; i++)
			{
				if(max<contadorServicio[i])
				{
					max = contadorServicio[i];
					strncpy(desc,pServicio[i].servDesc,26);
				}
			}




			printf("\nEl servicio mas pedido es %s\n",desc);
			system("pause");

			retorno = 0;

		}

	return retorno;
}

//"7- Mostrar la recaudación en una fecha en particular\n"
int recaudacionPorFecha(Reparacion *pArray, int limite, Servicio *pServicio, eFecha *pFecha, int *contFecha)
{
	int ret = -1;
	int i;
	int j;
	float totalPrecio = 0;
	int resGetFecha;


	eFecha aux;

	resGetFecha = getFecha(pFecha, limite, "\nError.", 10, contFecha);
	if (resGetFecha != 0) {
		printf("\nError ingresando Fecha.\n");
		system("pause");
	}
	aux = *pFecha;

	if(pArray != NULL && limite > 0 && pServicio != NULL)
	{

		for (i = 0; i < limite; ++i){
			if(pArray[i].isEmpty==0){
				if(aux.dia == pArray[i].fecha.dia && aux.anio == pArray[i].fecha.anio && aux.mes == pArray[i].fecha.mes){
					for (j = 0; j < 4; ++j){
						if(pArray[i].idServicio == pServicio[j].id){
							totalPrecio += pServicio[j].precio;
						}
					}
				}
			}
		}

		if(totalPrecio>0){
			printf("\nEl %d/%d/%d se recaudo: $%.2f\n", aux.dia,aux.mes, aux.anio, totalPrecio);
			system("pause");
		}else{
			printf("\nNo hay recaudacion para la fecha ingresada.\n");
			system("pause");
		}


		ret=0;
	}
	return ret;
}

//"8- Mostrar todos los Electrodomésticos que realizaron una garantía y la fecha\n"
int printGarantia(Reparacion *pArray, Electro *pElectro, Cliente *pCliente, Marca *pMarca, Servicio *pServicio, int limite)
{
	int ret = -1;
	int i;
	int indiceElec;
	int serie;
	int idMarca;
	int idMarcaPos;

	if (pArray != NULL && limite > 0) {


		printf("\n__________________________________________________________________________"
		       "\n| ID:      |   Serie:      |  Marca:        | Modelo:    |  Fecha:        | "
		       "\n|__________|_______________|________________|____________|________________|\n");
		for (i = 0; i < limite; i++) {
			if (pArray[i].isEmpty != 1 && pArray[i].idServicio == 20000) {

				indiceElec = findElectroBySerie(pElectro, limite, pArray[i].serie);
				serie = pElectro[indiceElec].serie;

				idMarca = pElectro[i].idMarca;
				idMarcaPos = findMarcaById(pMarca, limite, idMarca);

				printf("|%d         |   %d       | %s        |  %d      |     %d/%d/%d      \n",
						pElectro[indiceElec].id,    serie, pMarca[idMarcaPos].marcDesc,  pElectro[indiceElec].modelo,    pArray[i].fecha.dia,pArray[i].fecha.mes,pArray[i].fecha.anio);
			}
		}
		ret = 0;
	}
	return ret;
}


//"9- Trabajos realizados a Electrodomésticos del año(modelo) 2018\n"
int mostrarTrabajosAElectro2018(Reparacion *pArray, Electro *pElectro, Servicio *pServicio, Reparacion *pTrabajosAElectro2018, int limite)
{
	int retorno = -1;
	int i;
	int idServicio;
	int idServicioPos;

	mostrarElectroAnioServ(pElectro, pTrabajosAElectro2018, pServicio, limite, 2018);

	printf("\nTrabajos realizados a electrodomesticos modelo 2018: ");
	for(i=0;i<limite;i++)
	{
		idServicio = pTrabajosAElectro2018[i].idServicio;
		idServicioPos = findServicioById(pServicio, limite, idServicio);
		printf("\n%s",pServicio[idServicioPos].servDesc);

	}

	return retorno;
}

//"10- Facturación total por los mantenimientos\n"
int recaudacionDeMant(Reparacion *pArray, int limite, Servicio *pServicio)
{
	int ret = -1;
	int i;
	int j;
	float totalPrecio = 0;



	if(pArray != NULL && limite > 0 && pServicio != NULL)
	{

		for (i = 0; i < limite; ++i){
			if(pArray[i].isEmpty==0 && pArray[i].idServicio == 20001){

					for (j = 0; j < 4; ++j){
						if(pArray[i].idServicio == pServicio[j].id){
							totalPrecio += pServicio[j].precio;
						}
					}

			}
		}

		if(totalPrecio>0){
			printf("\nLa facturacion total por los mantenimientos es: $%.2f\n", totalPrecio);
			system("pause");
		}else{
			printf("\nNo hay servicios realizados de mantenimiento.\n");
			system("pause");
		}
		ret=0;
	}
	return ret;
}



//"11- Informar la marca con mas Electrodomésticos \n"
int contadoresMarcas(Electro *pElectro, Marca *pMarca, int limite, int *contadorElectro)
{
	int retorno = -1;
	int i;
	int j;



	int max=-1;
	char descMarcaMax[21];



	if (pElectro != NULL && pMarca != NULL && limite > 0) {
			for (i = 0; i < 5; i++)
			{
				contadorElectro[i]=0;
			}
			for (i = 0; i < 5; i++)
			{
				for (j = 0; j < limite; j++)
				{
					if(pElectro[j].idMarca == pMarca[i].id && pElectro[j].isEmpty == 0)
					{
						contadorElectro[i]++;
					}
				}
			}

			for (i = 0; i < 5; i++)
			{
				if(max<contadorElectro[i])
				{
					max = contadorElectro[i];
					strncpy(descMarcaMax,pMarca[i].marcDesc,21);
				}
			}




			printf("\nLa Marca con mas electrodomesticos es %s\n",descMarcaMax);

			retorno = 0;

		}

	return retorno;
}

//"12- Informar el cliente con mas reparaciones \n"
int contadoresClientes(Reparacion *pArray, Cliente *pCliente, int limite, int *contadorCliente)
{
	int retorno = -1;
	int i;
	int j;



	int max=-1;
	char nombre[51];
	char apellido[51];



	if (pArray != NULL && pCliente != NULL && limite > 0) {
			for (i = 0; i < 5; i++)
			{
				contadorCliente[i]=0;
			}
			for (i = 0; i < 5; i++)
			{
				for (j = 0; j < limite; j++)
				{
					if(pArray[j].idCliente == pCliente[i].id && pArray[j].isEmpty == 0)
					{
						contadorCliente[i]++;
					}
				}
			}

			for (i = 0; i < 5; i++)
			{
				if(max<contadorCliente[i])
				{
					max = contadorCliente[i];
					strncpy(nombre,pCliente[i].nombre,51);
					strncpy(apellido,pCliente[i].apellido,51);
				}
			}




			printf("\nEl cliente con mas reparaciones es %s %s\n",nombre,apellido);

			retorno = 0;

		}

	return retorno;
}
