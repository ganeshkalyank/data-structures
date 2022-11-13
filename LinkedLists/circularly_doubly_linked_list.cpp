#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* prev, *next;
};
struct HeadNode
{
	int count;
	Node* first, *last;
};
class CDLL
{
	HeadNode* Head;
	public:
		CDLL()
		{
			Head = new HeadNode;
			Head->first=Head->last = NULL;
			Head->count=0;
		}
		Node* createNode(int x)
		{
			Node* newnode=new Node;
			newnode->data=x;
			newnode->next=newnode->prev=NULL;
			return newnode;
		}
		void insert(int data)
		{
			Node* nn = createNode(data);
			if (Head->count==0)
			{
				Head->first=Head->last=nn;
				nn->next=nn->prev=nn;
				Head->count++;
				return;
			}
			Node* temp=Head->first;
			while(temp->next != Head->first)
				if (data > temp->data)
					temp=temp->next;
				else
					break;
			if (data > temp->data)	// insert nn as last node
			{
				nn->prev=temp;
				nn->next=temp->next;
				nn->prev->next=nn->next->prev=nn;
				Head->last=nn;	
			}
			else					// insert nn before temp
			{
				nn->next=temp;
				nn->prev=temp->prev;
				nn->prev->next=nn->next->prev=nn;
				if (nn->next==Head->first)
					Head->first=nn;				
			}
			Head->count++;
		}
		void deleteElem(int x)
		{
			if (!Head->first)
			{
				cout<<"List empty"; return;
			}
			Node* tmp=Head->first;
			while (tmp->data != x && tmp->next != Head->first)
				tmp=tmp->next;
			if (tmp->data != x)
			{
				cout<<"Data not found"; return;
			}
			if (tmp==Head->first&&tmp==Head->last)
			{
				Head->first=Head->last=NULL;
				Head->count=0;
				delete tmp; return;
			}
			if (Head->first==tmp)
				Head->first=tmp->next;
			if (Head->last==tmp)
				Head->last=tmp->prev;
			tmp->next->prev=tmp->prev;
			tmp->prev->next=tmp->next;
			
			Head->count--;
			delete tmp;
		}
		bool searchElem(int x, int& pos)
		{
			if (Head->count==0)
				cout<<"Empty List";
			else
			{
				Node* tmp=Head->first;
				pos=1;
				do
				{
					if (tmp->data==x)
						return true;
					else
					{
						tmp=tmp->next;
						pos++;
					}
				} while (tmp != Head->first);
			}
			return false;
		}
		void display()
		{
			if (Head->count==0)
				cout<<"Empty List";
			else
			{
				Node* tmp=Head->first;
				do
				{
					cout<<tmp->data<<" ";
					tmp=tmp->next;
				}
				while (tmp!=Head->first);				
			}
		}
};
int main()
{
	CDLL List; int ch, elem, val,pos;
	do
	{
		cout<<"\n1. Insert data\t2. Delete data\t3. Search Data\t5. Display list";
		cout<<"\nEnter choice:"; cin>>ch;
		switch(ch)
		{
			case 1: cout<<"Enter element to insert:"; cin>>elem;
					List.insert(elem); break;
			case 2: cout<<"Delete what? "; cin>>elem;
					List.deleteElem(elem); break;
			case 3: cout<<"Search what? "; cin>>elem;
					if (List.searchElem(elem,pos))
						cout<<"Element found at : "<<pos;
					else
						cout<<"Element not found";
					break;
			case 5: List.display();	
			default: break;				
		}
	}while (ch<=5);
	
}
