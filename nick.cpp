#include<iostream>
#include<fstream>
#include<string>
#include <bits/stdc++.h>
#include <cstdlib> 

using namespace std;
class nick
{
public:
int s,a[100],n[100],x,t;
string line;
void get()
{
	ifstream myFile;
myFile.open("array.csv");
getline(myFile, line, ',');
        int b=0;
        stringstream nick (line);
        nick>>b;
        s=b;
int i=1;
while (!myFile.eof())
    {
        
        getline(myFile, line, ',');
        int b=0;
        stringstream nick (line);
        nick>>b;
cout<<b;
        //int b = stoi(line);
        n[i]=b;
        i++;
        }
cout<<s;
for(int i=1;i<=s;i++)
{
a[i-1]=n[i];
}
	std::ofstream ofs;
ofs.open("ex.txt", std::ofstream::out | std::ofstream::trunc);
ofs.close();
}

void dis()
{
cout<<"jierndc";
	fstream file;
	file.open("ex.txt",ios::out|ios::in|ios::app);
	cout<<"the output is:-";
	file<<"pass:- ";
for(int i=0;i<s;i++)
{
file<<a[i]<<" ";	
}
file<<endl;
file.close();
for(int i=0;i<s;i++)
{

cout<<a[i]<<" ";

}
}
void mytech()
//x=max value
{
t=0;
x=s;
while(x>0)
{
for(int i=0;i<x-1;i++)
{
if(a[i]>a[x-1])
{
t=a[i];
a[i]=a[x-1];
a[x-1]=t;
}
}
cout<<endl;
dis();
x--;
}
}
};
int main()
{ nick o;
o.get();
cout<<"Your array : "<<endl;
o.mytech();
return 0;
}
