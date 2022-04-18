#include "Manejo.h"
#include <windows.h>
#include <vector>
#include <sstream>
#include <fstream>
#include <functional>
#include <Windows.h>
#include <ctime>
#include <iostream>

using namespace std;

void  lectura(vector<string>*&arreglo)
{
	ifstream archivo;
	archivo.open("Usuarios.txt ");
	if (archivo.fail())
	{
		cout << " Hubo un error al abrir el archivo ";
		exit(1);
	}

	while (!archivo.eof())
	{
		string texto;
		getline(archivo, texto, '\n');
		arreglo->push_back(texto);
	}
	archivo.close();
}

bool buscar_Palabra(string palabra, string texto)
{
	for (size_t i = 0; i <= texto.size() - palabra.size(); i++)
	{
		if (texto[i] == palabra[0])
		{
			int contador = 1;
			i++;
			for (size_t e = 1; e < palabra.size(); e++, i++)
			{
				if (texto[i] == palabra[e])
				{
					contador++;
				}
			}
			if (contador == palabra.size())
			{
				return true;
			}
		}
	}
	return false;
}


bool verificar(function<int(string)> noValido, string nombre)
{
	system("CLS");
	if (noValido(nombre) == std::string::npos)
	{
		cout << "No se ingreso un archivo con extension .txt" << endl << endl;
		return false;
	}
	else return true;
}

bool repeticion(vector<string> v, string nombre, bool verif)
{
	if (verif == true) system("CLS");

	if (find(v.begin(), v.end(), nombre) == v.end())
	{
		cout << "Ya existe un archivo con ese nombre." << endl << endl;
		return false;
	}
	else return true;
}

bool repeticion(vector<string> v, string nombre)
{
	if (find(v.begin(), v.end(), nombre) != v.end())
	{
		cout << "Ya existe un archivo con ese nombre." << endl << endl;
		return false;
	}
	else return true;
}

int main()
{
	Manejo arch;
	char opcion = '0';
	vector<string> archivos;
	vector<string> users;
	auto checkTxt = [](string nombre)->int {return nombre.find(".txt"); };

	vector<string>* texto = new vector<string>();
	lectura(texto);
	string texto2 = "";
	for (size_t i = 0; i < texto->size(); i++)
	{
		texto2 += texto->at(i);
	}

	while (opcion != '10')
	{
		cout << "\t******************************************************************" << endl; 
		cout << "\t***********   BIENVENIDO, A TU GESTOR DE PLAY LIST    ************" << endl; 
		cout << "\t******************************************************************" << endl << endl;
		cout << "\t1. Crear usuario" << endl;
		cout << "\t2. Crear Play List" << endl;
		cout << "\t3. Leer Play List" << endl;
		cout << "\t4. Editar Play List" << endl;
		cout << "\t5. Renombrar archivo" << endl;
		cout << "\t6. Borrar archivo" << endl;
		cout << "\t7. Mostrar archivos (segun usuarios)" << endl;
		cout << "\t8. Buscar palabra en archivo" << endl;
		cout << "\tx. Finalizar sesion" << endl << endl;
		cout << "\tIngrese una opcion: "; cin >> opcion;

		switch (opcion)
		{
		case '1':
		{
			system("CLS");
			string nombre;
			
			/*Usuario user;*/
			while (1)
			{
				bool validar = false;
				cout << "Ingresa el nombre del usuario: "; cin >> nombre;
				
				system("CLS"); 
				
				ofstream entrada;
				entrada.open("Usuarios.txt", ios::app);
	
				if (buscar_Palabra(nombre, texto2)) {
					entrada.close();
					cout << "El usuario ya fue creado";

				}
				else {

					texto2 += nombre;
					entrada << nombre << endl;
					entrada.close();
					cout << "Se creó el usuario correctamente" << endl;

				}
				

				if (find(users.begin(), users.end(), nombre) == users.end());

				Sleep(3000); break;
			}

			/*user.crearUsuario(nombre);*/
			users.push_back(nombre);
			break;
		}
		case '2':
		{
			system("CLS");
			string texto, nombre, user;
			/*char texto[200];*/
			Manejo arch;
			bool res1 = false, res2 = false;

			while (res2 == false)
			{
				cout << "Ingresa el nombre del usuario: ";
				cin >> user;
				res2 = repeticion(users, user, false);
				if (res2 == true) break;
				else
				{
					system("CLS");
					cout << "No existe un usuario con ese nombre" << endl;
				}
			}
			system("CLS");
			res2 = false;

			while (res1 == false || res2 == false)
			{
				cout << "Ingresa el nombre del archivo: " << endl;
				cin >> nombre;
				nombre += ".txt";
				res1 = verificar(checkTxt, nombre);
				res2 = repeticion(archivos, nombre);
				if (res1 == true && res2 == true)break;
			}

			cin.ignore();
			cout << "Ingresa la informacion del archivo: ";
			getline(cin, texto);

			system("CLS");

			arch.crearArch(nombre, texto);
			archivos.push_back(nombre + ", creado por el usuario: " + user);
			break;
		}
		case '3':
		{
			system("CLS");
			string nombre;
		
			bool res = false;

			while (res == false)
			{
				cout << "Ingresa el nombre del archivo a leer." << endl;
				cin >> nombre;
				nombre += ".txt";
				res = verificar(checkTxt, nombre);
				if (res == true)break;
			}

			arch.leerArch(nombre);
			break;
		}
		case '4': {
			system("CLS");
			char nomb[60];
			string texto;
			
			bool res1 = false;
			while (res1 == false)
			{
				cout << "Ingresa el nombre la play list a editar." << endl << "no olvide incluir la extension del archivo (.txt):";
				cin >> nomb;
				res1 = verificar(checkTxt, nomb);
				if (res1 == true)break;
			}
			arch.editarArch(nomb);
			break;
		}
		case '5':
		{
			system("CLS");
			char nomb[60], nuevo[60];
			
			bool res1 = false, res2 = false;

			while (res1 == false || res2 == false)
			{
				cout << "Ingresa el nombre del genero de la musica a renombrar." << endl << "No olvide incluir la extension del archivo (.txt): ";
				cin >> nomb;
				res1 = verificar(checkTxt, nomb);
				res2 = repeticion(archivos, nomb, res1);
				if (res1 == true && res2 == true)break;
			}

			res1 = res2 = false;
			system("CLS");

			while (res1 == false || res2 == false)
			{
				cout << "Ingresa el nombre nuevo del archivo: ";
				cin >> nuevo;
				res1 = verificar(checkTxt, nuevo);
				res2 = repeticion(archivos, nuevo, res1);
				if (res1 == true && res2 == true)break;
			}

			arch.renombrarArch(nomb, nuevo);
			break;
		}
		case '6':
		{
			system("CLS");
			char nombre[60];
			
			bool res = false;

			while (res == false)
			{
				cout << "Ingresa el nombre del archivo a borrar." << endl << "No olvide incluir la extension del archivo (.txt): ";
				cin >> nombre;
				bool res = verificar(checkTxt, nombre);
				if (res == true)break;
			}

			arch.borrarArch(nombre);
			break;
		}
		case '7':
		{
			system("CLS");
			string exit;
			for (int i = 0; i <= archivos.size() - 1; i++)
			{
				cout << archivos[i] << endl;
			}
			while (1)
			{
				cout << endl << "Estos son los archivos creados." << endl;
				cout << "Ingrese cualquier tecla para continuar...	";
				exit = _getch();
				if (exit.size() != 0) { system("CLS"); break; }
				system("CLS");
			}
		}
		case '8':
		{
			system("CLS");
			string exit, nombre;
			
			bool res = false;
			while (res == false)
			{
				cout << "Ingresa el nombre del archivo para buscar palabra." << endl << "No olvide incluir la extension del archivo (.txt): ";
				cin >> nombre;
				bool res = verificar(checkTxt, nombre);
				if (res == true)break;
			}
			arch.buscarpal(nombre);
			break;
		}
		default:
			break;
		}
		if (opcion == 'x')break;
		opcion = '0';
		system("CLS");
	}
	system("del *.txt");
	return 0;
}