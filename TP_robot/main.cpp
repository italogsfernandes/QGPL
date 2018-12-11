/* ************************************************************************** */
/** Main Source File
 *  #Entreprise
 *    UCBL1 - Polytech - QGPL
 *  #Équipe
 *    John Doe1
 *    John Doe2
 *    John Doe3
 *    John Doe4
 *  #Création
 *    John Doe1 - Date
 *  #Nom de fichier
 *    CDijkstra.cpp
 *  #Résumé
 *    Lorem ipsum dolor sit amet, consectetur adipisicing elit.
 *  #Description
 *    Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod
 *    tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim
 *    veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea
 *    commodo consequat. Duis aute irure dolor in reprehenderit in voluptate
 *    velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint
 *    occaecat cupidatat non proident, sunt in culpa qui officia deserunt
 *    mollit anim id est laborum.
 */
/* ************************************************************************** */
//////////////
// Includes //
//////////////
#include <iostream>         // comentar as bibioteca
#include "CDijkstra.h"      //
using namespace std;

////////////////////
// Main Function  //
////////////////////
int main(){
    // Instanciating a object of dijkstra class
    CDijkstra example_dijkstra_algo;
    example_dijkstra_algo = CDijkstra();
    example_dijkstra_algo.global_test();

    // if you are unsure about the result of get_neighbors uncomment the next
    // line to execute a manual test:
    //test_find_neighbors();
	return 0;
}
/*******************************************************************************
 End of File
*/
