#include "Menu.h"

Menu::Menu() {
	this->sistema = new Coleccion();
}

void Menu::menuPrincipal() {
	int opcion = -1;
	while (opcion != 0) {
		cout << "\n\tMen" << char(163) << " Principal" << endl << endl;
		cout << "\t1. Submen" << char(163) << " Administraci" << char(162) << "n" << endl;
		cout << "\t2. Submen" << char(163) << " Control de Citas" << endl;
		cout << "\t3. Submen" << char(163) << " B" << char(163) << "squeda y Listados" << endl;
		cout << "\t0. Salir" << endl << endl;
		cout << "\tIngrese la opci" << char(162) << "n: ";
		cin >> opcion;

		switch (opcion) {
		case 1:
			system("cls");
			subMenuAdministracion();
			break;
		case 2:
			system("cls");
			subMenuControlCitas();
			break;
		case 3:
			system("cls");
			subMenuListados();
			break;
		}
		system("cls");
	}
}

void Menu::subMenuAdministracion() {
	int opcion = -1;
	while (opcion != 0) {
		cout << "\n\tSubmen" << char(163) << " Administraci" << char(162) << "n" << endl << endl;
		cout << "\t1. Ingresar Especialidad" << endl;
		cout << "\t2. Ingresar Doctor (por especialidad)" << endl;
		cout << "\t3. Ingresar Due" << char(164) << "o" << endl;
		cout << "\t4. Ingresar Mascota (por due" << char(164) << "o)" << endl;
		cout << "\t0. Regresar al Men" << char(163) << " Principal" << endl << endl;
		cout << "\tIngrese la opci" << char(162) << "n: ";
		cin >> opcion;

		switch (opcion) {
		case 1:
			system("cls");
			ingresarEspecialidades();
			break;
		case 2:
			system("cls");
			ingresarDoctor();
			break;
		case 3:
			system("cls");
			ingresarDueno();
			break;
		case 4:
			system("cls");
			ingresarMascota();
			break;
		}
		system("cls");
	}
	system("cls");
}
void Menu::subMenuControlCitas() {
	int opcion = -1;
	while (opcion != 0) {
		cout << "\n\tSubmen" << char(163) << " Control de Citas" << endl << endl;
		cout << "\t1. Sacar Cita" << endl;
		cout << "\t2. Cancelar Cita" << endl;
		cout << "\t3. Mostrar Calendario de Citas por Doctor" << endl;
		cout << "\t4. Mostrar Citas por Due" << char(164) << "o" << endl;
		cout << "\t0. Regresar al Men" << char(163) << " Principal" << endl << endl;
		cout << "\tIngrese la opci" << char(162) << "n: ";
		cin >> opcion;

		switch (opcion) {
		case 1:
			system("cls");
			sacarCita();
			break;
		case 2:
			system("cls");
			cancelarCita();
			break;
		case 3:
			system("cls");
			mostrarCalendarioDoc();
			break;
		case 4:
			system("cls");
			mostrarCitasDueno();
			break;
		}
		system("cls");
	}
	system("cls");
}
void Menu::subMenuListados() {
	int opcion = -1;
	while (opcion != 0) {
		cout << "\n\tSubmen" << char(163) << " B" << char(163) << "squeda y Listados" << endl << endl;
		cout << "\t1. Mostrar Listado de Especialidades" << endl;
		cout << "\t2. Mostrar Listado de Doctores por Especialidad" << endl;
		cout << "\t3. Mostrar Due" << char(164) << "o con sus Mascotas" << endl;
		cout << "\t4. Mostrar Pacientes por Doctor" << endl;
		cout << "\t0. Regresar al Men" << char(163) << " Principal" << endl << endl;
		cout << "\tIngrese la opci" << char(162) << "n: ";
		cin >> opcion;

		switch (opcion) {
		case 1:
			system("cls");
			listadoEspecialidades();
			break;
		case 2:
			system("cls");
			listadoDocPorEsp();
			break;
		case 3:
			system("cls");
			mostrarDuenos();
			break;
		case 4:
			system("cls");
			mostrarPacientes();
			break;
		}
		system("cls");
	}
	system("cls");
}

void Menu::ingresarEspecialidades() {
	string tipo;
	int ID;
	cout << "\n\tTipo: ";
	cin >> tipo;
	cout << "\tID: ";
	cin >> ID;
	system("cls");
	if (sistema->agregarEspecialidad(new Especialidad(tipo, ID))) {
		cout << "\n\tEspecialidad registrada!";
	}
	else {
		cout << "\n\tNo hay espacio disponible o ID ya existente :(";
	}
	cin.ignore();
	cin.get();
}
void Menu::ingresarDoctor() {
	string nombre;
	int ID;
	int espID;

	cout << "\n\tNombre del doctor: ";
	cin >> nombre;
	cout << "\tID: ";
	cin >> ID;

	if (sistema->getCantEspecialidades() == 0) {
		system("cls");
		cout << "\n\tNo existen especialidades";
		cin.ignore();
		cin.get();
		return;
	}
	else {
		system("cls");
		cout << sistema->mostrarEspecialidades();
		cout << "\tID de la especialidad: ";
		cin >> espID;

		Especialidad* espSelected = sistema->getEspecialidadPorID(espID);

		if (espSelected == nullptr) {
			system("cls");
			cout << "\n\tID inv" << char(160) << "lido";
			cin.ignore();
			cin.get();
			return;
		}
		if (sistema->agregarDoctor(new Doctor(nombre, ID, espSelected))) {
			system("cls");
			cout << "\n\tDoctor registrado!";
			cin.ignore();
			cin.get();
		}
		else {
			system("cls");
			cout << "\n\tNo hay espacio disponible o ID ya existente :(" << endl;
			cin.ignore();
			cin.get();
		}
	}

}
void Menu::ingresarDueno() {
	string nombre;
	int ID;
	int tamMascotas;
	cout << "\n\tNombre del due" << char(164) << "o: ";
	cin >> nombre;
	cout << "\tID: ";
	cin >> ID;
	cout << "\tCantidad de mascotas: ";
	cin >> tamMascotas;

	if (sistema->agregarDueno(new Dueno(nombre, ID, tamMascotas))) {
		system("cls");
		cout << "\n\tDue" << char(164) << "o registrado!";
		cin.ignore();
		cin.get();
	}
	else {
		system("cls");
		cout << "\n\tNo hay espacio disponible o ID ya existente :(";
		cin.ignore();
		cin.get();
	}
}
void Menu::ingresarMascota() {
	string nombre;
	int edad;
	string especie;
	int ID;

	cout << "\n\tNombre de la mascota: ";
	cin >> nombre;
	cout << "\tEdad: ";
	cin >> edad;
	cout << "\tEspecie: ";
	cin >> especie;

	if (sistema->getCantDuenos() == 0) {
		system("cls");
		cout << "\n\tNo existen due" << char(164) << "os" << endl;
		cin.ignore();
		cin.get();
		return;
	}
	else {
		system("cls");
		cout << sistema->mostrarSoloDuenos();
		cout << "\tID del due" << char(164) << "o: ";
		cin >> ID;

		Dueno* duenoSelected = sistema->getDuenoPorID(ID);

		if (duenoSelected == nullptr) {
			system("cls");
			cout << "\n\tID inv" << char(160) << "lido" << endl;
			cin.ignore();
			cin.get();
			return;
		}
		if (duenoSelected->agregarMascota(new Mascota(nombre, edad, especie, duenoSelected))) {
			system("cls");
			cout << "\n\tMascota registrada!" << endl;
			cin.ignore();
			cin.get();
		}
		else {
			system("cls");
			cout << "\n\tNo hay espacio disponible :(" << endl;
			cin.ignore();
			cin.get();
		}
	}
}

void Menu::sacarCita() {
	string dia;
	string hora;
	int doctorID;
	int duenoID;
	int mascotaIndex;

	cout << "\n\tD" << char(161) << "a (ej. Lunes): ";
	cin >> dia;
	cout << "\tHora (--:--): ";
	cin >> hora;

	system("cls");
	cout << sistema->mostrarDoctores();
	cout << "\tID del doctor: ";
	cin >> doctorID;

	Doctor* doctorSelected = sistema->getDoctorPorID(doctorID);
	if (doctorSelected == nullptr) {
		system("cls");
		cout << "\n\tID inv" << char(160) << "lido" << endl;
		cin.ignore();
		cin.get();
		return;
	}

	system("cls");
	cout << sistema->mostrarSoloDuenos();
	cout << "\tID del due" << char(164) << "o: ";
	cin >> duenoID;

	Dueno* duenoSelected = sistema->getDuenoPorID(duenoID);
	if (duenoSelected == nullptr) {
		system("cls");
		cout << "\n\tID inv" << char(160) << "lido";
		cin.ignore();
		cin.get();
		return;
	}

	system("cls");
	cout << duenoSelected->mostrarMascotas();
	cout << "\tN" << char(163) << "mero de la mascota: ";
	cin >> mascotaIndex;
	Mascota* mascotaSelected = duenoSelected->getMascota(mascotaIndex - 1);

	Cita* cita = new Cita(dia, hora, doctorSelected, mascotaSelected, duenoSelected);
	if (sistema->agregarCita(cita)) {
		system("cls");
		cout << "\n\tCita registrada!";
		cin.ignore();
		cin.get();
	}
	else {
		system("cls");
		cout << "\n\tHorario no disponible :(";
		delete cita;
		cin.ignore();
		cin.get();
	}
}
void Menu::cancelarCita() {
	string dia;
	string hora;

	system("cls");
	cout << "\n\tD" << char(161) << "a (ej. Lunes): ";
	cin >> dia;
	cout << "\tHora (--:--): ";
	cin >> hora;

	Cita* cita = sistema->getCita(dia, hora);
	if (sistema->cancelarCita(cita)) {
		system("cls");
		cout << "\n\tCita eliminada!";
		cin.ignore();
		cin.get();
	}
	else {
		system("cls");
		cout << "\n\tNo se ha podido cancelar la cita :(";
		cin.ignore();
		cin.get();
	}
}
void Menu::mostrarCalendarioDoc() {
	int doctorID;
	system("cls");
	cout << sistema->mostrarDoctores();
	cout << "\tID del doctor: ";
	cin >> doctorID;

	Doctor* doctorSelected = sistema->getDoctorPorID(doctorID);
	if (doctorSelected == nullptr) {
		system("cls");
		cout << "\n\tID inv" << char(160) << "lido";
		cin.ignore();
		cin.get();
		return;
	}

	system("cls");
	cout << sistema->mostrarAgendaDoctor(doctorSelected);
	cin.ignore();
	cin.get();
}
void Menu::mostrarCitasDueno() {
	int duenoID;
	system("cls");
	cout << sistema->mostrarSoloDuenos();
	cout << "\tID del due" << char(164) << "o: ";
	cin >> duenoID;

	Dueno* duenoSelected = sistema->getDuenoPorID(duenoID);
	if (duenoSelected == nullptr) {
		system("cls");
		cout << "\n\tID inv" << char(160) << "lido";
		cin.ignore();
		cin.get();
		return;
	}

	system("cls");
	cout << sistema->mostrarAgendaDueno(duenoSelected);
	cin.ignore();
	cin.get();
}

void Menu::listadoEspecialidades() {
	system("cls");
	cout << sistema->mostrarEspecialidades();
	cin.ignore();
	cin.get();
}
void Menu::listadoDocPorEsp() {
	int especialidadID;

	system("cls");
	cout << sistema->mostrarEspecialidades();
	cout << "\tIngrese el ID de la especialidad: ";
	cin >> especialidadID;

	Especialidad* espSelected = sistema->getEspecialidadPorID(especialidadID);
	if (espSelected == nullptr) {
		system("cls");
		cout << "\n\tID inv" << char(160) << "lido";
		cin.ignore();
		cin.get();
		return;
	}

	system("cls");
	cout << espSelected->mostrarEspecialistas();
	cin.ignore();
	cin.get();
}
void Menu::mostrarDuenos() { // mostrar duenos con mascotas
	system("cls");
	cout << sistema->mostrarDuenos();
	cin.ignore();
	cin.get();
}
void Menu::mostrarPacientes() { // mostrar pacientes
	int doctorID;
	system("cls");
	cout << sistema->mostrarDoctores();
	cout << "\tID del doctor: ";
	cin >> doctorID;

	Doctor* doctorSelected = sistema->getDoctorPorID(doctorID);
	if (doctorSelected == nullptr) {
		system("cls");
		cout << "\n\tID inv" << char(160) << "lido";
		cin.ignore();
		cin.get();
		return;
	}

	system("cls");
	if (doctorSelected->getCantPacientes() == 0) {
		cout << "\n\tDr. " << doctorSelected->getNombre() << " no tiene pacientes";
		cin.ignore();
		cin.get();
		return;
	}
	cout << doctorSelected->mostrarPacientes();
	cin.ignore();
	cin.get();
}

Menu::~Menu() {
	delete sistema;
}
