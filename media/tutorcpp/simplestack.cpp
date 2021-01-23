#include<iostream>
using namespace std;
class nick
{
public:
int top,ele,choice,num,size,s[10];
public:
void push()
{
cout<<"push operation is selected\n";
if(top==size-1)
{
cout<<"stack exausted........\n";
}
else
{
cout<<"enter the element you want to push into the stack\n";
cin>>num;
++top;
s[top]=num;
cout<<"the number is inserted into the stack:-\n";
}
}

void pop()
{
cout<<"you have selected pop operation\n";
if(top==-1)
{
cout<<"no element present in the stack\n";
}
else
{
ele=s[top];
top--;
}
}

void dis()
{

cout<<"display option is selected\n";
if(top==-1)
{
cout<<"no element is present in array\n";
}
else
{
for(int i=top;i>-1;i--)
{
cout<<i<<" : "<<s[i]<<"\n";
}
}
}

void get()
{
top=-1;
cout<<"enter the size of the stack:-\n";
cin>>size;
int s[size];
do
{
cout<<"enter the option you want to select:-(1-push 2-pop 3-display 4-exit):-\n";
cin>>choice;

switch(choice)
{
case 1:
push();
break;

case 2:
pop();
break;

case 3:
dis();
break;

case 4:
break;

default:
cout<<"invalid choice ## enter right choice........\n";
}
}
while(choice!=4);
}
};

int main()
{
nick o;
o.get();
}
