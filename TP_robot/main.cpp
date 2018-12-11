//////////////
// Includes //
//////////////
#include <iostream>
#include "CDijkstra.h"
using namespace std;

////////////////////
// Main Function  //
////////////////////
int main(){
    // Instanciating a object of dijkstra class
    CDijkstra example_dijkstra_algo;
    example_dijkstra_algo = CDijkstra();

    // if you are unsure about the result of get_neighbors uncomment the next
    // line to execute a manual test:
    //test_find_neighbors();
	example_dijkstra_algo.global_test();
	return 0;
}
