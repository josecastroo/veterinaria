#include "Especialidad.h"

Especialidad::Especialidad(string tipo, int ID) {
	this->tipo = tipo;
	this->ID = ID;
	this->cantEspecialistas = 0;
	for (int i = 0; i < cantEspecialistas; i++) {
		especialistas[i] = nullptr;
	}
}
Especialidad::Especialidad() {
	this->tipo = "Sin definir";
	this->ID = -1;
	this->cantEspecialistas = 0;
	for (int i = 0; i < cantEspecialistas; i++) {
		especialistas[i] = nullptr;
	}
}

string Especialidad::getTipo() { return tipo; }
int Especialidad::getID() { return ID; }

void Especialidad::setTipo(string tipo) { this->tipo = tipo; }
void Especialidad::setID(int ID) { this->ID = ID; }

bool Especialidad::agregarEspecialista(Doctor* doctor) {
	if (cantEspecialistas < TAMESP) {
		especialistas[cantEspecialistas++] = doctor;
		return true;
	} return false;
}
string Especialidad::mostrarEspecialistas() {
	stringstream s;
	s << "\n\tEspecialistas" << endl << endl;
	for (int i = 0; i < cantEspecialistas; i++) {
		s << especialistas[i]->toString() << endl;
	} return s.str();
}

string Especialidad::toString() {
	stringstream s;
	s << "Tipo: " << tipo << "\tID: " << ID << endl;
	return s.str();
}

Especialidad::~Especialidad() {}