/* ************************************************************************** */
/** CTest Class Header
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
 *    CTest.h
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
#ifndef CTEST_H
#define CTEST_H
//////////////
// Includes //
//////////////
#include <stdio.h>          // Printing messages with prinf

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
