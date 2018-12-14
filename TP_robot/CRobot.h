/* ************************************************************************** */
/** CRobot Class Header
*  #Entreprise
*    UCBL1 - Polytech - QGPL
*  #Équipe
   LY Hélène
   RUIZ CANADA Paula
   SAMPAIO FERNANDES Italo Gustavo
   IRUMVA Bella

*  #Résumé
*    Identification de l'objet et sa position.
*  #Description

*/
/* ************************************************************************** */
#ifndef CROBOT_H
#define CROBOT_H
//////////////
// Includes //
//////////////
#include <iostream>
#include <string>
#include "CSalle.h"
#include "CObjet.h"
#include "CDijkstra.h"
using namespace std;

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
    CDijkstra algorithm_dijkstra; //NOTE: ce nest pas au CDC

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
