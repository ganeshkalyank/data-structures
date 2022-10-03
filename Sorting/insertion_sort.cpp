#include <bits/stdc++.h>

using namespace std;

void insertionSort(int arr[],int size) {
    int current,hold,walker;
    for (current=1;current<size;current++) {
        hold = arr[current];
        walker = current;
        while (walker>0&&hold<arr[walker-1]) {
            arr[walker]=arr[walker-1];
            walker = walker-1;
        }
        arr[walker]=hold;
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
    insertionSort(arr,size);
    cout<<"Elements after sorting: ";
    for (i=0;i<size;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}