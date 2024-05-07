#include "../Comportamientos_Jugador/jugador.hpp"
#include "motorlib/util.h"

#include <iostream>
#include <cmath>
#include <set>
#include <stack>
#include <queue>

bool PerciboColaborador(stateN1 st){
	bool percibido = false;
	switch(st.jugador.brujula){
		case norte:
			for(int i = 0; i < 4 ;i++){
				for(int j = 0; j < 2*i + 1 ; j++){
					if(st.jugador.f - i == st.colaborador.f and st.jugador.c - i + j == st.colaborador.c){
						//cout << "COLABORADOR PERCIBIDO EN " << st.jugador.f-i << " , " << st.jugador.c-i+j << endl;
						percibido = true;
					}
				}
			}
		break;

		case noreste:
			for(int i = 0; i < 4  ;i++){
				for(int j = 0; j < 4 ;j++){
					if(st.jugador.f - i == st.colaborador.f and st.jugador.c + j == st.colaborador.c){
						//cout << "COLABORADOR PERCIBIDO EN " << st.jugador.f-i << " , " << st.jugador.c+j << endl;
						percibido = true;
					}
				}
			}
		break;

		case sur:
			for(int i = 0; i < 4 ;i++){
				for(int j = 0; j < 2*i + 1 ; j++){
					if(st.jugador.f + i == st.colaborador.f and st.jugador.c + i - j == st.colaborador.c){
						//cout << "COLABORADOR PERCIBIDO EN " << st.jugador.f+i << " , " << st.jugador.c+i-j << endl;
						percibido = true;
					}
				}
			}
		break;

		case sureste:
			for(int i = 0; i < 4 ;i++){
				for(int j = 0; j < 4 ;j++){
					if(st.jugador.f + i == st.colaborador.f and st.jugador.c + j == st.colaborador.c){
						//cout << "COLABORADOR PERCIBIDO EN " << st.jugador.f+i << " , " << st.jugador.c+j << endl;
						percibido = true;
					}
				}
			}
		break;

		case este:
			for(int i = 0; i < 4 ;i++){
				for(int j = 0; j < 2*i + 1 ; j++){
					if(st.jugador.f - i + j == st.colaborador.f and st.jugador.c + i == st.colaborador.c){
						//cout << "COLABORADOR PERCIBIDO EN " << st.jugador.f-i+j << " , " << st.jugador.c+i << endl;
						percibido = true;
					}
				}
			}
		break;

		case noroeste:
			for(int i = 0; i < 4 ;i++){
				for(int j = 0; j < 4 ;j++){
					if(st.jugador.f - i == st.colaborador.f and st.jugador.c - j == st.colaborador.c){
						//cout << "COLABORADOR PERCIBIDO EN " << st.jugador.f-i << " , " << st.jugador.c-j << endl;
						percibido = true;
					}
				}
			}
		break;

		case oeste:
			for(int i = 0; i < 4 ;i++){
				for(int j = 0; j < 2*i + 1 ; j++){
					if(st.jugador.f + i - j == st.colaborador.f and st.jugador.c - i == st.colaborador.c){
						//cout << "COLABORADOR PERCIBIDO EN " << st.jugador.f+i-j << " , " << st.jugador.c-i << endl;
						percibido = true;
					}
				}
			}
		break;

		case suroeste:
			for(int i = 0; i < 4 ;i++){
				for(int j = 0; j < 4 ;j++){
					if(st.jugador.f + i == st.colaborador.f and st.jugador.c - j == st.colaborador.c){
						//cout << "COLABORADOR PERCIBIDO EN " << st.jugador.f+i << " , " << st.jugador.c-j << endl;
						percibido = true;
					}
				}
			}
		break;
	}

	return percibido;
}

bool PerciboColaborador(stateN3 st){
	bool percibido = false;
	switch(st.jugador.brujula){
		case norte:
			for(int i = 0; i < 4 ;i++){
				for(int j = 0; j < 2*i + 1 ; j++){
					if(st.jugador.f - i == st.colaborador.f and st.jugador.c - i + j == st.colaborador.c){
						//cout << "COLABORADOR PERCIBIDO EN " << st.jugador.f-i << " , " << st.jugador.c-i+j << endl;
						percibido = true;
					}
				}
			}
		break;

		case noreste:
			for(int i = 0; i < 4  ;i++){
				for(int j = 0; j < 4 ;j++){
					if(st.jugador.f - i == st.colaborador.f and st.jugador.c + j == st.colaborador.c){
						//cout << "COLABORADOR PERCIBIDO EN " << st.jugador.f-i << " , " << st.jugador.c+j << endl;
						percibido = true;
					}
				}
			}
		break;

		case sur:
			for(int i = 0; i < 4 ;i++){
				for(int j = 0; j < 2*i + 1 ; j++){
					if(st.jugador.f + i == st.colaborador.f and st.jugador.c + i - j == st.colaborador.c){
						//cout << "COLABORADOR PERCIBIDO EN " << st.jugador.f+i << " , " << st.jugador.c+i-j << endl;
						percibido = true;
					}
				}
			}
		break;

		case sureste:
			for(int i = 0; i < 4 ;i++){
				for(int j = 0; j < 4 ;j++){
					if(st.jugador.f + i == st.colaborador.f and st.jugador.c + j == st.colaborador.c){
						//cout << "COLABORADOR PERCIBIDO EN " << st.jugador.f+i << " , " << st.jugador.c+j << endl;
						percibido = true;
					}
				}
			}
		break;

		case este:
			for(int i = 0; i < 4 ;i++){
				for(int j = 0; j < 2*i + 1 ; j++){
					if(st.jugador.f - i + j == st.colaborador.f and st.jugador.c + i == st.colaborador.c){
						//cout << "COLABORADOR PERCIBIDO EN " << st.jugador.f-i+j << " , " << st.jugador.c+i << endl;
						percibido = true;
					}
				}
			}
		break;

		case noroeste:
			for(int i = 0; i < 4 ;i++){
				for(int j = 0; j < 4 ;j++){
					if(st.jugador.f - i == st.colaborador.f and st.jugador.c - j == st.colaborador.c){
						//cout << "COLABORADOR PERCIBIDO EN " << st.jugador.f-i << " , " << st.jugador.c-j << endl;
						percibido = true;
					}
				}
			}
		break;

		case oeste:
			for(int i = 0; i < 4 ;i++){
				for(int j = 0; j < 2*i + 1 ; j++){
					if(st.jugador.f + i - j == st.colaborador.f and st.jugador.c - i == st.colaborador.c){
						//cout << "COLABORADOR PERCIBIDO EN " << st.jugador.f+i-j << " , " << st.jugador.c-i << endl;
						percibido = true;
					}
				}
			}
		break;

		case suroeste:
			for(int i = 0; i < 4 ;i++){
				for(int j = 0; j < 4 ;j++){
					if(st.jugador.f + i == st.colaborador.f and st.jugador.c - j == st.colaborador.c){
						//cout << "COLABORADOR PERCIBIDO EN " << st.jugador.f+i << " , " << st.jugador.c-j << endl;
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
stateN0 apply(const Action &a, const stateN0 &st, const vector<vector<unsigned char>> &mapa){
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

stateN1 apply1(const Action &a, const stateN1 &st, const vector<vector<unsigned char>> &mapa){
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
	
	case act_CLB_STOP:
		break;
	}
	
	return st_result;
}

stateN2 apply2(const Action &a, const stateN2 &st, const vector<vector<unsigned char>> &mapa){
	stateN2 st_result = st;
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

stateN3 apply3(const Action &a, const stateN3 &st, const vector<vector<unsigned char>> &mapa){
	stateN3 st_result = st;
	ubicacion sig_ubicacion, sig_ubicacion2;
	switch (a) {
		case actWALK: //si prox casilla es transitable y no está ocupada por el colaborador
			sig_ubicacion = NextCasilla(st.jugador);
			if(CasillaTransitable(sig_ubicacion, mapa) and !(sig_ubicacion.f == st.colaborador.f and sig_ubicacion.c == st.colaborador.c)){
				st_result.jugador = sig_ubicacion;
			}
		break;
		
		case actRUN: //si prox 2 casillas son transitables y no está ocupada por el colaborador
			sig_ubicacion = NextCasilla(st.jugador);
			if(CasillaTransitable(sig_ubicacion, mapa) and
			!(sig_ubicacion.f == st.colaborador.f and sig_ubicacion.c == st.colaborador.c)){
				sig_ubicacion2 = NextCasilla(sig_ubicacion);
				if(CasillaTransitable(sig_ubicacion2, mapa) and !(sig_ubicacion2.f == st.colaborador.f and sig_ubicacion2.c == st.colaborador.c)){
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
		
		case act_CLB_STOP:
		break;
		
		return st_result;
	}
}

int CosteAccion(stateN2 st, Action accion, const vector<vector<unsigned char>> &mapa){
	int coste = 0;

	switch(accion){
		case actWALK:
			if(mapa[st.jugador.f][st.jugador.c] == 'A'){
				if(st.bikini){
					coste = 10;
				}
				else{
					coste = 100;
				}
			}
			else if(mapa[st.jugador.f][st.jugador.c] == 'B'){
				if(st.zapatillas){
					coste = 15;
				}
				else{
					coste = 50;
				}
			}
			else if(mapa[st.jugador.f][st.jugador.c] == 'T'){
				coste = 2;
			}
			else
				coste = 1;
		break;

		case actRUN:
			if(mapa[st.jugador.f][st.jugador.c] == 'A'){
				if(st.bikini){
					coste = 15;
				}
				else{
					coste = 150;
				}
			}
			else if(mapa[st.jugador.f][st.jugador.c] == 'B'){
				if(st.zapatillas){
					coste = 25;
				}
				else{
					coste = 75;
				}
			}
			else if(mapa[st.jugador.f][st.jugador.c] == 'T'){
				coste = 3;
			}
			else
				coste = 1;
		break;

		case actTURN_L:
			if(mapa[st.jugador.f][st.jugador.c] == 'A'){
				if(st.bikini){
					coste = 5;
				}
				else{
					coste = 30;
				}
			}
			else if(mapa[st.jugador.f][st.jugador.c] == 'B'){
				if(st.zapatillas){
					coste = 1;
				}
				else{
					coste = 7;
				}
			}
			else if(mapa[st.jugador.f][st.jugador.c] == 'T'){
				coste = 2;
			}
			else
				coste = 1;
		break;

		case actTURN_SR:
			if(mapa[st.jugador.f][st.jugador.c] == 'A'){
				if(st.bikini){
					coste = 2;
				}
				else{
					coste = 10;
				}
			}
			else if(mapa[st.jugador.f][st.jugador.c] == 'B'){
				if(st.zapatillas){
					coste = 1;
				}
				else{
					coste = 5;
				}
			}
			else if(mapa[st.jugador.f][st.jugador.c] == 'T'){
				coste = 1;
			}
			else
				coste = 1;
		break;
	}
	return coste;
}

int CosteAccion(stateN3 st, Action accion, const vector<vector<unsigned char>> &mapa){
	int coste = 0;

	switch(accion){
		case actWALK:
			if(mapa[st.jugador.f][st.jugador.c] == 'A'){
				if(st.bikini){
					coste = 10;
				}
				else{
					coste = 100;
				}
			}
			else if(mapa[st.jugador.f][st.jugador.c] == 'B'){
				if(st.zapatillas){
					coste = 15;
				}
				else{
					coste = 50;
				}
			}
			else if(mapa[st.jugador.f][st.jugador.c] == 'T'){
				coste = 2;
			}
			else
				coste = 1;
		break;

		case actRUN:
			if(mapa[st.jugador.f][st.jugador.c] == 'A'){
				if(st.bikini){
					coste = 15;
				}
				else{
					coste = 150;
				}
			}
			else if(mapa[st.jugador.f][st.jugador.c] == 'B'){
				if(st.zapatillas){
					coste = 25;
				}
				else{
					coste = 75;
				}
			}
			else if(mapa[st.jugador.f][st.jugador.c] == 'T'){
				coste = 3;
			}
			else
				coste = 1;
		break;

		case actTURN_L:
			if(mapa[st.jugador.f][st.jugador.c] == 'A'){
				if(st.bikini){
					coste = 5;
				}
				else{
					coste = 30;
				}
			}
			else if(mapa[st.jugador.f][st.jugador.c] == 'B'){
				if(st.zapatillas){
					coste = 1;
				}
				else{
					coste = 7;
				}
			}
			else if(mapa[st.jugador.f][st.jugador.c] == 'T'){
				coste = 2;
			}
			else
				coste = 1;
		break;

		case actTURN_SR:
			if(mapa[st.jugador.f][st.jugador.c] == 'A'){
				if(st.bikini){
					coste = 2;
				}
				else{
					coste = 10;
				}
			}
			else if(mapa[st.jugador.f][st.jugador.c] == 'B'){
				if(st.zapatillas){
					coste = 1;
				}
				else{
					coste = 5;
				}
			}
			else if(mapa[st.jugador.f][st.jugador.c] == 'T'){
				coste = 1;
			}
			else
				coste = 1;
		break;

		case act_CLB_WALK:
			if(mapa[st.colaborador.f][st.colaborador.c] == 'A'){
				if(st.bikini){
					coste = 10;
				}
				else{
					coste = 100;
				}
			}
			else if(mapa[st.colaborador.f][st.colaborador.c] == 'B'){
				if(st.zapatillas){
					coste = 15;
				}
				else{
					coste = 50;
				}
			}
			else if(mapa[st.colaborador.f][st.colaborador.c] == 'T'){
				coste = 2;
			}
			else
				coste = 1;
		break;

		case act_CLB_TURN_SR:
			if(mapa[st.colaborador.f][st.colaborador.c] == 'A'){
				if(st.bikini){
					coste = 2;
				}
				else{
					coste = 10;
				}
			}
			else if(mapa[st.colaborador.f][st.colaborador.c] == 'B'){
				if(st.zapatillas){
					coste = 1;
				}
				else{
					coste = 5;
				}
			}
			else if(mapa[st.colaborador.f][st.colaborador.c] == 'T'){
				coste = 1;
			}
			else
				coste = 1;
		break;
	}
	return coste;
}

int Distancias(const stateN3 &origen, const ubicacion &destino){
	int df = abs(origen.jugador.f - destino.f);
	int dc = abs(origen.jugador.c - destino.c);
	return max(df, dc);
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

void PintaEstado (const stateN1 &x){
	cout << "(" << x.jugador.f << ", " << x.jugador.c << ", " << x.jugador.brujula << ") ";
	cout << "(" << x.colaborador.f << ", " << x.colaborador.c << ", " << x.colaborador.brujula << ") ";
	cout << x.ultimaOrdenColaborador << endl;
}

void PintaEstado (const stateN2 &x){
	cout << "(" << x.jugador.f << ", " << x.jugador.c << ", " << x.jugador.brujula << ") ";
	cout << "(" << x.colaborador.f << ", " << x.colaborador.c << ", " << x.colaborador.brujula << ") ";
	cout << x.ultimaOrdenColaborador << endl;
}

void PintaEstado (const stateN3 &x){
	cout << "(" << x.jugador.f << ", " << x.jugador.c << ", " << x.jugador.brujula << ") ";
	cout << "(" << x.colaborador.f << ", " << x.colaborador.c << ", " << x.colaborador.brujula << ") ";
	cout << x.ultimaOrdenColaborador << endl;
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

		switch (*it){
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
			mapaConPlan[cst.colaborador.f][cst.colaborador.c] = 2;
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

void ComportamientoJugador::VisualizaPlan2(const stateN2 &st, const list<Action> &plan){
	AnulaMatriz(mapaConPlan);
	stateN2 cst = st;

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

		switch (*it){
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

void ComportamientoJugador::VisualizaPlan3(const stateN3 &st, const list<Action> &plan){
	AnulaMatriz(mapaConPlan);
	stateN3 cst = st;

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

		switch (*it){
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
list<Action> N0(const stateN0 &inicio, const ubicacion &final, const vector<vector<unsigned char>> &mapa){
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

list<Action> N1(const stateN1 &inicio, const ubicacion &final, const vector<vector<unsigned char>> &mapa)
{
	nodeN1 current_node;
	list<nodeN1> frontier;
	set<nodeN1> explored;
	list<Action> plan;
	bool percibido = false;
	current_node.st = inicio;
	frontier.push_back(current_node);
	bool valido;
	bool SolutionFound = (current_node.st.colaborador.f == final.f and
						  current_node.st.colaborador.c == final.c);

	while (!frontier.empty() and !SolutionFound)
	{
		frontier.pop_front();
		explored.insert(current_node);

		// cout << "PLAN ACTUAL --> ";
		// PintaPlan(current_node.secuencia);
		// PintaEstado(current_node.st);

		percibido = PerciboColaborador(current_node.st);

		if (percibido)
		{

			if (current_node.st.ultimaOrdenColaborador != act_CLB_WALK)
			{
				// Generar hijo act_CLB_WALK
				nodeN1 child_CLBwalk = current_node;
				child_CLBwalk.st = apply1(act_CLB_WALK, current_node.st, mapa);
				child_CLBwalk.secuencia.push_back(act_CLB_WALK);
				child_CLBwalk.st.ultimaOrdenColaborador = act_CLB_WALK;
				if (child_CLBwalk.st.colaborador.f == final.f and child_CLBwalk.st.colaborador.c == final.c)
				{
					current_node = child_CLBwalk;
					SolutionFound = true;
				}
				else if (explored.find(child_CLBwalk) == explored.end())
				{
					frontier.push_back(child_CLBwalk);
				}
			}

			if (!SolutionFound and current_node.st.ultimaOrdenColaborador != act_CLB_TURN_SR)
			{
				// Generar hijo act_CLB_TURN_SR
				nodeN1 child_CLBturnsr = current_node;
				child_CLBturnsr.st = apply1(act_CLB_TURN_SR, current_node.st, mapa);
				child_CLBturnsr.secuencia.push_back(act_CLB_TURN_SR);
				child_CLBturnsr.st.ultimaOrdenColaborador = act_CLB_TURN_SR;
				if (explored.find(child_CLBturnsr) == explored.end())
				{
					frontier.push_back(child_CLBturnsr);
				}
			}

			if (!SolutionFound and current_node.st.ultimaOrdenColaborador != act_CLB_STOP)
			{
				// Generar hijo act_CLB_STOP
				nodeN1 child_CLBstop = current_node;
				child_CLBstop.st = apply1(act_CLB_STOP, current_node.st, mapa);
				child_CLBstop.secuencia.push_back(act_CLB_STOP);
				child_CLBstop.st.ultimaOrdenColaborador = act_CLB_STOP;
				if (explored.find(child_CLBstop) == explored.end())
				{
					frontier.push_back(child_CLBstop);
				}
			}
		}

		// Generar el estado intermedio
		valido = true;
		if (current_node.st.ultimaOrdenColaborador == act_CLB_WALK)
		{
			nodeN1 child_CLBwalk = current_node;
			child_CLBwalk.st = apply1(act_CLB_WALK, current_node.st, mapa);
			if (child_CLBwalk.st.colaborador.f == final.f and child_CLBwalk.st.colaborador.c == final.c)
			{
				current_node = child_CLBwalk;
				SolutionFound = true;
			}
			else if (!(child_CLBwalk == current_node))
			{
				current_node = child_CLBwalk;
			}
			else
			{
				valido = false;
			}
		}
		else if (current_node.st.ultimaOrdenColaborador == act_CLB_TURN_SR)
		{
			nodeN1 child_CLBturnsr = current_node;
			child_CLBturnsr.st = apply1(act_CLB_TURN_SR, current_node.st, mapa);
			current_node = child_CLBturnsr;
		}

		if (!SolutionFound and valido)
		{
			// Generar hijo actIDLE
			nodeN1 child_idle = current_node;
			child_idle.st = apply1(actIDLE, current_node.st, mapa);
			child_idle.secuencia.push_back(actIDLE);
			if (child_idle.st.colaborador.f == final.f and child_idle.st.colaborador.c == final.c)
			{
				current_node = child_idle;
				SolutionFound = true;
			}
			else if (explored.find(child_idle) == explored.end())
			{
				frontier.push_back(child_idle);
			}
		}

		if (!SolutionFound and valido)
		{
			// Generar hijo actWALK
			nodeN1 child_walk = current_node;
			child_walk.st = apply1(actWALK, current_node.st, mapa);
			child_walk.secuencia.push_back(actWALK);
			if (child_walk.st.colaborador.f == final.f and child_walk.st.colaborador.c == final.c)
			{
				current_node = child_walk;
				SolutionFound = true;
			}
			else if (explored.find(child_walk) == explored.end())
			{
				frontier.push_back(child_walk);
			}
		}

		if(!SolutionFound and valido){
			//Generar hijo actRUN
			nodeN1 child_run = current_node;
			child_run.st = apply1(actRUN, current_node.st, mapa);
			child_run.secuencia.push_back(actRUN);
			if(child_run.st.colaborador.f == final.f and child_run.st.colaborador.c == final.c){
				current_node = child_run;
				SolutionFound = true;
			}
			else if (explored.find(child_run) == explored.end()){
				frontier.push_back(child_run);
			}
		}

		if (!SolutionFound and valido)
		{
			// Generar hijo actTURN_L
			nodeN1 child_turnl = current_node;
			child_turnl.st = apply1(actTURN_L, current_node.st, mapa);
			child_turnl.secuencia.push_back(actTURN_L);
			if (explored.find(child_turnl) == explored.end())
			{
				frontier.push_back(child_turnl);
			}
		}

		if (!SolutionFound and valido)
		{
			// Generar hijo actTURN_SR
			nodeN1 child_turnsr = current_node;
			child_turnsr.st = apply1(actTURN_SR, current_node.st, mapa);
			child_turnsr.secuencia.push_back(actTURN_SR);
			if (explored.find(child_turnsr) == explored.end())
			{
				frontier.push_back(child_turnsr);
			}
		}

		if (!SolutionFound and !frontier.empty())
		{
			current_node = frontier.front();
			while (!frontier.empty() and explored.find(current_node) != explored.end())
			{
				frontier.pop_front();
				if (!frontier.empty())
				{
					current_node = frontier.front();
				}
			}
		}
	}

	if (SolutionFound)
	{
		plan = current_node.secuencia;
		cout << "Encontrado un plan: ";
		PintaPlan(current_node.secuencia);
	}
	return plan;
}

list<Action> N2(const stateN2 &inicio, const ubicacion &final, const vector<vector<unsigned char>> &mapa){
	list<Action> plan;
	set<nodeN2> explored;
	priority_queue<nodeN2, vector<nodeN2>, OrdenarPrioridad> frontier;
	nodeN2 current_node;
	current_node.st = inicio;
	current_node.st.bateria = 0;

	bool SolutionFound = (current_node.st.jugador.f == final.f and current_node.st.jugador.c == final.c);
	current_node.secuencia.empty();
	frontier.push(current_node);

	while(!frontier.empty() and !SolutionFound){
	
		frontier.pop();
		explored.insert(current_node);

		if((mapa[current_node.st.jugador.f][current_node.st.jugador.c] == 'K') and (current_node.st.bikini == false)){
			//cout << "Bikini encontrado\n";
			current_node.st.bikini = true;
			current_node.st.zapatillas = false;
		}
		if((mapa[current_node.st.jugador.f][current_node.st.jugador.c] == 'D') and (current_node.st.zapatillas == false)){
			cout << "Zapatillas encontradas\n";
			PintaEstado(current_node.st);
			current_node.st.zapatillas = true;
			current_node.st.bikini = false;
		}

		//cout << "BATERIA: " << current_node.st.bateria << endl;

		//Generar hijo actWALK
		if(!SolutionFound){
			nodeN2 child_walk = current_node;
			child_walk.st = apply2(actWALK, current_node.st, mapa);
			child_walk.secuencia.push_back(actWALK);
			if (child_walk.st.jugador.f == final.f and child_walk.st.jugador.c == final.c){
				current_node = child_walk;
				SolutionFound = true;
			}
			else if(explored.find(child_walk) == explored.end()){
				child_walk.st.bateria += CosteAccion(child_walk.st, actWALK, mapa);
				frontier.push(child_walk);
			}
		}
		
		if(!SolutionFound){
			//Generar hijo actRUN
			nodeN2 child_run = current_node;
			child_run.st = apply2(actRUN, current_node.st, mapa);
			child_run.secuencia.push_back(actRUN);
			if (child_run.st.jugador.f == final.f and child_run.st.jugador.c == final.c){
				current_node = child_run;
				SolutionFound = true;
			}
			else if(explored.find(child_run) == explored.end()){
				child_run.st.bateria += CosteAccion(child_run.st, actRUN, mapa);
				frontier.push(child_run);
			}

			//Generar hijo actTURN_L
			nodeN2 child_turnl = current_node;
			child_turnl.st = apply2(actTURN_L, current_node.st, mapa);
			child_turnl.secuencia.push_back(actTURN_L);
			if(explored.find(child_turnl) == explored.end()){
				child_turnl.st.bateria += CosteAccion(child_turnl.st, actTURN_L, mapa);
				frontier.push(child_turnl);
			}

			//Generar hijo actTURN_SR
			nodeN2 child_turnsr = current_node;
			child_turnsr.st = apply2(actTURN_SR, current_node.st, mapa);
			child_turnsr.secuencia.push_back(actTURN_SR);
			if(explored.find(child_turnsr) == explored.end()){
				child_turnsr.st.bateria += CosteAccion(child_turnsr.st, actTURN_SR, mapa);
				frontier.push(child_turnsr);
			}
		}
		

		if(!frontier.empty() and !SolutionFound){
			current_node = frontier.top();
			while(!frontier.empty() and explored.find(current_node) != explored.end()){
				frontier.pop();
				if(!frontier.empty()){
					current_node = frontier.top();
				}
			}
		}
	}

	if(SolutionFound){
		plan = current_node.secuencia;
		cout << "Encontrado un plan: ";
		PintaPlan(current_node.secuencia);
		cout << "Coste total: " << current_node.st.bateria << endl;
	}
	return plan;
}

list<Action> N3(const stateN3 &inicio, const ubicacion &final, const vector<vector<unsigned char>> &mapa){
	list<Action> plan;
	set<nodeN3> explored;
	priority_queue<nodeN3, vector<nodeN3>, OrdenarPrioridad> frontier;
	nodeN3 current_node;
	bool percibido = false;
	bool valido;
	bool SolutionFound = (current_node.st.colaborador.f == final.f and 
						  current_node.st.colaborador.c == final.c  );
	
	current_node.st = inicio;
	current_node.st.bateria = 0;
	current_node.st.heuristica = 0;
	current_node.st.total = 0;

	frontier.push(current_node);

	while(!frontier.empty() and !SolutionFound){
		frontier.pop();
		explored.insert(current_node);
		valido = true;
		PintaPlan(current_node.secuencia);
		if((mapa[current_node.st.jugador.f][current_node.st.jugador.c] == 'K') and (current_node.st.bikini == false)){
			//cout << "Bikini encontrado\n";
			current_node.st.bikini = true;
			current_node.st.zapatillas = false;
		}
		if((mapa[current_node.st.jugador.f][current_node.st.jugador.c] == 'D') and (current_node.st.zapatillas == false)){
			//cout << "Zapatillas encontradas\n";
			current_node.st.zapatillas = true;
			current_node.st.bikini = false;
		}
		if((mapa[current_node.st.colaborador.f][current_node.st.colaborador.c] == 'K') and (current_node.st.bikini == false)){
			current_node.st.bikini = true;
			current_node.st.zapatillas = false;
		}
		if((mapa[current_node.st.colaborador.f][current_node.st.colaborador.c] == 'D') and (current_node.st.zapatillas == false)){
			current_node.st.zapatillas = true;
			current_node.st.bikini = false;
		}

		percibido = PerciboColaborador(current_node.st);

		if(percibido){
			//Generar hijo act_CLB_WALK
			nodeN3 child_CLBwalk = current_node;
			child_CLBwalk.st.bateria += CosteAccion(child_CLBwalk.st, act_CLB_WALK, mapa);
			child_CLBwalk.st.heuristica = Distancias(child_CLBwalk.st, final);
			child_CLBwalk.st.total = child_CLBwalk.st.bateria + child_CLBwalk.st.heuristica;
			child_CLBwalk.st = apply3(act_CLB_WALK, current_node.st, mapa);
			child_CLBwalk.secuencia.push_back(act_CLB_WALK);
			if(child_CLBwalk.st.colaborador.f == final.f and child_CLBwalk.st.colaborador.c == final.c){
				current_node = child_CLBwalk;
				SolutionFound = true;
			}
			else if(explored.find(child_CLBwalk) == explored.end()){
				frontier.push(child_CLBwalk);
			}

			if(!SolutionFound){
				//Generar hijo act_CLB_TURN_SR
				nodeN3 child_CLBturnsr = current_node;
				child_CLBturnsr.st.bateria += CosteAccion(child_CLBturnsr.st, act_CLB_TURN_SR, mapa);
				child_CLBturnsr.st.heuristica = Distancias(child_CLBturnsr.st, final);
				child_CLBturnsr.st.total = child_CLBturnsr.st.bateria + child_CLBturnsr.st.heuristica;
				child_CLBturnsr.st = apply3(act_CLB_TURN_SR, current_node.st, mapa);
				child_CLBturnsr.secuencia.push_back(act_CLB_TURN_SR);
				if(explored.find(child_CLBturnsr) == explored.end()){
					frontier.push(child_CLBturnsr);
				}
			}

			if(!SolutionFound){
				//Generar hijo act_CLB_STOP
				nodeN3 child_CLBstop = current_node;
				child_CLBstop.st.bateria += CosteAccion(child_CLBstop.st, act_CLB_STOP, mapa);
				child_CLBstop.st.heuristica = Distancias(child_CLBstop.st, final);
				child_CLBstop.st.total = child_CLBstop.st.bateria + child_CLBstop.st.heuristica;
				child_CLBstop.st = apply3(act_CLB_STOP, current_node.st, mapa);
				child_CLBstop.secuencia.push_back(act_CLB_STOP);
				if(explored.find(child_CLBstop) == explored.end()){
					frontier.push(child_CLBstop);
				}
			}
		}

		/*
		// Generar el estado intermedio
		if(current_node.st.ultimaOrdenColaborador == act_CLB_WALK){
			nodeN3 child_CLBwalk = current_node;
			child_CLBwalk.st.bateria += CosteAccion(child_CLBwalk.st, act_CLB_WALK, mapa);
			child_CLBwalk.st.prioridad = child_CLBwalk.st.bateria + Distancias(child_CLBwalk.st, final);
			child_CLBwalk.st = apply3(act_CLB_WALK, current_node.st, mapa);
			if(child_CLBwalk.st.colaborador.f == final.f and child_CLBwalk.st.colaborador.c == final.c){
				current_node = child_CLBwalk;
				SolutionFound = true;
			}
			else if(!(child_CLBwalk == current_node)){
				current_node = child_CLBwalk;
			}
			else{
				valido = false;
			}
		}

		if(current_node.st.ultimaOrdenColaborador == act_CLB_TURN_SR){
			nodeN3 child_CLBturnsr = current_node;
			child_CLBturnsr.st.bateria += CosteAccion(child_CLBturnsr.st, act_CLB_TURN_SR, mapa);
			child_CLBturnsr.st.prioridad = child_CLBturnsr.st.bateria + Distancias(child_CLBturnsr.st, final);
			child_CLBturnsr.st = apply3(act_CLB_TURN_SR, current_node.st, mapa);
			if(!(child_CLBturnsr == current_node)){
				current_node = child_CLBturnsr;
			}
			else{
				valido = false;
			}
		}	
		*/
		else{
			if(!SolutionFound and valido){
				//Generar hijo actIDLE
				nodeN3 child_idle = current_node;
				child_idle.st.bateria += CosteAccion(child_idle.st, actIDLE, mapa);
				child_idle.st.heuristica = Distancias(child_idle.st, final);
				child_idle.st.total = child_idle.st.bateria + child_idle.st.heuristica;
				child_idle.st = apply3(actIDLE, current_node.st, mapa);
				child_idle.secuencia.push_back(actIDLE);
				if(child_idle.st.colaborador.f == final.f and child_idle.st.colaborador.c == final.c){
					current_node = child_idle;
					SolutionFound = true;
				}
				else if(explored.find(child_idle) == explored.end()){
					frontier.push(child_idle);
				}
			}
			
			if(!SolutionFound and valido){
				//Generar hijo actWALK
				nodeN3 child_walk = current_node;
				child_walk.st.bateria += CosteAccion(child_walk.st, actWALK, mapa);
				child_walk.st.heuristica = Distancias(child_walk.st, final);
				child_walk.st.total = child_walk.st.bateria + child_walk.st.heuristica;
				child_walk.st = apply3(actWALK, current_node.st, mapa);
				child_walk.secuencia.push_back(actWALK);
				if(child_walk.st.colaborador.f == final.f and child_walk.st.colaborador.c == final.c){
					current_node = child_walk;
					SolutionFound = true;
				}
				else if(explored.find(child_walk) == explored.end()){
					frontier.push(child_walk);
				}
			}

			if(!SolutionFound and valido){
				//Generar hijo actRUN
				nodeN3 child_run = current_node;
				child_run.st.bateria += CosteAccion(child_run.st, actRUN, mapa);
				child_run.st.heuristica = Distancias(child_run.st, final);
				child_run.st.total = child_run.st.bateria + child_run.st.heuristica;
				child_run.st = apply3(actRUN, current_node.st, mapa);
				child_run.secuencia.push_back(actRUN);
				if(child_run.st.colaborador.f == final.f and child_run.st.colaborador.c == final.c){
					current_node = child_run;
					SolutionFound = true;
				}
				else if(explored.find(child_run) == explored.end()){
					frontier.push(child_run);
				}
			}

			if(!SolutionFound and valido){
				//Generar hijo actTURN_L
				nodeN3 child_turnl = current_node;
				child_turnl.st.bateria += CosteAccion(child_turnl.st, actTURN_L, mapa);
				child_turnl.st.heuristica = child_turnl.st.bateria + Distancias(child_turnl.st, final);
				child_turnl.st.total = child_turnl.st.bateria + child_turnl.st.heuristica;
				child_turnl.st = apply3(actTURN_L, current_node.st, mapa);
				child_turnl.secuencia.push_back(actTURN_L);
				if(explored.find(child_turnl) == explored.end()){
					frontier.push(child_turnl);
				}
			}

			if(!SolutionFound and valido){
				//Generar hijo actTURN_SR
				nodeN3 child_turnsr = current_node;
				child_turnsr.st.bateria += CosteAccion(child_turnsr.st, actTURN_SR, mapa);
				child_turnsr.st.heuristica = Distancias(child_turnsr.st, final);
				child_turnsr.st.total = child_turnsr.st.bateria + child_turnsr.st.heuristica;
				child_turnsr.st = apply3(actTURN_SR, current_node.st, mapa);
				child_turnsr.secuencia.push_back(actTURN_SR);
				if(explored.find(child_turnsr) == explored.end()){
					frontier.push(child_turnsr);
				}
			}
		}
		
		if(!SolutionFound and !frontier.empty()){
			current_node = frontier.top();
			while(!frontier.empty() and explored.find(current_node) != explored.end()){
				frontier.pop();
				if(!frontier.empty()){
					current_node = frontier.top();
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


void ComportamientoJugador::LoQueVeo(Sensores sensores){
	int n_casillas = mapaResultado.size();
	for(int i = 0; i < n_casillas; i++){
		for(int j = 0; j < n_casillas; j++){
			cout << vista[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	switch(sensores.sentido){
		case norte:
			for(int i = 0; i < 4 ;i++){
				for(int j = 0; j < 2*i + 1 ; j++){
					vista[sensores.posF -i][sensores.posC -i+j] = mapaResultado[sensores.posF -i][sensores.posC -i+j];
				}
			}
		break;

		case noreste:
			for(int i = 0; i < 4  ;i++){
				for(int j = 0; j < 4 ;j++){
					vista[sensores.posF -i][sensores.posC +j] = mapaResultado[sensores.posF -i][sensores.posC +j];
				}
			}
		break;

		case sur:
			for(int i = 0; i < 4 ;i++){
				for(int j = 0; j < 2*i + 1 ; j++){
					vista[sensores.posF +i][sensores.posC +i-j] = mapaResultado[sensores.posF +i][sensores.posC +i-j];
				}
			}
		break;

		case sureste:
			for(int i = 0; i < 4 ;i++){
				for(int j = 0; j < 4 ;j++){
					vista[sensores.posF +i][sensores.posC +j] = mapaResultado[sensores.posF +i][sensores.posC +j];
				}
			}

		case este:
			for(int i = 0; i < 4 ;i++){
				for(int j = 0; j < 2*i + 1 ; j++){
					vista[sensores.posF -i+j][sensores.posC +i] = mapaResultado[sensores.posF -i+j][sensores.posC +i];
				}
			}
		break;

		case noroeste:
			for(int i = 0; i < 4 ;i++){
				for(int j = 0; j < 4 ;j++){
					vista[sensores.posF -i][sensores.posC -j] = mapaResultado[sensores.posF -i][sensores.posC -j];
				}
			}

		case oeste:
			for(int i = 0; i < 4 ;i++){
				for(int j = 0; j < 2*i + 1 ; j++){
					vista[sensores.posF +i-j][sensores.posC -i] = mapaResultado[sensores.posF +i-j][sensores.posC -i];
				}
			}
		break;

		case suroeste:
			for(int i = 0; i < 4 ;i++){
				for(int j = 0; j < 4 ;j++){
					vista[sensores.posF +i][sensores.posC -j] = mapaResultado[sensores.posF +i][sensores.posC -j];
				}
			}
		break;
	}
}

// Este es el método principal que se piden en la practica.
// Tiene como entrada la información de los sensores y devuelve la acción a realizar.
// Para ver los distintos sensores mirar fichero "comportamiento.hpp"
Action ComportamientoJugador::think(Sensores sensores)
{
	Action accion = actIDLE;
	
	//LoQueVeo(sensores);
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

			c_state2.jugador.f = sensores.posF;
			c_state2.jugador.c = sensores.posC;
			c_state2.jugador.brujula = sensores.sentido;
			c_state2.colaborador.f = sensores.CLBposF;
			c_state2.colaborador.c = sensores.CLBposC;
			c_state2.colaborador.brujula = sensores.CLBsentido;

			c_state3.jugador.f = sensores.posF;
			c_state3.jugador.c = sensores.posC;
			c_state3.jugador.brujula = sensores.sentido;
			c_state3.colaborador.f = sensores.CLBposF;
			c_state3.colaborador.c = sensores.CLBposC;
			c_state3.colaborador.brujula = sensores.CLBsentido;

			goal.f = sensores.destinoF; 
			goal.c = sensores.destinoC;
			
			switch (sensores.nivel){
				case 0: 
					plan = N0(c_state, goal, mapaResultado);
					VisualizaPlan(c_state, plan);
					break;
				case 1: // Incluir aqui la llamada a alg. busqueda del nivel 1
					c_state1.ultimaOrdenColaborador = act_CLB_STOP;
					plan = N1(c_state1, goal, mapaResultado);
					VisualizaPlan1(c_state1,plan);
					break;
				case 2: // Incluir aqui la llamada a alg. busqueda del nivel 2
					plan = N2(c_state2, goal, mapaResultado);
					VisualizaPlan2(c_state2,plan);
					break;
				case 3: // Incluir aqui la llamada a alg. busqueda del nivel 3
					plan = N3(c_state3, goal, mapaResultado);
					VisualizaPlan3(c_state3,plan);
					break;
			}
			if (plan.size() > 0){
				//VisualizaPlan(c_state, plan);
				//VisualizaPlan1(c_state2, plan);
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
