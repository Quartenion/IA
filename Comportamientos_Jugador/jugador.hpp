#ifndef COMPORTAMIENTOJUGADOR_H
#define COMPORTAMIENTOJUGADOR_H

#include "comportamientos/comportamiento.hpp"

#include <list>

struct stateN0{
  ubicacion jugador;
  ubicacion colaborador;
  Action ultimaOrdenColaborador;

  bool operator==(const stateN0 &x) const{
    if(jugador == x.jugador and 
       colaborador.f == x.colaborador.f and colaborador.c == x.colaborador.c){
      return true;
    }
    else{
      return false;
    }
  }
};

struct stateN1{
  ubicacion jugador;
  ubicacion colaborador;
  Action ultimaOrdenColaborador;

  bool operator==(const stateN1 &x) const{
    if(jugador == x.jugador and 
       colaborador.f == x.colaborador.f and colaborador.c == x.colaborador.c and
       ultimaOrdenColaborador == x.ultimaOrdenColaborador){
      return true;
    }
    else{
      return false;
    }
  }
};

struct stateN2{
  ubicacion jugador;
  ubicacion colaborador;
  Action ultimaOrdenColaborador;
  bool bikini = false;
  bool zapatillas = false;
  int bateria;

  bool operator==(const stateN2 &x) const{
    if(jugador == x.jugador and 
       colaborador.f == x.colaborador.f and colaborador.c == x.colaborador.c){
      return true;
    }
    else{
      return false;
    }
  }

  bool operator<(const stateN2 &n) const{
		return n.bateria > bateria;
	}
};

struct stateN3{
  ubicacion jugador;
  ubicacion colaborador;
  Action ultimaOrdenColaborador;
  bool bikini = false;
  bool zapatillas = false;
  int bateria;
  int prioridad;

  bool operator==(const stateN3 &x) const{
    if(jugador == x.jugador and 
       colaborador.f == x.colaborador.f and colaborador.c == x.colaborador.c){
      return true;
    }
    else{
      return false;
    }
  }

  bool operator<(const stateN2 &n) const{
		return n.bateria > bateria;
	}
};

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
		else if (st.jugador.f == b.st.jugador.f and st.jugador.c == b.st.jugador.c and st.jugador.brujula == b.st.jugador.brujula and st.colaborador.f < b.st.colaborador.f)
			return true;
		else if (st.jugador.f == b.st.jugador.f and st.jugador.c == b.st.jugador.c and st.jugador.brujula == b.st.jugador.brujula and st.colaborador.f == b.st.colaborador.f and st.colaborador.c < b.st.colaborador.c)
			return true;
		else if (st.jugador.f == b.st.jugador.f and st.jugador.c == b.st.jugador.c and st.jugador.brujula == b.st.jugador.brujula and st.colaborador.f == b.st.colaborador.f and st.colaborador.c == b.st.colaborador.c and st.colaborador.brujula < b.st.colaborador.brujula)
			return true;
		else if (st.jugador.f == b.st.jugador.f and st.jugador.c == b.st.jugador.c and st.jugador.brujula == b.st.jugador.brujula and st.colaborador.f == b.st.colaborador.f and st.colaborador.c == b.st.colaborador.c and st.colaborador.brujula == b.st.colaborador.brujula and st.ultimaOrdenColaborador < b.st.ultimaOrdenColaborador)
			return true;
		else
			return false;
	}
};
// Definición del tipo de nodo del nivel 2
struct nodeN2{
	stateN2 st;
	list<Action> secuencia;

	bool operator==(const nodeN2 &n) const{
		return (st==n.st);
	}

	bool operator<(const nodeN2 &b) const{
		if(st.jugador.f < b.st.jugador.f)
			return true;
		else if(st.jugador.f == b.st.jugador.f and st.jugador.c < b.st.jugador.c)
			return true;
		else if (st.jugador.f == b.st.jugador.f and st.jugador.c == b.st.jugador.c and st.jugador.brujula < b.st.jugador.brujula)
			return true;
		else if (st.jugador.f == b.st.jugador.f and st.jugador.c == b.st.jugador.c and st.jugador.brujula < b.st.jugador.brujula and st.bikini < b.st.bikini)
			return true;
		else if (st.jugador.f == b.st.jugador.f and st.jugador.c == b.st.jugador.c and st.jugador.brujula < b.st.jugador.brujula and st.bikini == b.st.bikini and st.zapatillas < b.st.zapatillas)
			return true;
		else if (st.jugador.f == b.st.jugador.f and st.jugador.c == b.st.jugador.c and st.jugador.brujula < b.st.jugador.brujula and st.bikini == b.st.bikini and st.zapatillas == b.st.zapatillas and st.bateria < b.st.bateria)
			return true;
		else
			return false;
	}
};

struct nodeN3{
  stateN3 st;
  list<Action> secuencia;

  bool operator==(const nodeN3 &n) const{
    return (st==n.st);
  }

  bool operator<(const nodeN3 &b) const{
    if(st.jugador.f < b.st.jugador.f)
			return true;
		else if(st.jugador.f == b.st.jugador.f and st.jugador.c < b.st.jugador.c)
			return true;
		else if (st.jugador.f == b.st.jugador.f and st.jugador.c == b.st.jugador.c and st.jugador.brujula < b.st.jugador.brujula)
			return true;
		else if (st.jugador.f == b.st.jugador.f and st.jugador.c == b.st.jugador.c and st.jugador.brujula == b.st.jugador.brujula and st.colaborador.f < b.st.colaborador.f)
			return true;
		else if (st.jugador.f == b.st.jugador.f and st.jugador.c == b.st.jugador.c and st.jugador.brujula == b.st.jugador.brujula and st.colaborador.f == b.st.colaborador.f and st.colaborador.c < b.st.colaborador.c)
			return true;
		else if (st.jugador.f == b.st.jugador.f and st.jugador.c == b.st.jugador.c and st.jugador.brujula == b.st.jugador.brujula and st.colaborador.f == b.st.colaborador.f and st.colaborador.c == b.st.colaborador.c and st.colaborador.brujula < b.st.colaborador.brujula)
			return true;
		else if (st.jugador.f == b.st.jugador.f and st.jugador.c == b.st.jugador.c and st.jugador.brujula == b.st.jugador.brujula and st.colaborador.f == b.st.colaborador.f and st.colaborador.c == b.st.colaborador.c and st.colaborador.brujula == b.st.colaborador.brujula and st.ultimaOrdenColaborador < b.st.ultimaOrdenColaborador)
			return true;
		else
			return false;
	}
};

struct OrdenarPrioridad{
	bool operator()(nodeN2 &x, nodeN2 &y){
		return (x.st.bateria > y.st.bateria || 
    (x.st.bateria == y.st.bateria && x.st.bikini > y.st.bikini) || 
    (x.st.bateria == y.st.bateria && x.st.bikini == y.st.bikini && x.st.zapatillas > y.st.zapatillas));
	}
  bool operator()(nodeN3 &x, nodeN3 &y){
		return (x.st.bateria > y.st.bateria || 
    (x.st.bateria == y.st.bateria && x.st.bikini > y.st.bikini) || 
    (x.st.bateria == y.st.bateria && x.st.bikini == y.st.bikini && x.st.zapatillas > y.st.zapatillas));
	}
};

class ComportamientoJugador : public Comportamiento {
  public:
    ComportamientoJugador(unsigned int size) : Comportamiento(size) {
      // Inicializar Variables de Estado
    }
    ComportamientoJugador(std::vector< std::vector< unsigned char> > mapaR) : Comportamiento(mapaR) {
      // Inicializar Variables de Estado
      hayPlan = false;

      for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
          vista[i][j] = '-';
        }
      }
    }
    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
    ~ComportamientoJugador(){}

    Action think(Sensores sensores);
    int interact(Action accion, int valor);

    void VisualizaPlan(const stateN0 &st, const list<Action> &plan);
    void VisualizaPlan1(const stateN1 &st, const list<Action> &plan);
    void VisualizaPlan2(const stateN2 &st, const list<Action> &plan);
    void VisualizaPlan3(const stateN3 &st, const list<Action> &plan);
    void LoQueVeo(Sensores sensores);


  private:
    // Declarar Variables de Estado
    list<Action> plan;
    bool hayPlan;
    stateN0 c_state;
    stateN1 c_state1;
    stateN2 c_state2;
    stateN3 c_state3;
    ubicacion goal;
    char vista[100][100];
};

#endif
