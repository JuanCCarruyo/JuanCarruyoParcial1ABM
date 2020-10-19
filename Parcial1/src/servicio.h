/*
 * servicio.h
 *
 *  Created on: Oct 15, 2020
 *      Author: david
 */

#ifndef SERVICIO_H_
#define SERVICIO_H_

typedef struct
{
    int id; //comienza en 20000
    char servDesc[26];
    float precio;
    int isEmpty;
}Servicio;

int printServicio(Servicio *pArray, int limite);

#endif /* SERVICIO_H_ */
