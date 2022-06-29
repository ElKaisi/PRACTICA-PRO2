/** @file torneo.cc
 * @brief Implementacion de la clase Torneo
 */
#include "torneo.hh"

    Torneo::Torneo() {}
    
    Torneo::Torneo(int cat, Cjt_categoria& cats) {
        categoria = cats.nombre(cat);
        num_categoria = cat;
    }
    
    void Torneo::iniciar_torneo(Cjt_jugador& c) {
        if (se_ha_jugado()) limpiar();          
        leer_insiripciones(c);
        int h = ceil(log2(vi.size())) + 1;
        arbol = hacer_emparejamientos(h,make_pair(1,"vacio"),1, vi.size());
        escribir_arbol_empar(arbol,vi);
        cout << endl;
    }
   
    void Torneo::finalizar_torneo(Cjt_jugador& cjug, Cjt_categoria& cats) {
        if (se_ha_jugado()) quitar_puntuacion(cjug);
        hist = map<string,int>();
        vector<Jug> vstats(vi.size());      //vector local de strcuts para almacenar las estadisticas y sumarlas de una vez al final
        leer_ganadores(arbol,cjug,cats,1,vstats,vi,hist,num_categoria);
        escribir_cuadro_resultados(arbol,vi);
        cout << endl;
        for (int i = 0; i < vstats.size(); ++i) {   //pasar las estadisticas del vector local a los jugadores con una unica llamada al conjunto por jugador
            cjug.modificar_stats(vi[i].first, vi[i].second, vstats[i].pg, vstats[i].pp, vstats[i].sg, vstats[i].sp, vstats[i].jg, vstats[i].jp,true);
        }
        listar(vi);
        cjug.ordenar_por_puntos();
    }
    
    void Torneo::quitar_puntuacion(Cjt_jugador& cjug) const {
        for (map<string,int>::const_iterator it = hist.begin(); it != hist.end(); ++it) {
            if ((*it).second != 0)
                cjug.modificar_stats((*it).first,-1*(*it).second,0,0,0,0,0,0,false);
        }
    }
    
    bool Torneo::eliminar_del_historial(string nombre) {
        return hist.erase(nombre);
    }
    
    string Torneo::consultar_categoria() const {
        return categoria;
    }
    
    bool Torneo::se_ha_jugado() const {
        return not hist.empty();
    }
    
    void Torneo::leer_insiripciones(Cjt_jugador& cjug) {
        int n, pos;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> pos;
            vi.push_back(make_pair(cjug.consultar_nombre(pos),0));
        }
    }
    
    BinTree<pair<int,string>> Torneo::hacer_emparejamientos(int prof_max, pair<int,string> a, int prof, int n) {
        BinTree<pair<int,string>> t;
        if (prof <= prof_max) {
            int z = pow(2,prof); //lo calculo en el ciclo anterior, por lo tanto quito el -1
            int b = z + 1 - a.first;
            if (b >= 1 and b <= n) {
                t = BinTree<pair<int,string>> (a, hacer_emparejamientos(prof_max,a,prof + 1,n), hacer_emparejamientos(prof_max,make_pair(b,"vacio"),prof + 1,n));
            }
            else t = BinTree<pair<int,string>>(a);
        }
        return t;
    }
    
    void Torneo::escribir_arbol_empar(const BinTree<pair<int,string>>& a, const vector<pair<string,int>>& vi) {
        if (not a.empty()) {
            if (a.left().empty()) {
                cout << a.value().first << "." << vi[a.value().first - 1].first;
            }
            else {
                cout << "(";
                escribir_arbol_empar(a.left(),vi);
                cout << " ";
                escribir_arbol_empar(a.right(),vi);
                cout << ")";
            }
        }
    }
    
    void Torneo::leer_ganadores(BinTree<pair<int,string>>& a, Cjt_jugador& cjug, Cjt_categoria& cats, int prof, vector<Jug>& vstats, vector<pair<string,int>>& vi, map<string,int>& hist, int num_categoria) {
        if (not a.empty()) {
            string s;
            cin >> s;
            if (not a.left().empty()) {
                BinTree<pair<int,string>> l = a.left();
                BinTree<pair<int,string>> r = a.right();
                a = BinTree<pair<int,string>> (make_pair(a.value().first,s),l,r);   //leemos el string resultado 
                
                leer_ganadores(l,cjug,cats,prof + 1,vstats, vi, hist, num_categoria);
                leer_ganadores(r,cjug,cats,prof + 1,vstats, vi, hist, num_categoria);
                int p = cats.puntos_obtenidos(num_categoria,prof + 1);
                
                if (string_reader(a.value().second, l.value().first, r.value().first,vstats)) {  //decidimos los ganadores con el string reader
                    a = BinTree<pair<int,string>> (make_pair(l.value().first, a.value().second),l,r);
                    if (prof == 1) {
                        int p_ganador = cats.puntos_obtenidos(num_categoria,1);
                        vi[a.value().first - 1].second = p_ganador;
                        hist.insert(make_pair(vi[a.value().first - 1].first, p_ganador));
                    }
                    
                    vi[a.right().value().first - 1].second = p;
                    hist.insert(make_pair(vi[a.right().value().first - 1].first, p));
                }
                
                else {
                    a = BinTree<pair<int,string>> (make_pair(r.value().first, a.value().second),l,r);
                    if (prof == 1) {
                        int p_ganador = cats.puntos_obtenidos(num_categoria,1);
                        vi[a.value().first - 1].second = p_ganador;
                        hist.insert(make_pair(vi[a.value().first - 1].first, p_ganador));
                    }
                    
                    vi[a.left().value().first - 1].second = p;
                    hist.insert(make_pair(vi[a.left().value().first - 1].first, p));
                }
            }
            
            else a = BinTree<pair<int,string>> (make_pair(a.value().first,s));
        }
    }
    
    void Torneo::escribir_cuadro_resultados(const BinTree<pair<int,string>>& a, const vector<pair<string,int>>& vi) {
        if (not a.empty() and not a.left().empty()) {
            cout << "(";
            cout << a.left().value().first << "." << vi[a.left().value().first - 1].first << 
            " vs " << a.right().value().first << "." << vi[a.right().value().first - 1].first << " " 
            << a.value().second;
            escribir_cuadro_resultados(a.left(),vi);
            escribir_cuadro_resultados(a.right(),vi);
            cout << ")";
        }
    }
    
    void Torneo::listar(const vector<pair<string,int>>& vi) {
        for (int i = 0; i < vi.size(); ++i) {
            if (vi[i].second != 0) cout << i + 1 << "." << vi[i].first << " " << vi[i].second << endl;
        }
    }
    
    bool Torneo::string_reader(const string& a, int l, int r, vector<Jug>& vstats) {
        bool b = a[a.size() - 3] > a[a.size() - 1];
        if (a == "0-1" or a == "1-0") {
            if (a == "1-0") {
                ++vstats[l-1].pg;
                ++vstats[r-1].pp;
            }
            else if (a == "0-1") {
                ++vstats[l-1].pp;
                ++vstats[r-1].pg;
            }
        }
        else {
            for (int i = 0; i + 2 < a.size(); i += 4) {
                if(a[i] - '0' > a[i + 2] - '0') {
                    ++vstats[l-1].sg;
                    ++vstats[r-1].sp;
                }
                else {
                    ++vstats[r-1].sg;
                    ++vstats[l-1].sp;
                }
                vstats[l-1].jp += a[i + 2] - '0';       //almacenamos las estadisticas en struct para no llamar a cjt_jugadores muchas veces
                vstats[r-1].jp += a[i] - '0';
                vstats[l-1].jg += a[i] - '0';
                vstats[r-1].jg += a[i + 2] - '0';
            }
            if (b) {
                ++vstats[l-1].pg;
                ++vstats[r-1].pp;
            }
            else {
                ++vstats[l-1].pp;
                ++vstats[r-1].pg;
            }
        }
        return b;
    }
    
     void Torneo::limpiar() {
        arbol = BinTree<pair<int,string>>();
        vi = vector<pair<string,int>>();
    }
