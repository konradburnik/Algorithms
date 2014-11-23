#ifndef __GRAPH_H_
#define __GRAPH_H_

namespace Algorithms
{

  template <typename T>
  class Vertex
  {
    private:
      long ID;
      T* data;
    public:
      Vertex(long _ID, T* VertexData)
      {
        ID = _ID;
        data = VertexData;
      }

      long getID() const
      {
       return ID;
      }

      T* getData()
      {
        return data;
      }
  };

  template <typename T>
  class Graph
  {
    public:
      virtual void addVertex(Vertex<T> *v) = 0;
      virtual void removeVertex(Vertex<T> *v) = 0;
      virtual void addDirectedEdge(Vertex<T> *v1, Vertex<T> *v2) = 0;
      virtual void addEdge(Vertex<T> *v1, Vertex<T> *v2) = 0;
      virtual void removeDirectedEdge(Vertex<T> *v1, Vertex<T> *v2) = 0;
      virtual void removeEdge(Vertex<T> *v1, Vertex<T> *v2) = 0;
      virtual void getVertex(long ID, Vertex<T>* v) = 0;
  };

}

#endif
