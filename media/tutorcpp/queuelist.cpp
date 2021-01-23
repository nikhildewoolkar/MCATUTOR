#include<iostream>
#include<malloc.h>
using namespace std;

struct node{
    int data;
    struct node *next;
}*front=NULL, *rear=NULL, *p, *q, *r, *s;

class nick{
    int action, value;

    public:
    mytech(){
        do{
            cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter action you want to perform: ";
            cin >> action;
            switch (action)
            {
            case 1:
                enqueue();
                break;
            
            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;
            
            case 4:
                break;
            
            default:
                cout << "Invalid input." << endl;
                break;
            }
        }while(action != 4);
    }
    void enqueue(){
        cout << "Enter value you want to insert: ";
        cin >> value;
        p = (struct node*)malloc(sizeof(node));
        p->data = value;
        p->next = NULL;
        if(front==NULL){
            front = p;
            front = rear = p;
        }
        else{
            q = front;
            while(q->next!=NULL)
                q = q->next;
            q->next = p;
            rear = p;
        }
    }

    void dequeue(){
        if(front==NULL)
            cout << "Underflow." << endl;
        else{
            cout << front->data << " has been removed." << endl;
            front = front->next;
        }
    }

    void display(){
        if(front==NULL)
            cout << "No Element in the Queue.";
        else{
            p = front;
            cout << "Elements in the Queue are: ";
            while(p!=NULL){
                cout << p->data << " ";
                p = p->next;
            }
        }
    }
};

int main(){
    nick o;
    o.mytech();
}
