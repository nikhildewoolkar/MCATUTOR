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
int c1;
cout<<"from where u wanna insert the element:(1:front 2:rear):-";
cin>>c1;
switch(c1)
{
case 1:
{
cout<<"front enqueue\n";
if(front==-1)
{
front=0;
rear=0;
cout<<"enter the element you want to push into the queue\n";
cin>>num;
s[rear]=num;
cout<<"the number is inserted into the queue\n";
}
else
{
if(front==0)
{
front = size;
}
if((front-1)%size==rear)
{
cout<<"queue exausted........\n";
}
else
{
cout<<"enter the element you want to push into the queue\n";
cin>>num;
--front %= size;
s[front]=num;
cout<<"the number is inserted into the queue\n";
}
}
break;
}
case 2:
{
cout<<"rear enqueue\n";
if(front == -1)
{
front=0; 
rear=0;
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
++rear%=size;
s[rear]=num;
cout<<"the number is inserted into the queue\n";
}	
break;
}
default:
{
cout<<"entered wrong choice...";
break;
}
}
}
void dequeue()
{
cout<<"you have selected dequeue operation\n";
int c2;
cout<<"from where u wanna delete the element:(1:front 2:rear):-";
cin>>c2;
switch(c2)
{
case 1:
{
cout<<"front dequeue\n";
if(rear==-1&&front==-1)
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
++front%=size;
}
}	
break;
}
case 2:
{
cout<<"rear dequeue\n";
if(rear==-1&&front==-1)
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
--rear %=size;
}
}	
break;
}
default:
{
cout<<"entered wrong choice...";
break;
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
int t=front;
cout << "Queue is ";
do
{
cout<<s[t]<<" ";
++t%=size;
}
while(t!=(rear+1)%size);
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
