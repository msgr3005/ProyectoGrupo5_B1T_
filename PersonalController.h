#include <iostream>
#include <vector>
#include<fstream>
#include <conio.h>
#pragma once
#include <stdlib.h>
#include "../model/personal.h"

using namespace std;

class PersonalController
{
	private:
		vector<Personal> vectorPersonal;
	public:
		PersonalController()
		{
			cargarDatosDelArchivoAlVector();
		}
	int getCorrelativo()
		{
			if(vectorPersonal.size() == 0)
			{
				return 1;
			}
			else
			{
				return vectorPersonal[vectorPersonal.size() - 1].getCodPersonal() + 1;
			}
		}
	void add(Personal obj) 
		{
			vectorPersonal.push_back(obj);
		}
	Personal get(int pos)
		{
			return vectorPersonal[pos];
		}
	int sizePer()
		{	
			return vectorPersonal.size();
		}
	Personal buscarPorCodigo1(int codigo)
		{
			Personal objError;
			objError.setNomApePersonal("Error");
			for(Personal x:vectorPersonal)
			{
				if(codigo == x.getCodPersonal())
				{
					return x;
				}
			}
			return objError;
		}
	Personal buscarPorCodigo2(int codigo)
		{
			for(int i=0;i<sizePer();i++)
			{
				if(codigo == get(i).getCodPersonal())
				{
					return get(i);
				}
			}
		}
	int getPostArray(Personal obj)
		{
			for(int i=0;i<sizePer();i++)
			{
				if(obj.getCodPersonal() == get(i).getCodPersonal())
				{
					return i;
				}
			}
			return -1;
		}
	void remove(Personal obj)
		{
			vectorPersonal.erase(vectorPersonal.begin() + getPostArray(obj));
		}		
	bool modificar(Personal obj,string nom,string usu,string contra,string dni,float sueldo)
		{
			for(int i=0;i<sizePer();i++)
			{
				if(obj.getCodPersonal() == get(i).getCodPersonal())
				{
					vectorPersonal[i].setNomApePersonal(nom);
					vectorPersonal[i].setUsuario(usu);
					vectorPersonal[i].setContrasena(contra);
					vectorPersonal[i].setDniPersonal(dni);
					vectorPersonal[i].setSueldoPersonal(sueldo);
					
					return true;
				}
			}
			return false;
		}
	void grabarEnArchivo(Personal personal)
		{
			try
			{
				fstream archivoPersonal;
				archivoPersonal.open("personal.csv",ios::app);
				if(archivoPersonal.is_open())
				{
					archivoPersonal<<personal.getCodPersonal()<<";"<<personal.getNomApePersonal()<<";"<<personal.getUsuario()<<";"<<personal.getContrasena()<<";"<<personal.getDniPersonal()<<";"<<personal.getSueldoPersonal()<<";"<<endl;
					archivoPersonal.close();
				}
			}
			catch(exception e)
			{
				cout<<"¡¡¡Ocurrio un error al grabar el registro!!!";
			}
		}
	void grabarModificarArchivo()
		{
			try
			{
				fstream archivoPersonal;
				archivoPersonal.open("personal.csv",ios::out);
				if(archivoPersonal.is_open())
				{
					for(Personal x : vectorPersonal)
					{
						archivoPersonal<<x.getCodPersonal()<<";"<<x.getNomApePersonal()<<";"<<x.getUsuario()<<";"<<x.getContrasena()<<";"<<x.getDniPersonal()<<";"<<x.getSueldoPersonal()<<";\n";	
					}
					archivoPersonal.close();
				}
			}
			catch(exception e)
			{
				cout<<"¡¡¡Ocurrio un error al grabar en el archivo!!!";
			}
		}
	void cargarDatosDelArchivoAlVector()
		{
			try
			{
				int i;
				size_t 	posi; //Cantidad Maxima
				string 	linea;
				string 	temporal[6];  //Cantidad de Columnas
				fstream archivoPersonal;
				archivoPersonal.open("personal.csv",ios::in);
				if(archivoPersonal.is_open())
				{
					while(!archivoPersonal.eof() && getline(archivoPersonal, linea))
					{
							i = 0;
							while((posi = linea.find(";")) != string::npos)
							{
								temporal[i] = linea.substr(0,posi);
								linea.erase(0,posi + 1);
								i++;
							}
							//Crear un Objeto de Tipo Alumno
							Personal personal;
							personal.setCodPersonal(stoi(temporal[0]));
							personal.setNomApePersonal(temporal[1]);
							personal.setUsuario(temporal[2]);
							personal.setContrasena(temporal[3]);
							personal.setDniPersonal(temporal[4]);
							personal.setSueldoPersonal(stof(temporal[4]));
						
							add(personal);
					}
				}
				archivoPersonal.close();
			}
			catch(exception e)
			{	
				cout<<"¡¡¡Ocurrio un error al cargar en el archivo!!!";
			}
		}
};
