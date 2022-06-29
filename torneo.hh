/** @file torneo.hh
    @brief Especificación de la clase Torneo
*/


#ifndef _TORNEO_HH_
#define _TORNEO_HH_
#include "cjt_jugador.hh"
#include "cjt_categoria.hh"

#ifndef NO_DIAGRAM 
#include "BinTree.hh"
#include <map>
#include <cmath>
#include <string>
struct Jug {
    int sg;
    int sp;
    int jg;
    int jp;
    int pg;
    int pp;
};
#endif

/** @class Torneo
    @brief Representa un torneo de tenis.
    El torneo tiene su categoria, un registro de los participantes actuales y
    un registro de los participantes de la edicion anterior. Tiene un arbol binario que representa un torneo.
*/
class Torneo {
public:
    
    //constructoras
    
    /** @brief Constructora de Torneo vacio
     * \pre: cierto
     * \post: crea un torneo vacio
     */
    Torneo();
    
    /** @brief Constructora de Torneo con categoria
     * \pre: cierto
     * \post: Un torneo con nombre y categoria
     */
    Torneo(int cat, Cjt_categoria& cats);
    
    //modificadoras y consultoras
    
    /** @brief Inicia el torneo, se leen inscripciones, distribuye los emparejamientos
     *  y escribe el arbol de emparejamientos
     * \pre: cierto
     * \post: Se leen los jugadores y se confecciona y escribe el cuadro de emparejamientos
     */
    void iniciar_torneo(Cjt_jugador& c);
    
    /** @brief Finaliza el torneo acorde al enunciado
     * \pre: Se ha iniciado el torneo anteriormente
     * \post: Se leen los resultados, se produce e imprime el cuadro de resultados
     * y actualiza el ranking y estadisticas de los jugadores restando los puntos de
     * la edicion anterior si la hay
     */
    void finalizar_torneo(Cjt_jugador& cjug, Cjt_categoria& cats);
    
    /** @brief Resta la puntuacion de los ugadores obtenida en el torneo
     * \pre: cierto
     * \post: Se ha restado la puntuacion obtenida en el parametro implicito a los jugadores de Cjug y se ha eliminado el historial del torneo para ser remplazado por uno nuevo al finalizar este
     */
    void quitar_puntuacion(Cjt_jugador& cjug) const;
    
    /** @brief Elimina el jugador identificado por nombre del historial del p.i
     * \pre: cierto
     * \post: Devueolve true si se ha eliminado el jugador identificado por nombre del historial del p.i, false en caso contrario
     */
    bool eliminar_del_historial(string nombre);
    
    /** @brief Consultora de la categoria del torneo
     * \pre: cierto
     * \post: Devuelve el nombre de la categoria del p.i
     */
    string consultar_categoria() const;
    
    /** @brief Consultora de la finalizacion del torneo
     * \pre: cierto
     * \post: Devuelve true si se ha jugado una edicion de este torneo
     */
    bool se_ha_jugado() const;
    
private:
    /** @brief Identificador de la categoria del torneo por numero
     */
    int num_categoria;
    
    /** @brief Identificador de la categoria del torneo por numero
     */
    string categoria;
    
    /** @brief Vector con los nombres de los jugadores y los puntos ganados al finalizar el torneo, ordenado por orden del ranking al iniciar el torneo
     */
    vector<pair<string,int>> vi;
    
    /** @brief Arbol binario que representa un torneo de tennis, se usa tanto para los emparejamientos como para los resultados,
     * tiene un int para identificar el jugador y un resultado string para identificar quien ha ganado
     */
    BinTree<pair<int,string>> arbol;
    
    /** @brief Mapa con string y int que usaremos de historial para almacenar los nombres y puntos de los jugadores participantes
     * en la edicion anterior del torneo si la hay
     */
    map<string,int> hist;
    
    /** @brief Lectura de los jugadores inscritos en el torneo
     * \pre: Se encuentran en el canal estandar de entrada una secuencia de strings
     * \post: Se anaden al torneo los jugadores indicados por los enteros leidos
     */
    void leer_insiripciones(Cjt_jugador& cjug);
    
    /** @brief Funcion auxiliar para crear un arbol binario con la distribucion de los jugadores en un
     *  arbol binario segun los criterios del enunciado
     * \pre: cierto
     * \post: Devuelve un BinTree con los emparejamientos del torneo
     */
    BinTree<pair<int,string>> hacer_emparejamientos(int prof_max, pair<int,string> a, int prof, int n);
    
    /** @brief Escribe las hojas del arbol binario con el formato del enunciado
     * \pre: cierto
     * \post: Se escriben las hojas del arbol y su correspondiente nombre en el metodo de salida
     */
    static void escribir_arbol_empar(const BinTree<pair<int,string>>& a, const vector<pair<string,int>>& vi);
    
    /** @brief Funcion que lee una serie de strings y los acopla a nodos del arbol
     * \pre: Se encuentran en el canal estandar de entrada una secuencia de strings
     * \post: Se ha modificado el arbol y todas las estadisticas de los jugadores han sido actualizadas
     */
    static void leer_ganadores(BinTree <pair<int,string>>& a, Cjt_jugador& cjug, Cjt_categoria& cats, int prof, vector<Jug>& vstats, vector<pair<string,int>>& vi, map<string,int>& historial, int num_categoria);
    
    /** @brief Escribe el cuadro de resultados del torneo
     * \pre: cierto
     * \post: Se escribe el cuadro en canal estandar de salida
     */
    static void escribir_cuadro_resultados(const BinTree<pair<int,string>>& a, const vector<pair<string,int>>& vi);
    
    /** @brief Escribe los jugadores que han participado y cuantos puntos han ganado 
     * \pre: cierto
     * \post: Se escribe en el metodo de salida los jugadores que han ganado puntos en el torneo,
     * en el orden del ranking en el momento de inciar el torneo
     */
    static void listar(const vector<pair<string,int>>& vi);
    
    /** @brief Funcion que escoge ganadores y modifica estadisticas
     * \pre: El string de resultados es del formato correcto
     * \post: Devuelve true si gana el jugador identificado por l, false si gana r, las estadisticas de ambos jugadores han sido almacenadas
     */
    static bool string_reader(const string& a, int l, int r, vector<Jug>& vstats);
    
    /** @brief Funcion que resetea los parametros del private para que no se produzcan errores en ediciones siguientes del torneo
     * \pre: cierto
     * \post: Vector de jugadores vacio, arbol vacio
     */
    void limpiar();
};
#endif
