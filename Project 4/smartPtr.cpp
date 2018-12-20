#include<iostream>
using namespace std;

template<class T>
class smartPtr{
    private:
        T *ptr;
    public:

        smartPtr(T *p = 0){
            ptr(p);
        }

        smartPtr(const smartPtr& rhs){
            ptr = rhs.ptr;
            rhs.ptr = 0;
        }

        ~smartPtr(){
            delete ptr;
        }

        T* operator->(){
            return ptr;
        }

        T& operator*(){
            return *ptr;
        }

};