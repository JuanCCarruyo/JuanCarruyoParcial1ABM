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

#include "utnInputs.h"
#include "electrodomestico.h"
#include "marca.h"


#define NAMELIMIT 51
#define MAX 5

void harcodeoElectro(Electro *pArray,int limite)
{
	int i;
	int id[5]={1,2,3,4,5};
	int serie[5]={11111,22222,42003,44444,55555};
	int idMarca[5]={1000,1001,1001,1003,1004};
	int modelo[5]={1990,2018,2020,2018,2020};
	int idPais[5]={3,2,2,2,4};

	for (i = 0; i < 5; i++){

		pArray[i].id=id[i];
		pArray[i].serie=serie[i];
		pArray[i].idMarca=idMarca[i];
		pArray[i].modelo=modelo[i];
		pArray[i].idPais = idPais[i];

		pArray[i].isEmpty = 0;
	}
}

int altaElectro(Electro *pArray, Marca *pMarca, Procedencia *pProcedencia, int limite, int *contElectro) {

	int resultadoAddElectro = 0;
	int resultadoPrintMarca = 0;
	int retorno = -1;


	int auxId=0;
	int serie;
	int idMarca;
	int modelo;
	int rescheckMarca=0;

	int idPais=0;
	int resultadoPrintProcedencia;
	int rescheckPais=0;



	if (pArray != NULL && limite > 0){



	getInt(&serie, "\nIngrese el numero de serie: ",
			"\nERROR: Serie debe ser de 5 digitos", 10000, 99999, 10);

	do{
		if(rescheckMarca != 0){
			printf("\nError, ingrese un ID valido: ");
			system("pause");
			rescheckMarca = 0;
		}
	resultadoPrintMarca = printMarca(pMarca,limite);
	if (resultadoPrintMarca != 0)
	{
		printf("\nError mostrando las marcas.\n");
		system("pause");
	}

	rescheckMarca = getInt(&idMarca, "\nIngrese el ID de la marca: ",
				"\nERROR: Seleccione una marca valida", 1000, 1004, 10);

	}while (rescheckMarca!=0);


	getInt(&modelo, "\nIngrese el modelo (anio de fabricacion): ",
			"\nERROR: Ingrese un modelo valido", 1990, 2020, 10);


	do{
		if(rescheckPais != 0){
			printf("\nError, ingrese un ID valido: ");
			system("pause");
			rescheckPais = 0;
		}
		resultadoPrintProcedencia = printProcedencia(pProcedencia,4);
		if (resultadoPrintProcedencia != 0)
		{
			printf("\nError mostrando los paises.\n");
			system("pause");
		}

		rescheckPais = getInt(&idPais, "\nIngrese el ID del pais de procedencia: ",
					"\nERROR: Seleccione un ID valido", 1, 4, 10);

		}while (rescheckPais!=0);

	resultadoAddElectro = addElectro(pArray, limite, auxId, serie, idMarca,
			modelo, idPais, contElectro);

	if (resultadoAddElectro != 0) {
		printf("\nError agregando electrodomestico.\n");
		system("pause");
	} else {
		retorno = 0;
		printf("\nAlta realizada con exito.\n");
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
int addElectro(Electro *pArray, int limite, int id, int serie, int idMarca, int modelo, int idPais, int *contElectro) {
	int retorno = -1;
	int i;
	int contador = *contElectro;


	for (i = 0;i<limite;i++)
	{
		if (pArray[i].isEmpty == 1)
		{
			pArray[i].id = contador;
			pArray[i].serie = serie;
			pArray[i].idMarca = idMarca;
			pArray[i].modelo = modelo;
			pArray[i].idPais = idPais;
			pArray[i].isEmpty = 0;

			retorno = 0;
			contador++;
			*contElectro = contador;
			break;
		}

	}
/*
	if (findEmptyE(pArray, limite, &i) == 0) {


		pArray[i].id = i;
		pArray[i].serie = serie;
		pArray[i].idMarca = idMarca;
		pArray[i].modelo = modelo;
		pArray[i].isEmpty = 0;

		retorno = 0;

	} else {
		retorno = -1;
		printf("\nNo hay espacio para mas empleados.");
	}
*/
	return retorno;
}

int printElectro(Electro *pArray, Marca *pMarca, Procedencia *pProcedencia, int limite) {
	int retorno = -1;
	int i;
	int idMarca;
	int idMarcaPos;

	int idProcedencia;
	int idProcedenciaPos;

	if (pArray != NULL && limite > 0) {
		printf("\n_________________________________________________________________________________");
		printf("\n| ID:      |  Serie:       | Marca:         | Modelo:    | Pais de Procedencia:  ");
		printf("\n|__________|_______________|________________|____________|_______________________\n");
		for (i = 0; i < limite; i++) {
			if (pArray[i].isEmpty != 1) {

				idMarca = pArray[i].idMarca;
				idMarcaPos = findMarcaById(pMarca, limite, idMarca);

				idProcedencia = pArray[i].idPais;
				idProcedenciaPos = findPaisById(pProcedencia, limite, idProcedencia);

				printf("|%d         |   %d       | %s        |  %d      | %s \n",
				pArray[i].id,    pArray[i].serie,   pMarca[idMarcaPos].marcDesc,    pArray[i].modelo,  pProcedencia[idProcedenciaPos].nombrePais);
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


	if (pArray != NULL && limite > 0 && id != -1) {
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

int findElectroBySerie(Electro *pArray, int limite, int serie) {
	int retorno = -1;
	int i;
	int flag = 0;

	if (pArray != NULL && limite > 0){
	for (i = 0; i < limite; i++) {
		if (pArray[i].isEmpty != 1) {
			if (pArray[i].serie == serie) {
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

int findEmptyE(Electro *pArray, int limite, int *pos) {
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

int checkMayorMarca(Electro *pElectro, int limite, int *mayorMarca)
{
	int retorno = -1;
	int i;
	int idMarca;
	int maxMarca;
	int flag = 0;



	if (pElectro != NULL && limite > 0) {
			for (i = 0; i < limite; i++) {
				if (pElectro[i].isEmpty != 1) {
					idMarca = pElectro[i].idMarca;

					if(idMarca > maxMarca || flag == 0)
					{
						maxMarca = idMarca;
						flag = 1;
					}
					*mayorMarca = maxMarca;

				}
			}
			retorno = 0;

		}


	return retorno;
}





int mostrarElectroAnioServ(Electro *pElectro, Reparacion *pRepAnio, Servicio *pServicio, int limite, int anio)
{
	int retorno = -1;
	int i;

		for (i = 0; i < limite; i++)
		{
			if(pElectro[i].modelo == anio && pElectro[i].isEmpty == 0)
			{
				pRepAnio[i].id = pElectro[i].id;
				pRepAnio[i].serie = pElectro[i].serie;
				pRepAnio[i].idCliente = pElectro[i].idMarca;
				pRepAnio[i].idServicio = pElectro[i].modelo;
				pRepAnio[i].isEmpty = pElectro[i].isEmpty;
				retorno = 0;
			}
		}

		initRep(pRepAnio, limite);

		return retorno;

}




