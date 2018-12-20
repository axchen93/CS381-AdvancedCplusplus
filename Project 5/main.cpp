#include<iostream>
#include<fstream>
#include"Polynomial.cpp"

using namespace std;

int main(){
    ifstream input;
    ofstream output;
    input.open("input.txt");
    output.open("output.txt");
    int counter = 0;
    while(input){
        output << "--------------------------------------------------------------------------" << endl;
        string s;
        string p;
        getline(input, s);
        getline(input, p);
        if(s=="" || p == "") break;
        output << ++counter << ")\r\n";
        output << "Input strings: \r\n";
        output << "A: " << s << endl;
        output << "B: " << p << endl;
        Polynomial<int> poly1 (s);
        Polynomial<int> poly2 (p);
        output << "Polynomial A: " << poly1 << endl;
        output << "Polynomial B: " << poly2 << endl;
        Polynomial<int> polyAdd = poly1 + poly2;
        output << "Polynomial A + Polynomial B: " << polyAdd << endl;
        Polynomial<int> polySub = poly1 - poly2;
        output << "Polynomial A - Polynomial B: " << polySub << endl;
        Polynomial<int> polyMult = poly1 * poly2;
        output << "Polynomial A * Polynomial B: " << polyMult << endl;
    }
    
    input.close();
    output.close();
}