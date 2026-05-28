#include<bits/stdc++.h>
using namespace std;

int maximum(int arr[], int index, int size, int max){
    if(size<=0 || index<0) return -1;
    if(index == size) return max;

    if(arr[index] > max) {
        max = arr[index];
    }
    maximum(arr, index+1, size, max);
}

int main(){
    int size = 5;
    int arr[size] = {10,50, 30, 4, 20};
    cout<<maximum(arr,0,size, INT_MIN);
    return 0;
}