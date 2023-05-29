#ifndef LAB7_ARBOLBINARIO_H
#define LAB7_ARBOLBINARIO_H

template<typename T>
struct NodeArbol {
    T data;
    NodeArbol<T>* left;
    NodeArbol<T>* right;
    NodeArbol<T>* makeNode(const T& value);
    void insertLeft(const T& value);
    void insertRight(const T& value);
};

template<typename T>
class ArbolBinario {
protected:
    NodeArbol<T>* root;
    void destroy(NodeArbol<T>* ptr);
public:
    ArbolBinario(const T& value);
    ~ArbolBinario();

    void setRootValue(T& value);
    NodeArbol<T>* getRootValue();

};



#endif //LAB7_ARBOLBINARIO_H
