#include<bits/stdc++.h>
using namespace std;

int minimumValue(int arr[], int size, int index, int min) {

    if(index < 0 || size < 0) return -1;
    if(size == index) return min;

    if(arr[index]< min) {
        min = arr[index];
    }
    minimumValue(arr, size, index+1, min);
}

int main(){
    int size = 5;
    int arr[size] = {10,20, 30, 4, 50};

    cout<<minimumValue(arr, size, 0, INT_MAX);
    return 0;
}