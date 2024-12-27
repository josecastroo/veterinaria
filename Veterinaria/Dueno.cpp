#include "Dueno.h"
#include "Mascota.h"

Dueno::Dueno(string nombre, int ID, int tamMascotas) {
	this->nombre = nombre;
	this->ID = ID;
	this->mascotas = new Mascota * [tamMascotas];
	this->tamMascotas = tamMascotas;
	this->cantMascotas = 0;
	for (int i = 0; i < tamMascotas; i++) {
		mascotas[i] = nullptr;
	}
}
Dueno::Dueno() {
	this->nombre = "Sin definir";
	this->ID = -1;
	this->tamMascotas = 10;
	this->mascotas = new Mascota * [tamMascotas];
	this->cantMascotas = 0;
	for (int i = 0; i < tamMascotas; i++) {
		mascotas[i] = nullptr;
	}
}

string Dueno::getNombre() { return nombre; }
int Dueno::getID() { return ID; }

void Dueno::setNombre(string nombre) { this->nombre = nombre; }

bool Dueno::agregarMascota(Mascota* mascota) {
	if (cantMascotas < tamMascotas) {
		mascotas[cantMascotas++] = mascota;
		return true;
	} return false;
}
bool Dueno::eliminarMascota(Mascota* mascota) {
	for (int i = 0; i < cantMascotas; i++) {
		if (mascotas[i] == mascota) {
			delete mascotas[i];
			for (int j = 0; j < cantMascotas; j++) {
				mascotas[j] = mascotas[j + 1];
			}
			mascotas[cantMascotas - 1] = nullptr;
			cantMascotas--;
			return true;
		}
	} return false;
}

Mascota* Dueno::getMascota(int index) {
	if (index >= 0 && index < cantMascotas) {
		return mascotas[index];
	}
	return nullptr;
}

string Dueno::mostrarMascotas() {
	stringstream s;
	s << "\n\tNombre: " << nombre << "\tID: " << ID << endl << endl;
	for (int i = 0; i < cantMascotas; i++) {
		s << "\t" << i + 1 << ". " << mascotas[i]->toString() << endl;
	}
	return s.str();
}
string Dueno::toString() {
	stringstream s;
	s << "Nombre: " << nombre << "\tID: " << ID << endl;
	return s.str();
}

Dueno::~Dueno() {
	for (int i = 0; i < tamMascotas; i++) {
		delete mascotas[i];
	}
}