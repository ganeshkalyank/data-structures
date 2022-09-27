#include <bits/stdc++.h>

using namespace std;

void bubbleSort(int arr[],int size) {
    int i,j;
    for (i=0;i<size-1;i++) {
        for (j=i;j<size-i-1;j++) {
            if (arr[j]<arr[j-1]) {
                swap(arr[j],arr[j-1]);
            }
        }
    }
}

int main() {
    int arr[100],size,i;
    cin>>size;
    for (i=0;i<size;i++) {
        cin>>arr[i];
    }
    bubbleSort(arr,size);
    for (i=0;i<size;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}