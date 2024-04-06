#include "../Comportamientos_Jugador/jugador.hpp"
#include <iostream>
using namespace std;

Action ComportamientoJugador::think(Sensores sensores)
{

	Action accion = actIDLE;
	int a;

    //DEFINICION DE MOVIMIENTOS
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

    //COMPROBAR SI EL AGENTE SE HA CHOCADO CON UN LOBO
    if(sensores.reset){
        bien_situado = false;
        orientado = false;
        tengo_bikini = false;
        tengo_zapatillas = false;
    }

    //COMPROBAR SI EL AGENTE ESTA EN UNA CASILLA DE POSICIONAMIENTO
    if(sensores.terreno[0] == 'G'){
        orientado = true;
    }

    //COMPROBAR SI SE PUEDE EMPEZAR A UTILIZAR LA VISION
	if(!bien_situado and orientado){
        cout << "SITUADO" << endl;
        current_state.fil = sensores.posF;
        cout << "FILA: " << current_state.fil << endl;
		current_state.col = sensores.posC;
        cout << "COLUMNA: " << current_state.col << endl;
        current_state.brujula = sensores.sentido;	
        cout << "BRUJULA: " << current_state.brujula << endl;	
		bien_situado = true;
	}
	
    //VISION DEL AGENTE
	if(bien_situado){
		switch(current_state.brujula){
			case norte: 
				for(int i = 0; i < 4 ;i++){
					for(int j = 0; j < 2*i + 1; j++){
                        if(!(sensores.nivel == 3 and (i*i+j == 6 or i*i+j == 11 or i*i+j == 12 or i*i+j == 13))){
						    mapaResultado[current_state.fil-i][current_state.col-i+j] = sensores.terreno[i*i+j];
                        }
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
                if(sensores.nivel != 3){
                    mapaResultado[current_state.fil-2][current_state.col+2] = sensores.terreno[6];
                }
				mapaResultado[current_state.fil-1][current_state.col+2] = sensores.terreno[7];
				mapaResultado[current_state.fil][current_state.col+2] = sensores.terreno[8];

				mapaResultado[current_state.fil-3][current_state.col] = sensores.terreno[9];
				mapaResultado[current_state.fil-3][current_state.col+1] = sensores.terreno[10];
                if(sensores.nivel != 3){
                    mapaResultado[current_state.fil-3][current_state.col+2] = sensores.terreno[11];
                    mapaResultado[current_state.fil-3][current_state.col+3] = sensores.terreno[12];
                    mapaResultado[current_state.fil-2][current_state.col+3] = sensores.terreno[13];
                }
				mapaResultado[current_state.fil-1][current_state.col+3] = sensores.terreno[14];
				mapaResultado[current_state.fil][current_state.col+3] = sensores.terreno[15];
			break;

			case este: 
				for(int i = 0; i < 4 ;i++){
					for(int j = 0; j < 2*i + 1; j++){
                        if(!(sensores.nivel == 3 and (i*i+j == 6 or i*i+j == 11 or i*i+j == 12 or i*i+j == 13))){
                            mapaResultado[current_state.fil-i+j][current_state.col+i] = sensores.terreno[i*i+j];  
                        }
						
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
                if(sensores.nivel != 3){
				    mapaResultado[current_state.fil+2][current_state.col+2] = sensores.terreno[6];
                }
				mapaResultado[current_state.fil+1][current_state.col+2] = sensores.terreno[5];
				mapaResultado[current_state.fil][current_state.col+2] = sensores.terreno[4];

				mapaResultado[current_state.fil+3][current_state.col] = sensores.terreno[15];
				mapaResultado[current_state.fil+3][current_state.col+1] = sensores.terreno[14];
                if(sensores.nivel != 3){
                    mapaResultado[current_state.fil+3][current_state.col+2] = sensores.terreno[13];
                    mapaResultado[current_state.fil+3][current_state.col+3] = sensores.terreno[12];
                    mapaResultado[current_state.fil+2][current_state.col+3] = sensores.terreno[11];
                }
				mapaResultado[current_state.fil+1][current_state.col+3] = sensores.terreno[10];
				mapaResultado[current_state.fil][current_state.col+3] = sensores.terreno[9];
			break;

			case sur: 
				for(int i = 0; i < 4 ;i++){
					for(int j = 2*i; j >= 0; j--){
                        if(!(sensores.nivel == 3 and (i*i+j == 6 or i*i+j == 11 or i*i+j == 12 or i*i+j == 13))){
						    mapaResultado[current_state.fil+i][current_state.col+i-j] = sensores.terreno[i*i+j];
                        }
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
                if(sensores.nivel != 3){
				    mapaResultado[current_state.fil+2][current_state.col-2] = sensores.terreno[6];
                }
				mapaResultado[current_state.fil+1][current_state.col-2] = sensores.terreno[7];
				mapaResultado[current_state.fil][current_state.col-2] = sensores.terreno[8];

				mapaResultado[current_state.fil+3][current_state.col] = sensores.terreno[9];
				mapaResultado[current_state.fil+3][current_state.col-1] = sensores.terreno[10];
                if(sensores.nivel != 3){
                    mapaResultado[current_state.fil+3][current_state.col-2] = sensores.terreno[11];
                    mapaResultado[current_state.fil+3][current_state.col-3] = sensores.terreno[12];
                    mapaResultado[current_state.fil+2][current_state.col-3] = sensores.terreno[13];
                }
				mapaResultado[current_state.fil+1][current_state.col-3] = sensores.terreno[14];
				mapaResultado[current_state.fil][current_state.col-3] = sensores.terreno[15];
			break;

			case oeste: 
				for(int i = 0; i < 4 ;i++){
					for(int j = 2*i; j >= 0; j--){
                        if(!(sensores.nivel == 3 and (i*i+j == 6 or i*i+j == 11 or i*i+j == 12 or i*i+j == 13))){
                            mapaResultado[current_state.fil+i-j][current_state.col-i] = sensores.terreno[i*i+j];
                        }
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
                if(sensores.nivel != 3){
				    mapaResultado[current_state.fil-2][current_state.col-2] = sensores.terreno[6];
                }
				mapaResultado[current_state.fil-1][current_state.col-2] = sensores.terreno[5];
				mapaResultado[current_state.fil][current_state.col-2] = sensores.terreno[4];

				mapaResultado[current_state.fil-3][current_state.col] = sensores.terreno[15];
				mapaResultado[current_state.fil-3][current_state.col-1] = sensores.terreno[14];
                if(sensores.nivel != 3){
                    mapaResultado[current_state.fil-3][current_state.col-2] = sensores.terreno[13];
                    mapaResultado[current_state.fil-3][current_state.col-3] = sensores.terreno[12];
                    mapaResultado[current_state.fil-2][current_state.col-3] = sensores.terreno[11];
                }
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
	n_casillas = mapaResultado.size();
	cout << "CASILLAS: " << n_casillas << endl;

	if(orientado){
		for(int i = 0 ; i < n_casillas ; i++){
			for(int j = 0;  j < n_casillas ; j++){
				if(mapaResultado[i][j] == 'P' or mapaResultado[i][j] == 'M'){
					visitas[i][j] = 3000;
				}
                if(i < 3 or j < 3 or i > n_casillas-3 or j > n_casillas-3){
                    visitas[i][j] = 3000;
                }
			}
		}
		visitas[current_state.fil][current_state.col]++;
		
		
		//MOSTRAR CASILLAS VISITADAS POR PANTALLA
        
		for(int i = 0; i < n_casillas; i++){
			for(int j = 0; j < n_casillas; j++){
				cout << visitas[i][j] << " ";
			}
			cout << endl;
		}
	}

    //ACTUALIZAR MATRIZ DE SENSION
    /*
    if(orientado){
        for (int i = -3; i < 4 ; i++) {
            for (int j = -3; j < 4 ; j++) {
                if( (j < -2 or i > 2) or (i<-2 or j>2) ){
                    diametro[current_state.fil + i][current_state.col + j] = visitas[current_state.fil + i][current_state.col + j]+1;
                    diametro[current_state.fil][current_state.col] = 1;
                }
            }
        }

        for(int i = 0; i < n_casillas; i++){
			for(int j = 0; j < n_casillas; j++){
				cout << diametro[i][j] << " ";
			}
			cout << endl;
		}
    }
    */
 
	
	
	//Decir la nueva accion
	switch(sensores.nivel){
		case 0 : 
			//Todo el sistema sensorial funciona correctamente y el agente es el único agente que está en la simulación.
			orientado = true;
            if(inicio){
                accion = nextMove(sensores);
            }
            inicio = true;
		break;
		case 1 : 
			/*
			No funciona los sensores de posicionamiento posF, posC y sentido
			(dan siempre el valor -1 los dos primeros y siempre norte el último). 
			Inicialmente el agente empieza con orientación norte. Para poder 
			situarse en el mapa se utilizan las casillas de Posicionamiento. En 
			esas casillas, los sensores darán los valores correctos.
			*/
            if(inicio){
                if(!orientado){
                    accion = blindMove(sensores);
                }
                else{
                    accion = nextMove(sensores);
                }
            }
            inicio = true;		
		break;
		case 2 : 
			/*
			La situación sensorial del nivel anterior, pero ahora en el mapa
			pueden aparecer otros agentes como los aldeanos y los lobos. En este nivel se
			deben gestionar las colisiones y los reinicios con estos agentes
			*/
            if(inicio){
                if(!orientado){
                    if(sensores.agentes[2] != '_'){
                        if(!girar_derecha){
                            accion = actTURN_L;
                            girar_derecha = (rand()%5 == 0);
                        }
                        else{
                            accion = actTURN_SR;
                            girar_derecha = (rand()%5 == 0);
                        }
                    }
                    else{
                        accion = blindMove(sensores);
                    }
                }
                else if(sensores.agentes[2] != '_'){
                    if(!girar_derecha){
                        accion = actTURN_L;
                        girar_derecha = (rand()%5 == 0);
                    }
                    else{
                        accion = actTURN_SR;
                        girar_derecha = (rand()%5 == 0);
                    }
                }
                else{
                    accion = nextMove(sensores);
                }
            }
            inicio = true;
		break;
		case 3 : 
			/*
			Las condiciones del nivel 2 pero en este caso, (1) la orientación es
			desconocida al inicio, aunque se sabe que no es diagonal (es decir, es norte o
			sur o este u oeste). Además, el sensor de visión del terreno no da información
			sobre lo que aparece en las casillas 6, 11, 12 y 13.
			*/
            if(inicio){
                if(!orientado){
                    if(sensores.agentes[2] != '_'){
                        if(!girar_derecha){
                            accion = actTURN_L;
                            girar_derecha = (rand()%5 == 0);
                        }
                        else{
                            accion = actTURN_SR;
                            girar_derecha = (rand()%5 == 0);
                        }
                    }
                    else{
                        accion = blindMove(sensores);
                    }
                }
                else if(sensores.agentes[2] != '_'){
                    if(!girar_derecha){
                        accion = actTURN_L;
                        girar_derecha = (rand()%5 == 0);
                    }
                    else{
                        accion = actTURN_SR;
                        girar_derecha = (rand()%5 == 0);
                    }
                }
                else{
                    accion = nextMove(sensores);
                }
            }
            inicio = true;
		break;
	}

	//Recordar la ultima accion
	last_action = accion;

	// Mostrar el valor de los sensores
	std::cout << "Posicion: fila " << sensores.posF << " columna " << sensores.posC;
	switch (sensores.sentido)
	{
		case norte:	  std::cout << " Norte\n";	    break;
		case noreste: std::cout << " Noreste\n";	break;
		case este:    std::cout << " Este\n";	    break;
		case sureste: std::cout << " Sureste\n";	break;
		case sur:     std::cout << " Sur\n";	    break;
		case suroeste:std::cout << " Suroeste\n";	break;
		case oeste:   std::cout << " Oeste\n";	    break;
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

Action ComportamientoJugador::nextMove(Sensores sensores) {
    Action accion = actIDLE;
    if (girando_I) {
        accion = actTURN_L;
        girando_I = false;
        if (inicio and !sensores.reset) {
            moverse = true;
        }
    } 
    else if (girando_D) {
        accion = actTURN_SR;
        girando_D = false;
        if (inicio and !sensores.reset) {
            moverse = true;
        }
    } 
    else if (girar_MAS_I) {
        accion = actTURN_L;
        girar_MAS_I = false;
        if (inicio and !sensores.reset) {
            moverse = true;
        }
    } 
    else if (girar_MAS_D) {
        accion = actTURN_SR;
        girar_MAS_D = false;
        if (inicio and !sensores.reset) {
            moverse = true;
        }
    } 
    else if (sensores.terreno[0] == 'X' and sensores.bateria < 2000) {
        accion = actIDLE;
        visitas[current_state.fil][current_state.col] = 0;
    } 
    else if (moverse) {
        accion = actWALK;
        moverse = false;
    } 
    else {
        min_remoto = 3000;
        min_local = 3000;
            
        for (int i = -3; i < 4 and remoto; i++) {
            for (int j = -3; j < 4 and remoto; j++) {
                if(visitas[current_state.fil + i][current_state.col + j] == 3000){
                    remoto = false;
                }
                else if( (j < -2 or i > 2) or (i<-2 or j>2) ){
                    if(i%3 == 0 and j%3 == 0){
                        if(visitas[current_state.fil + i][current_state.col + j] < min_remoto){
                            min_remoto = visitas[current_state.fil + i][current_state.col + j];
                        }
                        remoto = true;
                    }
                }
            }
        }
        
        if(visitas[current_state.fil][current_state.col] > 2){
            remoto = false;
        }
        

        if(!remoto){
            for (int i = -1; i < 2; i++) {
                for (int j = -1; j < 2; j++) {
                    if (visitas[current_state.fil + i][current_state.col + j] < min_local and !(i == 0 and j == 0)) {
                        min_local = visitas[current_state.fil + i][current_state.col + j];
                    }
                }
            }
        }
        
        if(remoto){
            switch (current_state.brujula) {
                case norte:
                    remoto = true;
                    if (visitas[current_state.fil - 3][current_state.col] == min_remoto) {
                        // NORTE
                        accion = actWALK;
                    } 
                    else if (visitas[current_state.fil - 3][current_state.col + 3] == min_remoto) {
                        // NORESTE
                        accion = actTURN_SR;
                        moverse = true;
                    } 
                    else if (visitas[current_state.fil][current_state.col - 3] == min_remoto) {
                        // OESTE
                        accion = actTURN_L;
                        moverse = true;
                    } 
                    else if (visitas[current_state.fil][current_state.col + 3] == min_remoto) {
                        // ESTE
                        accion = actTURN_SR;
                        girando_D = true;
                    } 
                    else if (visitas[current_state.fil - 3][current_state.col - 3] == min_remoto) {
                        // NOROESTE
                        accion = actTURN_L;
                        girando_D = true;
                    } 
                    else if (visitas[current_state.fil + 3][current_state.col] == min_remoto) {
                        // SUR
                        accion = actTURN_L;
                        girando_I = true;
                    } 
                    else if (visitas[current_state.fil + 3][current_state.col + 3] == min_remoto) {
                        // SURESTE
                        accion = actTURN_SR;
                        girando_D = true;
                        girar_MAS_D = true;
                    } 
                    else if (visitas[current_state.fil + 3][current_state.col - 3] == min_remoto) {
                        // SUROESTE
                        accion = actTURN_L;
                        girando_I = true;
                        girar_MAS_D = true;
                    }
                    else{
                        remoto = false;
                    }
                break;

                case noreste:
                    remoto = true;
                    if (visitas[current_state.fil - 3][current_state.col + 3] == min_remoto) {
                        // NORESTE
                        accion = actWALK;
                    } 
                    else if (visitas[current_state.fil][current_state.col + 3] == min_remoto) {
                        // ESTE
                        accion = actTURN_SR;
                        moverse = true;
                    } 
                    else if (visitas[current_state.fil - 3][current_state.col - 3] == min_remoto) {
                        // NOROESTE
                        accion = actTURN_L;
                        moverse = true;
                    } 
                    else if (visitas[current_state.fil + 3][current_state.col + 3] == min_remoto) {
                        // SURESTE
                        accion = actTURN_SR;
                        girando_D = true;
                    } 
                    else if (visitas[current_state.fil - 3][current_state.col] == min_remoto) {
                        // NORTE
                        accion = actTURN_L;
                        girando_D = true;
                    } 
                    else if (visitas[current_state.fil + 3][current_state.col - 3] == min_remoto) {
                        // SUROESTE
                        accion = actTURN_L;
                        girando_I = true;
                    } 
                    else if (visitas[current_state.fil + 3][current_state.col] == min_remoto) {
                        // SUR
                        accion = actTURN_SR;
                        girando_D = true;
                        girar_MAS_D = true;
                    } 
                    else if (visitas[current_state.fil][current_state.col - 3] == min_remoto) {
                        // OESTE
                        accion = actTURN_L;
                        girando_I = true;
                        girar_MAS_D = true;
                    }
                    else{
                        remoto = false;
                    }
                break;

                case este:
                    remoto = true;
                    if (visitas[current_state.fil][current_state.col + 3] == min_remoto) {
                        // ESTE
                        accion = actWALK;
                    } 
                    else if (visitas[current_state.fil + 3][current_state.col + 3] == min_remoto) {
                        // SURESTE
                        accion = actTURN_SR;
                        moverse = true;
                    } 
                    else if (visitas[current_state.fil - 3][current_state.col] == min_remoto) {
                        // NORTE
                        accion = actTURN_L;
                        moverse = true;
                    } 
                    else if (visitas[current_state.fil + 3][current_state.col] == min_remoto) {
                        // SUR
                        accion = actTURN_SR;
                        girando_D = true;
                    } 
                    else if (visitas[current_state.fil - 3][current_state.col + 3] == min_remoto) {
                        // NORESTE
                        accion = actTURN_L;
                        girando_D = true;
                    } 
                    else if (visitas[current_state.fil][current_state.col - 3] == min_remoto) {
                        // OESTE
                        accion = actTURN_L;
                        girando_I = true;
                    } 
                    else if (visitas[current_state.fil + 3][current_state.col - 3] == min_remoto) {
                        // SUROESTE
                        accion = actTURN_SR;
                        girando_D = true;
                        girar_MAS_D = true;
                    } 
                    else if (visitas[current_state.fil - 3][current_state.col - 3] == min_remoto) {
                        // NOROESTE
                        accion = actTURN_L;
                        girando_I = true;
                        girar_MAS_D = true;
                    }
                    else{
                        remoto = false;
                    }
                break;

                case sureste:
                    remoto = true;
                    if (visitas[current_state.fil + 3][current_state.col + 3] == min_remoto) {
                        // SURESTE
                        accion = actWALK;
                    } 
                    else if (visitas[current_state.fil + 3][current_state.col] == min_remoto) {
                        // SUR
                        accion = actTURN_SR;
                        moverse = true;
                    } 
                    else if (visitas[current_state.fil - 3][current_state.col + 3] == min_remoto) {
                        // NORESTE
                        accion = actTURN_L;
                        moverse = true;
                    }
                    else if (visitas[current_state.fil + 3][current_state.col - 3] == min_remoto) {
                        // SUROESTE
                        accion = actTURN_SR;
                        girando_D = true;
                    } 
                    else if (visitas[current_state.fil][current_state.col + 3] == min_remoto) {
                        // ESTE
                        accion = actTURN_L;
                        girando_D = true;
                    } 
                    else if (visitas[current_state.fil - 3][current_state.col - 3] == min_remoto) {
                        // NOROESTE
                        accion = actTURN_L;
                        girando_I = true;
                    } 
                    else if (visitas[current_state.fil][current_state.col - 3] == min_remoto) {
                        // OESTE
                        accion = actTURN_SR;
                        girando_D = true;
                        girar_MAS_D = true;
                    } 
                    else if (visitas[current_state.fil - 3][current_state.col] == min_remoto) {
                        // NORTE
                        accion = actTURN_L;
                        girando_I = true;
                        girar_MAS_D = true;
                    }   
                    else{
                        remoto = false;
                    }
                break;

                case sur:
                    remoto = true;
                    if (visitas[current_state.fil + 3][current_state.col] == min_remoto) {
                        // SUR
                        accion = actWALK;
                    } 
                    else if (visitas[current_state.fil + 3][current_state.col - 3] == min_remoto) {
                        // SUROESTE
                        accion = actTURN_SR;
                        moverse = true;
                    } 
                    else if (visitas[current_state.fil][current_state.col + 3] == min_remoto) {
                        // ESTE
                        accion = actTURN_L;
                        moverse = true;
                    } 
                    else if (visitas[current_state.fil][current_state.col - 3] == min_remoto) {
                        // OESTE
                        accion = actTURN_SR;
                        girando_D = true;
                    } 
                    else if (visitas[current_state.fil + 3][current_state.col + 3] == min_remoto) {
                        // SURESTE
                        accion = actTURN_L;
                        girando_D = true;
                    } 
                    else if (visitas[current_state.fil - 3][current_state.col] == min_remoto) {
                        // NORTE
                        accion = actTURN_L;
                        girando_I = true;
                    } 
                    else if (visitas[current_state.fil - 3][current_state.col - 3] == min_remoto) {
                        // NOROESTE
                        accion = actTURN_SR;
                        girando_D = true;
                        girar_MAS_D = true;
                    } 
                    else if (visitas[current_state.fil - 3][current_state.col + 3] == min_remoto) {
                        // NORESTE
                        accion = actTURN_L;
                        girando_I = true;
                        girar_MAS_D = true;
                    }
                    else{
                        remoto = false;
                    }
                break;

                case suroeste:
                    remoto = true;
                    if (visitas[current_state.fil + 3][current_state.col - 3] == min_remoto) {
                        // SUROESTE
                        accion = actWALK;
                    } 
                    else if (visitas[current_state.fil][current_state.col - 3] == min_remoto) {
                        // OESTE
                        accion = actTURN_SR;
                        moverse = true;
                    } 
                    else if (visitas[current_state.fil + 3][current_state.col + 3] == min_remoto) {
                        // SURESTE
                        accion = actTURN_L;
                        moverse = true;
                    } 
                    else if (visitas[current_state.fil - 3][current_state.col - 3] == min_remoto) {
                        // NOROESTE
                        accion = actTURN_SR;
                        girando_D = true;
                    } 
                    else if (visitas[current_state.fil + 3][current_state.col] == min_remoto) {
                        // SUR
                        accion = actTURN_L;
                        girando_D = true;
                    } 
                    else if (visitas[current_state.fil - 3][current_state.col + 3] == min_remoto) {
                        // NORESTE
                        accion = actTURN_L;
                        girando_I = true;
                    } 
                    else if (visitas[current_state.fil - 3][current_state.col] == min_remoto) {
                        // NORTE
                        accion = actTURN_SR;
                        girando_D = true;
                        girar_MAS_D = true;
                    } 
                    else if (visitas[current_state.fil][current_state.col + 3] == min_remoto) {
                        // ESTE
                        accion = actTURN_L;
                        girando_I = true;
                        girar_MAS_D = true;
                    }
                    else{
                        remoto = false;
                    }
                break;

                case oeste:
                    remoto = true;
                    if (visitas[current_state.fil][current_state.col - 3] == min_remoto) {
                        // OESTE
                        accion = actWALK;
                    } 
                    else if (visitas[current_state.fil - 3][current_state.col - 3] == min_remoto) {
                        // NOROESTE
                        accion = actTURN_SR;
                        moverse = true;
                    } 
                    else if (visitas[current_state.fil + 3][current_state.col] == min_remoto) {
                        // SUR
                        accion = actTURN_L;
                        moverse = true;
                    } 
                    else if (visitas[current_state.fil - 3][current_state.col] == min_remoto) {
                        // NORTE
                        accion = actTURN_SR;
                        girando_D = true;
                    } 
                    else if (visitas[current_state.fil + 3][current_state.col - 3] == min_remoto) {
                        // SUROESTE
                        accion = actTURN_L;
                        girando_D = true;
                    } 
                    else if (visitas[current_state.fil][current_state.col + 3] == min_remoto) {
                        // ESTE
                        accion = actTURN_L;
                        girando_I = true;
                    } 
                    else if (visitas[current_state.fil - 3][current_state.col + 3] == min_remoto) {
                        // NORESTE
                        accion = actTURN_SR;
                        girando_D = true;
                        girar_MAS_D = true;
                    } 
                    else if (visitas[current_state.fil + 3][current_state.col + 3] == min_remoto) {
                        // SURESTE
                        accion = actTURN_L;
                        girando_I = true;
                        girar_MAS_D = true;
                    }
                    else{
                        remoto = false;
                    }
                break;

                case noroeste:
                    remoto = true;
                    if (visitas[current_state.fil - 3][current_state.col - 3] == min_remoto) {
                        // NOROESTE
                        accion = actWALK;
                    } 
                    else if (visitas[current_state.fil - 3][current_state.col] == min_remoto) {
                        // NORTE
                        accion = actTURN_SR;
                        moverse = true;
                    } 
                    else if (visitas[current_state.fil + 3][current_state.col - 3] == min_remoto) {
                        // SUROESTE
                        accion = actTURN_L;
                        moverse = true;
                    } 
                    else if (visitas[current_state.fil - 3][current_state.col + 3] == min_remoto) {
                        // NORESTE
                        accion = actTURN_SR;
                        girando_D = true;
                    } 
                    else if (visitas[current_state.fil][current_state.col - 3] == min_remoto) {
                        // OESTE
                        accion = actTURN_L;
                        girando_D = true;
                    } 
                    else if (visitas[current_state.fil + 3][current_state.col + 3] == min_remoto) {
                        // SURESTE
                        accion = actTURN_L;
                        girando_I = true;
                    } 
                    else if (visitas[current_state.fil][current_state.col + 3] == min_remoto) {
                        // ESTE
                        accion = actTURN_SR;
                        girando_D = true;
                        girar_MAS_D = true;
                    } 
                    else if (visitas[current_state.fil + 3][current_state.col] == min_remoto) {
                        // SUR
                        accion = actTURN_L;
                        girando_I = true;
                        girar_MAS_D = true;
                    }
                    else{
                        remoto = false;
                    }
                break;
            }
        }
        else{
            cout << "EL MINIMO LOCAL ES: " << min_local << endl;
            switch (current_state.brujula) {
                case norte:
                    remoto = true;
                    if (visitas[current_state.fil - 1][current_state.col] == min_local) {
                        // NORTE
                        accion = actWALK;
                    } 
                    else if (visitas[current_state.fil - 1][current_state.col + 1] == min_local) {
                        // NORESTE
                        accion = actTURN_SR;
                        moverse = true;
                    } 
                    else if (visitas[current_state.fil][current_state.col - 1] == min_local) {
                        // OESTE
                        accion = actTURN_L;
                        moverse = true;
                    } 
                    else if (visitas[current_state.fil][current_state.col + 1] == min_local) {
                        // ESTE
                        accion = actTURN_SR;
                        girando_D = true;
                    } 
                    else if (visitas[current_state.fil - 1][current_state.col - 1] == min_local) {
                        // NOROESTE
                        accion = actTURN_L;
                        girando_D = true;
                    } 
                    else if (visitas[current_state.fil + 1][current_state.col] == min_local) {
                        // SUR
                        accion = actTURN_L;
                        girando_I = true;
                    } 
                    else if (visitas[current_state.fil + 1][current_state.col + 1] == min_local) {
                        // SURESTE
                        accion = actTURN_SR;
                        girando_D = true;
                        girar_MAS_D = true;
                    } 
                    else if (visitas[current_state.fil + 1][current_state.col - 1] == min_local) {
                        // SUROESTE
                        accion = actTURN_L;
                        girando_I = true;
                        girar_MAS_D = true;
                    }
                break;

                case noreste:
                    remoto = true;
                    if (visitas[current_state.fil - 1][current_state.col + 1] == min_local) {
                        // NORESTE
                        accion = actWALK;
                    } 
                    else if (visitas[current_state.fil][current_state.col + 1] == min_local) {
                        // ESTE
                        accion = actTURN_SR;
                        moverse = true;
                    } 
                    else if (visitas[current_state.fil - 1][current_state.col - 1] == min_local) {
                        // NOROESTE
                        accion = actTURN_L;
                        moverse = true;
                    } 
                    else if (visitas[current_state.fil + 1][current_state.col + 1] == min_local) {
                        // SURESTE
                        accion = actTURN_SR;
                        girando_D = true;
                    } 
                    else if (visitas[current_state.fil - 1][current_state.col] == min_local) {
                        // NORTE
                        accion = actTURN_L;
                        girando_D = true;
                    } 
                    else if (visitas[current_state.fil + 1][current_state.col - 1] == min_local) {
                        // SUROESTE
                        accion = actTURN_L;
                        girando_I = true;
                    } 
                    else if (visitas[current_state.fil + 1][current_state.col] == min_local) {
                        // SUR
                        accion = actTURN_SR;
                        girando_D = true;
                        girar_MAS_D = true;
                    } 
                    else if (visitas[current_state.fil][current_state.col - 1] == min_local) {
                        // OESTE
                        accion = actTURN_L;
                        girando_I = true;
                        girar_MAS_D = true;
                    }
                break;

                case este:
                    remoto = true;
                    if (visitas[current_state.fil][current_state.col + 1] == min_local) {
                        // ESTE
                        accion = actWALK;
                    } 
                    else if (visitas[current_state.fil + 1][current_state.col + 1] == min_local) {
                        // SURESTE
                        accion = actTURN_SR;
                        moverse = true;
                    } 
                    else if (visitas[current_state.fil - 1][current_state.col] == min_local) {
                        // NORTE
                        accion = actTURN_L;
                        moverse = true;
                    } 
                    else if (visitas[current_state.fil + 1][current_state.col] == min_local) {
                        // SUR
                        accion = actTURN_SR;
                        girando_D = true;
                    } 
                    else if (visitas[current_state.fil - 1][current_state.col + 1] == min_local) {
                        // NORESTE
                        accion = actTURN_L;
                        girando_D = true;
                    } 
                    else if (visitas[current_state.fil][current_state.col - 1] == min_local) {
                        // OESTE
                        accion = actTURN_L;
                        girando_I = true;
                    } 
                    else if (visitas[current_state.fil + 1][current_state.col - 1] == min_local) {
                        // SUROESTE
                        accion = actTURN_SR;
                        girando_D = true;
                        girar_MAS_D = true;
                    } 
                    else if (visitas[current_state.fil - 1][current_state.col - 1] == min_local) {
                        // NOROESTE
                        accion = actTURN_L;
                        girando_I = true;
                        girar_MAS_D = true;
                    }
                break;

                case sureste:
                    remoto = true;
                    if (visitas[current_state.fil + 1][current_state.col + 1] == min_local) {
                        // SURESTE
                        accion = actWALK;
                    } 
                    else if (visitas[current_state.fil + 1][current_state.col] == min_local) {
                        // SUR
                        accion = actTURN_SR;
                        moverse = true;
                    } 
                    else if (visitas[current_state.fil - 1][current_state.col + 1] == min_local) {
                        // NORESTE
                        accion = actTURN_L;
                        moverse = true;
                    }
                    else if (visitas[current_state.fil + 1][current_state.col - 1] == min_local) {
                        // SUROESTE
                        accion = actTURN_SR;
                        girando_D = true;
                    } 
                    else if (visitas[current_state.fil][current_state.col + 1] == min_local) {
                        // ESTE
                        accion = actTURN_L;
                        girando_D = true;
                    } 
                    else if (visitas[current_state.fil - 1][current_state.col - 1] == min_local) {
                        // NOROESTE
                        accion = actTURN_L;
                        girando_I = true;
                    } 
                    else if (visitas[current_state.fil][current_state.col - 1] == min_local) {
                        // OESTE
                        accion = actTURN_SR;
                        girando_D = true;
                        girar_MAS_D = true;
                    } 
                    else if (visitas[current_state.fil - 1][current_state.col] == min_local) {
                        // NORTE
                        accion = actTURN_L;
                        girando_I = true;
                        girar_MAS_D = true;
                    }   
                break;

                case sur:
                    remoto = true;
                    if (visitas[current_state.fil + 1][current_state.col] == min_local) {
                        // SUR
                        accion = actWALK;
                    } 
                    else if (visitas[current_state.fil + 1][current_state.col - 1] == min_local) {
                        // SUROESTE
                        accion = actTURN_SR;
                        moverse = true;
                    } 
                    else if (visitas[current_state.fil][current_state.col + 1] == min_local) {
                        // ESTE
                        accion = actTURN_L;
                        moverse = true;
                    } 
                    else if (visitas[current_state.fil][current_state.col - 1] == min_local) {
                        // OESTE
                        accion = actTURN_SR;
                        girando_D = true;
                    } 
                    else if (visitas[current_state.fil + 1][current_state.col + 1] == min_local) {
                        // SURESTE
                        accion = actTURN_L;
                        girando_D = true;
                    } 
                    else if (visitas[current_state.fil - 1][current_state.col] == min_local) {
                        // NORTE
                        accion = actTURN_L;
                        girando_I = true;
                    } 
                    else if (visitas[current_state.fil - 1][current_state.col - 1] == min_local) {
                        // NOROESTE
                        accion = actTURN_SR;
                        girando_D = true;
                        girar_MAS_D = true;
                    } 
                    else if (visitas[current_state.fil - 1][current_state.col + 1] == min_local) {
                        // NORESTE
                        accion = actTURN_L;
                        girando_I = true;
                        girar_MAS_D = true;
                    }
                break;

                case suroeste:
                    remoto = true;
                    if (visitas[current_state.fil + 1][current_state.col - 1] == min_local) {
                        // SUROESTE
                        accion = actWALK;
                    } 
                    else if (visitas[current_state.fil][current_state.col - 1] == min_local) {
                        // OESTE
                        accion = actTURN_SR;
                        moverse = true;
                    } 
                    else if (visitas[current_state.fil + 1][current_state.col + 1] == min_local) {
                        // SURESTE
                        accion = actTURN_L;
                        moverse = true;
                    } 
                    else if (visitas[current_state.fil - 1][current_state.col - 1] == min_local) {
                        // NOROESTE
                        accion = actTURN_SR;
                        girando_D = true;
                    } 
                    else if (visitas[current_state.fil + 1][current_state.col] == min_local) {
                        // SUR
                        accion = actTURN_L;
                        girando_D = true;
                    } 
                    else if (visitas[current_state.fil - 1][current_state.col + 1] == min_local) {
                        // NORESTE
                        accion = actTURN_L;
                        girando_I = true;
                    } 
                    else if (visitas[current_state.fil - 1][current_state.col] == min_local) {
                        // NORTE
                        accion = actTURN_SR;
                        girando_D = true;
                        girar_MAS_D = true;
                    } 
                    else if (visitas[current_state.fil][current_state.col + 1] == min_local) {
                        // ESTE
                        accion = actTURN_L;
                        girando_I = true;
                        girar_MAS_D = true;
                    }
                break;

                case oeste:
                    remoto = true;
                    if (visitas[current_state.fil][current_state.col - 1] == min_local) {
                        // OESTE
                        accion = actWALK;
                    } 
                    else if (visitas[current_state.fil - 1][current_state.col - 1] == min_local) {
                        // NOROESTE
                        accion = actTURN_SR;
                        moverse = true;
                    } 
                    else if (visitas[current_state.fil + 1][current_state.col] == min_local) {
                        // SUR
                        accion = actTURN_L;
                        moverse = true;
                    } 
                    else if (visitas[current_state.fil - 1][current_state.col] == min_local) {
                        // NORTE
                        accion = actTURN_SR;
                        girando_D = true;
                    } 
                    else if (visitas[current_state.fil + 1][current_state.col - 1] == min_local) {
                        // SUROESTE
                        accion = actTURN_L;
                        girando_D = true;
                    } 
                    else if (visitas[current_state.fil][current_state.col + 1] == min_local) {
                        // ESTE
                        accion = actTURN_L;
                        girando_I = true;
                    } 
                    else if (visitas[current_state.fil - 1][current_state.col + 1] == min_local) {
                        // NORESTE
                        accion = actTURN_SR;
                        girando_D = true;
                        girar_MAS_D = true;
                    } 
                    else if (visitas[current_state.fil + 1][current_state.col + 1] == min_local) {
                        // SURESTE
                        accion = actTURN_L;
                        girando_I = true;
                        girar_MAS_D = true;
                    }
                break;

                case noroeste:
                    remoto = true;
                    if (visitas[current_state.fil - 1][current_state.col - 1] == min_local) {
                        // NOROESTE
                        accion = actWALK;
                    } 
                    else if (visitas[current_state.fil - 1][current_state.col] == min_local) {
                        // NORTE
                        accion = actTURN_SR;
                        moverse = true;
                    } 
                    else if (visitas[current_state.fil + 1][current_state.col - 1] == min_local) {
                        // SUROESTE
                        accion = actTURN_L;
                        moverse = true;
                    } 
                    else if (visitas[current_state.fil - 1][current_state.col + 1] == min_local) {
                        // NORESTE
                        accion = actTURN_SR;
                        girando_D = true;
                    } 
                    else if (visitas[current_state.fil][current_state.col - 1] == min_local) {
                        // OESTE
                        accion = actTURN_L;
                        girando_D = true;
                    } 
                    else if (visitas[current_state.fil + 1][current_state.col + 1] == min_local) {
                        // SURESTE
                        accion = actTURN_L;
                        girando_I = true;
                    } 
                    else if (visitas[current_state.fil][current_state.col + 1] == min_local) {
                        // ESTE
                        accion = actTURN_SR;
                        girando_D = true;
                        girar_MAS_D = true;
                    } 
                    else if (visitas[current_state.fil + 1][current_state.col] == min_local) {
                        // SUR
                        accion = actTURN_L;
                        girando_I = true;
                        girar_MAS_D = true;
                    }
                break;
            }
        }
    }
    return accion;
}

Action ComportamientoJugador::blindMove(Sensores sensores) {
    Action accion = actIDLE;
    if(girando_D){
        accion = actTURN_SR;
        girar_MAS_D = true;
        girando_D = false;
    }
    else if(girar_MAS_D){
        accion = actTURN_SR;
        girar_MAS_D = false;
    }
    //COMPRUEBA SI HAY ALGUN OBSTACULO
    //SI HAY UN OBSTACULO, LO RODEA

    else if(hay_obstaculo){
        if(sensores.terreno[2] == 'M'){
            accion = actTURN_L;
            hay_obstaculo = true;
        }
        else{
            accion = actWALK;
            girando_D = true;
            hay_obstaculo = false;
        }
    }
    else if(sensores.terreno[2] == 'M' && veces_en_precipicio == 0){
        accion = actTURN_L;
        hay_obstaculo = true;
    }
    //SI SE ENCUENTRA CON UN OBSTACULO QUE NO SEA UN MURO, RECORRE LA MATRIZ
    else if( girando == 2 and veces_en_precipicio%2 == 0 ){
        accion = actTURN_L;
        girando = 0;
        veces_en_precipicio++;
    }
    else if(girando == 1 and (sensores.terreno[2] == 'P' or sensores.terreno[2] == 'M') and veces_en_precipicio %2 == 0){
        accion = actTURN_L;
        girando = 0;
    }
    else if(girando == 1 and (sensores.terreno[2] == 'P' or sensores.terreno[2] == 'M') and veces_en_precipicio %2 == 1){
        accion = actTURN_SR;
        girar_MAS_D = true;
        girando = 0;
    }
    else if(girando == 1){
        accion = actWALK;
        girando = 2;
    }
    else if((sensores.terreno[2] == 'P' or sensores.terreno[2] == 'M') and veces_en_precipicio %2 == 0){
        girando = 1;
        accion = actTURN_L;
    }
    else if(girando == 2 and veces_en_precipicio%2 == 1){
        accion = actTURN_SR;
        girar_MAS_D = true;
        girando = 0;
        veces_en_precipicio++;
    }
    else if((sensores.terreno[2] == 'P' or sensores.terreno[2] == 'M') and veces_en_precipicio %2 == 1){
        girando = 1;
        accion = actTURN_SR;
        girar_MAS_D = true;
    }
    else{
        accion = actWALK;
    } 
    return accion;
}