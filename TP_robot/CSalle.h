/* ************************************************************************** */
/** CSalle Class Header
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
 *    CSalle.h
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
#ifndef CSALLE_H
#define CSALLE_H
//////////////
// Includes //
//////////////
#include <string>
#include <iostream>
using namespace std;

//////////////
// Defines  //
//////////////


///////////
// Class //
///////////
class CSalle {
private:
    /* data */
public:
    CSalle ();
    virtual ~CSalle ();
    //NOTE: change poir public
    string m_nom_fichier_carte_original;
    void show_objet_list();
};
#endif
/*******************************************************************************
 End of File
*/
