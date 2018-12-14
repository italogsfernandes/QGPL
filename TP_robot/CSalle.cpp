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
#include "CSalle.h"

/////////////////
// Constructor //
/////////////////
CSalle::CSalle()
{
    m_nom_fichier_carte_modifie = "NDEF";
    m_nom_fichier_carte_original = "NDEF";
    m_representation_visuel = "NDEF";
    m_quantite_des_objets = 0;
}

CSalle::~CSalle ()
{

}

////////////////////
// Public Methods //
////////////////////
void CSalle::lire_room()
{
    cout << "**************************************************\n";
    cout << "Je suis en train de lire la carte.\n";
    ifstream fileIN(m_nom_fichier_carte_original.c_str());
    string line;
    stringstream ss;

    int column = 0;
    int coodernee = 0;
    if (fileIN.is_open())
    {
        while (getline(fileIN,line))
        {
            ss << line << "\n";
            //cout << line << "\n";
            column += 1;
            for (int i = 0; i < 50; i++) {
                coodernee = column * 50 + i;
                if(line[i] == 'x'){ // obstacle
                    m_carte_de_la_salle[coodernee] = false;
                } else if(line[i] == 'R'){ //robot
                    m_carte_de_la_salle[coodernee] = true;
                } else if(line[i] == ' '){ //vide
                    m_carte_de_la_salle[coodernee] = true;
                } else { //objets
                    m_carte_de_la_salle[coodernee] = true;
                    for (int i = 0; i < m_quantite_des_objets; i++) {
                        if(m_liste_des_objets[i].m_Abreviation == line[i]){
                            m_liste_des_objets[i].m_Coord_X = i;
                            m_liste_des_objets[i].m_Coord_Y = column;
                            break;
                        }
                    }
                }
            }
        }
    } else {
        cout << "Unable to open file";
    }
    fileIN.close();
    m_representation_visuel = ss.str();
}
void CSalle::show_room()
{
    cout << m_representation_visuel;
}

void CSalle::show_object_list()
{
    cout << "**************************************************\n";
    cout << "List des objets:\n";
    for(int i=0; i<m_quantite_des_objets; i++)
    {
        m_liste_des_objets[i].get_description();
    }
    cout << "**************************************************\n";
}

void CSalle::read_object_list()
{
    stringstream ss;
    ss << "Objet_" << m_nom_fichier_carte_original;
    string nom_ficher_obj = ss.str();

    cout << "Je suis en train de lire: " << nom_ficher_obj << "\n";
    ifstream fileIN(nom_ficher_obj.c_str());
    char    var1, var4, var7, var10, var13;
    string  var2, var5, var8, var11, var14;
    int     var3, var6, var9, var12, var15;

    if (fileIN.is_open())
    {
        fileIN >> var1;
        fileIN >> var2;
        fileIN >> var3;
        fileIN >> var4;
        fileIN >> var5;
        fileIN >> var6;
        fileIN >> var7;
        fileIN >> var8;
        fileIN >> var9;
        fileIN >> var10;
        fileIN >> var11;
        fileIN >> var12;
        fileIN >> var13;
        fileIN >> var14;
        fileIN >> var15;
    } else {
        cout << "Unable to open file";
    }
    fileIN.close();

    m_liste_des_objets[0].m_Abreviation = var1;
    m_liste_des_objets[0].m_nom_objet = var2;
    m_liste_des_objets[0].m_ID = var3;

    m_liste_des_objets[1].m_Abreviation = var4;
    m_liste_des_objets[1].m_nom_objet = var5;
    m_liste_des_objets[1].m_ID = var6;

    m_liste_des_objets[2].m_Abreviation = var7;
    m_liste_des_objets[2].m_nom_objet = var8;
    m_liste_des_objets[2].m_ID = var9;

    m_liste_des_objets[3].m_Abreviation = var10;
    m_liste_des_objets[3].m_nom_objet = var11;
    m_liste_des_objets[3].m_ID = var12;

    m_liste_des_objets[4].m_Abreviation = var13;
    m_liste_des_objets[4].m_nom_objet = var14;
    m_liste_des_objets[4].m_ID = var15;

    m_quantite_des_objets = 5;
}

void CSalle::enregistrer_carte_modifie()
{

}

/////////////////////
// Private Methods //
/////////////////////


/*******************************************************************************
 End of File
*/
