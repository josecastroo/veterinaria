#include "Doctor.h"

Doctor::Doctor(string nombre, int ID, Especialidad* especialidad) {
	this->nombre = nombre;
	this->ID = ID;
	this->especialidad = especialidad;
	this->cantPacientes = 0;
	especialidad->agregarEspecialista(this);
	for (int i = 0; i < TAMPAC; i++) {
		pacientes[i] = nullptr;
	}
}
Doctor::Doctor() {
	this->nombre = "Sin definir";
	this->ID = -1;
	this->especialidad = nullptr;
	this->cantPacientes = 0;
	for (int i = 0; i < TAMPAC; i++) {
		pacientes[i] = nullptr;
	}
}

string Doctor::getNombre() { return nombre; }
int Doctor::getID() { return ID; }
Especialidad* Doctor::getEspecialidad() { return especialidad; }
int Doctor::getCantPacientes() { return cantPacientes; }

void Doctor::setNombre(string nombre) { this->nombre = nombre; }
void Doctor::setEspecialidad(Especialidad* especialidad) { this->especialidad = especialidad; }

bool Doctor::agregarPaciente(Mascota* paciente) {
	if (cantPacientes >= TAMPAC) {
		return false;
	}
	if (cantPacientes < TAMPAC) {
		for (int i = 0; i < cantPacientes; i++) {
			if (pacientes[i] == paciente) {
				return false;
			}
		}
	}
	pacientes[cantPacientes++] = paciente;
	return true;
}
bool Doctor::eliminarPaciente(Mascota* paciente) {
	for (int i = 0; i < cantPacientes; i++) {
		if (pacientes[i] == paciente) {
			delete pacientes[i];
			for (int j = i; j < cantPacientes; j++) {
				pacientes[j] = pacientes[j + 1];
			}
			pacientes[cantPacientes - 1] = nullptr;
			cantPacientes--;
			return true;
		}
	} return false;
}

string Doctor::mostrarPacientes() {
	stringstream s;
	s << "\n\tPacientes del Dr. " << nombre << endl << endl;
	for (int i = 0; i < cantPacientes; i++) {
		s << "\t" << pacientes[i]->toString() << endl;
	} return s.str();
}

string Doctor::toString() {
	stringstream s;
	s << "\n\tDr. " << nombre << endl;
	s << "\tID: " << ID << endl;
	s << "\tEspecialidad: " << especialidad->getTipo() << endl;
	return s.str();
}

Doctor::~Doctor() {
	for (int i = 0; i < TAMPAC; i++) {
		delete pacientes[i];
	}
}