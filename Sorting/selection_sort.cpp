#include <iostream>

using namespace std;

void selectionSort(int arr[], int size) {
    int current,walker,smallest;
    current=0;
    while (current<size) {
        smallest = current;
        walker = current+1;
        while (walker<size) {
            if (arr[walker]<arr[smallest]) {
                smallest = walker;
            }
            walker++;
        }
        swap(arr[current],arr[smallest]);
        current++;
    }
}

int main() {
    int arr[] = {9,5,4,3,8,1};
    selectionSort(arr,6);
    for (int i=0;i<6;i++) {
        cout<<arr[i]<<" ";
    } 
    return 0;
}