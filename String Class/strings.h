#ifndef STRINGS_H
#define STRINGS_H
class String{
    private:
        char* str; // pointer to the start of the char array
        int length; // integer keeping the length of the string
    public:
        enum SortOrder {Asc, Dec};
        enum ErrorsIO {ReadFail, WriteFail};
        String(); // default constructor
        String(const String &); // copy constructor
        String(const int); //blank string of a certain size
        String(const char*); // create from a C String
        ~String(); // destructor
        String operator+ (const String) const;
        int operator< (const String) const;
        int operator> (const String) const;
        String& operator= (const String&); // assignment operator overload
        friend void sort(String*, int, int); // selection sort
};

#endif