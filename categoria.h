#include <iostream>
#pragma once
using namespace std;

class Categoria
{
private://Atributos
	int codCategoria;
	string nomCategoria;
	
public:/*Metodos*/
	/*/Constructores*/
	Categoria(int codCategoria,string nomCategoria)  
	{
		this->codCategoria = codCategoria;
		this->nomCategoria = nomCategoria;
	}
	Categoria()//REGLA: Se crea por defecto
	{
		
	}
	/*set*/
	void setCodCat(int codCat)
	{
		this->codCategoria = codCat;
	}
	void setNomCat(string nomCat)
	{
		this->nomCategoria = nomCat;
	}
	/*get*/
	int getCodCat()
	{
		return this->codCategoria;
	}
	string getNomCat()
	{
		return this->nomCategoria;
	}
};

