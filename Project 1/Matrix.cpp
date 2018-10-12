#include<iostream>
#include<cstdlib>
#include<cassert>
using namespace std;

template<class T>
class SA{
private:
    int low, high;
    T* p;
public:
 // default constructor
 // allows for writing things like SA a;
    SA(){
        low=0; 
        high=-1;
        p=NULL;
    }
 // 2 parameter constructor lets us write
 // SA x(10,20);
    SA(int l, int h){
        if((h-l+1)<=0)
            {cout<< "constructor error in bounds definition"<<endl;
        exit(1);}
        low=l;
        high=h;
        p = new T[h-l+1];
    }


    // single parameter constructor lets us
    // create a SA almost like a "standard" one by writing
    // SA x(10); and getting an array x indexed from 0 to 9

    SA(int i){
        low=0; 
        high=i-1;
        p=new T[i];
    }
 // copy constructor for pass by value and
 // initialization

    SA(const SA<T> & s){
        int size=s.high-s.low+1;
        p=new T[size];
        for(int i=0; i<size; i++)
            p[i]=s.p[i];
        low=s.low;
        high=s.high;
    }
    // destructor

    ~SA(){
        delete [] p;
    }
 //overloaded [] lets us write
 //SA x(10,20); x[15]= 100;

    T& operator[](int i){
        if(i<low || i>high)
            {cout<< "index "<<i<<" out of range"<<endl;
        exit(1);}
        return p[i-low];
    }
    

    // overloaded assignment lets us assign
    // one SA to another

    SA & operator=(const SA<T> & s){
        if(this==&s)return *this;
        delete [] p;
        int size=s.high-s.low+1;
        p=new T[size];
        for(int i=0; i<size; i++)
            p[i]=s.p[i];
        low=s.low;
        high=s.high;
        return *this;
    }

    // overloads << so we can directly print SAs
    friend ostream& operator<<(ostream& os, SA<T> s){
        int size=s.high-s.low+1;
        for(int i=0; i<size; i++)
        cout<<s.p[i] << " ";
        return os;
    }

};

template<class T>
class Matrix{
    private:
        int x_high;
        int x_low;
        int y_high;
        int y_low;
        SA< SA <T> > * matrix;
    public:

        Matrix(){
            x_high = x_low = y_high = y_low = 0;
            matrix = NULL;
        } 

        Matrix(int xl, int xh, int yl, int yh){
            x_high = xh;
            x_low = xl;
            y_high = yh;
            y_low = xl;
            matrix = new SA< SA<T> > (x_low, x_high);
            for(int i = x_low; i< x_high+1 ; i++){
                SA<T> temp (y_low, y_high);
                (*matrix)[i] = temp;
            }
        }

        Matrix(Matrix<T>& x  ){
            x_high = x.x_high;
            x_low = x.x_low;
            y_high = x.y_high;
            y_low = x.y_low;
            matrix = new SA< SA<T> > (x_low, x_high);
            for(int i = x_low; i< x_high+1 ; i++){
                (*matrix)[i] = x[i];
            }
        }

        ~Matrix(){
            delete matrix;
        }

        SA<T>& operator[](int i){
            return (*matrix)[i];
        }

        Matrix<T>& operator+(Matrix<T>& x ){
            if(x_high - x_low + 1 != x.x_high - x.x_low + 1 && y_high - y_low + 1 != x.y_high - x.y_low + 1){
                cout << "different size matricies, cannot add\r\n";
                exit(1);
            }
            Matrix<T> *ans = new Matrix<T> (x);
            int row = x_high - x_low + 1;
            int col = y_high - y_low + 1;

            for(int i = 0; i< row; i++){
                SA<T> temp = (*matrix)[x_low + i];
                for(int j = 0; j< col; j++){
                    (*ans)[ans->x_low+i][ans->y_low+j] += temp[y_low+j];
                }
            }
            return *ans;
        }

        Matrix<T>& operator*(Matrix<T>& x ){
            if(y_high- y_low +1 != x.x_high-x.x_low+1){
                cout << "Cannot do multiply these 2 matrix!\n";
                exit(1);
            }
            int row = x_high - x_low;
            int col = x.y_high - x.y_low;
            Matrix<T> *ans = new Matrix<T> (0, row, 0 ,col);

            int size = y_high- y_low +1;
            for(int i = 0; i<row+1; i++){
                for(int j = 0; j<col+1; j++){
                    (*ans)[i][j] = 0;
                    for(int k = 0; k<size; k++){
                        (*ans)[i][j] += (*matrix)[x_low+i][y_low+k] * (*x.matrix)[x.x_low+k][x.y_low+j];
                    }
                }
            }

            return *ans;

        }

        void print(){
            for(int i = x_low; i< x_high +1; i++){
                SA<T> temp = (*matrix)[i];
                cout << temp << endl;
            }
        }

        
};

int main(){
    Matrix<int> x (0,1,0,1);
    Matrix<int> y (2,3,2,3);
   
    x[0][0] = 1; x[0][1] = 2; x[1][0] = 3; x[1][1] = 4;
    y[2][2] = 5; y[2][3] = 6; y[3][2] = 7; y[3][3] = 8;

    cout << "Matrix X:\n";
    x.print();
    cout << "Matrix Y:\n";
    y.print();

    Matrix<int> z = x + y;

    cout << "X + Y :\n";
    z.print();

    Matrix<int> a (0,1,0,2);
    Matrix<int> b (0,2,0,1);

    a[0][0] = 1; a[0][1] = 2; a[0][2] = 3; a[1][0] = 4; a[1][1] = 5; a[1][2] = 6;
    b[0][0] = 7; b[0][1] = 8; b[1][0] = 9; b[1][1] = 10; b[2][0] = 11; b[2][1] = 12;
    cout << "Matrix a:\n";
    a.print();
    cout << "Matrix b:\n";
    b.print();

    Matrix<int> c = a * b;
    cout << "a * b :\n";
    c.print();

    Matrix<int> d = x * y;

    cout << "x * y :\n";
    d.print();

    
} 
