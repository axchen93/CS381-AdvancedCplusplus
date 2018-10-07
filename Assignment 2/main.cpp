#include<iostream>
using namespace std;

//This function always returns true if the inout is either 0 or a power of 2
bool isTrue(int n){
    /* This function works because of logical AND
     * The logical bits of any power of 2 only has one 1 and the rest are 0s
     * So one less than that power of two bits are all the bits flipped
     * When logical is applied, there are no same corresponding bits -> false;
    */
    return (n&(n-1)) == 0;
}

int main(){
    cout << boolalpha;
    cout << isTrue(0) << endl; // true
    cout << isTrue(2) << endl; // true
    cout << isTrue(3) << endl; // false
    cout << isTrue(4) << endl; // true
    cout << isTrue(8) << endl; // true
    cout << isTrue(9) << endl; // false
    cout << isTrue(2048) << endl; // true
    cout << isTrue(2049) << endl; // false
}