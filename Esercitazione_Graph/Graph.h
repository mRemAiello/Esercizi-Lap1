template <class T> class Graph {
    T data;
    T * matrix;
    int size;
    
    public:
        Graph(int n, T inf);
        ~Graph();
        void link(int n1, int n2, T cost);
        void unlink(int n1, int n2);
        bool linked(int n1, int n2);
};
