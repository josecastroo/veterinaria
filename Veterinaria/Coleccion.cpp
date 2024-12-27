#include "Coleccion.h"

Coleccion::Coleccion(int tamDoctores, int tamDuenos, int tamEspecialidades) {
	this->tamDoctores = tamDoctores;
	this->cantDoctores = 0;
	this->tamDuenos = tamDuenos;
	this->cantDuenos = 0;
	this->tamEspecialidades = tamEspecialidades;
	this->cantEspecialidades = 0;
	this->doctores = new Doctor * [tamDoctores];
	this->duenos = new Dueno * [tamDuenos];
	this->especialidades = new Especialidad * [tamEspecialidades];
	for (int i = 0; i < tamDoctores; i++) {
		doctores[i] = nullptr;
	}
	for (int i = 0; i < tamDuenos; i++) {
		duenos[i] = nullptr;
	}
	for (int i = 0; i < tamEspecialidades; i++) {
		especialidades[i] = nullptr;
	}
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 11; j++) {
			citas[i][j] = nullptr;
		}
	}
}
Coleccion::Coleccion() {
	this->tamDoctores = 20;
	this->cantDoctores = 0;
	this->tamDuenos = 50;
	this->cantDuenos = 0;
	this->tamEspecialidades = 20;
	this->cantEspecialidades = 0;
	this->doctores = new Doctor * [tamDoctores];
	this->duenos = new Dueno * [tamDuenos];
	this->especialidades = new Especialidad * [tamEspecialidades];
	for (int i = 0; i < tamDoctores; i++) {
		doctores[i] = nullptr;
	}
	for (int i = 0; i < tamDuenos; i++) {
		duenos[i] = nullptr;
	}
	for (int i = 0; i < tamEspecialidades; i++) {
		especialidades[i] = nullptr;
	}
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 11; j++) {
			citas[i][j] = nullptr;
		}
	}
}

bool Coleccion::agregarDoctor(Doctor* doctor) {
	for (int i = 0; i < cantDoctores; i++) {
		if (doctores[i]->getID() == doctor->getID()) {
			return false;
		}
	}
	if (cantDoctores < tamDoctores) {
		doctores[cantDoctores++] = doctor;
		return true;
	} return false;
}
bool Coleccion::agregarDueno(Dueno* dueno) {
	for (int i = 0; i < cantDuenos; i++) {
		if (duenos[i]->getID() == dueno->getID()) {
			return false;
		}
	}
	if (cantDuenos < tamDuenos) {
		duenos[cantDuenos++] = dueno;
		return true;
	} return false;
}
bool Coleccion::agregarEspecialidad(Especialidad* especialidad) {
	for (int i = 0; i < cantEspecialidades; i++) {
		if (especialidades[i]->getID() == especialidad->getID()) {
			return false;
		}
	}
	if (cantEspecialidades < tamEspecialidades) {
		especialidades[cantEspecialidades++] = especialidad;
		return true;
	} return false;
}
bool Coleccion::agregarCita(Cita* cita) {
	string horas[11] = { "8:00", "9:00", "10:00", "11:00", "12:00", "1:00", "2:00", "3:00", "4:00", "5:00", "6:00" };
	string dias[6] = { "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado" };

	int diaIndex = -1;
	for (int i = 0; i < 6; i++) {
		if (cita->getDia() == dias[i]) {
			diaIndex = i;
			break;
		}
	}
	int horaIndex = -1;
	for (int j = 0; j < 11; j++) {
		if (cita->getHora() == horas[j]) {
			horaIndex = j;
			break;
		}
	}

	if (diaIndex == -1 || horaIndex == -1) {
		return false;
	}
	if (citas[diaIndex][horaIndex] != nullptr) {
		return false;
	}

	citas[diaIndex][horaIndex] = cita;
	return true;
}
bool Coleccion::cancelarCita(Cita* cita) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 11; j++) {
			if (citas[i][j] == cita) {
				citas[i][j] = nullptr;
				cita->getDoctor()->eliminarPaciente(cita->getMascota());
				delete citas[i][j];
				citas[i][j] = nullptr;
				return true;
			}
		}
	} return false;
}

string Coleccion::mostrarEspecialidades() {
	stringstream s;
	s << "\n\tEspecialidades" << endl << endl;
	for (int i = 0; i < cantEspecialidades; i++) {
		s << "\t" << especialidades[i]->toString() << endl;
	}
	return s.str();
}
int Coleccion::getCantEspecialidades() { return cantEspecialidades; }
int Coleccion::getCantDuenos() { return cantDuenos; }
int Coleccion::getCantDoctores() { return cantDoctores; }

string Coleccion::mostrarDoctores() {
	stringstream s;
	s << "\n\tEquipo de doctores" << endl << endl;
	for (int i = 0; i < cantDoctores; i++) {
		s << "\t" << doctores[i]->toString() << endl;
	} return s.str();
}
Cita* Coleccion::getCita(string dia, string hora) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 11; j++) {
			if (citas[i][j] != nullptr) {
				if ((citas[i][j]->getDia() == dia) && (citas[i][j]->getHora() == hora)) {
					return citas[i][j];
				}
			}
		}
	} return nullptr;
}
Especialidad* Coleccion::getEspecialidad(int index) {
	if (index >= 0 && index < cantEspecialidades) {
		return especialidades[index];
	}
	return nullptr;
}
Dueno* Coleccion::getDueno(int index) {
	if (index >= 0 && index < cantDuenos) {
		return duenos[index];
	}
	return nullptr;
}
Dueno* Coleccion::getDuenoPorID(int ID) {
	for (int i = 0; i < cantDuenos; i++) {
		if (duenos[i]->getID() == ID) {
			return duenos[i];
		}
	}
	return nullptr;
}
Doctor* Coleccion::getDoctorPorID(int ID) {
	for (int i = 0; i < cantDoctores; i++) {
		if (doctores[i]->getID() == ID) {
			return doctores[i];
		}
	}
	return nullptr;
}
Especialidad* Coleccion::getEspecialidadPorID(int ID) {
	for (int i = 0; i < cantEspecialidades; i++) {
		if (especialidades[i]->getID() == ID) {
			return especialidades[i];
		}
	}
	return nullptr;
}

string Coleccion::mostrarDuenos() {
	stringstream s;
	s << "\n\tDue" << char(164) << "os" << endl << endl;
	for (int i = 0; i < cantDuenos; i++) {
		s << "\t" << duenos[i]->mostrarMascotas() << endl;
	}
	return s.str();
}
string Coleccion::mostrarSoloDuenos() {
	stringstream s;
	s << "\n\tDue" << char(164) << "os" << endl << endl;
	for (int i = 0; i < cantDuenos; i++) {
		s << "\t" << duenos[i]->toString() << endl;
	}
	return s.str();
}
string Coleccion::mostrarAgendaDueno(Dueno* dueno) {
	string dias[6] = { "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado" };
	string horas[11] = { "8:00", "9:00", "10:00", "11:00", "12:00", "1:00", "2:00", "3:00", "4:00", "5:00", "6:00" };

	stringstream s;
	s << "\n    Agenda de " << dueno->getNombre() << endl << endl;
	s << "\t\t";
	for (int i = 0; i < 6; i++) {
		s << dias[i] << "\t";
	}
	s << "\n";

	for (int j = 0; j < 11; j++) {
		s << "    " << horas[j] << "\t";
		for (int i = 0; i < 6; i++) {
			if (citas[i][j] != nullptr && citas[i][j]->getDueno() == dueno) {
				s << citas[i][j]->getMascota()->getNombre() << "\t";
			}
			else {
				if (i == 2) {
					s << "[X]\t\t";
				}
				else {
					s << "[X]\t";
				}
			}
		}
		s << "\n";
	} return s.str();
}

string Coleccion::mostrarAgendaDoctor(Doctor* doctor) {
	string dias[6] = { "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado" };
	string horas[11] = { "8:00", "9:00", "10:00", "11:00", "12:00", "1:00", "2:00", "3:00", "4:00", "5:00", "6:00" };

	stringstream s;
	s << "\n    Agenda de " << doctor->getNombre() << endl << endl;
	s << "\t\t";
	for (int i = 0; i < 6; i++) {
		s << dias[i] << "\t";
	}
	s << "\n";

	for (int j = 0; j < 11; j++) {
		s << "    " << horas[j] << "\t";
		for (int i = 0; i < 6; i++) {
			if (citas[i][j] != nullptr && citas[i][j]->getDoctor() == doctor) {
				s << citas[i][j]->getMascota()->getNombre() << "\t";
			}
			else {
				if (i == 2) {
					s << "[X]\t\t";
				}
				else {
					s << "[X]\t";
				}
			}
		}
		s << "\n";
	} return s.str();
}

Coleccion::~Coleccion() {
	for (int i = 0; i < tamDoctores; i++) {
		delete doctores[i];
	}
	for (int i = 0; i < tamDuenos; i++) {
		delete duenos[i];
	}
	for (int i = 0; i < tamEspecialidades; i++) {
		delete especialidades[i];
	}
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 11; j++) {
			delete citas[i][j];
		}
	}
}
