/* ************************************************************************** */
/** CTest Class Header
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
#ifndef CTEST_H
#define CTEST_H
//////////////
// Includes //
//////////////
#include <stdio.h>          // Printing messages with prinf
#include "CRobot.h"

//////////////
// Defines  //
//////////////


///////////
// Class //
///////////
class CTest {
private:
    ////////////////////
    // Portee Private //
    ////////////////////
public:
    //////////////////
    // Porte Public //
    //////////////////
    int test_lire_carte_et_afficher();
    int test_chercher_cinq_objets();
    int test_chercher_object_en_contournant_un_obstacle();
    int test_introduction_character_incorrect();
    int lancer_tests();
    int test_executer_programme_3min();
    int test_meme_resultats();
    CTest ();
    virtual ~CTest ();
};
#endif
/*******************************************************************************
 End of File
*/
