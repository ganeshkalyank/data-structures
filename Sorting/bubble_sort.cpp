#include <bits/stdc++.h>

using namespace std;

void bubbleSort(int arr[],int size) {
    int current=0,walker; bool sorted=false;
    while (current<=size-1 && !sorted) {
        walker = size-1;
        sorted = true;
        while (walker>current) {
            if (arr[walker]<arr[walker-1]) {
                swap(arr[walker],arr[walker-1]);
                sorted = false;
            }
            walker--;
        }
        current++;
    }
}

int main() {
    int i,arr[100],size;
    cout<<"Enter size: ";
    cin>>size;
    cout<<"Enter elements: ";
    for (i=0;i<size;i++) {
        cin>>arr[i];
    }
    bubbleSort(arr,size);
    cout<<"Elements after sorting: ";
    for (i=0;i<size;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}