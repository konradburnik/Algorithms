#ifndef __GRAPH_H_
#define __GRAPH_H_

namespace Algorithms
{

  template <typename T>
  class Vertex
  {
    private:
      size_t ID;
      T* data;
    public:
      Vertex(T* VertexData)
      {
        data = VertexData;
      }

      size_t getID() const
      {
       return ID;
      }
  };

  template <typename T>
  class Graph
  {
    public:
      virtual void addVertex(Vertex *v) = 0;
      virtual void removeVertex(Vertex *v) = 0;
      virtual void addEdge(Vertex *v1, Vertex *v2) = 0;
      virtual void removeEdge(Vertex *v1, Vertex *v2) = 0;
      virtual void getVertex(size_t ID, Vertex* v) = 0;
  };

}

#endif __GRAPH_H_
