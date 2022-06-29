/** @file jugador.cc
    @brief Implementacion de la clase Jugador
*/

#include "jugador.hh"

    //constructoras
    Jugador::Jugador() {
         puntos = torneos = partidos_ganados = partidos_perdidos = sets_ganados = sets_perdidos
        = juegos_ganados = juegos_perdidos = 0;
    }
    
    int Jugador::consultar_puntos() const {
        return puntos;
    }
    
    int Jugador::consultar_posicion() const{
        return posicion;
    }
    
     int Jugador::consultar_torneos() const {
         return torneos;
    }
    
    void Jugador::modificar_stats(int punt, int pg, int pp, int sg, int sp, int jg, int jp, bool t) {
        puntos += punt;
        partidos_ganados += pg;
        partidos_perdidos += pp;
        sets_ganados += sg;
        sets_perdidos += sp;
        juegos_ganados += jg;
        juegos_perdidos += jp;
        if (t) ++torneos;
    }
    
    void Jugador::modificar_posicion(int p) {
        posicion = p;
    }
    
    void Jugador::consultar_jugador() const {
        cout << "Rk:" << posicion << " Ps:" << puntos << " Ts:" << torneos <<
        " WM:" << partidos_ganados << " LM:" << partidos_perdidos << " WS:" <<
        sets_ganados << " LS:" << sets_perdidos << " WG:" << juegos_ganados <<
        " LG:" << juegos_perdidos << endl;
    }
