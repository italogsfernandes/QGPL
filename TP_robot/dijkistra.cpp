
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
void show_bool_map(bool *map_to_show);
void show_distance_map(uint32_t *distances_to_show);
void show_steps_map(int32_t *steps_to_show);

void get_neighbors( uint32_t current_node, bool *graph_representation,
                    uint32_t *neighbors, uint32_t *qnt_neighbors);
void test_dijkistra();

void test_find_neighbors();

/////////////////////
//Global Variables //
/////////////////////
uint32_t qnt_lines = 7;
uint32_t qnt_columns = 7;
uint32_t qnt_nodes = qnt_lines*qnt_columns;
bool example_map[7*7];

bool debug_msgs_enabled = true;
////////////////////
// Main Function  //
////////////////////
int main(){
    printf("hora do show porra!\n");

    // if you are unsure about the result of get_neighbors uncomment the next
    // line to execute a manual test:
    //test_find_neighbors();

	test_dijkistra();
	return 0;
}

void test_find_neighbors(){
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
    qnt_lines = 5;
    qnt_columns = 5;
    qnt_nodes = 5*5;
    uint32_t neighbors[4];
    uint32_t qnt_neighbors;
    bool graph_representation[5*5] = {  0, 0, 0, 0, 0,
                                        0, 0, 0, 0, 0,
                                        0, 0, 1, 0, 0,
                                        0, 0, 0, 0, 0,
                                        0, 0, 0, 1, 0};

    printf("get_neighbors(current_node =  0) --> 1, 5\n");
    printf("neighbors of 0: ");
    get_neighbors(0, graph_representation, neighbors, &qnt_neighbors);
    for (size_t i = 0; i < qnt_neighbors; i++) {
        printf("%d ", neighbors[i]);
    }
    printf("\n\n");

    printf("get_neighbors(current_node =  4) --> 3, 9\n");
    printf("neighbors of 4: ");
    get_neighbors(4, graph_representation, neighbors, &qnt_neighbors);
    for (size_t i = 0; i < qnt_neighbors; i++) {
        printf("%d ", neighbors[i]);
    }
    printf("\n\n");

    printf("get_neighbors(current_node = 20) --> 15, 21\n");
    printf("neighbors of 20: ");
    get_neighbors(20, graph_representation, neighbors, &qnt_neighbors);
    for (size_t i = 0; i < qnt_neighbors; i++) {
        printf("%d ", neighbors[i]);
    }
    printf("\n\n");

    printf("get_neighbors(current_node = 24) --> 19\n");
    printf("neighbors of 24: ");
    get_neighbors(24, graph_representation, neighbors, &qnt_neighbors);
    for (size_t i = 0; i < qnt_neighbors; i++) {
        printf("%d ", neighbors[i]);
    }
    printf("\n\n");

    printf("get_neighbors(current_node =  2) --> 1, 3, 7\n");
    printf("neighbors of 2: ");
    get_neighbors(2, graph_representation, neighbors, &qnt_neighbors);
    for (size_t i = 0; i < qnt_neighbors; i++) {
        printf("%d ", neighbors[i]);
    }
    printf("\n\n");

    printf("get_neighbors(current_node = 10) --> 5, 11, 15\n");
    printf("neighbors of 10: ");
    get_neighbors(10, graph_representation, neighbors, &qnt_neighbors);
    for (size_t i = 0; i < qnt_neighbors; i++) {
        printf("%d ", neighbors[i]);
    }
    printf("\n\n");

    printf("get_neighbors(current_node = 14) --> 9, 13, 19\n");
    printf("neighbors of 14: ");
    get_neighbors(14, graph_representation, neighbors, &qnt_neighbors);
    for (size_t i = 0; i < qnt_neighbors; i++) {
        printf("%d ", neighbors[i]);
    }
    printf("\n\n");

    printf("get_neighbors(current_node = 22) --> 17, 21\n");
    printf("neighbors of 22: ");
    get_neighbors(22, graph_representation, neighbors, &qnt_neighbors);
    for (size_t i = 0; i < qnt_neighbors; i++) {
        printf("%d ", neighbors[i]);
    }
    printf("\n\n");

    printf("get_neighbors(current_node = 16) --> 11, 15, 17, 21\n");
    printf("neighbors of 16: ");
    get_neighbors(16, graph_representation, neighbors, &qnt_neighbors);
    for (size_t i = 0; i < qnt_neighbors; i++) {
        printf("%d ", neighbors[i]);
    }
    printf("\n\n");

    printf("get_neighbors(current_node = 11) --> 6, 10, 16\n");
    printf("neighbors of 11: ");
    get_neighbors(11, graph_representation, neighbors, &qnt_neighbors);
    for (size_t i = 0; i < qnt_neighbors; i++) {
        printf("%d ", neighbors[i]);
    }
    printf("\n\n");

    printf("get_neighbors(current_node = 12) --> 7, 11, 13, 17\n");
    printf("neighbors of 12: ");
    get_neighbors(12, graph_representation, neighbors, &qnt_neighbors);
    for (size_t i = 0; i < qnt_neighbors; i++) {
        printf("%d ", neighbors[i]);
    }
    printf("\n\n");

    printf("get_neighbors(current_node = 13) --> 8, 14, 18\n");
    printf("neighbors of 13: ");
    get_neighbors(13, graph_representation, neighbors, &qnt_neighbors);
    for (size_t i = 0; i < qnt_neighbors; i++) {
        printf("%d ", neighbors[i]);
    }
    printf("\n\n");

    printf("***************************************\n");
    qnt_lines = 7;
    qnt_columns = 7;
    qnt_nodes = 7*7;
}

//////////////////////////////
// Functions Implementation //
//////////////////////////////

bool are_all_nodes_verified(bool *vector_of_verifed_nodes){
    for (uint32_t i = 0; i < qnt_nodes; i++) {
        if(vector_of_verifed_nodes[i] == false){
            return false;
        }
    }
    return true;
}

int32_t get_node_with_min_distance(bool *vector_of_verifed_nodes,
                                    uint32_t *distances){
    uint32_t minimal_distance = 1 << 30;
    int32_t node_with_min_distance = -1;
    for (uint32_t i = 0; i < qnt_nodes; i++) {
        if(vector_of_verifed_nodes[i] == false){
            if(distances[i] < minimal_distance){
                minimal_distance = distances[i];
                node_with_min_distance = i;
            }
        }
    }
    return node_with_min_distance;
}


char get_char_encoding_of_direction(int32_t direction){
    if(direction == -1){
        return 'W';
    } else if(direction == 1){
        return 'E';
    } else if(direction == -qnt_columns){
        return 'N';
    } else if(direction == qnt_columns){
        return 'S';
    } else if(direction == 0){
        return '#';
    } else {
        return '?';
    }
}

char get_show_encoding_of_direction(int32_t direction){
    if(direction == -1){
        return '-';
    } else if(direction == 1){
        return '-';
    } else if(direction == -qnt_columns){
        return '|';
    } else if(direction == qnt_columns){
        return '|';
    } else if(direction == 0){
        return '#';
    } else {
        return '?';
    }
}

void show_steps_to_goal(char *steps_to_goal){
    printf("TODO");
}

//TODO: finish this function
//TODO: corrigir ortografia
void get_steps_to_goal( uint32_t start_node, uint32_t goal_node,
                        uint32_t before_goal_node,
                        uint32_t *next_node, char *steps_to_goal,
                        uint32_t qnt_of_steps){
    uint32_t index_of_current_step;
    uint32_t current_node;
    uint32_t before_node;
    int32_t direction;

    index_of_current_step = qnt_of_steps;
    current_node = goal_node;
    before_node = before_goal_node;

    direction =  current_node - before_node;
    steps_to_goal[index_of_current_step] = get_char_encoding_of_direction(direction);

    current_node = 0;
    direction =  current_node - before_node;
    steps_to_goal[index_of_current_step] = get_char_encoding_of_direction(direction);

}


void dijkstra_on_grid(uint32_t start_node, uint32_t goal_node, bool *graph_representation){
    /////////////////////////////////////////////////////
    // Variables to allow the dijkstra algorith to run //
    /////////////////////////////////////////////////////
    // Distance between the start and each node:
    uint32_t distances[qnt_nodes];
    uint32_t proposed_distance;
    // The next node that you shold go for each node:
    int32_t next_node[qnt_nodes];
    int32_t before_node[qnt_nodes];
    // Holds wich nodes are already verified and with are'nt.
    bool verified_nodes[qnt_nodes];
    // Indicates the node which are being analysed
    uint32_t current_node = start_node;
    // Indicates the neighbors to each node
    uint32_t neighbors[4]; // maximum 4 neighbors considering a grid layout
    uint32_t qnt_neighbors; // some nodes could have less than 4 neighbors
    // Indicates the currently neighbor which are being analysed
    uint32_t neighbor;

    ///
    char steps_to_goal[qnt_nodes];
    uint32_t distance_to_goal;
    ///

    ////////////////////////////////////////////////////////////////////////
    // Sets the distances between the origin end each node to infinite //
    // Sets no next node to each node                                  //
    // Sets the distance between the origin and itself to 0               //
    ////////////////////////////////////////////////////////////////////////
    for (uint16_t i = 0; i < qnt_nodes; i++) {
        verified_nodes[i] = false;
        distances[i] = 1 << 30; // Infinite (considering the worst scenary)
        next_node[i] = -1; // There is no next node
        before_node[i] = -1; // There is no next node
    }
    distances[start_node] = 0; // distance to stay in the same place
    next_node[goal_node] = goal_node;
    before_node[start_node] = start_node;
    // Debug msgs
    if(debug_msgs_enabled){
        printf("************************************************************\n");
        printf("Distances:\n");
        show_distance_map(distances);
        printf("************************************************************\n");
        printf("Best path:\n");
        show_steps_map(next_node);
        printf("************************************************************\n");
        printf("Inverse path:\n");
        show_steps_map(before_node);
    }

    ////////////////////////////////////////////////////////
    // Verifing each node and finding minimun distance //
    ////////////////////////////////////////////////////////
    if(debug_msgs_enabled){
        printf("************************************************************\n");
        printf("next node == %d != %d \n", next_node[current_node], goal_node);
        printf("are_all_nodes_verified == %d == false \n", are_all_nodes_verified(verified_nodes));
        printf("************************************************************\n");
    }
    while(  next_node[current_node] != goal_node
         && are_all_nodes_verified(verified_nodes) == false){
        current_node = get_node_with_min_distance(verified_nodes, distances); //and node valides (not walls)
        if(debug_msgs_enabled){
            printf("************************************************************\n");
            printf("node with minimun distance: %d\n", current_node);
        }
        get_neighbors(current_node, graph_representation, neighbors, &qnt_neighbors);
        if(debug_msgs_enabled){
            printf("get_neighbors(current_node =  %d) --> ", current_node);
            for (size_t i = 0; i < qnt_neighbors; i++) {
                printf("%d ", neighbors[i]);
            }
            printf("\n");
        }
        // for each neighbor of current_node
        for (uint32_t i = 0; i < qnt_neighbors; i++){
            neighbor = neighbors[i];
            // Weight between a node and its neighbor is always 1 unity
            proposed_distance = distances[current_node] + 1;

            if(debug_msgs_enabled){
                printf("    NEIGHBOR: %d\n", neighbor);
                printf("proposed distance: %d\n", proposed_distance);
                printf("current distance: %d\n", distances[neighbor] >= 1<<20 ? -1 :  distances[neighbor]);
            }
            // if the distance to neighbor are greater than the distance comming from the current_node
            if (distances[neighbor] > proposed_distance){
                distances[neighbor] = proposed_distance;
                next_node[current_node] = neighbor;
                before_node[neighbor] = current_node;
                if(debug_msgs_enabled){
                    printf("************************************************************\n");
                    printf("Distances:\n");
                    show_distance_map(distances);
                    printf("************************************************************\n");
                    printf("Best path:\n");
                    show_steps_map(next_node);
                    printf("************************************************************\n");
                    printf("Inverse path:\n");
                    show_steps_map(before_node);
                }
            }
        }
        // Set this node as verified
        verified_nodes[current_node] = true;
        if(debug_msgs_enabled){
            printf("************************************************************\n");
            show_bool_map(verified_nodes);
        }
    }
}

void get_neighbors( uint32_t current_node, bool *graph_representation,
                    uint32_t *neighbors, uint32_t *qnt_neighbors){
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
    qnt_neighbors[0] = 0;
    if(n_neighbor != -1 && graph_representation[n_neighbor] == 0){
        neighbors[qnt_neighbors[0]] = n_neighbor;
        qnt_neighbors[0] += 1;
    }
    if(s_neighbor != -1 && graph_representation[s_neighbor] == 0){
        neighbors[qnt_neighbors[0]] = s_neighbor;
        qnt_neighbors[0] += 1;
    }
    if(w_neighbor != -1 && graph_representation[w_neighbor] == 0){
        neighbors[qnt_neighbors[0]] = w_neighbor;
        qnt_neighbors[0] += 1;
    }
    if(e_neighbor != -1 && graph_representation[e_neighbor] == 0){
        neighbors[qnt_neighbors[0]] = e_neighbor;
        qnt_neighbors[0] += 1;
    }
}

void show_bool_map(bool *map_to_show){
    for (uint16_t i = 0; i < qnt_lines; i++) {
        for (uint16_t j = 0; j < qnt_columns; j++) {
            map_to_show[j+qnt_lines*i] ? printf(" x ") : printf("   ");
        }
        printf("\n");
    }
}

void show_distance_map(uint32_t *distances_to_show){
    for (uint16_t i = 0; i < qnt_lines; i++) {
        for (uint16_t j = 0; j < qnt_columns; j++) {
            if(distances_to_show[j+qnt_lines*i] < (1 << 14)){
                printf(" %3d ", distances_to_show[j+qnt_lines*i]);
            } else {
                printf("     ");
            }
        }
        printf("\n");
    }
}

void show_steps_map(int32_t *steps_to_show){
    for (uint16_t i = 0; i < qnt_lines; i++) {
        for (uint16_t j = 0; j < qnt_columns; j++) {
            if(steps_to_show[j+qnt_lines*i] < qnt_nodes){
                printf(" %3d ", steps_to_show[j+qnt_lines*i]);
            } else {
                printf("     ");
            }
        }
        printf("\n");
    }
}

void test_dijkistra(){
    printf("antes do hello\n");
    bool example_map[7*7] = {
                    1, 1, 1, 1, 1, 1, 1,  // line 0
                    1, 1, 0, 0, 1, 0, 1,  // line 1
                    1, 0, 0, 1, 1, 0, 1,  // line 2
                    1, 1, 0, 0, 0, 0, 1,  // line 3
                    1, 1, 1, 1, 0, 0, 1,  // line 4
                    1, 0, 0, 0, 0, 0, 1,  // line 5
                    1, 0, 1, 1, 1, 1, 1}; // line 6
    if(debug_msgs_enabled){
        show_bool_map(example_map);
    }
	printf("Hello disgraça!\n");
    printf("Testing dijkstra from node %d to %d.\n",43,10);
    dijkstra_on_grid(43, 10, example_map);
}
