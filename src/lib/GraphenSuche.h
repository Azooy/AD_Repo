#ifndef GRAPHENSUCHE_H
#define GRAPHENSUCHE_H 
#include <vector>
#include <queue>



enum color {white, grey, black};

class Knoten{
  public:
    std::vector<Knoten*> nachfolgeKnoten;
    int id;
    color col = white;
    
    Knoten(int id_): id(id_){};
    Knoten(): id(-1){};

    void addNachfolger(Knoten* k){
      nachfolgeKnoten.push_back(k);
    }
};

class Graph{
  public:
  std::vector<Knoten> Adjazenzmatrix;

  void init(int dimension){
    Adjazenzmatrix.resize(dimension);
    for(int i = 0; i < dimension; i++){
      Adjazenzmatrix[i].id = i;
      Adjazenzmatrix[i].col = white;
      Adjazenzmatrix[i].nachfolgeKnoten.resize(dimension, nullptr);
    }
    
  };

  void addKante(int start, int ende){
    Adjazenzmatrix[start].nachfolgeKnoten[ende] = &Adjazenzmatrix[ende];
  };

};


void BFS(Graph& G, int start){
  std::queue<Knoten*> Q;
  G.Adjazenzmatrix[start].col = grey;
  Q.push(&G.Adjazenzmatrix[start]);
  while(!Q.empty()){
    Knoten* u = Q.front();
    Q.pop();
    for(auto v: u->nachfolgeKnoten){
      if(v->col == white){
        v->col = grey;
        Q.push(v);
      }
    }
    u->col = black;
  }
}

#endif