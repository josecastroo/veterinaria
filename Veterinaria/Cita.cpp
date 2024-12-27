#include "Cita.h"

Cita::Cita(string dia, string hora, Doctor* doctor, Mascota* mascota, Dueno* dueno) {
	this->dia = dia;
	this->hora = hora;
	this->doctor = doctor;
	this->mascota = mascota;
	this->dueno = dueno;
	doctor->agregarPaciente(mascota);
}
Cita::Cita() {
	this->dia = "Sin definir";
	this->hora = "--:--";
	this->doctor = nullptr;
	this->mascota = nullptr;
	this->dueno = nullptr;
}

string Cita::getDia() { return dia; }
string Cita::getHora() { return hora; }
Doctor* Cita::getDoctor() { return doctor; }
Mascota* Cita::getMascota() { return mascota; }
Dueno* Cita::getDueno() { return dueno; }

void Cita::setDia(string dia) { this->dia = dia; }
void Cita::setHora(string hora) { this->hora = hora; }
void Cita::setDoctor(Doctor* doctor) { this->doctor = doctor; }

string Cita::toString() {
	stringstream s;
	s << "\tCita" << endl;
	s << "\tD" << char(161) << "a: " << dia << endl;
	s << "\tHora: " << hora << endl;
	s << "\tDetalles de la Cita:" << endl;
	s << "\tDoctor: " << doctor->getNombre() << endl;
	s << "\tMascota: " << mascota->getNombre() << endl;
	s << "\tDueño: " << dueno->getNombre() << endl;
	return s.str();
}

Cita::~Cita() {}