#ifndef DIJKSTRA_H
#define DIJKSTRA_H
//////////////
// Includes //
//////////////
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

/////////////
// Defines //
/////////////
#define QNT_LINES   7
#define QNT_COLUMNS 7
#define QNT_NODES   QNT_LINES*QNT_COLUMNS
#define DEBUG_MSGS_ENABLED
//#define DEBUG_MSGS_ENABLED_LEVEL_0
//#define DEBUG_MSGS_ENABLED_LEVEL_1
//#define DEBUG_MSGS_ENABLED_LEVEL_2
//#define DEBUG_MSGS_ENABLED_STEPS_TO_GOAL

///////////
// Class //
///////////
class CDijkstra {
private:
    //////////////////
    // Private Data //
    //////////////////
    // Distance between the start and each node:
    uint32_t distances[QNT_NODES];
    // Holds wich nodes are already verified and with are'nt.
    bool verified_nodes[QNT_NODES];
    // The next node that you shold go for each node:
    int32_t next_nodes[QNT_NODES];
    int32_t previous_nodes[QNT_NODES];
    // Boolean representation of grid map as a graph
    bool graph_representation[QNT_NODES];

    bool analysed;
    bool path_found;

    /////////////////////
    // Private Methods //
    /////////////////////

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
    void get_neighbors(uint32_t current_node,
        uint32_t *neighbors, uint32_t *qnt_neighbors);

    /**
     * Are all nodes verified?
     * Verify if there are any unverified node.
     * @return      true of false acording to the presence of unverified nodes
     */
    bool are_all_nodes_verified();

    /**
     * Get the node with minimum value of distance,
     * considering only the nodes not verified.
     * It is used to know which node will be the next to be analysed.
     * @return  the node with min distance value, -1 if all nodes are verified.
     */
    int32_t get_node_with_min_distance();

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
    char get_char_encoding_of_direction(int32_t direction);

    /**
     * Considering a graph already analysed, it obtains a list of steps.
     */
    void get_steps_to_goal();

    public:
    /////////////////
    // Public Data //
    /////////////////
    uint32_t distance_to_goal;
    char steps_to_goal[QNT_NODES];
    uint32_t start_node;
    uint32_t goal_node;
    uint32_t qnt_iterations;
    ////////////////////
    // Public Members //
    ////////////////////
    CDijkstra ();
    virtual ~CDijkstra ();

    /**
     * Defines a new start.
     * @param new_start_node new_start
     */
    void set_start_node(uint32_t new_start_node);

    /**
     * Defines a new goal.
     * @param new_goal_node new_goal
     */
    void set_goal_node(uint32_t new_goal_node);

    /**
     * [set_graph description]
     * @param new_graph [description]
     */
    void set_graph(bool *new_graph);

    ////////////////////////////////////////////
    // Main dijkstra algorithm implementation //
    ////////////////////////////////////////////
    void launch_algorithm();

    ///////////////////
    // Print methods //
    ///////////////////

    /**
     * Show a graph representation as a bool map in the following way:
     *
     * @param map_to_show which map do you desire do print
     */
    void show_bool_map(bool *map_to_show);

    /**
     * Shows the distances to each node in the graph representation.
     * Example:
     *
     * @param distances_to_show which map do you desire to show
     */
    void show_distance_map(uint32_t *distances_to_show);

    /**
     * Shows the steps to be percorrer in the following way:
     * Example:
     * @param steps_to_show which map do you desire to show
     */
    void show_steps_map(int32_t *steps_to_show);

    /**
     * Print steps to arrive at the goal as North South West East coordinates.
     * @param arrows is enabled this will show the steps also like arrows
     */
    void show_steps_to_goal(bool arrows);

    /**
     * Show some relevant public and private data.
     */
    void show_data_members();
    ///////////
    // Tests //
    ///////////

    /**
     * Execute dijkstra algorithm in a example map
     * WARNING: QNT_LINES and QNT_COLUMNS should match with: 7 x 7
     */
    void global_test();

    /**
     * Prints and verify the results of the method 'get_neighbors'
     */
    void test_find_neighbors();
};
#endif
