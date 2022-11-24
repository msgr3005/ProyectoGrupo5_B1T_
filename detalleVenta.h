#include <iostream>
#pragma once
#include "venta.h"
#include "producto.h"
using namespace std;
class DetalleVenta: public Producto, public Venta
{
	private:
		int cantidadDV;
		float precioDV;
	public:
	DetalleVenta(int codVenta,int codProducto,float precio, int _cantidadDV,float _precioDV):Venta(codVenta),Producto(codProducto,precio)
	{
		this->cantidadDV = _cantidadDV;
		this->precioDV = _precioDV;
	}
	DetalleVenta()
	{
	}
	~DetalleVenta()
	{
	}
	//SET
	void setCantidadDV(int cantDV)
	{
		cantidadDV = cantDV;
	}

	void setPrecioDV(float preDV)
	{
		precioDV = preDV;
	}
	
	// GET 
	int getCantidadDV()
	{
		return this->cantidadDV;
	}	
	float getPrecioDV()
	{
		return this->precioDV;
	}
	
};
