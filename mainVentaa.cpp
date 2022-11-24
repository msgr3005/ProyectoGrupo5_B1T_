#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctime>
#include "../controller/PersonalController.h"
#include "../controller/categoriaController.h"
#include "../controller/productoController.h"
#include "../controller/ClienteController.h"
#include "../controller/CControladora.h"
#include "../controller/DVentaController.h"
#include "../controller/ventaController.h"

using namespace std;

/*****************************************************************************/
/*Variables globales*/
CategoriaController* catController=new CategoriaController();
ProductoController* proController=new ProductoController();
ClienteController* cliController=new ClienteController();
CControladora* CUserCController = new CControladora();
DetVentaController* DetVController = new DetVentaController();
VentaController* ventaController = new VentaController();
//DetVentaVector vectorDVenta;
PersonalController* vendController = new PersonalController(); /*Instancia de la clase vendedor*/

void fecha();
void tituloPrincipal();
void menuPrincipal();
void menuDeOpciones();
void modificar();

void menuClientes();
	void addClientes();
	void listarClientes();
	void modificarCliente();
	void buscarClientes();
	void eliminarClientes();
	
void registroDeProductos();
	void adicionarProducto();
	void addCategory();
	void listCategories();
	void listarProductos();
	void eliminarProducto();
	void eliminarCategoria();
	void modificarProducto();
	void buscarProducto();
	
void menuPersonal();
	void adicionarVendedor();
	void listarVendedors();
	void modificarVendedor();
	void buscarVendedor();
	void addUsuarios();
	void LogIn();
	void listOfUsuarios();
	void eliminarVendedor();
	
	
void registroVentas();
	void registroUsuarios();
	
int main()
{
	LogIn();
	menuDeOpciones();
}

void LogIn()
{
	string loginUser;
	string loginPassword;
	bool ingresar = false;
	int contador = 0;
	do
	{
		system("cls");
		tituloPrincipal();
		cout << "\n\n\t\t======================== LOGIN DE USUARIO ========================" << endl;
		cout << "\n\t\t\tUsuario: ";
		cin>>loginUser;
		cout << "\n\t\t\tContraseña: ";
		//getline(cin,loginPassword);
		char c;
		c = getch();
		loginPassword = "";
		while(c != 13)
		{
			if(c != 8)
			{
				loginPassword.push_back(c);
				cout<<"*";
			}
			else if(loginPassword.length()>0)
			{
				cout<<"\b \b";
				loginPassword = loginPassword.substr(0,loginPassword.length()-1);
			}
			c = getch();
			
		}
		for(int i=0;i<CUserCController->getSize();i++){
			if(loginUser==CUserCController->getPosition(i).getUser() && loginPassword==CUserCController->getPosition(i).getPassword())
			{
				cout<<"\n\n\t\t=========================== BIENVENIDO ===========================\n"<<endl;
				ingresar = true;
				break;
			}
		}
		if(ingresar == false)
		{
			cout<<"\n\n\t\t=========== El usuario y/o contraseña son incorrectos ===========\n\n";
			contador++;
			system("pause");
			
		}
		
	}while(ingresar == false && contador < 3);
	
	
	if(ingresar == false)
	{
		cout<<"\n\n\t\t===================== Se quedo sin intentos =====================\n\n";
		system("pause");
		exit(1);
	}
	system("pause");
	system("cls");
	
}

void menuDeOpciones()
{
	int opt;
	
	do
	{
		
		tituloPrincipal();
		
		cout<<"\n\n";
		cout<<"\t\t\t\t- REGISTRO DE CLIENTES .........[1]"<<endl;
		cout<<"\t\t\t\t- REGISTRO DE PRODUCTOS ........[2]"<<endl;
		cout<<"\t\t\t\t- REGISTRO DE PERSONAL .........[3]"<<endl; //it now work btw :)
		cout<<"\t\t\t\t- REGISTRO DE Ventas .........[4]"<<endl;
		cout<<"\t\t\t\t- SALIR ........................[5]"<<endl;
		cout<<"\t\t\t***************************************************\n";
		cout<<"\t\t\t\t- Ingrese una opcion...........[1-5]"<<endl;
		cout<<"\t\t\t***************************************************\n";
		cout <<"\t\t\t\t--> ";
		cin >> opt;
		
		switch(opt)
		{
		case 1 : 	system("cls");	
		menuClientes();
		break;
		
		case 2 : 	system("cls");	
		registroDeProductos();
		break;
		
		case 3 : 	system("cls");	
		//registrarVendedores();
		menuPersonal();
		break;
		
		case 4 : 	system("cls");	
		registroVentas();
		break;
		
		case 5 :
			cout<<"\n\n\t\t\t*****Gracias por usar nuestro programa*****\n\n";exit(1);
			
			break; 
			default : cout<<"\t\t\t\t\t	* INGRESE UN OPCION CORRECTA [1-5] *"<<endl;
		}
		
	}
	while(opt != 5);
	
}

void registroUsuarios(){
	int opcion;
	do 
	{
		system("cls");
		cout << "\t\t\t\t============== VentaMas ==============" << endl;
		cout << "\t\t\t\t======================================" << endl;
		cout << "Ingrese la opcion a escoger: " << endl;
		cout << "1) Crear Usuario (Ingrese -> 1): " << endl;
		cout << "2) Ingresar Usuario (Ingrese -> 2): " << endl;
		cout << "3) Listar usuarios(Ingrese -> 3): "<<endl;
		cout << "4) Salir (Ingrese -> 4): " << endl;
		cout<<"Opcion: ";
		cin >> opcion;
		switch(opcion)
		{
		case 1: system("cls");addUsuarios();break;
		case 2: system("cls");LogIn();break;
		case 3: system("cls");listOfUsuarios();break;
		case 4: system("cls"); menuDeOpciones();break;
		default:cout<<"\nIngrese una opcion correcta[1-4]\n\n";system("pause");system("cls");break;
		}
	} 
	while(opcion != 4);
}
	
void addUsuarios()
{
	string flag;
	int codigo;
	string user;
	string password;
	do
	{
		codigo = CUserCController->getCorrelativo();
		cout << "============== VentaMas ==============" << endl;
		cout << "******(" << codigo << ")*******\n";
		cin.ignore();
		cout << "Cree su usuario:";
		getline(cin,user);
		cout << "Cree su Contrasenia:";
		//getline(cin,password);
		password = "";
		char caract;
		caract = getch();
		while(caract != 13)
		{
			if(caract != 8)
			{
				password.push_back(caract);
				cout<<"*";
			}
			else if(password.length()>0)
			{
				cout<<"\b \b";
				password = password.substr(0,password.length()-1);
			}
			caract = getch();
			
		}
		cout<<"\nDesea continuar(S/N)"<<endl;
		cin>>flag;
		/*Crear el objeto de tipo CUsuario*/
		CUsuario objUser(codigo,user,password);
		/*Agregar el objeto al arreglo*/
		CUserCController->addUsers(objUser);
		/*Grabando el archivo*/
		CUserCController->saveArchive(objUser);
		CUserCController->saveArchiveBinary(objUser);
		system("pause");
		system("cls");
	} 
	while(flag == "S" || flag == "s");
}
		
		
		
		
void listOfUsuarios()
{
	cout<<"Listando usuarios"<<endl;
	for(int i=0;i<CUserCController->getSize();i++)
	{
		cout<<CUserCController->getPosition(i).getUser()<<endl;
		system("pause");
	}
}

void menuPersonal()
{
	//Declarar Variables
	int opt;
	do
	{
		tituloPrincipal();
		cout<<"\n"<<endl;
 		cout<<"\t\t\t\t\tREGISTRO DE PERSONAL\n";
 		cout<<"\t\t\t***************************************************\n"<<endl;
		cout<<"\t\t\t- Ingresar Personal        [1]\n";
		cout<<"\t\t\t- Modificar Personal       [2]\n"; 
		cout<<"\t\t\t- Buscar Personal          [3]\n";
		cout<<"\t\t\t- Listar Personal          [4]\n";
		cout<<"\t\t\t- Eliminar Personal        [5]\n";
		cout<<"\t\t\t- Salir                    [6]\n";
		cout<<"\t\t\t***************************************************\n";
		cout<<"\t\t\t- Ingrese solo una opción : 		[1 - 6]"<<endl;
		cout<<"\t\t\t***************************************************\n";
		cout<<"\t\t\t--> ";
		cin>>opt;
	switch(opt)
		{
			case 1: system("cls");
					adicionarVendedor();
					break;
					
			case 2:system("cls");
					modificarVendedor();
					break;
					
			case 3:system("cls");
					buscarVendedor();
					break;
					
			case 4: system ("cls");
					listarVendedors();
					break;
					
					cout<<endl;
					
			case 5: system ("cls");
			eliminarVendedor();
			break;
			
			cout<<endl;
			case 6: 
					
					system("cls");

					menuDeOpciones();

					exit(0);
					break;
			default:cout<<"\t\t\t---------Ingresar una opción correcta [1-6]---------\n"<<endl;		
		}
	}
	while(opt!=6);
}
	
void adicionarVendedor()
{
	int cod; 
	string nom;
	string usu;
	string contra; 
	string dni;
	float sueldo;
	string rpta;
	
	do
	{
		//Entrada de Datos
		cod = vendController->getCorrelativo();
		tituloPrincipal();
		cout<<"\n"<<endl;
		cout<<"\t\t\t\t*****************************************\n";		
		cout<<"\t\t\t\t\t==> INGRESAR VENDEDOR(A) <==\n";
		cout<<"\t\t\t\t*****************************************\n";
		cout<<endl;
		cout<<"\t\t\t\tCódigo ("<<cod<<")"<<endl;
		cin.ignore();
		
		cout<<"\t\t\t\t- Ingresar Nombre de Vendedor(a) : ";
		getline(cin,nom);
		
		cout<<"\t\t\t\t- Ingresar Usuario de Vendedor(a) : ";
		getline(cin,usu);
		
		cout<<"\t\t\t\t- Ingresar Contrasena de Vendedor(a) : ";
		getline(cin,contra);
		
		cout<<"\t\t\t\t- Ingresar DNI de Vendedor(a) : ";
		cin>>dni;
		
		cout<<"\t\t\t\t- Ingresar sueldo de Vendedor(a) : ";
		cin>>sueldo;
		cout<<endl;
		
		Personal vendedor; /*Crear el Objeto*/
		
		vendedor.setCodPersonal(cod);
		vendedor.setNomApePersonal(nom);
		vendedor.setUsuario(usu);
		vendedor.setContrasena(contra);
		vendedor.setDniPersonal(dni);
		vendedor.setSueldoPersonal(sueldo);
		
		vendController->add(vendedor); //Agregar el Objeto al Vector dinamico	
		vendController->grabarEnArchivo(vendedor);
		/*Crear el objeto de tipo CUsuario*/
		CUsuario objUser(cod,usu,contra);
		/*Agregar el objeto al arreglo*/
		CUserCController->addUsers(objUser);
		/*Grabando el archivo*/
		CUserCController->saveArchive(objUser);
		CUserCController->saveArchiveBinary(objUser);
		
		system("cls");
		cout<<"\t\t\t*********************************************************\n";
		cout<<"\t\t\t- Continuar? (S/s) : ";
		cin>>rpta;
		cout<<"\t\t\t*********************************************************\n";
		system("cls"); 
	}
	while(rpta =="s" || rpta =="S");
}
void eliminarVendedor()
{
	int cod;
	//tituloPrincipal();
	cout<<"\n"<<endl;
	cout<<"\t\t\t***************************************************\n";
	cout<<"\t\t\t\t- Ingresar el código a eliminar : ";
	cin>>cod;
	cout<<"\t\t\t***************************************************\n";
	cout<<endl;
	Personal objAEliminar = vendController->buscarPorCodigo1(cod);
	if(objAEliminar.getNomApePersonal() != "Error")
	{
		vendController->remove(objAEliminar);
		cout<<"\t\t\t------>Registro Eliminado Satisfactoriamente<------\n";
		vendController->grabarModificarArchivo();
	}
	else
	{
		cout<<endl;
		cout<<"\t\t\t---------------------------------------------------\n";		
		cout<<"\t\t\t\t--> No se encontró el registro !!!! \n";
		cout<<"\t\t\t---------------------------------------------------\n";
		cout<<endl;
	}
	system ("pause");
	system("cls");	
	menuPersonal();
}
void listarVendedors()//Listado
	{
		for(int i=0;i<vendController->sizePer();i++)
		{
			cout<<"\n"<<endl;
			cout<<"\t\t\t- El Código : "<<vendController->get(i).getCodPersonal()<<"\n";
			cout<<"\t\t\t- El Nombre : "<<vendController->get(i).getNomApePersonal()<<"\n";
			cout<<"\t\t\t- El Usuario : "<<vendController->get(i).getUsuario()<<"\n";
			cout<<"\t\t\t- La Contrasena : "<<vendController->get(i).getContrasena()<<"\n";
			cout<<"\t\t\t- El DNI : "<<vendController->get(i).getDniPersonal()<<"\n";	
			cout<<"\t\t\t- El sueldo : "<<vendController->get(i).getSueldoPersonal()<<"\n";	
			cout<<endl;
		}
		system("pause");
		system("cls");
}

void modificarVendedor()
{
	int cod;
		tituloPrincipal();
		cout<<"\n"<<endl;
		cout<<"\t\t\t***********************************************************\n";
		cout<<"\t\t\t- Ingrese el código del vendedor(a) que usted desea modificar : ";
		cin>>cod;
		cout<<"\t\t\t***********************************************************\n";
		cout<<endl;
	Personal objAModificar = vendController->buscarPorCodigo1(cod);
		cout<<"\t\t\t**************************************************\n";
		cout<<"\t\t\t\t\tRegistro Encontrado\n";
		cout<<"\t\t\t**************************************************\n";
		cout<<"\t\t\t- El Código : "<<objAModificar.getCodPersonal()<<"\n";
		cout<<"\t\t\t- El Nombre : "<<objAModificar.getNomApePersonal()<<"\n";
		cout<<"\t\t\t- El Usuario : "<<objAModificar.getUsuario()<<"\n";
		cout<<"\t\t\t- La Contrasena : "<<objAModificar.getContrasena()<<"\n";
		cout<<"\t\t\t- El DNI : "<<objAModificar.getDniPersonal()<<"\n";
		cout<<"\t\t\t- El Sueldo : "<<objAModificar.getSueldoPersonal()<<"\n";
		cin.ignore();
		cout<<endl;
		cout<<"\t\t\t**************************************************\n";
		cout<<"\t\t\t\t\tModificar campos\n";
		cout<<"\t\t\t**************************************************\n";
		string nomModificado;
		cout<<"\t\t\t- El Nuevo Nombre es :\n "; 
		cout<<"\t\t\t"; getline(cin,nomModificado);
		
		string usuModificado;
		cout<<"\t\t\t- El Nuevo Usuario es :\n "; 
		cout<<"\t\t\t"; getline(cin,usuModificado);
		
		string contraModificado;
		cout<<"\t\t\t- La Nueva Contraseña es :\n "; 
		cout<<"\t\t\t"; getline(cin,contraModificado);
		
		string dniModificado;
		cout<<"\t\t\t- El Nuevo DNI es :\n "; 
		cout<<"\t\t\t"; getline(cin,dniModificado);
		
		float sueldoModificado;
		cout<<"\t\t\t- El nuevo sueldo es:\n ";
		cout<<"\t\t\t";cin>>sueldoModificado;
	
	bool estado = vendController->modificar(objAModificar,nomModificado,usuModificado,contraModificado,dniModificado,sueldoModificado);
		if(estado == true)
			{
				cout<<endl;
				cout<<"\t\t\t------------------------------------------------\n";
				cout<<"\t\t\t\tRegistro Modificado Exitosamente\n";
				cout<<"\t\t\t------------------------------------------------\n";
				cout<<endl;
				/*Grabar en archivo*/
				vendController->grabarModificarArchivo();
			}
		else
			{
				cout<<endl;
				cout<<"\t\t\t------------------------------------------------\n";
				cout<<"\t\t\t\tNo se Logró Editar el Registro!!\n";
				cout<<"\t\t\t------------------------------------------------\n";
				cout<<endl;
				system("pause");
				menuPersonal();
			}
		system("pause");
		system("cls");	
}

void buscarVendedor()
{
	int cod;
		tituloPrincipal();
		cout<<"\n"<<endl;
		cout<<"\t\t\t***************************************************\n";
		cout<<"\t\t\t- Ingrese el código que usted desea buscar : ";
		cin>>cod;
		cout<<"\t\t\t***************************************************\n";
		cout<<endl;

	Personal per = vendController->buscarPorCodigo1(cod);
	if(per.getNomApePersonal() != "Error")
		{
			cout<<"\t\t\t**************************************************\n";
			cout<<"\t\t\t\t\tRegistro Encontrado\n";
			cout<<"\t\t\t**************************************************\n";
			cout<<"\t\t\t- Código : "<<per.getCodPersonal()<<"\n";
			cout<<"\t\t\t- Nombre : "<<per.getNomApePersonal()<<"\n";
			cout<<"\t\t\t- Usuario : "<<per.getUsuario()<<"\n";
			cout<<"\t\t\t- Contrasena : "<<per.getContrasena()<<"\n";
			cout<<endl;
		}
	else
		{
			cout<<endl;
			cout<<"\t\t\t------------------------------------------------\n";
			cout <<"\t\t\t\tNo se encontró el registro!"<<endl;
			cout<<"\t\t\t------------------------------------------------\n";
			cout<<endl;
		}
		system("pause");
		system("cls");
		menuPersonal();
}

void tituloPrincipal()
{
	cout<<"\n\t\t===================================================================\n";
	cout<<"\t\t\t\t\tEMPRESA ventaMas\n";
	cout<<"\t\t  Creación, eliminación, actualización, búsqueda, lista y reportes\n";
	cout<<"\t\t\t\t\t Copyright 2022\n";
	cout<<"\t\t===================================================================\n";
 
	cout<<"\n";
	for (int i = 0; i < 120; i++) {
		cout<<"_";
	}
}

//Productos
void registroDeProductos()
{
	int opt;
	do
	{
		//tituloPrincipal();
		cout<<"\n"<<endl;
 		cout<<"\t\t\t\t\tREGISTRO DE PRODUCTOS\n";
 		cout<<"\t\t\t***************************************************\n";
 		cout<<endl;
		cout<<"\t\t\t- INGRESAR PRODUCTO .............[1]\n ";
		cout<<"\t\t\t- INGRESAR CATEGORIA.............[2]\n ";
		cout<<"\t\t\t- ELIMINAR CATEGORIA.............[3]\n ";
		cout<<"\t\t\t- ELIMINAR PRODUCTO .............[4]\n ";
		cout<<"\t\t\t- MODIFICAR PRODUCTO ............[5]\n ";
		cout<<"\t\t\t- BUSCAR PRODUCTO ...............[6]\n ";
		cout<<"\t\t\t- LISTAR PRODUCTOS ..............[7]\n ";
		cout<<"\t\t\t- ATRAS .........................[8]\n "<<endl;
		cout<<"\t\t\t***************************************************\n";
		cout<<"\t\t\t- Ingrese solo una opción : 		[1 - 8]"<<endl;
		cout<<"\t\t\t***************************************************\n";
		cout<<"\t\t\t--> ";
		cin>>opt;
		cout<<endl;	
	switch(opt)
		{
			case 1: system("cls");
					adicionarProducto();
					break;
			case 2:system("cls");
			addCategory();
			break;
			case 3:system("cls");
					eliminarCategoria();
					break;
			case 4:system("cls");
					eliminarProducto();
					break;
					
			case 5:system("cls");
					modificarProducto();
					break;
					
			case 6:system("cls");
					buscarProducto();
					break;
					
			case 7: system ("cls");
					listarProductos();
					break;
					
					
			case 8: system ("cls");
					menuDeOpciones();
					break;;
			default:cout<<"\t\t\t---------Ingresar una opción correcta [1-8]---------\n"<<endl;		
		}
	}
	while(opt!=8);
}
void addCategory()
{
	string flag;
	int codCat;
	string nomCat;
	do
	{
		codCat = catController->getCorrelativoCat();
		cout<<"******("<<codCat<<")*******\n";
		cin.ignore();
		cout<<"Nombre de la categoria: ";
		getline(cin,nomCat);
		cout<<"Continuar(S/s): ";
		cin>>flag;
		/*Crear el objeto de tipo categoria*/
		Categoria objCat(codCat,nomCat);
		/*Agregar el objeto al arreglo*/
		catController->addCat(objCat);
		/*Grabando en archivo*/
		catController->grabarEnArchivo(objCat);
		system("cls");
	} 
	while(flag == "S" || flag == "s");
}
void listCategories()
{
	for(int i = 0;i<catController->sizeCat();i++)
	{
		cout<<"["<<catController->posCat(i).getCodCat()<<"]\t"
			<<catController->posCat(i).getNomCat()<<endl;
	}
	
}	
void eliminarCategoria()
{
	int cod;
	//tituloPrincipal();
	cout<<"\n"<<endl;
	cout<<"\t\t\t***************************************************\n";
	cout<<"\t\t\t\t- Ingresar el código a eliminar : ";
	cin>>cod;
	cout<<"\t\t\t***************************************************\n";
	cout<<endl;
	Categoria objAEliminar = catController->buscar(cod);
	if(objAEliminar.getNomCat() != "Error")
	{
		catController->eliminarCategoria(objAEliminar);
		cout<<"\t\t\t------>Registro Eliminado Satisfactoriamente<------\n";
		catController->grabarModificarEliminar();
	}
	else
	{
		cout<<endl;
		cout<<"\t\t\t---------------------------------------------------\n";		
		cout<<"\t\t\t\t--> No se encontró el registro !!!! \n";
		cout<<"\t\t\t---------------------------------------------------\n";
		cout<<endl;
	}
	system ("pause");
	system("cls");	
	registroDeProductos();
}
void listarProductos()
{
	for(int i = 0;i<proController->sizePro();i++)
	{
		cout<<proController->get(i).getCodigoProducto()<<"\t"
			<<proController->get(i).getNombre()<<"\t"
			<<proController->get(i).getPrecio()<<"\t"
			<<proController->get(i).getStock()<<"\t"
			<<proController->get(i).getCodCat()<<"\t"
			<<proController->get(i).getNomCat()<<endl;
	}
	
	system("pause");
	system("cls");
	registroDeProductos();
}
void adicionarProducto()
{
	string flag;
	int 	codPro;
	string 	nomPro;
	float   prePro;
	int 	stkPro;
	int codCategoria;
	string nomCategoria;
	do
	{
		codPro = proController->getCorrelativo();
		cout<<"**("<<codPro<<")***\n";
		cin.ignore();
		cout<<"Nombre del Producto: ";
		getline(cin,nomPro);
		cout<<"Precio: ";
		cin>>prePro;
		cout<<"Stock Producto: ";
		cin>>stkPro;
		cout<<"Seleccione la categoria: \n";
		listCategories();
		cout<<"Codigo: ";
		cin>>codCategoria;
		for(int i=0;i<catController->sizeCat();i++)
		{
			
			if(codCategoria == catController->posCat(i).getCodCat())
			{
				nomCategoria = catController->posCat(i).getNomCat();
			}
		}
		cout<<"Continuar(S/s): ";
		cin>>flag;
		//Crear el objeto de tipo Producto/
			Producto objPro(codCategoria,nomCategoria,codPro,nomPro,prePro,stkPro);
		//Agregar el objeto alarreglo/
			proController->add(objPro);
		//grabar en archivo
		proController->grabarEnArchivo(objPro);
		system("cls");
	} 
	while(flag == "S" || flag == "s");
}	

void eliminarProducto()
{
	int cod;
		//tituloPrincipal();
		cout<<"\n"<<endl;
		cout<<"\t\t\t***************************************************\n";
		cout<<"\t\t\t\t- Ingresar el código a eliminar : ";
		cin>>cod;
		cout<<"\t\t\t***************************************************\n";
		cout<<endl;
	Producto objAEliminar = proController->buscarPorCodigo1(cod);
		if(objAEliminar.getNombre() != "Error")
			{
			proController->eliminarProducto(objAEliminar);
				cout<<"\t\t\t------>Registro Eliminado Satisfactoriamente<------\n";
				proController->grabarModificarEliminarArchivo();
			}
		else
			{
		cout<<endl;
		cout<<"\t\t\t---------------------------------------------------\n";		
		cout<<"\t\t\t\t--> No se encontró el registro !!!! \n";
		cout<<"\t\t\t---------------------------------------------------\n";
		cout<<endl;
			}
		system ("pause");
		system("cls");	
		registroDeProductos();
}

void modificarProducto()
{
	int cod;
		//tituloPrincipal();
		cout<<"\n"<<endl;
		cout<<"\t\t\t***************************************************\n";
		cout<<"\t\t\t- Ingrese el código que usted desea modificar : ";
		cin>>cod;
		cout<<"\t\t\t***************************************************\n";
		cout<<endl;
	Producto objAModificar = proController->buscarPorCodigo1(cod);
		cout<<"\t\t\t**************************************************\n";
		cout<<"\t\t\t\t\tRegistro Encontrado\n";
		cout<<"\t\t\t**************************************************\n";
		cout<<"\t\t\t- El Código : "<<objAModificar.getCodCat()<<"\n";
		cout<<"\t\t\t- El Nombre : "<<objAModificar.getNombre()<<"\n";
		cout<<"\t\t\t- El Precio : "<<objAModificar.getPrecio()<<"\n";
		cout<<"\t\t\t- El Stock : "<<objAModificar.getStock()<<"\n";
		cin.ignore();
		cout<<endl;
		cout<<"\t\t\t**************************************************\n";
		cout<<"\t\t\t\t\tModificar campos\n";
		cout<<"\t\t\t**************************************************\n";
		string nomModificado;
		cout<<"\t\t\t- El Nuevo Nombre es :\n "; 
		cout<<"\t\t\t"; getline(cin,nomModificado);
		
		string marModificado;
		cout<<"\t\t\t- La Nueva Marca es :\n "; 
		cout<<"\t\t\t"; getline(cin,marModificado);
		
		string descriModificado;
		cout<<"\t\t\t- La Nueva Descripción es :\n "; 
		cout<<"\t\t\t"; getline(cin,descriModificado);
		
		float preModificado;
		cout<<"\t\t\t- El Nuevo Precio es :\n "; 
		cout<<"\t\t\t"; cin>>preModificado;
		
		int stoModificado;
		cout<<"\t\t\t- El Nuevo Stock (cantidad) es :\n"; 
		cout<<"\t\t\t"; cin>>stoModificado;
	
	bool estado = proController->modificar(objAModificar,nomModificado,preModificado,stoModificado);
		if(estado == true)
			{
				cout<<endl;
				cout<<"\t\t\t------------------------------------------------\n";
				cout<<"\t\t\t\tRegistro Modificado Exitosamente\n";
				cout<<"\t\t\t------------------------------------------------\n";
				cout<<endl;
				/*Grabar en archivo*/
				proController->grabarModificarEliminarArchivo();
			}
		else
			{
				cout<<endl;
				cout<<"\t\t\t------------------------------------------------\n";
				cout<<"\t\t\t\tNo se Logró Editar el Registro!!\n";
				cout<<"\t\t\t------------------------------------------------\n";
				cout<<endl;
				system("pause");
				registroDeProductos();
			}
		system("pause");
		system("cls");	
}

void buscarProducto()
{
	string str;
		//tituloPrincipal();
		cout<<"\n"<<endl;
		cout<<"\t\t\t***************************************************\n";
		cout<<"\t\t\t- Ingrese el string que usted desea buscar : ";
		cin>>str;
		cout<<"\t\t\t***************************************************\n";
		cout<<endl;

	proController->buscarPorString2(str);
	system("pause");
	system("cls");
	/*if(pro.getNombre() != "Error")
		{
			cout<<"\t\t\t**************************************************\n";
			cout<<"\t\t\t\t\tRegistro Encontrado\n";
			cout<<"\t\t\t**************************************************\n";
			cout<<"\t\t\t- Código : "<<pro.getCodigoProducto()<<"\n";
			cout<<"\t\t\t- Nombre : "<<pro.getNombre()<<"\n";
			cout<<"\t\t\t- Precio : "<<pro.getPrecio()<<"\n";
			cout<<"\t\t\t- Stock : "<<pro.getStock()<<"\n";
		}
	else
		{
			cout<<endl;
			cout<<"\t\t\t------------------------------------------------\n";
			cout <<"\t\t\t\tNo se encontró el registro!!!!!"<<endl;
			cout<<"\t\t\t------------------------------------------------\n";
			cout<<endl;
		}
		system("pause");
		system("cls");
		registroDeProductos();*/
	
}

void menuClientes()
{
	//Declarar Variables
	int opt;
	do
	{
		tituloPrincipal();
		cout<<"\n"<<endl;
		cout<<"\t\t\t\t\tREGISTRO DE CLIENTES\n";
		cout<<"\t\t\t***************************************************\n"<<endl;
		cout<<"\t\t\t- Anadir Clientes      [1]\n";
		cout<<"\t\t\t- Listar Clientes      [2]\n"; 
		cout<<"\t\t\t- Modidicar Clientes   [3]\n"; 
		cout<<"\t\t\t- Buscar Clientes      [4]\n"; 
		cout<<"\t\t\t- Eliminar Clientes      [5]\n"; 
		cout<<"\t\t\t- Regresar             [6]\n";
		cout<<"\t\t\t***************************************************\n";
		cout<<"\t\t\t- Ingrese solo una opción : 		[1 - 5]"<<endl;
		cout<<"\t\t\t***************************************************\n";
		cout<<"\t\t\t--> ";
		cin>>opt;
		switch(opt)
		{
		case 1: system("cls");
		addClientes();
		break;
		
		case 2:system("cls");
		listarClientes();
		break;
		
		case 3:system("cls");
		modificarCliente();
		break;
		
		case 4:system("cls");
		buscarClientes();
		break;
		
		case 5:system("cls");
		eliminarClientes();
		break;
		cout<<endl;
		case 6: 
			
			system("cls");
			
			menuDeOpciones();
			
			exit(1);
			break;
		default:cout<<"\t\t\t---------Ingresar una opción correcta [1-3]---------\n"<<endl;		
		}
	}
	while(opt!=6);
}



void addClientes()
{
	string flag;
	int codCli;
	string nomCli;
	string dirCli;
	int rucCli;
	do
	{
		codCli = cliController->getCorrelativoCli();
		cout<<"******("<<codCli<<")*******\n";
		cin.ignore();
		cout<<"Nombre del cliente: ";
		getline(cin,nomCli);
		cout<<"Direccion: ";
		getline(cin,dirCli);
		cout<<"Ruc: ";
		cin>>rucCli;
		cout<<"Continuar(S/s): ";
		cin>>flag;
		/*Crear el objeto de tipo categoria*/
		Cliente objCli(codCli,nomCli,dirCli,rucCli);
		/*Agregar el objeto al arreglo*/
		cliController->addCli(objCli);
		/*Grabando en archivo*/
		cliController->grabarEnArchivo(objCli);
		system("cls");
	} 
	while(flag == "S" || flag == "s");
}

void listarClientes()
{
	for(int i=0; i<cliController->sizeCli(); i++) 
	{
		cout << "Nombre: "<<cliController->getCli(i).getNomApeCliente()<< "\n";
		cout << "Dirección: "<<cliController->getCli(i).getDireccion()<< "\n";
		cout << "Ruc: "<<cliController->getCli(i).getRuc()<< "\n";
		cout << endl;
	}
	system("pause");
	system("cls");
}
void modificarCliente()
{
	string str;
	//tituloPrincipal();
	cout<<"\n"<<endl;
	cout<<"\t\t\t***************************************************\n";
	cout<<"\t\t\t- Ingrese el nombre del cliente que usted desea modificar : ";
	cin>>str;
	cout<<"\t\t\t***************************************************\n";
	cout<<endl;
	Cliente objAModificar = cliController->	buscarPorString(str);
	cout<<"\t\t\t**************************************************\n";
	cout<<"\t\t\t\t\tRegistro Encontrado\n";
	cout<<"\t\t\t**************************************************\n";
	cout<<"\t\t\t- El Código : "<<objAModificar.getCodCliente()<<"\n";
	cout<<"\t\t\t- El Nombre : "<<objAModificar.getNomApeCliente()<<"\n";
	cout<<"\t\t\t- La direccion: "<<objAModificar.getDireccion()<<"\n";
	cout<<"\t\t\t- El Ruc: "<<objAModificar.getRuc()<<"\n";
	cin.ignore();
	cout<<endl;
	cout<<"\t\t\t**************************************************\n";
	cout<<"\t\t\t\t\tModificar campos\n";
	cout<<"\t\t\t**************************************************\n";
	string nomModificado;
	cout<<"\t\t\t- El Nuevo Nombre es :\n "; 
	cout<<"\t\t\t"; getline(cin,nomModificado);
	
	string dirModificado;
	cout<<"\t\t\t- La Nueva Direccion es :\n "; 
	cout<<"\t\t\t"; getline(cin,dirModificado);
	
	int rucModificado;
	cout<<"\t\t\t- El nuevo ruc es :\n "; 
	cout<<"\t\t\t"; cin>>rucModificado;
	
	bool estado = cliController->modificar(objAModificar,nomModificado,dirModificado,rucModificado);
	if(estado == true)
	{
		cout<<endl;
		cout<<"\t\t\t------------------------------------------------\n";
		cout<<"\t\t\t\tRegistro Modificado Exitosamente\n";
		cout<<"\t\t\t------------------------------------------------\n";
		cout<<endl;
		/*Grabar en archivo*/
		cliController->grabarModificarEliminarArchivo();
	}
	else
	{
		cout<<endl;
		cout<<"\t\t\t------------------------------------------------\n";
		cout<<"\t\t\t\tNo se Logró Editar el Registro!!\n";
		cout<<"\t\t\t------------------------------------------------\n";
		cout<<endl;
		system("pause");
		menuClientes();
	}
	system("pause");
	system("cls");	
}

void buscarClientes()
{
	string str;
	
	cout << "\t\t\t\t\t INGRESAR NOMBRE CLIENTE: "; cin >> str;
	cliController->buscarPorString2(str);
	
	/*if(client.getNomApeCliente() != "Error")
	{
		cout << "\t\t\t\t\t   ¡¡¡Registro encontrado!!!" << endl;
		cout << endl;
		cout << "\t\t\t\t\t ***** BIENVENIDO/A " << client.getNomApeCliente() <<" *****";
		cout << endl;
		cout << endl;
		
	}
	else
	{
		cout << "\t\t\t\t\t ¡¡¡No se encontró el registro :( !!!" << endl;
		menuClientes();
	}
	*/
	system ("pause");
	system("cls");
	
}

void eliminarClientes()
{
	
	int cod;
	//tituloPrincipal();
	cout<<"\n"<<endl;
	cout<<"\t\t\t***************************************************\n";
	cout<<"\t\t\t\t- Ingresar el código a eliminar : ";
	cin>>cod;
	cout<<"\t\t\t***************************************************\n";
	cout<<endl;
	Cliente objAEliminar = cliController->buscarPorCod(cod);
	if(objAEliminar.getNomApeCliente() != "Error")
	{
		cliController->eliminarCliente(objAEliminar);
		cout<<"\t\t\t------>Registro Eliminado Satisfactoriamente<------\n";
		cliController->grabarModificarEliminarArchivo();
	}
	else
	{
		cout<<endl;
		cout<<"\t\t\t---------------------------------------------------\n";		
		cout<<"\t\t\t\t--> No se encontró el registro !!!! \n";
		cout<<"\t\t\t---------------------------------------------------\n";
		cout<<endl;
	}
	system ("pause");
	system("cls");	
	menuClientes();
}

void registroVentas()
{
	string rpta;
	int codVen;
	int cant;
	float subTotal;
	float Total = 0;
	Producto prod;
	DetalleVenta dVenta;
	Cliente clie;
	string strPro;
	string strCli;
	int numVenta = ventaController->getCorrNumVenta();
	
	time_t   t,i;
	char *p;
	i = time (&t);
	p = ctime (&i); 
	
	codVen = ventaController->getCorrelativo();
	cout<<"Buscar cliente: "; cin>>strCli;
	clie = cliController->buscarPorString(strCli);
	if(clie.getNomApeCliente() != "Error")
	{
		cout << "\t\t\t\t\t -------------------------" << "\n";
		cout << "\t\t\t\t\t Codigo del cliente: " <<	clie.getCodCliente() << "\n"; 
		cout << "\t\t\t\t\t Nombre del cliente: " <<	clie.getNomApeCliente() << "\n";
		cout << "\t\t\t\t\t Direccion del cliente: " <<	clie.getDireccion() <<"\n";
		cout << "\t\t\t\t\t Ruc del cliente: " <<	clie.getRuc() <<"\n";
		cout << "\t\t\t\t\t -------------------------" << "\n";
		do{
			
			cout<<codVen<<endl;
			cout << "\t\t\t\t\t >>>>>>>>>>>>>>>>>>>>>>>>>" << "\n";
			cout << "\t\t\t\t\t Buscar un producto: "; cin >> strPro;
			prod = proController->buscarPorString(strPro);
		
			if(prod.getNombre() !="Error")
			{
				cout << "\t\t\t\t\t -------------------------" << "\n";
				cout << "\t\t\t\t\t Nombre del producto: " <<	prod.getNombre() << "\n"; 
				cout << "\t\t\t\t\t Categoria del producto: " <<	prod.getNomCat() << "\n";
				cout << "\t\t\t\t\t Precio del producto: S/." <<	prod.getPrecio() <<".0" << "\n";
				cout << "\t\t\t\t\t -------------------------" << "\n";
				cout << "\t\t\t\t\t Cantidad: "; cin >> cant;
				subTotal = cant * prod.getPrecio();
				Total += subTotal;
				cout << "\t\t\t\t\t ---> SUBTOTAL: S/." << subTotal << endl;	
				
				
				/***********DETALLE VENTA*************/
				
				dVenta.setCodVen(codVen);
				dVenta.setCodigoProducto(prod.getCodigoProducto());
				dVenta.setPrecio(prod.getPrecio());
				dVenta.setCantidadDV(cant);
				dVenta.setPrecioDV(subTotal);
				/***********GRABANDO EL ARCHIVO DETALLE VENTA************/
				DetVController->add(dVenta);
				DetVController->grabarEnArchivoDV(dVenta);	
				
				
			}
			else
			{
				cout << "\t\t\t\t\t ¡¡¡No se encontró el registro :( !!!" << endl;
			}
			cout << "\t\t\t\t\t ¿Añadir más? (Y / N): "; cin >> rpta;
			cout << endl;
			system("cls");
		}
		while(rpta == "y" || rpta == "Y");
		/**************VENTA*************/
		
		Venta vent;
		vent.setCodVen(codVen);
		vent.setFecha(p);
		vent.setNumVenta(numVenta);
		vent.setTotal(Total);
		vent.setEstado("T");
		vent.setCodCliente(clie.getCodCliente());
		
		/**********GRABANDO EL ARCHIVO VENTA************/
		ventaController->add(vent);
		ventaController->grabarEnArchivo(vent);		
	}
	else if(clie.getNomApeCliente()== "Error")
	{
		cout<<"\t\t\t\t\t ¡¡¡No se encontro el cliente:( !!!"<<endl;
		cout<<"\t\t\t\t\t.....Regresando al menu de opciones....."<<endl;
		system("pause");
		system("cls");
		menuDeOpciones();
	}

	
	cout << "\t\t\t\t\t TOTAL: S/." << Total <<".0" << "\n";
	

	
	cout << "\t\t\t\t\t COMPRA FINALIZADA " << endl;
	system ("pause");
	system("cls");
	menuDeOpciones();
	cout<<"..."<<endl;
	system("pause");
	system("cls");
	
}

