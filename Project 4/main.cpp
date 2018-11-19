#include <iostream>
#include "SA.cpp"

using namespace std;

int main(int argc, char * argv[]) {
    SA<int> s1(10);
    SA<int> s2(1,6);
    
    for(int i=0;i<10;i++){
        s1[i]=10-i;
        cout<<s1[i]<<" ";
    }
    cout<<endl;
    
     for(int i=1;i<=6;i++){
         s2[i]=i;
         cout<<s2[i]<<" ";
     }
     cout<<endl;
    
      SA<int> s3={1,2,3,4,5,6,7,8,9};
      for(int i=0;i<9;i++){
          cout<<s3[i]<<" ";
      }
      cout<<endl;
    
    return 0;
}
