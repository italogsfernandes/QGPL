/* ************************************************************************** */
/** CRobot Class Implementation
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
#include "CRobot.h"

/////////////////
// Constructor //
/////////////////
CRobot::CRobot(){
    m_coordonee_robot_y = 48;
    m_coordonee_robot_x = 48;
    cout << "Je vien de etre initilize.\n";
}

CRobot::~CRobot(){
    ;
}

////////////////////
// Public Methods //
////////////////////
void CRobot::prendre_objet(){
    algorithm_dijkstra.show_steps_to_goal(true);
}

void CRobot::deplacer(int deplacement){
    printf("TODO");
    //show_steps_to_goal(true);
}

void CRobot::trouver_chemin(int fin_x, int fin_y){
    cout << "***************************************************\n";
    cout << fin_y*50+fin_x << "\n";
    cout << "***************************************************\n";

    algorithm_dijkstra.set_start_node(m_coordonee_robot_y*50+m_coordonee_robot_x);
    algorithm_dijkstra.set_goal_node(fin_y*50+fin_x);
    algorithm_dijkstra.launch_algorithm();

    cout << "********************DEBBUGING ********************\n";
    cout << "Testing dijkstra: " << algorithm_dijkstra.start_node << " - " << algorithm_dijkstra.goal_node << "\n";
    algorithm_dijkstra.show_data_members();
    cout << "***************************************************\n";
    algorithm_dijkstra.show_steps_to_goal(true);
    cout << "***************************************************\n";
    algorithm_dijkstra.show_data_members();
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
    salle.read_object_list();
    salle.lire_room();
    algorithm_dijkstra.set_graph(salle.m_carte_de_la_salle);
    // Demander quelle est le objet
    int id_obj = demander_ID_objet();
    for (int i = 0; i < salle.m_quantite_des_objets; i++) {
         if(salle.m_liste_des_objets[i].m_ID == id_obj){
             objet_a_chercher = salle.m_liste_des_objets[i];
             break;
         }
    }
    objet_a_chercher.get_description();
    objet_a_chercher.m_Coord_X = 4;
    objet_a_chercher.m_Coord_Y = 1;
    cout << objet_a_chercher.m_Coord_X << " - " << objet_a_chercher.m_Coord_Y << "\n";
    // Le terminal affichera ensuite un plan de la salle
    salle.show_room();
    //  Trajet
    trouver_chemin(objet_a_chercher.m_Coord_X, objet_a_chercher.m_Coord_Y);
    exit(0);
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
        salle_nom = "Salle1.txt";
        break;
        case 2:
        salle_nom = "Salle2.txt";
        break;
        case 3:
        salle_nom = "Salle3.txt";
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
    salle.show_object_list();
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
