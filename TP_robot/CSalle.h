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
#include <fstream>
#include <sstream>
#include "CObjet.h"
using namespace std;

///////////
// Class //
///////////
class CSalle {
private:
    /* data */
    string m_nom_fichier_carte_modifie;
    string m_representation_visuel;

public:
    bool m_carte_de_la_salle[50*50];
    string m_nom_fichier_carte_original;
    CObjet m_liste_des_objets[100];
    int m_quantite_des_objets;
    CSalle ();
    virtual ~CSalle ();
    void lire_room();
    void show_room();
    void read_object_list();
    void show_object_list();
    void enregistrer_carte_modifie();
};

#endif
/*******************************************************************************
 End of File
*/
