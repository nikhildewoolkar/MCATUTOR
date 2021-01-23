#include<iostream>
#include<malloc.h>
using namespace std;

struct node{
    int data;
    struct node *lptr;
    struct node *rptr;
}*list=NULL, *p, *q, *r, *s;

class nick{
    int action, value, element;
    public:
    mytech(){
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
            p->lptr = p->rptr = NULL;
        else{
            p->lptr = NULL;
            p->rptr = list;
            list->lptr = p;
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
            p->lptr = p->rptr = NULL;
            list = p;
        }
        else{
            q = list;
            while(q->rptr!=NULL)
                q = q->rptr;
            q->rptr = p;
            p->rptr = NULL;
            p->lptr = q;
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
     
        while((q->data != element) && (q->rptr != NULL)){
            r = q;
            q = q->rptr;
        }
        if(q->data==element){
            if(list->data==element){
                p->rptr = q;
                p->lptr = NULL;
                list = p;
            }
            else{
                r->rptr = p;
                p->lptr = r;
                p->rptr = q;
                q->lptr = p;
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
        r = q->rptr;
        while((q->data != element) && (q->rptr != NULL)){
            q = r;
            r = r->rptr;
        }
        if(q->data != element)
            cout << "Data not found.";
        else if(r == NULL){
            q->rptr = p;
            p->lptr = q;
            p->rptr = NULL;
        }
        else{
            q->rptr = p;
            p->lptr = q;
            p->rptr = r;
            r->lptr = p;
        }
    }

    void delete_b(){
        if(list==NULL)
            cout << "List is empty nothing to delete.";
        else{
            list = list->rptr;
            cout << "Element has been deleted." << endl;
        }
    }

    void delete_e(){
        p = list;
        if(list==NULL)
            cout << "List is empty nothing to delete.";
        else{
            while(p->rptr != NULL){
                q = p;
                p = p->rptr;
            }
            q->rptr = NULL;
            cout << "Element has been deleted." << endl;
        }
    }

    void delete_v(){
        p = list;
        q = p;
        if(list==NULL)
            cout << "List is empty nothing to delete.";
        else{
            cout << "Enter value you want to delete: ";
            cin >> value;
            while(p->data != value && p->rptr!=NULL){
                q = p;
                p = p->rptr;
            }
            if(p->data != value)
                cout << "Data not found.";
            else{
                if(p==q)
                    list = p->rptr;
                else
                    q->rptr = p->rptr;
                cout << "Element has been deleted." << endl;
            }
        }
    }

    void display(){
        if(list==NULL)
            cout << "No Element in the linked list.";
        else{
            p = list;
            cout << "Elements in the linked list are: ";
            while(p!=NULL){
                cout << p->data << " ";
                p = p->rptr;
            }
        }
    }

    void count(){
        int count = 0;
        p = list;
        while(p != NULL){
            count++;
            p = p->rptr;
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
            r = q->rptr;
            s->lptr = r;
            while(r!=NULL){
                temp = q;
                q = r;
                r = q->rptr;
                q->rptr = temp;
            }
            list = q;
            s->rptr = NULL;
            cout << "Linked List has been reversed.";
        }
    }

    void sort(){
        p = list;
        int temp;
        while(p->rptr!=NULL){
            q = p->rptr;
            while(q->rptr!=NULL){
                if(p->data > q->data){
                    temp = p->data;
                    p->data = q->data;
                    q->data = temp;
                }
                q = q->rptr;
            }
            p = p->rptr;
        }
    }
};

int main(){
    nick o;
	o.mytech();
}
