/** @file cjt_categoria.hh
 * @brief Especificacion de la clase Cjt_categoria
 */

#ifndef CJT_CATEGORIA_HH_
#define CJT_CATEGORIA_HH_

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
using namespace std;
#endif

/** @class Cjt_categoria
    @brief Representa el conjunto de categorias del circuito.
    Hay C categorias y cada categoria tiene K niveles. Los puntos obtenidos en el torneo vienen determinados por el nivel y la categoria.
*/

class Cjt_categoria {
    
public:
    
    //constructora
    /** @brief Crea un Cjt_categoria vacio
     * \pre cierto
     * \post Se ha creado un conjunto de categorias vacío
    */
    Cjt_categoria();
    
    //consultoras
    
    /** @brief Consultora de los puntos otrogados al jugador que llega al nivel n en el torneo en categoria c
     * \pre: n y c existentes en el p.i
     * \post: Devuelve los puntos correspondientes a nivel n y categoria c
     */
    int puntos_obtenidos(int c, int n) const;
    
    /** @brief Consultora del nombre de la categoria numero c
     * \pre: cierto
     * \post: retorna el nombre de la categoria del p.i indicada por c
     */
    string nombre(int c) const;
    
    /** @brief Consultora de el numero de categorias
     * \pre: cierto
     * \post: Retorna el numero de categorias del p.i
     */
    int consultar_categoria_max() const;
    
    //lectura y escrtura
    
    /** @brief Lee el cjt_categoria
     * \pre: Se encuentran en el canal estandar de entrada una secuencia con los atributos de las categorias
     * \post: cjt_categoria con datos de entrada
     */
    void leer_cjt_categoria();
    
    /** @brief Lista el cjt de categorias
     * \pre: cierto
     * \post: Escribe por orden creciente del nombre, el nombre y la puntuacion por niveles de cada categoria
     */
    void listar_categorias() const;
    
private:
    /** @brief Vector que almacena los nombres de las categorias, ordenados por orden de numero de categoria
     */
    vector<string> nombres_categorias;
    
    /** @brief Matriz que almacena las categorias por filas y los puntos por niveles en cada categoria
     */
    vector< vector <int> > cjt_cat;
    
};
#endif
