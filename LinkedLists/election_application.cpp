#include <iostream>
#include <string>

using namespace std;

struct Node {
    string ContestantName;
    int NoOfVotes;
    Node *link;
};

struct HeadNode {
    int count;
    Node *list;
};

class List {
    HeadNode *Head;
    public:
        List() {
            Head = new HeadNode;
            Head->count = 0;
            Head->list = NULL;
        }
        Node *createNode(string name,int votes) {
            Node *temp = new Node;
            temp->ContestantName = name;
            temp->NoOfVotes = votes;
            temp->link = NULL;
            return temp;
        }
        void insertNode(string name, int votes) {
            Node *temp = createNode(name,votes);
            if (Head->count==0) {
                Head->list = temp;
                Head->count++;
                return;
            }
            Node *t = Head->list;
            while (t->link != NULL) t = t->link;
            t->link = temp;
            Head->count++;
        }
        void display(int threshold) {
            Node *temp = Head->list; int count=0;
            while (temp != NULL) {
                if ((temp->NoOfVotes)>threshold) {
                    cout<<temp->ContestantName<<" - "<<temp->NoOfVotes<<endl;
                    count++;
                }
                temp = temp->link;
            }
            if (count==0) cout<<"No items in given threshold..."<<endl;
        }
        int count() {
            return Head->count;
        }
};

int main() {
    List l;
    int op=10,dummyint;string dummystring;
    while (op!=0) {
        cout<<"Enter an option ( 1)Insert 2)Display 3)Count ): ";
        cin>>op;
        switch (op) {
            case 1:
                cout<<"Enter name of contestant: ";
                cin>>dummystring;
                cout<<"Enter number of votes: ";
                cin>>dummyint;
                l.insertNode(dummystring,dummyint);
                cout<<"Inserted to list"<<endl;
                break;
            case 2:
                cout<<"Enter threshold: ";
                cin>>dummyint;
                l.display(dummyint);
                break;
            case 3:
                cout<<"Count: "<<l.count()<<endl;
                break;
            case 0:
                cout<<"Exiting..."<<endl;
                break;
            default:
                cout<<"Invalid option! Please try again!"<<endl;
        }
    }
    return 0;
}