#include <iostream>
#pragma once
using namespace std;
class Cliente
{
	private:
		int codCliente;
		string nomApeClie;
		string direccion;
		int ruc;
		
	public:
		Cliente(int codCliente,string nomApeClie, string direccion, int ruc)
		{
			this -> codCliente = codCliente;
			this -> nomApeClie = nomApeClie;
			this -> direccion = direccion;
			this -> ruc = ruc;
		}
		Cliente(int codCliente)
		{
			
		}
		Cliente()
		{
			
		}
		void setCodCliente(int cod)
		{
			codCliente= cod;
		}
		void setNomApeCliente(string nomApe)
		{
			nomApeClie = nomApe;
		}
		void setDireccion(string dir)
		{
			direccion = dir;
		}
		void setRuc(int r)
		{
			ruc = r;
		}
		
		int getCodCliente()
		{
			return this -> codCliente;
		}
		string getNomApeCliente()
		{
			return this->nomApeClie;
		}
		string getDireccion()
		{
			return this -> direccion;
		}
		int getRuc()
		{
			return this -> ruc;
		}
		
};
