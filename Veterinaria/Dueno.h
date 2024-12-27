#pragma once
#ifndef DUENO_H
#define DUENO_H
#include <iostream>
#include <sstream>
using namespace std;

class Mascota;

class Dueno {
private:
	string nombre;
	int ID;
	Mascota** mascotas;
	int tamMascotas;
	int cantMascotas;

public:
	Dueno(string, int, int);
	Dueno();

	string getNombre();
	int getID();

	void setNombre(string);

	bool agregarMascota(Mascota*);
	bool eliminarMascota(Mascota*);

	Mascota* getMascota(int);

	string mostrarMascotas();
	string mostrarSoloMascotas();
	string toString();

	virtual ~Dueno();
};
#endif
