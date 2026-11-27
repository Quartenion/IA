# IA · Inteligencia Artificial

Prácticas de **Inteligencia Artificial** (Grado en Ingeniería Informática, Universidad de Granada). Las tres son en C++ y parten del código base que da la asignatura; el trabajo propio está en el comportamiento del agente.

| Carpeta | Práctica | Qué hace |
|---|---|---|
| `P1/` | **Agentes reactivos** | Un agente explora un mapa desconocido y decide cada paso según lo que percibe. El comportamiento está en `Comportamientos_Jugador/`. |
| `P2/` | **Agentes deliberativos (búsqueda)** | El agente planifica rutas sobre el mapa por niveles: búsqueda en anchura en los primeros niveles, coste uniforme cuando las acciones tienen coste distinto y A\* con heurística de distancia en los últimos, incluido coordinarse con un colaborador. |
| `P3/` | **Juegos con adversario: Parchís** | Un jugador automático de Parchís con **Minimax y poda alfa-beta** y heurísticas propias (`src/AIPlayer.cpp`). Tiene interfaz gráfica con SFML. |

## Cómo ejecutarlo

Necesita Linux (o WSL) con `g++`, `cmake` y `make`.

### P1 y P2

Cada una trae un script que instala las dependencias y compila:

```bash
cd P1            # o P2
./install.sh
./practica1      # con interfaz gráfica (en P2: ./practica2)
./practica1SG    # sin interfaz, para pruebas rápidas (en P2: ./practica2SG)
```

Los mapas de prueba están en `mapas/`. Si cambias el código, recompila con `make`.

### P3 · Parchís

```bash
cd P3
./install.sh          # instala SFML, compila en build/ y lanza el juego
./build/ParchisGame   # para volver a lanzarlo después
```

El README de cada carpeta es el enunciado original de la asignatura, con más detalles sobre los parámetros.
