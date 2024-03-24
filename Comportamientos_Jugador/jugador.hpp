#ifndef COMPORTAMIENTOJUGADOR_H
#define COMPORTAMIENTOJUGADOR_H

#include "comportamientos/comportamiento.hpp"
using namespace std;

struct state{
  int fil;
  int col;
  Orientacion brujula;
};

class ComportamientoJugador : public Comportamiento{
  public:
    ComportamientoJugador(unsigned int size) : Comportamiento(size){
      // Constructor de la clase
      current_state.fil = 99;
      current_state.col = 99;
      current_state.brujula = norte;
      last_action = actIDLE;
      girar_derecha = 0;
      n_casillas = 1;
      bien_situado = false;
      tengo_bikini = false;
      tengo_zapatillas = false;
      he_visto_precipicio = false;
      girando_I = false;
      girando_D = false;
      inicio = true;
      dimensiones = false;
      //MATRIZ DE CASILLAS VISITADAS
      for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
          visitas[i][j] = 0;
        }
      }
      tiempo = 0;
      min = 0;

    }

    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
    ~ComportamientoJugador(){}

    Action think(Sensores sensores);
    int interact(Action accion, int valor);

  private:
  // Declarar aquí las variables de estado
  state current_state; 
  Orientacion brujula;
  Action last_action;
  int girar_derecha;
  int n_casillas;
  bool bien_situado;
  bool tengo_bikini;
  bool tengo_zapatillas;
  bool he_visto_precipicio;
  bool girando_I;
  bool girando_D;
  bool inicio;
  bool dimensiones;
  int visitas[100][100];
  int tiempo;
  int min;
  bool moverse;
};
#endif
