#include<iostream>

template<class T>
T sum(T arg);
template<class T, class... Args>
T sum(T args1, Args... argsR);

int main(int args, char** argv){
    std::cout<< sum(1,2,3,4,5) << std::endl;
    std::cout<< sum(1,2,3,4,5,6) << std::endl;
}

//Basecase for the recursive calls.
template<class T>
T sum(T arg){
    return arg;
}

/* 
Generic function that takes any number of arguments of generic type T
Params is the first argument, argsR is the remaining arguments
Recursive function that call the ramining arguments
*/
template<class T, class... Args>
T sum(T args1, Args... argsR){
    return args1 + sum(argsR...);
}
