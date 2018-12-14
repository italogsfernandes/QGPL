/* ************************************************************************** */
/** CRobot Class Implementation
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
 *    CRobot.cpp
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
#include "CRobot.h"

/////////////////
// Constructor //
/////////////////
CRobot::CRobot(){
    m_coordonee_robot_y = 0;
    m_coordonee_robot_x = 0;
    salle = CSalle();
    objet_a_chercher = CObjet();
}

CRobot::~CRobot(){
    ;
}

////////////////////
// Public Methods //
////////////////////
void CRobot::prendre_objet(){
    printf("TODO");
}

void CRobot::deplacer(int deplacement){
    printf("TODO");
}

void CRobot::trouver_chemin(int fin_x, int fin_y){
    printf("TODO");
}

int CRobot::get_distance(){
    printf("TODO");
}

void CRobot::launch(){
    printf("TODO");
}

string CRobot::demander_nom_ficher_carte(){
    printf("TODO");
}

int CRobot::demander_ID_objet(){
    printf("TODO");
}

void CRobot::executer_chemin(){
    printf("TODO");
}

void CRobot::trouver_chemin_retour(){
    printf("TODO");
}


/*******************************************************************************
 End of File
*/
