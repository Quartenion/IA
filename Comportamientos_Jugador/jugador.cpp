#include "../Comportamientos_Jugador/jugador.hpp"
#include <iostream>
using namespace std;

Action ComportamientoJugador::think(Sensores sensores)
{

	Action accion = actIDLE;
	int a;

	//////////////////////////////////TUTORIAL\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
    \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//////////////////////////////////////
	switch(last_action){
		case actWALK: 
			switch(current_state.brujula){
				case norte: current_state.fil--; break;
				case noreste: current_state.fil--; current_state.col++; break;
				case este: current_state.col++; break;
				case sureste: current_state.fil++; current_state.col++; break;
				case sur: current_state.fil++; break;
				case suroeste: current_state.fil++; current_state.col--; break;
				case oeste: current_state.col--; break;
				case noroeste: current_state.fil--; current_state.col--; break;
			}
			break;

		case actRUN: 
			switch(current_state.brujula){
				case norte: current_state.fil-=2; break;
				case noreste: current_state.fil-=2; current_state.col+=2; break;
				case este: current_state.col+=2; break;
				case sureste: current_state.fil+=2; current_state.col+=2; break;
				case sur: current_state.fil+=2; break;
				case suroeste: current_state.fil+=2; current_state.col-=2; break;
				case oeste: current_state.col-=2; break;
				case noroeste: current_state.fil-=2; current_state.col-=2; break;
			}
			break;

		case actTURN_SR:
			a = current_state.brujula;
			a = (a+1)%8;
			current_state.brujula = static_cast<Orientacion>(a);
			break;

		case actTURN_L: 
			// Actualizacion en caso de girar 90 a la izquierda
			a = current_state.brujula;
			a = (a+6)%8;
			current_state.brujula = static_cast<Orientacion>(a);
			break;
	}

	if(sensores.posF!= -1 and !bien_situado){
		current_state.fil = sensores.posF;
		current_state.col = sensores.posC;
		current_state.brujula = sensores.sentido;
		bien_situado = true;
	}
	//VISIÓN DEL AGENTE
	if(bien_situado){
		switch(current_state.brujula){
			case norte: 
				mapaResultado[current_state.fil][current_state.col] = sensores.terreno[0];

				mapaResultado[current_state.fil-1][current_state.col-1] = sensores.terreno[1];
				mapaResultado[current_state.fil-1][current_state.col] = sensores.terreno[2];
				mapaResultado[current_state.fil-1][current_state.col+1] = sensores.terreno[3];

				mapaResultado[current_state.fil-2][current_state.col-2] = sensores.terreno[4];
				mapaResultado[current_state.fil-2][current_state.col-1] = sensores.terreno[5];
				mapaResultado[current_state.fil-2][current_state.col] = sensores.terreno[6];
				mapaResultado[current_state.fil-2][current_state.col+1] = sensores.terreno[7];
				mapaResultado[current_state.fil-2][current_state.col+2] = sensores.terreno[8];

				mapaResultado[current_state.fil-3][current_state.col-3] = sensores.terreno[9];
				mapaResultado[current_state.fil-3][current_state.col-2] = sensores.terreno[10];
				mapaResultado[current_state.fil-3][current_state.col-1] = sensores.terreno[11];
				mapaResultado[current_state.fil-3][current_state.col] = sensores.terreno[12];
				mapaResultado[current_state.fil-3][current_state.col+1] = sensores.terreno[13];
				mapaResultado[current_state.fil-3][current_state.col+2] = sensores.terreno[14];
				mapaResultado[current_state.fil-3][current_state.col+3] = sensores.terreno[15];
			break;

			case noreste: 
				mapaResultado[current_state.fil][current_state.col] = sensores.terreno[0];

				mapaResultado[current_state.fil-1][current_state.col] = sensores.terreno[1];
				mapaResultado[current_state.fil-1][current_state.col+1] = sensores.terreno[2];
				mapaResultado[current_state.fil][current_state.col+1] = sensores.terreno[3];

				mapaResultado[current_state.fil-2][current_state.col] = sensores.terreno[4];
				mapaResultado[current_state.fil-2][current_state.col+1] = sensores.terreno[5];
				mapaResultado[current_state.fil-2][current_state.col+2] = sensores.terreno[6];
				mapaResultado[current_state.fil-1][current_state.col+2] = sensores.terreno[7];
				mapaResultado[current_state.fil][current_state.col+2] = sensores.terreno[8];

				mapaResultado[current_state.fil-3][current_state.col] = sensores.terreno[9];
				mapaResultado[current_state.fil-3][current_state.col+1] = sensores.terreno[10];
				mapaResultado[current_state.fil-3][current_state.col+2] = sensores.terreno[11];
				mapaResultado[current_state.fil-3][current_state.col+3] = sensores.terreno[12];
				mapaResultado[current_state.fil-2][current_state.col+3] = sensores.terreno[13];
				mapaResultado[current_state.fil-1][current_state.col+3] = sensores.terreno[14];
				mapaResultado[current_state.fil][current_state.col+3] = sensores.terreno[15];
			break;

			case este: 
				mapaResultado[current_state.fil][current_state.col] = sensores.terreno[0];

				mapaResultado[current_state.fil-1][current_state.col+1] = sensores.terreno[1];
				mapaResultado[current_state.fil][current_state.col+1] = sensores.terreno[2];
				mapaResultado[current_state.fil+1][current_state.col+1] = sensores.terreno[3];

				mapaResultado[current_state.fil-2][current_state.col+2] = sensores.terreno[4];
				mapaResultado[current_state.fil-1][current_state.col+2] = sensores.terreno[5];
				mapaResultado[current_state.fil][current_state.col+2] = sensores.terreno[6];
				mapaResultado[current_state.fil+1][current_state.col+2] = sensores.terreno[7];
				mapaResultado[current_state.fil+2][current_state.col+2] = sensores.terreno[8];

				mapaResultado[current_state.fil-3][current_state.col+3] = sensores.terreno[9];
				mapaResultado[current_state.fil-2][current_state.col+3] = sensores.terreno[10];
				mapaResultado[current_state.fil-1][current_state.col+3] = sensores.terreno[11];
				mapaResultado[current_state.fil][current_state.col+3] = sensores.terreno[12];
				mapaResultado[current_state.fil+1][current_state.col+3] = sensores.terreno[13];
				mapaResultado[current_state.fil+2][current_state.col+3] = sensores.terreno[14];
				mapaResultado[current_state.fil+3][current_state.col+3] = sensores.terreno[15];
			break;

			case sureste: 
				mapaResultado[current_state.fil][current_state.col] = sensores.terreno[0];

				mapaResultado[current_state.fil+1][current_state.col] = sensores.terreno[3];
				mapaResultado[current_state.fil+1][current_state.col+1] = sensores.terreno[2];
				mapaResultado[current_state.fil][current_state.col+1] = sensores.terreno[1];

				mapaResultado[current_state.fil+2][current_state.col] = sensores.terreno[8];
				mapaResultado[current_state.fil+2][current_state.col+1] = sensores.terreno[7];
				mapaResultado[current_state.fil+2][current_state.col+2] = sensores.terreno[6];
				mapaResultado[current_state.fil+1][current_state.col+2] = sensores.terreno[5];
				mapaResultado[current_state.fil][current_state.col+2] = sensores.terreno[4];

				mapaResultado[current_state.fil+3][current_state.col] = sensores.terreno[15];
				mapaResultado[current_state.fil+3][current_state.col+1] = sensores.terreno[14];
				mapaResultado[current_state.fil+3][current_state.col+2] = sensores.terreno[13];
				mapaResultado[current_state.fil+3][current_state.col+3] = sensores.terreno[12];
				mapaResultado[current_state.fil+2][current_state.col+3] = sensores.terreno[11];
				mapaResultado[current_state.fil+1][current_state.col+3] = sensores.terreno[10];
				mapaResultado[current_state.fil][current_state.col+3] = sensores.terreno[9];
			break;

			case sur: 
				mapaResultado[current_state.fil][current_state.col] = sensores.terreno[0];

				mapaResultado[current_state.fil+1][current_state.col-1] = sensores.terreno[3];
				mapaResultado[current_state.fil+1][current_state.col] = sensores.terreno[2];
				mapaResultado[current_state.fil+1][current_state.col+1] = sensores.terreno[1];

				mapaResultado[current_state.fil+2][current_state.col-2] = sensores.terreno[8];
				mapaResultado[current_state.fil+2][current_state.col-1] = sensores.terreno[7];
				mapaResultado[current_state.fil+2][current_state.col] = sensores.terreno[6];
				mapaResultado[current_state.fil+2][current_state.col+1] = sensores.terreno[5];
				mapaResultado[current_state.fil+2][current_state.col+2] = sensores.terreno[4];

				mapaResultado[current_state.fil+3][current_state.col-3] = sensores.terreno[15];
				mapaResultado[current_state.fil+3][current_state.col-2] = sensores.terreno[14];
				mapaResultado[current_state.fil+3][current_state.col-1] = sensores.terreno[13];
				mapaResultado[current_state.fil+3][current_state.col] = sensores.terreno[12];
				mapaResultado[current_state.fil+3][current_state.col+1] = sensores.terreno[11];
				mapaResultado[current_state.fil+3][current_state.col+2] = sensores.terreno[10];
				mapaResultado[current_state.fil+3][current_state.col+3] = sensores.terreno[9];
			break;

			case suroeste: 
				mapaResultado[current_state.fil][current_state.col] = sensores.terreno[0];

				mapaResultado[current_state.fil+1][current_state.col] = sensores.terreno[1];
				mapaResultado[current_state.fil+1][current_state.col-1] = sensores.terreno[2];
				mapaResultado[current_state.fil][current_state.col-1] = sensores.terreno[3];

				mapaResultado[current_state.fil+2][current_state.col] = sensores.terreno[4];
				mapaResultado[current_state.fil+2][current_state.col-1] = sensores.terreno[5];
				mapaResultado[current_state.fil+2][current_state.col-2] = sensores.terreno[6];
				mapaResultado[current_state.fil+1][current_state.col-2] = sensores.terreno[7];
				mapaResultado[current_state.fil][current_state.col-2] = sensores.terreno[8];

				mapaResultado[current_state.fil+3][current_state.col] = sensores.terreno[9];
				mapaResultado[current_state.fil+3][current_state.col-1] = sensores.terreno[10];
				mapaResultado[current_state.fil+3][current_state.col-2] = sensores.terreno[11];
				mapaResultado[current_state.fil+3][current_state.col-3] = sensores.terreno[12];
				mapaResultado[current_state.fil+2][current_state.col-3] = sensores.terreno[13];
				mapaResultado[current_state.fil+1][current_state.col-3] = sensores.terreno[14];
				mapaResultado[current_state.fil][current_state.col-3] = sensores.terreno[15];
			break;

			case oeste: 
				mapaResultado[current_state.fil][current_state.col] = sensores.terreno[0];

				mapaResultado[current_state.fil-1][current_state.col-1] = sensores.terreno[3];
				mapaResultado[current_state.fil][current_state.col-1] = sensores.terreno[2];
				mapaResultado[current_state.fil+1][current_state.col-1] = sensores.terreno[1];

				mapaResultado[current_state.fil-2][current_state.col-2] = sensores.terreno[8];
				mapaResultado[current_state.fil-1][current_state.col-2] = sensores.terreno[7];
				mapaResultado[current_state.fil][current_state.col-2] = sensores.terreno[6];
				mapaResultado[current_state.fil+1][current_state.col-2] = sensores.terreno[5];
				mapaResultado[current_state.fil+2][current_state.col-2] = sensores.terreno[4];

				mapaResultado[current_state.fil-3][current_state.col-3] = sensores.terreno[15];
				mapaResultado[current_state.fil-2][current_state.col-3] = sensores.terreno[14];
				mapaResultado[current_state.fil-1][current_state.col-3] = sensores.terreno[13];
				mapaResultado[current_state.fil][current_state.col-3] = sensores.terreno[12];
				mapaResultado[current_state.fil+1][current_state.col-3] = sensores.terreno[11];
				mapaResultado[current_state.fil+2][current_state.col-3] = sensores.terreno[10];
				mapaResultado[current_state.fil+3][current_state.col-3] = sensores.terreno[9];
			break;

			case noroeste: 
				mapaResultado[current_state.fil][current_state.col] = sensores.terreno[0];

				mapaResultado[current_state.fil-1][current_state.col] = sensores.terreno[3];
				mapaResultado[current_state.fil-1][current_state.col-1] = sensores.terreno[2];
				mapaResultado[current_state.fil][current_state.col-1] = sensores.terreno[1];

				mapaResultado[current_state.fil-2][current_state.col] = sensores.terreno[8];
				mapaResultado[current_state.fil-2][current_state.col-1] = sensores.terreno[7];
				mapaResultado[current_state.fil-2][current_state.col-2] = sensores.terreno[6];
				mapaResultado[current_state.fil-1][current_state.col-2] = sensores.terreno[5];
				mapaResultado[current_state.fil][current_state.col-2] = sensores.terreno[4];

				mapaResultado[current_state.fil-3][current_state.col] = sensores.terreno[15];
				mapaResultado[current_state.fil-3][current_state.col-1] = sensores.terreno[14];
				mapaResultado[current_state.fil-3][current_state.col-2] = sensores.terreno[13];
				mapaResultado[current_state.fil-3][current_state.col-3] = sensores.terreno[12];
				mapaResultado[current_state.fil-2][current_state.col-3] = sensores.terreno[11];
				mapaResultado[current_state.fil-1][current_state.col-3] = sensores.terreno[10];
				mapaResultado[current_state.fil][current_state.col-3] = sensores.terreno[9];
			break;
		}
	}
	
	//RECOGER BIKINI
	if(sensores.terreno[2] == 'K' and !tengo_bikini){
		tengo_bikini = true;
	}

	//RECOGER ZAPATILLAS
	if(sensores.terreno[2] == 'D' and !tengo_zapatillas){
		tengo_zapatillas = true;
	}

	//Decir la nueva accion
	if (( sensores.terreno[2] == 'T' or sensores.terreno[2] == 'S' or sensores.terreno[2] == 'G' or sensores.terreno[2] == 'K' or sensores.terreno[2] == 'D') and sensores.agentes[2] == '_' ){
		accion = actWALK;
	}
	else if(tengo_bikini and sensores.terreno[2] == 'A'){
		accion = actWALK;
	}
	else if(tengo_zapatillas and sensores.terreno[2] == 'B'){
		accion = actWALK;
	}
	else if( !girar_derecha ){
		accion = actTURN_L;
		girar_derecha = (rand()%2 == 0);
	}
	else{
		accion = actTURN_SR;
		girar_derecha = (rand()%2 == 0);
	}

	//Recordar la ultima accion
	last_action = accion;

	//////////////////////////////////TUTORIAL\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
    \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//////////////////////////////////////

	// Mostrar el valor de los sensores
	cout << "Posicion: fila " << sensores.posF << " columna " << sensores.posC;
	switch (sensores.sentido)
	{
		case norte:	  cout << " Norte\n";	break;
		case noreste: cout << " Noreste\n";	break;
		case este:    cout << " Este\n";	break;
		case sureste: cout << " Sureste\n";	break;
		case sur:     cout << " Sur\n";	break;
		case suroeste:cout << " Suroeste\n";	break;
		case oeste:   cout << " Oeste\n";	break;
		case noroeste:cout << " Noroeste\n";	break;
	}
	cout << "Terreno: ";
	for (int i=0; i<sensores.terreno.size(); i++)
		cout << sensores.terreno[i];

	cout << "  Agentes: ";
	for (int i=0; i<sensores.agentes.size(); i++)
		cout << sensores.agentes[i];

	cout << "\nColision: " << sensores.colision;
	cout << "  Reset: " << sensores.reset;
	cout << "  Vida: " << sensores.vida << endl<< endl;

	return accion;
}

int ComportamientoJugador::interact(Action accion, int valor)
{
	return false;
}
