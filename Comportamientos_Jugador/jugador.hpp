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
      bien_situado = false;
      tengo_bikini = false;
      tengo_zapatillas = false;
      girando_I = false;
      girando_D = false;
      girar_MAS_I = false;
      girar_MAS_D = false;
      inicio = false;
      //MATRIZ DE CASILLAS VISITADAS
      for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
          visitas[i][j] = 0;
        }
      }
      min_local = 0;
      min_remoto = 0;
      moverse = false;
      n_casillas = 1;
      time = 0;
      orientado = false;
      hay_obstaculo = false;
      veces_en_precipicio = 0;
      girando = 0;
      remoto = true;
      preevision = false;
      

      //DIAMETRO DE SENSACION
      for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
          diametro[i][j] = 0;
        }
      }

    }

    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
    ~ComportamientoJugador(){}

    Action think(Sensores sensores);
    int interact(Action accion, int valor);

    Action nextMove(Sensores sensores);
    Action blindMove(Sensores sensores);

  private:
  // Declarar aquí las variables de estado
  state current_state; 
  Orientacion brujula;
  Action last_action;
  int girar_derecha;
  bool bien_situado;
  bool tengo_bikini, tengo_zapatillas;
  bool girando_I, girando_D, girar_MAS_I, girar_MAS_D;
  bool inicio;
  int visitas[100][100];
  int min_local;
  int min_remoto;
  bool moverse;
  int n_casillas;
  int time;
  bool orientado;
  bool hay_obstaculo;
  int veces_en_precipicio;
  int girando;
  bool remoto;
  bool preevision;
  int diametro[100][100];
};
#endif
