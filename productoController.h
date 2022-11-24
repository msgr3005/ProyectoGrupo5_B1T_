#include <iostream>
#include <vector>
#include<fstream>
#pragma once
#include <conio.h>
#include <stdlib.h>
#include "../model/producto.h"
using namespace std;

class ProductoController
{
	private:
		vector<Producto>vectorProducto;
	public:
		ProductoController()
		{
			cargarDatosDelArchivoAlVector();
		}
	int getCorrelativo()
		{
			if(sizePro() == 0)
			{
				return 1;
			}
			else
			{
				return vectorProducto[sizePro() - 1].getCodigoProducto() + 1;
			}
		}
	void add(Producto obj) 
		{
			vectorProducto.push_back(obj);
		}
	Producto get (int pos)
		{
			return vectorProducto[pos];
		}
	int sizePro()
		{	
			return vectorProducto.size();
		}
	Producto buscarPorCodigo1(int codigo)
		{
			Producto objError;
			objError.setNombre("Error");
			for(Producto x:vectorProducto)
			{
				if(codigo == x.getCodigoProducto())
				{
					return x;
				}
			}
			return objError;
		}
		
	Producto buscarPorCodigo2(int codigo)
		{
			for(int i=0;i<sizePro();i++)
			{
				if(codigo == get(i).getCodigoProducto())
				{
					return get(i);
				}
			}
		}
	Producto buscarPorString(string str)
	{
		Producto objError;
		objError.setNombre("Error");
		for(int i=0;i<sizePro();i++)
		{
			for(int j=0;j<(get(i).getNombre()).length();j++)
			{	
				if(str == (get(i).getNombre()).substr(0,j))
				{
					for(int a=0;a<20;a++)
					{
						return get(i);
					}
				}
			}
		}
		return objError;
	}
	void buscarPorString2(string str)
	{
		fstream archivoProducto;
		int r = 0;
		int i;
		size_t posi;
		string temporal[6];
		string linea;
		if(!archivoProducto.is_open())
		{
			archivoProducto.open("productos.csv",ios::in);
		}
		while(getline(archivoProducto,linea))
		{
			if(linea.find(str) != string::npos)
			{
				//cout<<"\t\t\t"<<linea<<endl;
				r=1;
				i = 0;
				while((posi = linea.find(";")) != string::npos)
				{
					temporal[i] = linea.substr(0,posi);
					linea.erase(0,posi + 1);
					i++;
				}
				
				cout<<"\t\t\t-Codigo Categoria:"<<temporal[0]<<endl;
				cout<<"\t\t\t-Nombre Categoria:"<<temporal[1]<<endl;
				cout<<"\t\t\t-Codigo Producto:"<<temporal[2]<<endl;
				cout<<"\t\t\t-Nombre Producto:"<<temporal[3]<<endl;
				cout<<"\t\t\t-Precio:"<<temporal[4]<<endl;
				cout<<"\t\t\t-Stock:"<<temporal[5]<<endl;
				cout<<"\t\t\t--------------------------------"<<endl;
			}
			
		}
		if(r==0)
		{
			cout<<"\t\t\t"<<str<<" no encontrado..."<<endl;
			system("break");
		}
		
	}
	int getPostArray(Producto obj)
		{
			for(int i=0;i<sizePro();i++)
			{
				if(obj.getCodigoProducto() == get(i).getCodigoProducto())
				{
					return i;
				}
			}
			return -1;
		}
	void eliminarProducto(Producto obj)
		{
			vectorProducto.erase(vectorProducto.begin() + getPostArray(obj));
		}		
	bool modificar(Producto obj,string nom,float pre,int sto)
		{
			for(int i=0;i<sizePro();i++)
			{
				if(obj.getCodigoProducto() == get(i).getCodigoProducto())
				{
					vectorProducto[i].setNombre(nom);
					vectorProducto[i].setPrecio(pre);
					vectorProducto[i].setStock(sto);
					
					return true;
				}
			}
			return false;
		}
	void grabarEnArchivo(Producto producto)
		{
			try
			{
				fstream archivoProducto;
				archivoProducto.open("productos.csv",ios::app);
				if(archivoProducto.is_open())
				{
					archivoProducto<<producto.getCodCat()<<";"<<producto.getNomCat()<<";"<<producto.getCodigoProducto()<<";"<<producto.getNombre()<<";"<<producto.getPrecio()<<";"<<producto.getStock()<<";"<<endl;
					archivoProducto.close();
				}
			}
			catch(exception e)
			{
				cout<<"¡¡¡Ocurrio un error al grabar el registro!!!";
			}
		}
	void grabarModificarEliminarArchivo()
		{
			try
			{
				fstream archivoProductos;
				archivoProductos.open("productos.csv",ios::out);
				if(archivoProductos.is_open())
				{
					for(Producto x : vectorProducto)
					{
						archivoProductos<<x.getCodCat()<<";"<<x.getNomCat()<<";"<<x.getCodigoProducto()<<";"<<x.getNombre()<<";"<<x.getPrecio()<<";"<<x.getStock()<<";"<<"\n";	
					}
					archivoProductos.close();
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
				fstream archivoProducto;
				archivoProducto.open("productos.csv",ios::in);
				if(archivoProducto.is_open())
				{
					while(!archivoProducto.eof() && getline(archivoProducto, linea))
					{
							i = 0;
							while((posi = linea.find(";")) != string::npos)
							{
								temporal[i] = linea.substr(0,posi);
								linea.erase(0,posi + 1);
								i++;
							}
							//Crear un Objeto de Tipo Alumno
							Producto objPro(stoi(temporal[0]),temporal[1],
											stoi(temporal[2]),temporal[3], 
											stof(temporal[4]),stoi(temporal[5]));
						
							add(objPro);
						}
				}
				archivoProducto.close();
			}
			catch(exception e)
			{	
				cout<<"¡¡¡Ocurrio un error al cargar en el archivo!!!";
			}
		}
};
