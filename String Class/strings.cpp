#include <iostream>
#include <cstring>
#include "strings.h"

/*
Creates an empty string of length 0
BTS its a array of length 1 that contains the null terminator
*/
String::String(){
    length = 0;
    str = new char[1];
    str[0] = '\0';
}
/*
Copy Constructor String --> String
create a string of length of the copy string +1 for the null terminator
strcpy function copies the original c-str to the new c-str
the length of the new str is the length of the orignal str
*/
String::String(const String & str){
    this->str = new char[ str.length + 1];
    strcpy(this->str, str.str);
    length = str.length;
}
/*
Create a blank string with the size of the param
BTS the the newly created array will all be initalized to ' '
and the final char is the terminating char
*/
String::String(const int size){
    str = new char[ size +1 ];
    length = size;
    char* ptr = str;
    for(int i = 0; i<size; i++){
        *ptr = ' ';
        ptr++;
    }
    *ptr = '\0';
}
/*
Convert Constructor
strlen a cstring library, returns the length of a cstring
create a new str with length + 1 for the null terminator
strcpy function to copy the orginal to the new
*/
String::String(const char* cstr){
    length = strlen(cstr);
    str = new char[ length + 1];
    strcpy(str, cstr);
}
/*
Destructor
deletes the only dynamic array
*/
String::~String(){
    delete[] str;
}
/*

*/
String String::operator+ (const String strarg) const{

}
/*

*/
int String::operator< (const String) const{
    
}
/*

*/
int String::operator> (const String) const{

}
/*
Assignment operator overload
*/
String& String::operator= (const String&){
}
/*
Selection sort
*/
void sort(String*, int, int){

}