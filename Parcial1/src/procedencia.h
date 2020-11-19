/*
 * procedencia.h
 *
 *  Created on: Nov 19, 2020
 *      Author: david
 */

#ifndef PROCEDENCIA_H_
#define PROCEDENCIA_H_

typedef struct
{
    int idPais;
    char nombrePais[51];
    int isEmpty;
}Procedencia;


void harcodeoProcedencia(Procedencia *pArray, int limite);

int printProcedencia(Procedencia *pArray, int limite);

int findPaisById(Procedencia *pArray, int limite, int id);

#endif /* PROCEDENCIA_H_ */
