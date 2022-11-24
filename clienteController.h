#include <iostream>
#include <vector>
#include <fstream>
#pragma once
#include "../model/client.h"

using namespace std;

class ClienteController
{
private:
	vector<Cliente> vectorCliente;
public:
	ClienteController()
	{
		cargarDatos();
	}
	void addCli(Cliente obj)
	{
		vectorCliente.push_back(obj);
	}
	Cliente getCli(int pos) 
	{
		return vectorCliente[pos];
	}
	int getCorrelativoCli()
	{
		if(sizeCli() == 0)
		{
			return 1;
		}
		else
		{
			return 	vectorCliente[sizeCli() - 1].getCodCliente() + 1;
		}
	}
			
	int sizeCli()
	{
		return vectorCliente.size();
	}
			
	Cliente buscarPorCod(int cod)
	{
		Cliente objError;
		objError.setNomApeCliente("Error");
		for (Cliente x : vectorCliente)
		{
			if (cod == x.getCodCliente())
			{
				return x;	
			}
		}
		return objError;
	}
	Cliente buscarPorString(string str)
	{
		Cliente	 objError;
		objError.setNomApeCliente("Error");
		for(int i=0;i<sizeCli();i++)
		{
			for(int j=0;j<(getCli(i).getNomApeCliente()).length();j++)
			{	
				if(str == (getCli(i).getNomApeCliente()).substr(0,j))
				{
					return getCli(i);
				}
			}
		}
		return objError;
	}
	void buscarPorString2(string str)
	{
		fstream archivoCliente;
		int r=0;
		int i;
		size_t posi;
		string temporal[4];
		string linea;
		if(!archivoCliente.is_open())
		{
			archivoCliente.open("clientes.csv",ios::in);
		}
		while(getline(archivoCliente,linea))
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
				cout<<"\t\t\t-Codigo Cliente:"<<temporal[0]<<endl;
				cout<<"\t\t\t-Nombre Cliente:"<<temporal[1]<<endl;
				cout<<"\t\t\t-Direccion:"<<temporal[2]<<endl;
				cout<<"\t\t\t-Numero de contacto:"<<temporal[3]<<endl;
				cout<<"\t\t\t--------------------------------"<<endl;
			}
			
			
		}
		if(r==0)
		{
			cout<<"\t\t\t"<<str<<" no encontrado..."<<endl;
			
			
		}
		/*for(int j=0;j<6;j++)
		{
		cout<<temporal[j]<<endl;
		}*/
		/*for(int i=0;i<sizePro();i++)
		{
		for(int j=0;j<(get(i).getNombre()).length();j++)
		{
		if(str == (get(i).getNombre()).substr(0,j))
		{
		cout<<get(i);
		}
		}
		}*/
	}
	int getPostArray(Cliente obj)
	{
		for(int i=0;i<sizeCli();i++)
		{
			if(obj.getCodCliente() == getCli(i).getCodCliente())
			{
				return i;
			}
		}
		return -1;
	}
	void eliminarCliente(Cliente obj)
	{
		vectorCliente.erase(vectorCliente.begin() + getPostArray(obj));
	}		
	bool modificar(Cliente obj,string nom,string dir,int ruc)
	{
		for(int i=0;i<sizeCli();i++)
		{
			if(obj.getCodCliente() == getCli(i).getCodCliente())
			{
				vectorCliente[i].setNomApeCliente(nom);
				vectorCliente[i].setDireccion(dir);
				vectorCliente[i].setRuc(ruc);
				
				return true;
			}
		}
		return false;
	}

	void grabarEnArchivo(Cliente cliente)
	{
		try 
		{		
			fstream archivoCliente;
			archivoCliente.open("clientes.csv", ios::app);
			if (archivoCliente.is_open())
			{
				archivoCliente << 	cliente.getCodCliente() 	<< ";" <<
									cliente.getNomApeCliente() << ";" <<
									cliente.getDireccion()  << ";" << 
									cliente.getRuc()  << ";" << endl;
						archivoCliente.close();			
			}
		}
		catch(exception e)
		{
			cout<< "Ocurrio un error al grabar el registro";
		}
	}
	void grabarModificarEliminarArchivo()
	{
		try
		{
			fstream archivoCliente;
			archivoCliente.open("clientes.csv",ios::out);
			if(archivoCliente.is_open())
			{
				for(Cliente x : vectorCliente)
				{
					archivoCliente<<x.getCodCliente()<<";"<<x.getNomApeCliente()<<";"<<x.getDireccion()<<";"<<x.getRuc()<<"\n";	
				}
				archivoCliente.close();
			}
		}
		catch(exception e)
		{
			cout<<"¡¡¡Ocurrio un error al grabar en el archivo!!!";
		}
	}
	void cargarDatos()
	{
		try
		{
			int i;
			size_t posicion; //Cantidad maxima
			string linea;
			string temporal[4];
			fstream archivoCliente;
			archivoCliente.open("clientes.csv", ios::in);
			if(archivoCliente.is_open())
			{
				while(!archivoCliente.eof())
				{
					while(getline(archivoCliente,linea))
					{
						i = 0;
						while((posicion = linea.find(";")) != string::npos) // string::npos = -1
						{
							temporal[i] = linea.substr(0, posicion); //substr obtiene/ saca una parte de la cadena
							linea.erase(0, posicion + 1); //se pone +1 para borrar el primer string(0) mas el ";"
							i++; 
						}

					Cliente	cliente;
						cliente.setCodCliente(stoi(temporal[0]));
						cliente.setNomApeCliente(temporal[1]);
						cliente.setDireccion(temporal[2]);
						cliente.setRuc(stoi(temporal[3]));
						addCli(cliente);
					}
				}
			} 
			archivoCliente.close();	
		}
		catch(exception e)
		{
			cout<< "Ocurrio un error al grabar el registro >:/";
		}
	}

	};
