#include<iostream>
#include<fstream>
#include"Node.h"
#include"Node.cpp"
#include"Polynomial.h"
#include"Polynomial.cpp"

using namespace std;

int main(){
    ifstream input;
    ofstream output;
    input.open("input.txt");
    output.open("output.txt");
    string s;
    string p;
    getline(input, s);
    getline(input, p);
    Polynomial<int> poly1 (s);
    Polynomial<int> poly2 (p);
    output << "Polynomial A: \n" << poly1 << endl;
    output << "Polynomial B: \n" << poly2 << endl;
    Polynomial<int> polyAdd = poly1 + poly2;
    output << "Polynomial A + Polynomial B: \n" << polyAdd << endl;
    Polynomial<int> polySub = poly1 - poly2;
    output << "Polynomial A - Polynomial B: \n" << polySub << endl;
    Polynomial<int> polyMult = poly1 * poly2;
    output << "Polynomial A * Polynomial B: \n" << polyMult << endl;
    input.close();
    output.close();
}
