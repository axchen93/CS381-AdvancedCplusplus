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
        void insert(Node<T>* node);
        friend ostream& operator<< (ostream& cout, const Polynomial<T>& poly){
            Node<T>* copy = poly.start;
            while(copy!=NULL){
                if(copy->getCoeff() < 0){
                    cout << "-" << *copy;
                }else{
                    cout << *copy;
                }
                copy = copy->getNext();
            }
            return cout;
        }
};


#endif