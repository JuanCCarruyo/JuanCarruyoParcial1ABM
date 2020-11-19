/*
 * informes.h
 *
 *  Created on: Nov 18, 2020
 *      Author: david
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include "electrodomestico.h"
#include "servicio.h"
#include "fecha.h"
#include "cliente.h"


#endif /* INFORMES_H_ */

//"1- Mostrar Electrodomesticos del anio(modelo) 2020 \n"
int mostrarElectroAnio(Electro *pElectro, Electro *pElectro2020, Marca *pMarca, Procedencia *pProcedencia, int limite, int anio);

//"2- Mostrar Electrodomesticos de una marca seleccionada\n"
int mostrarElectroMarca(Electro *pElectro, Marca *pMarca, Electro *pElectroMarca, Procedencia *pProcedencia, int limite);

//"3- Mostrar todos las reparaciones efectuadas al Electrodoméstico seleccionado \n"
int repElectroSelecc(Reparacion *pArray, Electro *pElectro, Servicio *pServicio, Cliente *pCliente, Reparacion *pRepElec, int limite);

//"4- Listar los Electrodomésticos que no tuvieron reparaciones  \n"
int mostrarElectroSinRep(Electro *pElectro, Reparacion *pRep, Marca *pMarca, Electro *pElectroSinRep, Procedencia *pProcedencia, int limite);

//"5- Informar importe total de las reparaciones realizadas a un Electrodoméstico seleccionado  \n"
int informeTotalRep(Reparacion *pArray, Electro *pElectro, Servicio *pServicio, Reparacion *pInformeTotalRep, int limite);

//"6- Mostrar el servicio más pedido \n"
int contadorServicio(Reparacion *pArray, Servicio *pServicio, int limite);

//"7- Mostrar la recaudación en una fecha en particular\n"
int recaudacionPorFecha(Reparacion *pArray, int limite, Servicio *pServicio, eFecha *pFecha, int *contFecha);

//"8- Mostrar todos los Electrodomésticos que realizaron una garantía y la fecha\n"
int printGarantia(Reparacion *pArray, Electro *pElectro, Cliente *pCliente, Marca *pMarca, Servicio *pServicio, int limite);

//"9- Trabajos realizados a Electrodomésticos del año(modelo) 2018\n"
int mostrarTrabajosAElectro2018(Reparacion *pArray, Electro *pElectro, Servicio *pServicio, Reparacion *pTrabajosAElectro2018, int limite);

//"10- Facturación total por los mantenimientos\n"
int recaudacionDeMant(Reparacion *pArray, int limite, Servicio *pServicio);

//"11- Informar la marca con mas Electrodomésticos \n"
int contadoresMarcas(Electro *pElectro, Marca *pMarca, int limite, int *contadorElectro);

//"12- Informar el cliente con mas reparaciones \n"
int contadoresClientes(Reparacion *pArray, Cliente *pCliente, int limite, int *contadorCliente);
