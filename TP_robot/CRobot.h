CRobot

Données membres :
int m_coordonee_robot_x
int m_coordonee_robot_y
CSalle salle
int * deplacements
CObjet objet_a_chercher

Fonctions membres :
void  CRobot( )
virtual ~CRobot( )
void prendre_objet( )
void deplacer(int deplacement)
void trouver_chemin(int fin_x, int fin_y)
int get_distance( )
void launch( )
string demander_nom_ficher_carte( )
int demander_ID_objet( )
void executer_chemin( )
void trouver_chemin_retour( )
