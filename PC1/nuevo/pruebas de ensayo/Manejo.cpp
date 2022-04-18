#include "Manejo.h"

void Manejo::crearArch(string nombre, string texto)
{
	ofstream input;
	input.open(nombre);
	input << texto << endl;
	input.close();
}


void Manejo::leerArch(string nombre)
{
	string resultado, exit;
	fstream output(nombre, ios::in);
	getline(output, resultado);
	output.close();

	while (1)
	{
		cout << "Contenido: " << resultado << endl << endl;
		cout << "Ingrese cualquier tecla para continuar...	";
		exit = _getch();
		if (exit.size() != 0) { system("CLS"); break; }
		system("CLS");
	}
}

void Manejo::borrarArch(char nomb[60])
{
	string exit;
	int k = remove(nomb);

	if (k != 0)cout << "No hay archivo con ese nombre y extension." << endl;
	else
	{
		while (1)
		{
			cout << "El archivo " << nomb << " ha sido eliminado." << endl;
			cout << "Ingrese cualquier tecla para continuar...	";
			exit = _getch();
			if (exit.size() != 0) { system("CLS"); break; }
			system("CLS");
		}
	}
}

void Manejo::renombrarArch(char nomb[60], char nuevo[60])
{
	string exit;

	int k = rename(nomb, nuevo);
	if (k != 0)cout << "No hay archivo con ese nombre y extension." << endl;
	else
	{
		while (1)
		{
			cout << "El archivo " << nomb << " ha sido renombrado." << endl;
			cout << "Ingrese cualquier tecla para continuar...	";
			exit = _getch();
			if (exit.size() != 0) { system("CLS"); break; }
			system("CLS");
		}
	}
}
void Manejo::editarArch(char nomb[60]) {
	string exit, buscar, reemplazar, texto;
	cout << "Ingrese el genero de musica que deseas editar en el archivo: " << endl;
	cin >> buscar;
	cout << "Ingrese el genero de musica que deseas reemplazar: " << endl;
	cin >> reemplazar;

	fstream fs(nomb);
	ofstream fstemp("archivotemp.txt");
	ifstream archivo;
	archivo.open(nomb, ios::in);
	while (!archivo.eof())
	{
		getline(archivo, texto);
	}
	while (fs >> texto)
	{
		if (texto == buscar)
		{
			texto = reemplazar;
		}
		fstemp << texto << endl;
	}
	fs.close();
	archivo.close();
	fstemp.close();
	int k = remove(nomb);
	k = rename("archivotemp.txt", nomb);
}
void Manejo::comentarArch(string nombre)
{
	string exit, comentario;
	cout << "Ingrese el genero de musica que desea agregar al archivo: " << endl;
	getline(cin, comentario);
	fstream arch(nombre, ios::out | ios::app);
	arch << comentario << endl;
	arch.close();
	while (1)
	{
		cout << "Se ha agregado el play list " << comentario << " al archivo " << nombre << endl;
		cout << "Ingrese cualquier tecla para continuar... ";
		exit = _getch();
		if (exit.size() != 0) { system("CLS"); break; }
		system("CLS");
	}
}

void Manejo::buscarpal(string nombre)
{
	fstream archivo;
	string palabra1, palabra2, exit;
	cout << "ingrese la palabra que quiere buscar: " << endl;
	cin >> palabra1;
	archivo.open(nombre.c_str());
	getline(archivo, palabra2);

	if (palabra2.find(palabra1))
	{
		while (1)
		{
			cout << "Se hallo la palabra " << palabra1 << " en el archivo " << endl;
			cout << "Ingrese cualquier tecla para continuar... ";
			exit = _getch();
			if (exit.size() != 0) { system("CLS"); break; }
			system("CLS");
		}
	}
	else { cout << "No se hallo la palabra en el archivo."; Sleep(2000); }
	archivo.close();
}

bool Manejo::buscarusuario(string nombre)
{
	fstream archivo;
	string palabra1, palabra2, exit;
	
	archivo.open("Usuarios.txt",ios::out);
	getline(archivo, palabra2);

	if (palabra2.find(nombre))
	{
	
		return true;
	}
	else { cout << "El usuario ya fue creado"; Sleep(2000); }
	archivo.close();
}

