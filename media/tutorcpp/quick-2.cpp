#include<iostream>
using namespace std;
class nick
{
private:
int s, t, a[100], p, mid;
public:
void get()
{
cout<<"enter array size:-";
cin>>s;
for(int i=0;i<s;i++)
{
cout<<"enter numbers:-"<<i+1<<" : ";
cin>>a[i];
}
p=-1;
cout<<endl;
dis();
mytech(0,s-1);
}
void dis()
{
cout<<"Pass "<<++p<<": ";
for(int i=0;i<s;i++)
{
cout<<a[i]<<" ";
}
cout << endl;
}
void mytech(int f,int l)
{
if(f<l)
{
mid=div(f,l);
mytech(f,mid-1);
mytech(mid+1,l);
}
}
int div(int f,int l)
{
int piv=a[f];
int i=f;
int j=l;
while(i<j)
{
while(a[i]<=piv)
i++;
while(a[j]>piv)
j--;
if(i<j)
{
t=a[i];
a[i]=a[j];
a[j]=t;
}
}
if(a[f]!=a[j])
{
t=a[f];
a[f]=a[j];
a[j]=t;
dis();
}
return j;
}
};
int main()
{
nick o;
o.get();
}
