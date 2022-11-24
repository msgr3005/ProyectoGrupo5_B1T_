#include <iostream>
#pragma once
using namespace std;
class TipoPersonal
{
private:
	int codTipPersonal;
	string nomTipPersonal;
public:
	TipoPersonal(int codTipPersonal,string nomTipPersonal)
	{
		codTipPersonal = codTipPersonal;
		nomTipPersonal = nomTipPersonal;
	}
	TipoPersonal()
	{
		
	}
	//set
	void setCodTipPersonal(int codTipPer)
	{
		codTipPersonal = codTipPer;
	}
	void setNomTipPersonal(string nomTipPer)
	{
		nomTipPersonal = nomTipPer;
	}
	//get
	int getCodTipPersonal()
	{
		return codTipPersonal;
	}
	string getNomTipPersonal()
	{
		return nomTipPersonal;
	}
};
