/** @file jugador.hh
    @brief Especificación de la clase Jugador
*/
#ifndef JUGADOR_HH_
#define JUGADOR_HH_

#ifndef NO_DIAGRAM
#include <iostream>
using namespace std;
#endif


/** @class Jugador
    @brief Representa un Jugador del circuito de tennis.
    El jugador tiene ranking y todas las estadisticas resultantes de los torneos en los que ha participado.
*/
class Jugador {
public:

    //constructoras
        
    /** @brief Constructora de Jugador
        \pre: cierto
        \post: Crea un jugador sin nombre y con 0 puntos
    */
    Jugador();

    //consultoras
    
    /** @brief Consultora de puntos de jugador
     * \pre: cierto
     * \post: Devuelve los puntos del p.i
     */
    int consultar_puntos() const;
    
    /** @brief Consultora la posicion del p.i en el ranking
     * \pre: cierto
     * \post: Devuelve la posicion de este jugador en el ranking
     */
    int consultar_posicion() const;
    
    /** @brief Consultora la posicion del p.i en el ranking
     * \pre: cierto
     * \post: Devuelve la posicion de este jugador en el ranking
     */
    int consultar_torneos() const;
    
    
    //modificadoras
    
    /** @brief Modificadora de estadisticas de jugador
        \pre: cierto
        \post: Las estadistcias del p.i han sido actualizadas
    */
    void modificar_stats(int punt, int pg, int pp, int sg, int sp, int jg, int jp, bool t);
    
     /** @brief Modificadora de la posicion de jugador
     *  \pre: cierto
     *  \post: Posicion del parametro implicito es p
     */
    void modificar_posicion(int p);
    
    //lectura y escritura
    
    /** @brief Consultora de todos los datos del jugador
     * \pre: cierto
     * \post: Se escriben los datos del parametro implicito en el medio de salida
     */
    void consultar_jugador() const;


private:
    /** @brief Puntos del jugador
     */
    int puntos;
    
    /** @brief Posicion en el ranking del jugador
     */
    int posicion;
    
    /** @brief Numero de torneos disputados
     */
    int torneos;
    
    /** @brief Partidos ganados por el jugador
     */
    int partidos_ganados;
    
    /** @brief Numero de partidos perdidos por el jugador
     */
    int partidos_perdidos;
    
    /** @brief Numero de sets ganados por el jugador
     */
    int sets_ganados;
    
    /** @brief Numero de sets perdidos por el jugador
     */
    int sets_perdidos;
    
    /** @brief Numero de juegos ganados por el jugador
     */
    int juegos_ganados;
    
    /** @brief Numero de juegos perdidos por el jugador
     */
    int juegos_perdidos;
};
#endif
