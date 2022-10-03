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

class HashSearch {
	HeadNode hashTable[101];
	// HeadNode* hashTable = new HeadNode[101];
	Node *createNode(int key) {
		Node *tmp = new Node;
		tmp->data = key;
		tmp->link = NULL;
		return tmp;
	}
	public:
		HashSearch() {
			for (int i=0;i<101;i++) {
				(hashTable+i)->count=0;
				(hashTable+i)->list=0;
			}
		}
		void insertToHash(int key) {
			int hashIndex = key%101;
			Node* newNode = createNode(key);
			newNode->link = (hashTable+hashIndex)->list;
			(hashTable+hashIndex)->list = newNode;
			(hashTable+hashIndex)->count++;
		}
		void deleteFromHash(int dltKey) {
			int hashIndex = dltKey%101;
			Node *delNode = (hashTable+hashIndex)->list;
			Node *temp = NULL;
			while (delNode != NULL) {
				if (delNode -> data == dltKey) {
					if (temp == NULL) {
						(hashTable+hashIndex)->list = delNode->link;
					} else {
						temp->link = delNode->link;
					}
					(hashTable+hashIndex)->count--;
					return;
				}
				temp = delNode;
				delNode = delNode->link;
			}
			cout<<"Given key is not present in the table."<<endl;
			return;
		}
		void searchInHash(int key) {
			int hashIndex = key%101;
			Node *searchNode = (hashTable+hashIndex)->list;
			while (searchNode != NULL) {
				if (searchNode->data == key) {
					cout<<searchNode->data<<endl;
					return;
				}
				searchNode = searchNode -> link;
			}
			cout<<"Given key is not present in the table."<<endl;
		}
		void display() {
			int i=0;
			while (i<101) {
				Node* temp = (hashTable+i)->list;
				while (temp!=NULL) {
					cout<<temp->data<<" ";
					temp = temp->link;
				}
				i++;
			}
			cout<<endl;
		}
};

int main() {
	HashSearch hs;
	int op=25,dummy;
	while(op!=0) {
		cout<<"Enter your option 1)Insert to Hash 2)Delete from Hash 3)Search in hash 4)Display ): ";
		cin>>op;
		switch(op) {
			case 1:
				cout<<"Enter key to insert: ";
				cin>>dummy;
				hs.insertToHash(dummy);
				cout<<"Inserted  to hash"<<endl;
				break;
			case 2:
				cout<<"Enter key to delete: ";
				cin>>dummy;
				hs.deleteFromHash(dummy);
				cout<<"Deleted from hash"<<endl;
				break;
			case 3:
				cout<<"Enter key to search: ";
				cin>>dummy;
				hs.searchInHash(dummy);
				break;
			case 4:
				hs.display();
				break;
			case 0:
				cout<<"Exiting!..."<<endl;
				break;
			default:
				cout<<"Invalid option! Please try again!"<<endl;
		}
	}
    return 0;
}
