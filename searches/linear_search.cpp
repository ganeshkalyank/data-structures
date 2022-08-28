#include <iostream>

using namespace std;

int linearSearch(int arr[],int elem,int size) {
    int i;
    for (i=0;i<size;i++) {
        if(arr[i]==elem) return i;
    }
    return -1;
}

int main() {
    int arr[100],elem,size,i;
    cin>>size;
    for (i=0;i<size;i++) cin>>arr[i];
    cin>>elem;
    cout<<endl<<linearSearch(arr,elem,size)<<endl;
    return 0;
}