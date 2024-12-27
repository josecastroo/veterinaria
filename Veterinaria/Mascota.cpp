#include "Mascota.h"

Mascota::Mascota(string nombre, int edad, string especie, Dueno* dueno) {
	this->nombre = nombre;
	this->edad = edad;
	this->especie = especie;
	this->dueno = dueno;
}
Mascota::Mascota() {
	this->nombre = "Sin definir";
	this->edad = -1;
	this->especie = "Sin definir";
	this->dueno = nullptr;
}

string Mascota::getNombre() { return nombre; }
int Mascota::getEdad() { return edad; }
string Mascota::getEspecie() { return especie; }
Dueno* Mascota::getDueno() { return dueno; }

void Mascota::setNombre(string nombre) { this->nombre = nombre; }
void Mascota::setEdad(int edad) { this->edad = edad; }
void Mascota::setDueno(Dueno* dueno) { this->dueno = dueno; }

string Mascota::toString() {
	stringstream s;
	s << "\n\t   Mascota: " << nombre << endl;
	s << "\t   Edad: " << edad << endl;
	s << "\t   Especie: " << especie << endl << endl;
	return s.str();
}

Mascota::~Mascota() {}