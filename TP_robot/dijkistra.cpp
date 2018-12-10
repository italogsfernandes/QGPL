
/**
 * DIJKISTRA PSEUDOCODE
 * function Dijkstra(Graph, source):
 *      create vertex set Q
 *
 *      for each vertex v in Graph:             // Initialization
 *          dist[v] ← INFINITY                  // Unknown distance from source to v
 *          prev[v] ← UNDEFINED                 // Previous node in optimal path from source
 *          add v to Q                          // All nodes initially in Q (unvisited nodes)
 *
 *      dist[source] ← 0                        // Distance from source to source
 *
 *      while Q is not empty:
 *          u ← vertex in Q with min dist[u]    // Node with the least distance
 *                                              // will be selected first
 *          remove u from Q
 *
 *          for each neighbor v of u:           // where v is still in Q.
 *              alt ← dist[u] + length(u, v)
 *              if alt < dist[v]:               // A shorter path to v has been found
 *                  dist[v] ← alt
 *                  prev[v] ← u
 *
 *      return dist[], prev[]
 */
//////////////
// Includes //
//////////////
#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>
#include <math.h>
#include <locale.h>

/////////////
// DEFINES //
/////////////
#define p 1
#define t 2
#define b 3
#define c 4
#define ra 5
#define re 6

#define nodes 100
#define linhas 10
#define colunas 10

///////////////
// Functions //
///////////////
void test_dijkistra();

////////////////////////
// Auxiliar Functions //
////////////////////////
/*
void erro();
char info(int i,int j);
void preenchertab(char *locais);
int potencia(double num, int ele);
void carregargrifo(char *locais, int *custos);
void obterdirecoes(int *origem, int *destino);
int dijkstra(int origem,int destino, int *custos, int *caminho, int *casas);
int convertenode(int *caminho, int *passos, int qnt);

//Mostradores
void mostrarmovs(int origem,int movs,int destino,int *passos);
void mostrartab(char *locais);
void mostrartabcustos(char *locais, int *custos);
void mostrartabcustosvolta(char *locais, int *custos);
void mostrarcaminho(int *caminho, int preco, int qnt);

//principais
void inicializar();
int executando(int *custos, int *caminho, char *locais,int de,int para);
void atualizartabinfos(int de,int para,char *locais,int *custos);
//void desvio(int *caminho, int *custos, int *locais, int de, int para)
void movendo(int *caminho,int *passos,int qnt,int de,int para,char *locais,int *custos);

//int tentdedesvio=0
*/
/////////////////////
void initiate_dijkstra();
void test_dijkistra();
void show_bool_map(bool * map_to_show, uint16_t qnt_lines, uint16_t qnt_columns);
////////////////////
// Main Function  //
////////////////////
int main(){
    printf("hora do show porra!\n");
    initiate_dijkstra();
	test_dijkistra();
	return 0;
}

//////////////////////////////
// Functions Implementation //
//////////////////////////////
void initiate_dijkstra(){
    bool example_map[7][7] = { {1, 1, 1, 1, 1, 1, 1},  // line 0
                    {1, 1, 0, 0, 1, 0, 1},  // line 1
                    {1, 0, 0, 1, 1, 0, 1},  // line 2
                    {1, 1, 0, 0, 0, 0, 1},  // line 3
                    {1, 1, 1, 1, 0, 0, 1},  // line 4
                    {1, 0, 0, 0, 0, 0, 1},  // line 5
                    {1, 0, 1, 1, 1, 1, 1}}; // line 6
    show_bool_map((bool *) example_map, 7, 7);

    //uint16_t weight_matrix[7*7][7*7];

}

void dijkstra_on_grid(uint32_t start_node, uint32_t goal_node){
    uint32_t qnt_nodes = 7*7;
    uint32_t qnt_lines = 7;
    uint32_t qnt_columns = 7;

    /////////////////////////////////////////////////////
    // Variables to allow the dijkstra algorith to run //
    /////////////////////////////////////////////////////
    // Distance between the start and each node:
    uint32_t distances[qnt_nodes];
    uint32_t proposed_distance;
    // The next node that you shold go for each node:
    int32_t next_node[qnt_nodes];
    // Holds wich nodes are already verified and with are'nt.
    bool verified_nodes[qnt_nodes];
    // Indicates the node which are being analysed
    uint32_t current_node;
    // Indicates the neighbors to each node
    uint32_t neighbors[4]; // maximum 4 neighbors considering a grid layout
    uint32_t qnt_neighbors; // some nodes could have less than 4 neighbors
    // Indicates the currently neighbor which are being analysed
    uint32_t neighbor;

    ////////////////////////////////////////////////////////////////////////
    // Sets the distances between the origin end each node to infinite //
    // Sets no next node to each node                                  //
    // Sets the distance between the origin and itself to 0               //
    ////////////////////////////////////////////////////////////////////////
    for (uint16_t i = 0; i < qnt_nodes; i++) {
        distances[i] = 1 << 30; // Infinite (considering the worst scenary)
        next_node[i] = -1; // There is no next node
    }
    distances[start_node] = 0; // distance to stay in the same place

    ////////////////////////////////////////////////////////
    // Verifing each node and finding minimun distance //
    ////////////////////////////////////////////////////////
    while(  next_node[current_node] != goal_node
         && are_all_nodes_verified() == false){
        current_node = get_node_with_min_distance(nodes_not_verfied); //and node valides (not walls)
        get_neighbors(current_node, graph_representation, neighbors, qnt_neighbors);
        // for each neighbor of current_node
        for (uint32_t i = 0; i < qnt_neighbors; i++){
            neighbor = neighbors[i];
            // Weight between a node and its neighbor is always 1 unity
            proposed_distance = distances[current_node] + 1;
            // if the distance to neighbor are greater than the distance comming from the current_node
            if (distances[neighbor] > proposed_distance){
                distances[neighbor] = proposed_distance;
                next_node[current_node] = neighbor;
            }
        }
        // Set this node as verified
        verified_nodes[current_node] = true;
    }
}

//TODO: NEED TO TEST THIS
/* With a grid like this one:
 *  0  1  2  3  4
 *  5  6  7  8  9
 * 10 11 12 13 14
 * 15 16 17 18 19
 * 20 21 22 23 24
 * Where: 12 and 23 are barriers
 * get_neighbors(current_node =  0) --> 1, 5
 * get_neighbors(current_node =  4) --> 3, 9
 * get_neighbors(current_node = 20) --> 15, 21
 * get_neighbors(current_node = 24) --> 19
 * get_neighbors(current_node =  2) --> 1, 3, 7
 * get_neighbors(current_node = 10) --> 5, 11, 15
 * get_neighbors(current_node = 14) --> 9, 13, 19
 * get_neighbors(current_node = 22) --> 17, 21
 * get_neighbors(current_node = 16) --> 11, 15, 17, 21
 * get_neighbors(current_node = 11) --> 6, 10, 16
 * get_neighbors(current_node = 12) --> 7, 11, 13, 17
 * get_neighbors(current_node = 13) --> 8, 14, 18
 */
void get_neighbors( uint32_t current_node, uint32_t *graph_representation,
                    uint32_t *neighbors, uint32_t qnt_neighbors){
    /* Possible Neighbors in this solution
     * North, East, South and West:
     *     N
     *  W--|--E
     *     S
     */
    int32_t n_neighbor, s_neighbor, w_neighbor, e_neighbor;
    n_neighbor = current_node - qnt_columns;
    s_neighbor = current_node + qnt_columns;
    w_neighbor = current_node - 1;
    e_neighbor = current_node + 1;

    //////////////////
    //Grid boundary //
    //////////////////
    // In the first line there are no north
    if(current_node < qnt_columns){
        n_neighbor = -1;
    }
    // In the last line there are no south
    if(current_node >= (qnt_nodes - qnt_columns)){
        s_neighbor = -1;
    }
    // In the first column there are no west
    if(current_node % qnt_columns == 0){
        w_neighbor = -1;
    }
    // In the last column there are no east
    if(current_node % qnt_columns == (qnt_columns - 1)){
        e_neighbor = -1;
    }

    /////////////////////////////////////
    // Consulting Graph Representation //
    /////////////////////////////////////
    qnt_neighbors = 0;
    if(n_neighbor != -1 && graph_representation(n_neighbor) == 0){
        neighbors[qnt_neighbors] = n_neighbor;
        qnt_neighbors += 1;
    }
    if(s_neighbor != -1 && graph_representation(s_neighbor) == 0){
        neighbors[qnt_neighbors] = s_neighbor;
        qnt_neighbors += 1;
    }
    if(w_neighbor != -1 && graph_representation(w_neighbor) == 0){
        neighbors[qnt_neighbors] = w_neighbor;
        qnt_neighbors += 1;
    }
    if(e_neighbor != -1 && graph_representation(e_neighbor) == 0){
        neighbors[qnt_neighbors] = e_neighbor;
        qnt_neighbors += 1;
    }
}

void show_bool_map(bool *map_to_show, uint16_t qnt_lines, uint16_t qnt_columns){
    for (uint16_t i = 0; i < qnt_lines; i++) {
        for (uint16_t j = 0; j < qnt_columns; j++) {
            map_to_show[j+qnt_lines*i] ? printf(" x ") : printf("   ");
        }
        printf("\n");
    }
}
void test_dijkistra(){
	printf("Hello disgraça!\n");
}
