/* ************************************************************************** */
/** CSalle Class Header
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
