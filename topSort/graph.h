#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include "Edge.h"
#include "Vertex.h"

class Graph {
public:

    Graph();

    bool AddVertex(Vertex * vertex);

    bool AddEdge(Vertex * start, Vertex * end, const int & weight);

    const std::vector<Vertex *> GetVertices() const ;//常量成员函数

    static void PrintPaths(const Graph &graph,
                           const std::map<std::string, std::string> &path_map);

    static void PrintPathsHelper(const Graph &graph, Vertex *v,
                                 const std::map<std::string, std::string> &path_map,
                                 const std::vector<Vertex *> &vertices);
private:

    bool CheckVertexIn(Vertex * vertex);

    std::vector<Vertex *> vertices;
};

#include "Graph.cpp"


#endif // GRAPH_H_INCLUDED
