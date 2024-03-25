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
				for(int i = 0; i < 4 ;i++){
					for(int j = 0; j < 2*i + 1; j++){
						mapaResultado[current_state.fil-i][current_state.col-i+j] = sensores.terreno[i*i+j];
					}
				}
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
				for(int i = 0; i < 4 ;i++){
					for(int j = 0; j < 2*i + 1; j++){
						mapaResultado[current_state.fil-i+j][current_state.col+i] = sensores.terreno[i*i+j];
					}
				}
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
				for(int i = 0; i < 4 ;i++){
					for(int j = 2*i; j >= 0; j--){
						mapaResultado[current_state.fil+i][current_state.col+i-j] = sensores.terreno[i*i+j];
					}
				}
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
				for(int i = 0; i < 4 ;i++){
					for(int j = 2*i; j >= 0; j--){
						mapaResultado[current_state.fil+i-j][current_state.col-i] = sensores.terreno[i*i+j];
					}
				}
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
	if(sensores.terreno[0] == 'K' and !tengo_bikini){
		tengo_bikini = true;
	}

	//RECOGER ZAPATILLAS
	if(sensores.terreno[0] == 'D' and !tengo_zapatillas){
		tengo_zapatillas = true;
	}

	//ACTUALIZAR CASILLAS VISITADAS
	if(dimensiones){
		for(int i = 0; i < 100; i++){
			for(int j = 0; j < 100; j++){
				if(i-2 > n_casillas or j-2 > n_casillas or i < 3 or j < 3){
					visitas[i][j] = 3000;				
				}
				else if(mapaResultado[i][j] == 'P' or mapaResultado[i][j] == 'M'){
					visitas[i][j] = 3000;
				}
			}
		}

		//MOSTRAR MATRIZ VISITAS EN TERMINAL
		for(int i = 0; i < n_casillas+6; i++){
			for(int j = 0; j < n_casillas+6; j++){
				std::cout << visitas[i][j] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << "MIN = " << min << endl;
	}

	tiempo++;
	visitas[current_state.fil][current_state.col] += 1;
	
	
	//Decir la nueva accion
	
	switch(sensores.nivel){
		case 0 : 
			if(girando_I){
				accion = actTURN_L;
				girando_I = false;
				moverse = true;
			}
			else if(girando_D){
				accion = actTURN_SR;
				girando_D = false;
				moverse = true;
			}
			else if(girar_MAS_I){
				accion = actTURN_L;
				girar_MAS_I = false;
				moverse = true;
			}
			else if(girar_MAS_D){
				accion = actTURN_SR;
				girar_MAS_D = false;
				moverse = true;
			}
			else if(sensores.terreno[2] == 'P' and !he_visto_precipicio){
				accion = actTURN_L;
				he_visto_precipicio = true;
				girando_I = true;
				n_casillas = 1;
			}
			else if(sensores.terreno[2] == 'P' and he_visto_precipicio and inicio){
				inicio = false;
				dimensiones = true;
				moverse = false;
				std::cout << "He contado " << n_casillas << " casillas" << std::endl;
				accion = actTURN_L;
			}
			else if(inicio){
				accion = actWALK;
				n_casillas++;
			}
			else if(sensores.terreno[0] == 'X' and sensores.bateria < 2000){
				accion = actIDLE;
			}
			else if(moverse){
				accion = actWALK;
				moverse = false;
			}
			
			else{
				min = 3000;
				for(int i = -1; i < 2 ;i++){
					for(int j = -1; j < 2 ;j++){
						if(visitas[current_state.fil+i][current_state.col+j] < min and !(i == 0 and j == 0)){
							min = visitas[current_state.fil+i][current_state.col+j];
						}
					}
				}

				cout << "-=+=-EL MINIMO DEBE DE SER: " << min << "-=+=-" <<endl;
				switch(current_state.brujula){
					case norte: 
						if(visitas[current_state.fil-1][current_state.col] == min){
							//NORTE
							accion = actWALK;
						}
						else if(visitas[current_state.fil-1][current_state.col+1] == min){
							//NORESTE
							accion = actTURN_SR;
							moverse = true;
						}
						else if(visitas[current_state.fil][current_state.col+1] == min){
							//ESTE
							accion = actTURN_SR;
							girando_D = true;
						}
						else if(visitas[current_state.fil+1][current_state.col+1] == min){
							//SURESTE
							accion = actTURN_SR;
							girando_D = true;
							girar_MAS_D = true;
						}
						else if(visitas[current_state.fil+1][current_state.col] == min){
							//SUR
							accion = actTURN_L;
							girando_I = true;
						}
						else if(visitas[current_state.fil+1][current_state.col-1] == min){
							//SUROESTE
							accion = actTURN_L;
							girando_I = true;
							girar_MAS_D = true;
						}
						else if(visitas[current_state.fil][current_state.col-1] == min){
							//OESTE
							accion = actTURN_L;
							moverse = true;
						}
						else if(visitas[current_state.fil-1][current_state.col-1] == min){
							//NOROESTE
							accion = actTURN_L;
							girando_D = true;
						}
					break;

					case noreste:
						if(visitas[current_state.fil-1][current_state.col+1] == min){
							//NORESTE
							accion = actWALK;
						}
						else if(visitas[current_state.fil][current_state.col+1] == min){
							//ESTE
							accion = actTURN_SR;
							moverse = true;
						}
						else if(visitas[current_state.fil+1][current_state.col+1] == min){
							//SURESTE
							accion = actTURN_SR;
							girando_D = true;
						}
						else if(visitas[current_state.fil+1][current_state.col] == min){
							//SUR
							accion = actTURN_SR;
							girando_D = true;
							girar_MAS_D = true;
						}
						else if(visitas[current_state.fil+1][current_state.col-1] == min){
							//SUROESTE
							accion = actTURN_L;
							girando_I = true;
						}
						else if(visitas[current_state.fil][current_state.col-1] == min){
							//OESTE
							accion = actTURN_L;
							girando_I = true;
							girar_MAS_D = true;
						}
						else if(visitas[current_state.fil-1][current_state.col-1] == min){
							//NOROESTE
							accion = actTURN_L;
							moverse = true;
						}
						else if(visitas[current_state.fil-1][current_state.col] == min){
							//NORTE
							accion = actTURN_L;
							girando_D = true;
						}
					break;

					case este:
						if(visitas[current_state.fil][current_state.col+1] == min){
							//ESTE
							accion = actWALK;
						}
						else if(visitas[current_state.fil-1][current_state.col] == min){
							//NORTE
							accion = actTURN_L;
							moverse = true;
						}
						else if(visitas[current_state.fil-1][current_state.col+1] == min){
							//NORESTE
							accion = actTURN_L;
							girando_D = true;
						}
						else if(visitas[current_state.fil+1][current_state.col+1] == min){
							//SURESTE
							accion = actTURN_SR;
							moverse = true;
						}
						else if(visitas[current_state.fil+1][current_state.col] == min){
							//SUR
							accion = actTURN_SR;
							girando_D = true;
						}
						else if(visitas[current_state.fil+1][current_state.col-1] == min){
							//SUROESTE
							accion = actTURN_SR;
							girando_D = true;
							girar_MAS_D = true;
						}
						else if(visitas[current_state.fil][current_state.col-1] == min){
							//OESTE
							accion = actTURN_L;
							girando_I = true;
						}
						else if(visitas[current_state.fil-1][current_state.col-1] == min){
							//NOROESTE
							accion = actTURN_L;
							girando_I = true;
							girar_MAS_D = true;
						}
					break;

					case sureste:
						if(visitas[current_state.fil+1][current_state.col+1] == min){
							//SURESTE
							accion = actWALK;
						}
						else if(visitas[current_state.fil+1][current_state.col] == min){
							//SUR
							accion = actTURN_SR;
							moverse = true;
						}
						else if(visitas[current_state.fil+1][current_state.col-1] == min){
							//SUROESTE
							accion = actTURN_SR;
							girando_D = true;
						}
						else if(visitas[current_state.fil][current_state.col-1] == min){
							//OESTE
							accion = actTURN_SR;
							girando_D = true;
							girar_MAS_D = true;
						}
						else if(visitas[current_state.fil-1][current_state.col-1] == min){
							//NOROESTE
							accion = actTURN_L;
							girando_I = true;
						}
						else if(visitas[current_state.fil-1][current_state.col] == min){
							//NORTE
							accion = actTURN_L;
							girando_I = true;
							girar_MAS_D = true;
						}
						else if(visitas[current_state.fil-1][current_state.col+1] == min){
							//NORESTE
							accion = actTURN_L;
							moverse = true;
						}
						else if(visitas[current_state.fil][current_state.col+1] == min){
							//ESTE
							accion = actTURN_L;
							girando_D = true;
						}
					break;

					case sur:
						if(visitas[current_state.fil+1][current_state.col] == min){
							//SUR
							accion = actWALK;
						}
						else if(visitas[current_state.fil+1][current_state.col+1] == min){
							//SURESTE
							accion = actTURN_L;
							girando_D = true;
						}
						else if(visitas[current_state.fil][current_state.col+1] == min){
							//ESTE
							accion = actTURN_L;
							moverse = true;
						}
						else if(visitas[current_state.fil-1][current_state.col+1] == min){
							//NORESTE
							accion = actTURN_L;
							girando_I = true;
							girar_MAS_D = true;
						}
						else if(visitas[current_state.fil-1][current_state.col] == min){
							//NORTE
							accion = actTURN_L;
							girando_I = true;
						}
						else if(visitas[current_state.fil-1][current_state.col-1] == min){
							//NOROESTE
							accion = actTURN_SR;
							girando_D = true;
							girar_MAS_D = true;
						}
						else if(visitas[current_state.fil][current_state.col-1] == min){
							//OESTE
							accion = actTURN_SR;
							girando_D = true;
						}
						else if(visitas[current_state.fil+1][current_state.col-1] == min){
							//SUROESTE
							accion = actTURN_SR;
							moverse = true;
						}
					break;

					case suroeste:
						if(visitas[current_state.fil+1][current_state.col-1] == min){
							//SUROESTE
							accion = actWALK;
						}
						else if(visitas[current_state.fil][current_state.col-1] == min){
							//OESTE
							accion = actTURN_SR;
							moverse = true;
						}
						else if(visitas[current_state.fil-1][current_state.col-1] == min){
							//NOROESTE
							accion = actTURN_SR;
							girando_D = true;
						}
						else if(visitas[current_state.fil-1][current_state.col] == min){
							//NORTE
							accion = actTURN_SR;
							girando_D = true;
							girar_MAS_D = true;
						}
						else if(visitas[current_state.fil-1][current_state.col+1] == min){
							//NORESTE
							accion = actTURN_L;
							girando_I = true;
						}
						else if(visitas[current_state.fil][current_state.col+1] == min){
							//ESTE
							accion = actTURN_L;
							girando_I = true;
							girar_MAS_D = true;
						}
						else if(visitas[current_state.fil+1][current_state.col+1] == min){
							//SURESTE
							accion = actTURN_L;
							moverse = true;
						}
						else if(visitas[current_state.fil+1][current_state.col] == min){
							//SUR
							accion = actTURN_L;
							girando_D = true;
						}
						
					break;

					case oeste:
						if(visitas[current_state.fil][current_state.col-1] == min){
							//OESTE
							accion = actWALK;
						}
						else if(visitas[current_state.fil-1][current_state.col-1] == min){
							//NOROESTE
							accion = actTURN_SR;
							moverse = true;
						}
						else if(visitas[current_state.fil-1][current_state.col] == min){
							//NORTE
							accion = actTURN_SR;
							girando_D = true;
						}
						else if(visitas[current_state.fil-1][current_state.col+1] == min){
							//NORESTE
							accion = actTURN_SR;
							girando_D = true;
							girar_MAS_D = true;
						}
						else if(visitas[current_state.fil][current_state.col+1] == min){
							//ESTE
							accion = actTURN_L;
							girando_I = true;
						}
						else if(visitas[current_state.fil+1][current_state.col+1] == min){
							//SURESTE
							accion = actTURN_L;
							girando_I = true;
							girar_MAS_D = true;
						}
						else if(visitas[current_state.fil+1][current_state.col] == min){
							//SUR
							accion = actTURN_L;
							moverse = true;
						}
						else if(visitas[current_state.fil+1][current_state.col-1] == min){
							//SUROESTE
							accion = actTURN_L;
							girando_D = true;
						}
					break;

					case noroeste:
						if(visitas[current_state.fil-1][current_state.col-1] == min){
							//NOROESTE
							accion = actWALK;
						}
						else if(visitas[current_state.fil][current_state.col-1] == min){
							//OESTE
							accion = actTURN_L;
							girando_D = true;
						}
						else if(visitas[current_state.fil+1][current_state.col-1] == min){
							//SUROESTE
							accion = actTURN_L;
							moverse = true;
						}
						else if(visitas[current_state.fil+1][current_state.col] == min){
							//SUR
							accion = actTURN_L;
							girando_I = true;
							girar_MAS_D = true;
						}
						else if(visitas[current_state.fil+1][current_state.col+1] == min){
							//SURESTE
							accion = actTURN_L;
							girando_I = true;
						}
						else if(visitas[current_state.fil][current_state.col+1] == min){
							//ESTE
							accion = actTURN_SR;
							girando_D = true;
							girar_MAS_D = true;
						}
						else if(visitas[current_state.fil-1][current_state.col+1] == min){
							//NORESTE
							accion = actTURN_SR;
							girando_D = true;
						}
						else if(visitas[current_state.fil-1][current_state.col] == min){
							//NORTE
							accion = actTURN_SR;
							moverse = true;
						}
					break;
				}
			}
			/*
			
			else if (sensores.terreno[2] != 'P' and sensores.terreno[2] != 'M' and sensores.terreno[2] != 'A' and sensores.terreno[2] != 'B' and sensores.agentes[2] == '_'){
				accion = actWALK;
			}
			else if(sensores.bateria < 2000 and sensores.terreno[2] == 'X'){
				accion = actIDLE;
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
			*/
			
		break;
		case 1 : break;
		case 2 : break;
		case 3 : break;
	}

	
	

	//Recordar la ultima accion
	last_action = accion;

	//////////////////////////////////TUTORIAL\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
    \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//////////////////////////////////////

	// Mostrar el valor de los sensores
	std::cout << "Posicion: fila " << sensores.posF << " columna " << sensores.posC;
	switch (sensores.sentido)
	{
		case norte:	  std::cout << " Norte\n";	break;
		case noreste: std::cout << " Noreste\n";	break;
		case este:    std::cout << " Este\n";	break;
		case sureste: std::cout << " Sureste\n";	break;
		case sur:     std::cout << " Sur\n";	break;
		case suroeste:std::cout << " Suroeste\n";	break;
		case oeste:   std::cout << " Oeste\n";	break;
		case noroeste:std::cout << " Noroeste\n";	break;
	}
	std::cout << "Terreno: ";
	for (int i=0; i<sensores.terreno.size(); i++)
		std::cout << sensores.terreno[i];

	std::cout << "  Agentes: ";
	for (int i=0; i<sensores.agentes.size(); i++)
		std::cout << sensores.agentes[i];

	std::cout << "\nColision: " << sensores.colision;
	std::cout << "  Reset: " << sensores.reset;
	std::cout << "  Vida: " << sensores.vida << endl<< endl;

	return accion;
}

int ComportamientoJugador::interact(Action accion, int valor)
{
	return false;
}
