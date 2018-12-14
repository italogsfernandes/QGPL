/* ************************************************************************** */
/** CRobot Class Header
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
 *    CRobot.h
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
#ifndef CROBOT_H
#define CROBOT_H
//////////////
// Includes //
//////////////
#include <string.h>
#include "CSalle.h"
#include "CObjet.h"

///////////
// Class //
///////////
class CRobot {
private:
    ////////////////////
    // Portee Private //
    ////////////////////
    int m_coordonee_robot_y;
    int m_coordonee_robot_x;
    CSalle salle;
    int deplacements[2500];
    CObjet objet_a_chercher;

public:
    //////////////////
    // Porte Public //
    //////////////////
    void prendre_objet();
    void deplacer(int deplacement);
    void trouver_chemin(int fin_x, int fin_y);
    int get_distance();
    void launch();
    string demander_nom_ficher_carte();
    int demander_ID_objet();
    void executer_chemin();
    void trouver_chemin_retour();
    CRobot ();
    virtual ~CRobot ();
};
#endif
/*******************************************************************************
 End of File
*/
