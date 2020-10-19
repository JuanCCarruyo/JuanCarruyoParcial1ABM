/*
 * electrodomestico.h
 *
 *  Created on: Oct 15, 2020
 *      Author: david
 */

#ifndef ELECTRODOMESTICO_H_
#define ELECTRODOMESTICO_H_

#include "marca.h"

typedef struct
{
    int id;
    int serie;
    int idMarca;
    int modelo;
    int isEmpty;
}Electro;


int altaElectro(Electro *pArray, Marca *pMarca, int limite, int *contElectro);

int checkMarca(Marca *pArray, int limite, int inputMarca);

int addElectro(Electro *pArray, int limite, int id, int serie, int idMarca, int modelo, int *contElectro);

int printElectro(Electro *pArray, int limite);

int initElectro(Electro *pArray, int limite);

int removeElectro(Electro *pArray, int limite, int id);

int findElectroById(Electro *pArray, int limite, int id);

int modifyElectro(Electro* pArray, int indice);

int sortElectro(Electro *pArray, int limite, int orden);

#endif /* ELECTRODOMESTICO_H_ */
