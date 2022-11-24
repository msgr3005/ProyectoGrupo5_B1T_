#include <iostream>
#include <vector>
#include <fstream>
#include "../model/CUsuario.h"
using namespace std;
class CControladora
{
private:
	vector<CUsuario> _vectorUsuarios;
public:
	CControladora()
	{
		cargarDatosDelArchivoAlVector();
	}
	
	void addUsers(CUsuario user)
	{
		_vectorUsuarios.push_back(user);
	}
	CUsuario getPosition(int pos)
	{
		return _vectorUsuarios[pos];
	}
	int getSize()
	{
		return _vectorUsuarios.size();
	}
	int getCorrelativo()
	{
		if(getSize() == 0)
		{
			return 1;
		}
		else
		{
			return 	_vectorUsuarios[getSize() - 1].getCodigo() + 1;
		}
	}
	void saveArchive(CUsuario user)
	{
		try
		{
			fstream archivoUsuario;
			archivoUsuario.open("Usuarios.csv",ios::app);
			if(archivoUsuario.is_open())
			{
				archivoUsuario<<user.getCodigo()<<";"<<user.getUser()<<";"<<user.getPassword()<<";"<<endl;
				archivoUsuario.close();
			}
		}
		catch(exception e)
		{
			cout<<"Ocurrio un error al grabar el archivo";
		}
	}
	void saveArchiveBinary(CUsuario user)
	{
		try
		{
			ofstream archivoUsuario;
			archivoUsuario.open("usuarios.bin",ios::binary);
			if(archivoUsuario.is_open())
			{
				archivoUsuario.write((char*)&user,sizeof(CUsuario));
				archivoUsuario.close();
			}
		}
		catch(exception e)
		{
			cout<<"Ocurrio un error al grabar el archivo";
		}
	}
	void cargarDatosDelArchivoAlVector()
	{
		try 
		{
			int i;
			size_t 	posi;
			string 	linea;
			string 	temporal[3];
			fstream archivoUsuario;
			archivoUsuario.open("Usuarios.csv",ios::in);
			if(archivoUsuario.is_open())
			{
				while(!archivoUsuario.eof() && getline(archivoUsuario,linea))
				{
					i=0;
					while((posi = linea.find(";")) != string::npos)
					{
						temporal[i] = linea.substr(0,posi);
						linea.erase(0,posi+1);
						++i;
					}
					CUsuario objUsuario(stoi(temporal[0]),temporal[1],temporal[2]);
					addUsers(objUsuario);
				}
			}
		}
		catch(exception e)
		{
			cout<<"Ocurrio un error";
		}
	}
};

