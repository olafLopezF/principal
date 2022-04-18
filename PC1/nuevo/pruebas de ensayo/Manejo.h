#pragma once
#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <conio.h>
#include<Windows.h>
using namespace std;

class Manejo
{
public:
	void crearArch(string nombre, string texto);
	void leerArch(string nombre);
	void borrarArch(char nomb[60]);
	void renombrarArch(char nomb[60], char nuevo[60]);
	void editarArch(char nomb[60]);
	void comentarArch(string nombre);
	void buscarpal(string nombre);
	bool buscarusuario(string nombre);
};