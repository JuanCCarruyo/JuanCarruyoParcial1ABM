/*
 ============================================================================
 Name        : modeloABM.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "utnInputs.h"
#include "fecha.h"
#include "marca.h"
#include "electrodomestico.h"
#include "servicio.h"
#include "reparacion.h"
#include "cliente.h"
#include "informes.h"

#define MAX 5

int main(void) {
	setbuf(stdout, NULL);

	Marca marcas[]={{1000, "Wirpool",0}, {1001, "Sony   ",0}, {1002, "Liliana",0}, {1003, "Gafa   ",0}, {1004, "Philips\0",0}};

	Servicio servicio[]= {{20000, "Garantia     ", 250,0}, {20001, "Mantenimiento", 500,0}, {20002, "Repuestos    ", 400,0}, {20003, "Refaccion    \0", 600,0}};
                                   //8                            13                               9                           9
	Electro arrayElectro[MAX];
	Reparacion arrayRep[MAX];
	eFecha arrayFecha[MAX];
	Cliente arrayClientes[MAX];
	Electro pElectroSinRep[MAX];
	int contElectro=1;
	int contRep=1;
	int contFecha=1;

	int opcion;
	int resultadoInicializar;
	int resultadoMenu;
	int resultadoCargaElectro;
	int resultadoBajaElectro;
	int resultadoFindElectroById;
	int resultadoRemoveElectro;
	int resultadoModElectro;
	int resultadoModifyElectro;
	int resultadoPrintMarca;
	int resultadoPrintServicio;
	int resultadoPrintCliente;
	int resultadoSortElectro;
	int resultadoPrintElectro;
	int resultadoPrintRep;
	int resultadoAltaReparacion;
	int resContadoresClientes;
	int resMostrarElectro2020;
	int resMostrarElectroMarca;
	int resrepElectroSelecc;
	int resMostrarElectroSinRep;
	int resInformeTotalRep;
	int resContadorServicio;
	int resMostrarTrabajosAElectro2018;
	int resRecaudacionPorFecha;
	int resprintGarantia;
	int resrecaudacionDeMant;

	int opcion2;
	int resultadoMenuInformes;
	int resContadoresMarcas;

	int contadorElectro[MAX];
	int contadorCliente[MAX];



	int inputID;

	Electro pElectro2020[MAX];
	Electro pElectroMarca[MAX];

	Reparacion pRepElec[MAX];
	Reparacion pInformeTotalRep[MAX];
	Reparacion pTrabajosAElectro2018[MAX];

	resultadoInicializar = initElectro(arrayElectro, MAX);
	resultadoInicializar = initRep(arrayRep, MAX);
	resultadoInicializar = initFecha(arrayFecha, MAX);
	resultadoInicializar = initElectro(pElectro2020, MAX);
	resultadoInicializar = initElectro(pElectroMarca, MAX);
	resultadoInicializar = initRep(pRepElec, MAX);
	resultadoInicializar = initElectro(pElectroSinRep, MAX);
	resultadoInicializar = initRep(pInformeTotalRep, MAX);
	resultadoInicializar = initRep(pTrabajosAElectro2018, MAX);

	harcodeoClientes(arrayClientes,MAX);

	//hardcore for testing
//	harcodeoElectro(arrayElectro,MAX);
//	harcodeoReparacion(arrayRep,MAX);
	int flagAltaElectro=0;
	int flagAltaReparacion=0;
	//hardcode end

	do {
			if (resultadoInicializar == -1) {
				printf("\nERROR AL INICIALIZAR");
				system("pause");
				break;
			}
			system("CLS");


			resultadoMenu = getInt(&opcion,
					"Menu de Opciones\n"
					"1- ALTA ELECTRODOMESTICO \n"
					"2- MODIFICAR ELECTRODOMESTICO\n"
					"3- BAJA ELECTRODOMESTICO\n"
					"4- LISTAR ELECTRODOMESTICO \n"
					"5- LISTAR MARCAS \n"
					"6- LISTAR SERVICIOS \n"
					"7- LISTAR CLIENTES \n"
					"8- ALTA REPARACION \n"
					"9- LISTAR REPARACIONES \n"
					"10- LISTAR INFORMES \n",
							"\nError: Seleccione una opcion valida.\n", 1, 10, 3);

			if (resultadoMenu != 0) {
				printf("\nERROR FATAL");
				system("pause");
				break;
			}

			switch (opcion) {
			case 1: // ALTA ELECTRODOMESTICO
				flagAltaElectro = 1;

				resultadoCargaElectro = altaElectro(arrayElectro, marcas, MAX, &contElectro);
				if (resultadoCargaElectro != 0) {
					flagAltaElectro = 0;
					printf("\nError en la Carga.\n");
					system("pause");
				}
				printf("\nAlta realizada con exito.\n");
				system("pause");

				break;

			case 2: //MODIFICAR ELECTRODOMESTICO
				if(flagAltaElectro == 1)
				{
					resultadoPrintElectro = printElectro(arrayElectro, marcas, MAX);
					if (resultadoPrintElectro != 0) {
						printf("\nError mostrando los electrodomesticos.\n");
						system("pause");
					}
					resultadoModElectro = getInt(&inputID, "\nIngrese el ID del electrodomestico: ",
							"\nERROR: Ingrese un ID valido", 1, MAX, 10);

					if (resultadoModElectro != 0) {
						printf("\nError ingresando ID.\n");
						system("pause");
					} else {
						resultadoFindElectroById = findElectroById(arrayElectro,
						MAX, inputID);

						if (resultadoFindElectroById == -1) {
							printf("\nNo se encontro electrodomestico con ese ID.");
							system("pause");
						} else {
							resultadoModifyElectro = modifyElectro(arrayElectro, resultadoFindElectroById);
							if (resultadoModifyElectro == 0){
								printf("\nSe modifico un electrodomestico con exito.\n");
								system("pause");
							}
							else if (resultadoModifyElectro == -1)
							{
								printf("\nHubo un error modificando el electrodomestico.\n");
								system("pause");
							}
						}
					}
				}
				else
				{
					printf("\nDebe cargar algun electrodomestico antes de Modificar. \n");
					system("pause");
				}

				break;
			case 3: //BAJA ELECTRODOMESTICO

				if(flagAltaElectro == 1)
				{
					resultadoPrintElectro = printElectro(arrayElectro, marcas, MAX);
					if (resultadoPrintElectro != 0) {
						printf("\nError mostrando los electrodomesticos.\n");
						system("pause");
					}
					resultadoBajaElectro = getInt(&inputID, "\nIngrese el ID del electrodomestico: ",
							"\nERROR: Ingrese un ID valido", 1, MAX, 10);

					if (resultadoBajaElectro != 0) {
						printf("\nError ingresando ID.\n");
						system("pause");
					} else {
						resultadoFindElectroById = findElectroById(arrayElectro,
						MAX, inputID);

						if (resultadoFindElectroById == -1) {
							printf("\nNo se encontro electrodomestico con ese ID.");
							system("pause");
						} else {
							resultadoRemoveElectro = removeElectro(arrayElectro,
							MAX, resultadoFindElectroById);
							if (resultadoRemoveElectro != 0) {
								printf("\nError removiendo electrodomestico.\n");
								system("pause");
							}
							printf("\nSe dio de baja a el electrodomestico con exito.\n");
							system("pause");
						}
					}

				}
				else
				{
					printf("\nDebe cargar algun electrodomestico antes de Bajar. \n");
					system("pause");
				}

				break;
			case 4: //LISTAR ELECTRODOMESTICO

				if(flagAltaElectro == 1){
				resultadoSortElectro = sortElectro(arrayElectro, MAX, 1);
				if (resultadoSortElectro != 0) {
					printf("\nError en el ordenamiento.\n");
					system("pause");
				}

				resultadoPrintElectro = printElectro(arrayElectro, marcas, MAX);
				if (resultadoPrintElectro != 0) {
					printf("\nError mostrando los electrodomesticos.\n");
					system("pause");
				}
				system("pause");
				}
				else
				{
					printf("\nDebe cargar algun electrodomestico antes de listar. \n");
					system("pause");
				}


				break;


			case 5: //LISTAR MARCAS

				resultadoPrintMarca = printMarca(marcas,MAX);
				if (resultadoPrintMarca != 0)
				{
					printf("\nError mostrando las marcas.\n");
					system("pause");
				}
				system("pause");

				break;


			case 6: //LISTAR SERVICIOS

				resultadoPrintServicio = printServicio(servicio,4);
				if (resultadoPrintServicio != 0)
				{
					printf("\nError mostrando los servicios.\n");
					system("pause");
				}
				system("pause");


				break;

			case 7: //LISTAR CLIENTES

				resultadoPrintCliente = printCliente(arrayClientes,MAX);
				if (resultadoPrintCliente != 0)
				{
					printf("\nError mostrando los clientes.\n");
					system("pause");
				}
				system("pause");


				break;

			case 8:  //ALTA REPARACION
				if(flagAltaElectro == 1)
				{
					flagAltaReparacion = 1;

					resultadoPrintElectro = printElectro(arrayElectro, marcas, MAX);
					if (resultadoPrintElectro != 0) {
						printf("\nError mostrando los electrodomesticos.\n");
						system("pause");
					}
					resultadoAltaReparacion = altaReparacion(arrayRep, arrayElectro, servicio, arrayFecha, arrayClientes, MAX, &contRep, &contFecha);
					if (resultadoAltaReparacion != 0) {
						flagAltaReparacion = 0;
						printf("\nError en la Carga.\n");
						system("pause");
					}
				}
				else
				{
					printf("\nDebe cargar algun electrodomestico antes de hacer una reparacion. \n");
				}

				break;

			case 9: //LISTAR REPARACIONES

				if(flagAltaElectro == 1 && flagAltaReparacion == 1)
				{
					resultadoPrintRep = printRep(arrayRep, arrayClientes, servicio, MAX);
					if (resultadoPrintRep != 0) {
						printf("\nError mostrando las reparaciones.\n");
						system("pause");
					}
					system("pause");

				}
				else
				{
					printf("\nDebe cargar algun electrodomestico antes de hacer una reparacion. \n");
					system("pause");
				}

				break;

			case 10: //INFORMES

				resultadoMenuInformes = getInt(&opcion2,
						"Menu de Opciones\n"
						"1- Mostrar Electrodomesticos del anio(modelo) 2020 \n"
						"2- Mostrar Electrodomesticos de una marca seleccionada\n"
						"3- Mostrar todos las reparaciones efectuadas al Electrodoméstico seleccionado \n"
						"4- Listar los Electrodomésticos que no tuvieron reparaciones  \n"
						"5- Informar importe total de las reparaciones realizadas a un Electrodoméstico seleccionado  \n"
						"6- Mostrar el servicio más pedido \n"
						"7- Mostrar la recaudación en una fecha en particular\n"
						"8- Mostrar todos los Electrodomésticos que realizaron una garantía y la fecha\n"
						"9- Trabajos realizados a Electrodomésticos del año(modelo) 2018\n"
						"10- Facturación total por los mantenimientos\n"
						"11- Informar la marca con mas Electrodomésticos \n"
						"12- Informar el cliente con mas reparaciones \n"
						"13- Volver \n",
								"\nError: Seleccione una opcion valida.\n", 1, 13, 3);

				if (resultadoMenuInformes != 0) {
					printf("\nERROR FATAL");
					system("pause");
					break;
				}

				switch(opcion2)
				{

				case 1: //"1- Mostrar Electrodomesticos del anio(modelo) 2020 \n"

					resMostrarElectro2020 = mostrarElectroAnio(arrayElectro, pElectro2020, marcas, MAX, 2020);
					if (resMostrarElectro2020 != 0) {
						printf("\nError mostrando el informe.\n");
						system("pause");
					}

					break;

				case 2: //"2- Mostrar Electrodomesticos de una marca seleccionada\n"

					resMostrarElectroMarca = mostrarElectroMarca(arrayElectro, marcas, pElectroMarca, MAX);
					if (resMostrarElectroMarca != 0) {
						printf("\nError mostrando el informe.\n");
						system("pause");
					}

					break;

				case 3: //"3- Mostrar todos las reparaciones efectuadas al Electrodoméstico seleccionado \n"

					resultadoPrintElectro = printElectro(arrayElectro, marcas, MAX);
					if (resultadoPrintElectro != 0) {
						printf("\nError mostrando los electrodomesticos.\n");
						system("pause");
					}
					resrepElectroSelecc = repElectroSelecc(arrayRep, arrayElectro, servicio, arrayClientes, pRepElec, MAX);
					if (resrepElectroSelecc != 0) {
						printf("\nError mostrando el informe.\n");
						system("pause");
					}

					break;

				case 4: //"4- Listar los Electrodomésticos que no tuvieron reparaciones  \n"

					resMostrarElectroSinRep = mostrarElectroSinRep(arrayElectro, arrayRep, marcas, pElectroSinRep, MAX);
					if (resMostrarElectroSinRep != 0) {
						printf("\nError mostrando el informe.\n");
						system("pause");
					}

					break;

				case 5: //"5- Informar importe total de las reparaciones realizadas a un Electrodoméstico seleccionado  \n"

					resultadoPrintElectro = printElectro(arrayElectro, marcas, MAX);
					if (resultadoPrintElectro != 0) {
						printf("\nError mostrando los electrodomesticos.\n");
						system("pause");
					}
					resInformeTotalRep = informeTotalRep(arrayRep, arrayElectro, servicio, pInformeTotalRep, MAX);
					if (resInformeTotalRep != 0) {
						printf("\nError mostrando el informe.\n");
						system("pause");
					}
					break;

				case 6: //"6- Mostrar el servicio más pedido \n"

					 resContadorServicio = contadorServicio(arrayRep, servicio, MAX);
						if (resContadorServicio != 0) {
							printf("\nError mostrando el informe.\n");
							system("pause");
						}
						break;

				case 7: //"7- Mostrar la recaudación en una fecha en particular\n"

					resRecaudacionPorFecha = recaudacionPorFecha(arrayRep, MAX, servicio, arrayFecha, &contFecha);
					if (resRecaudacionPorFecha != 0) {
						printf("\nError mostrando el informe.\n");
						system("pause");
					}
					break;

				case 8: //"8- Mostrar todos los Electrodomésticos que realizaron una garantía y la fecha\n"

					resprintGarantia = printGarantia(arrayRep, arrayElectro, arrayClientes, marcas, servicio, MAX);
					if (resprintGarantia != 0) {
						printf("\nError mostrando el informe.\n");
						system("pause");
					}
					system("pause");

					break;

				case 9: //"9- Trabajos realizados a Electrodomésticos del año(modelo) 2018\n"

					resMostrarTrabajosAElectro2018 = mostrarTrabajosAElectro2018(arrayRep, arrayElectro, servicio, pTrabajosAElectro2018, MAX);
					if (resMostrarTrabajosAElectro2018 != 0) {
						printf("\nError mostrando el informe.\n");
						system("pause");
					}
					break;

				case 10: //"10- Facturación total por los mantenimientos\n"

					resrecaudacionDeMant = recaudacionDeMant(arrayRep, MAX, servicio);
					if (resrecaudacionDeMant != 0) {
						printf("\nError mostrando el informe.\n");
						system("pause");
					}
					break;


				case 11: //"11- Informar la marca con mas Electrodomésticos \n"

					resContadoresMarcas = contadoresMarcas(arrayElectro, marcas, MAX, contadorElectro);
					if (resContadoresMarcas != 0) {
						printf("\nERROR FATAL");
						system("pause");
						break;
					}
					system("pause");

					break;

				case 12: //"12- Informar el cliente con mas reparaciones \n"

					resContadoresClientes = contadoresClientes(arrayRep, arrayClientes, MAX, contadorCliente);
					if (resContadoresClientes != 0) {
						printf("\nERROR FATAL");
						system("pause");
						break;
					}
					system("pause");


					break;

				case 13: //"13- Volver \n"

					break;





				}



				break;


			}

		} while (opcion == 1 || opcion == 2 || opcion == 3 || opcion == 4 || opcion == 5 || opcion == 6 || opcion == 7 || opcion == 8|| opcion == 9 || opcion == 10);


	return EXIT_SUCCESS;
}
