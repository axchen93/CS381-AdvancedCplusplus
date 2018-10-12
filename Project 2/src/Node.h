#ifndef NODE_H
#define NODE_H
#include<iostream>
using namespace std;
template<class T>
class Node{
    private:
        T coefficent;
        int power;
        Node* next;
    public:
        Node();
        Node(T coefficent, int power, Node<T>* next);
        Node(T coefficent, int power);
        Node(const Node& object);
        T getCoeff();
        int getPower();
        Node<T>* getNext();
        void setNext(Node<T>* next);
        Node<T>& operator+(const Node& object);
        Node<T>& operator-(const Node& object);
        Node<T>& operator*(const Node& object);
        void operator=(const Node& object);
        friend ostream& operator<< (ostream& cout, const Node<T>& object){
            if(object.power == 0){
                cout << object.coefficent;
                return cout;
            }
            cout << object.coefficent << "X^" << object.power;
            return cout;       
        }
};

#endif