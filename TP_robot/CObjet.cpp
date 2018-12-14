/* ************************************************************************** */
/** CObjet Class Implementation
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
 *    CObjet.cpp
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
#include "CObjet.h"

/////////////////
// Constructor //
/////////////////
CObjet::CObjet ()
{
    m_Abreviation = "DEFAULT";
    m_ID = 0;
    m_Coord_X = 0;
    m_Coord_Y = 0;
    m_il_est_pris = 0;
}

CObjet::~CObjet ()
{

}

////////////////////
// Public Methods //
////////////////////
void CObjet::get_description()
{
    //On va lire m_liste_des_objets qui a été lu par CSalle
    cout << m_Abreviation << "-" << m_nom_objet << "-" << m_ID << "\n";
}

/*******************************************************************************
 End of File
*/
