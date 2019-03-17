#ifndef VERTEX_H_INCLUDED
#define VERTEX_H_INCLUDED
class Vertex {
public:

    Vertex() {}
    Vertex(std::string name) :name_(name){}

    std::string GetName() ;


    bool SetName(std::string name) ;

    void AddTo(const Edge &to_edge) ;

    const std::list<Edge> &GetTos();

    const std::list<Edge> &GetFroms() ;

    void PrintAdjs() ;

private:

    // Add from edge for this vertex, outside class, user can only add to edges.
    void AddFrom(const Edge &from_edge) ;

    std::string name_;

    // From this vertex to other vertices' edges.
    std::list<Edge> to_;
    // From other vertex to this vertices's edges.
    std::list<Edge> from_;
};

#include "Vertex.cpp"


#endif // VERTEX_H_INCLUDED
