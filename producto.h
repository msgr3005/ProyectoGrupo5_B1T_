#include<string>
#include "categoria.h"
#pragma once
using namespace std;

class Producto:public Categoria
{
	private:
	int codProducto;
	string nombre;
	float precio;
	int stock;
	
	public:
	Producto(int codCategoria,string nomCategoria,
			 int cod, string nom, float pre, int sto):Categoria(codCategoria,nomCategoria)
	{
		this -> codProducto = cod;
		this -> nombre = nom;
		this -> precio = pre;
		this -> stock = sto;
	}
	Producto(int codProducto, float precio)
	{
		
	}
	Producto()
	{
		
	}
	void setCodigoProducto(int cod)
	{
		codProducto = cod;
	}
	void setNombre(string nom)
	{
		nombre = nom;
	}
	void setPrecio(float pre)
	{
		precio = pre;
	}
	void setStock(int sto)
	{
		stock = sto;
	}
		
	int getCodigoProducto()
	{
		return this->codProducto;
	}
	string getNombre()
	{
		return this->nombre;
	}
	float getPrecio()
	{
		return this->precio;
	}
	int getStock()
	{
		return this->stock;
	}	
};
