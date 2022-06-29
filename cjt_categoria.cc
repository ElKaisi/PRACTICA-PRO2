/** @file cjt_categoria.cc
 * @brief Implementacion de la clase cjt_categoria
 */

#include "cjt_categoria.hh"


    //constructora
    
    Cjt_categoria::Cjt_categoria() {}
    

    //consultoras
  
    int Cjt_categoria::puntos_obtenidos(int c, int n) const {
        if (c >= 1 and c <= cjt_cat.size() and n >= 1 and n <= cjt_cat[0].size()) return cjt_cat[c - 1][n - 1];
        else return 0;
    }
    
    string Cjt_categoria::nombre(int c) const {
        return nombres_categorias[c - 1];
    }
    
    int Cjt_categoria::consultar_categoria_max() const {
        return cjt_cat.size();
    }
    
    //lectura y escrtura
    
    void Cjt_categoria::leer_cjt_categoria() {
        int k, c;
        cin >> c >> k;
        cjt_cat = vector< vector<int> > (c,vector<int>(k));
        nombres_categorias = vector<string> (c);
        for (int i = 0; i < c; ++i) cin >> nombres_categorias[i];
        for (int i = 0; i < cjt_cat.size(); ++i) {
            for (int j = 0; j < cjt_cat[i].size(); ++j) cin >> cjt_cat[i][j];
        }
    }
    
    void Cjt_categoria::listar_categorias() const {
        cout << cjt_cat.size() << " " << cjt_cat[0].size() << endl;
        for (int i = 0; i < cjt_cat.size(); ++i) {
            cout << nombres_categorias[i];
            for (int j = 0; j < cjt_cat[i].size(); ++j) {
                cout << " " << cjt_cat[i][j];
            }
            cout << endl;
        }
    }
