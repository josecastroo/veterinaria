#pragma once
#ifndef ESPECIALIDAD_H
#define ESPECIALIDAD_H
#include <iostream>
#include <sstream>
#include "Doctor.h"
#define TAMESP 10
using namespace std;

class Doctor;

class Especialidad {
private:
	string tipo;
	int ID;
	Doctor* especialistas[TAMESP];
	int cantEspecialistas;

public:
	Especialidad(string, int);
	Especialidad();

	string getTipo();
	int getID();

	void setTipo(string);
	void setID(int);

	bool agregarEspecialista(Doctor*);
	string mostrarEspecialistas();

	string toString();

	virtual ~Especialidad();
};
#endif
