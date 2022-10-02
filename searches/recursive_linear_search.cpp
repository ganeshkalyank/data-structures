#include <iostream>

using namespace std;

int recursiveLinearSearch(int arr[],int elem,int first,int last) {
    if (first>last) return -1;
    if (elem==arr[first]) return first;
    return recursiveLinearSearch(arr,elem,first+1,last);
}

int main() {
    int arr[100],elem,size,i;
    cin>>size;
    for (i=0;i<size;i++) cin>>arr[i];
    cin>>elem;
    cout<<endl<<recursiveLinearSearch(arr,elem,0,size-1)<<endl;
    return 0;
}