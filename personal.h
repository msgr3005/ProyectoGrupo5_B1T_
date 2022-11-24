#include<string>
#include <iostream>
#pragma once
#include "tipoPersonal.h"
using namespace std;

class Personal:public TipoPersonal
{
private:
	int codPersonal;
	string nomApePersonal;
	string usuario;
	string contrasena;
	string dniPersonal;
	float sueldoPersonal;
	
	public:
		Personal(int codTipPersonal,string nomTipPersonal,int codPersonal,string nomApePersonal,string usuario,string contrasena,string dniPersonal,float sueldoPersonal
				):TipoPersonal(codTipPersonal,nomTipPersonal)
		{
			codPersonal = codPersonal;
			nomApePersonal = nomApePersonal;
			usuario = usuario;
			contrasena = contrasena;
			dniPersonal = dniPersonal;
			sueldoPersonal = sueldoPersonal;
		}
		Personal()
		{
			
		}
		//set
		void setCodPersonal(int codPer)
		{
			codPersonal = codPer;
		}
		void setNomApePersonal(string nomApePer)
		{
			nomApePersonal = nomApePer;
		}
		void setUsuario(string user)
		{
			usuario = user;
		}
		void setContrasena(string pass)
		{
			contrasena = pass;
		}
		void setDniPersonal(string dniPer)
		{
			dniPersonal = dniPer;
		}
		void setSueldoPersonal(float sueldoPer)
		{
			sueldoPersonal = sueldoPer;
		}
		//get
		int getCodPersonal()
		{
			return codPersonal;
		}
		string getNomApePersonal()
		{
			return nomApePersonal;
		}
		string getUsuario()
		{
			return usuario;
		}
		string getContrasena()
		{
			return contrasena;
		}
		string getDniPersonal()
		{
			return dniPersonal;
		}
		float getSueldoPersonal()
		{
			return sueldoPersonal;
		}
};
