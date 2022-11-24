#include <iostream>
#include <vector>
#include <fstream>
#include "../model/detalleVenta.h"
using namespace std;

class DetVentaController
{
private:
	vector <DetalleVenta> vectorDVenta;
public:
	DetVentaController()
	{
	}
	void add(DetalleVenta obj) //Agregar objetos al vector
	{
		vectorDVenta.push_back(obj);
	}
	DetalleVenta get(int pos) // Entregar el objeto actual, segun la posicion pasada como parámetro
	{
		return vectorDVenta[pos];
	}
	int size()
	{
		return vectorDVenta.size();
	}

	
	/******************************************/
	void grabarEnArchivoDV(DetalleVenta Dventa)
	{
		try 
		{		
			fstream archivoDVenta;
			archivoDVenta.open("DetalleVenta.csv", ios::app);
			if (archivoDVenta.is_open())
			{
				archivoDVenta<< Dventa.getCodVen()<<";"<<	
								Dventa.getCodigoProducto()<<";"<<
								Dventa.getPrecio()<<";"<<
								Dventa.getCantidadDV()<<";"<<
								Dventa.getPrecioDV()<<";"<<endl;
				archivoDVenta.close();			
			}
		}
		catch(exception e)
		{
			cout<< "Ocurrio un error al grabar el registro B/";
		}
	}
	void cargarDatos()
	{
		try
		{
			int i;
			size_t posicion; //Cantidad maxima
			string linea;
			string temporal[5];
			fstream archivoDVenta;
			archivoDVenta.open("DetalleVenta.csv", ios::in);
			if(archivoDVenta.is_open())
			{
				while(!archivoDVenta.eof())
				{
					while(getline(archivoDVenta,linea))
					{
						i = 0;
						while((posicion = linea.find(";")) != string::npos) // string::npos = -1
						{
							temporal[i] = linea.substr(0, posicion); //substr obtiene/ saca una parte de la cadena
							linea.erase(0, posicion + 1); //se pone +1 para borrar el primer string(0) mas el ";"
							i++; 
						}
						
						DetalleVenta	detVenta;
						detVenta.setCodVen(stoi(temporal[0]));
						detVenta.setCodigoProducto(stoi(temporal[1]));
						detVenta.setPrecio(stof(temporal[2]));
						detVenta.setCantidadDV(stoi(temporal[3]));
						detVenta.setPrecioDV(stof(temporal[4]));
				
						add(detVenta);
					}
				}
			} 
			archivoDVenta.close();	
		}
		catch(exception e)
		{
			cout<< "Ocurrio un error al grabar el registro >:/";
		}
	}
	
	/******************************************/
	
	
	
	
};
