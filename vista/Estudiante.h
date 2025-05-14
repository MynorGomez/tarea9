#pragma once
#include "Persona.h"
#include "ConexionDB.h"
#include <iostream>
#include <mysql.h>
#include <string>
class Estudiante : Persona{

private: string codigo;
	   int id_estudiante = 0;
public: //constructor
	   Estudiante() {}
	   Estudiante(string nom, string ape, string dir, int tel, string fn, int id_ts, string cod, int id_e) : Persona (nom, ape,dir, tel, fn, id_ts ){
		   codigo = cod;
		   id_estudiante = id_e;

}
	   //metodo set (modificar un atributo)
	   //metodo get (mmostrar contenido de un atributo)
	   void setIdEstudiante(int e) {
		   id_estudiante = e;
	   }
	   void setCodigo(string c) {
		   codigo = c;
	   }
	   void setNombres(string n) {
		   nombres = n;
	   }
	   void setApellidos(string a) {
		   apellidos = a;
	   }
	   void setDireccion(string d) {
		   direccion = d;
	   }
	   void setTelefono(int t) {
		   telefono = t;
	   }
	   void setFechaNacimiento(string fn) {
		   fecha_nacimiento = fn;
	   }
	   void setIdTipoSangre(int ts) {
		   id_tipo_sangre = ts;
	   }
	   //metodo get
	   int getId_estudiante() { return id_estudiante; }
	   string getNombres() { return nombres; }
	   string getApellidos() { return apellidos; }
	   string getDireccion() { return direccion; }
	   int getTelefono() { return telefono; }
	   string getFecha_nacimiento() { return fecha_nacimiento; }
	   int getIdTipo_sangre() { return id_tipo_sangre; }


	   void crear() {
		   int q_estado = 0;
		   ConexionDB cn = ConexionDB();
		   cn.abrir_conexion();
		   if (cn.getConector()) {

			   string t = to_string(telefono);
			   string id_ts = to_string(id_tipo_sangre);
			   string consulta= "insert into estudiantes(codigo, nombres, apellidos, direccion, telefono, fecha_nacimiento, id_tipo_sangre) values ('" + codigo + "','" + nombres + "','" + apellidos + "','" + direccion + "'," + t + ",'" + fecha_nacimiento + "'," + id_ts + ");";
			   const char* c = consulta.c_str();
			   q_estado = mysql_query(cn.getConector(), c);
			   if (!q_estado) {
				   cout << "Registro Exitoso" << endl;
			   }
			   else {
				   cout << "Error al registrar" << endl;
			   }
		   }
		   else {
			   cout << "Error de conexion" << endl;
		   }
		   cn.cerrar_conexion();
	   
	   
	   
	   }
	   void leer() {
		   int q_estado = 0;
		   ConexionDB cn = ConexionDB();
		   MYSQL_ROW fila;
		   MYSQL_RES* resultado;
		   cn.abrir_conexion();
		   if (cn.getConector()) {
			   cout << "_________Datos del Estudiante_______" << endl;
			   string consulta = "select e.id_estudiante as id, e.codigo, e.nombres, e.apellidos, e.direccion, e.telefono, e.fecha_nacimiento, ts.sangre from estudiantes as e inner join tipos_sangre as ts on e.id_tipo_sangre = ts.id_tipo_sangre; ";
			   const char* c = consulta.c_str();
			   q_estado = mysql_query(cn.getConector(), c);
			   if (!q_estado) {
				   resultado = mysql_store_result(cn.getConector());
				   while ((fila = mysql_fetch_row(resultado))) {
					   cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] << endl;

				   }
			   }
			   else {
				   cout << "Error en la consulta" << endl;
			   }
		   }
		   else { 
			   cout << "Error de conexion" << endl;
		   }
		   
		   cn.cerrar_conexion();

	   
	   }
	   void actualizar() {

		   int q_estado = 0;
		   ConexionDB cn = ConexionDB();
		   cn.abrir_conexion();
		   if (cn.getConector()) {
			   string id_e = to_string(id_estudiante);
			   string t = to_string(telefono);
			   string id_ts = to_string(id_tipo_sangre);
			   string consulta = "update estudiantes set codigo = '" + codigo + "' , nombres = '" + nombres + "', apellidos = '" + apellidos + "', direccion = '" + direccion + "', telefono = " + t + " , fecha_nacimiento '" + fecha_nacimiento + "', id_tipo_sangre =  " + id_ts + " where id_estudiante = "+id_e+ "";
			   const char* c = consulta.c_str();
			   q_estado = mysql_query(cn.getConector(), c);
			   if (!q_estado) {
				   cout << "Modificacion Exitoso" << endl;
			   }
			   else {
				   cout << "Error al registrar" << endl;
			   }
		   }
		   else {
			   cout << "Error de conexion" << endl;
		   }
		   cn.cerrar_conexion();



	   }
	   void borrar() {

		   int q_estado = 0;
		   ConexionDB cn = ConexionDB();
		   cn.abrir_conexion();
		   if (cn.getConector()) {
			   string id_e = to_string(id_estudiante);
			   string t = to_string(telefono);
			   string id_ts = to_string(id_tipo_sangre);
			   string consulta = "delet from estudiantes  where id_estudiante = " + id_e + "";
			   const char* c = consulta.c_str();
			   q_estado = mysql_query(cn.getConector(), c);
			   if (!q_estado) {
				   cout << "eliminacion de datos Exitoso" << endl;
			   }
			   else {
				   cout << "Error al registrar" << endl;
			   }
		   }
		   else {
			   cout << "Error de conexion" << endl;
		   }
		   cn.cerrar_conexion();


	   }

};