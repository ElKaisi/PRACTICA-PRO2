/** @file cjt_torneo.hh
 * @brief Especificación de la clase Cjt_torneo
 */
#ifndef _CJT_TORNEO_HH_
#define _CJT_TORNEO_HH_
#include "torneo.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
using namespace std;
#endif


/** @class Cjt_torneo
    @brief Representa el conjunto de torneos de tenis del circuito.
    Cada torneo se identifica por su nombre dentro del conjunto.
*/

class Cjt_torneo {
public:
    
    //constructoras
    /** @brief Constructora de Cjt_torneo
     * \pre: cierto
     * \post: Se ha creado un Cjt_torneo vacio
     */
    Cjt_torneo();
    
    //modificadoras
    
    /** @brief Anade el torneo con su nombre y categoria
     * \pre: cierto
     * \post: Se anade el torneo si no existe y se escribe el numero de torneos, en caso contrario se escribe un mensaje de error
     */
    void nuevo_torneo(string nombre, int c, Cjt_categoria& cats);

    /** @brief Quita el torneo con nombre
        \pre: cierto
        \post: el parametro implicito no tiene el torneo indicado por el nombre,
        y se restan las puntuaciones obtenidas en dicho torneo y se actualiza el ranking de jugadores
    */
    void quitar_torneo(string nombre, Cjt_jugador& cjug);
    
    /** @brief Elimina el los datos del jugador identificado por el nombre del historial
     * de todos los torneos en los que haya participado este
     * \pre: Cert
     * \post: Se ha eliminado del historial de todos los torneos en los que ha participado si es que ha participado en alguno
     */
    void eliminar_del_historial(string nombre, Cjt_jugador& cjug);
    
    //lectura y escritura
    
    /** @brief Lee el cjt acorde a los datos de entrada
     * \pre: Se encuentran en el canal estandar de entrada una secuencia strings e int
     * \post: cjt_torneo con datos de entrada
     */
    void leer_cjt_torneo(Cjt_categoria& cats);
    
    /** @brief Inicia el torneo identificado por nombre
     * \pre: cierto
     * \post: Se leen los jugadores y se confecciona y escribe el cuadro de emparejeamientos
     */
    void inciar_torneo(string nombre, Cjt_jugador& cjug);
    
    /** @brief Finaliza el torneo acorde al enunciado
     * \pre: Torneo existente, torneo inciado anteriormente
     * \post: Se leen los resultados, se produce e imprime el cuadro de resultados
     * y actualiza el ranking y estadisticas de los jugadores
     */
    void finalizar_torneo(string nombre, Cjt_jugador& cjug, Cjt_categoria& cats);
    
    /** @brief Escribe el cjt_torneo siguiendo el orden especificado por el enunciado
     * \pre: cierto
     * \post: se escribe n la salida
     */
    void listar_torneos() const;
    
private:
    /** @brief Mapa que almacena los torneos del circuito por orden alfabetico
     */
    map<string,Torneo> mt;
    
    /** @brief Anade el torneo t
        \pre: El p.i no contiene un torneo con el mismo nombre
        \post: el parametro implicito ahora contiene el torneo t y se escribe el numero de torneos actual
    */
    void anadir_torneo(string nombre, int c, Cjt_categoria& cats);
    
    /** @brief Consultora de la existencia del torneo identificado por nombre en el parametro implicito
     * \pre: cierto
     * \post: retorna true si existe, false en caso contrario
     */
    bool contiene(string nombre) const;
    
    /** @brief Consultora del numero de torneos en el conjunto
     * \pre: cierto
     * \post: devuelve el numero de torneos en el conjunto
     */
    int num_torneos() const;
};
#endif
