/** @file cjt_jugador.hh
    @brief Especificación de la clase Cjt_jugador
*/

#ifndef _CJT_JUGADOR_HH_
#define _CJT_JUGADOR_HH_
#include "jugador.hh"

#ifndef NO_DIAGRAM
#include <vector>
#include <algorithm>
#include <map>
#endif


/** @class Cjt_jugador
    @brief Representa el conjunto de jugadores que participa en el circuito. Tiene un ranking ordenado por puntos.
    Se puede identificar los jugadores por su nombre dentro del conjunto o por posicion en el ranking.
*/
class Cjt_jugador {

public:
    //constructoras

    /** @brief Crea un Cjt_jugador vacío;
     * \pre: cierto
     * \post: se ha creado un conjunto de jugadores vacio
     */    
    Cjt_jugador();
    
    //modificadoras
    
    /** @brief Añade un nuevo jugador al p.i si se dan las condiciones
     * \pre: cierto
     * \post: Si existe un jugador con el mismo nombre escribe un mensaje de error, en caso contrario anade el jugador al p.i
     */
    void nuevo_jugador(string nombre);
    
    
    /** @brief Quita un jugador del cjt_jugador
     * \pre: cierto
     * \post: Se elimina el jugador identificado por nombre del p.i,
     *  si no existe se escribe un mensaje de error
     */
    void quitar_jugador(string nombre);
    
    /** @brief Ordena el ranking acorde a los puntos de cada jugador
     * \pre: cierto
     * \post: ranking ordenado por puntos
     */
    void ordenar_por_puntos();
    
    /** @brief Modifica las estadistcas del jugador identificado por nombre
     * \pre: cierto
     * \post: Las estadisticas del jugador han sido actualizadas
     */
    void modificar_stats(string nombre, int punt, int pg, int pp, int sg, int sp, int jg, int jp, bool t);
    
    //lectura y escritura
    
    /** @brief Lectura del cjt de jugadores
     * \pre: Se encuentran en el canal estandar de entrada una secuencia de strings
     * \post: El p.i de jugadores con los datos de entrada
     */
    void leer_cjt_jugador();
    
    
     /** @brief Lista por orden de ranking la posicion, el nombre y los puntos de cada jugador
     * \pre: cierto
     * \post: Se escriben los datos de los jugadores del conjunto en el medio de salida por orden de puntos
     */
    void listar_ranking();
    
    /** @brief Consultora de todos los datos de cada jugador en el conjunto
     * \pre: cierto
     * \post: Se escriben los datos de los jugadores del conjunto en el medio de salida por orden alfabetico
     */
    void listar_jugadores();
    
    /** @brief Consultora de todos los datos del jugador nombre
     * \pre: jugador valido
     * \post: Se escriben los datos del parametro implicito en el medio de salida
     */
    void consultar_jugador(string nombre) const;
    
    /** @breif consultora del nombre del jugador en la posicion pos
     * \pre: Pos < numero de jugadores y >= 1
     * \post: Devuelve el nombre del juegador en la posicion indicada
     */
    string consultar_nombre(int pos) const;
    
    /** @breif Consultora del numero de torneos del jugador identificado por nombre
     * \pre: cierto
     * \post: Devuelve el numero de torneos del jugador identificado por nombre, si no existe el jugador devuelve 0
     */
    int consultar_torneos(string nombre) const;
    
private:
    /** @brief Mapa que almacena los jugadores en orden alfabetico
     */
    map<string,Jugador> mj;
    
    /** @brief Vector que contiene el nombre de los jugadores y su puntos, ordenados por orden de puntuacion de mayor a menor
     */
    vector< pair<string,int> > rnk;
    
    /** @brief Consultora de la existencia del jugador indicado por nombre en el parametro implicito
     * \pre: cierto
     * \post: Retorna true si existe, false en caso contrario
     */
    bool contiene(string nombre) const;
    
    /** @brief Anade un jugador al cjt_jugador al final del ranking
     * \pre: No existe un jugador con el mismo nombre en el p.i
     * \post: el parametro implicito ahora tiene el jugador identificado por nombre
     */
    void anadir_jugador(string nombre);
    
    /** @brief Funcion auxiliar que desplaza una posicion hacia delante el vector a partir del jugador identificado por nombre
     * \pre: cierto
     * \post: El jugador está al final del ranking
     */
    void desplazar(string nombre);
    
    /** @brief Funcion static que se usa como comparador para el sort
     * \pre: cierto
     * \post: Retorna true si a.second es mayor que b.second
     */
    static bool cmp(pair<string,int> a, pair<string,int> b);
};
#endif
