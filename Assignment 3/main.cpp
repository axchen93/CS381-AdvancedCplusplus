//Problem: Given n, find the number of ones in the integers 1 – n
#include<iostream>
#include<string>
using namespace std;

/*
    function is a pass by reference rather than returned value
    convert the integer of 1 - input into a string 
    iterate through the string and count the number char 1's that are seen
*/
void numOnes(int input, int &count){
    count = 0; // ensures count is always reset from previous calls
    int number = 1 - input;
    string strNum = to_string(number);
    for(char i : strNum) 
        if(i == '1') count++;

}

int main(){
    int num;
    numOnes(111112, num);
    cout << num << endl;
}