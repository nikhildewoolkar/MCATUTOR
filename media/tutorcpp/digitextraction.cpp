#include<iostream>
#include<math.h>
using namespace std;

class nick{
private:
int n,s,*a,num,add,*loc,no;
public:
void get()
{
do
{
cout << "Enter the size of the array: ";
cin >> s;
cout << "Enter the no. of digits you want to insert: ";
cin >> n;
}
while(n>s);
a=new int[s];
cout<<"\nEnter the no. of digits you want to extract: ";
cin>>no;
loc = new int[no];
for(int i=0;i<no;i++)
{
cout<<"Enter location no. "<<i+1<<" you want to extract: ";
cin >> loc[i];
}
sort();
a= new int[s];
for(int i=0; i<s;i++)
{
a[i]=-1;
}
}
void mytech()
{
cout<<"\n";
while(n--)
{
add= 0;
cout<<"Enter value you want to insert: ";
cin>>num;
if(num < 0)
{
cout<< "Invalid Input. Try Again\n";
n++;continue;
}
for(int i=0;i< no; i++)
{
num+= ((num% int(pow(10.0,float(loc[i])))) / (int(pow(10.0,float(loc[i])))/10)) * int(pow(10.0,float(i)));
}
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
void sort()
{
for(int i=0;i<no;i++)
{
for(int j=0;j<(no-i)-1;j++)
{
if(a[j]>a[j+1])
{
int t = a[j];
a[j] = a[j+1];
a[j+1]=t;
}
}
}
}
void dis()
{
cout << "\nhashed array is as below\n";
for(int i=0;i< s;i++)
{
cout << "Index no. " << i <<" : \t";
if(a[i]==-1)
cout<<"NULL"<<endl;
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
