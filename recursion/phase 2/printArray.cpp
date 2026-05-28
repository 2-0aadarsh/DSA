#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int size, int index){
    if(index<0 || index>=size) return;
    cout<<arr[index]<<" ";
    printArray(arr, size, index+1);
}

int main(){
    int size = 5;
    int arr[size] = {10,20, 30, 40, 50};

    printArray(arr, size, -1);
    return 0;
}
