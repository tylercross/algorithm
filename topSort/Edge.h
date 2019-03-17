#ifndef EDGE_H_INCLUDED
#define EDGE_H_INCLUDED

class Vertex;

struct Edge {
    Vertex *vertex;
    int weight;
    std::string name;

    Edge(Vertex *to, const int &weight, const std::string &name = "")\
     : vertex{to}, weight{weight}, name{} {}
};


#endif // EDGE_H_INCLUDED
