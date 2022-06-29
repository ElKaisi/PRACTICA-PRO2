/** @file cjt_jugador.cc
    @brief Implementacion de cjt_jugador
 */

#include "cjt_jugador.hh"

    Cjt_jugador::Cjt_jugador() {
        
    }
    
    void Cjt_jugador::nuevo_jugador(string nombre) {
        if (not contiene(nombre)) {
            anadir_jugador(nombre);
            cout << mj.size() << endl;
        }
        else cout << "error: ya existe un jugador con ese nombre" << endl;
    }
    
    void Cjt_jugador::quitar_jugador(string nombre) {
        if (contiene(nombre)) {
            desplazar(nombre);
            rnk.pop_back();
            mj.erase(nombre);
            cout << mj.size() << endl;
        }
        else cout << "error: el jugador no existe" << endl;
    }
    
    void Cjt_jugador::ordenar_por_puntos() {
        stable_sort(rnk.begin(),rnk.end(),cmp);
        for (int i = 0; i < rnk.size(); ++i) {
            (mj[rnk[i].first]).modificar_posicion(i + 1);
        }
    }
    
    void Cjt_jugador::modificar_stats(string nombre, int punt, int pg, int pp, int sg, int sp, int jg, int jp, bool t) {
        if (contiene(nombre)) {
            mj[nombre].modificar_stats(punt,pg,pp,sg,sp,jg,jp,t);
            rnk[mj[nombre].consultar_posicion() - 1].second += punt;
        }
    }
    
    void Cjt_jugador::leer_cjt_jugador() {
        int P;
        cin >> P;
        string s;
        for (int i = 0; i < P; ++i) {
            cin >> s;
            anadir_jugador(s);
        }
    }
    
    void Cjt_jugador::listar_ranking() {
        for (int i = 0; i < rnk.size(); ++i) {
            cout << i + 1 << " " << rnk[i].first << " " << rnk[i].second << endl;
        }
    }
    
    void Cjt_jugador::listar_jugadores() {
        cout << mj.size() << endl;
        for (map<string,Jugador>::iterator it = mj.begin(); it != mj.end(); ++it) {
            cout << (*it).first << " ";
            (*it).second.consultar_jugador();
        }
    }
    
    void Cjt_jugador::consultar_jugador(string nombre) const {
        if (contiene(nombre)) {
            cout << (*(mj.find(nombre))).first << " ";
            (*(mj.find(nombre))).second.consultar_jugador();
        }
        else cout << "error: el jugador no existe" << endl;
    }
    
    string Cjt_jugador::consultar_nombre(int pos) const {
        return rnk[pos - 1].first;
    }
    
    int Cjt_jugador::consultar_torneos(string nombre) const {
        if (contiene(nombre)) return (*mj.find(nombre)).second.consultar_torneos();
        return 0;
    }
    
    bool Cjt_jugador::contiene(string nombre) const {
            return not mj.empty() and mj.find(nombre) != mj.end();
    }
    
    void Cjt_jugador::anadir_jugador(string nombre) {
        if (not contiene(nombre)) {
            Jugador j;
            j.modificar_posicion(rnk.size() + 1);
            mj.insert(make_pair(nombre,j));
            rnk.push_back(make_pair(nombre,0));
        }
        else cout << "error: ya existe un jugador con ese nombre" << endl;
    }

    //lectura y escritura
    
    void Cjt_jugador::desplazar(string nombre) {
        int i = mj[nombre].consultar_posicion() - 1;
        while (i + 1 < rnk.size()) {
            rnk[i] = rnk[i + 1];
            mj[rnk[i].first].modificar_posicion(i + 1);
            ++i;
        }
    }
    
    bool Cjt_jugador::cmp(pair<string,int> a, pair<string,int> b) {
       return a.second > b.second;
    }
    
