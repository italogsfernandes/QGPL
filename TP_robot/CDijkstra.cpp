/**
 * DIJKISTRA PSEUDOCODE (from wikipedia)
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
#include "CDijkstra.h"

/////////////////
// Constructor //
/////////////////
CDijkstra::CDijkstra(){
    distance_to_goal = 0;
    start_node = 0;
    goal_node = 0;
    analysed = false;
    path_found = false;
}

CDijkstra::~CDijkstra(){
    ;
}

/**
 * Defines a new start.
 * @param new_start_node new_start
 */
void CDijkstra::set_start_node(uint32_t new_start_node){
    start_node = new_start_node;
    analysed = false;
    path_found = false;
}

/**
 * Defines a new goal.
 * @param new_goal_node new_goal
 */
void CDijkstra::set_goal_node(uint32_t new_goal_node){
    goal_node = new_goal_node;
    if(analysed == true){
        //TODO: don't need to re-analyse it
    }
}

/**
 * [CDijkstra::set_graph description]
 * @param new_graph [description]
 */
void CDijkstra::set_graph(bool *new_graph){
    //NOTE: Note optimized, to optimize use memcpy()
    for (uint32_t i = 0; i < QNT_NODES; i++) {
        graph_representation[i] = new_graph[i];
    }
    analysed = false;
    path_found = false;
}

////////////////////////////////////////////
// Main dijkstra algorithm implementation //
////////////////////////////////////////////

/**
 * Run dijkstra alrorithm implemented as described in the pseudocode
 * available at wikipedia.
 * Pre-requisites (before running):
 *  * A defined start point: start_node
 *  * A defined goal point: goal_node
 *  * A Graph: graph_representation
 */
void CDijkstra::launch_algorithm(){
    /////////////////////////////////////////////////////
    // Variables to allow the dijkstra algorithm to run //
    /////////////////////////////////////////////////////
    //Holds the proposed distance between a node and its neighbor
    uint32_t proposed_distance;
    // Indicates the node which are being analysed
    uint32_t current_node = start_node;
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
    for (uint16_t i = 0; i < QNT_NODES; i++) {
        verified_nodes[i] = false;
        distances[i] = 1 << 30; // Infinite (considering the worst scenary)
        next_nodes[i] = -1; // There is no next node
        previous_nodes[i] = -1; // There is no next node
    }
    distances[start_node] = 0; // distance to stay in the same place
    next_nodes[goal_node] = goal_node;
    previous_nodes[start_node] = start_node;

    // Debug messages
    #ifdef DEBUG_MSGS_ENABLED
    printf("************************************************************\n");
    printf("Distances:\n");
    show_distance_map(distances);
    #ifdef DEBUG_MSGS_ENABLED_LEVEL_1
    printf("************************************************************\n");
    printf("Best path:\n");
    show_steps_map(next_nodes);
    printf("************************************************************\n");
    printf("Inverse path:\n");
    show_steps_map(previous_nodes);
    #endif
    #endif
    ////////////////////////////////////////////////////////
    // Verifing each node and finding minimun distance //
    ////////////////////////////////////////////////////////
    #ifdef DEBUG_MSGS_ENABLED
    printf("************************************************************\n");
    printf("next node == %d != %d \n", next_nodes[current_node], goal_node);
    printf("are_all_nodes_verified == %d == false \n", are_all_nodes_verified());
    printf("************************************************************\n");
    #endif
    qnt_iterations = 0;
    while(  next_nodes[current_node] != goal_node
         && are_all_nodes_verified() == false){

        qnt_iterations ++;
        #ifdef DEBUG_MSGS_ENABLED
        printf("###### ITERATION NUMBER: %d ######\n", qnt_iterations);
        #endif

        current_node = get_node_with_min_distance(); //and node valides (not walls)
        if(current_node == -1){ //Protection
            break;
        }
        #ifdef DEBUG_MSGS_ENABLED
        printf("************************************************************\n");
        printf("node with minimun distance: %d\n", current_node);
        #endif

        get_neighbors(current_node, neighbors, &qnt_neighbors);

        #ifdef DEBUG_MSGS_ENABLED_LEVEL_2
        printf("get_neighbors(current_node =  %d) --> ", current_node);
        for (size_t i = 0; i < qnt_neighbors; i++) {
            printf("%d ", neighbors[i]);
        }
        printf("\n");
        #endif

        // for each neighbor of current_node
        for (uint32_t i = 0; i < qnt_neighbors; i++){
            neighbor = neighbors[i];
            // Weight between a node and its neighbor is always 1 unity
            proposed_distance = distances[current_node] + 1;

            #ifdef DEBUG_MSGS_ENABLED_LEVEL_2
            printf("    NEIGHBOR: %d\n", neighbor);
            printf("proposed distance: %d\n", proposed_distance);
            printf("current distance: %d\n", distances[neighbor] >= 1<<20 ? -1 :  distances[neighbor]);
            #endif
            // if the distance to neighbor are greater than the distance comming from the current_node
            if (distances[neighbor] > proposed_distance){
                distances[neighbor] = proposed_distance;
                next_nodes[current_node] = neighbor;
                previous_nodes[neighbor] = current_node;
                if(next_nodes[current_node] == goal_node){
                    path_found = true;
                }
                #ifdef DEBUG_MSGS_ENABLED
                printf("************************************************************\n");
                printf("Distances:\n");
                show_distance_map(distances);
                #ifdef DEBUG_MSGS_ENABLED_LEVEL_1
                printf("************************************************************\n");
                printf("Best path:\n");
                show_steps_map(next_nodes);
                printf("************************************************************\n");
                printf("Inverse path:\n");
                show_steps_map(previous_nodes);
                #endif
                #endif
            }
        }
        // Set this node as verified
        verified_nodes[current_node] = true;
        #ifdef DEBUG_MSGS_ENABLED_LEVEL_1
        printf("************************************************************\n");
        printf("Verified places:\n");
        show_bool_map(verified_nodes);
        #endif
    }
    analysed = true;

    #ifdef DEBUG_MSGS_ENABLED
    printf("************************************************************\n");
    if(path_found){
        printf("###### PATH FOUND WITH %d ITERATIONS ######\n", qnt_iterations);
    } else {
        printf("!!!!!! NO PATH FOUND WITH %d ITERATIONS !!!!!!\n", qnt_iterations);
    }
    printf("************************************************************\n");
    #endif

    if(path_found){
        //TODO: get_steps_to_goal
    }
}

///////////////////////
// Auxiliary methods //
///////////////////////

/**
 * Get Neighbors
 * Considering the representation of the map as a graph
 * andd considering a retangular grid (with borders),
 * it obtains all the adjacent nodes (North, South, West, East)
 * if there are some barrier or border near to the node
 * it will obtain less tha 4 nodes adjacents.
 * @param current_node  Node to be analysed
 * @param neighbors     uint32_t vector which will receive the nodes
 * @param qnt_neighbors uint32_t variable to receive the amount of nodes
 */
void CDijkstra::get_neighbors(uint32_t current_node,
    uint32_t *neighbors, uint32_t *qnt_neighbors){
    /* Possible Neighbors in this solution
     * North, East, South and West:
     *     N
     *  W--|--E
     *     S
     */
    int32_t n_neighbor, s_neighbor, w_neighbor, e_neighbor;
    n_neighbor = current_node - QNT_COLUMNS;
    s_neighbor = current_node + QNT_COLUMNS;
    w_neighbor = current_node - 1;
    e_neighbor = current_node + 1;

    //////////////////
    //Grid boundary //
    //////////////////
    // In the first line there are no north
    if(current_node < QNT_COLUMNS){
        n_neighbor = -1;
    }
    // In the last line there are no south
    if(current_node >= (QNT_NODES - QNT_COLUMNS)){
        s_neighbor = -1;
    }
    // In the first column there are no west
    if(current_node % QNT_COLUMNS == 0){
        w_neighbor = -1;
    }
    // In the last column there are no east
    if(current_node % QNT_COLUMNS == (QNT_COLUMNS - 1)){
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

/**
 * Are all nodes verified?
 * Verify if there are any unverified node.
 * @return      true of false acording to the presence of unverified nodes
 */
bool CDijkstra::are_all_nodes_verified(){
    for (uint32_t i = 0; i < QNT_NODES; i++) {
        if(verified_nodes[i] == false){
            return false;
        }
    }
    return true;
}

/**
 * Get the node with minimum value of distance,
 * considering only the nodes not verified.
 * It is used to know which node will be the next to be analysed.
 * @return  the node with min distance value, -1 if all nodes are verified.
 */
int32_t CDijkstra::get_node_with_min_distance(){
    uint32_t minimal_distance = 1 << 30;
    int32_t node_with_min_distance = -1;
    for (uint32_t i = 0; i < QNT_NODES; i++) {
        if(verified_nodes[i] == false){
            if(distances[i] < minimal_distance){
                minimal_distance = distances[i];
                node_with_min_distance = i;
            }
        }
    }
    return node_with_min_distance;
}

/**
 * Encode a step as a symbol of direction.
 * Being:
 *  N -> North: from my place to the previous line
 *  S -> South: from my place to the next line
 *  W -> West: from my place to a previous column
 *  E -> East: from my place to the next column
 *  # -> Stopped
 *  ? -> Error - Unknow
 * @param  direction direction representation as a number
 * @return           direction encoded as char
 */
char CDijkstra::get_char_encoding_of_direction(int32_t direction){
    if(direction == -1){
        return 'W';
    } else if(direction == 1){
        return 'E';
    } else if(direction == -QNT_COLUMNS){
        return 'N';
    } else if(direction == QNT_COLUMNS){
        return 'S';
    } else if(direction == 0){
        return '#';
    } else {
        return '?';
    }
}

/**
 * Considering a graph already analysed, it obtains a list of steps.
 */
void CDijkstra::get_steps_to_goal(){
    uint32_t index_of_current_step;
    uint32_t current_node;
    uint32_t previous_node;
    int32_t direction;

    index_of_current_step = distance_to_goal;
    current_node = goal_node;

     while (current_node != start_node) {
         previous_node = previous_nodes[current_node];
         direction =  current_node - previous_node;
         steps_to_goal[index_of_current_step] = get_char_encoding_of_direction(direction);
         index_of_current_step -= 1;
         current_node = previous_node;
         //TODO: finish
     }
}

///////////////////
// Print methods //
///////////////////

/**
 * Show a graph representation as a bool map in the following way:
 *
 * @param map_to_show which map do you desire do print
 */
void CDijkstra::show_bool_map(bool *map_to_show){
    for (uint16_t i = 0; i < QNT_LINES; i++) {
        for (uint16_t j = 0; j < QNT_COLUMNS; j++) {
            map_to_show[j+QNT_LINES*i] ? printf(" x ") : printf("   ");
        }
        printf("\n");
    }
}

/**
 * Shows the distances to each node in the graph representation.
 * Example:
 *
 * @param distances_to_show which map do you desire to show
 */
void CDijkstra::show_distance_map(uint32_t *distances_to_show){
    for (uint16_t i = 0; i < QNT_LINES; i++) {
        for (uint16_t j = 0; j < QNT_COLUMNS; j++) {
            if(distances_to_show[j+QNT_LINES*i] < (1 << 14)){
                printf(" %3d ", distances_to_show[j+QNT_LINES*i]);
            } else {
                printf("     ");
            }
        }
        printf("\n");
    }
}

/**
 * Shows the steps to be percorrer in the following way:
 * Example:
 * @param steps_to_show which map do you desire to show
 */
void CDijkstra::show_steps_map(int32_t *steps_to_show){
    for (uint16_t i = 0; i < QNT_LINES; i++) {
        for (uint16_t j = 0; j < QNT_COLUMNS; j++) {
            if(steps_to_show[j+QNT_LINES*i] < QNT_NODES){
                printf(" %3d ", steps_to_show[j+QNT_LINES*i]);
            } else {
                printf("     ");
            }
        }
        printf("\n");
    }
}

/**
 * Print steps to arrive at the goal as North South West East coordinates.
 * @param arrows is enabled this will show the steps also like arrows
 */
void CDijkstra::show_steps_to_goal(bool arrows){
    uint32_t i;
    printf("Steps to goal: \n\t");
    for (i = 0; i < distance_to_goal-1; i++) {
        printf("%c, ", steps_to_goal[i]);
    }
    printf("%c.\n", steps_to_goal[i]);

    if(arrows){
        for (i = 0; i < distance_to_goal-1; i++) {
            if(steps_to_goal[i] == 'N'){
                printf("* ");
            } else if(steps_to_goal[i] == 'S'){
                printf(". ");
            } else if(steps_to_goal[i] == 'N'){
                printf("> ");
            } else if(steps_to_goal[i] == 'N'){
                printf("< ");
            } else {
                printf("%c ", steps_to_goal[i]);
            }
        }
        if(steps_to_goal[i] == 'N'){
            printf("*\n");
        } else if(steps_to_goal[i] == 'S'){
            printf(".\n");
        } else if(steps_to_goal[i] == 'N'){
            printf(">\n");
        } else if(steps_to_goal[i] == 'N'){
            printf("<\n");
        } else {
            printf("%c\n", steps_to_goal[i]);
        }
    }
}

/**
 * Show some relevant public and private data.
 */
void CDijkstra::show_data_members(){
    printf("********************Some Data*******************\n");
    printf("\tanalysed:         %s\n", analysed?"yes":"no");
    printf("\tpath found:        %s\n", path_found?"yes":"no");
    printf("\tstart node:       %d\n", start_node);
    printf("\tgoal node:        %d\n", goal_node);
    printf("\tdistance to goal: %d\n", distance_to_goal);
}

///////////
// Tests //
///////////

/**
 * Execute dijkstra algorithm in a example map
 * WARNING: QNT_LINES and QNT_COLUMNS should match with: 7 x 7
 */
void CDijkstra::global_test(){
    //WARNING: QNT_LINES and QNT_COLUMNS should match with:
    //#define QNT_LINES   7
    //#define QNT_COLUMNS 7
    // Boolean representation of grid map as a graph for testing purposes
    bool example_map[QNT_NODES] = {
                    1, 1, 1, 1, 1, 1, 1,  // line 0
                    1, 1, 0, 0, 1, 0, 1,  // line 1
                    1, 0, 0, 1, 1, 0, 1,  // line 2
                    1, 1, 0, 0, 0, 0, 1,  // line 3
                    1, 1, 1, 1, 0, 0, 1,  // line 4
                    1, 0, 0, 0, 0, 0, 1,  // line 5
                    1, 0, 1, 1, 1, 1, 1}; // line 6
    set_graph(example_map);
    set_start_node(43);
    set_goal_node(12);
    #ifdef DEBUG_MSGS_ENABLED
    printf("********************GLOBAL TEST********************\n");
    show_bool_map(graph_representation);
    printf("***************************************************\n");
    printf("Testing dijkstra from node %d to %d.\n",start_node, goal_node);
    printf("***************************************************\n");
    show_data_members();
    #endif
    launch_algorithm();
}

/**
 * Prints and verify the results of the method 'get_neighbors'
 */
void CDijkstra::test_find_neighbors(){
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
    //WARNING: QNT_LINES and QNT_COLUMNS should match with:
    //#define QNT_LINES   5
    //#define QNT_COLUMNS 5
    uint32_t neighbors[4];
    uint32_t qnt_neighbors;
    bool graph_representation[5*5] = {  0, 0, 0, 0, 0,
                                        0, 0, 0, 0, 0,
                                        0, 0, 1, 0, 0,
                                        0, 0, 0, 0, 0,
                                        0, 0, 0, 1, 0};

    printf("get_neighbors(current_node =  0) --> 1, 5\n");
    printf("neighbors of 0: ");
    get_neighbors(0, neighbors, &qnt_neighbors);
    for (size_t i = 0; i < qnt_neighbors; i++) {
        printf("%d ", neighbors[i]);
    }
    printf("\n\n");

    printf("get_neighbors(current_node =  4) --> 3, 9\n");
    printf("neighbors of 4: ");
    get_neighbors(4, neighbors, &qnt_neighbors);
    for (size_t i = 0; i < qnt_neighbors; i++) {
        printf("%d ", neighbors[i]);
    }
    printf("\n\n");

    printf("get_neighbors(current_node = 20) --> 15, 21\n");
    printf("neighbors of 20: ");
    get_neighbors(20, neighbors, &qnt_neighbors);
    for (size_t i = 0; i < qnt_neighbors; i++) {
        printf("%d ", neighbors[i]);
    }
    printf("\n\n");

    printf("get_neighbors(current_node = 24) --> 19\n");
    printf("neighbors of 24: ");
    get_neighbors(24, neighbors, &qnt_neighbors);
    for (size_t i = 0; i < qnt_neighbors; i++) {
        printf("%d ", neighbors[i]);
    }
    printf("\n\n");

    printf("get_neighbors(current_node =  2) --> 1, 3, 7\n");
    printf("neighbors of 2: ");
    get_neighbors(2, neighbors, &qnt_neighbors);
    for (size_t i = 0; i < qnt_neighbors; i++) {
        printf("%d ", neighbors[i]);
    }
    printf("\n\n");

    printf("get_neighbors(current_node = 10) --> 5, 11, 15\n");
    printf("neighbors of 10: ");
    get_neighbors(10, neighbors, &qnt_neighbors);
    for (size_t i = 0; i < qnt_neighbors; i++) {
        printf("%d ", neighbors[i]);
    }
    printf("\n\n");

    printf("get_neighbors(current_node = 14) --> 9, 13, 19\n");
    printf("neighbors of 14: ");
    get_neighbors(14, neighbors, &qnt_neighbors);
    for (size_t i = 0; i < qnt_neighbors; i++) {
        printf("%d ", neighbors[i]);
    }
    printf("\n\n");

    printf("get_neighbors(current_node = 22) --> 17, 21\n");
    printf("neighbors of 22: ");
    get_neighbors(22, neighbors, &qnt_neighbors);
    for (size_t i = 0; i < qnt_neighbors; i++) {
        printf("%d ", neighbors[i]);
    }
    printf("\n\n");

    printf("get_neighbors(current_node = 16) --> 11, 15, 17, 21\n");
    printf("neighbors of 16: ");
    get_neighbors(16, neighbors, &qnt_neighbors);
    for (size_t i = 0; i < qnt_neighbors; i++) {
        printf("%d ", neighbors[i]);
    }
    printf("\n\n");

    printf("get_neighbors(current_node = 11) --> 6, 10, 16\n");
    printf("neighbors of 11: ");
    get_neighbors(11, neighbors, &qnt_neighbors);
    for (size_t i = 0; i < qnt_neighbors; i++) {
        printf("%d ", neighbors[i]);
    }
    printf("\n\n");

    printf("get_neighbors(current_node = 12) --> 7, 11, 13, 17\n");
    printf("neighbors of 12: ");
    get_neighbors(12, neighbors, &qnt_neighbors);
    for (size_t i = 0; i < qnt_neighbors; i++) {
        printf("%d ", neighbors[i]);
    }
    printf("\n\n");

    printf("get_neighbors(current_node = 13) --> 8, 14, 18\n");
    printf("neighbors of 13: ");
    get_neighbors(13, neighbors, &qnt_neighbors);
    for (size_t i = 0; i < qnt_neighbors; i++) {
        printf("%d ", neighbors[i]);
    }
    printf("\n\n");

    printf("***************************************\n");
}
