#include<bits/stdc++.h>
using namespace std;

void printSubArray(int arr[], int size) {
    //  also null set is a subarray of any array
        cout<<" "<<"\n";
        for(int i=0; i<size; i++) {
            for(int j=i; j<size; j++) {
                for(int k=i; k<=j; k++) {
                    cout<<arr[k]<<" ";
                }
                cout<<endl;
            }
        }
}

void getSubseqArray(vector<int> &arr, int index, vector<int> current, vector<vector<int>> &ans){

    if(index == arr.size()) {
        ans.push_back(current);
        return;
    }

    // we will not take the current value of the array as the part of the sub array
    getSubseqArray(arr, index+1, current, ans);

    // we will take the current value of the array as the part of the sub array
    current.push_back(arr[index]);
    getSubseqArray(arr, index+1, current, ans);
}

int main(){
    // int arr[] = {1, 2, 3};
    // int size = sizeof(arr) / sizeof(arr[0]);
    // printSubArray(arr, size);

    vector<int> arr = {1, 2, 3};
    vector<int> current;
    vector<vector<int>> ans;
    getSubseqArray(arr, 0, current, ans);

    cout<<ans.size()<<endl;
    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) {
            cout<<ans[i][j]<<" ";
        } cout<<endl;
    }

    return 0;
}