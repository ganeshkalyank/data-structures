#include <bits/stdc++.h>

using namespace std;

void insertionSort(int arr[],int size) {
    int i,key,hole;
    for (i=1;i<size;i++) {
        key = arr[i];
        hole = i;
        while (hole>0&&key<arr[hole-1]) {
            arr[hole]=arr[hole-1];
            hole = hole-1;
        }
        arr[hole]=key;
    }

}

int main() {
    int arr[100],size,i;
    cin>>size;
    for (i=0;i<size;i++) {
        cin>>arr[i];
    }
    insertionSort(arr,size);
    for (i=0;i<size;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}