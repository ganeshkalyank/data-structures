#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *link;
};

struct HeadNode {
    int count;
    Node *list;
};

class Stack {
    HeadNode *Head;
    public:
    Stack() {
        Head = new HeadNode;
        Head->count = 0;
        Head->list = NULL;
    }
    void pushStack(int x) {
        Node *temp = new Node;
        temp->data = x; temp->link=NULL;
        if(Head->count==0) {
            Head->list = temp;
            Head->count++;
        } else {
            temp->link = Head->list;
            Head->list = temp;
            Head->count++;
        }
    }
    bool popStack(int *dataOut) {
        if (Head->count>0) {
            *dataOut = Head->list->data;
            Node *temp = Head->list;
            Head->list = temp->link;
            Head->count--;
            delete temp;
            return true;
        }
        return false;
    }
    bool stackTop(int *dataOut) {
        if(Head->count>0) {
            *dataOut = Head->list->data;
            return true;
        }
        return false;
    }
    bool emptyStack() {
        if (Head->count==0) return true;
        return false;
    }
    void destroyStack() {
        Node *temp1 = Head->list,*temp2;
        while(temp1!=NULL) {
            temp2 = temp1;
            temp1 = temp1->link;
            delete temp2;
        }
        delete Head;
    }
};

int main() {
    int op=10,dummy; Stack s;
    while(op!=0) {
        cout<<"Enter an option ( 1)Push 2)Pop 3)Top 4)Empty 5)Destroy ): ";
        cin>>op;
        switch(op) {
            case 1:
                cout<<"Enter data to push: ";
                cin>>dummy;
                s.pushStack(dummy);
                cout<<"Pushed to stack"<<endl;
                break;
            case 2:
                if (s.popStack(&dummy)) cout<<dummy<<" popped"<<endl;
                else cout<<"Stack is empty"<<endl;
                break;
            case 3:
                if (s.stackTop(&dummy)) cout<<dummy<<" is at top"<<endl;
                else cout<<"Stack is empty"<<endl;
                break;
            case 4:
                if (s.emptyStack()) cout<<"Stack is empty"<<endl;
                else cout<<"Stack is not empty"<<endl;
                break;
            case 5:
                s.destroyStack();
                cout<<"Stack destroyed"<<endl;
                op = 0;
                break;
            case 0:
                cout<<"Exiting..."<<endl;
                break;
            default:
                cout<<"Invalid option! Please try again..."<<endl;
        }
    }
    return 0;
}