#pragma once
#ifndef COLECCION_H
#define COLECCION_H
#include "Dueno.h"
#include "Doctor.h"
#include "Cita.h"
#include "Especialidad.h"
using namespace std;

class Coleccion {
private:
	Doctor** doctores;
	Dueno** duenos;
	Especialidad** especialidades;
	Cita* citas[6][11] = { nullptr };
	int cantDoctores;
	int tamDoctores;
	int cantDuenos;
	int tamDuenos;
	int cantEspecialidades;
	int tamEspecialidades;

public:
	Coleccion(int, int, int);
	Coleccion();

	bool agregarDoctor(Doctor*);
	bool agregarDueno(Dueno*);
	bool agregarEspecialidad(Especialidad*);
	bool agregarCita(Cita*);
	bool cancelarCita(Cita*);

	string mostrarEspecialidades();
	int getCantEspecialidades();
	int getCantDuenos();
	int getCantDoctores();

	Cita* getCita(string, string);
	Dueno* getDueno(int);
	Dueno* getDuenoPorID(int);
	Doctor* getDoctorPorID(int);
	Especialidad* getEspecialidadPorID(int ID);
	Especialidad* getEspecialidad(int);

	string mostrarDoctores();
	string mostrarDuenos();
	string mostrarSoloDuenos();
	string mostrarAgendaDueno(Dueno*);
	string mostrarAgendaDoctor(Doctor*);

	virtual ~Coleccion();
};
#endif
