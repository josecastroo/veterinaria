#pragma once
#ifndef DOCTOR_H
#define DOCTOR_H
#include "Mascota.h"
#include "Especialidad.h"
#define TAMPAC 48
using namespace std;

class Especialidad;

class Doctor {
private:
	string nombre;
	int ID;
	Especialidad* especialidad;
	Mascota* pacientes[TAMPAC];
	int cantPacientes;

public:
	Doctor(string, int, Especialidad*);
	Doctor();

	string getNombre();
	int getID();
	Especialidad* getEspecialidad();
	int getCantPacientes();

	void setNombre(string);
	void setEspecialidad(Especialidad*);

	bool agregarPaciente(Mascota*);
	bool eliminarPaciente(Mascota*);

	string mostrarPacientes();
	string toString();

	virtual ~Doctor();
};
#endif

