#include<iostream>
using namespace std;
class Nick{
private:
int a[100],num,i,j,temp;
public:
void getData()
{
cout<<"Enter the size of array : ";
cin>>num;
cout<<"Enter "<<num<<" Elements : ";
for(i=0;i<num;i++)
{
cin>>a[i];
}	
}
void showData() {
cout<<"Array Elements : ";
for(i=0;i<num;i++)
{
cout<<"\t"<<a[i];
}
cout<<"\n";
}
void binarySearch() {
int no,flag,k,low,high,mid;
flag = 0;
cout<<"\nEnter the element/number which you want to search ? ";
cin>>no;
low=0;
high=num-1;
do
{
mid=(low+high)/2;
if(no==a[mid])
{
flag=1;
cout<<"\nEntered Element "<<no<<" Found at "<<mid+1<<" with index no "<<mid<<endl;
break;
}
if(no>a[mid])
{
low=mid+1;
}
if(no<a[mid])
{
high=mid-1;
}
}
while(low<=high);
if(flag==0)
{
cout<<"\nEnterd Value Not Found.array exausted & Added in the End.\n";
}
}
void bubbleSort()
{
for(int i=0;i<(num-1);i++)
{
for(j=0;j<(num-i)-1;j++)
{
if(a[j] > a[j+1])
{
a[j]>a[j+1];
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}	
}
cout<<"\t** After Sorting **\n";
showData();
}
};
int main()
{
Nick n;
n.getData();
n.bubbleSort();
n.binarySearch();
return 0;
}
