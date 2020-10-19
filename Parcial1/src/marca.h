/*
 * marca.h
 *
 *  Created on: Oct 15, 2020
 *      Author: david
 */

#ifndef MARCA_H_
#define MARCA_H_

typedef struct
{
 int id; //comienza en 1000
 char marcDesc[21]; // max 20 caracteres
 int isEmpty;
}Marca;

int printMarca(Marca *pArray, int limite);

#endif /* MARCA_H_ */
