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

    //COMPROBAR SI SE PUEDE EMPEZAR A UTILIZAR LA VISION
	if(!bien_situado and orientado){
        cout << "SITUADO" << endl;
        current_state.fil = sensores.posF;
		current_state.col = sensores.posC;
        current_state.brujula = sensores.sentido;		
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
                else if(i < 3 or j < 3 or i > n_casillas-3 or j > n_casillas-3){
                    visitas[i][j] = 3000;
                }
			}
		}
		time++;
		visitas[current_state.fil][current_state.col] = time;
		
		
		//MOSTRAR CASILLAS VISITADAS POR PANTALLA
		
		for(int i = 0; i < n_casillas; i++){
			for(int j = 0; j < n_casillas; j++){
				cout << visitas[i][j] << " ";
			}
			cout << endl;
		}
        
	}
	
	
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
                    if(sensores.terreno[0] == 'G'){
                        orientado = true;
                    }
                    else{
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

                            //IDEA: INTENTAR QUE UNA VEZ QUE ESQUIVE EL OBSTACULO, NO VUELVA A PASAR POR AHI (GIRANDO O ALGO)
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
                            /*
                            // SI EL AGENTE NO TIENE NADA DELANTE AVANZA
                            else if ( sensores.terreno[2] != 'P' and sensores.terreno[2] != 'M'  and sensores.agentes[2] == '_' ){
                                accion = actWALK;
                            }
                            */
                        
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
                    }   
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
                    if(sensores.terreno[0] == 'G'){
                        orientado = true;
                    }
                    else{
                        if (( sensores.terreno[2] == 'T' or sensores.terreno[2] == 'S' or sensores.terreno[2] == 'G' or sensores.terreno[2] == 'A' or sensores.terreno[2] == 'B') and sensores.agentes[2] == '_' ){
                            accion = actWALK;
                        }
                        else if( !girar_derecha ){
                            accion = actTURN_L;
                            girar_derecha = (rand()%5 == 0);
                        }
                        else{
                            accion = actTURN_SR;
                            girar_derecha = (rand()%2 == 0);
                        }
                    }
                }
                else if(sensores.agentes[2] != '_'){
                        if(!girar_derecha){
                            accion = actTURN_L;
                            girar_derecha = (rand()%5 == 0);
                        }
                        else{
                            accion = actTURN_SR;
                            girar_derecha = (rand()%2 == 0);
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
                if(sensores.reset){
                    bien_situado = false;
                    orientado = false;
                    tengo_bikini = false;
                    tengo_zapatillas = false;
                }
                if(!orientado){
                    if(sensores.terreno[0] == 'G'){
                        orientado = true;
                    }
                    else{
                        if (( sensores.terreno[2] == 'T' or sensores.terreno[2] == 'S' or sensores.terreno[2] == 'G' or sensores.terreno[2] == 'A' or sensores.terreno[2] == 'B') and sensores.agentes[2] == '_' ){
                            accion = actWALK;
                        }
                        else if( !girar_derecha ){
                            accion = actTURN_L;
                            girar_derecha = (rand()%5 == 0);
                        }
                        else{
                            accion = actTURN_SR;
                            girar_derecha = (rand()%2 == 0);
                        }
                    }
                }
                else if(sensores.agentes[2] != '_'){
                        if(!girar_derecha){
                            accion = actTURN_L;
                            girar_derecha = (rand()%5 == 0);
                        }
                        else{
                            accion = actTURN_SR;
                            girar_derecha = (rand()%2 == 0);
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
        min = 3000;
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                if (visitas[current_state.fil + i][current_state.col + j] < min and !(i == 0 and j == 0)) {
                    min = visitas[current_state.fil + i][current_state.col + j];
                }
            }
        }

        switch (current_state.brujula) {
            case norte:
                if (visitas[current_state.fil - 1][current_state.col] == min) {
                    // NORTE
                    accion = actWALK;
                } 
                else if (visitas[current_state.fil - 1][current_state.col + 1] == min) {
                    // NORESTE
                    accion = actTURN_SR;
                    moverse = true;
                } 
                else if (visitas[current_state.fil][current_state.col - 1] == min) {
                    // OESTE
                    accion = actTURN_L;
                    moverse = true;
                } 
                else if (visitas[current_state.fil][current_state.col + 1] == min) {
                    // ESTE
                    accion = actTURN_SR;
                    girando_D = true;
                } 
                else if (visitas[current_state.fil - 1][current_state.col - 1] == min) {
                    // NOROESTE
                    accion = actTURN_L;
                    girando_D = true;
                } 
                else if (visitas[current_state.fil + 1][current_state.col] == min) {
                    // SUR
                    accion = actTURN_L;
                    girando_I = true;
                } 
                else if (visitas[current_state.fil + 1][current_state.col + 1] == min) {
                    // SURESTE
                    accion = actTURN_SR;
                    girando_D = true;
                    girar_MAS_D = true;
                } 
                else if (visitas[current_state.fil + 1][current_state.col - 1] == min) {
                    // SUROESTE
                    accion = actTURN_L;
                    girando_I = true;
                    girar_MAS_D = true;
                }
            break;

            case noreste:
                if (visitas[current_state.fil - 1][current_state.col + 1] == min) {
                    // NORESTE
                    accion = actWALK;
                } 
                else if (visitas[current_state.fil][current_state.col + 1] == min) {
                    // ESTE
                    accion = actTURN_SR;
                    moverse = true;
                } 
                else if (visitas[current_state.fil - 1][current_state.col - 1] == min) {
                    // NOROESTE
                    accion = actTURN_L;
                    moverse = true;
                } 
                else if (visitas[current_state.fil + 1][current_state.col + 1] == min) {
                    // SURESTE
                    accion = actTURN_SR;
                    girando_D = true;
                } 
                else if (visitas[current_state.fil - 1][current_state.col] == min) {
                    // NORTE
                    accion = actTURN_L;
                    girando_D = true;
                } 
                else if (visitas[current_state.fil + 1][current_state.col - 1] == min) {
                    // SUROESTE
                    accion = actTURN_L;
                    girando_I = true;
                } 
                else if (visitas[current_state.fil + 1][current_state.col] == min) {
                    // SUR
                    accion = actTURN_SR;
                    girando_D = true;
                    girar_MAS_D = true;
                } 
                else if (visitas[current_state.fil][current_state.col - 1] == min) {
                    // OESTE
                    accion = actTURN_L;
                    girando_I = true;
                    girar_MAS_D = true;
                }
            break;

            case este:
                if (visitas[current_state.fil][current_state.col + 1] == min) {
                    // ESTE
                    accion = actWALK;
                } 
                else if (visitas[current_state.fil + 1][current_state.col + 1] == min) {
                    // SURESTE
                    accion = actTURN_SR;
                    moverse = true;
                } 
                else if (visitas[current_state.fil - 1][current_state.col] == min) {
                    // NORTE
                    accion = actTURN_L;
                    moverse = true;
                } 
                else if (visitas[current_state.fil + 1][current_state.col] == min) {
                    // SUR
                    accion = actTURN_SR;
                    girando_D = true;
                } 
                else if (visitas[current_state.fil - 1][current_state.col + 1] == min) {
                    // NORESTE
                    accion = actTURN_L;
                    girando_D = true;
                } 
                else if (visitas[current_state.fil][current_state.col - 1] == min) {
                    // OESTE
                    accion = actTURN_L;
                    girando_I = true;
                } 
                else if (visitas[current_state.fil + 1][current_state.col - 1] == min) {
                    // SUROESTE
                    accion = actTURN_SR;
                    girando_D = true;
                    girar_MAS_D = true;
                } 
                else if (visitas[current_state.fil - 1][current_state.col - 1] == min) {
                    // NOROESTE
                    accion = actTURN_L;
                    girando_I = true;
                    girar_MAS_D = true;
                }
            break;

            case sureste:
                if (visitas[current_state.fil + 1][current_state.col + 1] == min) {
                    // SURESTE
                    accion = actWALK;
                } 
                else if (visitas[current_state.fil + 1][current_state.col] == min) {
                    // SUR
                    accion = actTURN_SR;
                    moverse = true;
                } 
                else if (visitas[current_state.fil - 1][current_state.col + 1] == min) {
                    // NORESTE
                    accion = actTURN_L;
                    moverse = true;
                }
                else if (visitas[current_state.fil + 1][current_state.col - 1] == min) {
                    // SUROESTE
                    accion = actTURN_SR;
                    girando_D = true;
                } 
                else if (visitas[current_state.fil][current_state.col + 1] == min) {
                    // ESTE
                    accion = actTURN_L;
                    girando_D = true;
                } 
                else if (visitas[current_state.fil - 1][current_state.col - 1] == min) {
                    // NOROESTE
                    accion = actTURN_L;
                    girando_I = true;
                } 
                else if (visitas[current_state.fil][current_state.col - 1] == min) {
                    // OESTE
                    accion = actTURN_SR;
                    girando_D = true;
                    girar_MAS_D = true;
                } 
                else if (visitas[current_state.fil - 1][current_state.col] == min) {
                    // NORTE
                    accion = actTURN_L;
                    girando_I = true;
                    girar_MAS_D = true;
                }   
            break;

            case sur:
                if (visitas[current_state.fil + 1][current_state.col] == min) {
                    // SUR
                    accion = actWALK;
                } 
                else if (visitas[current_state.fil + 1][current_state.col - 1] == min) {
                    // SUROESTE
                    accion = actTURN_SR;
                    moverse = true;
                } 
                else if (visitas[current_state.fil][current_state.col + 1] == min) {
                    // ESTE
                    accion = actTURN_L;
                    moverse = true;
                } 
                else if (visitas[current_state.fil][current_state.col - 1] == min) {
                    // OESTE
                    accion = actTURN_SR;
                    girando_D = true;
                } 
                else if (visitas[current_state.fil + 1][current_state.col + 1] == min) {
                    // SURESTE
                    accion = actTURN_L;
                    girando_D = true;
                } 
                else if (visitas[current_state.fil - 1][current_state.col] == min) {
                    // NORTE
                    accion = actTURN_L;
                    girando_I = true;
                } 
                else if (visitas[current_state.fil - 1][current_state.col - 1] == min) {
                    // NOROESTE
                    accion = actTURN_SR;
                    girando_D = true;
                    girar_MAS_D = true;
                } 
                else if (visitas[current_state.fil - 1][current_state.col + 1] == min) {
                    // NORESTE
                    accion = actTURN_L;
                    girando_I = true;
                    girar_MAS_D = true;
                }
            break;

            case suroeste:
                if (visitas[current_state.fil + 1][current_state.col - 1] == min) {
                    // SUROESTE
                    accion = actWALK;
                } 
                else if (visitas[current_state.fil][current_state.col - 1] == min) {
                    // OESTE
                    accion = actTURN_SR;
                    moverse = true;
                } 
                else if (visitas[current_state.fil + 1][current_state.col + 1] == min) {
                    // SURESTE
                    accion = actTURN_L;
                    moverse = true;
                } 
                else if (visitas[current_state.fil - 1][current_state.col - 1] == min) {
                    // NOROESTE
                    accion = actTURN_SR;
                    girando_D = true;
                } 
                else if (visitas[current_state.fil + 1][current_state.col] == min) {
                    // SUR
                    accion = actTURN_L;
                    girando_D = true;
                } 
                else if (visitas[current_state.fil - 1][current_state.col + 1] == min) {
                    // NORESTE
                    accion = actTURN_L;
                    girando_I = true;
                } 
                else if (visitas[current_state.fil - 1][current_state.col] == min) {
                    // NORTE
                    accion = actTURN_SR;
                    girando_D = true;
                    girar_MAS_D = true;
                } 
                else if (visitas[current_state.fil][current_state.col + 1] == min) {
                    // ESTE
                    accion = actTURN_L;
                    girando_I = true;
                    girar_MAS_D = true;
                }
            break;

            case oeste:
                if (visitas[current_state.fil][current_state.col - 1] == min) {
                    // OESTE
                    accion = actWALK;
                } 
                else if (visitas[current_state.fil - 1][current_state.col - 1] == min) {
                    // NOROESTE
                    accion = actTURN_SR;
                    moverse = true;
                } 
                else if (visitas[current_state.fil + 1][current_state.col] == min) {
                    // SUR
                    accion = actTURN_L;
                    moverse = true;
                } 
                else if (visitas[current_state.fil - 1][current_state.col] == min) {
                    // NORTE
                    accion = actTURN_SR;
                    girando_D = true;
                } 
                else if (visitas[current_state.fil + 1][current_state.col - 1] == min) {
                    // SUROESTE
                    accion = actTURN_L;
                    girando_D = true;
                } 
                else if (visitas[current_state.fil][current_state.col + 1] == min) {
                    // ESTE
                    accion = actTURN_L;
                    girando_I = true;
                } 
                else if (visitas[current_state.fil - 1][current_state.col + 1] == min) {
                    // NORESTE
                    accion = actTURN_SR;
                    girando_D = true;
                    girar_MAS_D = true;
                } 
                else if (visitas[current_state.fil + 1][current_state.col + 1] == min) {
                    // SURESTE
                    accion = actTURN_L;
                    girando_I = true;
                    girar_MAS_D = true;
                }
            break;

            case noroeste:
                if (visitas[current_state.fil - 1][current_state.col - 1] == min) {
                    // NOROESTE
                    accion = actWALK;
                } 
                else if (visitas[current_state.fil - 1][current_state.col] == min) {
                    // NORTE
                    accion = actTURN_SR;
                    moverse = true;
                } 
                else if (visitas[current_state.fil + 1][current_state.col - 1] == min) {
                    // SUROESTE
                    accion = actTURN_L;
                    moverse = true;
                } 
                else if (visitas[current_state.fil - 1][current_state.col + 1] == min) {
                    // NORESTE
                    accion = actTURN_SR;
                    girando_D = true;
                } 
                else if (visitas[current_state.fil][current_state.col - 1] == min) {
                    // OESTE
                    accion = actTURN_L;
                    girando_D = true;
                } 
                else if (visitas[current_state.fil + 1][current_state.col + 1] == min) {
                    // SURESTE
                    accion = actTURN_L;
                    girando_I = true;
                } 
                else if (visitas[current_state.fil][current_state.col + 1] == min) {
                    // ESTE
                    accion = actTURN_SR;
                    girando_D = true;
                    girar_MAS_D = true;
                } 
                else if (visitas[current_state.fil + 1][current_state.col] == min) {
                    // SUR
                    accion = actTURN_L;
                    girando_I = true;
                    girar_MAS_D = true;
                }
            break;
        }
    }
    return accion;
}
