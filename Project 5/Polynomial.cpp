#include <map>
using namespace std;
template<class T>
class Polynomial{
    private:
        map<int, int> *poly;

        bool hasPower(int x){
            if(poly->find(x)!=poly->end()) return true;
            return false;
        }
    public:
        Polynomial(){
           poly = new map<int,int>();
        }
        Polynomial(string s){
            T coef = 0;
            int power = 0;
            int count = 0;
            bool hasSeenNegative = false;
            bool hasSeenNegativePower = false;
            poly = new map<int, int>();
            for(char x : s){
                if(x == '-' && count == 0) hasSeenNegative = true;
                if(x == '-' && count == 1) hasSeenNegativePower = true;
                if(x>='0' && x<='9' && count == 0){
                    coef = coef * 10 + (x - '0');
                }else if(x>='0' && x<='9' && count == 1){
                    power = power * 10 + (x - '0');
                }
                if(x == ' ')count++;
                if(count == 2){
                    coef = (hasSeenNegative) ? -1*coef : coef;
                    power = (hasSeenNegativePower) ? -1*power : power;
                    (*poly)[power] = (hasPower(power)) ? (*poly)[power] + coef : coef;
                    power = 0;
                    coef = 0;
                    count = 0;
                    hasSeenNegative = false;
                    hasSeenNegativePower = false;
                }
            }
            coef = (hasSeenNegative) ? -1*coef : coef;
            power = (hasSeenNegativePower) ? -1*power : power;
            (*poly)[power] = (hasPower(power)) ? (*poly)[power] + coef : coef;
        }

        ~Polynomial(){
            delete poly;
        }

        Polynomial<T>& operator+(Polynomial<T>& poly){
            Polynomial<T>* ans = new Polynomial<T>();
            auto i = (*(this->poly)).begin();
            auto j = (*(poly.poly)).begin();
            while(i!=(*(this->poly)).end() && j!=(*(poly.poly)).end()){
                int powA = i->first;
                int powB = j->first;
                if(powA == powB){
                    (*(ans->poly))[powA] = i->second + j->second;
                    i++;
                    j++;
                }else if(powA < powB){
                    (*(ans->poly))[powA] = i->second;
                    i++;
                }if(powA > powB) {
                    (*(ans->poly))[powB] = j->second;
                    j++;
                }
            }
            while(i!=(*(this->poly)).end()){
                (*(ans->poly))[i->first] = i->second;
                i++;
            }
            while(j!=(*(poly.poly)).end()){
                (*(ans->poly))[j->first] = j->second;
                j++;
            }
            return *ans;
        }

        Polynomial<T>& operator-(Polynomial<T>& poly){
            Polynomial<T>* ans = new Polynomial<T>();
            auto i = (*(this->poly)).begin();
            auto j = (*(poly.poly)).begin();
            while(i!=(*(this->poly)).end() && j!=(*(poly.poly)).end()){
                int powA = i->first;
                int powB = j->first;
                if(powA == powB){
                    (*(ans->poly))[powA] = i->second - j->second;
                    i++;
                    j++;
                }else if(powA < powB){
                    (*(ans->poly))[powA] = i->second;
                    i++;
                }if(powA > powB) {
                    (*(ans->poly))[powB] = j->second * -1;
                    j++;
                }
            }
            while(i!=(*(this->poly)).end()){
                (*(ans->poly))[i->first] = i->second;
                i++;
            }
            while(j!=(*(poly.poly)).end()){
                (*(ans->poly))[j->first] = j->second*-1;
                j++;
            }
            return *ans;
        }

        Polynomial<T>& operator*(Polynomial<T>& poly){
            Polynomial<T>* ans = new Polynomial<T>();
            for(auto i = (*(this->poly)).begin();i!=(*(this->poly)).end(); i++){
                for(auto j= (*(poly.poly)).begin(); j!=(*(poly.poly)).end(); j++){
                    int power = i->first + j->first;
                    int coef = i->second * j->second;
                    (*(ans->poly))[power] = (ans->poly->find(power)!=(*(ans->poly)).end()) ? (*(ans->poly))[power] + coef : coef;
                }
            }
            return *ans;
        }

        friend ostream& operator<< (ostream& cout, const Polynomial<T>& poly){
            map<int, int> copy = *(poly.poly);
            bool addOperator =false;
            for(auto i = copy.rbegin(); i!=copy.rend(); i++){
                if(i->second == 0) cout << 0;
                else{
                    if(addOperator && i->second > 0) cout << "+";
                    if(i->first == 0) cout << i->second;
                    else cout << i->second << "X^" << i->first;
                    addOperator = true;
                }
                
            }
            return cout;
        }
};