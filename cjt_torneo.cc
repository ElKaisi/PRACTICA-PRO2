/** @file cjt_torneo.cc
 * @brief Implementacioin de la clase Cjt_torneo
 */

#include "cjt_torneo.hh"

    Cjt_torneo::Cjt_torneo(){}
    
    void Cjt_torneo::nuevo_torneo(string nombre, int c, Cjt_categoria& cats) {
        if (c > cats.consultar_categoria_max() or c < 1) cout << "error: la categoria no existe" << endl;
        else if( contiene(nombre)) cout << "error: ya existe un torneo con ese nombre" << endl;
        else {
            anadir_torneo(nombre,c,cats);
            cout << mt.size() << endl;
        }
    }

    void Cjt_torneo::quitar_torneo(string nombre, Cjt_jugador& cjug) {
        if (not contiene(nombre)) cout << "error: el torneo no existe" << endl;
        else {
            if (mt[nombre].se_ha_jugado()) mt[nombre].quitar_puntuacion(cjug);
            mt.erase(nombre);
            cout << mt.size() << endl;
            cjug.ordenar_por_puntos();
        }
    }
    
    void Cjt_torneo::eliminar_del_historial(string nombre, Cjt_jugador& cjug) {
        map<string,Torneo>::iterator it = mt.begin();
        int k = cjug.consultar_torneos(nombre);     //solo buscamos hasta que lo hayamos eliminado del historial de los k torneos en que ha participado o hasta llegar al final del mapa 
        while (k > 0 and it != mt.end()) {      //si no tiene torneos disputados no entra en el bucle
            if ((*it).second.eliminar_del_historial(nombre)) --k;
            ++it;
        }
    }
    
    void Cjt_torneo::leer_cjt_torneo(Cjt_categoria& cats) {
        int t, cat;
        string nom;
        cin >> t;
        for (int i = 0; i < t; ++i) {
            cin >> nom >> cat;
            anadir_torneo(nom,cat,cats);
        }
    }
    
    void Cjt_torneo::inciar_torneo(string nombre, Cjt_jugador& cjug) {
        if (not contiene(nombre)) cout << "error: el torneo no existe" << endl;
        else mt[nombre].iniciar_torneo(cjug);
    }
    
    void Cjt_torneo::finalizar_torneo(string nombre, Cjt_jugador& cjug, Cjt_categoria& cats) {
        mt[nombre].finalizar_torneo(cjug,cats);
    }
    
    void Cjt_torneo::listar_torneos() const {
        cout << num_torneos() << endl;
        for (map<string,Torneo>::const_iterator it = mt.begin(); it != mt.end(); ++it) {
            cout << (*it).first << " " << (*it).second.consultar_categoria() << endl;
        }
    }
    
    void Cjt_torneo::anadir_torneo(string nombre, int c, Cjt_categoria& cats) {
        mt.insert(make_pair(nombre,Torneo(c,cats)));
    }
    
    bool Cjt_torneo::contiene(string nombre) const {
        return mt.find(nombre) != mt.end();
    }
    
    int Cjt_torneo::num_torneos() const {
        return mt.size();
    }
