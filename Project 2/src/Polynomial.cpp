#include "Polynomial.h"
#include "Node.h"
#include<string>
#include<iostream>
using namespace std;

template<class T>
Polynomial<T>::Polynomial(){
    start = NULL;
}
template<class T>
Polynomial<T>::Polynomial(string s){
    T coef = 0;
    int power = 0;
    int count = 0;
    bool hasSeenNegative = false;
    bool hasSeenNegativePower = false;
    start = NULL;
    for(char x : s){
        if(x == '-' && count == 0) hasSeenNegative = true;
        if(x == '-' && count == 1) hasSeenNegativePower = true;
        if(x>='0' && x<='9' && count == 0){
            coef = coef * 10 + (x - '0');
        }else if(x>='0' && x<='9' && count == 1){
            power = power * 10 + (x - '0');
        }
        if(x == ' ')count++;
        if(count == 2){
            coef = (hasSeenNegative) ? -1*coef : coef;
            power = (hasSeenNegativePower) ? -1*power : power;
            Node<T>* node = new Node<T>(coef, power);
            insert(node);
            power = 0;
            coef = 0;
            count = 0;
            hasSeenNegative = false;
            hasSeenNegativePower = false;
        }
    }
    coef = (hasSeenNegative) ? -1*coef : coef;
    power = (hasSeenNegativePower) ? -1*power : power;
    Node<T>* node = new Node<T>(coef, power);
    insert(node);   
}
template<class T>
Polynomial<T>::~Polynomial(){
    delete start;
}
template<class T>
void Polynomial<T>::insert(Node<T>* node){
    Node<T>* current = start;
    if(current == NULL){
        start = node;
        return;
    }
    Node<T>* previous = current;
    int powerA = node->getPower();
    while(current!=NULL){
        int powerB = current->getPower();
        if(powerA == powerB){
            *current = (*current + *node);
            return;
        }
        if(powerB < powerA){
            if(current==start){
                node->setNext(current);
                start = node;
                return;
            }
            node->setNext(current);
            previous->setNext(node);
            return;
        }
        previous = current;
        current = current->getNext();
    }
    node->setNext(current);
    previous->setNext(node);
}
template<class T>
Polynomial<T>& Polynomial<T>::operator+(Polynomial<T>& poly){
    Polynomial<T>* newPoly = new Polynomial<T>();
    Node<T>* polyA = start;
    Node<T>* polyB = poly.start;
    while(polyA!=NULL && polyB!=NULL){
        int powerA = polyA->getPower();
        int powerB = polyB->getPower();
        if(powerA == powerB){
            Node<T>* node = new Node<T>( (*polyA) + (*polyB) );
            newPoly->insert(node);
            polyA = polyA->getNext();
            polyB = polyB->getNext();
        }else if(powerA < powerB){ 
            Node<T>* node = new Node<T>(*polyA);
            newPoly->insert(node);
            polyA = polyA->getNext();
        }else{
            Node<T>* node = new Node<T>(*polyB);
            newPoly->insert(node);
            polyB = polyB->getNext();
        }
    }
    while(polyA!=NULL){
        Node<T>* node = new Node<T>(*polyA);
        newPoly->insert(node);
        polyA = polyA->getNext();
    }
    while(polyB!=NULL){
        Node<T>* node = new Node<T>(*polyB);
        newPoly->insert(node);
        polyB = polyB->getNext();
    }
    return *newPoly;
}
template<class T>
Polynomial<T>& Polynomial<T>::operator-(Polynomial<T>& poly){
    Polynomial<T>* newPoly = new Polynomial<T>();
    Node<T>* polyA = start;
    Node<T>* polyB = poly.start;
    while(polyA!=NULL && polyB!=NULL){
        int powerA = polyA->getPower();
        int powerB = polyB->getPower();
        if(powerA == powerB){
            Node<T>* node = new Node<T>( (*polyA) - (*polyB) );
            newPoly->insert(node);
            polyA = polyA->getNext();
            polyB = polyB->getNext();
        }else if(powerA < powerB){ 
            Node<T>* node = new Node<T>(*polyA);
            newPoly->insert(node);
            polyA = polyA->getNext();
        }else{
            Node<T>* node = new Node<T>(*polyB);
            newPoly->insert(node);
            polyB = polyB->getNext();
        }
    }
    while(polyA!=NULL){
        Node<T>* node = new Node<T>(*polyA);
        newPoly->insert(node);
        polyA = polyA->getNext();
    }
    while(polyB!=NULL){
        Node<T>* node = new Node<T>(*polyB);
        newPoly->insert(node);
        polyB = polyB->getNext();
    }
    return *newPoly;
}
template<class T>
Polynomial<T>& Polynomial<T>::operator*(Polynomial<T>& poly){
    Polynomial<T>* newPoly = new Polynomial<T>();
    Node<T>* polyA = start;
    Node<T>* polyB = poly.start;
    while(polyA!=NULL){
        while(polyB!=NULL){
            Node<T>* node = new Node<T>( (*polyA) * (*polyB) );
            newPoly->insert(node);
            polyB = polyB->getNext();
        }
        polyB = poly.start;
        polyA = polyA->getNext();
    }
    return *newPoly;
}
