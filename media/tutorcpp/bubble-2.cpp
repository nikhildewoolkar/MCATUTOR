#include<iostream>
using namespace std;
class nick
{
private:
int s, t, a[100], p,ch;
public:
void get()
{
cout<<"Enter array size: ";
cin>>s;
for(int i = 0; i < s; i++)
{
cout<<"Enter the numbers: "<<i+1<<" : ";
cin>>a[i];
}
cout<<"Pass 0: ";
for(int i=0;i<s;i++)
{
cout<<a[i]<<" ";
}
cout<<endl;
}
void mytech()
{
p=0;
for(int i=0;i<s;i++)
{
ch=0; 
for(int j=0;j<(s-i)-1;j++)
{
if(a[j]>a[j+1])
{
t=a[j];
a[j]=a[j+1];
a[j+1]=t;
p++;
ch=1;
}
}
if(p==0)
{
cout<<"Array is already sorted.";
break;
}
else if(ch==1)
{
cout<<"Pass "<<i+1<<": "; 
for(int i=0;i<s;i++)
cout<<a[i] <<" ";  
cout<<endl;
}
else
break;
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
