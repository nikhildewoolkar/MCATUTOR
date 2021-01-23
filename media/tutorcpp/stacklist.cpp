#include<iostream>
#include<malloc.h>
using namespace std;

struct node{
    int data;
    struct node *next;
}*list = NULL, *top = NULL, *p, *q;

class nick{
    int action, value;
    string str;
    public:
        void mytech(){
            do{
                cout << "\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter action no. you want to perform: ";
                cin >> action;
                switch (action)
                {
                    case 1:
                        push();
                        break;
                    case 2:
                        pop();
                        break;
                    case 3:
                        display();
                        break;
                    case 4:
                        break;
                    default:
                        cout << "Invalid input.";
                }
            }while(action != 4);
        }

        void push(){
            cout << "Enter value you want to insert: ";
            cin >> value;
            p = (struct node*)malloc(sizeof(node));
            p->data = value;
            p->next = NULL;
            top = p;
            if(list==NULL)
                list = p;
            else{
                q = list;
                while(q->next!=NULL)
                    q = q->next;
                q->next = p;
            }
        }

        void pop(){
            if(list==NULL)
                cout << "Underflow.\n";
            else{
                cout << top->data << " has been popped." << endl;
                q = list;
                if(q->next==NULL)
                    list = top = NULL;
                else{
                    while(q->next != top && q->next!=NULL)
                        q = q->next;
                    free(top);
                    top = q;
                    q->next=NULL;
                }
            }
        }

        void display(){
        if(list==NULL)
            cout << "No Element in the stack." << endl;
        else{
            p = list;
            cout << "Elements in the stack are: ";
            while(p!=NULL){
                cout << p->data << " ";
                p = p->next;
            }
            cout << endl;
        }
    }        
};

int main(){
    nick o;
    o.mytech();

}
