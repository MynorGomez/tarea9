
#include <iostream>
#include "Estudiante.h"
using namespace std;
int main()
{
	string codigo, nombres, apellidos, direccion, fecha_nacimiento;
	int telefono = 0, id_tipo_sangre = 0, id_estudiante = 0;

	cout << "Ingrese el codigo del estudiante: ";
	cin >> codigo;
	cout << "Ingrese el nombre del estudiante: ";
	getline(cin, nombres);
	cout << "Ingrese el apellido del estudiante: ";
	getline(cin, apellidos);
	cout << "Ingrese la direccion del estudiante: ";
	getline(cin, direccion);
	cout << "Ingrese el telefono del estudiante: ";
	cin >> telefono;
	cin.ignore(); // Limpiar el buffer de entrada
	cout << "Ingrese la fecha de nacimiento  (YYYY-MM-DD): ";
	getline(cin, fecha_nacimiento);
	cout << "Ingrese tipo de sangre: ";
	cin >> id_tipo_sangre;
	Estudiante e = Estudiante(nombres, apellidos, direccion, telefono, fecha_nacimiento, id_tipo_sangre, codigo, id_estudiante);
	e.crear();
	e.leer();

	cout << "Ingrese el id del estudiante a modificar: ";
	cin >> id_estudiante;

	cout << "Ingrese el codigo del estudiante: ";
	cin >> codigo;
	cout << "Ingrese el nombre del estudiante: ";
	getline(cin, nombres);
	cout << "Ingrese el apellido del estudiante: ";
	getline(cin, apellidos);
	cout << "Ingrese la direccion del estudiante: ";
	getline(cin, direccion);
	cout << "Ingrese el telefono del estudiante: ";
	cin >> telefono;
	cin.ignore(); // Limpiar el buffer de entrada
	cout << "Ingrese la fecha de nacimiento  (YYYY-MM-DD): ";
	getline(cin, fecha_nacimiento);
	cout << "Ingrese tipo de sangre: ";
	cin >> id_tipo_sangre;
	e.setIdEstudiante(id_estudiante);
	e.setCodigo(codigo);
	e.setNombres(nombres);
	e.setApellidos(apellidos);
	e.setDireccion(direccion);
	e.setTelefono(telefono);
	e.setFechaNacimiento(fecha_nacimiento);
	e.setIdTipoSangre(id_tipo_sangre);
	e.actualizar();	
	e.leer();
	cout << "Ingrese el id del estudiante a eliminar: ";
	cin >> id_estudiante;
	e.setIdEstudiante(id_estudiante);
	e.borrar();
	e.leer();

}
