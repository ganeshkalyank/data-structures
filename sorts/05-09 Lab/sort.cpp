#include <bits/stdc++.h>

using namespace std;

class Sort {
	public:
		int bubble(int arr[], int last) {
			int current = 0,walker,count=0; bool sorted = false;
			while (current<=last && sorted==false) {
				walker = last;
				sorted = true;
				count = 0;
				while (walker>current) {
					if (arr[walker]<arr[walker-1]) {
						sorted = false;
						swap(arr[walker],arr[walker-1]);
					}
					walker--;
				    count++;
				}
			    cout<<"Number of comparisions in iteration "<<current<<" : "<<count<<endl;
				current++;
			}
			return count;
		}
		int insertion(int arr[], int last) {
			int current,walker,hold,key,count=0;
			for (current=1;current<=last;current++) {
				hold = arr[current];
				walker = current-1;
				count = 0;
				while (walker>=0&&hold<arr[walker]) {
					arr[walker+1] = arr[walker];
					walker--;
					count++;
				}
				arr[walker+1] = hold;
			    cout<<"Number of comparisions in iteration "<<current<<" : "<<count<<endl;
			}
			return count;
		}
};

int main() {
	int arr[100],size,i,count;
	char op;
	Sort s;
	while (op!='q') {
		cout<<"Select sorting algorithm (b - Bubble Sort, i - Insertion Sort, q - quit): ";
		cin>>op;
		switch (op) {
			case 'b':
				cout<<"Enter array size: ";
				cin>>size;
				cout<<"Enter elements: ";
				for (i=0;i<size;i++) cin>>arr[i];
				count = s.bubble(arr,size-1);
				cout<<"Elements after sorting: ";
				for (i=0;i<size;i++) cout<<arr[i]<<" ";
				cout<<endl;
//				cout<<"Number of iterations: "<<count<<endl;
				break;
			case 'i':
				cout<<"Enter array size: ";
				cin>>size;
				cout<<"Enter elements: ";
				for (i=0;i<size;i++) cin>>arr[i];
				count = s.insertion(arr,size-1);
				cout<<"Elements after sorting: ";
				for (i=0;i<size;i++) cout<<arr[i]<<" ";
				cout<<endl;
//				cout<<"Number of comparisons: "<<count<<endl;
				break;
			case 'q':
				cout<<"Exiting..."<<endl;
				break;
			default:
				cout<<"Invalid option! Please try again."<<endl;
		}
	}
	return 0;
}
