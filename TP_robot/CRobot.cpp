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
    cout << "Je vien de etre initilize.\n";
}

CRobot::~CRobot(){
    ;
}

////////////////////
// Public Methods //
////////////////////
void CRobot::prendre_objet(){
    show_steps_to_goal(true);
}

void CRobot::deplacer(int deplacement){
    printf("TODO");
    //show_steps_to_goal(true);
}

void CRobot::trouver_chemin(int fin_x, int fin_y){
    algorithm_dijkstra.set_graph(salle.m_carte_de_la_salle);
    algorithm_dijkstra.set_start_node(m_coordonee_robot_y*50+m_coordonee_robot_x);
    algorithm_dijkstra.set_goal_node(fin_y*50+fin_x);
    algorithm_dijkstra.launch_algorithm();

    cout << "********************DEBBUGING ********************\n";
    show_bool_map(graph_representation);
    cout << "***************************************************\n";
    cout << "Testing dijkstra from node %d to %d.\n",start_node, goal_node);
    cout << "***************************************************\n";
    show_steps_to_goal(true);
    cout << "***************************************************\n";
    show_data_members();
    cout << "***************************************************\n";
}

int CRobot::get_distance(){
    return algorithm_dijkstra.distance_to_goal;
}

/**

Le robot nous dira «Voici votre objet, souhaitez-vous un autre objet de cette salle? Tapez Y si oui, tapez N si non.»
[Saisie choix utilisateur]
Si l’utilisateur dit oui la boucle recommence, si l’utilisateur dit non le robot dit «D’accord, fin de la recherche» et le programme se fermera.

Limites: Si l’utilisateur introduit un caractère incorrect alors le robot affiche le message «Saisie incorrecte, veuillez recommencer» et il répète la question.
 */
void CRobot::launch(){
    // Demander quelle salle
    salle.m_nom_fichier_carte_original = demander_nom_ficher_carte();
    // Demander quelle est le objet
    int id_obj = demander_ID_objet();
    for (int i = 0; i < salle.qnt; i++) {
         if(salle.m_liste_des_objets[i].m_ID == id_obj){
             objet_a_chercher = salle.m_liste_des_objets[i];
             break;
         }
    }
    objet_a_chercher.get_description();
    // Le terminal affichera ensuite un plan de la salle
    salle.show_room();
    //  Trajet
    //trouver_chemin(objet_a_chercher.m_Coord_X, objet_a_chercher.m_Coord_Y);
}

/**
 * Asks with 'cout' and 'cin' quelle est le nom ficher txt
 * @return ID
 */
string CRobot::demander_nom_ficher_carte(){
    int numero_salle;
    cout << "**************************************************\n";
    cout << "Dans quelle salle voulez-vous que je me déplace?\n";
    cout << "(Tapez 1 pour la salle 1, tapez 2 pour la salle 2 ou tapez 3 pour la salle 3.)\n";
    cout << "Veuillez n’en choisir que une.\n";
    cout << "Appuyez: ";
    cin >> numero_salle;

    string salle_nom;
    switch (numero_salle) {
        case 1:
        salle_nom = "salle1.txt";
        break;
        case 2:
        salle_nom = "salle2.txt";
        break;
        case 3:
        salle_nom = "salle3.txt";
        break;
        default:
        cout << "**************************************************\n";
        cout << "Cette salle n'existe pas!\n";
        cout << "**************************************************\n";
        exit(0);
        salle_nom = "None";
    }
    cout << "Tu as choisi la salle: " << salle_nom << "\n";
    cout << "**************************************************\n";
    return salle_nom;
}

/**
 * Asks with 'cout' and 'cin' quelle est le ID
 * @return ID
 */
int CRobot::demander_ID_objet(){
    /**
     * Il va ensuite demander:
     «Tapez le ID de l’objet que vous voulez que je prenne:
     NOM_OBJET_1 – ID_OBJET_1
     NOM_OBJET_2 – ID_OBJET_2
     NOM_OBJET_3 – ID_OBJET_3
     NOM_OBJET_4 – ID_OBJET_4
     NOM_OBJET_5 – ID_OBJET_5
     Veuillez n’en choisir que un.»
     	[Saisie ID de l’objet]
     */
    int id_objet;
    cout << "Tapez le ID de l’objet que vous voulez que je prenne:\n";
    salle.show_objet_list();
    cout << "Appuyez: ";
    cin >> id_objet;
    cout << "Tu as choisi l'objet: " << id_objet << "\n";
    return id_objet;
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
