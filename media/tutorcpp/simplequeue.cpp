#include<iostream>
using namespace std;
class nick
{
public:
int front,rear,choice,num,size,s[10],ele;
public:
void enqueue()
{
cout<<"enqueue operation is selected\n";
if(rear==size-1)
{
cout<<"queue exausted........\n";
}
else
{
cout<<"enter the element you want to push into the queue\n";
cin>>num;
++rear;
s[rear]=num;
cout<<"the number is inserted into the queue\n";
}
}

void dequeue()
{
cout<<"you have selected dequeue operation\n";
if(front>=rear)
{
cout<<"no element present in the stack\n";
}
else
{
ele=s[front];
front=front+1;
cout<<"you have removed "<<ele<<" front the queue....";
}
}

void dis()
{

cout<<"display option is selected\n";
if(front>rear)
{
cout<<"no element is present in array\n";
}
else
{
for(int i=front;i<=rear;i++)
{
cout<<i<<" : "<<s[i]<<"\n";
}
}
}

void get()
{
front=0;
rear=-1;
cout<<"enter the size of the queue:-\n";
cin>>size;
int s[size];
do
{
cout<<"enter the option you want to select:-(1-enqueue 2-dequeue 3-display 4-exit):-\n";
cin>>choice;
switch(choice)
{
case 1:
enqueue();
break;

case 2:
dequeue();
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
