
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

#define vertices 100
#define linhas 10
#define colunas 10

///////////////
// Functions //
///////////////
void test_dijkistra();

////////////////////////
// Auxiliar Functions //
////////////////////////

void erro();
char info(int i,int j);
void preenchertab(char *locais);
int potencia(double num, int ele);
void carregargrifo(char *locais, int *custos);
void obterdirecoes(int *origem, int *destino);
int dijkstra(int origem,int destino, int *custos, int *caminho, int *casas);
int convertestep(int *caminho, int *passos, int qnt);

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

////////////////////
// Main Function  //
////////////////////
int main(){
    initiate_dijkstra();
	test_dijkistra();
	return 0;
}

//////////////////////////////
// Functions Implementation //
//////////////////////////////
void initiate_dijkstra(){
    ////////////////iniciando////////////////////
    char *locais;
    locais = (char *) calloc(vertices, sizeof(char));
    if(locais == NULL)
        erro();

    preenchertab(locais);//inicia
    mostrartab(locais);
}

void test_dijkistra(){
	printf("Hello disgraça!\n");
}
