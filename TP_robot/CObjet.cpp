/* ************************************************************************** */
/** CObjet Class Implementation
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
//////////////
// Includes //
//////////////
#include "CObjet.h"

/////////////////
// Constructor //
/////////////////
CObjet::CObjet ()
{
    m_Abreviation = '0';
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
    cout << m_Abreviation << " - " << m_nom_objet << " - " << m_ID << "\n";
}

/*******************************************************************************
 End of File
*/
