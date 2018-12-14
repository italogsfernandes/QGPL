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
#include "CSalle.h"

/////////////////
// Constructor //
/////////////////
CSalle::CSalle(){
}

CSalle::~CSalle(){
    ;
}

////////////////////
// Public Methods //
////////////////////
/*
void CRobot::demander_ID_objet(){
    int id_objet;
    cout << "Tapez le ID de l’objet que vous voulez que je prenne:\n";
    salle.show_objet_list();
}*/

void CSalle::show_objet_list(){
    cout << "Helene est en train de faire ça\n";
    for (int i = 0; i < qnt_obj; i++) {
        m_liste_des_objets[i].get_description();
    }
}
/*
void CObjet::get_description(){
    cout << m_ID << " - " << m_nom_objet << " - " << m_Abreviation << "\n";
}
*/
/////////////////////
// Private Methods //
/////////////////////


/*******************************************************************************
 End of File
*/
