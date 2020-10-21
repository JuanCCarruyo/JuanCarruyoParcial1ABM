/*
 * reparacion.h
 *
 *  Created on: Oct 15, 2020
 *      Author: david
 */

#ifndef REPARACION_H_
#define REPARACION_H_

#include "fecha.h"
#include "electrodomestico.h"
#include "servicio.h"

typedef struct
{
int id;
int serie;
int idServicio;
eFecha fecha;
int isEmpty;
}Reparacion;

int altaReparacion(Reparacion *pArray, Electro *pElectro, Servicio *pServicio, eFecha *pFecha, int limite, int *contRep, int *contFecha);

int checkElectro(Electro *pElectro, int limite, int inputElectro);

int checkServicio(Servicio *pServicio, int limite, int inputServicio);

int addRep(Reparacion *pArray, int limite, int id, int serie, int idServicio, eFecha *fecha, int *contReparacion);

int printRep(Reparacion *pArray, int limite);

int initRep(Reparacion *pArray, int limite);
#endif /* REPARACION_H_ */
