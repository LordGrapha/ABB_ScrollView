#ifndef ABB_NODE_H
#define ABB_NODE_H



template <typename T>
struct ABB_Node
{
    //Constructor
    ABB_Node(int pKey, T pValue)
    {
        value = pValue;
        key = pKey;
        left = right = nullptr;
    }
    //Atributes
    int key;
    T value;
    ABB_Node<T>* left;
    ABB_Node<T>* right;
    //Methods
    void print()
    {
        qDebug() << "Node with Key = " << key;
    }

    void update(T pNewValue)
    {
        value = nullptr;
        value = pNewValue;
    }

};

#endif // ABB_NODE_H
