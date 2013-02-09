#include "Graph.h"

template <class T>
Graph<T>::Graph(int n, T cost) {
    matrix = new T[n*n];
    for(int i=0; i<n*n; i++)
        matrix[i] = cost;
    data = cost;
    size = n;
}

template <class T> 
Graph<T>::~Graph() {
    delete [] matrix; 
}

template <class T>
void Graph<T>::link(int i, int j, T cost) {
    matrix[i*size+j] = cost;    
}

template <class T>
void Graph<T>::unlink(int i, int j) {
    matrix[i*size+j] = data;
}

template <class T>
bool Graph<T>::linked(int i, int j) {
    if(matrix[i*size+j] != data)
        return true;
    return false;
}
