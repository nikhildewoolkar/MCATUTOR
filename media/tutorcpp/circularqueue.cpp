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
if(front==-1)
{
front=rear=0;
cout<<"enter the element you want to push into the queue\n";
cin>>num;
s[rear]=num;
cout<<"the number is inserted into the queue\n";
}
else if((rear+1)%size==front)
{
cout<<"queue exausted........\n";
}
else
{
cout<<"enter the element you want to push into the queue\n";
cin>>num;
rear=(rear+1)%size;
s[rear]=num;
}
}
void dequeue()
{
cout<<"you have selected dequeue operation\n";
if(rear==-1)
{
cout<<"no element present in the stack\n";
}
else
{
if(rear==front)
{
ele=s[front];
cout<<"you have removed "<<ele<<" front the queue....";
rear=-1;
front=-1;
}
else
{
ele=s[front];
cout<<"you have removed "<<ele<<" front the queue....";
front=(front+1)%size;
}
}
}

void dis()
{
cout<<"display option is selected\n";
if(front==-1)
{
cout<<"no element is present in array\n";
}
else
{
for(int i=front;i!=rear;++i %= size)
{
cout<<i<<" : "<<s[i]<<"\n";
}
cout<<rear<< " : "<<s[rear]<<"\n";
}
}

void get()
{
rear=-1;
front=-1;
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
return 0;
}
