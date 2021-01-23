#include<iostream>
#include<malloc.h>
using namespace std;

struct node{
    int data;
    struct node *next;
}*list=NULL, *p, *q, *r, *s;

class nick{
    int action, value, element;
    public:
    void mytech(){
        do{
            cout << endl << "1. Insert at Begining\n2. Insert at the End\n3. Insert Before an element.\n4. Insert after an element\n5. Delete at beginning\n6. Delete at end\n7. Delete Particular value\n8. Display\n9.Count\n10. Reverse\n11. Sort\n12. Exit\nEnter action you want to perform: ";
            cin >> action;
            switch (action)
            {
                case 1:
                    insert_b();
                    break;
                case 2:
                    insert_e();
                    break;
                case 3:
                    insert_be();
                    break;
                case 4:
                    insert_ae();
                    break;
                case 5:
                    delete_b();
                    break;
                case 6:
                    delete_e();
                    break;
                case 7:
                    delete_v();
                    break;
                case 8:
                    display();
                    break;
                case 9:
                    count();
                    break;
                case 10:
                    reverse();
                    break;
                case 11:
                    sort();
                    break;
                case 12:
                    break;
            default:
                cout << "Invalid entry.\nTry again.\n";
                break;
            }
        }while(action!=12);
    }

    void insert_b(){
        cout << "Enter value you want to insert: ";
        cin >> value;
        p = (struct node*)malloc(sizeof(node));
        
        p->data = value;
        if(list==NULL)
            p->next = p;
        else{
            q = list;
            while(q->next!=list)
                q = q->next;
            q->next = p;
            p->next = list;
        }
        list = p;
    }

    void insert_e(){
        cout << "Enter value you want to insert: ";
        cin >> value;
        p = (struct node*)malloc(sizeof(node));
        q = (struct node*)malloc(sizeof(node));
        p->data = value;
        if(list==NULL){
            p->next = p;
            list = p;
        }
        else{
            q = list;
            while(q->next!=list)
                q = q->next;
            q->next = p;
            p->next = list;
        }
    }
    void insert_be(){
        cout << "Enter element before you want to insert the value: ";
        cin >> element;
        cout << "Enter value you want to insert: ";
        cin >> value;
        p = (struct node*)malloc(sizeof(node));
        p->data = value;
        q = list;
     
        while((q->data != element) && (q->next != NULL)){
            r = q;
            q = q->next;
        }
        if(q->data==element)
         {
            if(list->data==element){
                s = list;
                while(s->next!=list)
                    s = s->next;
                s->next = p;
                p->next = list;
                list = p;
            }
            else{
                r->next = p;
                p->next = q;
            }
        }
        else{
            cout << "Data not found.";
        }
        
    }
    void insert_ae(){
        cout << "Enter element after you want to insert the value: ";
        cin >> element;
        cout << "Enter value you want to insert: ";
        cin >> value;
        p = (struct node*)malloc(sizeof(node));
        p->data = value;
        q = list;
        r = q->next;
        while((q->data != element) && (q->next != NULL)){
            q = r;
            r = r->next;
        }
        if(q->data != element)
            cout << "Data not found.";
        else if(r == list){
            q->next = p;
            p->next = list;
        }
        else{
            q->next = p;
            p->next = r;
        }
    }

    void delete_b(){
        if(list==NULL)
            cout << "List is empty nothing to delete.";
        else{
            p = list;
            while(p->next!=list){
                q = p;
                p = p->next;
            }
            if(list == p)
                list = NULL;
            else{
                q->next = list;
                list = list->next;
            }
            cout << "Element has been deleted." << endl;
        } 
    }

    void delete_e(){
        if(list==NULL)
            cout << "List is empty nothing to delete." << endl;
        else{
            p = list;
            while(p->next != list){
                q = p;
                p = p->next;
            }
            if(list == p)
                list = NULL;
            else
                q->next = list;
            cout << "Element has been deleted." << endl;
        }
    }

    void delete_v(){
        if(list==NULL)
            cout << "List is empty nothing to delete." << endl;
        else{
            p = list;
            q = p;
            cout << "Enter value you want to delete: ";
            cin >> value;
            while(p->data != value && p->next!=list){
                q = p;
                p = p->next;
            }
            if(p->data != value)
                cout << "Element not found.";
            else{
                if(p==q){
                    if(p->next==p)
                        list = NULL;
                    else{
                        r = list;
                        while(r->next!=list){
                            r = r->next;
                        }
                        r = p->next;
                        list = p;
                    }
                }
                else if(p->next = list){
                    q->next = list;
                }
                else
                    q->next = p->next;
                cout << "Element has been deleted." << endl;
            }
        }
    }

    void display(){
        if(list==NULL)
            cout << "No Element in the linked list." << endl;
        else{
            p = list;
            cout << "Elements in the linked list are: ";
            do{
                cout << p->data << " ";
                p = p->next;
            }while(p!=list);
            cout << endl;
        }
    }

    void count(){
        int count = 0;
        if(list!=NULL){
            p = list;
            do{
                count++;
                p = p->next;
            }while(p != list);
        }
        cout << "Count = " << count << endl;
    }

    void reverse(){
        if(list==NULL)
            cout << "No Element in the linked list.";
        else{
            struct node *temp;
            q = s = list;
            temp = NULL;
            r = q->next;
            while(r!=list){
                temp = q;
                q = r;
                r = q->next;
                q->next = temp;
            }
            list = q;
            s->next = q;
            cout << "Linked List has been reversed.";
        }
    }

    void sort(){
        p = list;
        int temp;
        while(p->next!=list){
            q = p->next;
            while(q!=list){
                if(p->data > q->data){
                    temp = p->data;
                    p->data = q->data;
                    q->data = temp;
                }
                q = q->next;
            }
            p = p->next;
        }
        cout << "Elements sorted...";
        display();
    }
};

int main(){
    nick o;
    o.mytech();
}
