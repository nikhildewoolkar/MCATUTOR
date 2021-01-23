#include<iostream>
#include<math.h>
using namespace std;
class nick
{
private:
int n,s,*a,num;
unsigned long int add;
public:
void get()
{
do
{
cout<<"Enter the size of the array: ";
cin>>s;
cout<<"Enter the no. of digits you want to insert: ";
cin>>n;
}
while(n>s);
a=new int[s];
for(int i=0;i<s;i++)
{
a[i]=-1;
}
}
void mytech()
{
cout<<"\n";
while(n--)
{
cout<<"Enter value you want to insert: ";
cin>>num;
if(num< 0)
{
cout<<"Invalid value. Try Again\n";
n++;continue;
}
int t=num;
add=0;
int round = 0;
while(t>0)
{
if((round==0) || (t<s))
{
add+=rev(t%s);
}
else
{
add+= t%s;
}
t/=s;
round++;
}
add%=100;
if(add>=s)
{
add=add%s;
}
lp();
a[add]=num;
}
dis();            
}
void lp()
{
while(a[add]!=-1)
{
if(add<s-2)
{
add++;
}
else
{
add=0;
}
}
}
int rev(int no)
{
if(no<10)
{
return (no*10);
}
else
{
int reverse = 0;
while(no>0){
reverse = (reverse*10)+(no%10);
no/=10;
}
return reverse;
}
}
void dis()
{
cout << "\nhashed array is as below\n";
for(int i=0;i<s;i++)
{
cout << "array Index " << i << " : \t";
if(a[i]==-1)
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
