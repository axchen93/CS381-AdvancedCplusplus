#include "Node.h"
#include<iostream>

template<class T>
Node<T>::Node(){
    coefficent = power = next = NULL;
}
template<class T>
Node<T>::Node(T coefficent, int power, Node* next){
    this->coefficent = coefficent;
    this->power = power;
    this->next = next;
}
template<class T>
Node<T>::Node(T coefficent, int power){
    this->coefficent = coefficent;
    this->power = power;
    next = NULL;
}
template<class T>
Node<T>::Node(const Node& object){
    coefficent = object.coefficent;
    power = object.power;
    next = NULL;
}
template<class T>
Node<T>::~Node(){
    delete next;
}
template<class T>
void Node<T>::setNext(Node<T>* next)
{
    this->next = next;
}
template<class T>
T Node<T>::getCoeff(){
    return coefficent;
}
template<class T>
int Node<T>::getPower(){
    return power;
}
template<class T>
Node<T>* Node<T>::getNext(){
    return next;
}
template<class T>
Node<T>& Node<T>::operator+(const Node& object){
    T newCoeffcient = this->coefficent + object.coefficent;
    Node<T>* newNode = new Node<T>(newCoeffcient, this->power);
    return *newNode;
}
template<class T>
Node<T>& Node<T>::operator-(const Node& object){
    T newCoeffcient = this->coefficent - object.coefficent;
    Node<T>* newNode = new Node<T>(newCoeffcient, this->power);
    return *newNode;
}
template<class T>
Node<T>& Node<T>::operator*(const Node& object){
    T newCoeffcient = this->coefficent * object.coefficent;
    int newPower = this->power + object.power;
    Node<T>* newNode = new Node<T>(newCoeffcient, newPower);
    return *newNode;
}

template<class T>
void Node<T>::operator=(const Node<T>& object){\
    this->coefficent = object.coefficent;
    this->power = object.power;
}