#include<iostream>
using namespace std;
class Nick
{
private:
int a[100],num,i,j,temp,p;
public:
void getData() {
cout<<"Enter the size of array : ";
cin>>num;
cout<<"Enter "<<num<<" Elements : ";
for(i=0;i<num;i++)
{
cin>>a[i];
}	
}
void showData()
{
cout<<"Array Elements : ";
for(i=0;i<=num;i++)
{
cout<<"\t"<<a[i];
}
cout<<"\n";
}
void linearSearch()
{
int no,flag,x;
flag = 0;
cout<<"\nEnter the element which you want to search ? ";
cin>>no;
for(x=0;x<num;x++)
{
if(no==a[x])
{
flag = 1;
cout<<"\nEntered Element "<<no<<" Found at "<<x+1<<" with index no "<<x<<endl;
break;
}
}
if(flag==0)
{
cout<<"\nEnterd Value Not Found...array exausted &Added to the End.\n";
a[x]=no;
showData();
}
}
};
int main()
{
Nick n;
n.getData();
n.linearSearch();
return 0;
}
