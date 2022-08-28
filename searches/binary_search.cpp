#include <iostream>

using namespace std;

int binarySearch(int arr[],int elem,int size) {
    int start=0,end=size-1,mid;
    while (start<=end) {
        mid = (start+end)/2;
        if (arr[mid]==elem) return mid;
        if (arr[mid]<elem) start=mid+1;
        else end=mid-1;
    }
    return -1;
}

int main() {
    int arr[100],elem,size,i;
    cin>>size;
    for (i=0;i<size;i++) cin>>arr[i];
    cin>>elem;
    cout<<endl<<binarySearch(arr,elem,size)<<endl;
    return 0;
}