#include<iostream>
using namespace std;
class nick
{
private:
int s,t,a[100],p;
int ch;
public:
void get()
{
cout<<"Enter array size: ";
cin>>s;
for(int i=0;i<s;i++)
{
cout<<"Enter numbers"<<i+1<<" : ";
cin>>a[i];
}
cout<<"Pass 0: ";
for(int i=0;i<s;i++)
{
cout<<a[i]<<" ";
}
cout<<endl;
p=0;
}
void mytech(){
for(int i=1;i<s; i++)
{
ch=0;
t=a[i];
int j=i-1;
while(j>=0 && a[j]>t)
{
a[j+1]=a[j];
j--;
ch=1;
}
if(ch==1)
{
a[j+1]=t;
cout<<"Pass "<<++p<< ": ";
for(int i=0;i<s; i++)
cout<<a[i] << " ";
cout<<endl;
}
}
cout<<endl;
}
};
int main()
{
nick o;
o.get();
o.mytech();
}
