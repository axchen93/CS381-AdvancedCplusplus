#include<iostream>
#include"Node.h"
#include"Node.cpp"
#include"Polynomial.h"
#include"Polynomial.cpp"

using namespace std;

int main(){
    Node<int> x (2,3);
    Node<int> y (5,3);
    string s = "-1+5x+20x^3-9x^2-2x+x^2-2x^3+x^9,";
    Polynomial<int> poly (s);
    //cout << poly << endl;
}