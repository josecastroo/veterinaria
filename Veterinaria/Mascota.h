#pragma once
#ifndef MASCOTA_H
#define MASCOTA_H
#include "Dueno.h"
using namespace std;

class Mascota {
private:
	string nombre;
	int edad;
	string especie;
	Dueno* dueno;

public:
	Mascota(string, int, string, Dueno*);
	Mascota();

	string getNombre();
	int getEdad();
	string getEspecie();
	Dueno* getDueno();

	void setNombre(string);
	void setEdad(int);
	void setDueno(Dueno*);

	string toString();

	virtual ~Mascota();
};
#endif

