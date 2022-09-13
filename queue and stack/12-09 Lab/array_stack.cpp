#include <bits/stdc++.h>

using namespace std;

class Stack {
	int arr[100],top;
	public:
		Stack():top(-1) {}
		bool pushStack(int data) {
			bool success;
			if (top==99) {
				success = false;
			} else {
				top++;
				arr[top] = data;
				success = true;
			}
			return success;
		}
		bool popStack(int *dataOut) {
			bool success;
			if (top==-1) {
				success = false;
			} else {
				*dataOut = arr[top];
				top--;
				success = true;
			}
			return success;
		}
		bool stackTop(int *dataOut) {
			bool success;
			if (top==-1) {
				success = false;
			} else {
				success = true;
			    *dataOut = arr[top];
			}
			return success;
		}
		bool emptyStack() {
			if (top==-1) {
				return true;
			}
			else {
				return false;
			}
		}
		bool fullStack() {
			if (top==99) {
				return true;
			} else {
				return false;
			}
		}
};

int main() {
	int op,dummy;
	Stack s;
	while (op!=9) {
		cout<<"1) Push"<<endl
		<<"2) Pop"<<endl
		<<"3) Top"<<endl
		<<"4) Empty"<<endl
		<<"5) Full"<<endl
		<<"9) Exit"<<endl;
		cout<<"Enter an option: "<<endl;
		cin>>op;
		switch(op) {
			case 1:
				cout<<"Enter element to push: ";
				cin>>dummy;
				if (s.pushStack(dummy)) {
					cout<<"Pushed to stack"<<endl;
				} else {
					cout<<"Stack is full"<<endl;
				}
				break;
			case 2:
				if (s.popStack(&dummy)) {
					cout<<dummy<<" popped out"<<endl;
				} else {
					cout<<"Stack is empty"<<endl;
				}
				break;
			case 3:
				if (s.stackTop(&dummy)) {
					cout<<"Top element is "<<dummy<<endl;
				} else {
					cout<<"Stack is empty"<<endl;
				}
				break;
			case 4:
				if (s.emptyStack()) {
					cout<<"Stack is empty"<<endl;
				} else {
					cout<<"Stack is full"<<endl;
				}
				break;
			case 5:
				if (s.fullStack()) {
					cout<<"Stack is full"<<endl;
				} else {
					cout<<"Stack is not full"<<endl;
				}
				break;
			case 9:
				cout<<"Exiting..."<<endl;
				break;
			default:
				cout<<"Invalid option!"<<endl;
		}
	}
	return 0;
}
