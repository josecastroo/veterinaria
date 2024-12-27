#pragma once
#ifndef CITA_H
#define CITA_H
#include "Doctor.h"
#include "Dueno.h"
#include "Mascota.h"
using namespace std;

class Cita {
private:
	string dia;
	string hora;
	Doctor* doctor;
	Mascota* mascota;
	Dueno* dueno;

public:
	Cita(string, string, Doctor*, Mascota*, Dueno*);
	Cita();

	string getDia();
	string getHora();
	Doctor* getDoctor();
	Mascota* getMascota();
	Dueno* getDueno();

	void setDia(string);
	void setHora(string);
	void setDoctor(Doctor*);

	string toString();

	virtual ~Cita();
};
#endif

