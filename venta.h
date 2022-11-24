#include <iostream>
#pragma once
#include "client.h"
using namespace std;

class Venta:public Cliente
{
private:
	int		codVenta;
	string	fecha;
	int 	numVenta;
	float 	total;
	string		estado;
public:
	Venta(int codVen,string fecha,int numVen,float total, string estado, int codCliente): Cliente(codCliente)
	{
		this ->	codVenta 	= codVen;
		this -> fecha 		= fecha;
		this -> numVenta    = numVen;
		this -> total 		= total;
		this -> estado 		= estado;
		
	}
	Venta(int codVenta){
	}
	Venta()
	{
		
	}

	
	//set
	void setCodVen(int codVen)
	{
		codVenta = codVen;
	}	
	void setFecha(string fec)
	{
		fecha = fec;
	}
	void setNumVenta(int numV)
	{
		numVenta = numV;
	}
	void setTotal(float tot)
	{
		total = tot;
	}
	void setEstado(string est)
	{
		estado = est;
	}
	//get
	int getCodVen() 
	{
		return this -> codVenta;
	}
	
	string getFecha()
	{
		return this -> fecha;
	}
	int getNumVenta()
	{
		return this -> numVenta;
	}
	float getTotal()
	{
		return this -> total;
	}
	string getEstado()
	{
		return this -> estado;
	}
	
};
