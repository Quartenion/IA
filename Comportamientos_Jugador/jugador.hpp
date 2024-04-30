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
       colaborador.f == x.colaborador.f and colaborador.c == x.colaborador.c){
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
  bool bikini;
  bool zapatillas;
  bool bateria;

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
    void LoQueVeo(Sensores sensores);


  private:
    // Declarar Variables de Estado
    list<Action> plan;
    bool hayPlan;
    stateN0 c_state;
    stateN1 c_state1;
    stateN2 c_state2;
    ubicacion goal;
    char vista[100][100];
};

#endif
