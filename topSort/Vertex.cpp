#include "Vertex.h"





    std::string Vertex::GetName() { return name_; }
    bool Vertex::SetName(std::string name) {
        name_ = name;
        return true;
    }

    void Vertex::AddTo(const Edge &to_edge) {
        std::list<Edge>::iterator it = to_.begin();
        std::list<Edge>::const_iterator end = to_.end();
        while (it != end) {
            if ((*it++).vertex == to_edge.vertex)
                return;
        }
        to_.push_back(to_edge);//先添加带end的边
        to_edge.vertex->AddFrom(Edge(this, to_edge.weight));//添加源头节点
    }

    const std::list<Edge> & Vertex::GetTos() {
        return to_;
    }

    const std::list<Edge> & Vertex::GetFroms() {
        return from_;
    }

    void Vertex::PrintAdjs() {
        std::list<Edge>::iterator it = to_.begin();
        std::list<Edge>::const_iterator end = to_.end();
        while (it != end) {
            std::cout << (*it++).vertex->GetName() << " ";
        }
        std::cout << "\n";
    }
    void Vertex::AddFrom(const Edge &from_edge) {
        std::list<Edge>::iterator it = from_.begin();
        std::list<Edge>::const_iterator end = from_.end();
        while (it != end) {
            if ((*it++).vertex == from_edge.vertex)
                return;
        }
        from_.push_back(from_edge);
}
