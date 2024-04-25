#include "../Comportamientos_Jugador/jugador.hpp"
#include "motorlib/util.h"

#include <iostream>
#include <cmath>
#include <set>
#include <stack>

bool PerciboColaborador(const ubicacion jug, const vector<vector<unsigned char>> &mapa){
	bool percibido = false;

	switch (jug.brujula)
	{
		case norte:
			for(int i = 0; i < 4 and !percibido;i++){
				for(int j = 0; j < 2*i + 1 and !percibido; j++){
					if(mapa[jug.f -i][jug.c -i+j] == 'c'){
						percibido = true;
					}
				}
			}
		break;	

		case noreste:
			for(int i = 0; i < 4 and !percibido ;i++){
				for(int j = 0; j < 4 ;j++){
					if(mapa[jug.f -i][jug.c +j] == 'c'){
						percibido = true;
					}
				}
			}
		break;
			
		case este:
			for(int i = 0; i < 4 ;i++){
				for(int j = 0; j < 2*i + 1; j++){
					if(mapa[jug.f -i+j][jug.c +i] == 'c'){
						percibido = true;
					}
				}
			}
		break;

		case sureste:
			for(int i = 0; i < 4 ;i++){
				for(int j = 0; j < 4 ;j++){
					if(mapa[jug.f +i][jug.c +j] == 'c'){
						percibido = true;
					}
				}
			}
		break;

		case sur:
			for(int i = 0; i < 4 ;i++){
				for(int j = 0; j < 2*i + 1; j++){
					if(mapa[jug.f +i][jug.c +i-j] == 'c'){
						percibido = true;
					}
				}
			}
		break;

		case suroeste:
			for(int i = 0; i < 4 ;i++){
				for(int j = 0; j < 4 ;j++){
					if(mapa[jug.f +i][jug.c -j] == 'c'){
						percibido = true;
					}
				}
			}
		break;

		case oeste:
			for(int i = 0; i < 4 ;i++){
				for(int j = 0; j < 2*i + 1; j++){
					if(mapa[jug.f +i-j][jug.c -i] == 'c'){
						percibido = true;
					}
				}
			}
		break;

		case noroeste:
			for(int i = 0; i < 4 ;i++){
				for(int j = 0; j < 4 ;j++){
					if(mapa[jug.f -i][jug.c -j] == 'c'){
						percibido = true;
					}
				}
			}
		break;
	}
	
	return percibido;
}

bool CasillaTransitable(const ubicacion &x, const vector<vector<unsigned char>> &mapa){
	return (mapa[x.f][x.c] != 'P' and mapa[x.f][x.c] != 'M');
}

ubicacion NextCasilla(const ubicacion &pos){
	ubicacion next = pos;
	switch (pos.brujula)
	{
		case norte:
			next.f = pos.f-1;
		break;

		case noreste:
			next.f = pos.f-1;
			next.c = pos.c+1;
		break;

		case este:
			next.c = pos.c+1;
		break;

		case sureste:
			next.f = pos.f+1;
			next.c = pos.c+1;
		break;

		case sur:
			next.f = pos.f+1;
		break;

		case suroeste:
			next.f = pos.f+1;
			next.c = pos.c-1;
		break;

		case oeste:
			next.c = pos.c-1;
		break;

		case noroeste:
			next.f = pos.f-1;
			next.c = pos.c-1;
		break;
	}

	return next;
}
// Devuelve el estado que se genera si el agente puede avanzar
// Si no puede avanzar, devuelve como salida el mismo estado de entrada
stateN0 apply(const Action &a, const stateN0 &st, const vector<vector<unsigned char>> mapa){
	stateN0 st_result = st;
	ubicacion sig_ubicacion, sig_ubicacion2;
	switch (a)
	{
	case actWALK: //si prox casilla es transitable y no está ocupada por el colaborador
		sig_ubicacion = NextCasilla(st.jugador);
		if(CasillaTransitable(sig_ubicacion, mapa) and
		   !(sig_ubicacion.f == st.colaborador.f and sig_ubicacion.c == st.colaborador.c)){
				st_result.jugador = sig_ubicacion;
		   }
		break;
	
	case actRUN: //si prox 2 casillas son transitables y no está ocupada por el colaborador
		sig_ubicacion = NextCasilla(st.jugador);
		if(CasillaTransitable(sig_ubicacion, mapa) and
		!(sig_ubicacion.f == st.colaborador.f and sig_ubicacion.c == st.colaborador.c)){
			sig_ubicacion2 = NextCasilla(sig_ubicacion);
			if(CasillaTransitable(sig_ubicacion2, mapa) and
				!(sig_ubicacion2.f == st.colaborador.f and sig_ubicacion2.c == st.colaborador.c)){
					st_result.jugador = sig_ubicacion2;
				}
		}
		break;
	
	case actTURN_L:
		st_result.jugador.brujula = static_cast<Orientacion>((st_result.jugador.brujula+6)%8);
		break;
	
	case actTURN_SR:
		st_result.jugador.brujula = static_cast<Orientacion>((st_result.jugador.brujula+1)%8);
		break;
	}
	return st_result;	
}

stateN1 apply1(const Action &a, const stateN1 &st, const vector<vector<unsigned char>> mapa){
	stateN1 st_result = st;
	ubicacion sig_ubicacion, sig_ubicacion2;
	switch (a)
	{
	case actWALK: //si prox casilla es transitable y no está ocupada por el colaborador
		sig_ubicacion = NextCasilla(st.jugador);
		if(CasillaTransitable(sig_ubicacion, mapa) and
		   !(sig_ubicacion.f == st.colaborador.f and sig_ubicacion.c == st.colaborador.c)){
				st_result.jugador = sig_ubicacion;
		   }
		break;
	
	case actRUN: //si prox 2 casillas son transitables y no está ocupada por el colaborador
		sig_ubicacion = NextCasilla(st.jugador);
		if(CasillaTransitable(sig_ubicacion, mapa) and
		!(sig_ubicacion.f == st.colaborador.f and sig_ubicacion.c == st.colaborador.c)){
			sig_ubicacion2 = NextCasilla(sig_ubicacion);
			if(CasillaTransitable(sig_ubicacion2, mapa) and
				!(sig_ubicacion2.f == st.colaborador.f and sig_ubicacion2.c == st.colaborador.c)){
					st_result.jugador = sig_ubicacion2;
				}
		}
		break;
	
	case actTURN_L:
		st_result.jugador.brujula = static_cast<Orientacion>((st_result.jugador.brujula+6)%8);
		break;
	
	case actTURN_SR:
		st_result.jugador.brujula = static_cast<Orientacion>((st_result.jugador.brujula+1)%8);
		break;
	
	case act_CLB_WALK:
		sig_ubicacion = NextCasilla(st.colaborador);
		if(CasillaTransitable(sig_ubicacion, mapa) and 
		!(sig_ubicacion.f == st.jugador.f and sig_ubicacion.c == st.jugador.c)){
			st_result.colaborador = sig_ubicacion;
		}
		break;

	case act_CLB_TURN_SR:
		st_result.colaborador.brujula = static_cast<Orientacion>((st_result.colaborador.brujula+1)%8);
		break;
	}
	return st_result;
}
// Encuentra si el elemento item está en la lista
bool Find (const stateN0 &item, const list <stateN0> &lista){
	auto it = lista.begin();
	while (it!=lista.end() and !((*it) == item))
		it++;

	return (!(it == lista.end()));
}

// Pone a cero todos los elementos de una matriz
void AnulaMatriz(vector<vector<unsigned char>> &matriz){
	for (int i = 0; i < matriz.size(); i++)
		for(int j = 0; j < matriz[0].size(); j++)
			matriz[i][j] = 0;
}

// Permite pintar sobre el mapa del simulador el plan partiendo desde el estado st
void ComportamientoJugador::VisualizaPlan(const stateN0 &st, const list<Action> &plan){
	AnulaMatriz(mapaConPlan);
	stateN0 cst = st;

	auto it = plan.begin();
	while (it != plan.end()){
		if((*it != act_CLB_WALK) and (*it != act_CLB_TURN_SR) and (*it != act_CLB_STOP)){
			switch (cst.ultimaOrdenColaborador)
			{
			case act_CLB_WALK:
				cst.colaborador = NextCasilla(cst.colaborador);
				mapaConPlan[cst.colaborador.f][cst.colaborador.c] = 2;
				break;
			
			case act_CLB_TURN_SR:
				cst.colaborador.brujula = (Orientacion)((cst.colaborador.brujula+1)%8);
				break;
			}
		}

		switch (*it)
		{
		case actRUN:
			cst.jugador = NextCasilla(cst.jugador);
			mapaConPlan[cst.jugador.f][cst.jugador.c] = 3;
			cst.jugador = NextCasilla(cst.jugador);
			mapaConPlan[cst.jugador.f][cst.jugador.c] = 1;
			break;
		case actWALK:
			cst.jugador = NextCasilla(cst.jugador);
			mapaConPlan[cst.jugador.f][cst.jugador.c] = 1;
			break;
		case actTURN_SR:
			cst.jugador.brujula = (Orientacion)((cst.jugador.brujula+1)%8);
			break;
		case actTURN_L:
			cst.jugador.brujula = (Orientacion)((cst.jugador.brujula+6)%8);
			break;
		case act_CLB_WALK:
			cst.colaborador = NextCasilla(cst.colaborador);
			cst.ultimaOrdenColaborador = act_CLB_WALK;
			mapaConPlan[cst.jugador.f][cst.jugador.c] = 2;
			break;
		case act_CLB_TURN_SR:
			cst.colaborador.brujula = (Orientacion)((cst.colaborador.brujula+1)%8);
			cst.ultimaOrdenColaborador = act_CLB_TURN_SR;
			break;
		case act_CLB_STOP:
			cst.ultimaOrdenColaborador = act_CLB_STOP;
			break;
		}
		it++;
	}
}

void ComportamientoJugador::VisualizaPlan1(const stateN1 &st, const list<Action> &plan){
	AnulaMatriz(mapaConPlan);
	stateN1 cst = st;

	auto it = plan.begin();
	while (it != plan.end()){
		if((*it != act_CLB_WALK) and (*it != act_CLB_TURN_SR) and (*it != act_CLB_STOP)){
			switch (cst.ultimaOrdenColaborador)
			{
			case act_CLB_WALK:
				cst.colaborador = NextCasilla(cst.colaborador);
				mapaConPlan[cst.colaborador.f][cst.colaborador.c] = 2;
				break;
			
			case act_CLB_TURN_SR:
				cst.colaborador.brujula = (Orientacion)((cst.colaborador.brujula+1)%8);
				break;
			}
		}

		switch (*it)
		{
		case actRUN:
			cst.jugador = NextCasilla(cst.jugador);
			mapaConPlan[cst.jugador.f][cst.jugador.c] = 3;
			cst.jugador = NextCasilla(cst.jugador);
			mapaConPlan[cst.jugador.f][cst.jugador.c] = 1;
			break;
		case actWALK:
			cst.jugador = NextCasilla(cst.jugador);
			mapaConPlan[cst.jugador.f][cst.jugador.c] = 1;
			break;
		case actTURN_SR:
			cst.jugador.brujula = (Orientacion)((cst.jugador.brujula+1)%8);
			break;
		case actTURN_L:
			cst.jugador.brujula = (Orientacion)((cst.jugador.brujula+6)%8);
			break;
		case act_CLB_WALK:
			cst.colaborador = NextCasilla(cst.colaborador);
			cst.ultimaOrdenColaborador = act_CLB_WALK;
			mapaConPlan[cst.jugador.f][cst.jugador.c] = 2;
			break;
		case act_CLB_TURN_SR:
			cst.colaborador.brujula = (Orientacion)((cst.colaborador.brujula+1)%8);
			cst.ultimaOrdenColaborador = act_CLB_TURN_SR;
			break;
		case act_CLB_STOP:
			cst.ultimaOrdenColaborador = act_CLB_STOP;
			break;
		}
		it++;
	}
}

// Definción del tipo de nodo del nivel 0
struct nodeN0{
	stateN0 st;
	list<Action> secuencia;

	bool operator==(const nodeN0 &n) const{
		return (st==n.st);
	}

	bool operator<(const nodeN0 &b) const{
		if(st.jugador.f < b.st.jugador.f)
			return true;
		else if(st.jugador.f == b.st.jugador.f and st.jugador.c < b.st.jugador.c)
			return true;
		else if (st.jugador.f == b.st.jugador.f and st.jugador.c == b.st.jugador.c and st.jugador.brujula < b.st.jugador.brujula)
			return true;
		else
			return false;
	}
};

// Definición del tipo de nodo del nivel 1
struct nodeN1{
	stateN1 st;
	list<Action> secuencia;

	bool operator==(const nodeN1 &n) const{
		return (st==n.st);
	}

	bool operator<(const nodeN1 &b) const{
		if(st.jugador.f < b.st.jugador.f)
			return true;
		else if(st.jugador.f == b.st.jugador.f and st.jugador.c < b.st.jugador.c)
			return true;
		else if (st.jugador.f == b.st.jugador.f and st.jugador.c == b.st.jugador.c and st.jugador.brujula < b.st.jugador.brujula)
			return true;
		else
			return false;
	}
};

bool Find(const stateN0 &item, const list<nodeN0> &lista){
	auto it = lista.begin();
	while(it != lista.end() and !(it->st == item))
		it++;
	
	return (!(it == lista.end()));
}

void PintaPlan(const list<Action> &plan){
	auto it = plan.begin();
	while (it != plan.end()){
		if (*it == actWALK){
			cout << "W ";
		}
		else if (*it == actRUN){
			cout << "R ";
		}
		else if (*it == actTURN_SR){
			cout << "r ";
		}
		else if (*it == actTURN_L){
			cout << "L ";
		}
		else if (*it == act_CLB_WALK){
			cout << "cW ";
		}
		else if (*it == act_CLB_TURN_SR){
			cout << "cr ";
		}
		else if (*it == act_CLB_STOP){
			cout << "cS ";
		}
		else if (*it == actIDLE){
			cout << "I ";
		}
		else{
			cout << "-_ ";
		}
		it++;
	}
	cout << " (" << plan.size() << " acciones)\n";
}


// Version tercera de la busqueda en anchura
list<Action> AnchuraSoloJugador(const stateN0 &inicio, const ubicacion &final, const vector<vector<unsigned char>> &mapa){
	nodeN0 current_node;
	list<nodeN0> frontier;
	set<nodeN0> explored;
	list<Action> plan;
	current_node.st = inicio;
	bool SolutionFound = (current_node.st.jugador.f == final.f and 
						  current_node.st.jugador.c == final.c);
	frontier.push_back(current_node);

	while(!frontier.empty() and !SolutionFound){
		frontier.pop_front();
		explored.insert(current_node);

		//Generar hijo actWALK
		nodeN0 child_walk = current_node;
		child_walk.st = apply(actWALK, current_node.st, mapa);
		child_walk.secuencia.push_back(actWALK);
		if (child_walk.st.jugador.f == final.f and child_walk.st.jugador.c == final.c){
			current_node = child_walk;
			SolutionFound = true;
		}
		else if (explored.find(child_walk) == explored.end()){
			frontier.push_back(child_walk);
		}

		if(!SolutionFound){
			//Generar hijo actRUN
			nodeN0 child_run = current_node;
			child_run.st = apply(actRUN, current_node.st, mapa);
			child_run.secuencia.push_back(actRUN);
			if(child_run.st.jugador.f == final.f and child_run.st.jugador.c == final.c){
				current_node = child_run;
				SolutionFound = true;
			}
			else if (explored.find(child_run) == explored.end()){
				frontier.push_back(child_run);
			}
		}

		if(!SolutionFound){
			//Generar hijo actTURN_L
			nodeN0 child_turnl = current_node;
			child_turnl.st = apply(actTURN_L, current_node.st, mapa);
			child_turnl.secuencia.push_back(actTURN_L);
			if( explored.find(child_turnl) == explored.end()){
				frontier.push_back(child_turnl);
			}
			//Generar hijo actTURN_SR
			nodeN0 child_turnsr = current_node;
			child_turnsr.st = apply(actTURN_SR, current_node.st, mapa);
			child_turnsr.secuencia.push_back(actTURN_SR);
			if(explored.find(child_turnsr) == explored.end()){
				frontier.push_back(child_turnsr);
			}
		}
		if(!SolutionFound and !frontier.empty()){
			current_node = frontier.front();
			while (!frontier.empty() and explored.find(current_node) != explored.end()){
				frontier.pop_front();
				if(!frontier.empty()){
					current_node = frontier.front();
				}
			}
		}
	}

	if(SolutionFound){
		plan = current_node.secuencia;
		cout << "Encontrado un plan: ";
		PintaPlan(current_node.secuencia);
	}

	return plan;
}

list<Action> AnchuraSoloColaborador(const stateN1 &inicio, const ubicacion &final, const vector<vector<unsigned char>> &mapa){
	nodeN1 current_node;
	list<nodeN1> frontier;
	set<nodeN1> explored;
	list<Action> plan;
	bool percibido = false;
	current_node.st = inicio;
	bool SolutionFound = (current_node.st.colaborador.f == final.f and 
						  current_node.st.colaborador.c == final.c);
	frontier.push_back(current_node);

	while(!frontier.empty() and !SolutionFound){
		frontier.pop_front();
		explored.insert(current_node);

		//Generar hijo act_CLB_WALK
		percibido = PerciboColaborador(current_node.st.jugador, mapa);

		if(percibido){
			nodeN1 child_CLBwalk = current_node;
			child_CLBwalk.st = apply1(act_CLB_WALK, current_node.st, mapa);
			child_CLBwalk.secuencia.push_back(act_CLB_WALK);
			if (child_CLBwalk.st.colaborador.f == final.f and child_CLBwalk.st.colaborador.c == final.c){
				current_node = child_CLBwalk;
				SolutionFound = true;
			}
			else if (explored.find(child_CLBwalk) == explored.end()){
				child_CLBwalk.secuencia.push_back(act_CLB_WALK);
				frontier.push_back(child_CLBwalk);
			}
		}

		if(!SolutionFound){
			//Generar hijo actWALK
			nodeN1 child_walk = current_node;
			child_walk.st = apply1(actWALK, current_node.st, mapa);
			child_walk.secuencia.push_back(actWALK);
			if (child_walk.st.jugador.f == final.f and child_walk.st.jugador.c == final.c){
				current_node = child_walk;
				SolutionFound = true;
			}
			else if (explored.find(child_walk) == explored.end()){
				frontier.push_back(child_walk);
			}
		}

		if(!SolutionFound){
			//Generar hijo actRUN
			nodeN1 child_run = current_node;
			child_run.st = apply1(actRUN, current_node.st, mapa);
			child_run.secuencia.push_back(actRUN);
			if(child_run.st.jugador.f == final.f and child_run.st.jugador.c == final.c){
				current_node = child_run;
				SolutionFound = true;
			}
			else if (explored.find(child_run) == explored.end()){
				frontier.push_back(child_run);
			}
		}

		if(!SolutionFound){
			//Generar hijo actTURN_L
			nodeN1 child_turnl = current_node;
			child_turnl.st = apply1(actTURN_L, current_node.st, mapa);
			child_turnl.secuencia.push_back(actTURN_L);
			if( explored.find(child_turnl) == explored.end()){
				frontier.push_back(child_turnl);
			}
			//Generar hijo actTURN_SR
			nodeN1 child_turnsr = current_node;
			child_turnsr.st = apply1(actTURN_SR, current_node.st, mapa);
			child_turnsr.secuencia.push_back(actTURN_SR);
			if(explored.find(child_turnsr) == explored.end()){
				frontier.push_back(child_turnsr);
			}
		}

		if(percibido){
			//Generar hijo act_CLB_TURN_SR
			nodeN1 child_turnsr = current_node;
			child_turnsr.st = apply1(act_CLB_TURN_SR, current_node.st, mapa);
			child_turnsr.secuencia.push_back(act_CLB_TURN_SR);
			if(explored.find(child_turnsr) == explored.end()){
				frontier.push_back(child_turnsr);
			}
		}

		if(!SolutionFound and !frontier.empty()){
			current_node = frontier.front();
			while (!frontier.empty() and explored.find(current_node) != explored.end()){
				frontier.pop_front();
				if(!frontier.empty()){
					current_node = frontier.front();
				}
			}
		}
	}

	if(SolutionFound){
		plan = current_node.secuencia;
		cout << "Encontrado un plan: ";
		PintaPlan(current_node.secuencia);
	}

	return plan;
}

// Este es el método principal que se piden en la practica.
// Tiene como entrada la información de los sensores y devuelve la acción a realizar.
// Para ver los distintos sensores mirar fichero "comportamiento.hpp"
Action ComportamientoJugador::think(Sensores sensores)
{
	Action accion = actIDLE;
	if (sensores.nivel != 4){
		if(!hayPlan)
		{
			cout << "Calculamos un nuevo plan\n";
			c_state.jugador.f = sensores.posF;
			c_state.jugador.c = sensores.posC;
			c_state.jugador.brujula = sensores.sentido;
			c_state.colaborador.f = sensores.CLBposF;
			c_state.colaborador.c = sensores.CLBposC;
			c_state.colaborador.brujula = sensores.CLBsentido;

			c_state1.jugador.f = sensores.posF;
			c_state1.jugador.c = sensores.posC;
			c_state1.jugador.brujula = sensores.sentido;
			c_state1.colaborador.f = sensores.CLBposF;
			c_state1.colaborador.c = sensores.CLBposC;
			c_state1.colaborador.brujula = sensores.CLBsentido;

			goal.f = sensores.destinoF; 
			goal.c = sensores.destinoC;
			goalGetToCLB.f = sensores.CLBposF;
			goalGetToCLB.c = sensores.CLBposC;
			switch (sensores.nivel){
				case 0: 
					plan = AnchuraSoloJugador(c_state, goal, mapaResultado);
					break;
				case 1: // Incluir aqui la llamada a alg. busqueda del nivel 1
					plan = AnchuraSoloColaborador(c_state1, goal, mapaResultado);
					cout << "Pendiente de implementar el nivel 1\n";
					break;
				case 2: // Incluir aqui la llamada a alg. busqueda del nivel 2
					cout << "Pendiente de implementar el nivel 2\n";
					break;
				case 3: // Incluir aqui la llamada a alg. busqueda del nivel 3
					cout << "Pendiente de implementar el nivel 3\n";
					break;
			}
			if (plan.size() > 0){
				VisualizaPlan(c_state, plan);
				hayPlan = true;
			}
		}
		if (hayPlan and plan.size() > 0){
			accion = plan.front();
			plan.pop_front();
		}
		if (plan.size() == 0){
			cout << "Se completo el plan\n";
			hayPlan = false;
		}
	}
	else{
		// Incluir aqui la solucion del nivel 4
	}
	return accion;
}

int ComportamientoJugador::interact(Action accion, int valor)
{
	return false;
}
