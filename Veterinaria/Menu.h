#pragma once
#ifndef MENU_H
#define MENU_H
#include "Coleccion.h"

class Menu {
private:
	Coleccion* sistema;

public:
	Menu();

	void menuPrincipal();

	void subMenuAdministracion();
	void subMenuControlCitas();
	void subMenuListados();

	void ingresarEspecialidades();
	void ingresarDoctor();
	void ingresarDueno();
	void ingresarMascota();

	void sacarCita();
	void cancelarCita();
	void mostrarCalendarioDoc();
	void mostrarCitasDueno();

	void listadoEspecialidades();
	void listadoDocPorEsp();
	void mostrarDuenos();
	void mostrarPacientes();

	virtual ~Menu();
};
#endif
