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
    bool carrot = false;
    bool hasSeenNegative = false;
    bool hasSeenX = false;
    bool hasSeenNum = false;
    int power = 0;
    start = NULL;
    for(char x : s){
        if(carrot && (x >= '0' && x <='9')){
            power = power * 10 + (x - '0');
        }else if(carrot && (x == '+' || x=='-')){
            if(coef == 0) coef = 1;
            Node<T>* node = (hasSeenNegative) ? new Node<T>(coef*-1,power) : new Node<T>(coef,power);
            cout << "node: " << *node << endl;
            insert(node);
            carrot = false;
            hasSeenX = false;
            hasSeenNegative = (x=='-') ? true: false;
            power = 0;
            coef = 0;
        }else if(!carrot && (x == '+' || x=='-')){
            hasSeenNegative = (x=='-') ? true: false;
        }else if(!carrot && (x >= '0' && x <='9')){
            coef = coef * 10 + (x - '0');
        }else if(x=='^'){
            carrot = true;
        }else{
            hasSeenX = true;
        }
    }
    if(coef == 0) coef = 1;
    Node<T>* node = (hasSeenNegative) ? new Node<T>(coef*-1,power) : new Node<T>(coef,power);
    cout << "node: " << *node << endl;
    insert(node);
}
template<class T>
void Polynomial<T>::insert(Node<T>* node){
    Node<T>* copy = start;
    if(copy == NULL){
        start = node;
        return;
    }
    Node<T>* previous = copy;
    while(copy!=NULL){
        int powerA = node->getPower();
        int powerB = copy->getPower();
        if(powerA == powerB){
            *copy = (*copy + *node);
            break;
        }
        if(powerB > powerA){
            break;
        }
        previous = copy;
        copy = copy->getNext();
    }
    node->setNext(copy);
    previous->setNext(node);
}