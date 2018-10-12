#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include<iostream>

template<class T>
class Polynomial{
    private:
        Node<T>* start;
    public:
        Polynomial();
        Polynomial(string s);
        ~Polynomial();
        void insert(Node<T>* node);
        Polynomial<T>& operator+(Polynomial<T>& poly);
        Polynomial<T>& operator-(Polynomial<T>& poly);
        Polynomial<T>& operator*(Polynomial<T>& poly);
        friend ostream& operator<< (ostream& cout, const Polynomial<T>& poly){
            Node<T>* copy = poly.start;
            bool addOperator =false;
            while(copy!=NULL){
                if(addOperator && copy->getCoeff()>0) cout << "+";
                cout << *copy;
                copy = copy->getNext();
                addOperator = true;
            }
            return cout;
        }
};


#endif