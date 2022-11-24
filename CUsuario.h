#include <iostream>
using namespace std;
class CUsuario
{
private:
	string _user;
	string _password;
	int _codigo;
public:
	CUsuario()
	{
		
	}
	CUsuario(int codigo, string user, string password)
	{
		this->_user = user;
		this->_password = password;
		this->_codigo = codigo;;
	}
	//set
	void setUser(string user)
	{
		_user = user;
	}
	void setPassword(string password)
	{
		_password=password;
	}
	void setCodigo(int codigo)
	{
		_codigo = codigo;
	}
	//get
	string getUser()
	{
		return _user;
	}
	string getPassword()
	{
		return _password;
	}
	int getCodigo()
	{
		return _codigo;
	}
};
