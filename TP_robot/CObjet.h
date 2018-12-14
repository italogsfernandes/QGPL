/* ************************************************************************** */
/** CObjet Class Header
 *  #Entreprise
 *    UCBL1 - Polytech - QGPL
 *  #Équipe
    LY Hélène
    RUIZ CANADA Paula
    SAMPAIO FERNANDES Italo Gustavo
    IRUMVA Bella

 *  #Nom de fichier
 *    CObjet.h
 *  #Résumé
 *    Identification de l'objet et sa position.
 *  #Description

 */
/* ************************************************************************** */
#ifndef COBJET_H
#define COBJET_H
//////////////
// Includes //
//////////////
#include <string>
#include <iostream>
using namespace std;

///////////
// Class //
///////////
class CObjet {
private:
    //////////////////
    // Private Data //
    //////////////////

    /////////////////////
    // Private Methods //
    /////////////////////
protected:

public:
    /////////////////
    // Public Data //
    /////////////////
    char m_Abreviation; // la représentation visuelle de l'objet  sur l' interface type string :
    int m_ID; //le numéro unique pour identifier chaque objet   type int
    int m_Coord_X;//la coordonnée X de l'objet  dans la salle type int
    int m_Coord_Y; //la coordonnée Y de l'objet  dans la salle type int
    bool m_il_est_pris; //pour indiquer  si oui ou non l'objet est pris  type bool
    string m_nom_objet;

    ////////////////////
    // Public Methods //
    ////////////////////
    CObjet ();
    virtual ~CObjet ();
    void get_description();


};
#endif
/*******************************************************************************
 End of File
*/
