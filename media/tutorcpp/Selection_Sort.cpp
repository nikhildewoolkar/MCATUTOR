#include<iostream>
using namespace std;
class nick
{
public:
int s,a[100],x,t;
void get()
{
cout<<"Enter array size"<<endl;
cin>>s;
cout<<"Enter the numbers:"<<endl;
for(int i=0;i<s;i++)
{
cin>>a[i];
}
}
void dis()
{
for(int i=0;i<s;i++)
{
cout<<a[i]<<" ";
}
}
void mytech()
//x=max value
{
t=0;
x=s;
while(x>0)
{
for(int i=0;i<x-1;i++)
{
if(a[i]>a[x-1])
{
t=a[i];
a[i]=a[x-1];
a[x-1]=t;
}
}
cout<<endl;
dis();
x--;
}
}
};
int main()
{ nick o;
o.get();
cout<<"Your array : "<<endl;
o.mytech();
return 0;
}
