/**
 * @mainpage </em>Practica de PRO2: Circuito de tenis.</em>
 
 Documentacion de las clases y funciones definidas en la practica. Las clases utilizadas son Jugador, Cjt_jugador, Torneo, Cjt_torneo, Cjt_categoria
*/


/** @file program.cc
    @brief Programa principal de la práctica
*/

#include "cjt_torneo.hh"
#include "cjt_jugador.hh"
#include "cjt_categoria.hh"

int main () {
    //leer conj cat
    Cjt_categoria Categorias;
    Categorias.leer_cjt_categoria();
    
    //leer conj inicial torneos
    Cjt_torneo Torneos;
    Torneos.leer_cjt_torneo(Categorias);
    
    //leer conj incial jugadores
    Cjt_jugador Jugadores;
    Jugadores.leer_cjt_jugador();
    
    string comando;
    cin >> comando;
    while (comando != "fin") {
        if (comando == "nuevo_jugador" or comando == "nj") {
            string p;
            cin >> p;
            cout << "#" << comando << " " << p << endl;
            Jugadores.nuevo_jugador(p);
        }
        
        else if (comando == "nuevo_torneo" or comando == "nt") {
            string id;
            int categoria;
            cin >> id >> categoria;
            cout << "#" << comando << " " << id << " " << categoria << endl;
            Torneos.nuevo_torneo(id,categoria,Categorias);
        }
        
        else if (comando == "baja_jugador" or comando == "bj") {
            string p; cin >> p;
            cout << "#" << comando << " " << p << endl;
            Torneos.eliminar_del_historial(p, Jugadores);
            Jugadores.quitar_jugador(p);
        }
        
        else if (comando == "baja_torneo" or comando == "bt") {
            string t; cin >> t;
            cout << "#" << comando << " " << t << endl;
            Torneos.quitar_torneo(t,Jugadores);
        }
        
        else if (comando == "iniciar_torneo" or comando == "it") {
            string t; cin >> t;
            cout << "#" << comando << " " << t << endl;
            Torneos.inciar_torneo(t, Jugadores);
        }
        
        else if (comando == "finalizar_torneo" or comando == "ft") {
            string t; cin >> t;
            cout << "#" << comando << " " << t << endl;
            Torneos.finalizar_torneo(t, Jugadores, Categorias);
        }
        
        else if (comando == "listar_ranking" or comando == "lr") {
            cout << "#" << comando << endl;
            Jugadores.listar_ranking();
        }
        
        else if (comando == "listar_jugadores" or comando == "lj") {
            cout << "#" << comando << endl;
            Jugadores.listar_jugadores();
        }
        
        else if (comando == "consultar_jugador" or comando == "cj") {
            string p; cin >> p;
            cout << "#" << comando << " " << p << endl;
            Jugadores.consultar_jugador(p);
        }
        
        else if (comando == "listar_torneos" or comando == "lt") {
            cout << "#" << comando << endl;
            Torneos.listar_torneos();
        }
        
        else if (comando == "listar_categorias" or comando == "lc") {
            cout << "#" << comando << endl;
            Categorias.listar_categorias();
        }
        
        cin >> comando;
    }
}
