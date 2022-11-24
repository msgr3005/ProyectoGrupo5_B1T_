#include <iostream>
#include <vector>
#include "../model/venta.h"
using namespace std;

class VentaController
{
private:
	vector<Venta> vectorVenta;
public:
	VentaController()
	{
		cargarDatos();
	}
	void add(Venta obj) //Agregar objetos al vector
	{
		vectorVenta.push_back(obj);
	}
	Venta get(int pos) // Entregar el objeto actual, segun la posicion pasada como parámetro
	{
		return vectorVenta[pos];
	}
	int size()
	{
		return vectorVenta.size();
	}
	int getCorrelativo()
	{
		if(size() == 0)
		{
			return 1;
		}
		else
		{
			return vectorVenta[size() - 1].getCodVen() + 1;
		}
	}
	int getCorrNumVenta()
	{
		if(size()==0)
		{
			return 001;
		}
		else
		{
			return vectorVenta[size()-1].getNumVenta()+1;
		}
	}
	
	void grabarEnArchivo(Venta venta)
	{
		try 
		{		
			fstream archivoVenta;
			archivoVenta.open("venta.csv", ios::app);
			if (archivoVenta.is_open())
			{
				archivoVenta << venta.getCodVen() << ";" <<
					venta.getFecha()  << ";" <<
					venta.getNumVenta()  << ";" <<
					venta.getTotal()  << ";" << 
					venta.getEstado() << ";" <<
					venta.getCodCliente()<<";"<<endl;
				archivoVenta.close();			
			}
		}
		catch(exception e)
		{
			cout<< "Ocurrio un error al grabar el registro °:/";
		}
	}
	
	void cargarDatos()
	{
		try
		{
			int i;
			size_t posicion; //Cantidad maxima
			string linea;
			string temporal[6];
			fstream archivoVenta;
			archivoVenta.open("venta.csv", ios::in);
			if(archivoVenta.is_open())
			{
				while(!archivoVenta.eof())
				{
					while(getline(archivoVenta,linea))
					{
						i = 0;
						while((posicion = linea.find(";")) != string::npos) // string::npos = -1
						{
							temporal[i] = linea.substr(0, posicion); //substr obtiene/ saca una parte de la cadena
							linea.erase(0, posicion + 1); //se pone +1 para borrar el primer string(0) mas el ";"
							i++; 
						}
						
						//Crear un objeto de tipo alumno
						Venta venta;
						
						venta.setCodVen(stoi(temporal[0]));
						venta.setFecha(temporal[1]);
						venta.setNumVenta(stoi(temporal[2]));
						venta.setTotal(stof(temporal[3]));
						venta.setEstado(temporal[4]);
						venta.setCodCliente(stoi(temporal[5]));
						add(venta);
					}						
				}
			} 
			archivoVenta.close();	
		}
		catch(exception e)
		{
			cout<< "Ocurrio un error al grabar el registro |:/";
		}
	}
};
