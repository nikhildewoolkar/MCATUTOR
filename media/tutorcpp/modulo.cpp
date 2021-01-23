#include<iostream>
using namespace std;
class nick{
private:
int n, s,*a,num,add;
public:
void get()
{
do
{
cout << "Enter array size:-";
cin >> s;
cout << "how many numbers you wanna insert:-";
cin >> n;
}
while(n>s);
a=new int[s];
for(int i = 0; i < s; i++)
a[i] = '\0';
}
void mytech()
{
cout << endl;
while(n--)
{
cout << "Enter numbers:-";
cin >> num;
if (num < 0)
{
cout << "Invalid number.Try Again\n";
n++;continue;
}
add = num % s;
lp();
a[add] =  num;
}
dis();
}
void lp(){
while(a[add]!='\0'){
if(add < s-2)
{
add++;
}
else
{
add = 0;
}
}
}
void dis()
{
cout << "\nhashed array is as below\n";
for(int i = 0; i < s; i++){
cout << "array index:-" << i << " : \t";
if(a[i]=='\0')
{
cout << "NULL" << endl;
}
else
{
cout << a[i] << endl;
}
}
}
};
int main()
{
nick o;
o.get();
o.mytech();
}
