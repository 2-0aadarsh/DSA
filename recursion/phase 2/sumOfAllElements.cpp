#include<bits/stdc++.h>
using namespace std;

int sumOfAllElements(int arr[], int size, int index) {
    if(index < 0) return -1;
    if(index == size) return 0;

    int sum = arr[index] + sumOfAllElements(arr, size, index+1);
    return sum;
}

int main(){
    int size = 5;
    int arr[size] = {10,20, 30, 40, 50};

    cout<<sumOfAllElements(arr, size, 0);
    return 0;
}