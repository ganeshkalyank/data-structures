#include <bits/stdc++.h>

using namespace std;

struct Node {
	int data;
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
			Head -> count = 0;
			Head -> list = NULL;
		}
		void InsertNode(int dataIn) {
			Node *t=new Node;t->data=dataIn;t->link=NULL;
			Node *tmp;
			if (Head->list==NULL) {
				Head->list=t;
				Head->count++;
			} else if (Head->list->data>t->data) {
				t->link = Head->list;
				Head->list = t;
				Head->count++;
			} else {
				tmp = Head->list;
				while (tmp->link!=NULL&&tmp->link->data<dataIn) {
					tmp=tmp->link;
				}
				t->link=tmp->link;
				tmp->link=t;
				Head->count++;
			}
		}
		void displayList() {
			Node *tmp;
			tmp=Head->list;
			while(tmp!=NULL) {
				cout<<tmp->data<<" ";
				tmp=tmp->link;
			}
			cout<<endl;
		}
		bool deleteNode(int target) {
			Node *temp,*dummy;
			if (Head->list==NULL) return false;
			if (Head->list->data == target) {
				temp = Head->list;
				Head->list=temp->link;
				delete temp; Head->count--;
				return true;
			}
			temp = Head->list;
			while (temp->link!=NULL) {
				if (temp->link->data!=target) {
					temp=temp->link;
				} else {
					break;
				}
			}
			if (temp->link==NULL) {
				cout<<"Target not found!"<<endl;
				return false;
			} else {
				dummy = temp->link;
				temp->link=temp->link->link;
				Head->count--;
				delete dummy;
				return true;
			}
		}
		bool searchList(Node *pPre,Node *pLoc, int target) {
			pPre=pLoc=NULL;
			if (Head->count==0) return false;
			pLoc=Head->list;
			while (pLoc!=NULL&&pLoc->data!=target) {
				pPre = pLoc;
				pLoc = pLoc->link;
			}
			if (pLoc==NULL) return false;
			else return true;
		}
		Node *retrieveNode(int target) {
			Node *pPre,*pLoc;
			searchList(pPre,pLoc,target);
			return pLoc;
		}
		int listCount() {
			return Head->count;
		}
		void destroyList() {
			Node *tmp=Head->list,*t;
			while (tmp!=NULL) {
				t=tmp;
				tmp=tmp->link;
				delete t;
			}
			delete Head;
		}
		bool listEmpty() {
	        if (Head->count==0) return true;
	        return false;
		}
};

int main() {
	List l;
	int op=25,dummy;
	Node *loc1,*loc2;
	while (op!=0&&op!=7) {
		cout<<"1)Insert 2)Display 3)Delete 4)Search 5)Retrieve 6)Count 7)Destroy 8)Empty 0)Exit"<<endl;
		cout<<"Enter an option: ";
		cin>>op;
		switch(op) {
			case 1:
				cout<<"Enter data to insert: ";
				cin>>dummy;
				l.InsertNode(dummy);
				break;
			case 2:
				l.displayList();
				break;
			case 3:
				cout<<"Enter element to delete: ";
				cin>>dummy;
				l.deleteNode(dummy);
				break;
			case 4:
				cout<<"Enter element to search: ";
				cin>>dummy;
				if (l.searchList(loc1,loc2,dummy)){
					cout<<"Prelocation: "<<loc1<<endl;
					cout<<"Location: "<<loc2<<endl;
				} else {
					cout<<"Element not found!"<<endl;
				}
				break;
			case 5:
				cout<<"Enter element to retrieve: ";
				cin>>dummy;
				cout<<"Element found at "<<l.retrieveNode(dummy)<<endl;
				break;
			case 6:
				cout<<"Count: "<<l.listCount()<<endl;
				break;
			case 7:
				cout<<"Destroying..."<<endl;
				l.destroyList();
				break;
			case 8:
				if(l.listEmpty()) {
					cout<<"List is empty!"<<endl;
				} else {
					cout<<"List is not empty!"<<endl;
				}
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
