#include <iostream>

using namespace std;

int recursiveBinarySearch(int arr[],int elem, int start, int end) {
    int mid = (start+end)/2;
    if (arr[mid]==elem) return mid;
    if (arr[mid]<elem) return recursiveBinarySearch(arr,elem,mid+1,end);
    else return recursiveBinarySearch(arr,elem,0,mid-1);
    return -1;
}

int main() {
    int arr[100],elem,size,i;
    cin>>size;
    for (i=0;i<size;i++) cin>>arr[i];
    cin>>elem;
    cout<<endl<<recursiveBinarySearch(arr,elem,0,size-1)<<endl;
    return 0;
}