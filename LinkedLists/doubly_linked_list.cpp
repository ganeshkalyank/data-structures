#include <iostream>

using namespace std;

struct Node {
    Node *rlink;
    int data;
    Node *flink;
};

struct HeadNode {
    Node *rear;
    int count;
    Node *front;
};

class DLL {
    HeadNode *Head;
    public:
    DLL() {
        Head = new HeadNode;
        Head->count=0;
        Head->front=NULL;
        Head->rear=NULL;
    }
    bool searchList(Node *pPre,Node *pLoc,int target) {
        pPre = NULL;
        pLoc = Head->front;
        bool found;
        while (pLoc!=NULL && target>pLoc->data) {
            pPre = pLoc;
            pLoc = pLoc->flink;
        }
        if (pLoc == NULL) found = false;
        else {
            if (target == pLoc->data) found = true;
            else found = false;
        }
        cout<<pPre<<endl;
        cout<<pLoc<<endl;
        return found;
    }
    int insertDLL(int dataIn) {
        bool found; Node *pPre,*pLoc;
        found = searchList(pPre,pLoc,dataIn);
        if (!found) {
            Node *t = new Node;
            t->data = dataIn;
            Head->count++;
            if (pPre == NULL) {
                t->rlink = NULL;
                t->flink = Head->front;
                Head->front = t;
            } else {
                t->flink = pLoc;
                t->rlink = pPre;
                pPre->flink = t;
            }
            if (pLoc == NULL) Head->rear = t;
            else pLoc->rlink = t;
            return 1;
        }
        return 2;
    }
    void deleteDLL(Node *deleteNode) {
        if (deleteNode == NULL) {
            cout<<"Node is null"<<endl;
            return;
        }
        if (deleteNode->rlink != NULL) {
            deleteNode->rlink->flink = deleteNode->flink;
            deleteNode->flink->rlink = deleteNode->rlink;
        } else Head->rear = deleteNode->rlink;
        delete deleteNode;
        Head->count--;
    }
    bool emptyList() {
        if (Head->count==0) return true;
        else return false;
    }
    int dllCount() {
        return Head->count;
    }
    void displayHeadToRear() {
        Node *pWalker = Head->front;
        while (pWalker!=NULL) {
            cout<<pWalker->data<<" ";
            pWalker = pWalker->flink;
        }
        cout<<endl;
    }
    void displayRearToHead() {
        Node *pWalker = Head->rear;
        while (pWalker!=NULL) {
            cout<<pWalker->data<<" ";
            pWalker = pWalker->rlink;
        }
    }
    void destroyDLL() {
        Node *t = Head->front,*temp;
        while (t!=NULL) {
            temp = t;
            t = t->flink;
            delete temp;
        }
        delete Head;
    }
    int searchDLLFromHead(int target) {
        Node *pLoc = Head->front;
        int pos=1;
        while (pLoc!=NULL && target>pLoc->data) {
            pos++;
            pLoc = pLoc->flink;
        }
        if (pLoc==NULL) return -1;
        else {
            if (target == pLoc->data) return pos;
            else return -1;
        }
    }
    int searchDLLFromRear(int target) {
        Node *pLoc = Head->rear;
        int pos=1;
        while (pLoc!=NULL && target<pLoc->data) {
            pos++;
            pLoc = pLoc->rlink;
        }
        if (pLoc==NULL) return -1;
        else {
            if (target == pLoc->data) return pos;
            else return -1;
        }
    }
};

int main() {
    DLL l; int op=15; int dummy; Node *n1,*n2;
    while (op!=0) {
        cout<<"Enter an option (1. Insert 2. Search 3. Delete 4. Empty 5. Count 6. Head to Rear 7. Rear to Head 8. Destroy 9. From Head 10. From Rear): ";
        cin>>op;
        switch(op) {
            case 1:
                cout<<"Enter data: ";
                cin>>dummy;
                if (l.insertDLL(dummy) == 1) cout<<"Data inserted!"<<endl;
                else cout<<"Insertion failed!"<<endl;
                break;
            case 2:
                cout<<"Enter target: ";
                cin>>dummy;
                if (l.searchList(n1,n2,dummy)) cout<<"Data found at "<<n2<<endl;
                else cout<<"Data not found!"<<endl;
                break;
            case 3:
                cout<<"Enter target: ";
                cin>>dummy;
                l.searchList(n1,n2,dummy);
                l.deleteDLL(n2);
                cout<<"Node deleted!"<<endl;
                break;
            case 4:
                if (l.emptyList()) cout<<"List is empty!"<<endl;
                else cout<<"List is not empty!"<<endl;
                break;
            case 5:
                cout<<"Count: "<<l.dllCount()<<endl;
                break;
            case 6:
                l.displayHeadToRear();
                break;
            case 7:
                l.displayRearToHead();
                break;
            case 8:
                l.destroyDLL();
                break;
            case 9:
                cout<<"Enter target: ";
                cin>>dummy;
                cout<<"From head: "<<l.searchDLLFromHead(dummy)<<endl;
                break;
            case 10:
                cout<<"Enter target: ";
                cin>>dummy;
                cout<<"From rear: "<<l.searchDLLFromRear(dummy)<<endl;
                break;
            default:
                cout<<"Invalid option! Please try again!"<<endl;
        }
    }
    return 0;
}