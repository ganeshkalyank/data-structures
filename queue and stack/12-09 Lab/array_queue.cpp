#include <bits/stdc++.h>

using namespace std;

class Queue {
	int arr[100],front,rear;
	public:
		Queue() {front=-1;rear=-1;}
		bool enqueue(int data) {
			bool success;
			if (rear==99) {
				success = false;
			} else {
				if (front==-1) {
					front++;
					rear++;
					arr[rear] = data;
					success = true;
				} else {
					rear++;
					arr[rear] = data;
					success = true;
				}
			}
			return success;
		}
		bool dequeue(int *dataOut) {
			bool success;
			if (front==-1) {
				success = false;
			} else {
				*dataOut = arr[front];
				if (front==rear) {
					front = rear = -1;
				}
				else {
					front++;
				}
				success = true;
			}
			return success;
		}
		bool queueFront(int *dataOut) {
			bool success;
			if (front==-1) {
				success = false;
			} else {
				*dataOut = arr[front];
				success = true;
			}
			return success;
		}
		bool queueRear(int *dataOut) {
			bool success;
			if (rear==-1) {
				success = false;
			} else {
				*dataOut = arr[rear];
				success = true;
			}
			return success;
		}
		bool emptyQueue() {
			if (front==-1&&rear==-1) {
				return true;
			} else {
				return false;
			}
		}
		bool fullQueue() {
			if (rear==99) {
				return true;
			} else {
				return false;
			}
		}
		int queueCount() {
			if (front!=-1) {
				return rear-front+1;
			} else {
				return 0;
			}
		}
};

int main() {
	int op,dummy;
	Queue q;
	while (op!=9) {
		cout<<"1) Enqueue"<<endl
		<<"2) Dequeue"<<endl
		<<"3) Front"<<endl
		<<"4) Rear"<<endl
		<<"5) Empty"<<endl
		<<"6) Full"<<endl
		<<"7) Count"<<endl
		<<"9) Exit"<<endl;
		cout<<"Enter an option: "<<endl;
		cin>>op;
		switch(op) {
			case 1:
				cout<<"Enter element to enqueue: ";
				cin>>dummy;
				if (q.enqueue(dummy)) {
					cout<<"Enqueued"<<endl;
				} else {
					cout<<"Queue is full"<<endl;
				}
				break;
			case 2:
				if (q.dequeue(&dummy)) {
					cout<<dummy<<" dequeued"<<endl;
				} else {
					cout<<"Queue is empty"<<endl;
				}
				break;
			case 3:
				if (q.queueFront(&dummy)) {
					cout<<"Front element is "<<dummy<<endl;
				} else {
					cout<<"Queue is empty"<<endl;
				}
				break;
			case 4:
				if (q.queueRear(&dummy)) {
					cout<<"Rear element is "<<dummy<<endl;
				} else {
					cout<<"Queue is empty"<<endl;
				}
				break;
			case 5:
				if (q.emptyQueue()) {
					cout<<"Queue is empty"<<endl;
				} else {
					cout<<"Queue is not empty"<<endl;
				}
				break;
			case 6:
				if (q.fullQueue()) {
					cout<<"Queue is full"<<endl;
				} else {
					cout<<"Queue is not full"<<endl;
				}
				break;
			case 7:
				cout<<"Queue count: "<<q.queueCount()<<endl;
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
