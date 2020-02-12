#include "miniwin.h"
#include <cstdlib>
#include <string>


using namespace miniwin;
using namespace std;

struct ManejadorEntrada
{
	float posx_intruccion, posy_instruccion;
	float posx_entrada, posy_entrada;
	int color_instruccion;
	int color_entrada;
	
	string obtenerEntrada(const string& intstruccion, bool numero = false) const;
	
	private:
		int filtrar_simbolo_miniwin(int simbolo)const;
		enum
		{
			PUNTO = 46,
			COMA = 44
		};
};

int main(){
	
//	Menu();
//	
//	vredimensiona(600,400);
//	
//	color(VERDE);
//	texto(20, 150,"Menu");
//	espera(20000);
//	refresca();
	
	ManejadorEntrada m_entrada;
	
	m_entrada.color_instruccion = CYAN;
	m_entrada.color_entrada = AMARILLO;
	m_entrada.posx_intruccion = 20;
	m_entrada.posy_instruccion = 220;
	m_entrada.posx_entrada = 20;
	m_entrada.posy_entrada = 250;
	
	vredimensiona(600 , 400);
	
	color(ROJO);
	rectangulo(10,10,590,390);
	texto(20,30,"Universidad de San Carlos de Guatemala");
	texto(20,45,"Facultad de Ingeniería");
	texto(20,60,"Estructuras de Datos");
	texto(20,75,"Practica #1");
	refresca();
	string x = "Menu";
	color(VERDE);
	texto(20, 150,x);
	texto(20, 165,"1. Crear archivo");
	texto(20, 180,"2. Abrir Archivo");
	texto(20, 195,"3. Salir");
	
	
	
	string entrada = m_entrada.obtenerEntrada("Escribe una cadena : ", false);
	color(BLANCO);
	texto(20,280,"escribiste esto: "+ entrada);
	refresca();

	return 0;

}

string ManejadorEntrada::obtenerEntrada(const string& intruccion, bool numero) const
{
	color(color_instruccion);
	texto(posx_intruccion,posy_instruccion,intruccion);
	color(color_entrada);
	string entrada;
	for(int simbolo = tecla(); simbolo!= RETURN; simbolo = tecla())
	{
		simbolo = filtrar_simbolo_miniwin(simbolo);
		if((simbolo== ESCAPE || simbolo == 8) && !entrada.empty())
		{
			borra();
			//BORRA EL ULTIMOCARRACTER DE STRING
			size_t tam= entrada.length();
			entrada.erase(tam-1);
			//BORRA ULTIMO CARACTER A LA LISTA
			color(color_instruccion);
			texto(posx_intruccion,posy_instruccion,intruccion);
		}
		else if(numero && (isdigit(simbolo )|| simbolo == PUNTO))
		{
			//INGRESA CARACTER A LA CADENA
			entrada += simbolo;
			//INGRESA CARACTER A LA LISTA
		}
		else if(simbolo == CONTROL)
		{
			//INGRESA CARACTER de CONTROL 
			entrada += "@";
			
		}
		else if (!numero && (isalnum(simbolo)||simbolo == ESPACIO || simbolo == PUNTO))
		{
			//INGRESA CARACTER A LA CADENA
			entrada += simbolo;
			///INGRESA CARACTER A LA LISTA
		}
		if(simbolo != NINGUNA)
		{
			//texto(100, 100,to_string(simbolo));
			color(color_entrada);
			texto(posx_entrada,posy_entrada,entrada);
		}
		
	color(ROJO);
	rectangulo(10,10,590,390);
	texto(20,30,"Universidad de San Carlos de Guatemala");
	texto(20,45,"Facultad de Ingeniería");
	texto(20,60,"Estructuras de Datos");
	texto(20,75,"Practica #1");
	refresca();
	string x = "Menu";
	color(VERDE);
	texto(20, 150,x);
	texto(20, 165,"1. Crear archivo");
	texto(20, 180,"2. Abrir Archivo");
	texto(20, 195,"3. Salir");
	
		
		
		refresca();
		espera(20);
	}
	return entrada;
}

int ManejadorEntrada::filtrar_simbolo_miniwin(int simbolo)const
{
	if(simbolo == 190 || simbolo == 110 )
		return PUNTO;
	if (simbolo == 188 )
		return COMA;
	if (simbolo >= 96 && simbolo <= 105)
		return simbolo - 48;
	return simbolo;
}

void Menu(){
	
}


