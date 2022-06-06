//
// Created by ebonitesh0ut on 06.06.2022.
//

#ifndef UNTITLED1_SPLAYTREE_H
#define UNTITLED1_SPLAYTREE_H
#include <stack>
#include "Survey.h"

class Stratege
{
public:
    virtual ~Stratege() {}

    virtual int compare(const Survey::BaseSurvey* r, const Survey::BaseSurvey* l)
    {
        if (r == l) return 0;
        else if (r > l) return 1;
        else return -1;
    }
};

class comparator
{
private:
    Stratege* stac = nullptr;
public:
    comparator() {
        stac = new Stratege;
    }

    comparator(Stratege* stac) : stac(stac)
    {};

    void SetNewStrategy(Stratege* const _stac)
    {
        stac = _stac;
    }

    template <typename T>
    int func(const T& r, const T& l) const
    {
        return this->stac->compare(r, l);
    }
};

template <class T>
class SplayTree
{
public:
    struct node
    {
        T key;
        node* lchild;
        node* rchild;
        node* parent;

        node(const T& value = T()) : key(value)
        {
            parent = lchild = rchild = nullptr;
        }
    };

    class Iterator
    {
    public:
        node* current;
        stack<node*> stack;

        Iterator(node* p = nullptr) : current(p)
        {
            while (current->lchild != nullptr)
                current = current->lchild;
        }

        node* operator *() { return current; }

        Iterator& operator ++()
        {
            stack.push(current);
            if (current == stack.top())
            {
                current = current->parent;
                return *this;
            }
            //descent to left bottom
            if (current->lchild != nullptr)
            {
                while (current->lchild != nullptr)
                    current = current->lchild;
                stack.push(current);
                return *this;
            }
            //if can move right
            if (current->rchild != nullptr)
                return *this;
            else if (current->rchild != nullptr)
                return *this;
        }
    };
protected:
    stack<node*> stack;
    node* _root;
    comparator _comp;
    node* _Successor(node* localRoot) const {
        node* successor = localRoot;

        if (successor->rchild != nullptr)
            successor = _Minimum(successor->rchild);

        else
            while (successor != _root ||
                   successor != successor->parent->lchild)
                successor = successor->parent;

        return successor;
    }

    node* _Predecessor(node* localRoot) const {
        node* predecessor = localRoot;

        if (predecessor->lchild != nullptr)
            predecessor = _Maximum(predecessor->lchild);

        else
            while (predecessor != _root ||
                   predecessor != predecessor->parent->rchild)
                predecessor = predecessor->parent;

        return predecessor;
    }

    node* _Minimum(node* localRoot) const {
        node* minimum = localRoot;

        while (minimum->lchild != nullptr)
            minimum = minimum->lchild;

        return minimum;
    }

    node* _Maximum(node* localRoot) const {
        node* maximum = localRoot;

        while (maximum->rchild != nullptr)
            maximum = maximum->rchild;

        return maximum;
    }

    node* _Search(const T& key) {
        node* searchedElement = _root;

        while (searchedElement != nullptr)
        {
            if (_comp.func(searchedElement->key, key) == 0)
            {
                _Splay(searchedElement);
                return searchedElement;
            }

            if (_comp.func(searchedElement->key, key) < 0)
                searchedElement = searchedElement->rchild;

            else
                searchedElement = searchedElement->lchild;
        }
        searchedElement = nullptr;
        return searchedElement;
    }






    node* inOrderTraversGender(node* root, Survey::Gender key, int* id) {
        if (root) {
            if (root->key->gender == key) { *id = root->key->surveyid; return root; }
            cout << root->key->gender << "   ";
            if(inOrderTraversGender(root->lchild, key,  id)) return root;
            if(inOrderTraversGender(root->rchild, key,  id)) return root;
        }
        return nullptr;
    }

    node* inOrderTraversCitizenship(node* root, Survey::CitizenShip key, int* id) {
        if (root) {
            if (root->key->citizen == key) { *id = root->key->surveyid; return root; }
            if (inOrderTraversCitizenship(root->lchild, key, id)) return root;
            if (inOrderTraversCitizenship(root->rchild, key, id)) return root;
        }
        return nullptr;
    }

    node* inOrderTraversEdu(node* root, Survey::Choice key, int* id) {
        if (root) {
            if (root->key->educationLevel == key) { *id = root->key->surveyid; return root; }
            if (inOrderTraversEdu(root->lchild, key, id)) return root;
            if (inOrderTraversEdu(root->rchild, key, id)) return root;
        }
        return nullptr;
    }

    node* inOrderTraversWorking(node* root, Survey::YesNo key, int* id) {
        if (root) {
            if (root->key->working == key) { *id = root->key->surveyid; return root; }
            if (inOrderTraversWorking(root->lchild, key, id)) return root;
            if (inOrderTraversWorking(root->rchild, key, id)) return root;
        }
        return nullptr;
    }





    void _LeftRotate(node* localRoot) {
        node* rightChild = localRoot->rchild;

        localRoot->rchild = rightChild->lchild;

        if (rightChild->lchild != nullptr)
            rightChild->lchild->parent = localRoot;

        _Transplant(localRoot, rightChild);

        rightChild->lchild = localRoot;
        rightChild->lchild->parent = rightChild;
    }

    void _RightRotate(node* localRoot) {
        node* leftChild = localRoot->lchild;

        localRoot->lchild = leftChild->rchild;

        if (leftChild->rchild != nullptr)
            leftChild->rchild->parent = localRoot;

        _Transplant(localRoot, leftChild);

        leftChild->rchild = localRoot;
        leftChild->rchild->parent = leftChild;
    }

    void _Transplant(node* localParent, node* localChild)
    {
        if (localParent->parent == nullptr)
            _root = localChild;

        else if (localParent == localParent->parent->lchild)
            localParent->parent->lchild = localChild;

        else if (localParent == localParent->parent->rchild)
            localParent->parent->rchild = localChild;

        if (localChild != nullptr)
            localChild->parent = localParent->parent;
    }

    void _Splay(node* pivotElement)
    {
        while (pivotElement != _root)
        {
            if (pivotElement->parent == _root)
            {

                if (pivotElement == pivotElement->parent->lchild)
                    _RightRotate(pivotElement->parent);
                else if (pivotElement == pivotElement->parent->rchild)
                    _LeftRotate(pivotElement->parent);
            }
            else
            {
                if (pivotElement == pivotElement->parent->lchild &&
                    pivotElement->parent == pivotElement->parent->parent->lchild)
                {
                    _RightRotate(pivotElement->parent->parent);
                    _RightRotate(pivotElement->parent);
                }
                else if (pivotElement == pivotElement->parent->rchild &&
                         pivotElement->parent == pivotElement->parent->parent->rchild)
                {
                    _LeftRotate(pivotElement->parent->parent);
                    _LeftRotate(pivotElement->parent);
                }
                else if (pivotElement == pivotElement->parent->rchild &&
                         pivotElement->parent == pivotElement->parent->parent->lchild)
                {
                    _LeftRotate(pivotElement->parent);
                    _RightRotate(pivotElement->parent);
                }
                else if (pivotElement == pivotElement->parent->lchild &&
                         pivotElement->parent == pivotElement->parent->parent->rchild)
                {
                    _RightRotate(pivotElement->parent);
                    _LeftRotate(pivotElement->parent);
                }
            }
        }
    }
public:
    SplayTree()
    {
        _root = nullptr;
        _comp = *new comparator();
    }

    SplayTree(T value)
    {
        _root = new node(value);
        _comp = new comparator();
    }

    SplayTree(T value, comparator& _comp)
    {
        _root = new node(value);
        _comp = _comp;
    }

    virtual ~SplayTree()
    {
        delete _root;
    }

    void Insert(const T key) {
        node* preInsertPlace = nullptr;
        node* insertPlace = _root;

        while (insertPlace != nullptr)
        {
            preInsertPlace = insertPlace;

            if (_comp.func(insertPlace->key, key) < 0)
                insertPlace = insertPlace->rchild;
            else
                insertPlace = insertPlace->lchild;
        }
        node* insertElement = new node(key);
        insertElement->parent = preInsertPlace;

        if (preInsertPlace == nullptr)
            _root = insertElement;
        else if (_comp.func(preInsertPlace->key, insertElement->key) < 0)
            preInsertPlace->rchild = insertElement;
        else if (_comp.func(insertElement->key, preInsertPlace->key) < 0)
            preInsertPlace->lchild = insertElement;

        _Splay(insertElement);
    }

    void Remove(const T key)
    {
        node* removeElement = _Search(key);

        if (removeElement != nullptr)
        {
            if (removeElement->rchild == nullptr)
                _Transplant(removeElement, removeElement->lchild);
            else if (removeElement->lchild == nullptr)
                _Transplant(removeElement, removeElement->rchild);
            else
            {
                node* newLocalRoot = _Minimum(removeElement->rchild);

                if (newLocalRoot->parent != removeElement)
                {

                    _Transplant(newLocalRoot, newLocalRoot->rchild);

                    newLocalRoot->rchild = removeElement->rchild;
                    newLocalRoot->rchild->parent = newLocalRoot;
                }

                _Transplant(removeElement, newLocalRoot);

                newLocalRoot->lchild = removeElement->lchild;
                newLocalRoot->lchild->parent = newLocalRoot;

                _Splay(newLocalRoot);
            }

            delete removeElement;
        }
    }

    T* Search(const T& key) {
        if (_Search(key) != nullptr)
            return &_Search(key)->key;
        else return nullptr;
    }



    int SearchByGender(Survey::Gender key) {
        int num =-1;
        inOrderTraversGender(_root, key, &num)->key;
        return num;
    }

    int SearchByCitizenship(Survey::CitizenShip key) {
        int num = -1;
        inOrderTraversCitizenship(_root, key, &num)->key;
        return num;
    }

    int SearchByWorking(Survey::YesNo key) {
        int num = -1;
        inOrderTraversWorking(_root, key, &num)->key;
        return num;
    }

    int SearchByEdu(Survey::Choice key) {
        int num = -1;
        inOrderTraversEdu(_root, key, &num)->key;
        return num;
    }




    bool empty() const { return _root == nullptr; }

    T Successor(const T& key) {
        if (_Successor(_Search(key)) != nullptr)
            return _Successor(_Search(key))->getValue();
        else
            return -1;
    }

    T Predecessor(const T& key) {
        if (_Predecessor(_Search(key)) != nullptr)
            return _Predecessor(_Search(key))->getValue();
        else
            return -1;
    }

    void SetComparator(Stratege* strat)
    {
        _comp.SetNewStrategy(strat);
    }

    Iterator GetIter()
    {
        return *new Iterator(_root);
    }
};
#endif //UNTITLED1_SPLAYTREE_H
