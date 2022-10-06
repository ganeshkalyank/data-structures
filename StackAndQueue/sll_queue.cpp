#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *link;
};

struct HeadNode {
    int count;
    Node *front;
    Node *rear;
};

class Queue {
    HeadNode *Head;
    public:
    Queue() {
        Head = new HeadNode;
        Head->count = 0;
        Head->front = NULL;
        Head->rear = NULL;
    }
    void enqueue(int x) {
        Node *temp = new Node;
        temp->data = x;
        temp->link = NULL;
        if (Head->count == 0) {
            Head->front = temp;
            Head->rear = temp;
            Head->count++;
        } else if (Head->count == 1) {
            Head->front->link = Head->rear;
            Head->rear->link = temp;
            Head->rear = temp;
            Head->count++;
        } else {
            Head->rear->link = temp;
            Head->rear = temp;
            Head->count++;
        }
    }
    bool dequeue(int *dataOut) {
        if (Head->count>0) {
            if (Head->count == 1) {
                Node *temp = Head->front;
                *dataOut = temp->data;
                Head->front = NULL;
                Head->rear = NULL;
                Head->count--;
                delete temp;
                return true;
            }
            Node *temp = Head->front;
            *dataOut = temp->data;
            Head->front = temp->link;
            Head->count--;
            delete temp;
            return true;
        }
        return false;
    }
    bool queueFront(int *dataOut) {
        if (Head->count>0) {
            *dataOut = Head->front->data;
            return true;
        }
        return false;
    }
    bool queueRear(int *dataOut) {
        if (Head->count>0) {
            *dataOut = Head->rear->data;
            return true;
        }
        return false;
    }
    bool emptyQueue() {
        if (Head->count == 0) return true;
        return false;
    }
    int queueCount() {
        return Head->count;
    }
    void destroyQueue() {
        Node *temp1 = Head->front,*temp2;
        while(temp1!=NULL) {
            temp2 = temp1;
            temp1 = temp1->link;
            delete temp2;
        }
        delete Head;
    }
};

int main() {
    int op=10,dummy; Queue q;
    while (op!=0) {
        cout<<"Enter an option ( 1)Enqueue 2)Dequeue 3)Front 4)Rear 5)Empty 6)Count 7)Destroy ): ";
        cin>>op;
        switch(op) {
            case 1:
                cout<<"Enter element to enqueue: ";
                cin>>dummy;
                q.enqueue(dummy);
                cout<<"Enqueued"<<endl;
                break;
            case 2:
                if (q.dequeue(&dummy)) cout<<dummy<<" dequeued"<<endl;
                else cout<<"Queue is empty"<<endl;
                break;
            case 3:
                if (q.queueFront(&dummy)) cout<<dummy<<" is at front"<<endl;
                else cout<<"Queue is empty"<<endl;
                break;
            case 4:
                if (q.queueRear(&dummy)) cout<<dummy<<" is at rear"<<endl;
                else cout<<"Queue is empty"<<endl;
                break;
            case 5:
                if(q.emptyQueue()) cout<<"Queue is empty"<<endl;
                else cout<<"Queue is not empty"<<endl;
                break;
            case 6:
                cout<<"Count: "<<q.queueCount()<<endl;
                break;
            case 7:
                q.destroyQueue();
                cout<<"Queue destroyed"<<endl;
                op=0;
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