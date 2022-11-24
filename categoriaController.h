#include <iostream>
#pragma once
#include <vector>
#include <fstream>
#include "../model/categoria.h"
using namespace std;
class CategoriaController
{
private:
	
	vector<Categoria> vectorCategoria;
public:
	CategoriaController()
	{
		cargarDatosDelArchivoAlVector();
	}
	void addCat(Categoria obj)
	{
		vectorCategoria.push_back(obj);
	}
	Categoria posCat(int pos)
	{
		return vectorCategoria[pos];
	}
	int sizeCat()
	{
		return vectorCategoria.size();
	}
	int getCorrelativoCat()
	{
		if(sizeCat() == 0)
		{
			return 1;
		}
		else
		{
			return 	vectorCategoria[sizeCat() - 1].getCodCat() + 1;
		}
	}
	void grabarEnArchivo(Categoria obj)
	{
		try
		{
			fstream archivoCategoria;
			archivoCategoria.open("categoria.csv",ios::app);
			if(archivoCategoria.is_open())
			{
				archivoCategoria<<obj.getCodCat()<<";"<<obj.getNomCat()<<";"<<endl;
				archivoCategoria.close();					
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
			int 	i;
			size_t 	posi;//Longitud
			string 	linea;
			string 	temporal[2];
			fstream	archivoCategoria;
			archivoCategoria.open("categoria.csv",ios::in);//Abre para lectura, situándose al principio.
			if(archivoCategoria.is_open())
			{
				while(!archivoCategoria.eof() && getline(archivoCategoria,linea))
				{
					i = 0;
					while((posi = linea.find(";")) != string::npos)
					{
						temporal[i] = linea.substr(0,posi);
						linea.erase(0,posi+1);
						++i;//Incrementa y devuelve
					}
					
					Categoria objCat(stoi(temporal[0]),temporal[1]);
					
					addCat(objCat);
				}
			}
		}
		catch(exception e)
		{
			cout<<"Ocurrio un error al grabar el archivo";
		}
	}
	bool modificar(Categoria ObjOld,Categoria ObjNew)
	{
		for(int i=0;i<vectorCategoria.size();i++)
		{
			if(ObjOld.getCodCat() == vectorCategoria[i].getCodCat())
			{
				vectorCategoria[i].setNomCat(ObjNew.getNomCat());

				return true;
			}
		}
		return false;
	}
	
	Categoria buscar(int dato)
	{
		Categoria objError;
		objError.setNomCat("Error");
		for(int i=0;i<vectorCategoria.size();i++)
		{
			if(dato == vectorCategoria[i].getCodCat())
			{
				return vectorCategoria[i];	
			}			
		}
		return objError;
	}
	
	int getPostArray(Categoria obj)
	{
		for(int i=0;i<sizeCat();i++)
		{
			if(obj.getCodCat() == posCat(i).getCodCat())
			{
				return i;
			}
		}
		return -1;
	}
	void eliminarCategoria(Categoria obj)
	{
		vectorCategoria.erase(vectorCategoria.begin() + getPostArray(obj));
	}		
	
	void grabarModificarEliminar()
	{
		try
		{
			fstream archivoCategoria;
			archivoCategoria.open("categoria.csv",ios::out);
			if(archivoCategoria.is_open())
			{
				for(Categoria x:vectorCategoria)
				{	
					archivoCategoria<<x.getCodCat()<<";"<<x.getNomCat()<<endl;
				}
				archivoCategoria.close();					
			}
		}
		catch(exception e)
		{
			cout<<"Ocurrio un error al grabar el archivo";
		}
	}
};

