#ifndef ABB_H
#define ABB_H

#include "ABB_Node.h"

template<typename T>
struct ABB
{
public:
    //Constructor
    ABB()
    {
        root = nullptr;
    }
    //Atributes
    ABB_Node<T>* root;

    //Methods
    void insert(int pK, T pT)
    {
        insert(pK, pT, root);
    }

    void insert(int pK, T pT, ABB_Node<T>* pParent)
    {
        if(pParent == nullptr){
            root = new ABB_Node<T>(pK, pT);
            return;
        }

        if(pK < pParent->key){
            if(pParent->left != nullptr){
                insert(pK, pT, pParent->left);
            }
            else{
                pParent->left = new ABB_Node<T>(pK, pT);
                return;
            }
        }
        else{
            if(pParent->right != nullptr){
                insert(pK, pT, pParent->right);
            }
            else{
                pParent->right = new ABB_Node<T>(pK, pT);
                return;
            }
        }
    }

    ABB_Node<T>* remove()
    {

    }

    ABB_Node<T>* search(int pK)
    {
        if(root == nullptr){
            return nullptr;
        }
        return search(pK, root);
    }

    ABB_Node<T>* search(int pK, ABB_Node<T>* pParent)
    {
        if(pParent == nullptr){
            return nullptr;
        }
        if(pK == pParent->key){
            return pParent;
        }
        if(pK < pParent->key){
            return search(pK, pParent->left);
        }
        return search(pK, pParent->right);
    }


    void update()
    {

    }
        //all the traversals are prints on the console, edit this to return a QList or whtvs you need

    void preOrder()
    {
        preOrder(root);
    }

    ABB_Node<T>* preOrder(ABB_Node<T>* pParent)
    {
        if(pParent == nullptr){            //Will stop in null, but you can use other condition like ifLeaf(), ifOneChild(), etc
            return nullptr;
        }
        pParent->print();               //Do your logic with the Node you want to work, in this case just print
        preOrder(pParent->left);        //Goes all the way to the left until nullptr
        preOrder(pParent->right);       //Goes all the way to the right until nullptr
    }

    void inOrder()
    {
        inOrder(root);
    }

    ABB_Node<T>* inOrder(ABB_Node<T>* pParent)
    {
        if(pParent == nullptr){            //Will stop in null, but you can use other condition like ifLeaf(), ifOneChild(), etc
            return nullptr;
        }
        inOrder(pParent->left);         //Goes all the way to the left until nullptr
        pParent->print();               //Do your logic with the Node you want to work, in this case just print♪
        inOrder(pParent->right);        //Goes all the way to the right until nullptr
    }

    void postOrder()
    {
        postOrder(root);
    }

    ABB_Node<T>* postOrder(ABB_Node<T>* pParent)
    {
        if(pParent == nullptr){            //Will stop in null, but you can use other condition like ifLeaf(), ifOneChild(), etc
            return nullptr;
        }
        postOrder(pParent->left);       //Goes all the way to the left until nullptr
        postOrder(pParent->right);      //Goes all the way to the right until nullptr
        pParent->print();               //Do your logic with the Node you want to work, in this case just print
    }

};

#endif // ABB_H
