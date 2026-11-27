# IA · Inteligencia Artificial

Prácticas de la asignatura Inteligencia Artificial del Grado en Ingeniería Informática de la Universidad de Granada, hechas en C++.

Las tres parten del código base que da la asignatura, que ya trae el simulador, los mapas y la interfaz gráfica. El trabajo de cada práctica está en el comportamiento del agente, es decir, en decidir qué hace en cada momento, y cada una sube un poco el nivel respecto a la anterior.

## Las prácticas

**P1 · Agente reactivo.** El agente se mueve por un mapa que no conoce y decide cada paso solo con lo que ve en ese momento, sin planificar nada. Mientras avanza, va guardando lo que descubre del mapa. El comportamiento está en `P1/Comportamientos_Jugador/`.

**P2 · Agente deliberativo.** Ahora el agente sí planifica el camino antes de moverse, y la práctica está dividida en niveles. En los primeros se usa búsqueda en anchura para llegar al destino con el menor número de acciones. Después, como moverse por cada tipo de casilla cuesta una cantidad distinta de energía (cruzar el agua cuesta mucho menos si llevas el bikini, y el bosque si llevas las zapatillas), se usa búsqueda de coste uniforme, y en los últimos niveles A\*, con la distancia hasta el objetivo como heurística, incluso cuando hay que coordinarse con un colaborador.

**P3 · Parchís.** Un jugador automático de Parchís que elige su jugada con Minimax y poda alfa-beta. Para ello, simula varias jugadas hacia delante, suyas y del rival, y puntúa cada tablero con una heurística propia, que es la que decide qué tan buena es cada posición. Está en `P3/src/AIPlayer.cpp` y tiene interfaz gráfica con SFML.

## Cómo ejecutarlo

**Requisitos:** Linux (o WSL en Windows) con `g++`, `cmake` y `make`.

### P1 y P2

Cada una trae un script que instala las dependencias y compila:

```bash
cd P1            # o P2
./install.sh
./practica1      # con interfaz gráfica (en P2: ./practica2)
./practica1SG    # sin interfaz, para probar más rápido (en P2: ./practica2SG)
```

Los mapas están en `mapas/`. Si cambias el código, recompila con `make`.

### P3 · Parchís

```bash
cd P3
./install.sh          # instala SFML, compila en build/ y lanza el juego
./build/ParchisGame   # para volver a lanzarlo después
```

El README que hay dentro de cada carpeta es el enunciado original de la asignatura, por si hace falta más detalle sobre los parámetros.

## Estructura

```
P1/Comportamientos_Jugador/   <- agente reactivo
P2/Comportamientos_Jugador/   <- agente deliberativo (búsquedas por niveles)
P3/src/AIPlayer.cpp           <- jugador de Parchís con Minimax y poda alfa-beta
*/mapas/                      <- mapas de prueba
```

## Créditos

Agentes y jugador automático: Fernando Lanzarot Facio. El simulador y el código base son de la asignatura.
