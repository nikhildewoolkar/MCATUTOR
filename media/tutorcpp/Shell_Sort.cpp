#include<iostream>
using namespace std;
class nick{
    private:
        int s, t, a[100], p,ch;
        
    public:
        void get(){
            cout <<"Enter array size: ";
            cin >> s;

            for(int i = 0; i < s; i++){
                cout << "Enter element no. " << i+1 << " : ";
                cin >> a[i];
            }
            p = -1;
            cout << endl;
            dis();
        }
        void dis(){
          cout << "Pass " << ++p << ": ";
          for(int i = 0; i < s; i++){
              cout << a[i] << " ";
          }
          cout << endl;
        }
        void mytech(){
          get();
          //inc is increment 
          for(int inc = s/2; inc > 0; inc /= 2){
            for(int j = inc; j < s; j++){
              ch = 0;
              for(int k = j - inc; k >= 0; k -= inc){
                if(a[k+inc] > a[k]){
                  break;
                }
                else{
                  t = a[k+inc];
                  a[k+inc] = a[k];
                  a[k] = t;
                  ch = 1;
                }
              }
            }
            if(ch == 1){
            dis();
            }
          }
        }
};

int main(){
    nick o;
    o.mytech();
}
